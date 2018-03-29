#define SENSORPINA A0 // x axis
 //TODO: define other sensor inputs

unsigned long targetTime=0;
const unsigned long interval=9600; //TODO: How fast should we read

int potPin = A5;
int rotPin = A4;
int ledPin = 6;
int buttonPin = 3;

int prVal = 0;
int rrVal = 0;
int pwWval = 0;
int rwWval = 0;

int btnState = 0;

void setup(){
  // TODO: begin the serial connection with a baudrate of 115200
  pinMode(potPin, INPUT);
  pinMode(rotPin, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}
void loop(){
//  if(millis()>=targetTime){
//    targetTime= millis()+interval;
//    readValue = analogRead(potPin);
//    writeValue = (255./1023.) * readValue;
    //Serial.println(analogRead(SENSORPINA));
    btnState = digitalRead(buttonPin);

    if (btnState == HIGH) {
        //Serial.println("reset");
    } else {
	Serial.println("reset");
    }

    prVal = analogRead(potPin);
    pwWval = (255./1023.) * prVal; // not used
    Serial.println(prVal);

    rrVal = analogRead(rotPin);
    rwWval = (255./1023.) * rrVal; // not used
    Serial.println(rrVal);
//    Serial.println("rotPin", rrVal);
//    analogWrite(ledPin, pwWval);
    delay(100);
    //Serial.println(analogRead(prVal));


    //Serial.println(analogRead(rrVal));

  //readValue = analogRead(potPin);
  //writeValue = (255./1023.) * readValue;
  //analogWrite(lightPin, writeValue);
     //TODO: Add other sensor read outs
     //TODO: convert values into a string https://www.arduino.cc/en/Tutorial/StringConstructors
     //TODO: combine them into a string that can be understood by server.js
     //TODO: send the string over serial


//  }
  // TODO: Detect if you want to reset the screen(shake the etch-a-sketch)
  // TODO: write the reset message(see server.js) to the serial port

}

