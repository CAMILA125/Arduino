/*Serial_LED_02.ino  Arduining 4 May 2015
  Controlling the LED in pin 13 with the Serial Monitor.
  --- Command list: ---
  ? -> Print this HELP
  a -> LED On  "activate"
  d -> LED Off "deactivate"
  s -> LED     "status"

  Example using the switch statement.
*/

#define LED 13          // Pin 13 is connected to the LED
#define COOLER 8
#define led 9
char rxChar = 0;        // RXcHAR holds the received command.

//=== function to print the command list:  ===========================
void printHelp(void) {
  Serial.println("--- Command list: ---");
  Serial.println("? -> Print this HELP");
  Serial.println("a -> LED On  \"ativado\"");
  Serial.println("d -> LED Off \"desativado\"");
  Serial.println("c -> COOLER On  \"activado\"");
  Serial.println("r -> COOLER Off \"desativado\"");
  Serial.println("v -> led On  \"activado\"");
  Serial.println("x -> led Off \"desativado\"");
  Serial.println("s -> LED COOLER cooler     \"status\"");
}

//---------------- setup ---------------------------------------------
void setup() {
  Serial.begin(9600);   // Open serial port (9600 bauds).
  pinMode(LED, OUTPUT); // Sets pin 13 as OUTPUT.
  Serial.flush();       // Clear receive buffer.
  //printHelp();          // Print the command list.
  Serial.begin(9600);   // Open serial port (9600 bauds).
  pinMode(COOLER, OUTPUT); // Sets pin 13 as OUTPUT.
  Serial.flush();
  Serial.begin(9600);   // Open serial port (9600 bauds).
  pinMode(led, OUTPUT); // Sets pin 13 as OUTPUT.
  Serial.flush(); // Clear receive buffer.
  printHelp();
}

//--------------- loop -----------------------------------------------
void loop() {
  if (Serial.available() > 0) {        // Check receive buffer.
    rxChar = Serial.read();            // Save character received.
    Serial.flush();                    // Clear receive buffer.

    switch (rxChar) {

      case 'a':
      case 'A':                          // If received 'a' or 'A':
        if (digitalRead(LED) == LOW) {       // If LED is Off:
          digitalWrite(LED, HIGH);     // Turn On the LED.
          Serial.println("LED est?? ligado");
        }
        else Serial.println("LED j?? est?? ligado!");
        break;

      case 'd':
      case 'D':                          // If received 'd' or 'D':
        if (digitalRead(LED) == HIGH) {      // If LED is On:
          digitalWrite(LED, LOW);      // Turn Off the LED.
          Serial.println("LED est?? desligado");
        }
        else Serial.println("LED j?? est?? desligado!");
        break;
      case 'c':
      case 'C':                          // If received 'a' or 'A':
        if (digitalRead(COOLER) == LOW) {       // If LED is Off:
          digitalWrite(COOLER, HIGH);     // Turn On the LED.
          Serial.println("COOLER est?? ligado");
        }
        else Serial.println("COOLER j?? est?? ligado!");
        break;

      case 'r':
      case 'R':                          // If received 'd' or 'D':
        if (digitalRead(COOLER) == HIGH) {      // If LED is On:
          digitalWrite(COOLER, LOW);      // Turn Off the LED.
          Serial.println("COOLER est?? desligado");
        }
        else Serial.println("COOLER j?? est?? desligado!");
        break;
      case 'v':
      case 'V':                          // If received 'a' or 'A':
        if (digitalRead(led) == LOW) {       // If LED is Off:
          digitalWrite(led, HIGH);     // Turn On the LED.
          Serial.println("led est?? ligado");
        }
        else Serial.println("led j?? est?? ligado!");
        break;

      case 'x':
      case 'X':                          // If received 'd' or 'D':
        if (digitalRead(led) == HIGH) {      // If LED is On:
          digitalWrite(led, LOW);      // Turn Off the LED.
          Serial.println("led est?? desligado");
        }
        else Serial.println("led j?? est?? desligado!");
        break;

      case 's':
      case 'S':                          // If received  's' or 'S':
        if (digitalRead(LED) == HIGH)        // Read LED status.
          Serial.println("LED status: ligado");
        else Serial.println("LED status: desligado");
        if (digitalRead(COOLER) == HIGH)        // Read LED status.
          Serial.println("COOLER status: ligado");
        else Serial.println("COOLER status: desligado");
        if (digitalRead(led) == HIGH)        // Read LED status;
          Serial.println("led status: ligado");
        else Serial.println("led status: desligado");
        break;

      case '?':                          // If received a ?:
        printHelp();                   // print the command list.
        break;

      default:
        Serial.print("'");
        Serial.print((char)rxChar);
        Serial.println("' is not a command!");
    }
  }
}
// End of the Sketch.
