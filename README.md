# NeuroTap
Tap-response prototype tracking focus, fatigue, and friction during high-stakes mental load.
------------------

## Overview

NeuroTap is a tap-based cognitive load testing system that uses an ESP32 microcontroller, LED cueing, and tactile response input to measure fatigue-indiced delays in reaction time. Built as a minimal, desktop-connected prototype, it represents the first functioning tool in a broader cognitive neurotechnological suite aimed at tracking mental performance in high-stakes environments.

------------------

## Features
- Reaction time measurement with millisecond precision
- False tap detection (response without cue)
- Serial data logging to CSV
- Minimal interface (command-line)

------------------

## System Overview
- LED flashes at randomized intervals as visual cues
- User taps button in response
- ESP32 microcontroller timestamps all responses
- Output includes valid tap latency and error frequency

------------------

## Hardware 
- ESP32 microcontroller
- Tactile pushbutton
- Breadboard
- USB-C wire

<img width="569" height="219" alt="Screenshot 2025-07-18 at 5 24 03 PM" src="https://github.com/user-attachments/assets/0d59de1f-27f9-4fce-96e3-34a93c69c34a" />

------------------

## Planned Improvements
- GUI overlay
- Configurable test parameters
- Tap classification and ML model integration
- Compatibility with remaining systems in GABAv0.1

------------------

## Disclaimer

This prototype is intended for research and development purposes only. 
It is not validated for clinical use or medical diagnosis.

