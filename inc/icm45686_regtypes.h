#pragma once

#include <stdint.h>
#include "icm45686_regconst.h"

typedef struct PWR_MGMT0
{
    enum ACCEL_MODE accel_mode:2;
    enum GYRO_MODE gyro_mode:2;
    uint8_t __dummy:4;
};

typedef struct INT1_CONFIG0
{
    uint8_t en_fifo_full:1;
    uint8_t en_fifo_ths:1;
    uint8_t en_drdy:1;
    uint8_t en_aux1_drdy:1;
    uint8_t en_ap_fsync:1;
    uint8_t en_ap_agc_rdy:1;
    uint8_t en_aux1_agc_rdy:1;
    uint8_t en_reset_done:1;
};

typedef struct INT1_CONFIG1
{
    uint8_t en_pll_rdy:1;
    uint8_t en_wom_x:1;
    uint8_t en_wom_y:1;
    uint8_t en_wom_z:1;
    uint8_t en_i3c_protocol_err:1;
    uint8_t en_i2cm_done:1;
    uint8_t en_apex_event:1;
    uint8_t __dummy:1;
};

typedef struct INT1_CONFIG2
{
    enum INT_POLARITY polarity:1;
    enum INT_MODE mode:1;
    enum INT_DRIVE drive:1;
};

typedef struct INT1_STATUS0
{
    uint8_t fifo_full:1;
    uint8_t fifo_ths:1;
    uint8_t drdy:1;
    uint8_t aux1_drdy:1;
    uint8_t ap_fsync:1;
    uint8_t ap_agc_rdy:1;
    uint8_t aux1_agc_rdy:1;
    uint8_t reset_done:1;
};

typedef struct INT1_STATUS1
{
    uint8_t pll_rdy:1;
    uint8_t wom_x:1;
    uint8_t wom_y:1;
    uint8_t wom_z:1;
    uint8_t i3c_protocol_err:1;
    uint8_t i2cm_done:1;
    uint8_t apex_event:1;
    uint8_t __dummy:1;
};

typedef struct ACCEL_CONFIG0
{
    enum ACCEL_ODR odr:4;
    enum ACCEL_UI_FS_SEL scale:3;
    uint8_t __dummy:1;
};

typedef struct GYRO_CONFIG0
{
    enum GYRO_ODR odr:4;
    enum GYRO_UI_FS_SEL scale:4;
};

typedef struct FIFO_CONFIG
{
    enum FIFO_DEPTH fifo_depth:6;
    enum FIFO_MODE mode:2;
};

