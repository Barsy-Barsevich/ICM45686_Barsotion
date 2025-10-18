#pragma once

#include <stdio.h>
#include "icm45686_regconst.h"

void icm45686_decode_accel_mode(enum ACCEL_MODE mode, FILE *stream, const char *tag);
void icm45686_decode_gyro_mode(enum GYRO_MODE mode, FILE *stream, const char *tag);
void icm45686_decode_int_polarity(enum INT_POLARITY pol, FILE *stream, const char *tag);
void icm45686_decode_int_mode(enum INT_MODE mode, FILE *stream, const char *tag);
void icm45686_decode_int_drive(enum INT_DRIVE drive, FILE *stream, const char *tag);
void icm45686_decode_accel_scale(enum ACCEL_UI_FS_SEL, FILE *stream, const char *tag);
void icm45686_decode_accel_odr(enum ACCEL_ODR, FILE *stream, const char *tag);
void icm45686_decode_gyro_scale(enum GYRO_UI_FS_SEL, FILE *stream, const char *tag);
void icm45686_decode_gyro_odr(enum GYRO_ODR, FILE *stream, const char *tag);
void icm45686_decode_fifo_mode(enum FIFO_MODE, FILE *stream, const char *tag);
void icm45686_decode_fifo_depth(enum FIFO_DEPTH, FILE *stream, const char *tag);
