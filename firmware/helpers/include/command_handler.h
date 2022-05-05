/**
 * @file command_handler.h
 * @author Joey De Smet (Joey@de-smet.org)
 * @brief Class to hold a key value mapping of uint8_t and function pointer
 * @version 0.1
 * @date 2022-05-04
 * 
 * @copyright Copyright 2022 Joey De Smet
 * 
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 * 
 *         http://www.apache.org/licenses/LICENSE-2.0
 * 
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#pragma once

#include <map>
#include <iostream>
#include <stdint.h>
#include <functional>

namespace Lannooleaf {

  class CommandHandler {

    public:
      CommandHandler();
      ~CommandHandler();

    public:
      /** \brief Add a handler for a command (uint8_t) that can then be executed later by referencing the comman */
      void add_handler(uint8_t cmd, std::function<void(void)> handler);

      /** \brief Execute a handler for a command, if no handler is found will just return*/ 
      bool handel_command(uint8_t cmd);

    private:
      std::unordered_map<uint8_t, std::function<void(void)>> handler_map;

  };

}
