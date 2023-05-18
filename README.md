# Guess-A-Number-with-Arduino

This Arduino project implements a number guessing game using a 16x2 LCD display and a keypad. The player enters a number using the keypad, and the Arduino compares it to a randomly generated number. The LCD display provides feedback to the player indicating whether the guess is correct, too high, or too low. The project also includes LEDs to indicate game status.

## Components Used

<ul>
<li>Arduino board (any Arduino board compatible with the LiquidCrystal and Keypad libraries)
<li>16x2 LCD display compatible with the Hitachi HD44780 driver
<li>Keypad (4x3 matrix keypad)
<li>Green LED (connected to pin 7)
<li>Red LED (connected to pin 6)
<li>10K resistor
<li>Jumper wires
<li>Circuit Setup
<li>Connect the components as follows:
</ul>

## Circuit Diagram

![Swanky Luulia-Jarv](https://github.com/ahmedelzaky/Guess-A-Number-with-Arduino/assets/89663624/bf38779c-ccb6-4f2e-8219-bfe8fe22ab61)


## LCD Connections:

<ul>
<li>RS pin to digital pin 12
<li>Enable pin to digital pin 11
<li>D4 pin to digital pin 5
<li>D5 pin to digital pin 4
<li>D6 pin to digital pin 3
<li>D7 pin to digital pin 2
<li>R/W pin to ground
<li>VSS pin to ground
<li>VCC pin to 5V
<li>VO pin to wiper of a 10K resistor, with one end connected to +5V and the other end connected to ground
</ul>

## Keypad Connections:

<ul>
<li>Row pins (R1, R2, R3, R4) to digital pins 13, 10, 9, 8
<li>Column pins (C1, C2, C3) to analog pins A1, A2, A3
</ul>

## LED Connections:

### Green LED:

Connect the anode (longer leg) to pin 7
Connect the cathode (shorter leg) to ground through a current-limiting resistor (e.g., 220-470 ohms)

### Red LED:

Connect the anode (longer leg) to pin 6
Connect the cathode (shorter leg) to ground through a current-limiting resistor (e.g., 220-470 ohms)

## Libraries Used

This project utilizes the following libraries:

LiquidCrystal: Allows control of LCD displays compatible with the Hitachi HD44780 driver.
Keypad: Provides functions for reading input from a keypad.

## How to Use

<ol>
<li>Set up the circuit according to the specified connections.
<li>Connect your Arduino board to your computer.
<li>Open the Arduino IDE and upload the sketch to your Arduino board.
<li>Open the serial monitor to view debug information (baud rate: 9600).
<li>The LCD will display the initial message: "Guess A Number".
<li>Enter a two-digit number on the keypad and press "#" or "\*", or enter two digits to trigger the comparison.
<li>The LCD will display the result:
<ul>
<li>If the guess is correct, the LCD will display "Winner ^\_^" and the green LED will briefly turn on.
<li>If the guess is too high, the LCD will display "The number is Less Than: <guess>" and the red LED will briefly turn on.
<li>If the guess is too low, the LCD will display "The Number is Greater Than: <guess>" and the red LED will briefly turn on.
</ul>
<li>Repeat steps 6-7 to make additional guesses.
<li>If the player reaches 10 incorrect guesses, the LCD will display "GAME OVER" and the red LED will briefly turn on.
<li>The game will automatically reset, generating a new random number and resetting the guess counter, after a win or after reaching 10 incorrect guesses.
</ol>

  
## Demo
  
https://github.com/ahmedelzaky/Guess-A-Number-with-Arduino/assets/89663624/a5e72569-26f6-427f-9573-66a39801e93b



  
