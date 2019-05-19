#include <LiquidCrystal.h>

#define trigPin 13

#define echoPin 12

#define led 11

#define buzzer 11
LiquidCrystal lcd(8, 7, 5, 4, 3, 2);

void setup()

{ Serial.begin (9600);

pinMode(trigPin, OUTPUT);

pinMode(echoPin, INPUT);

pinMode(led, OUTPUT);

pinMode(buzzer,OUTPUT);
 
lcd.begin(16, 2);
  
lcd.print("distance");


}

void loop()

{ long duration, distance;

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = (duration/2) / 29.1;
lcd.print("Arduino"); // Prints "Arduino" on the LCD 
 delay(3000); // 3 seconds delay 
 lcd.setCursor(7,8); // Sets the location at which subsequent text written to the LCD will be displayed 
 lcd.print("distance"); 
 delay(3000); 
 lcd.clear(); // Clears the display 
 lcd.blink(); //Displays the blinking LCD cursor 
 delay(4000); 
 lcd.setCursor(2,8); 
 delay(3000); 
 lcd.noBlink(); // Turns off the blinking LCD cursor 
 lcd.cursor(); // Displays an underscore (line) at the position to which the next character will be written 
 delay(4000); 
 lcd.noCursor(); // Hides the LCD cursor 
 lcd.clear(); // Clears the LCD screen 


if (distance < 9)

{ digitalWrite(led,HIGH);
digitalWrite(buzzer,HIGH);

}

else {

digitalWrite(led,LOW);
digitalWrite(buzzer,LOW);

}

Serial.print(distance);

Serial.println(" cm");


delay(500);
}
