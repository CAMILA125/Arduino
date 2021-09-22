/*
CGS arduino
CURSO ARDUINO - CIENCIA DA COMPUTAÇÃO- URI FW
AQUECIMENTO
*/


int ledPin = 8;
void setup(){
  pinMode (ledPin, OUTPUT); //O PINO DO LED SERA DE SAIDA  
}
void loop (){
  digitalWrite (ledPin, HIGH); //MANDA ENERGIA PARA O PINO 13
  delay (10000); //aguarda 1s
  digitalWrite(ledPin, LOW); //DESLIGA A ENERGIA
  delay (5000); //AGUARDA 1S
}
