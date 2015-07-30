/********************************************************
** Download from:                                      **
** http://www.alhin.de/arduino/index.php?n=53          **
********************************************************/

#include <Shrg595.h>

#define D1N_Pin   13   // Digit 1 Enable negated
#define D2N_Pin   12   // Digit 2 Enable negated
#define TICK_Pin  11    // TICK PIN
#define SER_Pin   10   //Serial data input
#define RCLK_Pin  9    //Register clock
#define SRCLK_Pin 8    //Shift register clock
#define BUTTON_START 7 
#define BUTTON_FOCUS 6
#define LED_START    5
#define LED_FOCUS    4


//Initialisation
Shrg595 seven_segment(SER_Pin, RCLK_Pin, SRCLK_Pin, false	); 

void setup(){
// Serial.begin(9600);
 seven_segment.clear();
  // define & initialize control pins for digits
  pinMode(D1N_Pin, OUTPUT);   
  pinMode(D2N_Pin, OUTPUT);     
  digitalWrite(D1N_Pin, HIGH);
  digitalWrite(D2N_Pin, LOW);

}

void loop(){
 for (int i=0;i<16;i++){
   seven_segment.showNumber(i);
   delay(500);
 }
 seven_segment.clear();
 delay(1000);
 seven_segment.setPoint(true);
 delay(1000);
 seven_segment.setPoint(false);    
}

