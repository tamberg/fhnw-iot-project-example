# IoT Engineering
## Project Example

## Introduction
This project is part of the [IoT Engineering](../../../fhnw-iot) course.

* 2-person teams, building an IoT system.
* 32 hours of work per person, 1 prototype.
* 10' presentation of the project at Demo Day.
* Slides, source code and setup steps on GitHub.
* Both team members are able to explain the project.

### Team members
* [@tamberg](https://github.com/tamberg)
* [@DIYKulturZH](https://github.com/DIYKulturZH)

## Deliverables
> The following deliverables are mandatory.

### Source code
> Source code, Arduino C, JS or Python, committed to (this) project repo.

#### Device
> Embedded code / microcontroller firmware.

* [Arduino/nRF52840_DHT11_Test/nRF52840_DHT11_Test.ino](Arduino/nRF52840_DHT11_Test/nRF52840_DHT11_Test.ino)
* [Arduino/nRF52840_LoRaWAN_Test/nRF52840_LoRaWAN_Test.ino](Arduino/nRF52840_LoRaWAN_Test/nRF52840_LoRaWAN_Test.ino)

#### Glue code
> Glue Code used on the gateway or "in the cloud".

* [Nodejs/TtnToThingSpeakAdapter/index.js](Nodejs/TtnToThingSpeakAdapter/index.js)
* [Nodejs/TtnToThingSpeakAdapter/now.json](Nodejs/TtnToThingSpeakAdapter/now.json)
* TODO: setup steps

#### Dashboard
> App or Web UI code, or IoT platform setup steps.

* TODO: setup steps

### Presentation
> 4-slide presentation, PDF format, committed to (this) project repo.

* [MY_TEAM_PROJECT_PRESENTATION.pdf](MY_TEAM_PROJECT_PRESENTATION.pdf)

1) Use-case of your project.
2) Reference model of your project.
3) Single slide interface documentation.
4) Issues you faced, how you solved them.

### Live demo
> Working end-to-end prototype, "device to cloud", part of your 10' presentation.

[https://MY_TEAM_PROJECT_DEMO_HOST:PORT/](https://MY_TEAM_PROJECT_DEMO_HOST:PORT/)

1) Sensor input on a IoT device triggers an event.
2) The event or measurement shows up online, in an app or Web client.
3) The event triggers actuator output on the same or on a separate IoT device.

## Submission deadline
> Commit and push to (this) project repo before Demo Day, _03.06.2019, 00:00_.
