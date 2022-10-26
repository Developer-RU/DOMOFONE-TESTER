#include "main.hpp"


/**
 * @brief 
 * 
 */
void setup() 
{
    pinMode(IN_GERCON, INPUT);

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
    if(digitalRead(IN_GERCON) == LOW)
    {
        digitalWrite(REL_GERCON, HIGH);
        delay(500);
        digitalWrite(REL_GERCON, LOW);
        delay(500);

        digitalWrite(REL_SPEAKER, HIGH);
        delay(500);
        digitalWrite(REL_SPEAKER, LOW);
        delay(500);

        digitalWrite(REL_MP3, HIGH);
        delay(5000);
        digitalWrite(REL_MP3, LOW);
        delay(500);
    }
}