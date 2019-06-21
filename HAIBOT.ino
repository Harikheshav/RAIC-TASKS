const int leftForward = 2; //Left motor pin1
const int leftBackward = 3;  //Left motor pin2
const int rightForward = 4;  //Right motor pin1
const int rightBackward = 5;  //Right motor pin2
const int soundsensor=6;  //Detecting Clap
const int IR_RECV=10;    //Detecting Obstacle
int F=0;//Flag var
void setup() 
{
  //DIFF COLOURED LEDS 
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  //motor pins
  pinMode(leftForward , OUTPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(rightForward , OUTPUT);
  pinMode(rightBackward , OUTPUT);
  //Detecting Clap
  pinMode(soundsensor,INPUT);
  //Detecting Obstacle
  pinMode(IR_RECV,INPUT);
  //Increasing the Randomness
  randomSeed(analogRead(1));
}
 
void loop()
{
  if(digitalRead(soundsensor)==HIGH||F==1)//clap detection and sustaining of condition[flag]
      { F=1;
        digitalWrite(leftForward , HIGH);
    digitalWrite(leftBackward , LOW);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW); } //Move Forward
     if(digitalRead(IR_RECV)==LOW) //Obstacle Detection
   {
    digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , LOW);
    digitalWrite(rightForward , LOW); 
    digitalWrite(rightBackward , LOW); //Stop
     int n=random(7);
     int m=random(6);
     digitalWrite(m+9,HIGH); //Random Lights
     delay(n*500); //Random gaps
     digitalWrite(m+9,LOW); 
   
    } 
   
}
 
