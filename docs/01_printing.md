# 3D Printing Guide

This section covers the materials, orientation, and specific techniques used to print the tombstone bezel and buttons.

## 🧵 Material Choice
**My Experience:**
I personally printed these parts in **PLA**. So far, I have had no issues, but it is important to note that my car has not yet gone through a hot summer with this installed.

**Recommendation:**
The general consensus in the automotive community is that PLA will deform in a hot car interior (which can reach 60°C+ / 140°F+). If you want this to last permanently:
* **Best:** ASA or ABS (High heat resistance, UV resistant).
* **Good:** PETG (Better heat resistance than PLA, easier to print).
* **Risk:** PLA (Only recommended if you park in a garage or live in a cold climate).

## 🎨 Color & Aesthetics (Mistake to Avoid)
**Do not print the internal mount frame in White!**
I made the mistake of printing the internal bracket and mount in white. Because the tolerances are tight, there is a tiny gap between the bezel and the tombstone, and you can see the white plastic peeking through.
* **Fix:** Print all internal mounting parts in **Black** to make them invisible behind the gaps.

## 🖨️ Printing the Buttons (Multicolor vs. Single Color)
The file includes custom buttons with icons (Power/Volume). The `.3mf` file is set up with split bodies for the button cap and the icon symbol.

### For Toolchanger / IDEX / AMS Users
I used a printer with a toolchanger to print the symbols in a contrasting color. You can simply assign a different filament to the symbol body in your slicer.

### For Single Extruder Users
If you cannot print multicolor:
1.  Open the `.3mf` file.
2.  Delete the "Symbol" body. This will leave the button with a recessed texture where the icon was.
3.  Print the button in your main color.
4.  Fill the recessed icon with white model paint or nail polish (the "enamel fill" technique).

### Note on TPU Seals
You might notice the seal is split from the button in the project files. I originally tested printing the seal in **TPU** (flexible filament). However, I found that printing the entire assembly in rigid plastic (PLA/PETG) actually worked better and felt more solid. I recommend printing the whole button assembly in rigid material.

## 📐 Slicer Settings & Orientation

### Mainframe
* **Orientation:** Print with the **Front Face (Display Side) down** on the build plate.
* **Plate Texture:** I recommend using a Textured PEI plate to give the front surface a nice, OEM-style finish.

### Buttons
* **Orientation:** Print with the **Symbol Face down** to get the cleanest quality on the icon.

### Internal Mounts
* **Orientation:** No specific orientation required; place them however they fit best on your bed.
* **Infill:** Standard 15-20% infill is sufficient, but consider adding extra walls (perimeters) for strength where the screws attach.
<img width="1708" height="1119" alt="render" src="https://github.com/user-attachments/assets/15856c01-845b-4156-a203-d12310900679" />
