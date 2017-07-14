#include <Servo.h>
Servo servoLeft;
Servo servoRight;
long randNumber;
long random2;
long randommove;
long randomturn;
long randcircle;

int PIEZOPIN = 5;

// One octave of notes between A4 and A5
int note_A4 = 440;
int note_As4 = 466; int note_Bb4 = note_As4;
int note_B4 = 494;
int note_C5 = 523;
int note_Cs5 = 554; int note_Db5 = note_Cs5;
int note_D5 = 587;
int note_Ds5 = 622; int note_Eb5 = note_Ds5;
int note_E5 = 659;
int note_F5 = 698;
int note_Fs5 = 740; int note_Gb5 = note_Fs5;
int note_G5 = 784;
int note_Gs5 = 830; int note_Ab5 = note_Gs5;
int note_Gs4 = 415;
int note_D4 = 294;
int note_Fs4 = 370;
int note_A5 = note_A4 * 2;
int note_As5 = note_As4 * 2; int note_Bb5 = note_As5;
int note_B5 = note_B4 * 2;
int note_E4 = 330;
int note_C4 = 262;

int note_rest = -1;

// note lengths defined here
long whole_note = 3200; // change tempo by changing duration of one measure
long half_note = whole_note / 2;
long quarter_note = whole_note / 4;
long eighth_note = whole_note / 8;
long sixteenth_note = whole_note / 16;

// song is stored as notes and duration of those notes
long worknotes[11][2] = {
  {note_Eb5, eighth_note}, {note_B4, eighth_note}, {note_B4, eighth_note}, {note_Cs5, eighth_note}, 
  {note_Cs5, eighth_note}, {note_Cs5, sixteenth_note}, {note_B4, sixteenth_note}, {note_Eb5, sixteenth_note}, 
  {note_Fs5, sixteenth_note}, {note_E5, sixteenth_note}, {note_Eb5, sixteenth_note}
  };

// Unforgettable
long unforgettable_notes[120][2] = {
  
  {note_A4, sixteenth_note},
  {note_A4, sixteenth_note},
  {note_A4, sixteenth_note},
  {note_A4, sixteenth_note}, 
  {note_A4, eighth_note}, 
  {note_A4, sixteenth_note},
  {note_B4, sixteenth_note * 5}, 
  
  {note_rest,  eighth_note}, 
  {note_B4, sixteenth_note},
  {note_B4, sixteenth_note},
  {note_B4, sixteenth_note},
  {note_B4,  sixteenth_note}, 
  {note_B4, eighth_note},
  {note_Cs5, eighth_note}, 
  {note_Gs4, sixteenth_note}, 
  {note_Gs4, eighth_note}, 
  {note_Fs4, sixteenth_note * 3}, 
   {note_A4, sixteenth_note},
  {note_A4, sixteenth_note},
  {note_A4, sixteenth_note},
  {note_A4, sixteenth_note}, 
  {note_A4, eighth_note}, 
  {note_A4, sixteenth_note},
  {note_B4, sixteenth_note * 5}, 
  
  {note_rest, quarter_note},
   {note_A4, sixteenth_note},
  {note_A4, sixteenth_note},
  {note_A4, sixteenth_note},
  {note_A4, sixteenth_note}, 
  {note_A4, eighth_note}, 
  {note_A4, sixteenth_note},
  {note_A4, sixteenth_note * 5}, 
  {note_E4, sixteenth_note}, 
  {note_D4, sixteenth_note}, 
  {note_C4, sixteenth_note * 3}, 
  
  {note_rest, sixteenth_note}, 
  {note_Fs4, sixteenth_note}, 
  {note_A4, sixteenth_note}, 
  {note_A4, sixteenth_note},
  {note_A4, eighth_note},
  {note_A4, eighth_note}, 
  {note_Gs4, sixteenth_note}, 
  {note_A4, sixteenth_note * 7}, 
  
  {note_rest, sixteenth_note}, 
  {note_E4, sixteenth_note},
  {note_A4, sixteenth_note},
  {note_A4, sixteenth_note},
  {note_A4, sixteenth_note},
  {note_A4, sixteenth_note}, 
  {note_A4, eighth_note}, 
  {note_A4, sixteenth_note},
  {note_B4, sixteenth_note * 5}, 

  
  {note_rest, sixteenth_note},
  {note_Fs4, sixteenth_note},
  {note_B4, sixteenth_note},
  {note_B4, sixteenth_note},
  {note_B4, eighth_note},
  {note_Cs5, sixteenth_note},
  {note_B4, sixteenth_note},
  {note_A4, sixteenth_note},
  {note_A4, eighth_note},
  {note_Gs4, sixteenth_note},
  {note_Fs4, eighth_note * 3},
  {note_rest, eighth_note},
  //baby i can feel your
  {note_A4, sixteenth_note}, 
  {note_A4, sixteenth_note}, 
  {note_A4, sixteenth_note}, 
  {note_A4, sixteenth_note}, 
  {note_A4, eighth_note},
  {note_A4, sixteenth_note}, 
  {note_A4, eighth_note},
  
  {note_E4, sixteenth_note},
  {note_D4, sixteenth_note},
  {note_C4, eighth_note},
  {note_rest, eighth_note},
  {note_A4, sixteenth_note}, 
  {note_A4, sixteenth_note}, 
  {note_A4, eighth_note},
  {note_A4, eighth_note},
  {note_A4, sixteenth_note},  
  {note_A4, sixteenth_note * 5}, 
  
  {note_Cs5, eighth_note},
  {note_B4, eighth_note},

  {note_Cs5, eighth_note},
  {note_B4, eighth_note},

  {note_Cs5, eighth_note},
  {note_B4, eighth_note},
  
  {note_A4, sixteenth_note},
  {note_A4, sixteenth_note},
  {note_A4, sixteenth_note},
  {note_B4, sixteenth_note},

  {note_D5, eighth_note},
  {note_B4, eighth_note},

  {note_D5, eighth_note},
  {note_B4, eighth_note},

  {note_D5, eighth_note},
  {note_Cs5, eighth_note},
  {note_B4, eighth_note},
  {note_A4, eighth_note},
  {note_Cs5, eighth_note},
  {note_B4, eighth_note},
  {note_A4, eighth_note},

  {note_Fs4, eighth_note}, 
  {note_Cs5, eighth_note}, 
  {note_B4, eighth_note}, 
 
};
  
// if you want there to be silence between notes,
//   staccato should be true
bool staccato = true;

void setup() {
  // put your setup code here, to run once:
servoLeft.attach(13);
servoRight.attach(12);


}
void  turn_right(int time) {
  servoLeft.writeMicroseconds (1700);
  servoRight.writeMicroseconds (1700);
  delay (time);
}
void turn_left(int time) {
  servoLeft.writeMicroseconds(1300);         
  servoRight.writeMicroseconds(1300);       
  delay(time);
  
}
void circle (int time) {
  servoLeft.writeMicroseconds (1700);
  servoRight.writeMicroseconds (1700);
  delay (time);
}

void forward (int time) {
  servoLeft.writeMicroseconds (1700);
  servoRight.writeMicroseconds (1300);
  delay (time) ;
}
void backward (int time){
  servoLeft.writeMicroseconds(1300);         // 1.7 ms -> counterclockwise
  servoRight.writeMicroseconds(1700);        // 1.3 ms -> clockwise
  delay(time);
}
void turn1 (){
  randNumber = random (200, 1000);
  turn_right (randNumber);
   delay (100);
   turn_left(randNumber);
}
void turn2 (){
  random2 = random (200, 1000);
   turn_left (random2);
   delay (100);
   turn_right (random2);
}
void zigzag () {
  randommove = random (500, 1000);
 randomturn = random (200, 2000);
   forward (randommove);
   turn_left (randomturn);
   forward (randommove);
   turn_right (randomturn);
   turn_right (randomturn);
   forward (randommove);
   turn_left (randomturn);
   turn_left (randomturn);
   forward (randommove); 
   backward (randommove);
   turn_left (randomturn);
   backward(randommove);
   turn_right (randomturn);
   turn_right (randomturn);
   backward(randommove);
   turn_left (randomturn);
   turn_left (randomturn);
   backward (randommove);
  
}
void loop() {
  randcircle = random (1000, 2000);
   turn1 ();
   turn2 ();
   circle (randcircle);
   delay (100);
   zigzag ();
   delay (3000);
   
}

