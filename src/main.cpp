#include <Arduino.h>

void printBinary4(byte value)
{
    for(int i = 3; i >= 0; i--)
    {
        Serial.print((value >> i) & 1);
    }
    Serial.println();
} 

void setup() {
  DDRD &= 0xF0;       //Set PD7-PD4 to inputs
  PORTD |= 0xF0;      //Set pullup resistors
  DDRB |= 0x0F;       //Set PB3-PB0 to outputs
  PORTB &= ~0x0F;     //Set LEDS off
  Serial.begin(9600); //
}

void loop() {
  uint8_t value = PIND;
  value = value & 0xF0;
  value = value >> 4;
  value = ~value;
  value = value & 0x0F;

  value = ~value;
  value = value + 1;
  value = value & 0x0F;
  PORTB = (PORTB & ~0x0F) | value;
  Serial.print("DIP Switch Value : ");
  printBinary4(value);
  delay(1000);
}