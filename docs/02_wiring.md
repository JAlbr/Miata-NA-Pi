# Wiring & Power Management Guide

<img width="706" height="530" alt="Scematic" src="https://github.com/user-attachments/assets/c86538c3-4ab4-41dd-af37-5182f19f1640" />

R1 -> 10kΩ, R2 -> 1.8kΩ, R3 -> 3.3kΩ, R4 -> 1kΩ, D1 = D2 -> IN4007

This project uses a custom power management circuit controlled by a **DFRobot Beetle (RP2350)**. This ensures the Raspberry Pi boots when the key is turned and shuts down safely when the key is removed, rather than just cutting power instantly (which corrupts SD cards).

## ⚡ The Power Logic

The Beetle microcontroller acts as a timer. It needs to stay alive even after you turn the car off, at least long enough to tell the Pi to shut down safely. The current code has a 15min timer so it does not have to reboot at every time the ignition is off for a short time. To achieve this, we use a **"Diode OR-ing"** setup.

### 1. Power Sources for the Beetle
The Beetle receives power from **two sources** through diodes (so they don't fight each other):
1.  **Ignition Source:** From the **Green Mini Buck Converter**.
    * *Logic:* When **IGN** is ON, Beetle is powered and connects the rest of the system to **Permanent**.
2.  **System Source:** From the **Main DFRobot Buck Converter** (powered by Relay).
    * *Logic:* When **IGN** is turned off, the Beetle is powered by the DFRobot Buck (System power) until it shuts down the PI and eventually          disconnects the entire system (including itself) from power (Relay OFF).

**Result:** The Beetle stays on if *either* the Car is ON *or* the System is currently running.

### 2. Ignition Sensing
* **Source:** The 5V output from the Green Mini Buck (Ignition).
* **Connection:** Goes through a **Voltage Divider** (two resistors) to drop the voltage from 5V to 3.3V.
* **Destination:** Connects to Beetle `GPIO 0`.
* **Function:** Tells the code: "Is the ignition on?"

### 3. Relay Control (Main Power)
* **Connection:** Beetle`GPIO 4` -> Relay Input.
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
    * *Note:* Can also be powerd over 5V and GND pin on the Pi instead of a USB C cable.

### 2. Shutdown Signal (The "F10" Button)
We treat the safe shutdown signal as a keyboard key press.
* **Wiring:** Beetle `GPIO 1` -> connects to the Raspberry Pi `GPIO 23` (or any other GPIO) through a 10KOhm Resistor.
* **Software Logic:** LineageOS is configured to treat this pin as the **"F10" key**.
* **Action:** An automation app on the Pi listens for "F10" and runs the shutdown command.

### 3. Buttons
These connect directly to the Raspberry Pi GPIO headers (standard KonstaKANG layout).
* **Volume Up:** `GPIO 26` -> BTN -> Ground
* **Volume Down:** `GPIO 20` -> BTN -> Ground
* **Power:** `GPIO 21` -> BTN -> Ground

---

## 📺 Display & Audio Connections
* **Video:** Micro HDMI (Pi) -> HDMI Adapter (Screen).
* **Touch:** USB Cable (Pi) -> USB Port (Screen).
* **Audio:** USB Sound Card -> Ground Loop Isolator -> Amplifier -> Speakers. (Or any ground isolated USB amp.)
    * *Tip:* Use an Equalizer app (like "Flat Equalizer") in Android to boost the master volume if the output is too quiet.
