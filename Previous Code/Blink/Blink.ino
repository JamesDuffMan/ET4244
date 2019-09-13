
/* --------------------------------------------------------------
 * Sketch name        :Blink
 * File name          : Blink
 * --------------------------------------------------------------
 * Group number       : 4
 * Group members      :James, Silvia
 * Last updated on    : 13.09.19
 * --------------------------------------------------------------
 * Sketch description : Testing Blink file
 * 
 * 
 * -------------------------------------------------------------- */

/* --------------------------------------------------------------
 * Preamble
 * -------------------------------------------------------------- */


/* --------------------------------------------------------------
 * void setup( void )
 * -------------------------------------------------------------- */
 #define MY_LED 13
 void setup( void )
 {
  //pinMode(LED_BUILTIN, OUTPUT);
  //pinMode(13,OUTPUT);
  pinMode(MY_LED, OUTPUT);
  /* Setup code to run once */

}

/* --------------------------------------------------------------
 * void loop( void ) 
 * -------------------------------------------------------------- */
 
void loop( void )
{
   digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  
  /* Main code to run repeatedly */

}

/* --------------------------------------------------------------
 * End of file
 * -------------------------------------------------------------- */
