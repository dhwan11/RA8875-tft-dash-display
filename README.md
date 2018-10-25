# RA8875-tft-dash-display
Using the RA8875 driver to run Adafruit 5" tft lcd display. My project is to build a dash display for a formula SAE car but the basics from this project will apply to all tft/RA8875 projects.

# parts
The parts I am using for this project are:

1.The RA 8875 driver - https://www.adafruit.com/product/1590
![1590-08](https://user-images.githubusercontent.com/43940356/47516546-b841b800-d853-11e8-8208-4cf2bbfa796e.jpg)

2. 5.0" 40-PIN 800X480 TFT DISPLAY WITHOUT TOUCHSCREEN - https://www.adafruit.com/product/1680
![lcd display](https://user-images.githubusercontent.com/43940356/47517324-d4deef80-d855-11e8-8a92-93e77edd48d3.jpg)

3. Teensy 3.2 - https://www.pjrc.com/store/teensy32.html
![teensy32](https://user-images.githubusercontent.com/43940356/47517437-330bd280-d856-11e8-8871-3d8b3cc98af7.jpg)


# Connections:
RA8875 pin: Teensy 3.2 pin

Vin: +5V

GND: GND

3Vo: Not used 

Lite: Not used

SCK: pin13

MISO: pin12

MOSI: pin11

CS: pin10

RST: pin9

WAIT: Not used

INT: pin3

Y+: Not used

Y-: Not used

X+: Not used

Y-: Not used

some images to help
![img_9832](https://user-images.githubusercontent.com/43940356/47524388-81c26800-d868-11e8-90df-9ccc8db05738.JPG)


See the link below for a video of how to connect a ribbon cable to ra8875. Its not exactly the same but it is key to carefully open the connector clip on the RAA875, inserting the ribbon cable and then closing the clip. 

https://www.youtube.com/watch?v=2wmvtg797t0
