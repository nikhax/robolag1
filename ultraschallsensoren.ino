#define trigPin1 2                // Definiert die Anzahl der Pins
#define echoPin1 3
#define g 9
#define r 8
#define trigPin2 4
#define echoPin1 5
#define buzzer 6

float d1, Dis1, d2, Dis2;         // definiert Variablen 

void setup() {
pinMode(buzzer, OUTPUT);          // Setzt das Buzzer als Ausgabe
pinMode(trigPin1, OUTPUT);        // Setzt das trigPin1 von Ultraschall1 als Ausgabe
pinMode(echoPin1, INPUT);         // Setzt das echoPin1 von Ultraschall1 als  Eingabe
pinMode(g, OUTPUT);               // Setzt das RGB-LED Ausgänge als  Eingabe
pinMode(r, OUTPUT);
pinMode(trigPin2, OUTPUT);         // Setzt das trigPin2 von Ultraschall2 als Ausgabe
pinMode(echoPin2, INPUT);          // Setzt das echoPin2 von Ultraschall2 als  Eingabe
Serial.begin(9600);                // Startet die serielle Kommunikation
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin1, LOW);        // setzt das digitale TrigPin1 ab
delayMicroseconds(2);               // Pausiert für 2 Mikrosekunden
digitalWrite(trigPin1, HIGH);       // setzt das digitale TrigPin1 auf
delayMicroseconds(10);              // Pausiert für 10 Mikrosekunden
digitalWrite(trigPin1, LOW);        // setzt das digitale TrigPin1 ab
digitalWrite(trigPin2, LOW);        // setzt das digitale TrigPin2 ab
delayMicroseconds(2);               // Pausiert für 2 Mikrosekunden
digitalWrite(trigPin2, HIGH);       // setzt das digitale TrigPin2 auf
delayMicroseconds(10);              // Pausiert für 10 Mikrosekunden
digitalWrite(trigPin2, LOW);        // setzt das digitale TrigPin2 ab

d1 = pulseIn(echoPin1, HIGH);       //Berechnen die Dauer1
d2 = pulseIn(echoPin2, HIGH);       //Berechnen die Dauer2

Dis1 = (d1/2) *0.0343;              // Berechnung der Abstand1
Dis2 = (d2/2) *0.0343;              // Berechnung der Abstand2

if (Dis1 <= 10 ){                   //Abstand1 weniger als 10 cm Summer macht Lärm mit Frequenz 5000
  if (Dis1 <=5  ){                  //Abstand1 weniger als 5 cm Summer macht Lärm mit Frequenz 3000
    tone(buzzer, 3000); 
  } else
tone(buzzer, 5000);  
digitalWrite(g, LOW);                //Abstand1 weniger als 10 cm RGB LED wird mit roter Farbe leuchten
digitalWrite(r, HIGH);               
}
else{      
noTone(buzzer);                      //Abstand1 mehr als 10 cm Summer macht kein Lärm 
digitalWrite(r, LOW);                //Abstand1 mehr als 10 cm RGB LED wird mit grüne Farbe leuchten
digitalWrite(g, HIGH );  
}

if (Dis2 <= 10){                      //Abstand2 weniger als 10 cm Summer macht Lärm mit Frequenz 5000
  if (Dis2 <=5){                      //Abstand2 weniger als 5 cm Summer macht Lärm mit Frequenz 3000
    tone(buzzer, 3000); 
  } else  
tone(buzzer, 5000); 
digitalWrite(g, LOW);                 //Abstand2 weniger als 10 cm RGB LED wird mit roter Farbe leuchten
digitalWrite(r, HIGH);
}
else{       
noTone(buzzer);                        //Abstand1 mehr als 10 cm Summer macht kein Lärm 
digitalWrite(r, LOW);                  //Abstand1 mehr als 10 cm RGB LED wird mit grüne Farbe leuchten
digitalWrite(g, HIGH );  
}

String s1 = String("Front Distance: " + String(Dis1, DEC) );      //Bearbeitet die Ansicht, die im seriellen Monitor angezeigt wird (Abstand1)
String s2 = String(s1 + " cm");
String s3 = String("Back Distance: " + String(Dis2, DEC) );       //Bearbeitet die Ansicht, die im seriellen Monitor angezeigt wird (Abstand2)
String s4 = String(s3 + " cm");
Serial.println(s2);                   // Druckt der Abstand1 auf dem seriellen Monitor
Serial.println(s4);                   // Druckt der Abstand1 auf dem seriellen Monitor
delay(1000);
}
