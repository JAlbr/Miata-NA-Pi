/*
 * PROJECT: Car PC Final Power Manager
 * BOARD:   DFRobot Beetle RP2350
 *
 * PINS:
 * - Pin 0 (Input): Ignition Sense (High = Car ON)
 * - Pin 1 (Output): Shutdown Trigger (F10) -> Connected to Pi GPIO 23
 * - Pin 4 (Output): Relay Control (High = Relay ON)
 */

// ================= CONFIGURATION =================
// 1. How long to keep power ON after key is removed? (15 Minutes)
const unsigned long GRACE_PERIOD_MS = 15 * 60 * 1000; 

// 2. How long to wait for Pi to save files before killing power? (1 Minute)
const unsigned long SHUTDOWN_WAIT_MS = 1 * 60 * 1000; 

// 3. How often to press the "Shutdown Button" during the wait? (Every 3s)
const unsigned long PULSE_INTERVAL_MS = 3000;

// ================= PIN DEFINITIONS =================
const int PIN_IGNITION = 0; 
const int PIN_TRIGGER  = 1; 
const int PIN_RELAY    = 4; 

// ================= STATE MACHINE =================
enum SystemState {
  STATE_IGNITION_ON,    // Car is running
  STATE_GRACE_PERIOD,   // Car off, waiting 15 mins
  STATE_SHUTDOWN_SEQ,   // 15 mins up, pulsing F10 + waiting 1 min
  STATE_POWER_OFF       // Killed relay, sleeping
};

SystemState currentState = STATE_IGNITION_ON;
unsigned long timerStart = 0;     // Tracks when a state started
unsigned long lastPulseTime = 0;  // Tracks the spamming pulses

void setup() {
  Serial.begin(9600);
  
  // Setup Pins
  pinMode(PIN_IGNITION, INPUT);
  pinMode(PIN_RELAY, OUTPUT);
  
  // Default Trigger to "Released" (Input/Float)
  pinMode(PIN_TRIGGER, INPUT); 
  
  // Assume Power ON at boot to be safe
  digitalWrite(PIN_RELAY, HIGH);
  Serial.println("System Booted. Relay ON.");
}

void loop() {
  int ignitionState = digitalRead(PIN_IGNITION);

  // --- GLOBAL SAFETY CHECK ---
  // If Ignition comes back ON at ANY moment, reset everything immediately.
  if (ignitionState == HIGH) {
    if (currentState != STATE_IGNITION_ON) {
      Serial.println(">> Ignition Detected! Resuming Normal Power.");
      
      // 1. Release the F10 button instantly
      pinMode(PIN_TRIGGER, INPUT); 
      
      // 2. Ensure Relay is ON
      digitalWrite(PIN_RELAY, HIGH);
      
      currentState = STATE_IGNITION_ON;
    }
  }

  // --- STATE MACHINE LOGIC ---
  switch (currentState) {
    
    // CASE 1: CAR IS RUNNING
    case STATE_IGNITION_ON:
      digitalWrite(PIN_RELAY, HIGH); // Ensure Power is clamped ON
      
      if (ignitionState == LOW) {
        Serial.println("Ignition Lost. Starting 15min Grace Period...");
        timerStart = millis(); // Start the 15min clock
        currentState = STATE_GRACE_PERIOD;
      }
      break;

    // CASE 2: GRACE PERIOD (15 MINS)
    case STATE_GRACE_PERIOD:
      // Check if 15 minutes have passed
      if (millis() - timerStart >= GRACE_PERIOD_MS) {
        Serial.println("Grace Period Over. Starting Shutdown Sequence...");
        
        timerStart = millis(); // Reset timer for the "1 Minute Kill" countdown
        lastPulseTime = 0;     // Reset pulse timer to fire immediately
        currentState = STATE_SHUTDOWN_SEQ;
      }
      break;

    // CASE 3: SHUTDOWN SEQUENCE (1 MINUTE)
    case STATE_SHUTDOWN_SEQ:
      // A. Check if the "Kill Timer" (1 Minute) is finished
      if (millis() - timerStart >= SHUTDOWN_WAIT_MS) {
        Serial.println("Shutdown Wait Over. KILLING POWER.");
        digitalWrite(PIN_RELAY, LOW); // <--- POWER CUT
        currentState = STATE_POWER_OFF;
        break; // Exit loop immediately
      }

      // B. Pulse the Shutdown Signal (F10) every 3 seconds
      if (millis() - lastPulseTime >= PULSE_INTERVAL_MS) {
        Serial.print("Pulsing Shutdown Signal... ");
        Serial.print((SHUTDOWN_WAIT_MS - (millis() - timerStart))/1000);
        Serial.println("s until power cut.");
        
        triggerPulse();
        lastPulseTime = millis();
      }
      break;

    // CASE 4: SLEEPING (DARKNESS)
    case STATE_POWER_OFF:
      // Do nothing. We just wait for Ignition to go HIGH (Global Check above).
      // Relay is LOW here.
      break;
  }
}

// --- HELPER FUNCTION: THE PULSE ---
void triggerPulse() {
  // 1. Press (Pull to Ground)
  pinMode(PIN_TRIGGER, OUTPUT);
  digitalWrite(PIN_TRIGGER, LOW);
  
  delay(200); // Hold for 0.2s
  
  // 2. Release (Float)
  pinMode(PIN_TRIGGER, INPUT);
}