# LCDEmulator
LCD Screen Emulator

The following files are included in the repository:

LCDEmulator.pde - An LCD screen with serial interface emulator that runs in Processing-2. An example Energia Sketch that runs on the MSP430G2553 is included at the bottom of the Processing code.

LCDEmulatorTest_C - This folder contains an Energia C code sketch, LCDEmulatorTest_C.ino,  that can be uploaded to the MSP430G2553 launchpad to test the LCDEmulator. The .c and .h files are the libraries that this sketch requires. Download all files and save in the same folder open the LCDEmulatorTest_C.ino in Energia. This example uses the ADC to capture the analogue input on pin P1.5 in order to control the position of a rectangle on the LCD Emulator. The ADC is initialised using the internal 1.5V reference which is also output to pin P1.4. Placing a 1-10k Potentiometer between P1.4 and GND with the wiper attached to P1.5 will allow you to use this example.
