/* sensor de temperatura*/


const int sensor = 0; // pino da entrada 0
int valorsensor = 0;

void setup() {
  Serial.begin  (9600);// controla a velocidade da entrada
}

void loop() {
   valorsensor = analogRead (sensor); // ler o que a porta serial analoga mandar
   Serial.print ("Valor do Sensor = ");
   Serial.println (valorsensor); // ln quebra linha
   delay (1000);// variavel le quanto tempo
}
