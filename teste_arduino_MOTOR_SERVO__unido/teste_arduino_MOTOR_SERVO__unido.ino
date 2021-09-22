#include <Servo.h> //INCLUSÃO DA BIBLIOTECA NECESSÁRIA

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
 
const int pinoServo = 7; //PINO DIGITAL UTILIZADO PELO SERVO  
 
Servo s; //OBJETO DO TIPO SERVO
int pos; //POSIÇÃO DO SERVO

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

void setup (){
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
  // inicio codigo servo
  s.attach(pinoServo); //ASSOCIAÇÃO DO PINO DIGITAL AO OBJETO DO TIPO SERVO
  s.write(0); //INICIA O MOTOR NA POSIÇÃO 0º

  // 
   
}
void loop(){
    delay(1000); //INTERVALO DE 1 SEGUNDO
  for(pos = 0; pos < 80; pos++){ //PARA "pos" IGUAL A 0, ENQUANTO "pos" MENOR QUE 180, INCREMENTA "pos"
    s.write(pos); //ESCREVE O VALOR DA POSIÇÃO QUE O SERVO DEVE GIRAR
    delay(30); //INTERVALO DE 15 MILISSEGUNDOS
  }
  delay(1000); //INTERVALO DE 1 SEGUNDO
  for(pos = 80; pos >= 0; pos--){ //PARA "pos" IGUAL A 180, ENQUANTO "pos" MAIOR OU IGUAL QUE 0, DECREMENTA "pos"
    s.write(pos); //ESCREVE O VALOR DA POSIÇÃO QUE O SERVO DEVE GIRAR
    delay(15); //INTERVALO DE 15 MILISSEGUNDOS
    
  }
   if (Serial.available() > 0) {        // Check receive buffer.
    rxChar = Serial.read();            // Save character received.
    Serial.flush();                    // Clear receive buffer.

    switch (rxChar) {

      case 'a':
      case 'A':                          // If received 'a' or 'A':
        if (digitalRead(LED) == LOW) {       // If LED is Off:
          digitalWrite(LED, HIGH);     // Turn On the LED.
          Serial.println("LED está ligado");
        }
        else Serial.println("LED já está ligado!");
        break;

      case 'd':
      case 'D':                          // If received 'd' or 'D':
        if (digitalRead(LED) == HIGH) {      // If LED is On:
          digitalWrite(LED, LOW);      // Turn Off the LED.
          Serial.println("LED está desligado");
        }
        else Serial.println("LED já está desligado!");
        break;
      case 'c':
      case 'C':                          // If received 'a' or 'A':
        if (digitalRead(COOLER) == LOW) {       // If LED is Off:
          digitalWrite(COOLER, HIGH);     // Turn On the LED.
          Serial.println("COOLER está ligado");
        }
        else Serial.println("COOLER já está ligado!");
        break;

      case 'r':
      case 'R':                          // If received 'd' or 'D':
        if (digitalRead(COOLER) == HIGH) {      // If LED is On:
          digitalWrite(COOLER, LOW);      // Turn Off the LED.
          Serial.println("COOLER está desligado");
        }
        else Serial.println("COOLER já está desligado!");
        break;
      case 'v':
      case 'V':                          // If received 'a' or 'A':
        if (digitalRead(led) == LOW) {       // If LED is Off:
          digitalWrite(led, HIGH);     // Turn On the LED.
          Serial.println("led está ligado");
        }
        else Serial.println("led já está ligado!");
        break;

      case 'x':
      case 'X':                          // If received 'd' or 'D':
        if (digitalRead(led) == HIGH) {      // If LED is On:
          digitalWrite(led, LOW);      // Turn Off the LED.
          Serial.println("led está desligado");
        }
        else Serial.println("led já está desligado!");
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
  
}/// inicio do proximo codigo 



// End of the Sketch.
