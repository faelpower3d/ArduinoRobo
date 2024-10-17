// C++ code
//
int trig = 13;
int echo = 12;
double motor11f = 11;  // Motor para frente (direção 1)
double motor10f = 10;  // Motor para frente (direção 1)
double motor9v = 9;    // Motor para trás (direção 2)
double motor8v = 8;    // Motor para trás (direção 2)
double upButton = 7;      
double downButton = 6;    
double leftButton = 5;    
double rightButton = 4; 
int serra = 3;

float distancia;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(motor11f, OUTPUT);
  pinMode(motor10f, OUTPUT);
  pinMode(motor9v, OUTPUT);
  pinMode(motor8v, OUTPUT);
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(serra, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {  
  mover();  

  // Sensor de distância
  digitalWrite(trig, HIGH);
  
  
  delay(10);
  digitalWrite(trig, LOW);
  distancia = pulseIn(echo, HIGH);
  distancia = distancia / 58;
  Serial.println(distancia);
  
  if (distancia<15){
    digitalWrite(serra, HIGH);  
  }else{
    digitalWrite(serra, LOW);  
  }
  
}

void mover() {   
  if (digitalRead(upButton) == LOW) {
    digitalWrite(motor10f, HIGH); 
    digitalWrite(motor11f, HIGH);
  } else {
    digitalWrite(motor10f, LOW); 
    digitalWrite(motor11f, LOW);      
  }

  if (digitalRead(downButton) == LOW) {
    digitalWrite(motor9v, HIGH); 
    digitalWrite(motor8v, HIGH); 
  } else {
    digitalWrite(motor9v, LOW); 
    digitalWrite(motor8v, LOW); 
  }

  if (digitalRead(leftButton) == LOW) {    
    digitalWrite(motor11f, HIGH); 
  } else {
    digitalWrite(motor11f, LOW); 
  }

  if (digitalRead(rightButton) == LOW) {    
    digitalWrite(motor10f, HIGH); 
  } else {
    digitalWrite(motor10f, LOW); 
  }
}
