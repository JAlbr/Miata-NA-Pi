# Software Setup

## Operating System
We are using **LineageOS 22 (Android 15)** created by KonstaKANG.
* **Download:** [Link to KonstaKANG's site]
* **Installation:** Flash to MicroSD using Raspberry Pi Imager or Etcher. Follow the official KonstaKANG guide for initial partition resizing and GApps installation (if you want the Play Store).

## 🛑 Safe Shutdown Configuration (The F10 Trick)
To make the Pi shut down safely when the Beetle sends the signal, we map a GPIO pin to a keyboard key.

1.  **Edit the GPIO Map:**
    * Open the file `/boot/resolution.txt` (or the specific overlay config file for KonstaKANG).
    * Add the overlay to map the shutdown pin to keycode `F10`.
    * *(I will add the exact code snippet here later).*

2.  **Install Automation App:**
    * Install an app like **"Button Mapper"** or **"Automate"**.
    * Create a flow: `When Key F10 is pressed` -> `Execute Shell Command: reboot -p` (Shutdown).

## 🔊 Audio Tweaks
* **Volume Boost:** The USB sound card output can be quiet. Install a system-wide equalizer (e.g., **Flat Equalizer**) to increase gain.
