void setup() {
  pinMode(9,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(9,HIGH);
delay(2000);
digitalWrite(9,LOW);
delay(1000);
}
