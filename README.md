# Wireless Digital Notice Board

Welcome to the Wireless Digital Notice Board System! 🖥️📲
This project uses the LPC2148 microcontroller to display scrolling messages on a 4-panel LED matrix. Messages are sent from a smartphone via Bluetooth 📱🔗 and saved in EEPROM 💾, so they stay even after power is turned off. It’s a simple, secure 🔐, and useful system for schools 🎓, offices 🏢, or public places 🚌, a smart way to share messages wirelessly! 🚀

---
## 📋 Project Overview

This project combines multiple hardware modules to create a smart and interactive wireless display system. Here’s what it does:
🖥️ **Displays Messages**: Shows scrolling text on a 4-panel 8×8 dot matrix LED display.

📱 **Bluetooth Connectivity**: Accepts messages wirelessly from a smartphone using the HC-05 Bluetooth module.

💾 **EEPROM Storage**: Saves messages in the AT24C256 EEPROM, ensuring they remain even after the device is powered off.

🔐 **Secure Message Update**: Only updates messages that come with a valid passkey (`@153Your Message$`).

🔁 **Auto-Scroll Display**: Continuously scrolls stored messages until a new one is received.

🧠 **Built on LPC2148**: Uses the ARM7-based LPC2148 microcontroller for fast and reliable control.

This system is easy to use, secure, and ideal for campuses, offices, and public spaces where digital communication is essential. 🚀

---
## 🔧 Hardware Components
- **LPC2148** (ARM7 Microcontroller)
- **4 × 8×8 Dot Matrix LED Displays**
- **HC-05 Bluetooth Module**
- **AT24C256 EEPROM** (I2C-based)
- **74HC573** (Octal Latch)
- **74HC164** (Shift Register)

---

## 📂 Project Structure
```
Major_Project/
├── delay.c / delay.h          # Custom delay functions
├── dml.c / dml.h              # Dot matrix LED control
├── i2c.c / i2c.h              # I2C protocol implementation
├── i2c_eeprom.c / .h          # EEPROM read/write functions
├── uart.c / uart.h            # UART communication
├── defines.h                  # Global definitions
├── projectmain.c              # Main source file
```

---

## 💡 Features
- Send text messages via Bluetooth using a passkey (e.g., `@153Message$`)
- Scroll long messages across all 4 LED matrices
- Store and retrieve messages using EEPROM (AT24C256)
- Continuously display stored messages until a new one is received
- Default message shown if EEPROM is empty

---

## 🛠 Tools Used
- **Keil uVision** (Embedded C development)
- **Flash Magic** (Programming LPC2148)
- **Embedded C Language**

---

## 🚀 How to Use
1. Flash the firmware using Flash Magic onto LPC2148.
2. Power on the board and connect your smartphone to **HC-05**.
3. Use a terminal app to send a message like:
   ```
   @153Hello World$
   ```
4. The system will:
   - Validate the passkey
   - Store the message in EEPROM
   - Scroll it on the LED display

---

## ✅ Status
- Bluetooth communication ✔️  
- EEPROM read/write ✔️  
- 4-panel dot matrix scrolling ✔️  
- UART + I2C integration ✔️  
- Passkey-based security ✔️  

---
💡 **Hardware Highlights**

- **ARM7 Development Board Integration 🔗:** Centralized processing with LPC2148 microcontroller.
- **I2C Communication Protocol 🔄:** Efficient interfacing with peripheral devices using I2C for reliable data exchange.
- **UART Interrupt-driven Messaging 🚦:** Real-time wireless data transmission with UART interrupts for responsive communication.
- **Dynamic LED Matrix Display 🟩:** Multi-panel dot matrix modules for clear, vibrant message visualization.
- **Interactive LCD Interface 🖥️:** Character LCD for status updates and user feedback.
- **User-friendly Controls ⌨️:** Push buttons and 4x4 keypad for intuitive user interaction.
- **Sensor Connectivity 🌡️:** On-board ADC for analog sensor integration.
- **Modular Wiring 🧩:** Organized and scalable hardware connections for easy maintenance and upgrades.

---
## 🔧 Improvements & Future Enhancements

- **LCD Integration 📟**: While this project uses 8×8 dot matrix displays, it can be extended to work with an LCD (like 16x2 or graphical LCDs) for clearer, more flexible message display.   
- **Mobile App Interface 📱**: Create a simple Android app to send and manage messages easily over Bluetooth.  
- **Multi-Language Support 🌐**: Enhance character encoding to support local languages or symbols.  
- **Power Efficiency 💡**: Use LPC2148’s low-power modes to reduce energy consumption in idle states.  
- **Message Management 🗂️**: Implement EEPROM history to view or restore previously displayed messages.  
---
## 🤝 Contributing

- Developed as part of *Embedded Systems Training*
- Based on ARM7 *LPC2148* architecture
- Guided by trainers from *Vector India*


---

## 🙏 Acknowledgments

- 🎓 Developed by: *Sai Manideep Chekkala*
- 🏫 Major Project
- 🎯 Tech: LPC2148, Embedded C, 8*8 LED Matrix, HC-05(Bluetooth), AT24C256(EEPROM).

---

**Happy Coding!** 💻✨  
Let's keep sharing messages, wirelessly and smartly! 🖥️📲🚀

