int switchState = 0;

void setup() {
  pinMode(3,OUTPUT); // Green LED
  pinMode(4,OUTPUT); // Red LED 1
  pinMode(5,OUTPUT); // Red LED 2
  pinMode(2,INPUT);
}

void loop() {
  switchState = digitalRead(2);
  
  if (switchState == LOW) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else {
    digitalWrite(3, LOW);
    
    // Let the LED's blink 60 times.
    // Pin 4 and 5 are highlighted in succession. Each 30 times.
    for (int i = 0; i < 60; i++) {
      digitalWrite(4+i%2, HIGH);
      digitalWrite(5-i%2, LOW);
      delay(250);
    }
  }

}
