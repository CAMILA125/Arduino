/* sensor de temperatura com o alarme*/
const int sensor= 0;
const int buzzer = 6;
int valorsensor = 0;

void setup (){
 pinMode (buzzer, OUTPUT);
 Serial.begin (9600);
}
void loop (){
  valorsensor = analogRead (sensor);
  Serial.print ("Valor do sensore");
  Serial.println (valorsensor);
  if (valorsensor > 490) {
    digitalWrite (buzzer, HIGH);
  }
  else {
    digitalWrite (buzzer, LOW);
  }
}
