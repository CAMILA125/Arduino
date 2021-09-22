// EXERCICIO 2
// COPONENTES UTILIZADOS;
//3LEDS, 3BOTOES
//DESCRICAO --CONFORME VC PRECIONAR QUALQUER BOTAO LEDS DE DIFERENTES CORES SAO ACESSOS

int ledPin1 = 13;
int ledPin2 = 12;
int ledPin3 = 11;

int botao1 = 2;
int botao2 = 3;
int botao3 = 4;

int estadodobotao1 = 0;
int estadodobotao2 = 0;
int estadodobotao3 = 0;


void setup (){
  pinMode(ledPin1, OUTPUT);
  pinMode(botao1, INPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(botao2, INPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(botao3, INPUT);
}


void loop (){
  estadodobotao1 = digitalRead (botao1);
  estadodobotao2 = digitalRead (botao2);
  estadodobotao3 = digitalRead (botao3);
    if (estadodobotao1 == HIGH){
    digitalWrite (ledPin1, HIGH);
    }
    else{
    digitalWrite (ledPin1, LOW);
    }
     if (estadodobotao2 == HIGH){
    digitalWrite (ledPin2, HIGH);
    }
    else{
    digitalWrite (ledPin2, LOW);
    }
     if (estadodobotao3 == HIGH){
    digitalWrite (ledPin3, HIGH);
    }
    else{
    digitalWrite (ledPin3, LOW);
    }
  
}
