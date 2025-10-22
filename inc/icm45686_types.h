#pragma once

typedef struct icm45686_interrupt
{
    uint16_t fifo_full:1;
    uint16_t fifo_ths:1;
    uint16_t drdy:1;
    uint16_t aux1_drdy:1;
    uint16_t ap_fsync:1;
    uint16_t ap_agc_rdy:1;
    uint16_t aux1_agc_rdy:1;
    uint16_t reset_done:1;
    uint16_t pll_rdy:1;
    uint16_t wom_x:1;
    uint16_t wom_y:1;
    uint16_t wom_z:1;
    uint16_t i3c_protocol_err:1;
    uint16_t i2cm_done:1;
    uint16_t apex_event:1;
    uint16_t __dummy:1;
};

typedef struct icm45686_desc
{
    int dummy;
};