# HobbyKing_UBEC_programmer
Arduino code to configure a HobbyKing UBEC 30A ESC

This code performs the same action of holding the throttle at 100% during power up to enter into the ESC configuration mode so settings may be changed.  The way to change settings is to simply set the throttle to 0% when the ESC plays the desired beep code.  You can set the delay parameter in the main loop to the music number you want to change.  The "music1" delay parameter that is currently used in the main loop sets the max throttle setting for the ESC which you generally have to do before the ESC will run.

I used this code in conjunction with this code to control a ducted fan pinewood derby car. https://github.com/NegativeC/ducted-fan-pinewood-derby

More info about he ESC can be found here: https://hobbyking.com/en_us/hobby-king-30a-esc-3a-ubec.html