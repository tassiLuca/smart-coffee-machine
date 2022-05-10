# Smart Coffee Machine
This is the second assignment for the Embedded System and IoT course of the Computer Science and Engineering Bachelor Degree @ UniBO.

## Project Overview
We want to realize an embedded system simulating a smart coffee machine.

The system is composed of three tactile buttons B_up, B_down, B_make, a potentiometer Pot_sugar, a display D connected to the board through I2C, a pir P, a sonar S, a servo motor M and analog temperature sensor T. The system is connected to a PC through a serial line. On the PC there is a simple application called "Coffee Machine Manager" that interacts with the system.

The coffee machine is able to make three different kinds of products: coffee, tea, chocolate. When refilled, the machine can make up to Nmax products for each type.

A user interacts with the machine by means of the buttons Bup, Bdown, and Bmake – to select and make a product – and to Potsugar to choose the sugar level. The making process is simulated by means of the motor M.

The machine has a power-saving modality, so that it goes to sleep if it is idle for a certain amount of time and no users are nearby.

The Coffee Machine Manager application is used to monitor and check the state of the machine, as well as to refill it when there are no more products that can be made.

## How to execute
The arduino sub-system is made with [Platformio](https://platformio.org) and Visual Studio Code.
The Java program is a Gradle project. Tu run as a gradle project:
```sh
./gradlew run --args="PORT_NAME"
```
To run the jar:
```sh
java -jar ./smart-coffee-machine-all.jar PORT_NAME
```
where `PORT_NAME` is the port to which is connected the Arduino.

## More infos
Refers to the [report](./docs/report.md) for a short demo, the breadboard circuit schema and the state charts.