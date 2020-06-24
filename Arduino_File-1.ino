#define segA 0 
#define segB 1 
#define segC 2 
#define segD 3 
#define segE 4 
#define segF 5 
#define segG 6

int in4=53;
int in3=52;
int en2=51;
int en1=50;
int in2=49;
int in1=48;

int enM=A0;
int in1M=A1;
int in2M=A2;

int bl2=A4;
int bl1=A5;
int blg=A6;

int bG=8;
int b1=9;
int b2=10;

int lStatus=13;
int lState = 0;

void setup()
{

for (int i=0;i<7;i++)
{
pinMode(i,OUTPUT);
}
  
pinMode(in4, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(en2, OUTPUT);
pinMode(en1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in1, OUTPUT);

pinMode(enM, OUTPUT);
pinMode(in1M, OUTPUT);
pinMode(in2M, OUTPUT);

pinMode(bG, OUTPUT);
pinMode(b1, OUTPUT);
pinMode(b2, OUTPUT);

pinMode(bl2, OUTPUT);
pinMode(bl1, OUTPUT);
pinMode(blg, OUTPUT);

pinMode(lStatus, OUTPUT);
}

void loop()
{

if(digitalRead(bG) == HIGH && lState == 0){
  lState=0;
  segmentZero();
  doorOpen();
}

else if(digitalRead(bG) == HIGH && lState == 1){
  lState=0;
  segmentOne();
  doorClose();
  liftDown();
  segmentZero();
  doorOpen();
}
else if(digitalRead(bG) == HIGH && lState == 2){
  lState=0;
  segmentTwo();
  doorClose();
  liftDown();
  segmentOne();
  liftDown();
  segmentZero();
  doorOpen();
}

else if(digitalRead(b1) == HIGH && lState == 1){
  lState=1;
  segmentOne();
  doorOpen();
}

else if(digitalRead(b1) == HIGH && lState == 2){
  lState=1;
  segmentTwo();
  doorClose();
  liftDown();
  segmentOne();
  doorOpen();
}

else if(digitalRead(b1) == HIGH && lState == 0){
  lState=1;
  segmentZero();
  doorClose();
  liftUp();
  segmentOne();
  doorOpen();
}

else if(digitalRead(b2) == HIGH && lState == 2){
  lState=2;
  segmentTwo();
  doorOpen();
}

else if(digitalRead(b2) == HIGH && lState == 1){
  lState=2;
  segmentOne();
  doorClose();
  liftUp();
  segmentTwo();
  doorOpen();
}

else if(digitalRead(b2) == HIGH && lState == 0){
  lState=2;
  segmentZero();
  doorClose();
  liftUp();
  segmentOne();
  liftUp();
  segmentTwo();
  doorOpen();
}

else if(digitalRead(blg) == HIGH && lState == 0){
  lState=0;
  segmentZero();
  doorClose();
}

else if(digitalRead(bl1) == HIGH && lState == 0){
  lState=1;
  segmentZero();
  doorClose();
  liftUp();
  segmentOne();
  doorOpen();
}

else if(digitalRead(bl2) == HIGH && lState == 0){
  lState=2;
  segmentZero();
  doorClose();
  liftUp();
  segmentOne();
  liftUp();
  segmentTwo();
  doorOpen();
}

else if(digitalRead(blg) == HIGH && lState == 1){
  lState=0;
  segmentOne();
  doorClose();
  liftDown();
  segmentZero();
  doorOpen();
}

else if(digitalRead(bl2) == HIGH && lState == 1){
  lState=2;
  segmentOne();
  doorClose();
  liftUp();
  segmentTwo();
  doorOpen();
}

else if(digitalRead(blg) == HIGH && lState == 2){
  lState=0;
  segmentTwo();
  doorClose();
  liftDown();
  segmentOne();
  liftDown();
  segmentZero();
  doorOpen();
}

else if(digitalRead(bl1) == HIGH && lState == 2){
  lState=1;
  segmentTwo();
  doorClose();
  liftDown();
  segmentOne();
  doorOpen();
}

else{
 
}
liftStatus();
}


void doorOpen(){
digitalWrite(en2, HIGH); 
digitalWrite(in3, LOW); 
digitalWrite(in4, HIGH);  
digitalWrite(en1, HIGH); 
digitalWrite(in2, HIGH); 
digitalWrite(in1, LOW);
delay(500);
digitalWrite(en2, LOW);
digitalWrite(en1, LOW);
delay(500);
}

void doorClose(){
digitalWrite(en2, HIGH); 
digitalWrite(in3, HIGH); 
digitalWrite(in4, LOW);  
digitalWrite(en1, HIGH); 
digitalWrite(in2, LOW); 
digitalWrite(in1, HIGH);
delay(500);
digitalWrite(en2, LOW);
digitalWrite(en1, LOW);
delay(500);
}

void liftUp(){
digitalWrite(enM, HIGH); 
digitalWrite(in1M, HIGH); 
digitalWrite(in2M, LOW);  
delay(500);
digitalWrite(enM, LOW);
delay(500);
}

void liftDown(){
digitalWrite(enM, HIGH); 
digitalWrite(in1M, LOW); 
digitalWrite(in2M, HIGH);  
delay(500);
digitalWrite(enM, LOW);
delay(500);
}

void segmentDash(){
digitalWrite(segA, LOW);
digitalWrite(segB, LOW);
digitalWrite(segC, LOW);
digitalWrite(segD, LOW);
digitalWrite(segE, LOW);
digitalWrite(segF, LOW);
digitalWrite(segG, HIGH);
}

void segmentZero(){
digitalWrite(segA, HIGH);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, HIGH);
digitalWrite(segE, HIGH);
digitalWrite(segF, HIGH);
digitalWrite(segG, LOW);
}

void segmentOne(){
digitalWrite(segA, LOW);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, LOW);
digitalWrite(segE, LOW);
digitalWrite(segF, LOW);
digitalWrite(segG, LOW);
}

void segmentTwo(){
digitalWrite(segA, HIGH);
digitalWrite(segB, HIGH);
digitalWrite(segC, LOW);
digitalWrite(segD,HIGH);
digitalWrite(segE, HIGH);
digitalWrite(segF, LOW);
digitalWrite(segG, HIGH);
}

void liftStatus(){
digitalWrite(lStatus, HIGH);

}
