#include <Servo.h> //INCLUSÃO DA BIBLIOTECA NECESSÁRIA
 
const int pinoServo = 6; //PINO DIGITAL UTILIZADO PELO SERVO  


int botao1 = 2; //BOTAO LIGADO NO PIO 2
int estadodoBotao1 = 0;
int botao2 = 3; //BOTAO LIGADO NO PIO 2
int estadodoBotao2 = 0;


Servo s; //OBJETO DO TIPO SERVO
int pos; //POSIÇÃO DO SERVO
 
void setup (){
  s.attach(pinoServo); //ASSOCIAÇÃO DO PINO DIGITAL AO OBJETO DO TIPO SERVO
  s.write(0); //INICIA O MOTOR NA POSIÇÃO 0º
   pinMode (botao1, INPUT); 
    pinMode (botao2, INPUT); 
}
void loop(){
  estadodoBotao1 = digitalRead(botao1);
  if (estadodoBotao1 == HIGH){ //SE O BOTAO ESTIVER PRESSIONADO
    for(pos = 0; pos < 80; pos++){ //PARA "pos" IGUAL A 0, ENQUANTO "pos" MENOR QUE 180, INCREMENTA "pos"
    s.write(pos); //ESCREVE O VALOR DA POSIÇÃO QUE O SERVO DEVE GIRAR
   delay(1500); //INTERVALO DE 15 
    }
  }
   else{
    digitalWrite (pinoServo, LOW); // DEIXA O PINO SEM ENERGIA 
  }


estadodoBotao2 = digitalRead(botao2);
if (estadodoBotao2 == HIGH){
  for(pos = 80; pos >= 0; pos--){ //PARA "pos" IGUAL A 180, ENQUANTO "pos" MAIOR OU IGUAL QUE 0, DECREMENTA "pos"
    s.write(pos); //ESCREVE O VALOR DA POSIÇÃO QUE O SERVO DEVE GIRAR
    delay(15); //INTERVALO DE 15 
}
}
}




 
