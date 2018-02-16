#include <Adafruit_SoftServo.h>

volatile uint8_t counter = 0;

Adafruit_SoftServo esc;

#define SERVOPIN  0                 // Servo control output pin

#define OFF 0                       // Lowest ESC speed (range 0-180)
#define FULLTHROTTLE 180            // Maximum ESC speed

#define music1 2500     // Set Max Throttle
#define music2 7000     // Set Min Throttle
#define music3 13000    // Set Battery Type = NmH
#define music4 20000    // Set Battery Type = LiPo
#define music5 27000    // Low Voltage Protection = Low
#define music6 34000    // Low Voltage Protection = Middle
#define music7 40500    // Low Voltage Protection = High
#define music8 51500    // Factory Default
#define music9 61500    // Angle of Entrance = Auto
#define music10 70000   // Angle of Entrance = Low
#define music11 77000   // Angle of Entrance = High
#define music12 85000   // Start of motor = Ultra Smooth
#define music13 98000   // Start of motor = Smooth
#define music14 110500  // Start of Motor = Accelerated
#define music15 122000  // Helicopter mode = Off
#define music16 132500  // Helicopter mode = Mode 1
#define music17 142500  // Helicopter mode = Mode 2
#define music18 159000  // Motor Rotation
#define music19 174500  // PWM Frequency = 8K
#define music20 188000  // PWM Frequency = 16K
#define music21 199500  // Protection Mode = Reduce Power
#define music22 207500  // Protection Mode = Output Off

void setup() {
  pinMode(SERVOPIN, OUTPUT);                // Set up ESC control pin as an output
  esc.attach(SERVOPIN);                     // Attach the pin to the software servo library

  OCR0A = 0xAF;                             // Set up a 2ms interrupt
  TIMSK |= _BV(OCIE0A);
}

bool program = true;
void loop()
{
  if (program)
  {
    // Programming Mode
    esc.write(FULLTHROTTLE);
    delay(music1);
    esc.write(OFF);
    program = false;
  }
}

// The SIGNAL(TIMER0_COMPA_vect) function is the interrupt that will be called by the microcontroller every 2 milliseconds
SIGNAL(TIMER0_COMPA_vect)
{
  counter += 2;                             // Add two milliseconds to the elapsed time
  if (counter >= 20)                        // Has 20ms elapsed?
  {
    counter = 0;                            // Reset the timer
    esc.refresh();                          // Refesh the software based servo control
  }
}
