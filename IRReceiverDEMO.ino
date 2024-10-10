#include <IRremote.hpp>  // Use the new header for version 4.x
#define IR_RECEIVE_PIN 2 // Set the pin number for the IR receiver

void setup() {
    Serial.begin(19200); // Establish serial communication at 19200 baud
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver with LED feedback
    Serial.println("IR Receiver Ready"); // Indicate that the receiver is ready
}

void loop() {
    if (IrReceiver.decode()) { // Check if a signal is received
        Serial.print("Received: ");
        Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print the decoded raw data in hexadecimal
        IrReceiver.printIRResultShort(&Serial); // Print the complete received data in one line
        IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data
        IrReceiver.resume(); // Prepare to receive the next value
    }
}
