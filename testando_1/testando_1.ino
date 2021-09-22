#include <Servo.h>  //incluir a biblioteca de servo

Servo s1;  //Inclusao do servo
Servo s2;  //Inclusao do servo

int n = 0;  //Entradas seriais
int pos = 0;  //Posição zero para o servop
int rxChar;

const int pinoServo1 = 7; //PINO DIGITAL UTILIZADO PELO SERVO 
const int pinoServo2 = 8; //PINO DIGITAL UTILIZADO PELO SERVO   


void setup(){
  Serial.begin(9600);  //Ativando a porta serial
  s1.attach(pinoServo1);  //Pino do servo+arduino
  s1.write(0);  //Servo setado com valor zero
  Serial.flush();  //Limpando a memoria do serial

  Serial.begin(9600);  //Ativando a porta serial
  s2.attach(pinoServo2);  //Pino do servo+arduino
  s2.write(0);  //Servo setado com valor zero
  Serial.flush();  //Limpando a memoria do serial
}

void loop (){
   if (Serial.available() > 0) {        // Check receive buffer.
    rxChar = Serial.read();            // Save character received.
    Serial.flush();                    // Clear receive buffer.

      switch (rxChar) {

    case 'a':
    case 'A':             // If received 'a' or 'A':

        if (s1.read(pinoServo1) == 0) {   // If LED is Off:
            s1.write(90);     // Turn On the LED.
          Serial.println("maca");
        }

        else Serial.println("Ja esta em posição maca!");
        break;
      }
   }
}
