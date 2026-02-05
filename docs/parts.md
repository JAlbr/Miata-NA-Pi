# Bill of Materials (BOM)

This list is separated into parts that were purchased specifically for this project and parts that were scavenged from old electronics.

## 🛒 Purchased Parts

These are the core components you will need to buy to replicate the build.

| Part Name | Model/Description | Notes |
| :--- | :--- | :--- |
| **CarPlay/Android Auto Adapter** | Carlinkit CPC200-CCPA | Must be this specific model ("Wireless") for hardware Android Auto support. |
| **Main Computer** | Raspberry Pi 4 | Model B |
| **Display** | Waveshare 7-inch IPS Touch (70H-1024600-IPS-CT-B) | "Thin & Light" version. Uses 40-pin FPC ribbon cable. Includes HDMI/USB adapter board. |
| **Microcontroller** | DFRobot Beetle RP2350 | Used for handling vehicle signals (like ignition). |
| **Primary Power Supply (5V)** | DFRobot 5A DC-DC Buck Converter (DFR0946) | High-quality converter to power the Pi and peripherals from the car's 12V. |
| **Secondary Power Supply** | Mini DC-DC Adjustable Buck Converter | Small green module (MP2307 style) used for Ignition sensor/timer. |
| **Relay** | 3.3V - 5V One-Channel Relay Module | Used to completely disconnect from car BAT |
| **Buttons** | Colorful Round Tactile Button Switch Assortment (I got a 15 pack but we only need 2) | Used for volume and power button |
| **Video Cable** | Micro HDMI to HDMI Cable | Short length (0.5m) recommended. Connects Pi 4 (Micro HDMI) to Screen Adapter (Standard HDMI). |
| **Power Cable** | USB-C Cable | To be cut in half. **Optional**, the Pi can also be powered over the Pins |
| **Diodes** | 2 x IN4007 Diodes | Used for the dual power supply of the Bettle |
| **Resistors** | 1.8kΩ, 3.3kΩ, 10kΩ, 1kΩ | For the Voltage divider and some other connections. |

## ♻️ Scavenged / Recycled Parts

I used these specific legacy parts because I had them on hand. If you are replicating this, you can look for these exact models on eBay or use the "Modern Equivalent" listed below.

| Part Source | Specific Model Used | What Was Used / Modified | Modern Equivalent |
| :--- | :--- | :--- | :--- |
| **Speaker System** | **Logitech Z313** (2.1 System) | The internal amplifier board was removed from the subwoofer unit. The subwoofer was also repackaged and Installed in the Miata. | Any 12V Class-D Amplifier board (e.g., PAM8610) should work |
| **Ground Isolator** | **MONACOR FGA-35** | Disassembled. The input was soldered directly to the USB sound card, and output to the amplifier, removing bulky connectors. | Any 3.5mm Ground Loop Isolator (GLI) |
| **USB Audio** | **Old Logitech USB Dongle** | Vintage model (Green/Pink rings). Disassembled, original USB plug removed and replaced with a soldered custom-length cable. Aux ports desoldered for direct wiring. | Any Plug-and-Play USB Sound Card |
