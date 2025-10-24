#pragma once

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>
#include "icm45686_regconst.h"
#include "icm45686_types.h"

int icm45686_set_accel_mode(struct icm45686_desc *desc, const enum ACCEL_MODE mode);
int icm45686_get_accel_mode(struct icm45686_desc *desc, enum ACCEL_MODE *mode);
int icm45686_set_gyro_mode(struct icm45686_desc *desc, const enum GYRO_MODE mode);
int icm45686_get_gyro_mode(struct icm45686_desc *desc, enum GYRO_MODE *mode);
int icm45686_set_int1_enable(struct icm45686_desc *desc, struct icm45686_interrupt *cfg);
int icm45686_get_int1_enable(struct icm45686_desc *desc, struct icm45686_interrupt *cfg);
int icm45686_set_int1_fifo_full_enable(struct icm45686_desc *desc);
int icm45686_set_int1_fifo_full_disable(struct icm45686_desc *desc);
int icm45686_get_int1_fifo_full_enable_status(struct icm45686_desc *desc, bool *status);
int icm45686_set_int1_fifo_ths_enable(struct icm45686_desc *desc);
int icm45686_set_int1_fifo_ths_disable(struct icm45686_desc *desc);
int icm45686_get_int1_fifo_ths_enable_status(struct icm45686_desc *desc, bool *status);
int icm45686_set_int1_ap_drdy_enable(struct icm45686_desc *desc);
int icm45686_set_int1_ap_drdy_disable(struct icm45686_desc *desc);
int icm45686_get_int1_ap_drdy_enable_status(struct icm45686_desc *desc, bool *status);
int icm45686_set_int1_aux1_drdy_enable(struct icm45686_desc *desc);
int icm45686_set_int1_aux1_drdy_disable(struct icm45686_desc *desc);
int icm45686_get_int1_aux1_drdy_enable_status(struct icm45686_desc *desc, bool *status);
int icm45686_set_int1_ap_fsync_enable(struct icm45686_desc *desc);
int icm45686_set_int1_ap_fsync_disable(struct icm45686_desc *desc);
int icm45686_get_int1_ap_fsync_enable_status(struct icm45686_desc *desc, bool *status);
int icm45686_set_int1_ap_agc_rdy_enable(struct icm45686_desc *desc);
int icm45686_set_int1_ap_agc_rdy_disable(struct icm45686_desc *desc);
int icm45686_get_int1_ap_agc_rdy_enable_status(struct icm45686_desc *desc, bool *status);
int icm45686_set_int1_aux1_agc_rdy_enable(struct icm45686_desc *desc);
int icm45686_set_int1_aux1_agc_rdy_disable(struct icm45686_desc *desc);
int icm45686_get_int1_aux1_agc_rdy_enable_status(struct icm45686_desc *desc, bool *status);
int icm45686_set_int1_reset_done_enable(struct icm45686_desc *desc);
int icm45686_set_int1_reset_done_disable(struct icm45686_desc *desc);
int icm45686_get_int1_reset_done_enable_status(struct icm45686_desc *desc, bool *status);
int icm45686_set_int1_pll_rdy_enable(struct icm45686_desc *desc);
int icm45686_set_int1_pll_rdy_disable(struct icm45686_desc *desc);
int icm45686_get_int1_pll_rdy_enable_status(struct icm45686_desc *desc, bool *status);
int icm45686_set_int1_wom_x_enable(struct icm45686_desc *desc);
int icm45686_set_int1_wom_x_disable(struct icm45686_desc *desc);
int icm45686_get_int1_wom_x_enable_status(struct icm45686_desc *desc, bool *status);
int icm45686_set_int1_wom_y_enable(struct icm45686_desc *desc);
int icm45686_set_int1_wom_y_disable(struct icm45686_desc *desc);
int icm45686_get_int1_wom_y_enable_status(struct icm45686_desc *desc, bool *status);
int icm45686_set_int1_wom_z_enable(struct icm45686_desc *desc);
int icm45686_set_int1_wom_z_disable(struct icm45686_desc *desc);
int icm45686_get_int1_wom_z_enable_status(struct icm45686_desc *desc, bool *status);
int icm45686_set_int1_i3c_protocol_err_enable(struct icm45686_desc *desc);
int icm45686_set_int1_i3c_protocol_err_disable(struct icm45686_desc *desc);
int icm45686_get_int1_i3c_protocol_err_enable_status(struct icm45686_desc *desc, bool *status);
int icm45686_set_int1_i2cm_done_enable(struct icm45686_desc *desc);
int icm45686_set_int1_i2cm_done_disable(struct icm45686_desc *desc);
int icm45686_get_int1_i2cm_done_enable_status(struct icm45686_desc *desc, bool *status);
int icm45686_set_int1_apex_event_enable(struct icm45686_desc *desc);
int icm45686_set_int1_apex_event_disable(struct icm45686_desc *desc);
int icm45686_get_int1_apex_event_enable_status(struct icm45686_desc *desc, bool *status);
int icm45686_set_int1_polarity(struct icm45686_desc *desc, const enum INT_POLARITY pol);
int icm45686_get_int1_polarity(struct icm45686_desc *desc, enum INT_POLARITY *pol);
int icm45686_set_int1_mode(struct icm45686_desc *desc, const enum INT_MODE mode);
int icm45686_get_int1_mode(struct icm45686_desc *desc, enum INT_MODE *mode);
int icm45686_set_int1_drive(struct icm45686_desc *desc, const enum INT_DRIVE drive);
int icm45686_get_int1_drive(struct icm45686_desc *desc, enum INT_DRIVE *drive);
int icm45686_get_int1_status(struct icm45686_desc *desc, struct icm45686_interrupt *status);
int icm45686_get_int1_fifo_full_status(struct icm45686_desc *desc, bool *status);
int icm45686_get_int1_fifo_ths_status(struct icm45686_desc *desc, bool *status);
int icm45686_get_int1_ap_drdy_status(struct icm45686_desc *desc, bool *status);
int icm45686_get_int1_aux1_drdy_status(struct icm45686_desc *desc, bool *status);
int icm45686_get_int1_ap_fsync_status(struct icm45686_desc *desc, bool *status);
int icm45686_get_int1_ap_agc_rdy_status(struct icm45686_desc *desc, bool *status);
int icm45686_get_int1_aux1_agc_rdy_status(struct icm45686_desc *desc, bool *status);
int icm45686_get_int1_reset_done_status(struct icm45686_desc *desc, bool *status);
int icm45686_get_int1_pll_rdy_status(struct icm45686_desc *desc, bool *status);
int icm45686_get_int1_wom_x_status(struct icm45686_desc *desc, bool *status);
int icm45686_get_int1_wom_y_status(struct icm45686_desc *desc, bool *status);
int icm45686_get_int1_wom_z_status(struct icm45686_desc *desc, bool *status);
int icm45686_get_int1_i3c_protocol_err_status(struct icm45686_desc *desc, bool *status);
int icm45686_get_int1_i2cm_done_status(struct icm45686_desc *desc, bool *status);
int icm45686_get_int1_apex_event_status(struct icm45686_desc *desc, bool *status);
int icm45686_set_ap_accel_scale(struct icm45686_desc *desc, const enum ACCEL_UI_FS_SEL scale);
int icm45686_get_ap_accel_scale(struct icm45686_desc *desc, enum ACCEL_UI_FS_SEL *scale);
int icm45686_set_ap_accel_odr(struct icm45686_desc *desc, const enum ACCEL_ODR odr);
int icm45686_get_ap_accel_odr(struct icm45686_desc *desc, enum ACCEL_ODR *odr);
int icm45686_set_ap_gyro_scale(struct icm45686_desc *desc, const enum GYRO_UI_FS_SEL scale);
int icm45686_get_ap_gyro_scale(struct icm45686_desc *desc, enum GYRO_UI_FS_SEL *scale);
int icm45686_set_ap_gyro_odr(struct icm45686_desc *desc, const enum GYRO_ODR odr);
int icm45686_get_ap_gyro_odr(struct icm45686_desc *desc, enum GYRO_ODR *odr);
int icm45686_set_fifo_depth(struct icm45686_desc *desc, const enum FIFO_DEPTH depth);
int icm45686_get_fifo_depth(struct icm45686_desc *desc, enum FIFO_DEPTH *depth);
int icm45686_set_fifo_mode(struct icm45686_desc *desc, const enum FIFO_MODE mode);
int icm45686_get_fifo_mode(struct icm45686_desc *desc, enum FIFO_MODE *mode);
int icm45686_set_fifo_watermark(struct icm45686_desc *desc, uint16_t watermark);
int icm45686_get_fifo_watermark(struct icm45686_desc *desc, uint16_t *watermark);
int icm45686_fifo_flush(struct icm45686_desc *desc);
int icm45686_set_fifo_watermark_mode(struct icm45686_desc *desc, enum FIFO_WR_WM_GT_TH mode);
int icm45686_get_fifo_watermark_mode(struct icm45686_desc *desc, enum FIFO_WR_WM_GT_TH *mode);


#if defined(__cplusplus)
}
#endif