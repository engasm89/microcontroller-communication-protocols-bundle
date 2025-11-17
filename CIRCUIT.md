# Protocols Bundle — Circuit Schematic

- Course: Microcontroller Communication Protocols Bundle
- Author: Ashraf S A AlMadhoun
- Link: https://www.udemy.com/course/serial-communication-spi-rs232-spi-communication-protocols-bundle/?couponCode=JULYMAXDICOUNT

## Connections

- UART: `TX -> RX`, `RX -> TX`, GND common.
- SPI: `MOSI`, `MISO`, `SCK`, `CS` between master and slave.
- I2C: `SDA`, `SCL` with 4.7k pull-ups to VCC, common GND.

## Diagram (ASCII)

```
 UART:  MCU1 TX ---- RX MCU2
        MCU1 RX ---- TX MCU2
        GND  --------- GND

 SPI:   MOSI ---- MOSI
        MISO ---- MISO
        SCK  ---- SCK
        CS   ---- CS

 I2C:   SDA <----> SDA (pull-up)
        SCL <----> SCL (pull-up)
        GND ------- GND
```

## Purchase With Discount

Get a discounted price and build robust communication links — use the course link above.

