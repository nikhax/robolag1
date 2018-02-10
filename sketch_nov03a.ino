// defines pins numbers
#define tP1 10
#define eP1 11
#define jeshile1 13
#define blu1 12
#define tP2 6
#define eP2 5
#define b 13
#define jeshile2 4
#define blu2 2


// defines variables
float d1, Dis1, d2, Dis2;

void setup() {
pinMode(b, OUTPUT);
pinMode(tP1, OUTPUT);
pinMode(eP1, INPUT); 
pinMode(jeshile1, OUTPUT);
pinMode(blu1, OUTPUT);
pinMode(tP2, OUTPUT);
pinMode(eP2, INPUT); 
pinMode(jeshile2, OUTPUT);
pinMode(blu2, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(tP1, LOW);
delayMicroseconds(2);
digitalWrite(tP1, HIGH);
delayMicroseconds(10);
digitalWrite(tP1, LOW);
digitalWrite(tP2, LOW);
delayMicroseconds(2);
digitalWrite(tP2, HIGH);
delayMicroseconds(10);
digitalWrite(tP2, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
d1 = pulseIn(eP1, HIGH);
d2 = pulseIn(eP2, HIGH);

// Calculating the distance
Dis1 = (d1/2) *0.0343;
Dis2 = (d2/2) *0.0343; 

if (Dis1 <= 10 ){
  if (Dis1 <=5  ){
    tone(b, 3000); 
  } else
tone(b, 5000);  
digitalWrite(jeshile1, LOW);
digitalWrite(blu1, HIGH);
}
else{      
noTone(b);      
digitalWrite(blu1, LOW);
digitalWrite(jeshile1, HIGH );  
}

if (Dis2 <= 10){
  if (Dis2 <=5){
    tone(b, 3000); 
  } else  
digitalWrite(jeshile2, LOW);
digitalWrite(blu2, HIGH);
}
else{       
tone(b, 5000);     
digitalWrite(blu2, LOW);
digitalWrite(jeshile2, HIGH );  
}

// Prints the distance on the Serial Monitor
String s1 = String("Front Distance: " + String(Dis1, DEC) );
String s2 = String(s1 + " cm");
String s3 = String("Back Distance: " + String(Dis2, DEC) );
String s4 = String(s3 + " cm");
Serial.println(s2);
Serial.println(s4);
delay(1000);
}
