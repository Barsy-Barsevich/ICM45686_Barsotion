#pragma once

#if defined(__cplusplus)
extern "C" {
#endif

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

typedef struct FIFO_CONFIG2
{
    uint8_t __dummy1:3;
    enum FIFO_WR_WM_GT_TH fifo_wm_int_condition:1;
    uint8_t __dummy2:3;
    uint8_t fifo_flush:1;
};

typedef struct FIFO_CONFIG3
{
    uint8_t fifo_data_insertion_en:1;
    uint8_t fifo_accel_insertion_en:1;
    uint8_t fifo_gyro_insertion_en:1;
    uint8_t fifo_sensor_high_resolution_en:1;
    uint8_t fifo_es0_insertion_en:1;
    uint8_t fifo_es1_insertion_en:1;
    uint8_t __dummy:2;
};

typedef struct FIFO_CONFIG4
{
    enum FIFO_ES0_6B_9B ext_sensor0_bytes:1;
    uint8_t fifo_tmst_fsync_insertion_en:1;
    uint8_t fifo_compression_en:1;
    enum FIFO_COMP_NC_FLOW_CFG compression_algorithm:3;
    uint8_t __dummy:2;
};

typedef struct TMST_WOM_CONFIG
{
    enum WOM_INT_DUR wom_int_duration:2;
    uint8_t wom_interrupt_en:1;
    enum WOM_MODE wom_mode:1;
    enum TMST_RESOL tmst_resolution:1;
    uint8_t tmst_delta_en:1;
    uint8_t __dummy:1;
};

typedef struct FSYNC_CONFIG0
{
    enum AP_FSYNC_SEL fsync_tag_sensor:3;
    enum AP_FSYNC_FLAG_CLEAR_SEL fsync_clear_policy:1;
    uint8_t __dummy:4;
};

typedef struct FSYNC_CONFIG1
{
    enum AUX1_FSYNC_SEL fsync_tag_sensor:3;
    enum AUX1_FSYNC_FLAG_CLEAR_SEL fsync_clear_policy:1;
    uint8_t __dummy:4;
};

typedef struct RTC_CONFIG
{
    uint8_t __dummy1:5;
    uint8_t rtc_func_en:1;
    uint8_t rtc_realign:1;
    uint8_t __dummy2:1;
};

typedef struct DMP_EXT_SEN_ODR_CFG
{
    enum APEX_ODR apex_odr:3;
    enum I2CM_EXT_ODR i2cm_ext_odr:3;
    uint8_t ext_sensor_en:1;
    uint8_t __dummy:1;
};

typedef struct ODR_DECIMATE_CONFIG
{
    enum ACCEL_FIFO_ODR_DEC accel_decimate:4;
    enum GYRO_FIFO_ODR_DEC gyro_decimate:4;
};

typedef struct EDMP_APEX_EN0
{
    uint8_t tap_en:1;
    uint8_t __dummy:2;
    uint8_t tilt_en:1;
    uint8_t pedometer_en:1;
    uint8_t freefall_en:1;
    uint8_t raise_to_wake_en:1;
    uint8_t smd_en:1;
};

typedef struct EDMP_APEX_EN1
{
    uint8_t soft_hard_iron_correction_en:1;
    uint8_t init_en:1;
    uint8_t power_save_en:1;
    uint8_t __dummy1:2;
    uint8_t feature3_en:1;
    uint8_t edmp_en:1;
    uint8_t __dummy2:1;
};

typedef struct APEX_BUFFER_MGMT
{
    uint8_t step_count_edmp_addr:1;
    uint8_t step_count_edmp_size:1;
    uint8_t step_count_host_addr:1;
    uint8_t step_count_host_size:1;
    uint8_t freefall_edmp_addr:1;
    uint8_t freefall_edmp_size:1;
    uint8_t freefall_host_addr:1;
    uint8_t freefall_host_size:1;
};

typedef struct INTF_CONFIG0
{
    enum AP_SPI_MODE spi_mode:1;
    enum AP_SPI_34_MODE spi_wire_mode:1;
    uint8_t __dummy1:3;
    uint8_t virtual_access_aux1_en:1;
    uint8_t __dummy2:2;
};

typedef struct INTF_CONFIG1_OVRD
{
    enum AP_SPI_MODE_OVRD_VAL spi_mode_override:1;
    uint8_t spi_mode_override_en:1;
    enum AP_SPI_34_MODE_OVRD_VAL spi_wire_mode_override:1;
    uint8_t spi_wire_mode_override_en:1;
    uint8_t __dummy:4;
};

typedef struct INTF_AUX_CONFIG
{
    enum AUX1_SPI_MODE spi_mode:1;
    enum AUX1_SPI_34_MODE spi_wire_mode:1;
    uint8_t __dummy:6;
};

typedef struct IOC_PAD_SCENARIO
{
    uint8_t aux1_en:1;
    enum AUX1_MODE aux1_mode:2;
    uint8_t __dummy:5;
};

typedef struct IOC_PAD_SCENARIO_AUX_OVRD
{
    uint8_t aux1_en_override:1;
    uint8_t aux1_en_override_en:1;
    enum AUX1_MODE_OVRD_VAL aux1_mode_override:2;
    uint8_t aux1_mode_override_en:1;
    uint8_t __dummy:3;
};

typedef struct DRIVE_CONFIG0
{
    uint8_t __dummy1:1;
    enum PADS_SPI_SLEW spi_slew:3;
    enum PADS_I2C_SLEW i2c_slew:3;
    uint8_t __dummy2:1;
};


#if defined(__cplusplus)
}
#endif