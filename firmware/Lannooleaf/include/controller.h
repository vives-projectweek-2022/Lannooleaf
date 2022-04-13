#pragma once

#include <map>
#include <vector>
#include <stdint.h>
#include <functional>

#include <PicoLed.hpp>

#include <graph.h>
#include <commands.h>
#include <spi_slave.h>
#include <i2c_master.h>
#include <command_handler.h>

#include <pico/stdlib.h>
#include <hardware/i2c.h>
#include <hardware/gpio.h>

namespace Lannooleaf {

  class Controller {

    public:
      Controller(i2c_inst_t * i2c_leaf_inst, uint sda_pin, uint scl_pin);
      ~Controller();

    public:
      /** \brief Starts device discorvery algorithm*/
      void device_discovery(void);

      /** \brief Starts topology discovery algorithm*/
      void topology_discovery(void);

      /** \brief Resets all slaves and reruns discovery/topology discovery algorithm*/
      void reset(void);

      /** \brief Adds handles to commandhandler */
      void add_controller_handlers(CommandHandler* handler);

    private:  
      /** \returns Next unused i2c address*/
      uint8_t get_next_available_address(void);

      /** \brief Assings new address to device if present
       * \returns Assigned address on succes, UNCONFIGUREDADDRESS on fail*/
      uint8_t assign_new_address(void);

    public:
      Graph graph;
      I2CMaster leaf_master;

    public:
      PicoLed::PicoLedController ledstrip = PicoLed::addLeds<PicoLed::WS2812B>(pio0, 0, LED_PIN, LED_LENGTH, PicoLed::FORMAT_GRB);
  
  };
  
}