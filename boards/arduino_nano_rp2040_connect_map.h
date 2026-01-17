/**
 * @file arduino_nano_rp2040_connect_map.h
 * @author Gkrizis Christos (gkrizis@ergonautomation.gr)
 * @brief Driver code for Arduino Nano RP2040 Connect
 * @version 0.1
 * @date 2026-01-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#if TRINAMIC_ENABLE
#error Trinamic plugin not supported!
#endif

#if N_ABC_MOTORS
#error "Axis configuration is not supported!"
#endif

#if I2C_STROBE_ENABLE && MOTOR_FAULT_ENABLE
#error "Motor fault input and I2C strobe input (keypad plugin) cannot be enabled at the same time."
#endif

// Define step pulse output pins.
#define STEP_PORT               GPIO_PIO  // N_AXIS pin PIO SM
#define STEP_PINS_BASE          15         // N_AXIS number of consecutive pins are used by PIO (15, 16 for X, Y)

// Define step direction output pins.
#define DIRECTION_PORT          GPIO_OUTPUT
#define X_DIRECTION_PIN         19
#define Y_DIRECTION_PIN         20
#define Z_DIRECTION_PIN         21  // Not used - dummy for 2-axis configuration
#define DIRECTION_OUTMODE       GPIO_SHIFT19

// Define stepper driver enable/disable output pin.
#define ENABLE_PORT             GPIO_OUTPUT
#define STEPPERS_ENABLE_PIN     5
#define STEPPERS_ENABLE_INVERT  1  // Active LOW

// Define homing/hard limit switch input pins.
#define X_LIMIT_PIN             12
#define Y_LIMIT_PIN             13
#define Z_LIMIT_PIN             14  // Not used - dummy for 2-axis configuration
#define LIMIT_INMODE            GPIO_MAP

#define AUXOUTPUT0_PORT         GPIO_OUTPUT
#define AUXOUTPUT0_PIN          6
#if I2C_ENABLE
#define I2C_PORT                1
#define I2C_SDA                 26
#define I2C_SCL                 27
#else
#define AUXOUTPUT1_PORT         GPIO_OUTPUT
#define AUXOUTPUT1_PIN          26
#define AUXOUTPUT2_PORT         GPIO_OUTPUT
#define AUXOUTPUT2_PIN          27
#endif
#define AUXOUTPUT3_PORT         GPIO_OUTPUT // Spindle PWM
#define AUXOUTPUT3_PIN          7
#define AUXOUTPUT4_PORT         GPIO_OUTPUT // Spindle direction
#define AUXOUTPUT4_PIN          4
#define AUXOUTPUT5_PORT         GPIO_OUTPUT // Spindle enable
#define AUXOUTPUT5_PIN          26   

// Define control signals (Reset/EStop, Feed Hold, Cycle Start)
#define AUXINPUT3_PIN           18  // Reset/EStop (2-axis CNC)

//#define NEOPIXELS_PIN 27
//#define NEOPIXELS_NUM 5

// Define driver spindle pins
#if DRIVER_SPINDLE_ENABLE
#define SPINDLE_PORT            GPIO_OUTPUT
#endif
#if DRIVER_SPINDLE_ENABLE & SPINDLE_PWM
#define SPINDLE_PWM_PIN         AUXOUTPUT3_PIN
#endif
#if DRIVER_SPINDLE_ENABLE & SPINDLE_DIR
#define SPINDLE_DIRECTION_PIN   AUXOUTPUT4_PIN
#endif
#if DRIVER_SPINDLE_ENABLE & SPINDLE_ENA   
#define SPINDLE_ENABLE_PIN      AUXOUTPUT5_PIN
#endif

// Define flood and mist coolant enable output pins.
#if COOLANT_ENABLE
#define COOLANT_PORT            GPIO_OUTPUT
#endif

// Define user-control controls (cycle start, reset, feed hold) input pins.
#if CONTROL_ENABLE & CONTROL_HALT
#define RESET_PIN               AUXINPUT3_PIN
#endif

#if PROBE_ENABLE
#define PROBE_PIN               14  // Probe input
#endif

#if SAFETY_DOOR_ENABLE
#define SAFETY_DOOR_PIN         25  // Safety door input
#endif

#undef BOARD_NAME
#define BOARD_NAME "Arduino Nano RP2040 Connect - 2 Axis CNC"
