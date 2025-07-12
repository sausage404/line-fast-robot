# Line Following Robot Project

This repository contains code for line following robots using either SPACE-01 or Sopon boards. The robots use PID control for line following and support various movement patterns.

## Installation

### Required Libraries
1. Install the following libraries via Arduino IDE:
   ```
   Arduino > Sketch > Include Library > Add .zip Library
   ```
   - SPACE01.zip
   - light_CD74HC4067.zip

### Driver Installation
If you have upload issues:

1. Connect the board to your computer
2. Run `Driver/CH341SER.EXE` as administrator
3. Click Install
4. Restart your PC

## Board Configuration

Configure your Arduino IDE as follows:

1. Go to `Tools > Board` and select **Arduino Nano**
2. Select the processor based on your board:
   - SPACE-01 board: `Tools > Processor > ATmega328P (Old Bootloader)`
   - Sopon board: `Tools > Processor > ATmega328P`
3. Select the appropriate COM port under `Tools > Port`

## Project Structure

- `board/`
  - `space-01/` - Code for SPACE-01 board variants
    - `2000/` - 2000 series configuration
    - `3000/` - 3000 series configuration
  - `sopon/` - Code for Sopon board

## Features

- Line following using PID control
- Sensor calibration
- Turn functions (left/right)
- Cross detection
- Timed movements
- Motor control
- Serial debugging support

## Usage

1. Select the appropriate board folder for your hardware
2. Upload the main .ino file
3. Use the calibration function to adjust sensors:
   ```cpp
   ShowCalibrate();  // Uncomment in setup()
   ```
4. Configure movement parameters:
   ```cpp
   TrackTime(speed, Kp, Kd, duration);  // Basic line following
   TrackCross(speed, Kp, Kd, action);   // Line following with intersection detection
   ```

## Pin Configuration

### SPACE-01 Board
- 8 analog sensors (A0-A7)
- Motor control pins defined in SPACE01 library

### Sopon Board
- 8 analog sensors via MCP3008
- Motor pins:
  - PWMA: 5
  - AIN1: 2
  - AIN2: 3
  - PWMB: 6
  - BIN1: 4
  - BIN2: 7

## License

This project is provided for educational purposes.