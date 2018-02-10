const int s0=2;
const int s1=3;
const int s2=4;
const int s3=5;
const int sensorData=6;
const int ledRed=10;
const int ledGreen=11;
const int ledBlue=12;
const int ledYellow=13;
const int ledWhite=8;


int dataR=0;
int dataG=0;
int dataB=0;

void setup() 
{
   pinMode(s0,OUTPUT);
   pinMode(s1,OUTPUT);
   pinMode(s2,OUTPUT);
   pinMode(s3,OUTPUT);
   pinMode(sensorData,INPUT);
   Serial.begin(9600);

   digitalWrite(s0,HIGH);
   digitalWrite(s1,HIGH);
   
}

void loop()
{
   digitalWrite(s2,LOW);
   digitalWrite(s3,LOW);
   dataR=pulseIn(sensorData,LOW);
   delay(20);

   digitalWrite(s2,HIGH);
   digitalWrite(s3,HIGH);
   dataG=pulseIn(sensorData,LOW);
   delay(20);

   digitalWrite(s2,LOW);
   digitalWrite(s3,HIGH);
   dataB=pulseIn(sensorData,LOW);
   delay(20);

  bool found=false;
   
   if( !found && (dataR<16 && dataR>12) && (dataG<23 && dataG>19) && (dataB<19 && dataB>15))
   {
    found=true;
    Serial.println("this is the RED color");
    digitalWrite(ledRed, HIGH );
    digitalWrite(ledGreen, LOW ); 
    digitalWrite(ledBlue, LOW ); 
    digitalWrite(ledYellow, LOW ); 
    digitalWrite(ledWhite, LOW ); 
    delay(200); 
    }
   if( !found && (dataR<19 && dataR>15) && (dataG<22 && dataG>18) && (dataB<17 && dataB>13))
   {
    found=true;
    Serial.println("this is the Blue color");
    digitalWrite(ledRed, LOW );
    digitalWrite(ledGreen, LOW ); 
    digitalWrite(ledBlue, HIGH ); 
    digitalWrite(ledYellow, LOW ); 
    digitalWrite(ledWhite, LOW ); 
    delay(200);
    }
    if( !found && (dataR<18 && dataR>14) && (dataG<19 && dataG>15) && (dataB<18 && dataB>14))
   {
    found=true;
    Serial.println("this is the Green color");
    digitalWrite(ledRed, LOW );
    digitalWrite(ledGreen, HIGH ); 
    digitalWrite(ledBlue, LOW ); 
    digitalWrite(ledYellow, LOW ); 
    digitalWrite(ledWhite, LOW ); 
    delay(200);
    }
     if( !found && (dataR<13 && dataR>9) && (dataG<16 && dataG>12) && (dataB<15 && dataB>11))
   {
    found=true;
    Serial.println("this is the Yellow color");
    digitalWrite(ledRed, LOW );
    digitalWrite(ledGreen, LOW ); 
    digitalWrite(ledBlue, LOW ); 
    digitalWrite(ledYellow, HIGH ); 
    digitalWrite(ledWhite, LOW ); 
    delay(200);
   }
    if (!found)
    {   
     Serial.println("No color");
     digitalWrite(ledRed, LOW );
     digitalWrite(ledGreen, LOW ); 
     digitalWrite(ledBlue, LOW ); 
     digitalWrite(ledYellow, LOW ); 
     digitalWrite(ledWhite, HIGH ); 
     delay(200);
    }
   
}
