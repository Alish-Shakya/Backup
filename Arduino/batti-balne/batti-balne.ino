int ldrPin = A0;
int ldrVal  = 0;
int ledPin = LED_BUILTIN;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    ldrVal =analogRead(ldrPin);
    Serial.println(ldrVal);

    

    if (ldrVal < 500){
      digitalWrite(ledPin, HIGH);
      Serial.println("on");
    }
    else{
      digitalWrite(ledPin, LOW);
      Serial.println("off");
    }
    delay(100);

}
