#include <Servo.h>  //incluir a biblioteca de servo

Servo s1;  //Inclusao do servo
Servo s2;  //Inclusao do servo

int n = 0;  //Entradas seriais
int pos = 0;  //Posição zero para o servop


void setup(){
  Serial.begin(9600);  //Ativando a porta serial
  s1.attach(8);  //Pino do servo+arduino
  s2.attach(7);
  s1.write(0);  //Servo setado com valor zero
  s2.write(0);  //Servo setado com valor zero
  Serial.flush();  //Limpando a memoria do serial
  Serial.println("--- Lista de commandos : ---");
  Serial.println("Digite: ");  //criação de um cabeçalho no serial
  Serial.println("1 alterar para CADEIRA "); 
  Serial.println("2 alterar para MACA "); 
}


void loop(){
  
  if(Serial.available()>0){  //Teste se porta serial esta recebendo dados
    n = Serial.read();  //leitura de dados
    
    
        if(n==49){  
          s1.write(0);
          s2.write(90);
          delay(500);
          Serial.println("ALTERADA PARA CADEIRA "); 
          Serial.println (" ");
         }

        if(n==50){  
          s1.write(75);
          s2.write(0);
          delay(500);
          Serial.println("ALTERADA PARA MACA"); 
          Serial.println (" ");
         }
    }
      Serial.flush();
}
