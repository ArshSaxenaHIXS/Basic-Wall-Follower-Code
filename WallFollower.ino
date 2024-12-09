int offset = 8;
int frontIRtrig = 6;
int frontIRecho = 11;
int rightIRtrig = 2;
int rightIRecho = 4;
int leftIRtrig = 7;
int leftIRecho = 8;
int lmf = 5;
int lmr = 3;
int rmf = 9;
int rmr = 10;
int basespeed = 100;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float getFront = getDistance(frontIRtrig, frontIRecho);
  float getRight = getDistance(rightIRtrig, rightIRecho);
  float getLeft = getDistance(leftIRtrig, leftIRecho);

  int error  = (getLeft - 4)*0.7;
  moveMotor(basespeed-error ,basespeed+error);

  Serial.println(getFront);


   

}
float getDistance(int trigPin, int echoPin) {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH, 100000);
  return (duration * 0.0343) / 2 ;
}

void moveMotor(int lms, int rms){
 lms = constrain(lms,-255,255);
 rms = constrain(rms,-255,255);

 if(rms > 0 ){
  analogWrite(rmf,rms);
  analogWrite(rmr,0);
 }else{
  analogWrite(rmf,0);
  analogWrite(rmr,-rms);
 }
 if(lms > 0){
  analogWrite(lmf,lms);
  analogWrite(lmr,0);
 }else{
  analogWrite(lmf,0);
  analogWrite(lmr,-lms);
 }
}
