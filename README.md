# ESP32 with W5500 using MQTT
This repository contains a sample project that demonstrates how to connect an ESP32 board with the W5500 Ethernet module to an MQTT broker. MQTT (Message Queuing Telemetry Transport) is a lightweight messaging protocol widely used in IoT applications for communication between devices and servers.

## Hardware Requirements
To run this project, you will need the following hardware components:
ESP32 development board
W5500 Ethernet module
USB to Serial converter (for programming the ESP32)
Power supply (5V DC)
Software Requirements
Arduino IDE (latest version)
ESP32 board support package for Arduino IDE
PubSubClient library for MQTT communication

## Wiring
Ensure that you connect the ESP32 and the W5500 Ethernet module using the appropriate connections:
ESP32 5V    ->  W5500 VCC
ESP32 GND   ->  W5500 GND
ESP32 D18   ->  W5500 CS
ESP32 D23   ->  W5500 MOSI
ESP32 D19   ->  W5500 MISO
ESP32 D5    ->  W5500 SCK
ESP32 D26   ->  W5500 RESET
ESP32 G23   ->  W5500 INT

## Installation
Install the Arduino IDE and configure it to support the ESP32 board.
Open the Arduino IDE and install the PubSubClient library from the Library Manager.
Clone this repository or download the project files and open the main sketch (e.g., esp32_w5500_mqtt.ino) in the Arduino IDE.

## Configuration
Edit the sketch to set the appropriate configuration parameters:
MQTT_BROKER - The IP address or hostname of your MQTT broker.
MQTT_PORT - The MQTT broker port (default: 1883).
CLIENT_ID - A unique identifier for the ESP32 client connecting to the broker.
SUBSCRIBE_TOPIC - The MQTT topic to which the ESP32 will subscribe.
PUBLISH_TOPIC - The MQTT topic to which the ESP32 will publish messages.
ETHERNET_MAC - The MAC address of the W5500 module. You can use any unique MAC address.

## Uploading the Code
Connect the ESP32 board to your computer using the USB to Serial converter.
Select the appropriate board (e.g., "ESP32 Dev Module") and port from the Arduino IDE's "Tools" menu.
Click the "Upload" button to upload the code to the ESP32.

## Usage
Once the code is uploaded successfully, open the Serial Monitor in the Arduino IDE. You should see the ESP32 connecting to the MQTT broker and subscribing to the specified topic. It will also display any messages received on the subscribed topic.
You can now interact with the ESP32 and W5500 module via MQTT by publishing messages to the subscribed topic.
