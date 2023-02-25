# Arduino Simple program
## Write a program to on an led for 1 second and off for 1 second
```c
void setup() {
pinMode(13, OUTPUT);
}

void loop() {
digitalWrite(13, HIGH);
delay(1000);
digitalWrite(13, LOW);
delay(1000);
}

```

## Write a program to increase and decrease the brightness of the led.
```c
int brightness=0;
int fadeAmount=5;
void setup() {
pinMode(A0, OUTPUT);
}

void loop() {
  analogWrite(A0, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(100);
}
```

## Write a program to glow a led if an button is pressed.
```c
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
```
Circuit:  
<img src="https://user-images.githubusercontent.com/57592824/217681638-555b8ba0-e139-4040-9de0-95f5cf14b7fd.png" width=300px>

## Write a program to on and off the led when the button is pressed(changing the state of an led)
```c
#define LED_PIN 13
#define BUTTON_PIN 2
byte lastButtonState = LOW;
byte ledState = LOW;
void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}
void loop() {
  byte buttonState = digitalRead(BUTTON_PIN);
  if (buttonState != lastButtonState) {
    lastButtonState = buttonState;
    if (buttonState == LOW) {
      ledState = (ledState == HIGH) ? LOW: HIGH;
      digitalWrite(LED_PIN, ledState);
    }
  }
  delay(200);
}
```
## Write a program to make a LED 5times blink when a button is pressed
```c
#define LED_PIN 13
#define BUTTON_PIN 2
void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}
void loop() {
  byte buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == HIGH)
  {
    for(int i=0; i<5; i++)
    {
      digitalWrite(LED_PIN, HIGH);
      delay(800);
      digitalWrite(LED_PIN, LOW);
      delay(800);
    }
  }
  delay(200);
}
```