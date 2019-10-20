
int speakerOut=D1;
//byte names[] ={'c','d','e','f','g','a','b','c'};
//int tones[]={1915,1700,1519,1432,1275,1136,1014,950};
//byte melody[]="2d2a1f2c2d2a2d2c2f2d2a2c2d2a1f2c2d2a2a2g2p8p8p8p";
int count =0;
int count2 =0;
int count3 =0;
int sensor=D2;
int val;
int led=D0;
int state=LOW;
int Max_count=24;
int statePin =LOW;
//void siren();
int intruder;
const char*ssid="OnePlus6t";
const char*password="kanpur12";
const int ledPin=2;
void setup() {
    Serial.begin(115200);
  Serial.println("working");
  pinMode(sensor,INPUT);
  pinMode(speakerOut, OUTPUT);
  //attachInterrupt(0,intruder_detect,RISING);
  //initialise the interrrupt pin for the motion sensor(Arduino Digital pin 2)
  //intruder=0;
}

void loop() {
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
    //delay(100);                // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      intruder_detect();
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
      //delay(100);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
      }
  }
}
void intruder_detect()//this function is called whenever is called whenever an intruder is detected by the arduino
{
  //intruder++;
  Serial.println("Intruder detected");
  for(int i=0;i<3;i++)//play the alarm three times
  siren();
}
void siren()//This function will make the alarm sound using the piezo buzzer
{
//  for (count=0;count<Max_count;count++)
//  {
//    for(count3=0;count<=(melody[count*2]-48)*30;count3++){
//      for (count2=0;count2<0;count2++){
//        if(names[count2]==melody[count*2+1]){
//          analogWrite(speakerOut,1023);
//          //delay(tones[count2]);
//        }
//        if(melody[count*2+1] == 'p'){
//          //make a pause of certain time
//          analogWrite(speakerOut,0);
//          //delay(1);
//        }
//      }
//    }
//  }
digitalWrite(speakerOut, HIGH);
delay(100);
digitalWrite(speakerOut, LOW);
delay(100);
}

 
