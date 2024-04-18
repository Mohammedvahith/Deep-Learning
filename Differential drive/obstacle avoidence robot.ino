char blueToothVal;
char lastValue;
//left wheel
int inl1=4;
int inl2=5;
int inl3=6;
int inl4=7;
//right wheel
int inr1=8;
int inr2=9;
int inr3=10;
int inr4=11;
//ultra sonic sensor
int trig=12;
int echo=13;
float duration;
int dist;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(inl1,OUTPUT);
  pinMode(inl2,OUTPUT);
  pinMode(inl3,OUTPUT);
  pinMode(inl4,OUTPUT);
  pinMode(inr1,OUTPUT);
  pinMode(inr2,OUTPUT);
  pinMode(inr3,OUTPUT);
  pinMode(inr4,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  digitalWrite(trig,0);
  delayMicroseconds(2);
  digitalWrite(trig,1);
  delayMicroseconds(10);
  digitalWrite(trig,0);
  duration=pulseIn(echo,1);
  dist=duration * 0.034 / 2;
  if(dist < 20)
  {
    digitalWrite(inl1,LOW);
    digitalWrite(inl2,HIGH);
    digitalWrite(inl3,LOW);   
    digitalWrite(inl4,HIGH);
    digitalWrite(inr1,LOW);
    digitalWrite(inr2,HIGH);
    digitalWrite(inr3,LOW);
    digitalWrite(inr4,HIGH);
  }
  else if(dist>=20 && dist<=25)
  {
    //right
    digitalWrite(inl1,HIGH);
    digitalWrite(inl2,LOW);
    digitalWrite(inl3,LOW);
    digitalWrite(inl4,HIGH);
    digitalWrite(inr1,LOW);
    digitalWrite(inr2,HIGH);
    digitalWrite(inr3,HIGH);
    digitalWrite(inr4,LOW);
  }
  else
  {
   //Forward direction
  digitalWrite(inl1, HIGH);
  digitalWrite(inl2, LOW);
  digitalWrite(inl3, HIGH);
  digitalWrite(inl4, LOW);
  digitalWrite(inr1,HIGH);
  digitalWrite(inr2, LOW);
  digitalWrite(inr3,HIGH);
  digitalWrite(inr4, LOW);
  }
}
