#include "icm45686_fielddecode.h"

void icm45686_decode_accel_mode(enum ACCEL_MODE mode, FILE *stream, const char *tag)
{
    fprintf(stream, "%s accel mode: ", tag);
    switch (mode)
    {
        case ACCEL_MODE_OFF:
        case ACCEL_MODE_OFF_2:
            fprintf(stream, "off (0b%02b)", (int)mode);
            break;
        case ACCEL_MODE_LP:
            fprintf(stream, "LP (low power)");
            break;
        case ACCEL_MODE_LN:
            fprintf(stream, "LN (low noise)");
            break;
        default:
            fprintf("unexpected error (0b%b)", (int)mode);
    }
    fprintf(stream, "\n");
}

void icm45686_decode_gyro_mode(enum GYRO_MODE mode, FILE *stream, const char *tag)
{
    fprintf(stream, "%s gyro mode: ", tag);
    switch (mode)
    {
        case GYRO_MODE_OFF:
        case GYRO_MODE_OFF_2:
            fprintf(stream, "off (0b%02b)", (int)mode);
            break;
        case GYRO_MODE_LP:
            fprintf(stream, "LP (low power)");
            break;
        case GYRO_MODE_LN:
            fprintf(stream, "LN (low noise)");
            break;
        default:
            fprintf("unexpected error (0b%b)", (int)mode);
    }
    fprintf(stream, "\n");
}

void icm45686_decode_int_polarity(enum INT_POLARITY pol, FILE *stream, const char *tag)
{
    fprintf(stream, "%s int polarity: ", tag);
    switch (pol)
    {
    case INT_POLARITY_ACTIVE_LOW:
        fprintf(stream, "active LOW");
        break;
    case INT_POLARITY_ACTIVE_HIGH:
        fprintf(stream, "active HIGH");
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)pol);
        break;
    }
    fprintf(stream, "\n");
}

void icm45686_decode_int_mode(enum INT_MODE mode, FILE *stream, const char *tag)
{
    fprintf(stream, "%s int mode: ", tag);
    switch (mode)
    {
    case INT_MODE_LATCH:
        fprintf(stream, "Latch");
        break;
    case INT_MODE_PULSE:
        fprintf(stream, "Pulse");
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)mode);
        break;
    }
    fprintf(stream, "\n");
}

void icm45686_decode_int_drive(enum INT_DRIVE drive, FILE *stream, const char *tag)
{
    fprintf(stream, "%s int drive: ", tag);
    switch (drive)
    {
    case INT_DRIVE_PUSH_PULL:
        fprintf(stream, "Push-Pull");
        break;
    case INT_DRIVE_OPEN_DRAIN:
        fprintf(stream, "Open Drain");
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)drive);
        break;
    }
    fprintf(stream, "\n");
}

void icm45686_decode_accel_scale(enum ACCEL_UI_FS_SEL scale, FILE *stream, const char *tag)
{
    fprintf(stream, "%s accel scale: ", tag);
    switch (scale)
    {
    case ACCEL_SCALE_32G:
        fprintf(stream, "32g");
        break;
    case ACCEL_SCALE_16G:
        fprintf(stream, "16g");
        break;
    case ACCEL_SCALE_8G:
        fprintf(stream, "8g");
        break;
    case ACCEL_SCALE_4G:
        fprintf(stream, "4g");
        break;
    case ACCEL_SCALE_2G:
        fprintf(stream, "2g");
        break;
    case ACCEL_SCALE_RES1:
    case ACCEL_SCALE_RES2:
    case ACCEL_SCALE_RES3:
        fprintf(stream, "reserved (0b%03b)", (int)scale);
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)scale);
        break;
    }
    fprintf(stream, "\n");
}

void icm45686_decode_accel_odr(enum ACCEL_ODR odr, FILE *stream, const char *tag)
{
    fprintf(stream, "%s accel odr: ", tag);
    switch (odr)
    {
    case ACCEL_ODR_RES1:
    case ACCEL_ODR_RES2:
    case ACCEL_ODR_RES3:
        fprintf(stream, "reserved (0b%03b)", (int)odr);
        break;
    case ACCEL_ODR_6400HZ:
        fprintf(stream, "6400Hz");
        break;
    case ACCEL_ODR_3200HZ:
        fprintf(stream, "3200Hz");
        break;
    case ACCEL_ODR_1600HZ:
        fprintf(stream, "1600Hz");
        break;
    case ACCEL_ODR_800HZ:
        fprintf(stream, "800Hz");
        break;
    case ACCEL_ODR_400HZ:
        fprintf(stream, "400Hz");
        break;
    case ACCEL_ODR_200HZ:
        fprintf(stream, "200Hz");
        break;
    case ACCEL_ODR_100HZ:
        fprintf(stream, "100Hz");
        break;
    case ACCEL_ODR_50HZ:
        fprintf(stream, "50Hz");
        break;
    case ACCEL_ODR_25HZ:
        fprintf(stream, "25Hz");
        break;
    case ACCEL_ODR_12P5HZ:
        fprintf(stream, "12.5Hz");
        break;
    case ACCEL_ODR_6P25HZ:
        fprintf(stream, "6.25Hz");
        break;
    case ACCEL_ODR_3P125HZ:
        fprintf(stream, "3.125Hz");
        break;
    case ACCEL_ODR_1P5625HZ:
        fprintf(stream, "1.5625Hz");
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)odr);
        break;
    }
    fprintf(stream, "\n");
}

void icm45686_decode_gyro_scale(enum GYRO_UI_FS_SEL scale, FILE *stream, const char *tag)
{
    fprintf(stream, "%s gyro scale: ", tag);
    switch (scale)
    {
    case GYRO_SCALE_4000DPS:
        fprintf(stream, "4000 dps");
        break;
    case GYRO_SCALE_2000DPS:
        fprintf(stream, "4000 dps");
        break;
    case GYRO_SCALE_1000DPS:
        fprintf(stream, "4000 dps");
        break;
    case GYRO_SCALE_500DPS:
        fprintf(stream, "4000 dps");
        break;
    case GYRO_SCALE_250DPS:
        fprintf(stream, "4000 dps");
        break;
    case GYRO_SCALE_125DPS:
        fprintf(stream, "4000 dps");
        break;
    case GYRO_SCALE_62P5DPS:
        fprintf(stream, "4000 dps");
        break;
    case GYRO_SCALE_31P25DPS:
        fprintf(stream, "4000 dps");
        break;
    case GYRO_SCALE_15P625DPS:
        fprintf(stream, "4000 dps");
        break;
    case GYRO_SCALE_RES1:
    case GYRO_SCALE_RES2:
    case GYRO_SCALE_RES3:
    case GYRO_SCALE_RES4:
    case GYRO_SCALE_RES5:
    case GYRO_SCALE_RES6:
    case GYRO_SCALE_RES7:
        fprintf(stream, "reserved (0b%04b)", (int)scale);
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)scale);
        break;
    }
    fprintf(stream, "\n");
}

void icm45686_decode_gyro_odr(enum GYRO_ODR odr, FILE *stream, const char *tag)
{
    fprintf(stream, "%s gyro odr: ", tag);
    switch (odr)
    {
    case GYRO_ODR_RES1:
    case GYRO_ODR_RES2:
    case GYRO_ODR_RES3:
        fprintf(stream, "reserved (0b%04b)", (int)odr);
        break;
    case GYRO_ODR_6400HZ:
        fprintf(stream, "6400Hz");
        break;
    case GYRO_ODR_3200HZ:
        fprintf(stream, "3200Hz");
        break;
    case GYRO_ODR_1600HZ:
        fprintf(stream, "1600Hz");
        break;
    case GYRO_ODR_800HZ:
        fprintf(stream, "800Hz");
        break;
    case GYRO_ODR_400HZ:
        fprintf(stream, "400Hz");
        break;
    case GYRO_ODR_200HZ:
        fprintf(stream, "200Hz");
        break;
    case GYRO_ODR_100HZ:
        fprintf(stream, "100Hz");
        break;
    case GYRO_ODR_50HZ:
        fprintf(stream, "50Hz");
        break;
    case GYRO_ODR_25HZ:
        fprintf(stream, "25Hz");
        break;
    case GYRO_ODR_12P5HZ:
        fprintf(stream, "12.5Hz");
        break;
    case GYRO_ODR_6P25HZ:
        fprintf(stream, "6.25Hz");
        break;
    case GYRO_ODR_3P125HZ:
        fprintf(stream, "3.125Hz");
        break;
    case GYRO_ODR_1P5625HZ:
        fprintf(stream, "1.5625Hz");
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)odr);
        break;
    }
    fprintf(stream, "\n");
}

void icm45686_decode_fifo_mode(enum FIFO_MODE mode, FILE *stream, const char *tag)
{
    fprintf(stream, "%s fifo mode: ", tag);
    switch (mode)
    {
    case FIFO_MODE_BYPASS:
        fprintf(stream, "Bypass");
        break;
    case FIFO_MODE_STREAM:
        fprintf(stream, "Stream");
        break;
    case FIFO_MODE_STOP_ON_FULL:
        fprintf(stream, "Stop-On-Full");
        break;
    case FIFO_MODE_RESERVED:
        fprintf(stream, "reserved");
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)mode);
        break;
    }
    fprintf(stream, "\n");
}

void icm45686_decode_fifo_depth(enum FIFO_DEPTH depth, FILE *stream, const char *tag)
{
    fprintf(stream, "%s fifo depth: ", tag);
    switch (depth)
    {
    case FIFO_DEPTH_2K:
        fprintf(stream, "2KiB");
        break;
    case FIFO_DEPTH_8K:
        fprintf(stream, "8KiB");
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)depth);
        break;
    }
    fprintf(stream, "\n");
}

void icm45686_decode_fifo_wr_wm_gt_th(enum FIFO_WR_WM_GT_TH cond, FILE *stream, const char *tag)
{
    fprintf(stream, "%s fifo write watermark interrupt generating condition: ", tag);
    switch (cond)
    {
    case FIFO_WM_INT_IF_EQUAL:
        fprintf(stream, "FIFO data count is equal to FIFO WM threshold");
        break;
    case FIFO_WM_INT_IF_GREATER_OR_EQUAL:
        fprintf(stream, "FIFO data count is greater or equal to FIFO WM threshold");
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)cond);
        break;
    }
    fprintf(stream, "\n");
}
