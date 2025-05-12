/* 

Code completed on 27-04-2025 22:54 pm IST.

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
