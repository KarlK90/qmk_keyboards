// Copyright 2023 Stefan Kerkmann (@karlk90)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "quantum.h"
#include "spi_master.h"

static pin_t row_pins[MATRIX_ROWS] = {GP28, GP27, GP26, GP22,
                                      GP21, GP20, GP19, GP18};

void matrix_init_custom(void) {
  // SPI Matrix
  setPinOutput(SPI_MATRIX_CHIP_SELECT_PIN);
  writePinHigh(SPI_MATRIX_CHIP_SELECT_PIN);

  spi_init();
  spi_start(SPI_MATRIX_CHIP_SELECT_PIN, false, 0, SPI_MATRIX_DIVISOR);
  setPinInput(SPI_MOSI_PIN);

  for (int row = 0; row < MATRIX_ROWS; row++) {
    setPinOutput(row_pins[row]);
    writePinLow(row_pins[row]);
  }
}

bool matrix_scan_custom(matrix_row_t current_matrix[MATRIX_ROWS]) {
  matrix_row_t input_matrix[MATRIX_ROWS] = {0};
  pin_t *pin = row_pins;

  for (int row = 0; row < MATRIX_ROWS; row++, pin++) {
    writePinHigh(*pin);
    spiSelect(&SPI_DRIVER);
    spiReceive(&SPI_DRIVER, sizeof(matrix_row_t), &input_matrix[row]);
    writePinLow(*pin);
    spiUnselect(&SPI_DRIVER);
  }

  matrix_row_t shifted_matrix[MATRIX_ROWS] = {0};
  memcpy(shifted_matrix, &input_matrix[1], sizeof(input_matrix)-1);
  shifted_matrix[7] = input_matrix[0];

  // Check if we've changed, return the last-read data
  bool changed = memcmp(current_matrix, shifted_matrix, sizeof(shifted_matrix)) != 0;
  if (changed) {
    memcpy(current_matrix, shifted_matrix, sizeof(shifted_matrix));
  }
  return changed;
}
