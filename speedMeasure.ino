/* 

Code completed on 27-04-2025 22:54 pm IST.

You are free to use the code anyhow you want, but please try to keep this comment attached. It means a lot to me.

  _____  _____ _______ _    _ _____ _   _ 
 |  __ \|_   _|__   __| |  | |_   _| \ | |
 | |__) | | |    | |  | |__| | | | |  \| |
 |  _  /  | |    | |  |  __  | | | | . ` |
 | | \ \ _| |_   | |  | |  | |_| |_| |\  |
 |_|  \_\_____|  |_|  |_|  |_|_____|_| \_|

Support me 

Github - https://github.com/RithinM69

*/

const int trigPin = 7;
const int echoPin = 8;


long duration;
int distance1=0;
int distance2=0;
int distance=0;
double Speed=0;


void setup() 
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);

}


void loop() 
{

    distance1 = ultrasonicRead();
    delay(1000);   
    distance2 = ultrasonicRead();
   

    Speed = (distance2 - distance1)/1.0;
    Serial.print("Speed :"); 
    Serial.print(Speed);
    Serial.println(" cm/s"); 
}
 
float ultrasonicRead ()
{

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);


    distance= duration*0.034/2;

//    Serial.print("Distance in cm : ");
//    Serial.println(distance);

    return distance;
}
