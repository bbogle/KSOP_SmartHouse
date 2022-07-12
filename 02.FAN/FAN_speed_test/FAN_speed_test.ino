int motor = 5;

void setup() {

}

void loop() {
  analogWrite(motor, 100);
  delay(3000);  
  analogWrite(motor, 155);
  delay(3000);  
  analogWrite(motor, 200);
  delay(3000);  
  analogWrite(motor, 255);
  delay(3000);  
  analogWrite(motor, 0);
  delay(10000);  
}
