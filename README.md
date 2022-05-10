# Smart Coffee Machine
This is the second assignment for the Embedded System and IoT course of the Computer Science and Engineering Bachelor Degree @ UniBO.

## Project Overview
We want to realize an embedded system simulating a smart coffee machine.

The system is composed of three tactile buttons B_up, B_down, B_make, a potentiometer Pot_sugar, a display D connected to the board through I2C, a pir P, a sonar S, a servo motor M and analog temperature sensor T. The system is connected to a PC through a serial line. On the PC there is a simple application called "Coffee Machine Manager" that interacts with the system.

The coffee machine is able to make three different kinds of products: coffee, tea, chocolate. When refilled, the machine can make up to Nmax products for each type.

A user interacts with the machine by means of the buttons Bup, Bdown, and Bmake – to select and make a product – and to Potsugar to choose the sugar level. The making process is simulated by means of the motor M.

The machine has a power-saving modality, so that it goes to sleep if it is idle for a certain amount of time and no users are nearby.

The Coffee Machine Manager application is used to monitor and check the state of the machine, as well as to refill it when there are no more products that can be made.

## More infos
Refers to the [report](./docs/report.html) for a short demo, the breadboard circuit schema and the state charts.