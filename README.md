# Mazda MX5 NA Open Source Head Unit

This repository documents my project to build a modern, 3D-printed head unit for the Mazda MX5 NA (Miata) using a Raspberry Pi and LineageOS.

It relies on a **Karlinkit adapter** to handle the heavy lifting for Wireless CarPlay and Android Auto.

![IMG_0847](https://github.com/user-attachments/assets/a1888fce-1aa8-4a78-acd5-02d48babc50f)

### Project Status
* **CarPlay:** Fully tested and working wirelessly.
* **Android Auto:** Supported by the hardware (Karlinkit CCPA), but I personally use an iPhone so I haven't daily-driven the Android side.
* **Audio:** The Raspberry Pi 5 (and likely future models) lacks a headphone jack, so this build uses a **USB Sound Card architecture**.

**Note on Audio Hardware:**
My personal build uses "recycled" electronics (a disassembled Logitech PC speaker system wired to a USB dongle).
However, **you do not need to replicate my exact hack.** The guide below explains how to use *any* standard USB amplifier and sound card, provided it has **ground isolation** and a **microphone input** for calls.

## ⚠️ Legal Disclaimer & Safety Warning

**Please read this section carefully before attempting this project.**

1.  **Use at Your Own Risk:** This project involves modifying a vehicle's electrical system. I am a hobbyist, not a professional engineer. I accept no responsibility for any damage to your vehicle, your electronics, or yourself (e.g., electrical fires, blown fuses, battery drainage).
2.  **Not Approved for Road Use:** This modification has not been tested or approved by any regulatory body (DOT, TUV, etc.). It is your responsibility to ensure that your vehicle remains road-legal in your country/state.
3.  **Distracted Driving:** This system is capable of displaying video and complex interfaces. **Never** operate the touchscreen or view video content while driving. Always obey your local traffic laws regarding infotainment systems.
4.  **Battery Safety:** If you choose to add a dedicated battery (UPS) to the Raspberry Pi, ensure it is rated for automotive temperature ranges. Lithium batteries can explode in hot cars.

**By using the files or instructions in this repository, you agree that you are doing so entirely at your own risk.**
