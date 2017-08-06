#include "i2c_base.h"


int Addr[8] = {0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27};

void i2c_write(int fd, int addr, int reg, int value) {
  struct i2c_rdwr_ioctl_data msgset;
  struct i2c_msg iomsgs[1];
  char buf[2];
  int rc;

  buf[0] = (unsigned char) reg;
  buf[1] = (unsigned char) value;

  iomsgs[0].addr = (unsigned) addr;
  iomsgs[0].flags = 0;
  iomsgs[0].buf = buf;
  iomsgs[0].len = 2;

  msgset.msgs = iomsgs;
  msgset.nmsgs = 1;

  rc = ioctl(fd, I2C_RDWR, &msgset); 
}


int i2c_read(int fd, int addr, int reg) {
  struct i2c_rdwr_ioctl_data msgset;
  struct i2c_msg iomsgs[2];
  char buf[1], rbuf[1];
  int rc;

  buf[0] = (unsigned char) reg;
  iomsgs[0].addr = iomsgs[1].addr = (unsigned) addr;
  iomsgs[0].flags = 0;
  iomsgs[0].buf = buf;
  iomsgs[0].len = 1;

  iomsgs[1].flags = I2C_M_RD;
  iomsgs[1].buf = rbuf;
  iomsgs[1].len = 1;

  msgset.msgs = iomsgs;
  msgset.nmsgs = 2;

  ioctl(fd, I2C_RDWR, &msgset);
  return (int) rbuf[0];
}


int* i2c_bus_init(int bus_num) {
  int* new_fd = malloc(sizeof(int));
  char* file_path;

  if (bus_num == 0)
    file_path = I2C_DEVICE_1;
  else
    file_path = I2C_DEVICE_2;

  if ((*new_fd = open(file_path, O_RDWR)) < 0) {
    perror("Failed to open i2c bus\n");
    exit(1);
  }

  for(int i = 0; i < 8; i++) {
    init_mcp23017(*new_fd, Addr[i]);
  }

  return new_fd;
}

void init_mcp23017(int fd, int addr) {
  if (ioctl(fd, I2C_SLAVE, addr) < 0) {
    perror("Failed to acquire bus access and/or talk to slave");
    exit(1);
  } else {
    printf("successfully talked with device %d\n", addr);
  }
 
  i2c_write(fd, addr, 0x00, 0x00);
  i2c_write(fd, addr, 0x01, 0x00);
}


int pin_converter(int pin) {
  if (pin == 15)
    return 7;
  else if (pin == 14)
    return 6;
  else if (pin == 13)
    return 5;
  else if (pin == 12)
    return 4;
  else if (pin == 11)
    return 3;
  else if (pin == 10)
    return 2;
  else if (pin == 9)
    return 1;
  else if (pin == 8)
    return 0;
  else
    perror("Pin conversion error\n");
    exit(1);
}


void set_chip_high(int fd, int chip_number, int* list) {
  int length = *(list - 1);
  //printf("%d\n", length);
  
  int A_reg = i2c_read(fd, Addr[chip_number], 0x14);
  int B_reg = i2c_read(fd, Addr[chip_number], 0x15);

  for (int i = 0; i < length; i++) {
    if (list[i] < 8)
      A_reg = A_reg |= 1 << (list[i]);
    else
      B_reg = B_reg |= 1 << (pin_converter(list[i]));
    
  }

  i2c_write(fd, Addr[chip_number], 0x14, A_reg);
  i2c_write(fd, Addr[chip_number], 0x15, B_reg);

} 


void set_chip_low(int fd, int chip_number, int* list) {
  int length = *(list - 1);
  //printf("%d\n", length);
  
  int A_reg = i2c_read(fd, Addr[chip_number], 0x14);
  int B_reg = i2c_read(fd, Addr[chip_number], 0x15);

  for (int i = 0; i < length; i++) {
    if (list[i] < 8)
      A_reg = A_reg &= ~(1 << (list[i]));
    else
      B_reg = B_reg &= ~(1 << (pin_converter(list[i])));
    
  }

  i2c_write(fd, Addr[chip_number], 0x14, A_reg);
  i2c_write(fd, Addr[chip_number], 0x15, B_reg);

}


void map_pins(int fd1, int fd2, int* list, int pin_state) {
  void (*chip_set[2])(int, int, int*);
  chip_set[1] = set_chip_high;
  chip_set[0] = set_chip_low;

  for (int i = 0; i < CHIP_NUM; i++) {
    *(chip_list[i]) = 0;
  }

  for (int i = 0; i < list[0]; i++) {
    chip_list[list[i+1] / 16][(1 + *(chip_list[list[i+1] / 16]))] = list[i+1] % 16;
    *(chip_list[list[i+1] / 16]) += 1; 
  }

  for (int i = 0; i < CHIP_NUM; i++) {
    if (*(chip_list[i]) > 0)
      chip_set[pin_state](fd1, i, (chip_list[i] + 1));
  }

}


struct i2c_base* i2c_base_init() {
  struct i2c_base* i2c_item = malloc(sizeof(struct i2c_base));
  int* fd1 = i2c_bus_init(BUS_1);
  //(*i2c_item).file_descriptor_1 = malloc(sizeof(int));; 
  (*i2c_item).file_descriptor_1 = fd1;
  //i2c_item.file_descriptor_2 = i2c_bus_init(BUS_2);
  i2c_item->map = map_pins;
  for(int i = 0; i < CHIP_NUM; i++) {
    chip_list[i] = malloc(17 * sizeof(int));
  }

  return i2c_item;
}


void i2c_base_destroy(struct i2c_base* i2c_item) {
  close(*i2c_item->file_descriptor_1);
  //close(*i2c_item.file_descriptor_2);
  free(i2c_item->file_descriptor_1);
  //free(i2c_item.file_descriptor_2);

  for(int i = 0; i < CHIP_NUM; i++) { 
    free(chip_list[i]);
  }
  free(i2c_item);
}
