#define SENSORPINA A0 // x axis

unsigned long targetTime=0;
const unsigned long interval=500; //TODO: How fast should we read

int potPin = A5;
int rotPin = A4;
int ledPin = 6;
int fsr = A3;
int buttonPin = 3;

int prVal = 0;
int rrVal = 0;
int pwWval = 0;
int rwWval = 0;

int btnState = 0;
int prevValX = 0;
int prevValY = 0;
int fsrVal = 0;

int colorChange = 0;

void setup(){
  // begin the serial connection with a baudrate of 115200
  pinMode(potPin, INPUT);
  pinMode(rotPin, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(fsr, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}
void loop(){
  btnState = digitalRead(buttonPin);
  prVal = analogRead(potPin);
  pwWval = (255./1023.) * prVal; // not used
  String x = String(prVal);
  rrVal = analogRead(rotPin);
  rwWval = (255./1023.) * rrVal; // not used
  String y = String(rrVal);
    
  fsrVal = analogRead(fsr);
  String fsrS = String(fsrVal);

  if(millis()>=targetTime){

    targetTime= millis()+interval;
    if (btnState == HIGH) {
    } else {
        Serial.println("rst"); // send reset when button is pressed
    }
  
    if (fsrVal > 3 and colorChange == 0) {
      colorChange = 1;
      Serial.println("color");
    }

    if ((abs(rrVal- prevValX) >= 50 )  or (abs(prVal- prevValY)>=50)) {
       digitalWrite(ledPin, HIGH);
    } else {
       digitalWrite(ledPin, LOW);
    }
    Serial.println(x + "," + y);
    prevValX = rrVal;
    prevValY = prVal;
  }

}

