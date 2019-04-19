# IoT Engineering
## Project Example

## Introduction
This project is part of the [IoT Engineering](../../../fhnw-iot) course.

> * 2-person teams, building an IoT system.
> * 32 hours of work per person, 1 prototype.
> * 10' presentation of the project at Demo Day.
> * Slides, source code and setup steps on GitHub.
> * Both team members are able to explain the project.

### Team members
* [@tamberg](https://github.com/tamberg)
* [@DIYKulturZH](https://github.com/DIYKulturZH)

## Deliverables
> The following deliverables are mandatory.

### Source code
> Source code, Arduino C, JS or Python, committed to (this) project repo.

#### Sensor device
> Embedded code / microcontroller firmware.

##### Source code
* ...

##### Setup software
* ...

##### Setup hardware
* https://github.com/tamberg/fhnw-iot/wiki/Feather-nRF52840-Express
* https://github.com/tamberg/fhnw-iot/wiki/FeatherWing-RFM95W
* https://github.com/tamberg/fhnw-iot/wiki/Grove-Sensors#temperature--humidity-sensor-dht11
* https://github.com/tamberg/fhnw-iot/wiki/Grove-Adapters#pinout

#### Actuator device
> Embedded code / microcontroller firmware.

##### Source code
* [Arduino/nRF52840_DHT11_Test/nRF52840_DHT11_Test.ino](Arduino/nRF52840_DHT11_Test/nRF52840_DHT11_Test.ino)
* [Arduino/nRF52840_LoRaWAN_Test/nRF52840_LoRaWAN_Test.ino](Arduino/nRF52840_LoRaWAN_Test/nRF52840_LoRaWAN_Test.ino)

##### Setup software
* TODO: set keys

##### Setup hardware
* https://github.com/tamberg/fhnw-iot/wiki/Feather-Huzzah-ESP8266
* https://github.com/tamberg/fhnw-iot/wiki/Grove-Actuators#chainable-rgb-led
* https://github.com/tamberg/fhnw-iot/wiki/Grove-Sensors#button
* https://github.com/tamberg/fhnw-iot/wiki/Grove-Adapters#pinout

#### TTN backend
> ... IoT platform setup steps.

* TODO: setup steps

#### ThingSpeak dashboard
> ... IoT platform setup steps.

* TODO: setup steps

#### TTN to ThingSpeak adapter
> Glue Code used on the gateway or "in the cloud".

##### Source code
* [Nodejs/TtnToThingSpeakAdapter/index.js](Nodejs/TtnToThingSpeakAdapter/index.js)
* [Nodejs/TtnToThingSpeakAdapter/now.json](Nodejs/TtnToThingSpeakAdapter/now.json)

##### Setup
* Edit [index.js](Nodejs/TtnToThingSpeakAdapter/index.js) to add your TTN AppID:

    ```
    const appId = "TTN_APP_ID";
    ```
    
    and per device TNT device IDs and ThingSpeak keys:

    ```
    const writeApiKeys = {
        "TTN_DEVICE_ID_1": "WRITE_API_KEY_1", // CHANNEL_ID_1
        ...
    }
    ```

* To deploy the code on [Zeit Now](https://zeit.co/now), type:<pre>
$ cd Nodejs/TtnToThingSpeakAdapter
$ now</pre>

### Presentation
> 4-slide presentation, PDF format, committed to (this) project repo.

* [MY_TEAM_PROJECT_PRESENTATION.pdf](MY_TEAM_PROJECT_PRESENTATION.pdf)

#### Use case
> Use-case of your project.

This project is a temperature and humidity monitoring system with a configurable alert.

* Measure temperature and humidity
* Display (historic) measurements
* Set a humidity alarm threshold
* Get a humidity alarm
* Confirm an alarm

#### Reference model
> Reference model of your project.

* LoRaWAN-connected sensor device with a temperature and humidity sensor
* Wi-Fi-connected actuator device with a buzzer, a display, a button and a potentiometer (dial)
* LoRaWAN Gateway
* Wi-Fi Router
* TTN LoRaWAN backend
* ThingSpeak backend
* Glue code on Zeit Now

#### Interface documentation
> Single slide interface documentation.

* ...

#### Issues
> Issues you faced, how you solved them.

* Device: Pin mapping, "D2 is D5" on the nRF52840
* See also [GitHub Issues](../../issues) of this project.

### Live demo
> Working end-to-end prototype, "device to cloud", part of your 10' presentation.

[https://MY_TEAM_PROJECT_DEMO_HOST:PORT/](https://MY_TEAM_PROJECT_DEMO_HOST:PORT/)

1) Sensor input on a IoT device triggers an event.
2) The event or measurement shows up online, in an app or Web client.
3) The event triggers actuator output on the same or on a separate IoT device.

## Submission deadline
> Commit and push to (this) project repo before Demo Day, _03.06.2019, 00:00_.
