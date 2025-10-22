#pragma once

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdint.h>

#define _ROE(res)    do {\
    if (res != 0)\
    {\
        return 1;\
    }\
} while(0);

int icm45686_read_register(uint8_t address, uint8_t *value, int len);
int icm45686_write_register(uint8_t address, const uint8_t *value, int len);

#if defined(__cplusplus)
}
#endif