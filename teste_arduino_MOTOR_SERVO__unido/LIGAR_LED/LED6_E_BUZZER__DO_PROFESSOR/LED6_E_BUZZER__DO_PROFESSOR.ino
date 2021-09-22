/* sensor de temperatura com o alarme*/
const int sensor= 0;
const int buzzer = 6;
int valorsensor = 0;
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;
const int led5 = 4;
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

  
  if (valorsensor > 0){
    digitalWrite (led1, HIGH);
  }
  else {
    digitalWrite (led1, LOW);
  }
  

  if (valorsensor > 40){
    digitalWrite (led2, HIGH);
  }
  else {
    digitalWrite (led2, LOW);
  }


  if (valorsensor > 430 ){ 
    digitalWrite (led3, HIGH);
  }
  else {
    digitalWrite (led3, LOW);
    
   }

   
  if (valorsensor > 440 ){ 
    digitalWrite (led4, HIGH);
  }
  else {
    digitalWrite (led4, LOW);
    
   }


    if (valorsensor > 540 ){ 
    digitalWrite (led5, HIGH);
  }
  else {
    digitalWrite (led5, LOW);
    
   }

    if (valorsensor > 560 ){ 
    digitalWrite (led6, HIGH);
    digitalWrite (buzzer, HIGH);
  }
  else {
    digitalWrite (led6, LOW);
    digitalWrite (buzzer, LOW);
    
   }
  
}
