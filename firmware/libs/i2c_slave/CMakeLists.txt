add_library(i2c_slave_lib INTERFACE)

target_include_directories(i2c_slave_lib INTERFACE
  ./include
)

target_sources(i2c_slave_lib INTERFACE
  i2c_slave_lib.c
)

target_link_libraries(i2c_slave_lib INTERFACE
  hardware_i2c
  hardware_irq
)
