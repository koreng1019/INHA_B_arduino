#define trigger 11 //trigger pin
#define echo 12 //echo pin

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
  duration = pulseIn(echo, HIGH);
  distance = duration * 17 / 1000;
  Serial.println(duration );
  Serial.print("\nDistance : ");
  Serial.print(distance);
  Serial.println(" Cm");
}
