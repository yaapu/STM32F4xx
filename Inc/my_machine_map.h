/*
  uno_map.h - driver code for STM32F411 ARM processor on a Nucleo-F411RE board

  Part of grblHAL

  Copyright (c) 2020-2021 Terje Io

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#if N_ABC_MOTORS > 1
#error "Axis configuration is not supported!"
#endif

#if TRINAMIC_ENABLE
#error "Trinamic plugin not supported!"
#endif

#define BOARD_NAME "My Machine - Yaapu"
#define BOARD_URL "https://www.makerfabs.com/arduino-cnc-shield-v3.html"

#define SERIAL_PORT     2   // GPIOA: TX = 2, RX = 3
//#define SERIAL1_PORT   31   // GPIOC: TX = 10, RX = 11

#define I2C_PORT        1   // GPIOB: SCL = 8, SDA = 9
#define IS_NUCLEO_BOB
#define HAS_IOPORTS
#define VARIABLE_SPINDLE // Comment out to disable variable spindle

#if ETHERNET_ENABLE
#define SPI_PORT                2 // GPIOB, SCK_PIN = 13, MISO_PIN = 14, MOSI_PIN = 15
#endif

// Define step pulse output pins.
#define X_STEP_PORT             GPIOA // D2
#define X_STEP_PIN              10
#define Y_STEP_PORT             GPIOB // D3
#define Y_STEP_PIN              3
#define Z_STEP_PORT             GPIOB // D4
#define Z_STEP_PIN              5
#define STEP_OUTMODE            GPIO_BITBAND
//#define STEP_PINMODE            PINMODE_OD // Uncomment for open drain outputs

// Define step direction output pins.
#define X_DIRECTION_PORT        GPIOB // D5
#define X_DIRECTION_PIN         4
#define Y_DIRECTION_PORT        GPIOB // D6
#define Y_DIRECTION_PIN         10
#define Z_DIRECTION_PORT        GPIOA // D7
#define Z_DIRECTION_PIN         8
#define DIRECTION_OUTMODE       GPIO_BITBAND
//#define DIRECTION_PINMODE       PINMODE_OD // Uncomment for open drain outputs

// Define stepper driver enable/disable output pin.
#define STEPPERS_ENABLE_PORT    GPIOC // Morpho CN7
#define STEPPERS_ENABLE_PIN     12
#define STEPPERS_ENABLE_MASK    STEPPERS_ENABLE_BIT
//#define STEPPERS_ENABLE_PINMODE PINMODE_OD // Uncomment for open drain outputs

// Define homing/hard limit switch input pins.
#define X_LIMIT_PORT            GPIOC // D9
#define X_LIMIT_PIN             7
#define Y_LIMIT_PORT            GPIOB // D10
#define Y_LIMIT_PIN             6
#ifdef VARIABLE_SPINDLE
  #define Z_LIMIT_PORT          GPIOA // D12
  #define Z_LIMIT_PIN           6
#else
  #define Z_LIMIT_PORT          GPIOA // D11
  #define Z_LIMIT_PIN           7
#endif
#define LIMIT_INMODE            GPIO_BITBAND

// Comment out if Z limit pin is not assigned to an interrupt enabled pin on a different port.

#define Z_LIMIT_POLL

// Define spindle enable and spindle direction output pins.
#ifdef VARIABLE_SPINDLE
  #define SPINDLE_ENABLE_PORT   GPIOC // on morpho header
  #define SPINDLE_ENABLE_PIN    4
#else
  #define SPINDLE_ENABLE_PORT   GPIOA // D12
  #define SPINDLE_ENABLE_PIN    6
#endif
#define SPINDLE_DIRECTION_PORT  GPIOA // D13
#define SPINDLE_DIRECTION_PIN   5

// Define spindle PWM output pin.
#ifdef VARIABLE_SPINDLE
#define SPINDLE_PWM_PORT_BASE   GPIOA_BASE // D11
#define SPINDLE_PWM_PIN         7
#endif

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PORT      GPIOB // A3
#define COOLANT_FLOOD_PIN       0
#define COOLANT_MIST_PORT       GPIOC // A4
#define COOLANT_MIST_PIN        1

// Define user-control CONTROLs (cycle start, reset, feed hold) input pins.
#define CONTROL_PORT            GPIOA
#define RESET_PIN               0 // A0
#define FEED_HOLD_PIN           1 // A1
#define CYCLE_START_PIN         4 // A2

#define CONTROL_INMODE          GPIO_MAP

// Define probe switch input pin.
#define PROBE_PORT              GPIOC // A5
#define PROBE_PIN               0
// 2 AUX in
//#define AUXINPUT0_PORT          GPIOB
//#define AUXINPUT0_PIN           1
//#define AUXINPUT1_PORT          GPIOC
//#define AUXINPUT1_PIN           12

// 3 AUX out
#define AUXOUTPUT0_PORT         GPIOC
#define AUXOUTPUT0_PIN          8
#define AUXOUTPUT1_PORT         GPIOA
#define AUXOUTPUT1_PIN          12
#define AUXOUTPUT2_PORT         GPIOC
#define AUXOUTPUT2_PIN          5

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS == 1
#define M3_AVAILABLE
#define M3_STEP_PORT            GPIOB
#define M3_STEP_PIN             1
#define M3_DIRECTION_PORT       GPIOB
#define M3_DIRECTION_PIN        12
#define M3_LIMIT_PORT           GPIOB
#define M3_LIMIT_PIN            2
#define M3_ENABLE_PORT          GPIOA
#define M3_ENABLE_PIN           11
#endif

#ifdef SPI_PORT

#if ETHERNET_ENABLE
#undef SPI_ENABLE
#define SPI_ENABLE 1
#define SPI_CS_PORT             GPIOC
#define SPI_CS_PIN              13
#define SPI_IRQ_PORT            GPIOC
#define SPI_IRQ_PIN             14
#define SPI_RST_PORT            GPIOC
#define SPI_RST_PIN             15
#endif

#endif
/**/
