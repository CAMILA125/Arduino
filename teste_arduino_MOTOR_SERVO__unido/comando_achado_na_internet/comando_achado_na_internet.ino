'#include <Servo.h>  //incluir a biblioteca de servo

Servo myservo;  //Inclusao do servo
Servo myservo2;  //Inclusao do servo

int n = 0;  //Entradas seriais
int pos = 0;  //Posição zero para o servop

void setup(){
  Serial.begin(9600);  //Ativando a porta serial
  myservo.attach(8);  //Pino do servo+arduino
  myservo2.attach(7);
  myservo.write(0);  //Servo setado com valor zero
   myservo2.write(0);  //Servo setado com valor zero
  Serial.flush();  //Limpando a memoria do serial
  Serial.println("Digite: ");  //criação de um cabeçalho no serial
  Serial.println("1 para CADEIRA "); 
  Serial.println("2 para MACA "); 
}


void loop(){
  if(Serial.available()>0){  //Teste se porta serial esta recebendo dados
    n = Serial.read();  //leitura de dados
    Serial.print("Valor lido: ");  
    Serial.println(n);  //Printa o valor teclado

    if(n==50){  //girar 90
    myservo.write(0);
    delay(500);
    }

    if(n==51){  //girar 180
    myservo.write(90);
    delay(500);
    }

if(n==50){  //girar 90
    myservo2.write(90);
    delay(500);
    }

    if(n==51){  //girar 180
    myservo2.write(180);
    delay(500);
    }  
    
  }


  Serial.flush();
}
