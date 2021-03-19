## HRV measurements via rPPG

The project is in ongoing development, but the main goal is to be able to measure HRV via laptop / web camera.

## Requirements

### Install latest openCV

I used this repo for installation on Ubuntu: https://github.com/jitendra29mishra/OpencvInstallation

### Compile camera.cpp

`g++ camera.cpp -o hrv.bin `pkg-config --cflags --libs opencv4``