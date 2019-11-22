/* WorkingHumidityTest
 *  James Duffy and Silvia F
 *  Lab group 4
*/
/* These are the liberaries that we need to import to run our code */
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
/* These are the pins that describe which pins are bound to what operations */
// If using software SPI (the default case):
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 8
Adafruit_SH1106 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
/* Define our current sea level pressure. This figure is used in the calculations to calculcate himidity, air pressure, altitude and temperture*/
#define SEALEVELPRESSURE_HPA (1005)
Adafruit_BME280 bme;
/* Basic catch incase the led display is the incorrect dimension*/
#if (SH1106_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SH1106.h!");
#endif
/*Basic error checking, ensuring that the monitor is right etc */
void setup()   {                
  Serial.begin(9600);//start serial communication, 9600 is the baud rate of the connection.
  if (!bme.begin(0x76)) 
  {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SH1106_SWITCHCAPVCC);
  display.clearDisplay(); // Make sure the display is cleared
  // Draw the bitmap:
  // drawBitmap(x position, y position, bitmap data, bitmap width, bitmap height, color)
  // Update the display
  display.display();
  delay(5000);//Put in a 5000 delay so there is time for the display to update
  text();//call the text method below
}
/* Test code, not used anymore but might be useful in the future.
void loop() 
{
}
*/
/*This is the code to display the data on the screen/calculations to get readable figures. It is formatted in such a way that it will work with python too :)*/
void text(void){
  static int i = 0;
  while(1) {
    display.clearDisplay();
    display.setTextSize(1);             // Normal 1:1 pixel scale
    display.setTextColor(WHITE);        // Draw white text
    display.setCursor(0,0);             // Start at top-left corner
    //display.print("Temp = ");
    display.print(bme.readTemperature());
    display.println("*C");
    display.println(" ");
    Serial.print("Temp = ");
    Serial.println(bme.readTemperature());
  
    display.setCursor(74,0);
    //display.print("Pressure = ");
    display.print(bme.readPressure() / 100.0F);
    display.println("hPa");
    display.println(" ");
    Serial.print("Pressure = ");
    Serial.println(bme.readPressure() / 100.0F);
  
    display.setCursor(0,57);
    //display.print("Alt = ");
    display.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    display.println("m");
    display.println(" ");
    Serial.print("Altitude = ");
    Serial.println(bme.readAltitude(SEALEVELPRESSURE_HPA));
  
    display.setCursor(88,57);
    //display.print("Hum. = ");
    display.print(bme.readHumidity());
    display.println("%");
    display.println(" ");
    Serial.print("Humidity = ");
    Serial.println(bme.readHumidity());
  
    display.display();
    delay(2000);
  }
}
