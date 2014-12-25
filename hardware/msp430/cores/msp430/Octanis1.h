#ifndef OCTANIS_H
#define OCTANIS_H

// Motor driver pin definitions
#define M1234_SLEEP P1_0 //Motor 1-4 sleep pins, active low!
#define M1_IN1 P8_0
#define M1_IN2 P1_1
#define M2_IN1 P8_1
#define M2_IN2 P1_2
#define M3_IN1 P8_2
#define M3_IN2 P1_3
#define M4_IN1 P1_4
#define M4_IN2 P1_5

#define M5678_SLEEP P2_6 //Motor 5-8 sleep pins, active low!
#define M5_IN1 P1_6
#define M5_IN2 P1_7
#define M6_IN1 P2_0
#define M6_IN2 P2_1
#define M7_IN1 P2_2
#define M7_IN2 P2_3
#define M8_IN1 P2_4
#define M8_IN2 P2_5

// I2C address definitions
#define BMP180_ADDR 0x77 // barometer
#define MPU6050_ADDR 0x68 // Gyro, accelerometer
#define COMPASS_READ 0x3D
#define COMPASS_WRITE 0x3C


#endif
