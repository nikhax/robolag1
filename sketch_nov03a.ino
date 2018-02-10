// defines pins numbers
#define trigPin1 2
#define echoPin1 3
#define g 9
#define r 8
#define trigPin2 4
#define echoPin1 5
#define buzzer 6

float d1, Dis1, d2, Dis2;

void setup() {
pinMode(buzzer, OUTPUT);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT); 
pinMode(g, OUTPUT);
pinMode(r, OUTPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT); 
Serial.begin(9600); 
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);

d1 = pulseIn(echoPin1, HIGH);
d2 = pulseIn(echoPin2, HIGH);

Dis1 = (d1/2) *0.0343;
Dis2 = (d2/2) *0.0343; 

if (Dis1 <= 10 ){
  if (Dis1 <=5  ){
    tone(buzzer, 3000); 
  } else
tone(buzzer, 5000);  
digitalWrite(g, LOW);
digitalWrite(r, HIGH);
}
else{      
noTone(buzzer);      
digitalWrite(r, LOW);
digitalWrite(g, HIGH );  
}

if (Dis2 <= 10){
  if (Dis2 <=5){
    tone(buzzer, 3000); 
  } else  
digitalWrite(g, LOW);
digitalWrite(r, HIGH);
}
else{       
tone(buzzer, 5000);     
digitalWrite(r, LOW);
digitalWrite(g, HIGH );  
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
