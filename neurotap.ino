int buttonPin = 4;   // Button connected to GPIO4
int ledPin = 2;      // LED cue (blinks for tap signal)

int buttonState = 0;
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

int tapCount = 0;
unsigned long startTime = 0;
unsigned long elapsedTime = 0;
unsigned long tapTimes[100];
unsigned long cueTime = 0;  // When the cue appeared
const unsigned long testDuration = 30000;  // 30 seconds

bool testActive = false;
bool cueActive = false;
unsigned long nextCueDelay = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  
  Serial.println("Press the button to start the tap test...");
}

void loop() {
  int reading = digitalRead(buttonPin);

  // Start test on first tap
  if (!testActive && reading == LOW) {
    testActive = true;
    startTime = millis();
    tapCount = 0;
    Serial.println("Tap test started!");
    nextCueDelay = random(1000, 3000);  // Random delay for first cue
    cueTime = millis() + nextCueDelay;
  }

  if (testActive) {
    elapsedTime = millis() - startTime;

    // Generate cue at random intervals
    if (!cueActive && millis() >= cueTime) {
      cueActive = true;
      digitalWrite(ledPin, HIGH);
      Serial.println("CUE: Tap Now!");
    }

    // Check button press
    if (reading != lastButtonState) {
      lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {
      if (reading != buttonState) {
        buttonState = reading;
        
        if (buttonState == LOW) {  // Button pressed
          unsigned long tapTime = millis();
          if (cueActive) {
            unsigned long reactionTime = tapTime - cueTime;
            Serial.print("Correct tap! Reaction Time: ");
            Serial.print(reactionTime);
            Serial.println(" ms");
            tapTimes[tapCount] = reactionTime;
            tapCount++;
            cueActive = false;
            digitalWrite(ledPin, LOW);
            nextCueDelay = random(1000, 3000);  // Set new random cue time
            cueTime = millis() + nextCueDelay;
          } else {
            Serial.println("False tap! No cue was given.");
          }
        }
      }
    }

    lastButtonState = reading;

    // End test after 10 seconds
    if (elapsedTime >= testDuration) {
      testActive = false;
      Serial.println("Tap test ended!");
      Serial.print("Total Correct Taps: ");
      Serial.println(tapCount);

      Serial.println("Reaction Times (ms):");
      for (int i = 0; i < tapCount; i++) {
        Serial.println(tapTimes[i]);
      }

      Serial.println("Press the button to restart.");
    }
  }
}
