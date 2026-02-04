# Mazda MX5 NA Open Source Head Unit

This repository documents my project to build a modern, 3D-printed head unit for the Mazda MX5 NA (Miata) using a Raspberry Pi and LineageOS.

It relies on a **Karlinkit adapter** to handle the heavy lifting for Wireless CarPlay and Android Auto.

### Project Status
* **CarPlay:** Fully tested and working wirelessly.
* **Android Auto:** Supported by the hardware (Karlinkit CCPA), but I personally use an iPhone so I haven't daily-driven the Android side.
* **Audio:** The Raspberry Pi 5 (and likely future models) lacks a headphone jack, so this build uses a **USB Sound Card architecture**.

**Note on Audio Hardware:**
My personal build uses "recycled" electronics (a disassembled Logitech PC speaker system wired to a USB dongle).
However, **you do not need to replicate my exact hack.** The guide below explains how to use *any* standard USB amplifier and sound card, provided it has **ground isolation** and a **microphone input** for calls.
