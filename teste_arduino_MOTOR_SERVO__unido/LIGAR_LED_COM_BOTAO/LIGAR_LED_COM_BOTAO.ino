/*
conforme o botao e precionado liga o led
*/

int led = 13; //LED NO PINO 13
int botao=2; //BOTAO LIGADO NO PIO 2
int estadodoBotao = 0; //vaariavel para saber se o botao esta pressionado
void setup(){
  pinMode (led, OUTPUT); //PINO DO LED SAIDA
  pinMode (botao, INPUT); //PINO COM O BOTAO SERA A ENTRADA
}
void loop(){
  estadodoBotao = digitalRead(botao);
  if (estadodoBotao == HIGH){ //SE O BOTAO ESTIVER PRESSIONADO
    digitalWrite (led, HIGH) ; // LIGA O LED DO PINO 13
  }
  else{
    digitalWrite (led, LOW); // DEIXA O PINO SEM ENERGIA 
  }
}
