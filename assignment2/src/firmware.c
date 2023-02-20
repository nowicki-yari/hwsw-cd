#include "print.h"

extern unsigned int hwswcd_avg(unsigned int value1, unsigned int value2);

void main(void) {
    volatile unsigned int value1, value2, value3, value4, hd, hd2;

    value1 = 32;
    value2 = 16;
    value3 = 3;
    value4 = 4;

    hd = hwswcd_avg(value1, value2);
    hd2 = hwswcd_avg(value3, value4);

    print_str("HD(0x");
    print_hex(value1, 2);
    print_str(", ");
    print_hex(value2, 2);
    print_str(") = 0x");
    print_hex(hd, 2);
    print_str(".\n");

    print_str("HD(0x");
    print_hex(value3, 2);
    print_str(", ");
    print_hex(value4, 2);
    print_str(") = 0x");
    print_hex(hd2, 2);
    print_str(".\n");
}