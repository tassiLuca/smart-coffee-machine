package seiot.coffeemanager.utils;

import java.util.concurrent.*;
import jssc.*;

/**
 * Communication channel implementation based on serial port.
 */
public class SerialCommChannel implements CommChannel, SerialPortEventListener {

    private final SerialPort serialPort;
    private final BlockingQueue<String> queue;
    private StringBuffer currentMsg = new StringBuffer("");
	
    public SerialCommChannel(final String port, final int rate) throws Exception {
        queue = new ArrayBlockingQueue<>(100);
        serialPort = new SerialPort(port);
        serialPort.openPort();
        serialPort.setParams(rate, SerialPort.DATABITS_8, SerialPort.STOPBITS_1, SerialPort.PARITY_NONE);
        serialPort.setFlowControlMode(SerialPort.FLOWCONTROL_RTSCTS_IN | SerialPort.FLOWCONTROL_RTSCTS_OUT);
        // serialPort.addEventListener(this, SerialPort.MASK_RXCHAR);
	serialPort.addEventListener(this);
    }

    @Override
    public void sendMsg(final String msg) {
	final char[] array = (msg+"\n").toCharArray();
	byte[] bytes = new byte[array.length];
	for (int i = 0; i < array.length; i++){
	    bytes[i] = (byte) array[i];
	}
	try {
	    synchronized (serialPort) {
	        serialPort.writeBytes(bytes);
	    }
	} catch(Exception ex){
	    ex.printStackTrace();
	}
    }

    @Override
    public String receiveMsg() throws InterruptedException {
        return queue.take();
    }

    @Override
    public boolean isMsgAvailable() {
        return !queue.isEmpty();
    }

    /**
     * This should be called when you stop using the port.
     * This will prevent port locking on platforms like Linux.
     */
    public void close() {
        try {
            if (serialPort != null) {
                serialPort.removeEventListener();
                serialPort.closePort();
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    public void serialEvent(final SerialPortEvent event) {
        /* if there are bytes received in the input buffer */
        if (event.isRXCHAR()) {
            try {
                String msg = serialPort.readString(event.getEventValue());
                msg = msg.replaceAll("\r", "");
                currentMsg.append(msg);
            	boolean goAhead = true;
            	while (goAhead) {
            	    final String msg2 = currentMsg.toString();
            	    final int index = msg2.indexOf("\n");
            	    if (index >= 0) {
            	        queue.put(msg2.substring(0, index));
            	        currentMsg = new StringBuffer("");
            	        if (index + 1 < msg2.length()) {
            	            currentMsg.append(msg2.substring(index + 1)); 
            	        }
            	    } else {
            	        goAhead = false;
            	    }
            	}
            } catch (final Exception ex) {
                ex.printStackTrace();
                System.out.println("Error in receiving string from COM-port: " + ex);
            }
        }
    }
}
