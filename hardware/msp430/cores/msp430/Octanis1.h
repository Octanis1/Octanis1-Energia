#ifndef OCTANIS_H
#define OCTANIS_H

// Motor driver pin definitions
#define M1234_SLEEP P1_0 //Motor 1-4 sleep pins, active low!
#define M1_PH P8_0
#define M1_EN P1_1
#define M2_PH P8_1
#define M2_EN P1_2
#define M3_PH P8_2
#define M3_EN P1_3
#define M4_PH P1_4
#define M4_EN P1_5

#define M5678_SLEEP P2_6 //Motor 5-8 sleep pins, active low!
#define M5_PH P1_6
#define M5_EN P1_7
#define M6_PH P2_0
#define M6_EN P2_1
#define M7_PH P2_2
#define M7_EN P2_3
#define M8_PH P2_4
#define M8_EN P2_5

//solar charge enable
#define BATT_CHG_EN P7_0

//battery heat pad, battery powered
#define HEAT_BAT 	P3_4

// I2C address definitions
#define BMP180_ADDR 0x77 // barometer
#define MPU6050_ADDR 0x68 // Gyro, accelerometer
#define COMPASS_READ 0x3D
#define COMPASS_WRITE 0x3C


#endif
