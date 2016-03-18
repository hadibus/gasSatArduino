/*
 * closest thing to concurrency I could do, since 
 * arduino doesn't do concurrency.
 */


#define LEDPIN 13;
const long INTERVAL = 2000;
unsigned long previousMillis = 0;
bool btnSched = false;
int btn2 = 2;


// the setup routine runs once when you press reset:
void setup() 
{
  Serial.begin(9600);
  pinMode(btn2, INPUT);
}

// the loop routine runs over and over again forever:
void loop() 
{
  unsigned long currentMillis = millis();

  /*This checks to see if the button has been pressed.
   * The check happens every time the loop happens.  
   * Subsequent button presses are ignored.
   */
  if (digitalRead(btn2) && !btnSched)
  {
    btnSched = true;
    Serial.println("Button pressed!");
  }

  //Serial.print('*'); // uncomment this to see how often the button
                        // is checked.

  /*The things in this if statement will only happen
   * when the difference between the current time and
   * the previous time  are greater than the set interval.
   * In other words, it will happen every INTERVAL 
   * milliseconds.  
   */
  if (currentMillis - previousMillis >= INTERVAL)
  {
    previousMillis = currentMillis;
    Serial.println();
    Serial.print("Normal Stuff... ");
    Serial.println("Done.");
  
    Serial.print("More normal Stuff... ");
    Serial.println("Done.");
  
    Serial.print("Much normal Stuff...");
    Serial.println("Done.");

    if(btnSched)
    {
      Serial.print("Stuff because you pressed button... ");
      //delay(1000);
      Serial.println("Done.");
      btnSched = false;
    }
  }
}
