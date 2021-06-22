# Extruderlight
ATTINY85 control for 3D printer Extruder Lights

Control 4 RGB leds fix on Extruder cover by an ATTINY85
Interface mount on RAMPS AUX2 connector

**Principle:  Use the MARLIN's command M42**
*M42 P64 S255  : Pin 42 set to 255 (1)*

Files:
Code .ino for ATTINY, download Arduino IDE.
Pictures
Extract of GCODE generate by a slicer to set the pins

Remarq: The module uses the power on the AUX2 connector, the current is limited.
Don't use more than 8 leds.

STL files for support available on Thingiverse:
https://www.thingiverse.com/thing:4891687

VIDEO available on Youtube
https://youtu.be/6vatNTefBa4
