# Software Setup

## Operating System
We are using **LineageOS 22 (Android 15)** created by KonstaKANG.
* **Download:** [Link to KonstaKANG's site]
* **Installation:** Flash to MicroSD using Raspberry Pi Imager or Etcher. Follow the official KonstaKANG guide for initial partition resizing and GApps installation (if you want the Play Store).

## 🛑 Safe Shutdown Configuration (The F10 Trick)
To make the Pi shut down safely when the Beetle sends the signal, we map a GPIO pin to a keyboard key.

1.  **Edit the Config File:**
    * Open `/boot/config.txt`.
    * Add the following line to the end of the file (replace `26` with your actual GPIO pin):
        `dtoverlay=gpio-key,gpio=26,active_low=0,gpio_pull=down,keycode=68,label="F10"`
    * *Note:* `keycode=68` corresponds to the **F10** key. `active_low=0` assumes the Beetle sends a 3.3V "High" signal to trigger it.

2.  **Install Automation App:**
(details will be added soon)

## 🔊 Audio Tweaks
* **Volume Boost:** The USB sound card output can be quiet. Install a system-wide equalizer (e.g., **Flat Equalizer**) to increase gain.
