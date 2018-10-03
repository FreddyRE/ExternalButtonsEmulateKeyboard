int pushButtonLimpiadores = 2; //LEtra o 
int pushButtonLucesAltas = 3;  //letra k 
int pushButtonIntermitentes = 4; // letra j 
int pushButtonFrenoMano = 5; // Letra n 
int pushButtonReversa = 6; // Letra m  
int palancaDireccionDerecha = 7; //letra x 
int palancaDireccionIzquierda = 8; // letra z 
int cinturon = 9;


//String Volante = "#"; //volante 1
//String Volante = "h";

int buttonStateFrenoMano = 0;
int buttonStateReversa = 0;
int buttonStateIntermitentes = 0;
int buttonStateLucesAltas= 0;
int butoonStateLimpiadores = 0;
int buttonStateDireccionDerecha = 0;
int buttonStateDireccionIzquierda = 0;

//int buttonStatePalancaDireccionIzquierda = 0;
//int buttonStatePalancaDireccionDerecha = 0;
//int buttonStatePushButtonLucesAltas = 0;
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
  pinMode(pushButtonLucesAltas, INPUT);
  pinMode(pushButtonLimpiadores, INPUT);
  pinMode(palancaDireccionDerecha, INPUT);
  pinMode(palancaDireccionIzquierda, INPUT);
  //pinMode(pushButtonLucesAltas, INPUT);
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
  //Serial.println(Volante);
  buttonStateFrenoMano = digitalRead(pushButtonFrenoMano);
  buttonStateReversa = digitalRead(pushButtonReversa);
  buttonStateIntermitentes = digitalRead(pushButtonIntermitentes);
  buttonStateLucesAltas = digitalRead(pushButtonLucesAltas);
  butoonStateLimpiadores = digitalRead(pushButtonLimpiadores);
  buttonStateDireccionIzquierda = digitalRead(palancaDireccionIzquierda);
  buttonStateDireccionDerecha = digitalRead(palancaDireccionDerecha);
  cinturonState = digitalRead(cinturon);

  if(buttonStateFrenoMano == HIGH){
    Serial.println("n");
    delay(10);
  } else {
    delay(10);
    //Serial.println("#");
  }

  if(buttonStateReversa == HIGH){
    Serial.println("m");
    delay(10);
  } else {
    delay(10);
    //Serial.println("#");
  }
  if(buttonStateIntermitentes == HIGH){
    Serial.println("j");
    delay(10);
  } else {
    delay(10);
   // Serial.println("#");
  }
  
  if(buttonStateLucesAltas == HIGH){
    Serial.println("k");
    delay(10);
  } else {
    delay(10);
   // Serial.println("#");
  }
  if(butoonStateLimpiadores== HIGH){
   Serial.println("o");
    delay(10);
  } else {
    delay(10);
    //Serial.println("#");
  }
  
  if(buttonStateDireccionIzquierda == HIGH){
   Serial.println("z");
    delay(10);
  } else {
    delay(10);
    //Serial.println("#");
  }
  if(buttonStateDireccionDerecha == HIGH){
    Serial.println("x");
    delay(10);
  } else {
    delay(10);
   //2Serial.println("#");
  }

  
  if(cinturonState == HIGH){
    Serial.println("h");
    delay(10);
  } else {
    delay(10);
  }
  
}
