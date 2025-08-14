void setup() {
  pinMode(9, OUTPUT);// put your setup code here, to run once:
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

}

void loop() {

  for(int i=0; i<255; i=i+5)
  {
    analogWrite(11,i);
    delay(100);

      for(int i=255; i>2; i=i-5)
    {
      analogWrite(9,i);
      delay(20);
        
    }
      for(int i=0; i<255; i=i+5)
    {
      analogWrite(10,i);
      delay(100);
    }
  //   for(int i=255; i>2; i=i-5)
  // {
  //   analogWrite(11,i);
  //   delay(200);
  // }

  }
}