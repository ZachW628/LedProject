#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <stdio.h>
#include <stdlib.h>

#define CHIP_NUM 8
#define I2C_DEVICE_1 "/dev/i2c-1"
#define I2C_DEVICE_2 "/dev/i2c-0"


enum chip_select {
    CHIP_A,
    CHIP_B,
    CHIP_C,
    CHIP_D,
    CHIP_E,
    CHIP_F,
    CHIP_G,
    CHIP_H
};


enum i2c_bus {
    BUS_1,
    BUS_2
};


enum pin_status {
    LOW,
    HIGH
};


struct i2c_base {
  int* file_descriptor_1;
  int* file_descriptor_2;

  void (*map)(int, int, int*, int);
};


void i2c_write(int fd, int addr, int reg, int value);
int i2c_read(int fd, int addr, int reg);
void init_mcp23017(int fd, int addr);
int* i2c_bus_init(int bus_num);
int pin_converter(int pin);
void set_chip_high(int fd, int chip_number, int* list);
void set_chip_low(int fd, int chip_number, int* list);
void map_pins(int fd1, int fd2, int* list, int pin_state);

struct i2c_base* i2c_base_init();
void i2c_base_destroy(struct i2c_base*);

int* chip_list[CHIP_NUM];

