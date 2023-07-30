Here is a README file for the attached C code:

# Vehicle Control System

This program implements a vehicle control system with the following features:

## Main Menu

- Start engine 
- Stop engine
- Quit system

## Sensors Menu (when the engine is running)

- Stop engine
- Set traffic light color (G, O, R) 
- Set room temperature
- Display system state

## Functionality

- Controls AC based on room temperature 
- Controls vehicle speed based on traffic light
- Uses preprocessor directive to optionally control engine temperature
- Prints the current state of systems after each action

## Structures

- `TemperatureMode` struct to store temperature values
- Linked list to store room and engine temperature 

## Input/Output

- User selects options from menus printed to the console  
- User enters values when prompted
- Program prints system state and messages

## Notes

- Uses rand() to generate sensor values 
- Traffic light values defined as enum
- scanf() used for user input
- malloc() to allocate TemperatureMode structs

# Cmake 
add Cmakelists.txt for easy building, and linking the executables together
## How to
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```
### run 
```
$ cd build
$ ./CarSystemMain
```
Let me know if you would like me to explain or expand on any part of the README.
