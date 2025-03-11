#define redLED 10 //redLED pin
#define greenLED 9 //greenLED pin

int light = 0;
int num = 5;

void setup()
{
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop()
{
  // digitalWrite(redLED, HIGH); //redLED set HIGH
  // digitalWrite(greenLED, LOW); //greenLED set LOW
  // delay(1000); //wait 1 second
  // digitalWrite(redLED, LOW); //redLED set LOW
  // digitalWrite(greenLED, HIGH); //greenLED set HIGH
  // delay(1000); //wait 1 second

  analogWrite(redLED, light);
  analogWrite(greenLED, 255 - light);
  light += num;

  if(light == 0 || light == 255) {
    num *= -1;
  }
  delay(20);
}