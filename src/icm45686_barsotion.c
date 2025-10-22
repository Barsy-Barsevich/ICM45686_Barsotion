#include "icm45686_barsotion.h"

#include "icm45686_regmap.h"
#include "icm45686_regtypes.h"
#include "icm45686_wheels.h"

#define _read_register      icm45686_read_register
#define _write_register     icm45686_write_register

int icm45686_set_accel_mode(struct icm45686_desc *desc, const enum ACCEL_MODE mode)
{
    PWR_MGMT0_t pwr_mgmt0;
    _ROE(_read_register(PWR_MGMT0, (uint8_t*)&pwr_mgmt0, 1));
    pwr_mgmt0.accel_mode = mode;
    _ROE(_write_register(PWR_MGMT0, (uint8_t*)&pwr_mgmt0, 1));
    return 0;
}

int icm45686_get_accel_mode(struct icm45686_desc *desc, enum ACCEL_MODE *mode)
{
    PWR_MGMT0_t pwr_mgmt0;
    _ROE(_read_register(PWR_MGMT0, (uint8_t*)&pwr_mgmt0, 1));
    *mode = pwr_mgmt0.accel_mode;
    return 0;
}

int icm45686_set_gyro_mode(struct icm45686_desc *desc, const enum GYRO_MODE mode)
{
    PWR_MGMT0_t pwr_mgmt0;
    _ROE(_read_register(PWR_MGMT0, (uint8_t*)&pwr_mgmt0, 1));
    pwr_mgmt0.gyro_mode = mode;
    _ROE(_write_register(PWR_MGMT0, (uint8_t*)&pwr_mgmt0, 1));
    return 0;
}

int icm45686_get_gyro_mode(struct icm45686_desc *desc, enum GYRO_MODE *mode)
{
    PWR_MGMT0_t pwr_mgmt0;
    _ROE(_read_register(PWR_MGMT0, (uint8_t*)&pwr_mgmt0, 1));
    *mode = pwr_mgmt0.gyro_mode;
    return 0;
}

int icm45686_set_int1_enable(struct icm45686_desc *desc, struct icm45686_interrupt *cfg)
{
    INT1_CONFIG0_t int1_config0 = {
        .en_fifo_full = cfg->fifo_full,
        .en_fifo_ths = cfg->fifo_ths,
        .en_drdy = cfg->drdy,
        .en_aux1_drdy = cfg->aux1_drdy,
        .en_ap_fsync = cfg->ap_fsync,
        .en_ap_agc_rdy = cfg->ap_agc_rdy,
        .en_aux1_agc_rdy = cfg->aux1_agc_rdy,
        .en_reset_done = cfg->reset_done,
    };
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    INT1_CONFIG1_t int1_config1 = {
        .en_pll_rdy = cfg->pll_rdy,
        .en_wom_x = cfg->wom_x,
        .en_wom_y = cfg->wom_y,
        .en_wom_z = cfg->wom_z,
        .en_i3c_protocol_err = cfg->i3c_protocol_err,
        .en_i2cm_done = cfg->i2cm_done,
        .en_apex_event = cfg->apex_event,
        .__dummy = 0,
    };
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_get_int1_enable(struct icm45686_desc *desc, struct icm45686_interrupt *cfg)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    cfg->fifo_full = int1_config0.en_fifo_full;
    cfg->fifo_ths = int1_config0.en_fifo_ths;
    cfg->drdy = int1_config0.en_drdy;
    cfg->aux1_drdy = int1_config0.en_aux1_drdy;
    cfg->ap_fsync = int1_config0.en_ap_fsync;
    cfg->ap_agc_rdy = int1_config0.en_ap_agc_rdy;
    cfg->aux1_agc_rdy = int1_config0.en_aux1_agc_rdy;
    cfg->reset_done = int1_config0.en_reset_done;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    cfg->pll_rdy = int1_config1.en_pll_rdy;
    cfg->wom_x = int1_config1.en_wom_x;
    cfg->wom_y = int1_config1.en_wom_y;
    cfg->wom_z = int1_config1.en_wom_z;
    cfg->i3c_protocol_err = int1_config1.en_i3c_protocol_err;
    cfg->i2cm_done = int1_config1.en_i2cm_done;
    cfg->apex_event = int1_config1.en_apex_event;
    return 0;
}

int icm45686_set_int1_fifo_full_enable(struct icm45686_desc *desc)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_fifo_full = 1;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_set_int1_fifo_full_disable(struct icm45686_desc *desc)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_fifo_full = 0;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_get_int1_fifo_full_enable_status(struct icm45686_desc *desc, bool *status)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    *status = int1_config0.en_fifo_full;
    return 0;
}

int icm45686_set_int1_fifo_ths_enable(struct icm45686_desc *desc)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_fifo_ths = 1;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_set_int1_fifo_ths_disable(struct icm45686_desc *desc)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_fifo_ths = 0;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_get_int1_fifo_ths_enable_status(struct icm45686_desc *desc, bool *status)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    *status = int1_config0.en_fifo_ths;
    return 0;
}

int icm45686_set_int1_ap_drdy_enable(struct icm45686_desc *desc)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_drdy = 1;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_set_int1_ap_drdy_disable(struct icm45686_desc *desc)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_drdy = 0;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_get_int1_ap_drdy_enable_status(struct icm45686_desc *desc, bool *status)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    *status = int1_config0.en_drdy;
    return 0;
}

int icm45686_set_int1_aux1_drdy_enable(struct icm45686_desc *desc)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_aux1_drdy = 1;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_set_int1_aux1_drdy_disable(struct icm45686_desc *desc)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_aux1_drdy = 0;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_get_int1_aux1_drdy_enable_status(struct icm45686_desc *desc, bool *status)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    *status = int1_config0.en_aux1_drdy;
    return 0;
}

int icm45686_set_int1_ap_fsync_enable(struct icm45686_desc *desc)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_ap_fsync = 1;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_set_int1_ap_fsync_enable(struct icm45686_desc *desc)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_ap_fsync = 0;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_get_int1_ap_fsync_enable_status(struct icm45686_desc *desc, bool *status)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    *status = int1_config0.en_ap_fsync;
    return 0;
}

int icm45686_set_int1_ap_agc_rdy_enable(struct icm45686_desc *desc)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_ap_agc_rdy = 1;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_set_int1_ap_agc_rdy_disable(struct icm45686_desc *desc)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_ap_agc_rdy = 0;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_get_int1_ap_agc_rdy_enable_status(struct icm45686_desc *desc, bool *status)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    *status = int1_config0.en_ap_agc_rdy;
    return 0;
}

int icm45686_set_int1_aux1_agc_rdy_enable(struct icm45686_desc *desc)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_aux1_agc_rdy = 1;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_set_int1_aux1_agc_rdy_disable(struct icm45686_desc *desc)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_aux1_agc_rdy = 0;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_get_int1_aux1_agc_rdy_enable_status(struct icm45686_desc *desc, bool *status)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    *status = int1_config0.en_aux1_agc_rdy;
    return 0;
}

int icm45686_set_int1_reset_done_enable(struct icm45686_desc *desc)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_reset_done = 1;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_set_int1_reset_done_disable(struct icm45686_desc *desc)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_reset_done = 0;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_get_int1_reset_done_enable_status(struct icm45686_desc *desc, bool *status)
{
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    *status = int1_config0.en_reset_done;
    return 0;
}

int icm45686_set_int1_pll_rdy_enable(struct icm45686_desc *desc)
{
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_pll_rdy = 1;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_set_int1_pll_rdy_disable(struct icm45686_desc *desc)
{
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_pll_rdy = 0;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_get_int1_pll_rdy_enable_status(struct icm45686_desc *desc, bool *status)
{
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    *status = int1_config1.en_pll_rdy;
    return 0;
}

int icm45686_set_int1_wom_x_enable(struct icm45686_desc *desc)
{
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_wom_x = 1;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_set_int1_wom_x_disable(struct icm45686_desc *desc)
{
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_wom_x = 0;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_get_int1_wom_x_enable_status(struct icm45686_desc *desc, bool *status)
{
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    *status = int1_config1.en_wom_x;
    return 0;
}

int icm45686_set_int1_wom_y_enable(struct icm45686_desc *desc)
{
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_wom_y = 1;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_set_int1_wom_y_disable(struct icm45686_desc *desc)
{
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_wom_y = 0;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_get_int1_wom_y_enable_status(struct icm45686_desc *desc, bool *status)
{
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    *status = int1_config1.en_wom_y;
    return 0;
}

int icm45686_set_int1_wom_z_enable(struct icm45686_desc *desc)
{
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_wom_z = 1;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_set_int1_wom_z_disable(struct icm45686_desc *desc)
{
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_wom_z = 0;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_get_int1_wom_z_enable_status(struct icm45686_desc *desc, bool *status)
{
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    *status = int1_config1.en_wom_z;
    return 0;
}

int icm45686_set_int1_i3c_protocol_err_enable(struct icm45686_desc *desc)
{
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_i3c_protocol_err = 1;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_set_int1_i3c_protocol_err_disable(struct icm45686_desc *desc)
{
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_i3c_protocol_err = 0;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_get_int1_i3c_protocol_err_enable_status(struct icm45686_desc *desc, bool *status)
{
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    *status = int1_config1.en_i3c_protocol_err;
    return 0;
}

int icm45686_set_int1_i2cm_done_enable(struct icm45686_desc *desc)
{
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_i2cm_done = 1;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_set_int1_i2cm_done_disable(struct icm45686_desc *desc)
{
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_i2cm_done = 0;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_get_int1_i2cm_done_enable_status(struct icm45686_desc *desc, bool *status)
{
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    *status = int1_config1.en_i2cm_done;
    return 0;
}

int icm45686_set_int1_apex_event_enable(struct icm45686_desc *desc)
{
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_apex_event = 1;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_set_int1_apex_event_disable(struct icm45686_desc *desc)
{
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_apex_event = 0;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_get_int1_apex_event_enable_status(struct icm45686_desc *desc, bool *status)
{
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    *status = int1_config1.en_apex_event;
    return 0;
}

int icm45686_set_int1_polarity(struct icm45686_desc *desc, const enum INT_POLARITY pol)
{
    INT1_CONFIG2_t int1_config2;
    _ROE(_read_register(INT1_CONFIG2, (uint8_t*)&int1_config2, 1));
    int1_config2.polarity = pol;
    _ROE(_write_register(INT1_CONFIG2, (uint8_t*)&int1_config2, 1));
    return 0;
}

int icm45686_get_int1_polarity(struct icm45686_desc *desc, enum INT_POLARITY *pol)
{
    INT1_CONFIG2_t int1_config2;
    _ROE(_read_register(INT1_CONFIG2, (uint8_t*)&int1_config2, 1));
    *pol = int1_config2.polarity;
    return 0;
}

int icm45686_set_int1_mode(struct icm45686_desc *desc, const enum INT_MODE mode)
{
    INT1_CONFIG2_t int1_config2;
    _ROE(_read_register(INT1_CONFIG2, (uint8_t*)&int1_config2, 1));
    int1_config2.mode = mode;
    _ROE(_write_register(INT1_CONFIG2, (uint8_t*)&int1_config2, 1));
    return 0;
}

int icm45686_get_int1_mode(struct icm45686_desc *desc, enum INT_MODE *mode)
{
    INT1_CONFIG2_t int1_config2;
    _ROE(_read_register(INT1_CONFIG2, (uint8_t*)&int1_config2, 1));
    *mode = int1_config2.mode;
    return 0;
}

int icm45686_set_int1_drive(struct icm45686_desc *desc, const enum INT_DRIVE drive)
{
    INT1_CONFIG2_t int1_config2;
    _ROE(_read_register(INT1_CONFIG2, (uint8_t*)&int1_config2, 1));
    int1_config2.drive = drive;
    _ROE(_write_register(INT1_CONFIG2, (uint8_t*)&int1_config2, 1));
    return 0;
}

int icm45686_get_int1_drive(struct icm45686_desc *desc, enum INT_DRIVE *drive)
{
    INT1_CONFIG2_t int1_config2;
    _ROE(_read_register(INT1_CONFIG2, (uint8_t*)&int1_config2, 1));
    *drive = int1_config2.drive;
    return 0;
}

int icm45686_get_int1_status(struct icm45686_desc *desc, struct icm45686_interrupt *status)
{
    INT1_STATUS0_t int1_status0;
    _ROE(_read_register(INT1_STATUS0, (uint8_t*)&int1_status0, 1));
    status->fifo_full = int1_status0.fifo_full;
    status->fifo_ths = int1_status0.fifo_ths;
    status->drdy = int1_status0.drdy;
    status->aux1_drdy = int1_status0.aux1_drdy;
    status->ap_fsync = int1_status0.ap_fsync;
    status->ap_agc_rdy = int1_status0.ap_agc_rdy;
    status->aux1_agc_rdy = int1_status0.aux1_agc_rdy;
    status->reset_done = int1_status0.reset_done;
    INT1_STATUS1_t int1_status1;
    _ROE(_read_register(INT1_STATUS1, (uint8_t*)&int1_status1, 1));
    status->pll_rdy = int1_status1.pll_rdy;
    status->wom_x = int1_status1.wom_x;
    status->wom_y = int1_status1.wom_y;
    status->wom_z = int1_status1.wom_z;
    status->i3c_protocol_err = int1_status1.i3c_protocol_err;
    status->i2cm_done = int1_status1.i2cm_done;
    status->apex_event = int1_status1.apex_event;
    return 0;
}

int icm45686_get_int1_fifo_full_status(struct icm45686_desc *desc, bool *status)
{
    INT1_STATUS0_t int1_status0;
    _ROE(_read_register(INT1_STATUS0, (uint8_t*)&int1_status0, 1));
    *status = int1_status0.fifo_full;
    return 0;
}

int icm45686_get_int1_fifo_ths_status(struct icm45686_desc *desc, bool *status)
{
    INT1_STATUS0_t int1_status0;
    _ROE(_read_register(INT1_STATUS0, (uint8_t*)&int1_status0, 1));
    *status = int1_status0.fifo_ths;
    return 0;
}

int icm45686_get_int1_ap_drdy_status(struct icm45686_desc *desc, bool *status)
{
    INT1_STATUS0_t int1_status0;
    _ROE(_read_register(INT1_STATUS0, (uint8_t*)&int1_status0, 1));
    *status = int1_status0.drdy;
    return 0;
}

int icm45686_get_int1_aux1_drdy_status(struct icm45686_desc *desc, bool *status)
{
    INT1_STATUS0_t int1_status0;
    _ROE(_read_register(INT1_STATUS0, (uint8_t*)&int1_status0, 1));
    *status = int1_status0.aux1_drdy;
    return 0;
}

int icm45686_get_int1_ap_fsync_status(struct icm45686_desc *desc, bool *status)
{
    INT1_STATUS0_t int1_status0;
    _ROE(_read_register(INT1_STATUS0, (uint8_t*)&int1_status0, 1));
    *status = int1_status0.ap_fsync;
    return 0;
}

int icm45686_get_int1_ap_agc_rdy_status(struct icm45686_desc *desc, bool *status)
{
    INT1_STATUS0_t int1_status0;
    _ROE(_read_register(INT1_STATUS0, (uint8_t*)&int1_status0, 1));
    *status = int1_status0.ap_agc_rdy;
    return 0;
}

int icm45686_get_int1_aux1_agc_rdy_status(struct icm45686_desc *desc, bool *status)
{
    INT1_STATUS0_t int1_status0;
    _ROE(_read_register(INT1_STATUS0, (uint8_t*)&int1_status0, 1));
    *status = int1_status0.aux1_agc_rdy;
    return 0;
}

int icm45686_get_int1_reset_done_status(struct icm45686_desc *desc, bool *status)
{
    INT1_STATUS0_t int1_status0;
    _ROE(_read_register(INT1_STATUS0, (uint8_t*)&int1_status0, 1));
    *status = int1_status0.reset_done;
    return 0;
}

int icm45686_get_int1_pll_rdy_status(struct icm45686_desc *desc, bool *status)
{
    INT1_STATUS1_t int1_status1;
    _ROE(_read_register(INT1_STATUS1, (uint8_t*)&int1_status1, 1));
    *status = int1_status1.pll_rdy;
    return 0;
}

int icm45686_get_int1_wom_x_status(struct icm45686_desc *desc, bool *status)
{
    INT1_STATUS1_t int1_status1;
    _ROE(_read_register(INT1_STATUS1, (uint8_t*)&int1_status1, 1));
    *status = int1_status1.wom_x;
    return 0;
}

int icm45686_get_int1_wom_y_status(struct icm45686_desc *desc, bool *status)
{
    INT1_STATUS1_t int1_status1;
    _ROE(_read_register(INT1_STATUS1, (uint8_t*)&int1_status1, 1));
    *status = int1_status1.wom_y;
    return 0;
}

int icm45686_get_int1_wom_z_status(struct icm45686_desc *desc, bool *status)
{
    INT1_STATUS1_t int1_status1;
    _ROE(_read_register(INT1_STATUS1, (uint8_t*)&int1_status1, 1));
    *status = int1_status1.wom_z;
    return 0;
}

int icm45686_get_int1_i3c_protocol_err_status(struct icm45686_desc *desc, bool *status)
{
    INT1_STATUS1_t int1_status1;
    _ROE(_read_register(INT1_STATUS1, (uint8_t*)&int1_status1, 1));
    *status = int1_status1.i3c_protocol_err;
    return 0;
}

int icm45686_get_int1_i2cm_done_status(struct icm45686_desc *desc, bool *status)
{
    INT1_STATUS1_t int1_status1;
    _ROE(_read_register(INT1_STATUS1, (uint8_t*)&int1_status1, 1));
    *status = int1_status1.i2cm_done;
    return 0;
}

int icm45686_get_int1_apex_event_status(struct icm45686_desc *desc, bool *status)
{
    INT1_STATUS1_t int1_status1;
    _ROE(_read_register(INT1_STATUS1, (uint8_t*)&int1_status1, 1));
    *status = int1_status1.apex_event;
    return 0;
}

int icm45686_set_ap_accel_scale(struct icm45686_desc *desc, const enum ACCEL_UI_FS_SEL scale)
{
    ACCEL_CONFIG0_t accel_config0;
    _ROE(_read_register(ACCEL_CONFIG0, (uint8_t*)&accel_config0, 1));
    accel_config0.scale = scale;
    _ROE(_write_register(ACCEL_CONFIG0, (uint8_t*)&accel_config0, 1));
    return 0;
}

int icm45686_get_ap_accel_scale(struct icm45686_desc *desc, enum ACCEL_UI_FS_SEL *scale)
{
    ACCEL_CONFIG0_t accel_config0;
    _ROE(_read_register(ACCEL_CONFIG0, (uint8_t*)&accel_config0, 1));
    *scale = accel_config0.scale;
    return 0;
}

int icm45686_set_ap_accel_odr(struct icm45686_desc *desc, const enum ACCEL_ODR odr)
{
    ACCEL_CONFIG0_t accel_config0;
    _ROE(_read_register(ACCEL_CONFIG0, (uint8_t*)&accel_config0, 1));
    accel_config0.odr = odr;
    _ROE(_write_register(ACCEL_CONFIG0, (uint8_t*)&accel_config0, 1));
    return 0;
}

int icm45686_get_ap_accel_odr(struct icm45686_desc *desc, enum ACCEL_ODR *odr)
{
    ACCEL_CONFIG0_t accel_config0;
    _ROE(_read_register(ACCEL_CONFIG0, (uint8_t*)&accel_config0, 1));
    *odr = accel_config0.odr;
    return 0;
}

int icm45686_set_ap_gyro_scale(struct icm45686_desc *desc, const enum GYRO_UI_FS_SEL scale)
{
    GYRO_CONFIG0_t gyro_config0;
    _ROE(_read_register(GYRO_CONFIG0, (uint8_t*)&gyro_config0, 1));
    gyro_config0.scale = scale;
    _ROE(_write_register(GYRO_CONFIG0, (uint8_t*)&gyro_config0, 1));
    return 0;
}

int icm45686_get_ap_gyro_scale(struct icm45686_desc *desc, enum GYRO_UI_FS_SEL *scale)
{
    GYRO_CONFIG0_t gyro_config0;
    _ROE(_read_register(GYRO_CONFIG0, (uint8_t*)&gyro_config0, 1));
    *scale = gyro_config0.scale;
    return 0;
}

int icm45686_set_ap_gyro_odr(struct icm45686_desc *desc, const enum GYRO_ODR odr)
{
    GYRO_CONFIG0_t gyro_config0;
    _ROE(_read_register(GYRO_CONFIG0, (uint8_t*)&gyro_config0, 1));
    gyro_config0.odr = odr;
    _ROE(_write_register(GYRO_CONFIG0, (uint8_t*)&gyro_config0, 1));
    return 0;
}

int icm45686_get_ap_gyro_odr(struct icm45686_desc *desc, enum GYRO_ODR *odr)
{
    GYRO_CONFIG0_t gyro_config0;
    _ROE(_read_register(GYRO_CONFIG0, (uint8_t*)&gyro_config0, 1));
    *odr = gyro_config0.odr;
    return 0;
}

int icm45686_set_fifo_depth(struct icm45686_desc *desc, const enum FIFO_DEPTH depth)
{
    FIFO_CONFIG0_t fifo_config0;
    _ROE(_read_register(FIFO_CONFIG0, (uint8_t*)&fifo_config0, 1));
    fifo_config0.fifo_depth = depth;
    _ROE(_write_register(FIFO_CONFIG0, (uint8_t*)&fifo_config0, 1));
    return 0;
}

int icm45686_get_fifo_depth(struct icm45686_desc *desc, enum FIFO_DEPTH *depth)
{
    FIFO_CONFIG0_t fifo_config0;
    _ROE(_read_register(FIFO_CONFIG0, (uint8_t*)&fifo_config0, 1));
    *depth = fifo_config0.fifo_depth;
    return 0;
}

int icm45686_set_fifo_mode(struct icm45686_desc *desc, const enum FIFO_MODE mode)
{
    FIFO_CONFIG0_t fifo_config0;
    _ROE(_read_register(FIFO_CONFIG0, (uint8_t*)&fifo_config0, 1));
    fifo_config0.mode = mode;
    _ROE(_write_register(FIFO_CONFIG0, (uint8_t*)&fifo_config0, 1));
    return 0;
}

int icm45686_get_fifo_mode(struct icm45686_desc *desc, enum FIFO_MODE *mode)
{
    FIFO_CONFIG0_t fifo_config0;
    _ROE(_read_register(FIFO_CONFIG0, (uint8_t*)&fifo_config0, 1));
    *mode = fifo_config0.mode;
    return 0;
}