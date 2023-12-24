#include "pitches.h"

#define BUZZER_PIN 11

int melody[] = {
  NOTE_A3, NOTE_C4, NOTE_G4, NOTE_C4,
  NOTE_F3, NOTE_G3, NOTE_A3, NOTE_G4, NOTE_C4,
  NOTE_C3, NOTE_G3, NOTE_G4, NOTE_C4,
  NOTE_C4, NOTE_G4, NOTE_B3, NOTE_G4,
  //Intro re1 
  NOTE_A3, NOTE_C4, NOTE_G4, NOTE_C4,
  NOTE_F3, NOTE_G3, NOTE_A3, NOTE_G4, NOTE_C4,
  NOTE_C3, NOTE_G3, NOTE_G4, NOTE_C4,
  NOTE_C4, NOTE_G4, NOTE_B3, NOTE_G4,
  //Intro re2 
  NOTE_A3, NOTE_G5, NOTE_G5, NOTE_C5,
  NOTE_C5, NOTE_G3, NOTE_A3, NOTE_D5, NOTE_E5,
  NOTE_C3, NOTE_G5, NOTE_G5, NOTE_C5,
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_G4,
  //verse re1
  NOTE_A3, NOTE_G5, NOTE_G5, NOTE_C5,
  NOTE_C5, NOTE_G3, NOTE_A3, NOTE_D5, NOTE_E5,
  NOTE_C3, NOTE_E5, NOTE_G4, NOTE_E5,
  NOTE_F5, NOTE_E5, NOTE_D5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5,
  //verse re2
  NOTE_G4, NOTE_C5, NOTE_C5, NOTE_E5,
  NOTE_F5, NOTE_E5, NOTE_A3, NOTE_D5, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_G4
  //v re3

  
};

int durations[] = {
 
  4, 4, 4, 4,
  4, 8, 8, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  //Intro
  4, 4, 4, 4,
  4, 8, 8, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  //Intro
  4, 4, 4, 4,
  4, 8, 8, 4, 4,
  4, 4, 4, 4,
  4, 8, 8, 8, 8, 4,
  //verse 1
  4, 4, 4, 4,
  4, 8, 8, 4, 4,
  4, 4, 4, 4,
  8, 8, 8, 8, 8, 8, 8, 4,
  //verse 2
  4, 4, 4, 4,
  4, 8, 8, 4, 8, 8,
  4, 4, 4, 4,
  8, 8, 8, 8, 4, 4,
  //verse 3
   4, 4, 4, 4,
  4, 8, 8, 4, 8, 8,
  4, 4, 4, 4,
  8, 8, 8, 8, 4, 8, 8,
  //verse 4
};

void setup()
{
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop()
{
  int size = sizeof(durations) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations[note];
    tone(BUZZER_PIN, melody[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);
    
    //stop the tone playing:
    noTone(BUZZER_PIN);
  }
}