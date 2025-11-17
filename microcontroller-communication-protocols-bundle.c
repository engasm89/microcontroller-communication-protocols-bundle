#include <stdio.h> // Include I/O for printing protocol status
#include <unistd.h> // Include POSIX sleep for timing between frames

// Simulated UART buffer and status
static int uart_ok = 1; // Track UART status (1=OK,0=ERR)

// Simulated SPI transfer state
static int spi_ok = 1; // Track SPI status (1=OK,0=ERR)

// Simulated I2C transfer state
static int i2c_ok = 1; // Track I2C status (1=OK,0=ERR)

// Initialize UART (stub)
int uart_init(long baud) { // Function to initialize UART with baud rate
  (void)baud; // Suppress unused parameter warning for baud
  uart_ok = 1; // Mark UART as OK
  return uart_ok; // Return UART status
} // End uart_init

// Send a UART frame (stub)
int uart_send(const char *msg) { // Function to send UART message
  if (!uart_ok) return 0; // Early return if UART not OK
  printf("UART SEND: %s\n", msg); // Print the message sent
  return 1; // Indicate success
} // End uart_send

// Initialize SPI master (stub)
int spi_init_master(void) { // Function to initialize SPI master
  spi_ok = 1; // Mark SPI as OK
  return spi_ok; // Return status
} // End spi_init_master

// Perform SPI transfer (stub)
int spi_transfer(unsigned char tx, unsigned char *rx) { // Function for SPI transfer
  if (!spi_ok) return 0; // Fail if SPI not OK
  unsigned char echoed = tx ^ 0xAA; // Simulate slave response by XOR
  *rx = echoed; // Store response in rx
  printf("SPI TX=0x%02X RX=0x%02X\n", tx, *rx); // Print TX/RX
  return 1; // Indicate success
} // End spi_transfer

// Initialize I2C master (stub)
int i2c_init_master(long freq_hz) { // Function to initialize I2C with frequency
  (void)freq_hz; // Suppress unused parameter warning
  i2c_ok = 1; // Mark I2C as OK
  return i2c_ok; // Return status
} // End i2c_init_master

// I2C write to device register (stub)
int i2c_write(unsigned char addr, unsigned char reg, unsigned char val) { // Function for I2C write
  if (!i2c_ok) return 0; // Fail if I2C not OK
  printf("I2C WRITE addr=0x%02X reg=0x%02X val=0x%02X\n", addr, reg, val); // Log write
  return 1; // Indicate success
} // End i2c_write

// I2C read from device register (stub)
int i2c_read(unsigned char addr, unsigned char reg, unsigned char *val) { // Function for I2C read
  if (!i2c_ok) return 0; // Fail if I2C not OK
  *val = (unsigned char)(reg ^ 0x55); // Simulate value
  printf("I2C READ addr=0x%02X reg=0x%02X val=0x%02X\n", addr, reg, *val); // Log read
  return 1; // Indicate success
} // End i2c_read

// Entry point demonstrating bundle of protocols
int main(void) { // Begin main function
  printf("Microcontroller Communication Protocols Bundle\n"); // Print title
  uart_init(9600); // Initialize UART at 9600 baud
  spi_init_master(); // Initialize SPI master
  i2c_init_master(100000); // Initialize I2C master at 100kHz
  uart_send("Hello"); // Send a UART message
  unsigned char rx = 0; // Prepare a variable for SPI RX
  spi_transfer(0x3C, &rx); // Perform SPI transfer with TX byte 0x3C
  unsigned char v = 0; // Prepare variable for I2C read value
  i2c_write(0x50, 0x01, 0xAB); // Write 0xAB to register 0x01 at address 0x50
  i2c_read(0x50, 0x01, &v); // Read from register 0x01 at address 0x50
  for (int i = 0; i < 3; ++i) { // Loop to emit JSON frames
    printf("{\"uart_ok\":%d,\"spi_ok\":%d,\"i2c_ok\":%d}\n", uart_ok, spi_ok, i2c_ok); // Print protocol states
    usleep(400000); // Delay 400 ms
  } // End loop
  return 0; // Return success
} // End main

