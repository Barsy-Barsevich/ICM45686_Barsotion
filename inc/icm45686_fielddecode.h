#pragma once

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdio.h>
#include "icm45686_regconst.h"

void icm45686_decode_ACCEL_MODE(enum ACCEL_MODE mode, FILE *stream, const char *tag);
void icm45686_decode_GYRO_MODE(enum GYRO_MODE mode, FILE *stream, const char *tag);
void icm45686_decode_INT_POLARITY(enum INT_POLARITY pol, FILE *stream, const char *tag);
void icm45686_decode_INT_MODE(enum INT_MODE mode, FILE *stream, const char *tag);
void icm45686_decode_INT_DRIVE(enum INT_DRIVE drive, FILE *stream, const char *tag);
void icm45686_decode_ACCEL_UI_FS_SEL(enum ACCEL_UI_FS_SEL scale, FILE *stream, const char *tag);
void icm45686_decode_ACCEL_ODR(enum ACCEL_ODR odr, FILE *stream, const char *tag);
void icm45686_decode_GYRO_UI_FS_SEL(enum GYRO_UI_FS_SEL scale, FILE *stream, const char *tag);
void icm45686_decode_GYRO_ODR(enum GYRO_ODR odr, FILE *stream, const char *tag);
void icm45686_decode_FIFO_MODE(enum FIFO_MODE mode, FILE *stream, const char *tag);
void icm45686_decode_FIFO_DEPTH(enum FIFO_DEPTH depth, FILE *stream, const char *tag);
void icm45686_decode_FIFO_WR_WM_GT_TH(enum FIFO_WR_WM_GT_TH cond, FILE *stream, const char *tag);
void icm45686_decode_FIFO_ES0_6B_9B(enum FIFO_ES0_6B_9B bytes, FILE *stream, const char *tag);
void icm45686_decode_FIFO_COMP_NC_FLOW_CFG(enum FIFO_COMP_NC_FLOW_CFG num, FILE *stream, const char *tag);
void icm45686_decode_WOM_INT_DUR(enum WOM_INT_DUR dur, FILE *stream, const char *tag);
void icm45686_decode_WOM_MODE(enum WOM_MODE mode, FILE *stream, const char *tag);
void icm45686_decode_TMST_RESOL(enum TMST_RESOL res, FILE *stream, const char *tag);
void icm45686_decode_AP_FSYNC_SEL(enum AP_FSYNC_SEL sel, FILE *stream, const char *tag);
void icm45686_decode_AP_FSYNC_FLAG_CLEAR_SEL(enum AP_FSYNC_FLAG_CLEAR_SEL sel, FILE *stream, const char *tag);
void icm45686_decode_AUX1_FSYNC_SEL(enum AUX1_FSYNC_SEL sel, FILE *stream, const char *tag);
void icm45686_decode_AUX1_FSYNC_FLAG_CLEAR_SEL(enum AUX1_FSYNC_FLAG_CLEAR_SEL sel, FILE *stream, const char *tag);
void icm45686_decode_APEX_ODR(enum APEX_ODR odr, FILE *stream, const char *tag);
void icm45686_decode_I2CM_EXT_ODR(enum I2CM_EXT_ODR odr, FILE *stream, const char *tag);
void icm45686_decode_ACCEL_FIFO_ODR_DEC(enum ACCEL_FIFO_ODR_DEC dec, FILE *stream, const char *tag);
void icm45686_decode_GYRO_FIFO_ODR_DEC(enum GYRO_FIFO_ODR_DEC dec, FILE *stream, const char *tag);
void icm45686_decode_AP_SPI_MODE(enum AP_SPI_MODE mode, FILE *stream, const char *tag);
void icm45686_decode_AP_SPI_34_MODE(enum AP_SPI_34_MODE mode, FILE *stream, const char *tag);
void icm45686_decode_AP_SPI_MODE_OVRD_VAL(enum AP_SPI_MODE_OVRD_VAL mode, FILE *stream, const char *tag);
void icm45686_decode_AP_SPI_34_MODE_OVRD_VAL(enum AP_SPI_34_MODE_OVRD_VAL mode, FILE *stream, const char *tag);
void icm45686_decode_AUX1_SPI_MODE(enum AUX1_SPI_MODE mode, FILE *stream, const char *tag);
void icm45686_decode_AUX1_SPI_34_MODE(enum AUX1_SPI_34_MODE mode, FILE *stream, const char *tag);
void icm45686_decode_PADS_SPI_SLEW(enum PADS_SPI_SLEW slew, FILE *stream, const char *tag);
void icm45686_decode_PADS_I2C_SLEW(enum PADS_I2C_SLEW slew, FILE *stream, const char *tag);
void icm45686_decode_PADS_I3C_SDR_SLEW(enum PADS_I3C_SDR_SLEW slew, FILE *stream, const char *tag);
void icm45686_decode_PADS_I3C_DDR_SLEW(enum PADS_I3C_DDR_SLEW slew, FILE *stream, const char *tag);
void icm45686_decode_PADS_SLEW(enum PADS_SLEW slew, FILE *stream, const char *tag);
void icm45686_decode_OSC_ID_OVRD(enum OSC_ID_OVRD osc, FILE *stream, const char *tag);
void icm45686_decode_ACCEL_AUX1_FS_SEL(enum ACCEL_AUX1_FS_SEL sel, FILE *stream, const char *tag);
void icm45686_decode_GYRO_AUX1_FS_SEL(enum GYRO_AUX1_FS_SEL sel, FILE *stream, const char *tag);

#if defined(__cplusplus)
}
#endif