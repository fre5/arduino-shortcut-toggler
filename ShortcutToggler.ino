//This sketch simulates the keypress of Ctrl + R while toggling an LED

#include <JC_Button.h>          // https://github.com/JChristensen/JC_Button
#include <Keyboard.h>           // Keyboard library included in Arduino IDE installation


// pin assignments
const byte
    BUTTON_PIN(2),              // connect a button switch from this pin to ground
    LED_PIN(15);                // connect the led to this pin

    char ctrlKey = KEY_LEFT_CTRL;   // define the left ctrl key for Windows
    char shiftKey = KEY_LEFT_SHIFT;  
    char altKey = KEY_LEFT_ALT;
    Button myBtn(BUTTON_PIN);       // define the button

void setup()
{
    myBtn.begin();              // initialize the button object
    pinMode(LED_PIN, OUTPUT);   // set the LED pin as an output
    Keyboard.begin();
}

void keyboardaction()
{
        Keyboard.press(ctrlKey);     //ctrl
        Keyboard.press(altKey);      //alt
        Keyboard.press(shiftKey);    //shift
         
}

void loop()
{
    static bool ledState;       // a variable that keeps the current LED status
    myBtn.read();               // read the button

    if (myBtn.wasReleased())    // if the button was released, change the LED state
    {
        ledState = !ledState;             // check led state
        digitalWrite(LED_PIN, ledState);  // perform the led state
        keyboardaction();
        delay(100);
        Keyboard.releaseAll();
    }
}
