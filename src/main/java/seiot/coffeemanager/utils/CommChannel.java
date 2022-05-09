package seiot.coffeemanager.utils;

/**
 * Simple interface for an asynchronous message communication channel.
 */
public interface CommChannel {
	
    /**
     * Send a message. Asynchronous model.
     * @param msg a string, without new line
     */
    void sendMsg(String msg);
	
    /**
     * To receive a message.
     * Blocking behavior.
     */
    String receiveMsg() throws InterruptedException;
    
    /**
     * Check if a message is available.
     * @return true if a message is available, false otherwise.
     */
    boolean isMsgAvailable();

}
