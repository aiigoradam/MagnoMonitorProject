# MagnoMonitor

MagnoMonitor is a program designed to monitor and analyze magnetic fields in real-time, using data from a transmitter device that measures magnetic fields in three orthogonal axes (x, y, and z).

![Logo](MagnoMonitor.gif)

## Features

- Real-time monitoring and processing of magnetic field data
- COM port communication for data input
- Configurable connection settings
- Live chart visualization
- 3D graph representation
- Fourier transform analysis
- Data logging functionality
- User-friendly interface with multiple views

## Requirements

- LabWindows/CVI
- RS-232 compatible device or simulator for data input
- com0com software for virtual COM ports (if using simulator)

## Setup

1. Connect the measuring device (or set up virtual COM ports if using the simulator).
2. Launch MagnoMonitor (and Transmitter if using the simulator).
3. Configure the COM port settings.

## Usage

1. Click "CONFIGURE" to set up communication parameters.
2. (Optional) Enable data logging by toggling "Write to File".
3. Set the sample rate and time window for the strip chart.
4. Click "START" to begin data acquisition and processing.
5. Use tabs to switch between live chart, 3D graph, and Fourier transform views.
6. Click "STOP" to end data acquisition.
7. In the Fourier transform tab, click "PLOT FFT" to calculate and display the Fourier transform.

## Configuration

Use the RS-232 Configurator to set:
- COM port
- Baud rate
- Parity
- Data bits
- Stop bits
- Handshaking mode

## Logging

Data can be logged to a text file. Choose the file location and name in the interface.

## Visualization

- Live Chart: Displays real-time changes in magnetic field magnitude.
- 3D Graph: Shows variations in magnetic field values over time.
- Fourier Transform: Displays the frequency spectrum of the recorded data.

## Notes

- The program uses multithreading for handling asynchronous data reception.
- A companion Transmitter program is available for simulation purposes.

## Known Issues

- Lack of reset mechanism without relaunching the program.
- Limited error-handling mechanisms.
- Potential issues with input queue when interrupting data acquisition.
- Occasional data acquisition stoppage when switching to 3D graph tab.
- Incomplete file writing upon program exit.

## Future Improvements

- Add cursors and numeric controls to graphs.
- Implement harmonic analysis.
- Expand data-saving options.
- Improve error-handling mechanisms.
- Add circular program flow for easy restart.
- Provide options for different data units.
- Create additional visualization options.
- Introduce more signal processing options.

## Author
Copyright (c) 2024 Igor Adamenko. All rights reserved.
Afeka College of Engineering
Electrical Engineering Department 
