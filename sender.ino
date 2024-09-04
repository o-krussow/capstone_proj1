void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  pinMode(11, OUTPUT);
}

void transmitByte(char incomingByte) {
  char mask = 0x01; //to and against

  for(int i = 7; 0 <= i; i--) {
    if ((incomingByte >> i) & mask == 0) {
      digitalWrite(11, LOW); //"Send" 0
    }
    else {
      digitalWrite(11, HIGH); //"Send" 1
    }
    delayMicroseconds(450); //2200 bps
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  //char incomingByte = 0;

  //if (Serial.available() > 0) {
  //  incomingByte = Serial.read();

  //  transmitByte(incomingByte);
  //  transmitByte(0x00);
  //}


  digitalWrite(11, HIGH);
  delay(1000);
  delayMicroseconds(450);
  digitalWrite(11, LOW);
  delayMicroseconds(450);
  delay(1000);


}
