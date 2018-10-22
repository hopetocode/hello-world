int pingPinL = P1_6;
int pingReceiveL = P1_7;
int pingPinR = P5_0;
int pingReceiveR = P5_2;


void setup() {
 // initialize serial communication:
 Serial.begin(9600);
}

void loop()
{
// inits
long durL, durR, cmL, cmR;

// Ask for data (left)
 pinMode(pingPinL, OUTPUT);
 digitalWrite(pingPinL, LOW);
 delayMicroseconds(2);
 digitalWrite(pingPinL, HIGH);
 delayMicroseconds(10);
 digitalWrite(pingPinL, LOW);

// Read in data
 pinMode(pingReceiveL, INPUT);
 durL = pulseIn(pingReceiveL, HIGH);

 // Ask for data (right)
 pinMode(pingPinR, OUTPUT);
 digitalWrite(pingPinR, LOW);
 delayMicroseconds(2);
 digitalWrite(pingPinR, HIGH);
 delayMicroseconds(10);
 digitalWrite(pingPinR, LOW);

// Read in data
 pinMode(pingReceiveR, INPUT);
 durR = pulseIn(pingReceiveR, HIGH);

 // convert the times into distances
 cmL = msToCm(durL);
 cmR = msToCm(durR);

 // Side decision
 if (cmL < 100 | cmR < 100) {
  if (cmL < cmR) {
    // Servo turns to left
    
  }else if (cmL > cmR) {
    // Servo turns to right
    
  }else{
    // Servo turns forward
    
  }
  // Arms raise corresponding to distance
  
 }else{
  // Servo turns forward
  
 }


 Serial.print(cmL);
 Serial.print("cm (left)");
 Serial.println();
 Serial.print(cmR);
 Serial.print("cm (right)");
 Serial.println();

 delay(1000);
}

long msToCm(long ms)
{
 return ms / 58;
}
