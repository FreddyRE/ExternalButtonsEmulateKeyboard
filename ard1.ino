int pushButtonFrenoMano = 2;
int pushButtonReversa = 3;
int pushButtonIntermitentes = 4;
int pushButtonEncendidoLuces = 5;
int palancaDireccionIzquierda = 6;
int palancaDireccionDerecha = 7;
int pushButtonLucesAltas = 8;
int cinturon = 9;

int buttonStateFrenoMano = 0;
int buttonStateReversa = 0;
int buttonStateIntermitentes = 0;
int buttonStateEncendidoLuces = 0;
int buttonStatePalancaDireccionIzquierda = 0;
int buttonStatePalancaDireccionDerecha = 0;
int buttonStatePushButtonLucesAltas = 0;
int cinturonState = 0;

const unsigned int TRIG_PIN=13;
const unsigned int ECHO_PIN=12;
const unsigned int BAUD_RATE=9600;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pushButtonFrenoMano, INPUT);
  pinMode(pushButtonReversa, INPUT);
  pinMode(pushButtonIntermitentes, INPUT);
  pinMode(pushButtonEncendidoLuces, INPUT);
  pinMode(palancaDireccionIzquierda, INPUT);
  pinMode(palancaDireccionDerecha, INPUT);
  pinMode(pushButtonLucesAltas, INPUT);
  pinMode(cinturon, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

/*
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  const unsigned long duration= pulseIn(ECHO_PIN, HIGH);
  int distance= duration/29/2;
  if(duration==0){
   Serial.println("Warning: no pulse from sensor");
   } 
  else{
    
      if(distance <= 4){
          Serial.println("cinturon cerrado");
        }
        else{
          Serial.println("cinturon abierto");
        }
      
     // Serial.print("distance to nearest object:");
     // Serial.println(distance);
     // Serial.println(" cm");
}*/

  delay(100);

  buttonStateFrenoMano = digitalRead(pushButtonFrenoMano);
  buttonStateReversa = digitalRead(pushButtonReversa);
  buttonStateIntermitentes = digitalRead(pushButtonIntermitentes);
  buttonStateEncendidoLuces = digitalRead(pushButtonEncendidoLuces);
  buttonStatePalancaDireccionIzquierda = digitalRead(palancaDireccionIzquierda);
  buttonStatePalancaDireccionDerecha = digitalRead(palancaDireccionDerecha);
  buttonStatePushButtonLucesAltas = digitalRead(pushButtonLucesAltas);
  
  if(buttonStateFrenoMano == HIGH){
    Serial.println("n");
    delay(10);
  } else {
    Serial.println("Open State Freno");
    delay(10);
  }

  if(buttonStateReversa == HIGH){
    Serial.println("m");
    delay(10);
  } else {
    Serial.println("Open State Reversa");
    delay(10);
  }
  if(buttonStateIntermitentes == HIGH){
    Serial.println("j");
    delay(10);
  } else {
    Serial.println("Open State Intermitentes");
    delay(10);
  }
  if(buttonStateEncendidoLuces == HIGH){
    Serial.println("k");
    delay(10);
  } else {
    Serial.println("Open State Encenido Luces");
    delay(10);
  }
  if(buttonStatePalancaDireccionIzquierda == HIGH){
    Serial.println("z");
    delay(10);
  } else {
    Serial.println("Open State Direccional Izquierda");
    delay(10);
  }
  if(buttonStatePalancaDireccionDerecha == HIGH){
    Serial.println("x");
    delay(10);
  } else {
    Serial.println("Open State Direccional Derecha");
    delay(10);
  }
   if(buttonStatePushButtonLucesAltas == HIGH){
    Serial.println("l");
    delay(10);
  } else {
    Serial.println("Open State Luces Altas");
    delay(10);
  }
  if(cinturon == HIGH){
    Serial.println("h");
    delay(10);
  } else {
    Serial.println("Open State Cinturon ");
    delay(10);
  }
  
}
