/* sensor de temperatura com o alarme*/
const int sensor= 0;
const int buzzer = 6;
int valorsensor = 0;
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;
const int led5 = 12;
const int led6 = 13;



void setup (){
 pinMode (buzzer, OUTPUT);
 pinMode (led1, OUTPUT);
 pinMode (led2, OUTPUT);
 pinMode (led3, OUTPUT);
 pinMode (led4, OUTPUT);
 pinMode (led5, OUTPUT);
 pinMode (led6, OUTPUT);
 Serial.begin (9600);
}
void loop (){
  valorsensor = analogRead (sensor);
  Serial.print ("Valor do sensore");
  Serial.println (valorsensor);

  if (valorsensor < 450){
    digitalWrite ( led1, HIGH);
    digitalWrite (led2, HIGH);
  }
 else {
  digitalWrite (led1, LOW); 
  digitalWrite (led2, LOW);
 }

  
 if (valorsensor > 451 and valorsensor < 460) {
    digitalWrite (led3, HIGH);
    digitalWrite (led4, HIGH);
  }
  else {
  digitalWrite (led3, LOW);
  digitalWrite (led4, LOW);
 }

 

  if (valorsensor < 490){
    digitalWrite (led5, HIGH);
    digitalWrite (led6, HIGH);
  }
   else {
  digitalWrite (led5, LOW);  
  digitalWrite (led6, LOW);
 }
    if (led6 == HIGH) {
    digitalWrite (buzzer, HIGH);
  }
  else {
    digitalWrite (buzzer, LOW);
  }
}
