//!!!!!!MIGHT HAVE TO CHANGE DIGITALWRITE TO ANALOGUE
  
//Pick up notification
  
  const int trigPin = 10;   //trig pin of distance sensor connected to pin 10
  const int echoPin = 11;    //echo pin of distance sensor to pin 11
  const int Motor1 = 9;      //Motor 1 connected to pin 9       
  
  long duration;    //defines variables
  int distance;     //defines variables
  
void setup() 
{
 pinMode(trigPin, OUTPUT);  //trigPin set as output
 pinMode(echoPin, INPUT);   //echoPin set as input
 pinMode(Motor1, OUTPUT);   //Motor assigned to distance sensor
 Serial.begin(9600); //Starts Serial
 Serial.println("Distance");
}

void loop() 
{
  digitalWrite(trigPin, LOW);   //clears trig pin
  delay(2);                      //delay of 2ms
  digitalWrite(trigPin, HIGH);  //trigPin high for 10ms
  delay(10);
  digitalWrite(trigPin, LOW);   //resets trig pin
  duration = pulseIn(echoPin,HIGH);  //Duration soundwave traveled for in ms
  distance = duration*0.034/2;   //distance soundwave traveled/2   
//speed = 34000cm/s
//duration in sx10-6
//speed*duration = 34000*10-6 times duration
     
  Serial.print("Distance: ");
  Serial.println(distance);      //prints distance

  if (distance = 7)
  {
   digitalWrite(Motor1, 255);
   delay(50);
   digitalWrite(Motor1, 0);
   delay(1000);
  }
  else if (distance < 10)
  {
   digitalWrite(Motor1, 255);    //moderates motor speed
   delay(200);                    
   digitalWrite(Motor1, 0);
   delay(100);
  }
  else if (distance < 15)
  {
   digitalWrite(Motor1, 127);
   delay(200);
   digitalWrite(Motor1, 0);
   delay(200);
  }
  else if (distance < 20)
  {
   digitalWrite(Motor1, 63);
   delay(200);
   digitalWrite(Motor1, 0);
   delay(400);
  }
  else if (distance = 100)        //notification if walking
  {
   digitalWrite(Motor1, 63);
   delay(600);
   digitalWrite(Motor1, 0);
   delay(1000);
  }
   else if (distance = 150)        //notification for walking
  {
   digitalWrite(Motor1, 31);
   delay(100);
   digitalWrite(Motor1, 0);
   delay(200);
  }
  else if (distance = 200)        //notification if walking
  {
   digitalWrite(Motor1, 15);
   delay(200);
   digitalWrite(Motor1, 0);
   delay(200);
  }
  else
  {
    digitalWrite(Motor1, LOW);
    delay(300);
  }
}
