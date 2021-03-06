#include

#include

/* define L298N or L293D motor control pins */

int leftMotorForward = 2; /* GPIO2(D4) -> IN3 */

int rightMotorForward = 15; /* GPIO15(D8) -> IN1 */

int leftMotorBackward = 0; /* GPIO0(D3) -> IN4 */

int rightMotorBackward = 13; /* GPIO13(D7) -> IN2 */

int z;

/* define L298N or L293D enable pins */

int rightMotorENB = 14; /* GPIO14(D5) -> Motor-A Enable */

int leftMotorENB = 12; /* GPIO12(D6) -> Motor-B Enable *

  / You should get Auth Token in the Blynk App. // Go to the Project Settings (nut icon).

  // Use your own WiFi settings

  char auth[] = "**********";

  char ssid[] = "type your network name here ";

  char pass[] = "type your network password here";

  // neutral zone settings for x and y

  // joystick must move outside these boundary numbers to activate the motors

  // makes it a little easier to control the wifi car

  int minRange = 312;

  int maxRange = 712;

  // analog speeds from 0 (lowest) - 1023 (highest)

  // 3 speeds used -- 0 (noSpeed), 350 (minSpeed), 850 (maxSpeed).

  // use whatever speeds you want...too fast made it a pain in the ass to control

  int minSpeed = 450;

  int maxSpeed = 1023;

  int noSpeed = 0;

  void moveControl(int x, int y) {

  // movement logic // move forward

  // y je vetsi jak maxrange a současně x je vetsi jak minRange a současne mensi jak max range

  if(y >= maxRange && x >= minRange && x <= maxRange) {

  analogWrite(leftMotorENB,z);

  analogWrite(rightMotorENB,z);

  digitalWrite(leftMotorForward,HIGH);

  digitalWrite(rightMotorForward,HIGH);

  digitalWrite(leftMotorBackward,LOW);

  digitalWrite(rightMotorBackward,LOW); } //MOVE FORWARD RIGHT

  else if(x <= minRange && y >= maxRange ) {

  digitalWrite(leftMotorENB,maxSpeed);

  digitalWrite(rightMotorENB,minSpeed);

  digitalWrite(leftMotorForward,HIGH);

  digitalWrite(rightMotorForward,HIGH);

  digitalWrite(rightMotorBackward,LOW);

  digitalWrite(leftMotorBackward,LOW); } // move right

  else if(x >= maxRange && y >= minRange && y<=maxRange)

  { analogWrite(leftMotorENB,z);

  analogWrite(rightMotorENB,z);

  digitalWrite(leftMotorForward,HIGH);

  digitalWrite(rightMotorForward,LOW);

  digitalWrite(rightMotorBackward,HIGH);

  digitalWrite(leftMotorBackward,LOW);

  }

  // move forward LEFT

  else if(x <= minRange && y >= maxRange ) {

  digitalWrite(leftMotorENB,minSpeed);

  digitalWrite(rightMotorENB,maxSpeed);

  digitalWrite(leftMotorForward,HIGH);

  digitalWrite(rightMotorForward,HIGH);

  digitalWrite(rightMotorBackward,LOW);

  digitalWrite(leftMotorBackward,LOW); }

  // moveleft else if(x <= minRange && y >= minRange && y <= maxRange) {

  analogWrite(leftMotorENB,z);

  analogWrite(rightMotorENB,z);

  digitalWrite(leftMotorForward,LOW);

  digitalWrite(rightMotorForward,HIGH);

  digitalWrite(rightMotorBackward,LOW);

  digitalWrite(leftMotorBackward,HIGH); }

  // neutral zone

  else if(y < maxRange && y > minRange && x < maxRange && x > minRange)

  { digitalWrite(leftMotorENB,LOW);

  digitalWrite(rightMotorENB,LOW);

  digitalWrite(leftMotorForward,LOW);

  digitalWrite(leftMotorBackward,LOW);

  digitalWrite(rightMotorForward,LOW);

  digitalWrite(rightMotorBackward,LOW); }

  // move back

  else if(y <= minRange && x >= minRange && x <= maxRange) {

  analogWrite(leftMotorENB,z);

  analogWrite(rightMotorENB,z);

  digitalWrite(leftMotorBackward,HIGH);

  digitalWrite(rightMotorBackward,HIGH);

  digitalWrite(leftMotorForward,LOW);

  digitalWrite(rightMotorForward,LOW); }

  // move back and right

  else if(y <= minRange && x <= minRange) {

  digitalWrite(leftMotorENB,maxSpeed);

  digitalWrite(rightMotorENB,minSpeed);

  digitalWrite(leftMotorForward,LOW);

  digitalWrite(rightMotorForward,LOW);

  digitalWrite(rightMotorBackward,HIGH);

  digitalWrite(leftMotorBackward,HIGH); }

  // move back and left

  else if(y <= minRange && x >= maxRange) {

  digitalWrite(leftMotorENB,minSpeed);

  digitalWrite(rightMotorENB,maxSpeed);

  digitalWrite(leftMotorForward,LOW);

  digitalWrite(rightMotorForward,LOW);

  digitalWrite(rightMotorBackward,HIGH);

  digitalWrite(leftMotorBackward,HIGH); } }

  void setup() {

  // initial settings for motors off and direction forward

  pinMode(leftMotorForward, OUTPUT);

  pinMode(rightMotorForward, OUTPUT);

  pinMode(leftMotorBackward, OUTPUT);

  pinMode(rightMotorBackward, OUTPUT);

  /* initialize motor enable pins as output */

pinMode(leftMotorENB, OUTPUT);

pinMode(rightMotorENB, OUTPUT);

Blynk.begin(auth, ssid, pass);
}

void loop() {

  Blynk.run();
}

BLYNK_WRITE(V1)

{ int x = param[0].asInt();

  int y = param[1].asInt();

  moveControl(x, y);
}

BLYNK_WRITE(V2)

{
  z = param[0].asInt();
}
