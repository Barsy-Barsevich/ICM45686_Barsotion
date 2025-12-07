#pragma once

typedef struct icm45686_fifo
{
    enum FIFO_DEPTH depth;
    enum FIFO_MODE mode;
    uint16_t watermark;
    enum FIFO_WR_WM_GT_TH wm_int_cond;
    int accel_en;
    int gyro_en;
    int hires_en;
    int es0_en;
    int es1_en;
    enum FIFO_ES0_6B_9B es0_bytes;
    int fsync_en;
    int compression_en;
    enum FIFO_COMP_NC_FLOW_CFG compression_alg;
} icm45686_fifo_t;

typedef struct icm45686_intflag
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
} icm45686_intflag_t;

typedef struct icm45686_interrupt
{
    enum INT_MODE mode;
    enum INT_POLARITY polarity;
    enum INT_DRIVE drive;
    struct icm45686_intflag flags;
} icm45686_interrupt_t;

typedef struct icm45686_desc
{
    int dummy;
} icm45686_desc_t;

typedef struct icm45686_cfg
{
    struct
    {
        enum ACCEL_MODE mode;
        enum ACCEL_UI_FS_SEL scale;
        enum ACCEL_ODR odr;
    } accel;
    struct
    {
        enum GYRO_MODE mode;
        enum GYRO_UI_FS_SEL scale;
        enum GYRO_ODR odr;
    } gyro;
    struct
    {
        
    } fifo;
    struct
    {
        int delta_en;
        enum TMST_RESOL resolution;
    } tmst;
    struct icm45686_interrupt int1;
    struct icm45686_interrupt int2;
} icm45686_cfg;