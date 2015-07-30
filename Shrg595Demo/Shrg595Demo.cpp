/********************************************************
** Download from:                                      **
** http://www.alhin.de/arduino/index.php?n=53          **
********************************************************/
#include <Arduino.h>
#include <Shrg595.h>

#define D1N_Pin   13   // Digit 1 Enable negated
#define D2N_Pin   12   // Digit 2 Enable negated
#define TICK_Pin  11   // TICK PIN
#define DS_Pin    10   //Serial data input
#define SH_CP_Pin 9    //Shift register clock
#define ST_CP_Pin 8    //Register clock
#define BUTTON_START 7 
#define BUTTON_FOCUS 6
#define LED_START    5
#define LED_FOCUS    4
#define COMMONANODE  true
	
//Initialisation
Shrg595 seven_segment(DS_Pin, ST_CP_Pin, SH_CP_Pin, COMMONANODE	); 

void setup(){
  seven_segment.clear();
  pinMode(D1N_Pin, OUTPUT);
  pinMode(D2N_Pin, OUTPUT);     
  digitalWrite(D1N_Pin, HIGH);
  digitalWrite(D2N_Pin, LOW);

}

void loop(){
 for (int i=0;i<16;i++){
	 seven_segment.setPoint(i%2);
     seven_segment.showNumber(i);
   delay(500);
 }
  seven_segment.clear();
  delay(1000);
char *s	="-1234567890abcdefABCDEFgh";
while (*s)
{
   seven_segment.showChar(*s++);
   delay(500);
}
  seven_segment.clear();
  delay(1000);

}

