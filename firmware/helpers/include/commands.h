#pragma once

namespace Lannooleaf {

  enum class slave_commands {

    set_i2c_address = 0x01,
    ping,
    
    set_sel_pin,
    get_sel_pin,
    
    is_neighbor,
    get_neigbor_size,
    get_neighbor_information,
    
    set_led,
    set_all_led,

    reset
  };

  enum class controller_commands {

    hello_message = 0x01,

    get_matrix_size,

    set_leaf_led,
    set_all,

    clear_leaf_led,
    clear_all,

    set_random,

  };

}