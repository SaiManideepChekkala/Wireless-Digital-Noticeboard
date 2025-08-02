# Wireless Digital Notice Board

Welcome to the Wireless Digital Notice Board System! 🖥️📲
This project uses the LPC2148 microcontroller to display scrolling messages on a 4-panel LED matrix. Messages are sent from a smartphone via Bluetooth 📱🔗 and saved in EEPROM 💾, so they stay even after power is turned off.

It’s a simple, secure 🔐, and useful system for schools 🎓, offices 🏢, or public places 🚌 — a smart way to share messages wirelessly! 🚀

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

