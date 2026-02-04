# Wiring & Power Management Guide

This project uses a custom power management circuit controlled by a **DFRobot Beetle (RP2350)**. This ensures the Raspberry Pi boots when the key is turned and shuts down safely when the key is removed, rather than just cutting power instantly (which corrupts SD cards).

## ⚡ The Power Logic (The "Beetle Brain")

The Beetle microcontroller acts as the brain. It needs to stay alive even after you turn the car off, just long enough to tell the Pi to shut down safely. To achieve this, we use a **"Diode OR-ing"** setup.

### 1. Power Sources for the Beetle
The Beetle receives power from **two sources** through diodes (so they don't fight each other):
1.  **Ignition Source:** From the **Green Mini Buck Converter** (powered by ACC fuse).
    * *Logic:* When car is ON, Beetle is powered.
2.  **System Source:** From the **Main DFRobot Buck Converter** (powered by Relay).
    * *Logic:* When the Relay is active, Beetle is powered.

**Result:** The Beetle stays on if *either* the Car is ON *or* the System is currently running.

### 2. Ignition Sensing
* **Source:** The 5V output from the Green Mini Buck (Ignition).
* **Connection:** Goes through a **Voltage Divider** (two resistors) to drop the voltage from 5V to 3.3V.
* **Destination:** Connects to Beetle GPIO `[PIN_X]`.
* **Function:** Tells the code: "Is the car key turned?"

### 3. Relay Control (Main Power)
* **Connection:** Beetle GPIO `[PIN_Y]` -> Relay Input.
* **Function:**
    * **ON:** When Ignition is detected, Beetle turns Relay ON. This connects the Car Battery (BAT) to the Main DFRobot Buck and Amplifier.
    * **OFF:** When Ignition is lost, Beetle keeps Relay ON for a set timer (e.g., 15 mins) or until Shutdown is complete, then turns it OFF.

---

## 🔌 Connecting the Raspberry Pi

### 1. Power Input
* **Cable:** USB-C cable (cut in half).
* **Wiring:**
    * **Red Wire:** Connects to DFRobot Buck Positive (+).
    * **Black Wire:** Connects to DFRobot Buck Negative (-).
    * *Note:* The DFRobot Buck is triggered by the Relay.

### 2. Shutdown Signal (The "F10" Button)
We treat the safe shutdown signal as a keyboard key press.
* **Wiring:** Beetle GPIO `[PIN_Z]` -> connects directly to a specific Raspberry Pi GPIO pin.
* **Software Logic:** LineageOS is configured to treat this pin as the **"F10" key**.
* **Action:** An automation app on the Pi listens for "F10" and runs the shutdown command.

### 3. Volume Buttons
These connect directly to the Raspberry Pi GPIO headers (standard KonstaKANG layout).
* **Volume Up:** GPIO `[PIN_A]` -> Ground
* **Volume Down:** GPIO `[PIN_B]` -> Ground

---

## 📺 Display & Audio Connections
* **Video:** Micro HDMI (Pi) -> HDMI Adapter (Screen).
* **Touch:** USB Cable (Pi) -> USB Port (Screen).
* **Audio:** USB Sound Card -> Ground Loop Isolator -> Amplifier -> Speakers.
    * *Tip:* Use an Equalizer app (like "Flat Equalizer") in Android to boost the master volume if the output is too quiet.
