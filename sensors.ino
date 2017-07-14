/*
 * Robotics with the BOE Shield - TestLeftIR
 * Display 1 if the left IR detector does not detect an object,
 * or 0 if it does.
 */

void setup()                                 // Built-in initialization block
{
  tone(5, 3000, 1000);                       // Play tone for 1 second
  delay(100);                               // Delay to finish tone

  pinMode(11, INPUT);  pinMode(7, OUTPUT); // Left IR LED & Receiver
  pinMode(5, OUTPUT);  //LED

//Serial.begin(9600);                        // Set data rate to 9600 bps
}

void loop()                                  // Main loop auto-repeats
{
  int irLeft = irDetect(7, 11, 38000);       // Check for object

 // Serial.println(irLeft);                    // Display 1/0 no detect/detect
  if(irLeft == 0)
  {
    digitalWrite(0, HIGH);
    tone(5, 3000, 100);
    delay(100);
    digitalWrite(0, LOW);
  }
}

// IR Object Detection Function

int irDetect(int irLedPin, int irReceiverPin, long frequency)
{
  tone(irLedPin, frequency, 8);      // IRLED 38 kHz for at least 1 ms
  delay(1);                                  // Wait 1 ms
  int ir = digitalRead(irReceiverPin);       // IR receiver -> ir variable
  delay(1);                                  // Down time before recheck
  return ir;                                 // Return 1 no detect, 0 detect
}
