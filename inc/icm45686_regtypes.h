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
} PWR_MGMT0_t;

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
} INT1_CONFIG0_t;

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
} INT1_CONFIG1_t;

typedef struct INT1_CONFIG2
{
    enum INT_POLARITY polarity:1;
    enum INT_MODE mode:1;
    enum INT_DRIVE drive:1;
} INT1_CONFIG2_t;

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
} INT1_STATUS0_t;

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
} INT1_STATUS1_t;

typedef struct ACCEL_CONFIG0
{
    enum ACCEL_ODR odr:4;
    enum ACCEL_UI_FS_SEL scale:3;
    uint8_t __dummy:1;
} ACCEL_CONFIG0_t;

typedef struct GYRO_CONFIG0
{
    enum GYRO_ODR odr:4;
    enum GYRO_UI_FS_SEL scale:4;
} GYRO_CONFIG0_t;

typedef struct FIFO_CONFIG0
{
    enum FIFO_DEPTH fifo_depth:6;
    enum FIFO_MODE mode:2;
} FIFO_CONFIG0_t;

typedef struct FIFO_CONFIG2
{
    uint8_t __dummy1:3;
    enum FIFO_WR_WM_GT_TH fifo_wm_int_condition:1;
    uint8_t __dummy2:3;
    uint8_t fifo_flush:1;
} FIFO_CONFIG2_t;

typedef struct FIFO_CONFIG3
{
    uint8_t fifo_data_insertion_en:1;
    uint8_t fifo_accel_insertion_en:1;
    uint8_t fifo_gyro_insertion_en:1;
    uint8_t fifo_sensor_high_resolution_en:1;
    uint8_t fifo_es0_insertion_en:1;
    uint8_t fifo_es1_insertion_en:1;
    uint8_t __dummy:2;
} FIFO_CONFIG3_t;

typedef struct FIFO_CONFIG4
{
    enum FIFO_ES0_6B_9B ext_sensor0_bytes:1;
    uint8_t fifo_tmst_fsync_insertion_en:1;
    uint8_t fifo_compression_en:1;
    enum FIFO_COMP_NC_FLOW_CFG compression_algorithm:3;
    uint8_t __dummy:2;
} FIFO_CONFIG4_t;

typedef struct TMST_WOM_CONFIG
{
    enum WOM_INT_DUR wom_int_duration:2;
    uint8_t wom_interrupt_en:1;
    enum WOM_MODE wom_mode:1;
    uint8_t wom_en:1;
    enum TMST_RESOL tmst_resolution:1;
    uint8_t tmst_delta_en:1;
    uint8_t __dummy:1;
} TMST_WOM_CONFIG_t;

typedef struct FSYNC_CONFIG0
{
    enum AP_FSYNC_SEL fsync_tag_sensor:3;
    enum AP_FSYNC_FLAG_CLEAR_SEL fsync_clear_policy:1;
    uint8_t __dummy:4;
} FSYNC_CONFIG0_t;

typedef struct FSYNC_CONFIG1
{
    enum AUX1_FSYNC_SEL fsync_tag_sensor:3;
    enum AUX1_FSYNC_FLAG_CLEAR_SEL fsync_clear_policy:1;
    uint8_t __dummy:4;
} FSYNC_CONFIG1_t;

typedef struct RTC_CONFIG
{
    uint8_t __dummy1:5;
    uint8_t rtc_func_en:1;
    uint8_t rtc_realign:1;
    uint8_t __dummy2:1;
} RTC_CONFIG_t;

typedef struct DMP_EXT_SEN_ODR_CFG
{
    enum APEX_ODR apex_odr:3;
    enum I2CM_EXT_ODR i2cm_ext_odr:3;
    uint8_t ext_sensor_en:1;
    uint8_t __dummy:1;
} DMP_EXT_SEN_ODR_CFG_t;

typedef struct ODR_DECIMATE_CONFIG
{
    enum ACCEL_FIFO_ODR_DEC accel_decimate:4;
    enum GYRO_FIFO_ODR_DEC gyro_decimate:4;
} ODR_DECIMATE_CONFIG_t;

typedef struct EDMP_APEX_EN0
{
    uint8_t tap_en:1;
    uint8_t __dummy:2;
    uint8_t tilt_en:1;
    uint8_t pedometer_en:1;
    uint8_t freefall_en:1;
    uint8_t raise_to_wake_en:1;
    uint8_t smd_en:1;
} EDMP_APEX_EN0_t;

typedef struct EDMP_APEX_EN1
{
    uint8_t soft_hard_iron_correction_en:1;
    uint8_t init_en:1;
    uint8_t power_save_en:1;
    uint8_t __dummy1:2;
    uint8_t feature3_en:1;
    uint8_t edmp_en:1;
    uint8_t __dummy2:1;
} EDMP_APEX_EN1_t;

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
} APEX_BUFFER_MGMT_t;

typedef struct INTF_CONFIG0
{
    enum AP_SPI_MODE spi_mode:1;
    enum AP_SPI_34_MODE spi_wire_mode:1;
    uint8_t __dummy1:3;
    uint8_t virtual_access_aux1_en:1;
    uint8_t __dummy2:2;
} INTF_CONFIG0_t;

typedef struct INTF_CONFIG1_OVRD
{
    enum AP_SPI_MODE_OVRD_VAL spi_mode_override:1;
    uint8_t spi_mode_override_en:1;
    enum AP_SPI_34_MODE_OVRD_VAL spi_wire_mode_override:1;
    uint8_t spi_wire_mode_override_en:1;
    uint8_t __dummy:4;
} INTF_CONFIG1_OVRD_t;

typedef struct INTF_AUX_CONFIG
{
    enum AUX1_SPI_MODE spi_mode:1;
    enum AUX1_SPI_34_MODE spi_wire_mode:1;
    uint8_t __dummy:6;
} INTF_AUX_CONFIG_t;

typedef struct IOC_PAD_SCENARIO
{
    uint8_t aux1_en:1;
    enum AUX1_MODE aux1_mode:2;
    uint8_t __dummy:5;
} IOC_PAD_SCENARIO_t;

typedef struct IOC_PAD_SCENARIO_AUX_OVRD
{
    uint8_t aux1_en_override:1;
    uint8_t aux1_en_override_en:1;
    enum AUX1_MODE_OVRD_VAL aux1_mode_override:2;
    uint8_t aux1_mode_override_en:1;
    uint8_t __dummy:3;
} IOC_PAD_SCENARIO_AUX_OVRD_t;

typedef struct DRIVE_CONFIG0
{
    uint8_t __dummy1:1;
    enum PADS_SPI_SLEW spi_slew:3;
    enum PADS_I2C_SLEW i2c_slew:3;
    uint8_t __dummy2:1;
} DRIVE_CONFIG0_t;

typedef struct DRIVE_CONFIG1
{
    enum PADS_I3C_SDR_SLEW i3c_sdr_slew:3;
    enum PADS_I3C_DDR_SLEW i3c_ddr_slew:3;
    uint8_t __dummy:2;
} DRIVE_CONFIG1_t;

typedef struct DRIVE_CONFIG2
{
    enum PADS_SLEW int1_slew:3;
    uint8_t __dummy:5;
} DRIVE_CONFIG2_t;

typedef struct REG_MISC1
{
    enum OSC_ID_OVRD mclk_source:4;
    uint8_t __dummy:4;
} REG_MISC1_t;

typedef struct INT_APEX_CONFIG0
{
    uint8_t tap_detection_en:1;
    uint8_t high_g_detection_en:1;
    uint8_t low_g_detection_en:1;
    uint8_t tilt_detection_en:1;
    uint8_t step_count_overflow_en:1;
    uint8_t step_detection_en:1;
    uint8_t freefall_detection_en:1;
    uint8_t r2w_wake_en:1;
} INT_APEX_CONFIG0_t;

typedef struct INT_APEX_CONFIG1
{
    uint8_t r2w_sleep_detection_en:1;
    uint8_t smd_detection_en:1;
    uint8_t selftest_done_en:1;
    uint8_t __dummy1:1;
    uint8_t secure_authentication_done_en:1;
    uint8_t __dummy2:3;
} INT_APEX_CONFIG1_t;

typedef struct INT_APEX_STATUS0
{
    uint8_t tap_detection:1;
    uint8_t high_g_detection:1;
    uint8_t low_g_detection:1;
    uint8_t tilt_detection:1;
    uint8_t step_count_overflow:1;
    uint8_t step_detection:1;
    uint8_t freefall_detection:1;
    uint8_t r2w_wake_detection:1;
} INT_APEX_STATUS0_t;

typedef struct INT_APEX_STATUS1
{
    uint8_t r2w_sleep_detection:1;
    uint8_t smd_detection:1;
    uint8_t selftest_done:1;
    uint8_t __dummy1:1;
    uint8_t secure_authentication_done:1;
    uint8_t __dummy2:3;
} INT_APEX_STATUS1_t;

typedef struct PWR_MGMT_AUX1
{
    uint8_t aux1_accel_en:1;
    uint8_t aux1_gyro_en:1;
    uint8_t __dummy:6;
} PWR_MGMT_AUX1_t;

typedef struct FS_SEL_AUX1
{
    enum ACCEL_AUX1_FS_SEL accel_scale:3;
    enum GYRO_AUX1_FS_SEL gyro_scale:4;
    uint8_t __dummy:1;
} FS_SEL_AUX1_t;

typedef struct INT2_CONFIG0
{
    uint8_t en_fifo_full:1;
    uint8_t en_fifo_ths:1;
    uint8_t en_drdy:1;
    uint8_t en_aux1_drdy:1;
    uint8_t en_ap_fsync:1;
    uint8_t en_ap_agc_rdy:1;
    uint8_t en_aux1_agc_rdy:1;
    uint8_t en_reset_done:1;
} INT2_CONFIG0_t;

typedef struct INT2_CONFIG1
{
    uint8_t en_pll_rdy:1;
    uint8_t en_wom_x:1;
    uint8_t en_wom_y:1;
    uint8_t en_wom_z:1;
    uint8_t en_i3c_protocol_err:1;
    uint8_t en_i2cm_done:1;
    uint8_t en_apex_event:1;
    uint8_t __dummy:1;
} INT2_CONFIG1_t;

typedef struct INT2_CONFIG2
{
    enum INT_POLARITY polarity:1;
    enum INT_MODE mode:1;
    enum INT_DRIVE drive:1;
} INT2_CONFIG2_t;

typedef struct INT2_STATUS0
{
    uint8_t fifo_full:1;
    uint8_t fifo_ths:1;
    uint8_t drdy:1;
    uint8_t aux1_drdy:1;
    uint8_t ap_fsync:1;
    uint8_t ap_agc_rdy:1;
    uint8_t aux1_agc_rdy:1;
    uint8_t reset_done:1;
} INT2_STATUS0_t;

typedef struct INT2_STATUS1
{
    uint8_t pll_rdy:1;
    uint8_t wom_x:1;
    uint8_t wom_y:1;
    uint8_t wom_z:1;
    uint8_t i3c_protocol_err:1;
    uint8_t i2cm_done:1;
    uint8_t apex_event:1;
    uint8_t __dummy:1;
} INT2_STATUS1_t;

typedef struct REG_HOST_MSG
{
    uint8_t test_operation_en:1;
    uint8_t __dummy1:4;
    uint8_t edmp_on_demand_en:1;
    uint8_t __dummy2:2;
} REG_HOST_MSG_t;

typedef struct REG_MISC2
{
    uint8_t ireg_access_done:1;
    uint8_t soft_reset:1;
    uint8_t __dummy:6;
} REG_MISC2_t;

#if defined(__cplusplus)
}
#endif