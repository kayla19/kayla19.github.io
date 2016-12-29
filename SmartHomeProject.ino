// 

#include <Servo.h>  // servo library
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
Servo myservo;  // servo control object

const int temperaturePin = A1,
          redLED = 10,
          greenLED = 8,
          buzzerPin = 9,
          songLength = 18,
          lightSensorPin = A2,
           button1Pin = 7;

int tempo = 113, lightLevel;
float getVoltage(int);
void manualTune();
void speakerSound(int beats[], char notes[]);

void setup()
{
  pinMode(button1Pin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
//  pinMode(lcdPin, OUTPUT);
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600);
  myservo.attach(A0);
}


void loop()
{
  float voltage, degreesC, degreesF;
  int button1State = digitalRead(button1Pin);
  voltage = getVoltage(temperaturePin);
  degreesC = (voltage * 500) - 273.15;
  degreesF = degreesC * (9.0/5.0) + 32.0;
  char notes1[] = "Cdef gab aabC ce"; 
  int beats1[] = {1,2,1,3,1,4,4,2,1,3,1,1,1,4,4,2};
  char notes2[] = "ee fefed dceddcfcd"; 
  int beats2[] = {1,2,1,3,1,4,4,2,1,3,1,1,1,4,4,2};

  myservo.write(0);
  delay(50);  
  
// light sensor

  lightLevel = analogRead(lightSensorPin);
  manualTune();
  Serial.print("Light Level: ");
  Serial.print(lightLevel);
  delay(500);
  
  //analogWrite(lcdPin, lightLevel);
  
// switch
if (button1State == LOW){
  // servo movement
  while(lightLevel < 50){
      myservo.write(179);              // tell servo to go to position in variable 'pos'
      delay(100);                       // waits 15ms for the servo to reach the position
  }
      myservo.write(0);              // tell servo to go to position in variable 'pos'
      delay(100);                       // waits 15ms for the servo to reach the position
}
else{
  Serial.print("deg C: ");
  Serial.print(degreesC);
  Serial.print("  deg F: ");
  Serial.println(degreesF);

  // LCD
  lcd.setCursor(3,0);

  lcd.print("degC: ");
  lcd.print(degreesC);

  lcd.setCursor(3,1);
  lcd.print("degF: ");
  lcd.print(degreesF);
  
  delay(1000);

  if (degreesC >= 35){
  speakerSound(beats1, notes1);
  digitalWrite(redLED, HIGH);   
  delay(500); 
  }
  else if (degreesC <= 15){
  speakerSound(beats1, notes1);
  digitalWrite(greenLED, HIGH);   
  delay(500);
  }
  else {
  digitalWrite(redLED, LOW);   
  delay(500); 
  digitalWrite(greenLED, LOW);   
  delay(500);
  }
}

}

void manualTune()
{
  lightLevel = map(lightLevel, 0, 300, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);
} 

void speakerSound(int beats[], char notes[]){
  //SPEAKER
 int i, duration;
 
    for (i = 0; i < songLength; i++) // step through the song arrays
  {
    duration = beats[i] * tempo;  // length of note/rest in ms

    if (notes[i] == ' ')          // is this a rest? 
    {
      delay(duration);            // then pause for a moment
    }
    else                          // otherwise, play the note
    {
      tone(buzzerPin, frequency(notes[i]), duration);
      delay(duration);            // wait for tone to finish
    }
    delay(tempo/10);              // brief pause between notes
  }

 // while(true){}
 return;
}

float getVoltage(int pin)
{
 
  return (analogRead(pin)/1024.0);
}

int frequency(char note) 
{
  int i;
  const int numNotes = 8;  
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};

  for (i = 0; i < numNotes; i++)  
  {
    if (names[i] == note)         
    {
      return(frequencies[i]);     
    }
  }
  return(0);
}


