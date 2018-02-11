const int s0=2;                        // Definiert die Anzahl der Pins 
const int s1=3;
const int s2=4;
const int s3=5;
const int sensorData=6;
const int ledRed=10;
const int ledGreen=11;
const int ledBlue=12;
const int ledYellow=13;
const int ledWhite=8;


int dataR=0;                          // Definierung von 3 globalen Parametern
int dataG=0;
int dataB=0;

void setup() 
{
   pinMode(s0,OUTPUT);                // Setzt das s0 als Ausgabe  
   pinMode(s1,OUTPUT);                // Setzt das s1 als Ausgabe  
   pinMode(s2,OUTPUT);                // Setzt das s2 als Ausgabe  
   pinMode(s3,OUTPUT);                // Setzt das s3 als Ausgabe  
   pinMode(sensorData,INPUT);         // Setzt das sensorData als Eingsbe 
   Serial.begin(9600);                // Startet die serielle Kommunikation 

   digitalWrite(s0,HIGH);             // setzt das digitale s0 auf   
   digitalWrite(s1,HIGH);             // setzt das digitale s1 auf 
   
}

void loop()
{
   digitalWrite(s2,LOW);              // setzt das digitale s2 ab 
   digitalWrite(s3,LOW);              // setzt das digitale s3 ab 
   dataR=pulseIn(sensorData,LOW);     // Berechnen die dataR
   delay(20);                         // wartet 0.02 Sekunde

   digitalWrite(s2,HIGH);             // setzt das digitale s2 auf 
   digitalWrite(s3,HIGH);             // setzt das digitale s3 auf 
   dataG=pulseIn(sensorData,LOW);     // Berechnen die dataG
   delay(20);                          // wartet 0.02 Sekunde

   digitalWrite(s2,LOW);               // setzt das digitale s2 ab 
   digitalWrite(s3,HIGH);              // setzt das digitale s3 auf 
   dataB=pulseIn(sensorData,LOW);      // Berechnen die dataB
   delay(20);                          // wartet 0.02 Sekunde

  bool found=false;
   
   if( !found && (dataR<16 && dataR>12) && (dataG<23 && dataG>19) && (dataB<19 && dataB>15))    //Werte, die von Farbsensor empfangen werden, sind die gleichen wie die in ()
   {
    found=true;
    Serial.println("this is the RED color");      // Druckt die Rot Farbe auf dem seriellen Monitor  
    digitalWrite(ledRed, HIGH );                  // setzt das ledRed auf 
    digitalWrite(ledGreen, LOW );                 // setzt das ledGreen ab  
    digitalWrite(ledBlue, LOW );                  // setzt das ledBlue ab  
    digitalWrite(ledYellow, LOW );                // setzt das ledYellow ab  
    digitalWrite(ledWhite, LOW );                 // setzt das ledWhite ab  
    delay(200);                                   // wartet 0.2 Sekunde
    }
   if( !found && (dataR<19 && dataR>15) && (dataG<22 && dataG>18) && (dataB<17 && dataB>13))    //Werte, die von Farbsensor empfangen werden, sind die gleichen wie die in ()
   {
    found=true;
    Serial.println("this is the Blue color");     // Druckt die Blau Farbe auf dem seriellen Monitor  
    digitalWrite(ledRed, LOW );                   // setzt das ledRed ab  
    digitalWrite(ledGreen, LOW );                 // setzt das ledGreen ab 
    digitalWrite(ledBlue, HIGH );                 // setzt das ledBlue auf  
    digitalWrite(ledYellow, LOW );                // setzt das ledYellow ab 
    digitalWrite(ledWhite, LOW );                 // setzt das ledWhite ab 
    delay(200);                                   // wartet 0.2 Sekunde
    }
    if( !found && (dataR<18 && dataR>14) && (dataG<19 && dataG>15) && (dataB<18 && dataB>14))   //Werte, die von Farbsensor empfangen werden, sind die gleichen wie die in ()
   {
    found=true;
    Serial.println("this is the Green color");    // Druckt die Grün Farbe auf dem seriellen Monitor  
    digitalWrite(ledRed, LOW );                   // setzt das ledRed ab  
    digitalWrite(ledGreen, HIGH );                // setzt das ledGreen auf 
    digitalWrite(ledBlue, LOW );                  // setzt das ledBlue ab
    digitalWrite(ledYellow, LOW );                // setzt das ledYellow ab 
    digitalWrite(ledWhite, LOW );                 // setzt das ledWhite ab 
    delay(200);                                   // wartet 0.2 Sekunde
    }
     if( !found && (dataR<13 && dataR>9) && (dataG<16 && dataG>12) && (dataB<15 && dataB>11))   //Werte, die von Farbsensor empfangen werden, sind die gleichen wie die in ()
   {
    found=true;
    Serial.println("this is the Yellow color");   // Druckt die Gelb Farbe auf dem seriellen Monitor  
    digitalWrite(ledRed, LOW );                   // setzt das ledRed ab  
    digitalWrite(ledGreen, LOW );                 // setzt das ledGreen ab
    digitalWrite(ledBlue, LOW );                  // setzt das ledBlue ab
    digitalWrite(ledYellow, HIGH );               // setzt das ledYellow auf 
    digitalWrite(ledWhite, LOW );                 // setzt das ledWhite ab 
    delay(200);                                   // wartet 0.2 Sekunde
   }
    if (!found)
    {   
     Serial.println("No color");                  // Druckt keine Farbe auf dem seriellen Monitor  
     digitalWrite(ledRed, LOW );                  // setzt das ledRed ab  
     digitalWrite(ledGreen, LOW );                // setzt das ledGreen ab
     digitalWrite(ledBlue, LOW );                 // setzt das ledBlue ab
     digitalWrite(ledYellow, LOW );               // setzt das ledYellow ab 
     digitalWrite(ledWhite, HIGH );               // setzt das ledWhite auf
     delay(200);                                  // wartet 0.2 Sekunde 
    }
   
}
