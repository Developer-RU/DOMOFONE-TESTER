#include <avr/wdt.h>
#include "main.hpp"


bool flagCall = false;
int counter = 0;


/**
 * @brief 
 * 
 */
void setup() 
{
    wdt_disable();
    wdt_enable(WDTO_8S);

    pinMode(IN_GERCON, INPUT);      digitalWrite(IN_GERCON, HIGH);

    pinMode(REL_GERCON, OUTPUT);    digitalWrite(REL_GERCON, LOW);
    pinMode(REL_SPEAKER, OUTPUT);   digitalWrite(REL_SPEAKER, LOW);
    pinMode(REL_MP3, OUTPUT);       digitalWrite(REL_MP3, LOW);
}

/**
 * @brief 
 * 
 */
void loop() 
{
    wdt_reset();

    if(counter < 500 && flagCall == false)
    {
        if(digitalRead(IN_GERCON) == LOW) { counter++; }
        if(digitalRead(IN_GERCON) == HIGH) { if(counter > 0) counter--; }
        if(counter == 500) { flagCall = true; }
    }

    if(flagCall == true)
    {
        delay(500);
        wdt_reset();
        digitalWrite(REL_GERCON, HIGH);
        wdt_reset();
        delay(500);
        digitalWrite(REL_MP3, HIGH);
        int c = 20;
        while(c > 0)
        {
            delay(500);
            c--;
            wdt_reset();
        }
        digitalWrite(REL_MP3, LOW);

        c = 10;
        while(c > 0)
        {
            delay(500);
            c--;
            wdt_reset();
        }        
        
        digitalWrite(REL_GERCON, LOW);
        delay(500);

        flagCall = false;
        counter = 0;
    }
}