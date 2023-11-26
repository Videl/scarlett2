// SPDX-FileCopyrightText: 2023 Geoffrey D. Bennett <g@b4.vu>
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef SCARLETT2_FIRMWARE_H
#define SCARLETT2_FIRMWARE_H

#include <stdint.h>

#define MAGIC_STRING "SCARLETT"

struct scarlett2_firmware_header {
  char magic[8];             // "SCARLETT"
  uint16_t usb_vid;          // Big-endian
  uint16_t usb_pid;          // Big-endian
  uint32_t firmware_version; // Big-endian
  uint32_t firmware_length;  // Big-endian
  uint8_t sha256[32];
} __attribute__((packed));

struct scarlett2_firmware_file {
  struct scarlett2_firmware_header header;
  uint8_t *firmware_data;
};

struct scarlett2_firmware_header *scarlett2_read_firmware_header(
  const char *fn
);

void scarlett2_free_firmware_header(
  struct scarlett2_firmware_header *firmware
);

struct scarlett2_firmware_file *scarlett2_read_firmware_file(
  const char *fn
);

void scarlett2_free_firmware_file(
  struct scarlett2_firmware_file *firmware
);

#endif // SCARLETT2_FIRMWARE_H
