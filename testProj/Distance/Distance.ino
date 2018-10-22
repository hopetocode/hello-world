const int pingPin = P1_6;
const int pingReceive = P1_7;

void setup() {
 // initialize serial communication:
 Serial.begin(9600);
}

void loop()
{
 // establish variables for duration of the ping, 
 // and the distance result in inches and centimeters:
 long duration, inches, cm;

 // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
 // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
 pinMode(pingPin, OUTPUT);
 digitalWrite(pingPin, LOW);
 delayMicroseconds(2);
 digitalWrite(pingPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(pingPin, LOW);

 // The same pin is used to read the signal from the PING))): a HIGH
 // pulse whose duration is the time (in microseconds) from the sending
 // of the ping to the reception of its echo off of an object.
 pinMode(pingReceive, INPUT);
 duration = pulseIn(pingReceive, HIGH);

 // convert the time into a distance
 inches = msToIn(duration);
 cm = msToCm(duration);

 Serial.print(inches);
 Serial.print("in, ");
 Serial.print(cm);
 Serial.print("cm");
 Serial.println();

 delay(100);
}

long msToIn(long ms)
{
 return ms / 148;
}

long msToCm(long ms)
{
 return ms / 58;
}
