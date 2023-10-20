#include "HX711.h"

#define DOUT  3
#define CLK  2
 
HX711 scale;

float calibration_factor = -239250; //-7050 worked for my 440lb max scale setup
int buzzer = 4;    // The speaker is on pin 8
int freq = 50;      // Starting frequency

int red = 8;
int green = 9;
int blue = 10;
int check = true;
int waiting = true;
int relay = 11; // relay turns trigger signal - active high;

void setup() {   
  //Set-up
  Serial.begin(9600);
  Serial.println("HX711 calibration sketch");
  Serial.println("Remove all weight from scale");
  Serial.println("After readings begin, place known weight on scale");
  Serial.println("Press + or a to increase calibration factor");
  Serial.println("Press - or z to decrease calibration factor");

  scale.begin(DOUT, CLK);
  scale.set_scale();
  scale.tare(); //Reset the scale to 0

  long zero_factor = scale.read_average(); //Get a baseline reading
  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor);

  //Buzzer
  pinMode(buzzer, OUTPUT);
  digitalWrite (relay, LOW); // relay switch is turned off;


  //Relay 
   pinMode (relay, OUTPUT); // Define port attribute is output;


  //RGB LED
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

}  

void loop() {   // put your main code here, to run
if (digitalRead(5) == HIGH) {    
 noTone(buzzer); 
 fireStage();
  digitalWrite (relay, HIGH); // relay switch is turned off;

 waiting = false;
} 
else {
 waitingStage();
 } 
 
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red, red_light_value);
  analogWrite(green, green_light_value);
  analogWrite(blue, blue_light_value);
}

int holdingStage(){

  Serial.println("Holding");
  RGB_color(0, 255, 0); // Green
  tone(buzzer,1000);
  delay(1000);
}

int waitingStage(){

  if (waiting == true){
    Serial.println("Waiting");
    tone(buzzer, 1000); // Send 1KHz sound signal...
    RGB_color(0, 0, 255);
    delay(1000);        // ...for 1 sec
    RGB_color(0,0,0);
    noTone(buzzer);     // Stop sound...
    delay(1000);        // ...for 1sec
  } else{
    holdingStage();
  }
  
  
  
}

int countdownStage(){
  Serial.println("3");
  RGB_color(255, 255, 0); // Yellow
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(500);
  noTone(buzzer);
  delay(500);
  Serial.println("2");
  RGB_color(255, 255, 0); // Yellow
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(500);
  noTone(buzzer);
  delay(500);
  Serial.println("1");
  RGB_color(255, 255, 0); // Yellow
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(500);
  noTone(buzzer);
  delay(500);
}

int fireStage(){ 
  
  if (check == true){
    countdownStage();
    check = false;
  } 
  
  RGB_color(255, 0, 0); // Red
  scale.set_scale(calibration_factor); //Adjust to this calibration factor
  Serial.print(scale.get_units()*0.453592, 3);
  Serial.print(" kgs"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
  //Serial.print(" calibration_factor: ");
  //Serial.print(calibration_factor);
  Serial.println();

  if(Serial.available())
  {
    char temp = Serial.read();
    if(temp == '+' || temp == 'a')
      calibration_factor += 10;
    else if(temp == '-' || temp == 'z')
      calibration_factor -= 10;
  }
}
