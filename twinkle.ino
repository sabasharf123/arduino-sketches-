void setup() {
  // set up a pin for each "note" of twinkle twinkle little star 
    pinMode (13, OUTPUT); //first note "twinkle"
    pinMode (11, OUTPUT); // second note "twinkle"
    pinMode (9, OUTPUT); // third note "little"
    pinMode (7, OUTPUT); // fourth note "star"
}

void loop() {
  // put your main code here, to run repeatedly:

  //let's set up an array for our pattern 
  //which pins (which LEDs) to turn on in sequence
  int pattern [] = {13, 13, 11, 11, 9, 9, 7}; 

  //loop through the ENTIRE pattern 
  for (int count = 0; count <7; count++) { 
    //pattern[count] gives me the note in the 
    //pattern that I've counted up to by now 
    digitalWrite (pattern [count], HIGH); //turn this light on
   delay (250);
   digitalWrite (pattern [count], LOW); //turn this light off 
   delay (250);
  }

  digitalWrite (13, HIGH);
  digitalWrite (11, HIGH);
  digitalWrite (9, HIGH);
  digitalWrite (7, HIGH);
  delay (500);
  digitalWrite (13, LOW);
  digitalWrite (11, LOW);
  digitalWrite (9, LOW);
  digitalWrite (7, LOW);

long randNumber; 

  randNumber = random(0,3);
  Serial.println(randNumber);

int pins[] = {13,11,9,7};

int randpin = pins[randNumber];

for (int count = 0; count <10; count++) { 
  digitalWrite(randpin, HIGH);
  delay(50);
  digitalWrite(randpin, LOW); 
  
}

}


