#include "icm45686_barsotion.h"

#include "icm45686_regmap.h"
#include "icm45686_regtypes.h"
#include "icm45686_wheels.h"

#define _read_register      icm45686_read_register
#define _write_register     icm45686_write_register

int icm45686_set_accel_mode(struct icm45686_desc *desc, const enum ACCEL_MODE mode)
{
    if (desc == NULL) return 1;
    PWR_MGMT0_t pwr_mgmt0;
    _ROE(_read_register(PWR_MGMT0, (uint8_t*)&pwr_mgmt0, 1));
    pwr_mgmt0.accel_mode = mode;
    _ROE(_write_register(PWR_MGMT0, (uint8_t*)&pwr_mgmt0, 1));
    return 0;
}

int icm45686_get_accel_mode(struct icm45686_desc *desc, enum ACCEL_MODE *mode)
{
    if (desc == NULL || mode == NULL) return 1;
    PWR_MGMT0_t pwr_mgmt0;
    _ROE(_read_register(PWR_MGMT0, (uint8_t*)&pwr_mgmt0, 1));
    *mode = pwr_mgmt0.accel_mode;
    return 0;
}

int icm45686_set_gyro_mode(struct icm45686_desc *desc, const enum GYRO_MODE mode)
{
    if (desc == NULL) return 1;
    PWR_MGMT0_t pwr_mgmt0;
    _ROE(_read_register(PWR_MGMT0, (uint8_t*)&pwr_mgmt0, 1));
    pwr_mgmt0.gyro_mode = mode;
    _ROE(_write_register(PWR_MGMT0, (uint8_t*)&pwr_mgmt0, 1));
    return 0;
}

int icm45686_get_gyro_mode(struct icm45686_desc *desc, enum GYRO_MODE *mode)
{
    if (desc == NULL || mode == NULL) return 1;
    PWR_MGMT0_t pwr_mgmt0;
    _ROE(_read_register(PWR_MGMT0, (uint8_t*)&pwr_mgmt0, 1));
    *mode = pwr_mgmt0.gyro_mode;
    return 0;
}

int icm45686_set_int1_enable(struct icm45686_desc *desc, struct icm45686_interrupt *cfg)
{
    if (desc == NULL || cfg == NULL) return 1;
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
    if (desc == NULL || cfg == NULL) return 1;
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
    if (desc == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_fifo_full = 1;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_set_int1_fifo_full_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_fifo_full = 0;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_get_int1_fifo_full_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    *status = int1_config0.en_fifo_full;
    return 0;
}

int icm45686_set_int1_fifo_ths_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_fifo_ths = 1;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_set_int1_fifo_ths_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_fifo_ths = 0;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_get_int1_fifo_ths_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    *status = int1_config0.en_fifo_ths;
    return 0;
}

int icm45686_set_int1_ap_drdy_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_drdy = 1;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_set_int1_ap_drdy_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_drdy = 0;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_get_int1_ap_drdy_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    *status = int1_config0.en_drdy;
    return 0;
}

int icm45686_set_int1_aux1_drdy_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_aux1_drdy = 1;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_set_int1_aux1_drdy_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_aux1_drdy = 0;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_get_int1_aux1_drdy_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    *status = int1_config0.en_aux1_drdy;
    return 0;
}

int icm45686_set_int1_ap_fsync_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_ap_fsync = 1;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_set_int1_ap_fsync_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_ap_fsync = 0;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_get_int1_ap_fsync_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    *status = int1_config0.en_ap_fsync;
    return 0;
}

int icm45686_set_int1_ap_agc_rdy_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_ap_agc_rdy = 1;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_set_int1_ap_agc_rdy_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_ap_agc_rdy = 0;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_get_int1_ap_agc_rdy_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    *status = int1_config0.en_ap_agc_rdy;
    return 0;
}

int icm45686_set_int1_aux1_agc_rdy_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_aux1_agc_rdy = 1;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_set_int1_aux1_agc_rdy_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_aux1_agc_rdy = 0;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_get_int1_aux1_agc_rdy_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    *status = int1_config0.en_aux1_agc_rdy;
    return 0;
}

int icm45686_set_int1_reset_done_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_reset_done = 1;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_set_int1_reset_done_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    int1_config0.en_reset_done = 0;
    _ROE(_write_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    return 0;
}

int icm45686_get_int1_reset_done_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_CONFIG0_t int1_config0;
    _ROE(_read_register(INT1_CONFIG0, (uint8_t*)&int1_config0, 1));
    *status = int1_config0.en_reset_done;
    return 0;
}

int icm45686_set_int1_pll_rdy_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_pll_rdy = 1;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_set_int1_pll_rdy_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_pll_rdy = 0;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_get_int1_pll_rdy_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    *status = int1_config1.en_pll_rdy;
    return 0;
}

int icm45686_set_int1_wom_x_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_wom_x = 1;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_set_int1_wom_x_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_wom_x = 0;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_get_int1_wom_x_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    *status = int1_config1.en_wom_x;
    return 0;
}

int icm45686_set_int1_wom_y_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_wom_y = 1;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_set_int1_wom_y_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_wom_y = 0;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_get_int1_wom_y_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    *status = int1_config1.en_wom_y;
    return 0;
}

int icm45686_set_int1_wom_z_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_wom_z = 1;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_set_int1_wom_z_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_wom_z = 0;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_get_int1_wom_z_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    *status = int1_config1.en_wom_z;
    return 0;
}

int icm45686_set_int1_i3c_protocol_err_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_i3c_protocol_err = 1;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_set_int1_i3c_protocol_err_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_i3c_protocol_err = 0;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_get_int1_i3c_protocol_err_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    *status = int1_config1.en_i3c_protocol_err;
    return 0;
}

int icm45686_set_int1_i2cm_done_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_i2cm_done = 1;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_set_int1_i2cm_done_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_i2cm_done = 0;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_get_int1_i2cm_done_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    *status = int1_config1.en_i2cm_done;
    return 0;
}

int icm45686_set_int1_apex_event_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_apex_event = 1;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_set_int1_apex_event_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    int1_config1.en_apex_event = 0;
    _ROE(_write_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    return 0;
}

int icm45686_get_int1_apex_event_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_CONFIG1_t int1_config1;
    _ROE(_read_register(INT1_CONFIG1, (uint8_t*)&int1_config1, 1));
    *status = int1_config1.en_apex_event;
    return 0;
}

int icm45686_set_int1_polarity(struct icm45686_desc *desc, const enum INT_POLARITY pol)
{
    if (desc == NULL) return 1;
    INT1_CONFIG2_t int1_config2;
    _ROE(_read_register(INT1_CONFIG2, (uint8_t*)&int1_config2, 1));
    int1_config2.polarity = pol;
    _ROE(_write_register(INT1_CONFIG2, (uint8_t*)&int1_config2, 1));
    return 0;
}

int icm45686_get_int1_polarity(struct icm45686_desc *desc, enum INT_POLARITY *pol)
{
    if (desc == NULL || pol == NULL) return 1;
    INT1_CONFIG2_t int1_config2;
    _ROE(_read_register(INT1_CONFIG2, (uint8_t*)&int1_config2, 1));
    *pol = int1_config2.polarity;
    return 0;
}

int icm45686_set_int1_mode(struct icm45686_desc *desc, const enum INT_MODE mode)
{
    if (desc == NULL) return 1;
    INT1_CONFIG2_t int1_config2;
    _ROE(_read_register(INT1_CONFIG2, (uint8_t*)&int1_config2, 1));
    int1_config2.mode = mode;
    _ROE(_write_register(INT1_CONFIG2, (uint8_t*)&int1_config2, 1));
    return 0;
}

int icm45686_get_int1_mode(struct icm45686_desc *desc, enum INT_MODE *mode)
{
    if (desc == NULL || mode == NULL) return 1;
    INT1_CONFIG2_t int1_config2;
    _ROE(_read_register(INT1_CONFIG2, (uint8_t*)&int1_config2, 1));
    *mode = int1_config2.mode;
    return 0;
}

int icm45686_set_int1_drive(struct icm45686_desc *desc, const enum INT_DRIVE drive)
{
    if (desc == NULL) return 1;
    INT1_CONFIG2_t int1_config2;
    _ROE(_read_register(INT1_CONFIG2, (uint8_t*)&int1_config2, 1));
    int1_config2.drive = drive;
    _ROE(_write_register(INT1_CONFIG2, (uint8_t*)&int1_config2, 1));
    return 0;
}

int icm45686_get_int1_drive(struct icm45686_desc *desc, enum INT_DRIVE *drive)
{
    if (desc == NULL || drive == NULL) return 1;
    INT1_CONFIG2_t int1_config2;
    _ROE(_read_register(INT1_CONFIG2, (uint8_t*)&int1_config2, 1));
    *drive = int1_config2.drive;
    return 0;
}

int icm45686_get_int1_status(struct icm45686_desc *desc, struct icm45686_interrupt *status)
{
    if (desc == NULL || status == NULL) return 1;
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
    if (desc == NULL || status == NULL) return 1;
    INT1_STATUS0_t int1_status0;
    _ROE(_read_register(INT1_STATUS0, (uint8_t*)&int1_status0, 1));
    *status = int1_status0.fifo_full;
    return 0;
}

int icm45686_get_int1_fifo_ths_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_STATUS0_t int1_status0;
    _ROE(_read_register(INT1_STATUS0, (uint8_t*)&int1_status0, 1));
    *status = int1_status0.fifo_ths;
    return 0;
}

int icm45686_get_int1_ap_drdy_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_STATUS0_t int1_status0;
    _ROE(_read_register(INT1_STATUS0, (uint8_t*)&int1_status0, 1));
    *status = int1_status0.drdy;
    return 0;
}

int icm45686_get_int1_aux1_drdy_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_STATUS0_t int1_status0;
    _ROE(_read_register(INT1_STATUS0, (uint8_t*)&int1_status0, 1));
    *status = int1_status0.aux1_drdy;
    return 0;
}

int icm45686_get_int1_ap_fsync_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_STATUS0_t int1_status0;
    _ROE(_read_register(INT1_STATUS0, (uint8_t*)&int1_status0, 1));
    *status = int1_status0.ap_fsync;
    return 0;
}

int icm45686_get_int1_ap_agc_rdy_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_STATUS0_t int1_status0;
    _ROE(_read_register(INT1_STATUS0, (uint8_t*)&int1_status0, 1));
    *status = int1_status0.ap_agc_rdy;
    return 0;
}

int icm45686_get_int1_aux1_agc_rdy_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_STATUS0_t int1_status0;
    _ROE(_read_register(INT1_STATUS0, (uint8_t*)&int1_status0, 1));
    *status = int1_status0.aux1_agc_rdy;
    return 0;
}

int icm45686_get_int1_reset_done_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_STATUS0_t int1_status0;
    _ROE(_read_register(INT1_STATUS0, (uint8_t*)&int1_status0, 1));
    *status = int1_status0.reset_done;
    return 0;
}

int icm45686_get_int1_pll_rdy_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_STATUS1_t int1_status1;
    _ROE(_read_register(INT1_STATUS1, (uint8_t*)&int1_status1, 1));
    *status = int1_status1.pll_rdy;
    return 0;
}

int icm45686_get_int1_wom_x_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_STATUS1_t int1_status1;
    _ROE(_read_register(INT1_STATUS1, (uint8_t*)&int1_status1, 1));
    *status = int1_status1.wom_x;
    return 0;
}

int icm45686_get_int1_wom_y_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_STATUS1_t int1_status1;
    _ROE(_read_register(INT1_STATUS1, (uint8_t*)&int1_status1, 1));
    *status = int1_status1.wom_y;
    return 0;
}

int icm45686_get_int1_wom_z_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_STATUS1_t int1_status1;
    _ROE(_read_register(INT1_STATUS1, (uint8_t*)&int1_status1, 1));
    *status = int1_status1.wom_z;
    return 0;
}

int icm45686_get_int1_i3c_protocol_err_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_STATUS1_t int1_status1;
    _ROE(_read_register(INT1_STATUS1, (uint8_t*)&int1_status1, 1));
    *status = int1_status1.i3c_protocol_err;
    return 0;
}

int icm45686_get_int1_i2cm_done_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_STATUS1_t int1_status1;
    _ROE(_read_register(INT1_STATUS1, (uint8_t*)&int1_status1, 1));
    *status = int1_status1.i2cm_done;
    return 0;
}

int icm45686_get_int1_apex_event_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT1_STATUS1_t int1_status1;
    _ROE(_read_register(INT1_STATUS1, (uint8_t*)&int1_status1, 1));
    *status = int1_status1.apex_event;
    return 0;
}

int icm45686_set_ap_accel_scale(struct icm45686_desc *desc, const enum ACCEL_UI_FS_SEL scale)
{
    if (desc == NULL) return 1;
    ACCEL_CONFIG0_t accel_config0;
    _ROE(_read_register(ACCEL_CONFIG0, (uint8_t*)&accel_config0, 1));
    accel_config0.scale = scale;
    _ROE(_write_register(ACCEL_CONFIG0, (uint8_t*)&accel_config0, 1));
    return 0;
}

int icm45686_get_ap_accel_scale(struct icm45686_desc *desc, enum ACCEL_UI_FS_SEL *scale)
{
    if (desc == NULL || scale == NULL) return 1;
    ACCEL_CONFIG0_t accel_config0;
    _ROE(_read_register(ACCEL_CONFIG0, (uint8_t*)&accel_config0, 1));
    *scale = accel_config0.scale;
    return 0;
}

int icm45686_set_ap_accel_odr(struct icm45686_desc *desc, const enum ACCEL_ODR odr)
{
    if (desc == NULL) return 1;
    ACCEL_CONFIG0_t accel_config0;
    _ROE(_read_register(ACCEL_CONFIG0, (uint8_t*)&accel_config0, 1));
    accel_config0.odr = odr;
    _ROE(_write_register(ACCEL_CONFIG0, (uint8_t*)&accel_config0, 1));
    return 0;
}

int icm45686_get_ap_accel_odr(struct icm45686_desc *desc, enum ACCEL_ODR *odr)
{
    if (desc == NULL || odr == NULL) return 1;
    ACCEL_CONFIG0_t accel_config0;
    _ROE(_read_register(ACCEL_CONFIG0, (uint8_t*)&accel_config0, 1));
    *odr = accel_config0.odr;
    return 0;
}

int icm45686_set_ap_gyro_scale(struct icm45686_desc *desc, const enum GYRO_UI_FS_SEL scale)
{
    if (desc == NULL) return 1;
    GYRO_CONFIG0_t gyro_config0;
    _ROE(_read_register(GYRO_CONFIG0, (uint8_t*)&gyro_config0, 1));
    gyro_config0.scale = scale;
    _ROE(_write_register(GYRO_CONFIG0, (uint8_t*)&gyro_config0, 1));
    return 0;
}

int icm45686_get_ap_gyro_scale(struct icm45686_desc *desc, enum GYRO_UI_FS_SEL *scale)
{
    if (desc == NULL || scale == NULL) return 1;
    GYRO_CONFIG0_t gyro_config0;
    _ROE(_read_register(GYRO_CONFIG0, (uint8_t*)&gyro_config0, 1));
    *scale = gyro_config0.scale;
    return 0;
}

int icm45686_set_ap_gyro_odr(struct icm45686_desc *desc, const enum GYRO_ODR odr)
{
    if (desc == NULL) return 1;
    GYRO_CONFIG0_t gyro_config0;
    _ROE(_read_register(GYRO_CONFIG0, (uint8_t*)&gyro_config0, 1));
    gyro_config0.odr = odr;
    _ROE(_write_register(GYRO_CONFIG0, (uint8_t*)&gyro_config0, 1));
    return 0;
}

int icm45686_get_ap_gyro_odr(struct icm45686_desc *desc, enum GYRO_ODR *odr)
{
    if (desc == NULL || odr == NULL) return 1;
    GYRO_CONFIG0_t gyro_config0;
    _ROE(_read_register(GYRO_CONFIG0, (uint8_t*)&gyro_config0, 1));
    *odr = gyro_config0.odr;
    return 0;
}

int icm45686_set_fifo_depth(struct icm45686_desc *desc, const enum FIFO_DEPTH depth)
{
    if (desc == NULL) return 1;
    FIFO_CONFIG0_t fifo_config0;
    _ROE(_read_register(FIFO_CONFIG0, (uint8_t*)&fifo_config0, 1));
    fifo_config0.fifo_depth = depth;
    _ROE(_write_register(FIFO_CONFIG0, (uint8_t*)&fifo_config0, 1));
    return 0;
}

int icm45686_get_fifo_depth(struct icm45686_desc *desc, enum FIFO_DEPTH *depth)
{
    if (desc == NULL || depth == NULL) return 1;
    FIFO_CONFIG0_t fifo_config0;
    _ROE(_read_register(FIFO_CONFIG0, (uint8_t*)&fifo_config0, 1));
    *depth = fifo_config0.fifo_depth;
    return 0;
}

int icm45686_set_fifo_mode(struct icm45686_desc *desc, const enum FIFO_MODE mode)
{
    if (desc == NULL) return 1;
    FIFO_CONFIG0_t fifo_config0;
    _ROE(_read_register(FIFO_CONFIG0, (uint8_t*)&fifo_config0, 1));
    fifo_config0.mode = mode;
    _ROE(_write_register(FIFO_CONFIG0, (uint8_t*)&fifo_config0, 1));
    return 0;
}

int icm45686_get_fifo_mode(struct icm45686_desc *desc, enum FIFO_MODE *mode)
{
    if (desc == NULL || mode == NULL) return 1;
    FIFO_CONFIG0_t fifo_config0;
    _ROE(_read_register(FIFO_CONFIG0, (uint8_t*)&fifo_config0, 1));
    *mode = fifo_config0.mode;
    return 0;
}

int icm45686_set_fifo_watermark(struct icm45686_desc *desc, uint16_t watermark)
{
    if (desc == NULL) return 1;
    uint8_t wm[2];
    wm[0] = (uint8_t)watermark;
    wm[1] = (uint8_t)(watermark>>8);
    _ROE(_write_register(FIFO_CONFIG1_0, wm, 2));
    return 0;
}

int icm45686_get_fifo_watermark(struct icm45686_desc *desc, uint16_t *watermark)
{
    if (desc == NULL) return 1;
    _ROE(_read_register(FIFO_CONFIG1_0, watermark, 2));
    return 0;
}

int icm45686_fifo_flush(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    FIFO_CONFIG2_t fifo_config2;
    _ROE(_read_register(FIFO_CONFIG2, (uint8_t*)&fifo_config2, 1));
    fifo_config2.fifo_flush = 1;
    _ROE(_write_register(FIFO_CONFIG2, (uint8_t*)&fifo_config2, 1));
    fifo_config2.fifo_flush = 0;
    _ROE(_write_register(FIFO_CONFIG2, (uint8_t*)&fifo_config2, 1));
    return 0;
}

int icm45686_set_fifo_watermark_mode(struct icm45686_desc *desc, enum FIFO_WR_WM_GT_TH mode)
{
    if (desc == NULL) return 1;
    FIFO_CONFIG2_t fifo_config2 = {
        .__dummy1 = 0,
        .fifo_wm_int_condition = mode,
        .__dummy2 = 0,
        .fifo_flush = 0,
    };
    _ROE(_write_register(FIFO_CONFIG2, (uint8_t*)&fifo_config2, 1));
    return 0;
}

int icm45686_get_fifo_watermark_mode(struct icm45686_desc *desc, enum FIFO_WR_WM_GT_TH *mode)
{
    if (desc == NULL) return 1;
    FIFO_CONFIG2_t fifo_config2;
    _ROE(_read_register(FIFO_CONFIG2, (uint8_t*)&fifo_config2, 1));
    *mode = fifo_config2.fifo_wm_int_condition;
    return 0;
}

int icm45686_set_fifo_accel_insertion_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    FIFO_CONFIG3_t fifo_config3;
    _ROE(_read_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    fifo_config3.fifo_accel_insertion_en = 1;
    _ROE(_write_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    return 0;
}

int icm45686_set_fifo_accel_insertion_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    FIFO_CONFIG3_t fifo_config3;
    _ROE(_read_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    fifo_config3.fifo_accel_insertion_en = 0;
    _ROE(_write_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    return 0;
}

int icm45686_get_fifo_accel_insertion_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    FIFO_CONFIG3_t fifo_config3;
    _ROE(_read_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    *status = fifo_config3.fifo_accel_insertion_en;
    return 0;
}

int icm45686_set_fifo_gyro_insertion_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    FIFO_CONFIG3_t fifo_config3;
    _ROE(_read_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    fifo_config3.fifo_gyro_insertion_en = 1;
    _ROE(_write_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    return 0;
}

int icm45686_set_fifo_gyro_insertion_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    FIFO_CONFIG3_t fifo_config3;
    _ROE(_read_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    fifo_config3.fifo_gyro_insertion_en = 0;
    _ROE(_write_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    return 0;
}

int icm45686_get_fifo_accel_insertion_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    FIFO_CONFIG3_t fifo_config3;
    _ROE(_read_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    *status = fifo_config3.fifo_gyro_insertion_en;
    return 0;
}

int icm45686_set_fifo_hires_insertion_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    FIFO_CONFIG3_t fifo_config3;
    _ROE(_read_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    fifo_config3.fifo_sensor_high_resolution_en = 1;
    _ROE(_write_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    return 0;
}

int icm45686_set_fifo_hires_insertion_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    FIFO_CONFIG3_t fifo_config3;
    _ROE(_read_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    fifo_config3.fifo_sensor_high_resolution_en = 0;
    _ROE(_write_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    return 0;
}

int icm45686_get_fifo_hires_insertion_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    FIFO_CONFIG3_t fifo_config3;
    _ROE(_read_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    *status = fifo_config3.fifo_sensor_high_resolution_en;
    return 0;
}

int icm45686_set_fifo_es0_insertion_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    FIFO_CONFIG3_t fifo_config3;
    _ROE(_read_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    fifo_config3.fifo_es0_insertion_en = 1;
    _ROE(_write_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    return 0;
}

int icm45686_set_fifo_es0_insertion_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    FIFO_CONFIG3_t fifo_config3;
    _ROE(_read_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    fifo_config3.fifo_es0_insertion_en = 0;
    _ROE(_write_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    return 0;
}

int icm45686_get_fifo_es0_insertion_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    FIFO_CONFIG3_t fifo_config3;
    _ROE(_read_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    *status = fifo_config3.fifo_es0_insertion_en;
    return 0;
}

int icm45686_set_fifo_es1_insertion_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    FIFO_CONFIG3_t fifo_config3;
    _ROE(_read_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    fifo_config3.fifo_es1_insertion_en = 1;
    _ROE(_write_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    return 0;
}

int icm45686_set_fifo_es1_insertion_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    FIFO_CONFIG3_t fifo_config3;
    _ROE(_read_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    fifo_config3.fifo_es1_insertion_en = 0;
    _ROE(_write_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    return 0;
}

int icm45686_get_fifo_es1_insertion_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    FIFO_CONFIG3_t fifo_config3;
    _ROE(_read_register(FIFO_CONFIG3, (uint8_t*)&fifo_config3, 1));
    *status = fifo_config3.fifo_es1_insertion_en;
    return 0;
}

int icm45686_set_fifo_tmst_insertion_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    FIFO_CONFIG4_t fifo_config4;
    _ROE(_read_register(FIFO_CONFIG4, (uint8_t*)&fifo_config4, 1));
    fifo_config4.fifo_tmst_fsync_insertion_en = 1;
    _ROE(_write_register(FIFO_CONFIG3, (uint8_t*)&fifo_config4, 1));
    return 0;
}

int icm45686_set_fifo_tmst_insertion_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    FIFO_CONFIG4_t fifo_config4;
    _ROE(_read_register(FIFO_CONFIG4, (uint8_t*)&fifo_config4, 1));
    fifo_config4.fifo_tmst_fsync_insertion_en = 0;
    _ROE(_write_register(FIFO_CONFIG3, (uint8_t*)&fifo_config4, 1));
    return 0;
}

int icm45686_get_fifo_tmst_insertion_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    FIFO_CONFIG4_t fifo_config4;
    _ROE(_read_register(FIFO_CONFIG4, (uint8_t*)&fifo_config4, 1));
    *status = fifo_config4.fifo_tmst_fsync_insertion_en;
    return 0;
}

int icm45686_set_es0_bytes(struct icm45686_desc *desc, enum FIFO_ES0_6B_9B bytes)
{
    if (desc == NULL) return 1;
    FIFO_CONFIG4_t fifo_config4;
    _ROE(_read_register(FIFO_CONFIG4, (uint8_t*)&fifo_config4, 1));
    fifo_config4.ext_sensor0_bytes = bytes;
    _ROE(_write_register(FIFO_CONFIG4, (uint8_t*)&fifo_config4, 1));
    return 0;
}

int icm45686_get_es0_bytes(struct icm45686_desc *desc, enum FIFO_ES0_6B_9B *bytes)
{
    if (desc == NULL || bytes == NULL) return 1;
    FIFO_CONFIG4_t fifo_config4;
    _ROE(_read_register(FIFO_CONFIG4, (uint8_t*)&fifo_config4, 1));
    *bytes = fifo_config4.ext_sensor0_bytes;
    return 0;
}

int icm45686_set_fifo_compression_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    FIFO_CONFIG4_t fifo_config4;
    _ROE(_read_register(FIFO_CONFIG4, (uint8_t*)&fifo_config4, 1));
    fifo_config4.fifo_compression_en = 1;
    _ROE(_write_register(FIFO_CONFIG4, (uint8_t*)&fifo_config4, 1));
    return 0;
}

int icm45686_set_fifo_compression_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    FIFO_CONFIG4_t fifo_config4;
    _ROE(_read_register(FIFO_CONFIG4, (uint8_t*)&fifo_config4, 1));
    fifo_config4.fifo_compression_en = 0;
    _ROE(_write_register(FIFO_CONFIG4, (uint8_t*)&fifo_config4, 1));
    return 0;
}

int icm45686_get_fifo_compression_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    FIFO_CONFIG4_t fifo_config4;
    _ROE(_read_register(FIFO_CONFIG4, (uint8_t*)&fifo_config4, 1));
    *status = fifo_config4.fifo_compression_en;
    return 0;
}

int icm45686_set_fifo_compression_algorithm(struct icm45686_desc *desc, enum FIFO_COMP_NC_FLOW_CFG cfg)
{
    if (desc == NULL) return 1;
    FIFO_CONFIG4_t fifo_config4;
    _ROE(_read_register(FIFO_CONFIG4, (uint8_t*)&fifo_config4, 1));
    fifo_config4.compression_algorithm = cfg;
    _ROE(_write_register(FIFO_CONFIG4, (uint8_t*)&fifo_config4, 1));
    return 0;
}

int icm45686_get_fifo_compression_algorithm(struct icm45686_desc *desc, enum FIFO_COMP_NC_FLOW_CFG *cfg)
{
    if (desc == NULL || cfg == NULL) return 1;
    FIFO_CONFIG4_t fifo_config4;
    _ROE(_read_register(FIFO_CONFIG4, (uint8_t*)&fifo_config4, 1));
    *cfg = fifo_config4.compression_algorithm;
    return 0;
}

int icm45686_set_wom_int_duration(struct icm45686_desc *desc, enum WOM_INT_DUR dur)
{
    if (desc == NULL) return 1;
    TMST_WOM_CONFIG_t tmst_wom_cfg;
    _ROE(_read_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    tmst_wom_cfg.wom_int_duration = dur;
    _ROE(_write_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    return 0;
}

int icm45686_get_wom_int_duration(struct icm45686_desc *desc, enum WOM_INT_DUR *dur)
{
    if (desc == NULL || dur == NULL) return 1;
    TMST_WOM_CONFIG_t tmst_wom_cfg;
    _ROE(_read_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    *dur = tmst_wom_cfg.wom_int_duration;
    return 0;
}

int icm45686_set_wom_int_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    TMST_WOM_CONFIG_t tmst_wom_cfg;
    _ROE(_read_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    tmst_wom_cfg.wom_interrupt_en = 1;
    _ROE(_write_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    return 0;
}

int icm45686_set_wom_int_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    TMST_WOM_CONFIG_t tmst_wom_cfg;
    _ROE(_read_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    tmst_wom_cfg.wom_interrupt_en = 0;
    _ROE(_write_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    return 0;
}

int icm45686_get_wom_int_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    TMST_WOM_CONFIG_t tmst_wom_cfg;
    _ROE(_read_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    *status = tmst_wom_cfg.wom_interrupt_en;
    return 0;
}

int icm45686_set_wom_mode(struct icm45686_desc *desc, enum WOM_MODE mode)
{
    if (desc == NULL) return 1;
    TMST_WOM_CONFIG_t tmst_wom_cfg;
    _ROE(_read_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    tmst_wom_cfg.wom_mode = mode;
    _ROE(_write_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    return 0;
}

int icm45686_get_wom_mode(struct icm45686_desc *desc, enum WOM_MODE *mode)
{
    if (desc == NULL || mode == NULL) return 1;
    TMST_WOM_CONFIG_t tmst_wom_cfg;
    _ROE(_read_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    *mode = tmst_wom_cfg.wom_mode;
    return 0;
}

int icm45686_set_wom_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    TMST_WOM_CONFIG_t tmst_wom_cfg;
    _ROE(_read_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    tmst_wom_cfg.wom_en = 1;
    _ROE(_write_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    return 0;
}

int icm45686_set_wom_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    TMST_WOM_CONFIG_t tmst_wom_cfg;
    _ROE(_read_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    tmst_wom_cfg.wom_en = 0;
    _ROE(_write_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    return 0;
}

int icm45686_get_wom_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    TMST_WOM_CONFIG_t tmst_wom_cfg;
    _ROE(_read_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    *status = tmst_wom_cfg.wom_en;
    return 0;
}

int icm45686_set_tmst_resol(struct icm45686_desc *desc, enum TMST_RESOL res)
{
    if (desc == NULL) return 1;
    TMST_WOM_CONFIG_t tmst_wom_cfg;
    _ROE(_read_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    tmst_wom_cfg.tmst_resolution = res;
    _ROE(_write_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    return 0;
}

int icm45686_get_tmst_resol(struct icm45686_desc *desc, enum TMST_RESOL *res)
{
    if (desc == NULL || res == NULL) return 1;
    TMST_WOM_CONFIG_t tmst_wom_cfg;
    _ROE(_read_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    *res = tmst_wom_cfg.tmst_resolution;
    return 0;
}

int icm45686_set_tmst_delta_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    TMST_WOM_CONFIG_t tmst_wom_cfg;
    _ROE(_read_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    tmst_wom_cfg.tmst_delta_en = 1;
    _ROE(_write_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    return 0;
}

int icm45686_set_tmst_delta_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    TMST_WOM_CONFIG_t tmst_wom_cfg;
    _ROE(_read_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    tmst_wom_cfg.tmst_delta_en = 0;
    _ROE(_write_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    return 0;
}

int icm45686_get_tmst_delta_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    TMST_WOM_CONFIG_t tmst_wom_cfg;
    _ROE(_read_register(TMST_WOM_CONFIG, (uint8_t*)&tmst_wom_cfg, 1));
    *status = tmst_wom_cfg.tmst_delta_en;
    return 0;
}




int icm45686_set_int2_enable(struct icm45686_desc *desc, struct icm45686_interrupt *cfg)
{
    if (desc == NULL || cfg == NULL) return 1;
    INT2_CONFIG0_t int2_config0 = {
        .en_fifo_full = cfg->fifo_full,
        .en_fifo_ths = cfg->fifo_ths,
        .en_drdy = cfg->drdy,
        .en_aux1_drdy = cfg->aux1_drdy,
        .en_ap_fsync = cfg->ap_fsync,
        .en_ap_agc_rdy = cfg->ap_agc_rdy,
        .en_aux1_agc_rdy = cfg->aux1_agc_rdy,
        .en_reset_done = cfg->reset_done,
    };
    _ROE(_write_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    INT2_CONFIG1_t int2_config1 = {
        .en_pll_rdy = cfg->pll_rdy,
        .en_wom_x = cfg->wom_x,
        .en_wom_y = cfg->wom_y,
        .en_wom_z = cfg->wom_z,
        .en_i3c_protocol_err = cfg->i3c_protocol_err,
        .en_i2cm_done = cfg->i2cm_done,
        .en_apex_event = cfg->apex_event,
        .__dummy = 0,
    };
    _ROE(_write_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    return 0;
}

int icm45686_get_int2_enable(struct icm45686_desc *desc, struct icm45686_interrupt *cfg)
{
    if (desc == NULL || cfg == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    cfg->fifo_full = int2_config0.en_fifo_full;
    cfg->fifo_ths = int2_config0.en_fifo_ths;
    cfg->drdy = int2_config0.en_drdy;
    cfg->aux1_drdy = int2_config0.en_aux1_drdy;
    cfg->ap_fsync = int2_config0.en_ap_fsync;
    cfg->ap_agc_rdy = int2_config0.en_ap_agc_rdy;
    cfg->aux1_agc_rdy = int2_config0.en_aux1_agc_rdy;
    cfg->reset_done = int2_config0.en_reset_done;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    cfg->pll_rdy = int2_config1.en_pll_rdy;
    cfg->wom_x = int2_config1.en_wom_x;
    cfg->wom_y = int2_config1.en_wom_y;
    cfg->wom_z = int2_config1.en_wom_z;
    cfg->i3c_protocol_err = int2_config1.en_i3c_protocol_err;
    cfg->i2cm_done = int2_config1.en_i2cm_done;
    cfg->apex_event = int2_config1.en_apex_event;
    return 0;
}

int icm45686_set_int2_fifo_full_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    int2_config0.en_fifo_full = 1;
    _ROE(_write_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    return 0;
}

int icm45686_set_int2_fifo_full_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    int2_config0.en_fifo_full = 0;
    _ROE(_write_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    return 0;
}

int icm45686_get_int2_fifo_full_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    *status = int2_config0.en_fifo_full;
    return 0;
}

int icm45686_set_int2_fifo_ths_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    int2_config0.en_fifo_ths = 1;
    _ROE(_write_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    return 0;
}

int icm45686_set_int2_fifo_ths_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    int2_config0.en_fifo_ths = 0;
    _ROE(_write_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    return 0;
}

int icm45686_get_int2_fifo_ths_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    *status = int2_config0.en_fifo_ths;
    return 0;
}

int icm45686_set_int2_ap_drdy_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    int2_config0.en_drdy = 1;
    _ROE(_write_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    return 0;
}

int icm45686_set_int2_ap_drdy_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    int2_config0.en_drdy = 0;
    _ROE(_write_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    return 0;
}

int icm45686_get_int2_ap_drdy_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    *status = int2_config0.en_drdy;
    return 0;
}

int icm45686_set_int2_aux1_drdy_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    int2_config0.en_aux1_drdy = 1;
    _ROE(_write_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    return 0;
}

int icm45686_set_int2_aux1_drdy_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    int2_config0.en_aux1_drdy = 0;
    _ROE(_write_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    return 0;
}

int icm45686_get_int2_aux1_drdy_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    *status = int2_config0.en_aux1_drdy;
    return 0;
}

int icm45686_set_int2_ap_fsync_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    int2_config0.en_ap_fsync = 1;
    _ROE(_write_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    return 0;
}

int icm45686_set_int2_ap_fsync_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    int2_config0.en_ap_fsync = 0;
    _ROE(_write_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    return 0;
}

int icm45686_get_int2_ap_fsync_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    *status = int2_config0.en_ap_fsync;
    return 0;
}

int icm45686_set_int2_ap_agc_rdy_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT1_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    int2_config0.en_ap_agc_rdy = 1;
    _ROE(_write_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    return 0;
}

int icm45686_set_int2_ap_agc_rdy_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    int2_config0.en_ap_agc_rdy = 0;
    _ROE(_write_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    return 0;
}

int icm45686_get_int2_ap_agc_rdy_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    *status = int2_config0.en_ap_agc_rdy;
    return 0;
}

int icm45686_set_int2_aux1_agc_rdy_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    int2_config0.en_aux1_agc_rdy = 1;
    _ROE(_write_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    return 0;
}

int icm45686_set_int2_aux1_agc_rdy_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    int2_config0.en_aux1_agc_rdy = 0;
    _ROE(_write_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    return 0;
}

int icm45686_get_int2_aux1_agc_rdy_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    *status = int2_config0.en_aux1_agc_rdy;
    return 0;
}

int icm45686_set_int2_reset_done_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    int2_config0.en_reset_done = 1;
    _ROE(_write_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    return 0;
}

int icm45686_set_int2_reset_done_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    int2_config0.en_reset_done = 0;
    _ROE(_write_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    return 0;
}

int icm45686_get_int2_reset_done_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_CONFIG0_t int2_config0;
    _ROE(_read_register(INT2_CONFIG0, (uint8_t*)&int2_config0, 1));
    *status = int2_config0.en_reset_done;
    return 0;
}

int icm45686_set_int2_pll_rdy_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    int2_config1.en_pll_rdy = 1;
    _ROE(_write_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    return 0;
}

int icm45686_set_int2_pll_rdy_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    int2_config1.en_pll_rdy = 0;
    _ROE(_write_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    return 0;
}

int icm45686_get_int2_pll_rdy_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    *status = int2_config1.en_pll_rdy;
    return 0;
}

int icm45686_set_int2_wom_x_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    int2_config1.en_wom_x = 1;
    _ROE(_write_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    return 0;
}

int icm45686_set_int2_wom_x_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    int2_config1.en_wom_x = 0;
    _ROE(_write_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    return 0;
}

int icm45686_get_int2_wom_x_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    *status = int2_config1.en_wom_x;
    return 0;
}

int icm45686_set_int2_wom_y_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    int2_config1.en_wom_y = 1;
    _ROE(_write_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    return 0;
}

int icm45686_set_int2_wom_y_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    int2_config1.en_wom_y = 0;
    _ROE(_write_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    return 0;
}

int icm45686_get_int2_wom_y_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    *status = int2_config1.en_wom_y;
    return 0;
}

int icm45686_set_int2_wom_z_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    int2_config1.en_wom_z = 1;
    _ROE(_write_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    return 0;
}

int icm45686_set_int2_wom_z_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    int2_config1.en_wom_z = 0;
    _ROE(_write_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    return 0;
}

int icm45686_get_int2_wom_z_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    *status = int2_config1.en_wom_z;
    return 0;
}

int icm45686_set_int2_i3c_protocol_err_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    int2_config1.en_i3c_protocol_err = 1;
    _ROE(_write_register(INT1_CONFIG2, (uint8_t*)&int2_config1, 1));
    return 0;
}

int icm45686_set_int2_i3c_protocol_err_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    int2_config1.en_i3c_protocol_err = 0;
    _ROE(_write_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    return 0;
}

int icm45686_get_int2_i3c_protocol_err_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    *status = int2_config1.en_i3c_protocol_err;
    return 0;
}

int icm45686_set_int2_i2cm_done_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    int2_config1.en_i2cm_done = 1;
    _ROE(_write_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    return 0;
}

int icm45686_set_int2_i2cm_done_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    int2_config1.en_i2cm_done = 0;
    _ROE(_write_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    return 0;
}

int icm45686_get_int2_i2cm_done_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    *status = int2_config1.en_i2cm_done;
    return 0;
}

int icm45686_set_int2_apex_event_enable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    int2_config1.en_apex_event = 1;
    _ROE(_write_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    return 0;
}

int icm45686_set_int2_apex_event_disable(struct icm45686_desc *desc)
{
    if (desc == NULL) return 1;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    int2_config1.en_apex_event = 0;
    _ROE(_write_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    return 0;
}

int icm45686_get_int2_apex_event_enable_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_CONFIG1_t int2_config1;
    _ROE(_read_register(INT2_CONFIG1, (uint8_t*)&int2_config1, 1));
    *status = int2_config1.en_apex_event;
    return 0;
}

int icm45686_set_int2_polarity(struct icm45686_desc *desc, const enum INT_POLARITY pol)
{
    if (desc == NULL) return 1;
    INT2_CONFIG2_t int2_config2;
    _ROE(_read_register(INT2_CONFIG2, (uint8_t*)&int2_config2, 1));
    int2_config2.polarity = pol;
    _ROE(_write_register(INT2_CONFIG2, (uint8_t*)&int2_config2, 1));
    return 0;
}

int icm45686_get_int2_polarity(struct icm45686_desc *desc, enum INT_POLARITY *pol)
{
    if (desc == NULL || pol == NULL) return 1;
    INT2_CONFIG2_t int2_config2;
    _ROE(_read_register(INT2_CONFIG2, (uint8_t*)&int2_config2, 1));
    *pol = int2_config2.polarity;
    return 0;
}

int icm45686_set_int2_mode(struct icm45686_desc *desc, const enum INT_MODE mode)
{
    if (desc == NULL) return 1;
    INT2_CONFIG2_t int2_config2;
    _ROE(_read_register(INT2_CONFIG2, (uint8_t*)&int2_config2, 1));
    int2_config2.mode = mode;
    _ROE(_write_register(INT2_CONFIG2, (uint8_t*)&int2_config2, 1));
    return 0;
}

int icm45686_get_int2_mode(struct icm45686_desc *desc, enum INT_MODE *mode)
{
    if (desc == NULL || mode == NULL) return 1;
    INT2_CONFIG2_t int2_config2;
    _ROE(_read_register(INT2_CONFIG2, (uint8_t*)&int2_config2, 1));
    *mode = int2_config2.mode;
    return 0;
}

int icm45686_set_int2_drive(struct icm45686_desc *desc, const enum INT_DRIVE drive)
{
    if (desc == NULL) return 1;
    INT2_CONFIG2_t int2_config2;
    _ROE(_read_register(INT2_CONFIG2, (uint8_t*)&int2_config2, 1));
    int2_config2.drive = drive;
    _ROE(_write_register(INT2_CONFIG2, (uint8_t*)&int2_config2, 1));
    return 0;
}

int icm45686_get_int2_drive(struct icm45686_desc *desc, enum INT_DRIVE *drive)
{
    if (desc == NULL || drive == NULL) return 1;
    INT2_CONFIG2_t int2_config2;
    _ROE(_read_register(INT2_CONFIG2, (uint8_t*)&int2_config2, 1));
    *drive = int2_config2.drive;
    return 0;
}

int icm45686_get_int2_status(struct icm45686_desc *desc, struct icm45686_interrupt *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_STATUS0_t int2_status0;
    _ROE(_read_register(INT2_STATUS0, (uint8_t*)&int2_status0, 1));
    status->fifo_full = int2_status0.fifo_full;
    status->fifo_ths = int2_status0.fifo_ths;
    status->drdy = int2_status0.drdy;
    status->aux1_drdy = int2_status0.aux1_drdy;
    status->ap_fsync = int2_status0.ap_fsync;
    status->ap_agc_rdy = int2_status0.ap_agc_rdy;
    status->aux1_agc_rdy = int2_status0.aux1_agc_rdy;
    status->reset_done = int2_status0.reset_done;
    INT2_STATUS1_t int2_status1;
    _ROE(_read_register(INT2_STATUS1, (uint8_t*)&int2_status1, 1));
    status->pll_rdy = int2_status1.pll_rdy;
    status->wom_x = int2_status1.wom_x;
    status->wom_y = int2_status1.wom_y;
    status->wom_z = int2_status1.wom_z;
    status->i3c_protocol_err = int2_status1.i3c_protocol_err;
    status->i2cm_done = int2_status1.i2cm_done;
    status->apex_event = int2_status1.apex_event;
    return 0;
}

int icm45686_get_int2_fifo_full_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_STATUS0_t int2_status0;
    _ROE(_read_register(INT2_STATUS0, (uint8_t*)&int2_status0, 1));
    *status = int2_status0.fifo_full;
    return 0;
}

int icm45686_get_int2_fifo_ths_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_STATUS0_t int2_status0;
    _ROE(_read_register(INT2_STATUS0, (uint8_t*)&int2_status0, 1));
    *status = int2_status0.fifo_ths;
    return 0;
}

int icm45686_get_int2_ap_drdy_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_STATUS0_t int2_status0;
    _ROE(_read_register(INT2_STATUS0, (uint8_t*)&int2_status0, 1));
    *status = int2_status0.drdy;
    return 0;
}

int icm45686_get_int2_aux1_drdy_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_STATUS0_t int2_status0;
    _ROE(_read_register(INT2_STATUS0, (uint8_t*)&int2_status0, 1));
    *status = int2_status0.aux1_drdy;
    return 0;
}

int icm45686_get_int2_ap_fsync_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_STATUS0_t int2_status0;
    _ROE(_read_register(INT2_STATUS0, (uint8_t*)&int2_status0, 1));
    *status = int2_status0.ap_fsync;
    return 0;
}

int icm45686_get_int2_ap_agc_rdy_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_STATUS0_t int2_status0;
    _ROE(_read_register(INT2_STATUS0, (uint8_t*)&int2_status0, 1));
    *status = int2_status0.ap_agc_rdy;
    return 0;
}

int icm45686_get_int2_aux1_agc_rdy_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_STATUS0_t int2_status0;
    _ROE(_read_register(INT2_STATUS0, (uint8_t*)&int2_status0, 1));
    *status = int2_status0.aux1_agc_rdy;
    return 0;
}

int icm45686_get_int2_reset_done_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_STATUS0_t int2_status0;
    _ROE(_read_register(INT2_STATUS0, (uint8_t*)&int2_status0, 1));
    *status = int2_status0.reset_done;
    return 0;
}

int icm45686_get_int2_pll_rdy_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_STATUS1_t int2_status1;
    _ROE(_read_register(INT2_STATUS1, (uint8_t*)&int2_status1, 1));
    *status = int2_status1.pll_rdy;
    return 0;
}

int icm45686_get_int2_wom_x_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_STATUS1_t int2_status1;
    _ROE(_read_register(INT2_STATUS1, (uint8_t*)&int2_status1, 1));
    *status = int2_status1.wom_x;
    return 0;
}

int icm45686_get_int2_wom_y_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_STATUS1_t int2_status1;
    _ROE(_read_register(INT2_STATUS1, (uint8_t*)&int2_status1, 1));
    *status = int2_status1.wom_y;
    return 0;
}

int icm45686_get_int2_wom_z_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_STATUS1_t int2_status1;
    _ROE(_read_register(INT2_STATUS1, (uint8_t*)&int2_status1, 1));
    *status = int2_status1.wom_z;
    return 0;
}

int icm45686_get_int2_i3c_protocol_err_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_STATUS1_t int2_status1;
    _ROE(_read_register(INT2_STATUS1, (uint8_t*)&int2_status1, 1));
    *status = int2_status1.i3c_protocol_err;
    return 0;
}

int icm45686_get_int2_i2cm_done_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_STATUS1_t int2_status1;
    _ROE(_read_register(INT2_STATUS1, (uint8_t*)&int2_status1, 1));
    *status = int2_status1.i2cm_done;
    return 0;
}

int icm45686_get_int2_apex_event_status(struct icm45686_desc *desc, bool *status)
{
    if (desc == NULL || status == NULL) return 1;
    INT2_STATUS1_t int2_status1;
    _ROE(_read_register(INT2_STATUS1, (uint8_t*)&int2_status1, 1));
    *status = int2_status1.apex_event;
    return 0;
}