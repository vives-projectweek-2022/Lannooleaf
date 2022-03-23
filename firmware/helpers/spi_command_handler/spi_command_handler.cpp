#include <spi_command_handler.h>

namespace LannoLeaf {

  Spi_command_handler::Spi_command_handler(uint8_t mosi, uint8_t miso, uint8_t clk, uint8_t cs) {

    spi_init(spi0, 1000 * 1000);
    spi_set_slave(spi0, true);

    // PI4_MOSI -> PICO_RX, PI4_MISO -> PICO_TX, PI4_CLK -> PICO_CLK
    gpio_set_function(mosi, GPIO_FUNC_SPI);
    gpio_set_function(miso, GPIO_FUNC_SPI);
    gpio_set_function(clk, GPIO_FUNC_SPI);
    gpio_set_function(cs, GPIO_FUNC_SPI);

    spi_set_format(spi0,
    8,
    SPI_CPOL_1,
    SPI_CPHA_1,
    SPI_MSB_FIRST);
  }

  uint8_t Spi_command_handler::read_command(void) {
    if (spi_is_readable(spi0)) {
      printf("Readable\n");
      uint8_t cmd;
      spi_read_blocking(spi0, 0xff, &cmd, 1);
      printf("%02x\n", cmd);
      return cmd;
    } 
    return 0x00;
  }

  void Spi_command_handler::read_data(uint8_t *data_buffer, size_t len) {
    if (spi_is_readable(spi0)) {
      spi_read_blocking(spi0, 0xff, data_buffer, len);
    }
  }

  void Spi_command_handler::write_data(uint8_t *data_buffer, size_t len) {
    if (spi_is_writable(spi0)){
      spi_write_blocking(spi0, (uint8_t *) &len, 1);
      spi_write_blocking(spi0, data_buffer, len);
    }
  }

}