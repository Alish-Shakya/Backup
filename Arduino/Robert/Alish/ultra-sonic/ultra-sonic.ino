

//define pin number
const int triger = 9;
const int ecopin= 10;

float distance, time;


void setup() {
  // put your setup code here, to run once:
  pinMode(triger, OUTPUT);//start the triger pin as output
  pinMode(ecopin, INPUT);//start the ecopin as input
  Serial.begin(9600);//starts the serial communtication
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(triger, HIGH);
  delay(10);
  digitalWrite(triger,LOW);
  
  time = pulseIn(ecopin, HIGH);
  distance = (time*34300)/2;
  // Serial.print("the time taken is"+time);
  Serial.print(distance);
  delay(500);

}
