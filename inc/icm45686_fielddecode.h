#pragma once

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdio.h>
#include "icm45686_regconst.h"

void icm45686_decode_accel_mode(enum ACCEL_MODE mode, FILE *stream, const char *tag);
void icm45686_decode_gyro_mode(enum GYRO_MODE mode, FILE *stream, const char *tag);
void icm45686_decode_int_polarity(enum INT_POLARITY pol, FILE *stream, const char *tag);
void icm45686_decode_int_mode(enum INT_MODE mode, FILE *stream, const char *tag);
void icm45686_decode_int_drive(enum INT_DRIVE drive, FILE *stream, const char *tag);
void icm45686_decode_accel_scale(enum ACCEL_UI_FS_SEL scale, FILE *stream, const char *tag);
void icm45686_decode_accel_odr(enum ACCEL_ODR odr, FILE *stream, const char *tag);
void icm45686_decode_gyro_scale(enum GYRO_UI_FS_SEL scale, FILE *stream, const char *tag);
void icm45686_decode_gyro_odr(enum GYRO_ODR odr, FILE *stream, const char *tag);
void icm45686_decode_fifo_mode(enum FIFO_MODE mode, FILE *stream, const char *tag);
void icm45686_decode_fifo_depth(enum FIFO_DEPTH depth, FILE *stream, const char *tag);
void icm45686_decode_fifo_wr_wm_gt_th(enum FIFO_WR_WM_GT_TH cond, FILE *stream, const char *tag);

#if defined(__cplusplus)
}
#endif