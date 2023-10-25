# Static Fire Test Code & Electronics

<img width="533" alt="Screenshot 2023-10-24 at 11 37 10 PM" src="https://github.com/joeyheo/Static-Fire-Electronics/assets/73047475/4ef9ee04-e083-4309-8739-dc798dc6bf6d">


## Overview

Developed by Joey Heo and Vega Space & Propulsion Lab, this code is meticulously crafted for the testing of rocket engines. It measures their thrust over the duration of the rocket motor's burn time. Employing the HX711 load cell amplifier module, the code ensures accurate and consistent measurements. Additionally, to enhance user interaction and provide real-time feedback, a buzzer for audio cues and an RGB LED for visual indicators are incorporated.

## Setup

### Hardware Requirements:

1. HX711 Load Cell Amplifier
2. Buzzer/Speaker
3. RGB LED
4. Relay Module

### Pin Connections:

- **HX711**:
  - DOUT: Pin 3
  - CLK: Pin 2
- **Buzzer**: Pin 4
- **RGB LED**:
  - Red: Pin 8
  - Green: Pin 9
  - Blue: Pin 10
- **Relay**: Pin 11

## How it Works:

1. **Initialization**:
   - Establish communication with the HX711 load cell amplifier and reset the scale to zero.
   - Initialize the buzzer, relay, and RGB LED.

2. **Waiting Stage**:
   - If digital pin 5 isn't HIGH, the system remains in the waiting stage. The RGB LED will produce a blue flash synchronized with a buzzer tone to indicate this state.

3. **Fire Stage**:
   - When digital pin 5 turns HIGH, the system transitions to the fire stage. A countdown sequence featuring yellow LED flashes and buzzer sounds is initiated before the firing begins.
   - During the fire stage, the RGB LED emits a red light while the system continuously measures and displays the thrust in kilograms.

## Functions Breakdown:

- **RGB_color(int red_light_value, int green_light_value, int blue_light_value)**: Governs the colors displayed by the RGB LED.
  
- **holdingStage()**: When activated, the system projects a green LED light and emits a continuous buzzer sound.
  
- **waitingStage()**: In this mode, a pulsating blue LED light couples with intermittent buzzer sounds.
  
- **countdownStage()**: A countdown procedure signaled by a series of yellow LED flashes and buzzer beeps.
  
- **fireStage()**: The primary function where the thrust gets measured and relayed.

## Calibration:

The in-built calibration feature tailors the system for precise thrust measurements. The default calibration factor stands at `-239250`. This factor can undergo adjustments in real-time via the serial monitor:

- Increment the calibration factor by pressing `+` or `a`.
- Decrement it by pressing `-` or `z`.

## Safety Notice:

Rocket engine testing is a high-risk procedure. It's paramount to abide by safety protocols and to operate the equipment within a controlled and secure environment. Ensure that both the load cell and other equipment are designed to withstand the forces you intend to apply.

## Disclaimer:

Utilize this code and its associated hardware components at your own discretion and risk. Neither Joey Heo, Vega Space & Propulsion Lab, nor any associated parties bear responsibility for any damages, injuries, or mishaps resulting from its use. For maximum safety, always have precautionary measures in place and seek advice from relevant experts when necessary.

---

**Note:** This README offers a succinct explanation of the code and its operational nuances. For a more comprehensive understanding, consider integrating detailed instructions, images, or diagrams, especially if the setup is intended for a wider audience.

![IMG_2967](https://user-images.githubusercontent.com/73047475/109959579-08d25580-7d2b-11eb-9709-972895e61af2.jpg)
![IMG_2968](https://user-images.githubusercontent.com/73047475/109959142-703bd580-7d2a-11eb-8058-3b848d5a9cca.jpg)
![IMG_2969](https://user-images.githubusercontent.com/73047475/109959144-716d0280-7d2a-11eb-8674-40fcb697ae22.jpg)
![IMG_2966](https://user-images.githubusercontent.com/73047475/109959114-6a45f480-7d2a-11eb-90cc-ff8bbece3066.jpg)
