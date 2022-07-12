int led1 = 9;
int led2 = 10;
int led3 = 11;

void setup()
{
  pinMode(led1,OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}
void loop()
{
  fadeOn(1000, 5, led1);
  fadeOff(1000, 5, led1);
  delay(1000);
  fadeOn(1000, 5, led2);
  fadeOff(1000, 5, led2);
  delay(1000);
  fadeOn(1000, 5, led3);
  fadeOff(1000, 5, led3);
  delay(1000);
}

void fadeOn(unsigned int time,int increament, int led){
  for(byte value=0;value<255;value+=increament){
            analogWrite(led, value);
            delay(time/(255/increament));
   }
}
 
void fadeOff(unsigned int time,int decreament, int led){
  for(byte value=255;value>0;value-=decreament){
        analogWrite(led,value);
            delay(time/(255/decreament));
    }
}
