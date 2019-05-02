# TinyLidarPhoton
Achieving approximately 930Hz I2C reading rates using Particle Photon

The documentation for TinyLidar has sample code for the Arduino family of boards but when adapting this code for other boards
like the Photon from Particle, it was realized that, the dependant I2C library is no longer supported.

This script adapts the original code for use with the wire library to achieve same results.
