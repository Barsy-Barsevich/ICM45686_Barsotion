#include "icm45686_fielddecode.h"

void icm45686_decode_accel_mode(enum ACCEL_MODE mode, FILE *stream, const char *tag)
{
    fprintf(stream, "%s accel mode: ", tag);
    switch (mode)
    {
        case ACCEL_MODE_OFF:
        case _ACCEL_MODE_OFF_2:
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
        case _GYRO_MODE_OFF_2:
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
    case _ACCEL_SCALE_RES1:
    case _ACCEL_SCALE_RES2:
    case _ACCEL_SCALE_RES3:
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
    case _ACCEL_ODR_RES1:
    case _ACCEL_ODR_RES2:
    case _ACCEL_ODR_RES3:
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
    case _GYRO_SCALE_RES1:
    case _GYRO_SCALE_RES2:
    case _GYRO_SCALE_RES3:
    case _GYRO_SCALE_RES4:
    case _GYRO_SCALE_RES5:
    case _GYRO_SCALE_RES6:
    case _GYRO_SCALE_RES7:
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
    case _GYRO_ODR_RES1:
    case _GYRO_ODR_RES2:
    case _GYRO_ODR_RES3:
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
    case _FIFO_MODE_RESERVED:
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

void icm45686_decode_fifo_ext_sensor0_bytes(enum FIFO_ES0_6B_9B bytes, FILE *stream, const char *tag)
{
    fprintf(stream, "%s fifo external sensor0 bytes: ", tag);
    switch (bytes)
    {
    case FIFO_ES0_6_BYTES:
        fprintf(stream, "6");
        break;
    case FIFO_ES0_9_BYTES:
        fprintf(stream, "9");
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)bytes);
        break;
    }
    fprintf(stream, "\n");
}

void icm45686_decode_FIFO_COMP_NC_FLOW_CFG(enum FIFO_COMP_NC_FLOW_CFG num, FILE *stream, const char *tag)
{
    fprintf(stream, "%s fifo non-compressed packet: ", tag);
    switch (num)
    {
    case NON_COMPRESSED_PACKET_FLOW_DIS:
        fprintf(stream, "disable");
        break;
    case NON_COMPRESSED_PACKET_EVERY_8_FRAMES:
        fprintf(stream, "every 8 frames");
        break;
    case NON_COMPRESSED_PACKET_EVERY_16_FRAMES:
        fprintf(stream, "every 16 frames");
        break;
    case NON_COMPRESSED_PACKET_EVERY_32_FRAMES:
        fprintf(stream, "every 32 frames");
        break;
    case NON_COMPRESSED_PACKET_EVERY_64_FRAMES:
        fprintf(stream, "every 64 frames");
        break;
    case NON_COMPRESSED_PACKET_EVERY_128_FRAMES:
        fprintf(stream, "every 128 frames");
        break;
    case _NON_COMPRESSED_PACKET_RES1:
    case _NON_COMPRESSED_PACKET_RES2:
        fprintf(stream, "reserved (0b%b)", num);
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)num);
        break;
    }
    fprintf(stream, "\n");
}

void icm45686_decode_WOM_INT_DUR(enum WOM_INT_DUR dur, FILE *stream, const char *tag)
{
    fprintf(stream, "%s WOM interrupt duration: ", tag);
    switch (dur)
    {
    case WOM_INT_DUR_FIRST_OVER_THS_EVNT:
        fprintf(stream, "First over threshold event");
        break;
    case WOM_INT_DUR_SECOND_OVER_THS_EVNT:
        fprintf(stream, "Second over threshold event");
        break;
    case WOM_INT_DUR_THIRD_OVER_THS_EVNT:
        fprintf(stream, "Third over threshold event");
        break;
    case WOM_INT_DUR_FOURTH_OVER_THS_EVNT:
        fprintf(stream, "Fourth over threshold event");
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)dur);
        break;
    }
    fprintf(stream, "\n");
}

void icm45686_decode_WOM_MODE(enum WOM_MODE mode, FILE *stream, const char *tag)
{
    fprintf(stream, "%s WOM mode: ", tag);
    switch (mode)
    {
    case WOM_MODE_INITIAL_SAMPLE_IS_STORED:
        fprintf(stream, "Initial sample is stored");
        break;
    case WOM_MODE_COMPARE_CUR_TO_PREV:
        fprintf(stream, "Compare current sample & previous and store greater");
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)mode);
        break;
    }
    fprintf(stream, "\n");
}

void icm45686_decode_TMST_RESOL(enum TMST_RESOL res, FILE *stream, const char *tag)
{
    fprintf(stream, "%s TMST resolution: ", tag);
    switch (res)
    {
    case TMST_RESOL_1US:
        fprintf(stream, "1us");
        break;
    case TMST_RESOL_16US:
        fprintf(stream, "16us");
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)res);
        break;
    }
    fprintf(stream, "\n");
}

void icm45686_decode_AP_FSYNC_SEL(enum AP_FSYNC_SEL sel, FILE *stream, const char *tag)
{
    fprintf(stream, "%s AP/UI FSYNC tag select: ", tag);
    switch (sel)
    {
    case APUI_FSYNC_TAG_DISABLED:
        fprintf(stream, "Disabled");
        break;
    case APUI_FSYNC_TAG_TO_TEMP_DATA_UI_LSB:
        fprintf(stream, "TEMP_DATA_UI_LSB");
        break;
    case APUI_FSYNC_TAG_TO_GYRO_DATA_X_UI_LSB:
        fprintf(stream, "GYRO_DATA_X_UI_LSB");
        break;
    case APUI_FSYNC_TAG_TO_GYRO_DATA_Y_UI_LSB:
        fprintf(stream, "GYRO_DATA_Y_UI_LSB");
        break;
    case APUI_FSYNC_TAG_TO_GYRO_DATA_Z_UI_LSB:
        fprintf(stream, "GYRO_DATA_Z_UI_LSB");
        break;
    case APUI_FSYNC_TAG_TO_ACCEL_DATA_X_UI_LSB:
        fprintf(stream, "ACCEL_DATA_X_UI_LSB");
        break;
    case APUI_FSYNC_TAG_TO_ACCEL_DATA_Y_UI_LSB:
        fprintf(stream, "ACCEL_DATA_Y_UI_LSB");
        break;
    case APUI_FSYNC_TAG_TO_ACCEL_DATA_Z_UI_LSB:
        fprintf(stream, "ACCEL_DATA_Z_UI_LSB");
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)sel);
        break;
    }
    fprintf(stream, "\n");
}

void icm45686_decode_AP_FSYNC_FLAG_CLEAR_SEL(enum AP_FSYNC_FLAG_CLEAR_SEL sel, FILE *stream, const char *tag)
{
    fprintf(stream, "%s AP/UI FSYNC flag clear: ", tag);
    switch (sel)
    {
    case APUI_FSYNC_CLEAR_ON_REGISTER_UPDATE:
        fprintf(stream, "On register update");
        break;
    case APUI_FSYNC_CLEAR_ON_REGISTER_READ:
        fprintf(stream, "On register read");
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)sel);
        break;
    }
    fprintf(stream, "\n");
}

void icm45686_decode_AUX1_FSYNC_SEL(enum AUX1_FSYNC_SEL sel, FILE *stream, const char *tag)
{
    fprintf(stream, "%s AUX1 FSYNC tag select: ", tag);
    switch (sel)
    {
    case AUX1_FSYNC_TAG_DISABLED:
        fprintf(stream, "Disabled");
        break;
    case AUX1_FSYNC_TAG_TO_TEMP_DATA_AUX1_LSB:
        fprintf(stream, "TEMP_DATA_AUX1_LSB");
        break;
    case AUX1_FSYNC_TAG_TO_GYRO_DATA_X_AUX1_LSB:
        fprintf(stream, "GYRO_DATA_X_AUX1_LSB");
        break;
    case AUX1_FSYNC_TAG_TO_GYRO_DATA_Y_AUX1_LSB:
        fprintf(stream, "GYRO_DATA_Y_AUX1_LSB");
        break;
    case AUX1_FSYNC_TAG_TO_GYRO_DATA_Z_AUX1_LSB:
        fprintf(stream, "GYRO_DATA_Z_AUX1_LSB");
        break;
    case AUX1_FSYNC_TAG_TO_ACCEL_DATA_X_AUX1_LSB:
        fprintf(stream, "ACCEL_DATA_X_AUX1_LSB");
        break;
    case AUX1_FSYNC_TAG_TO_ACCEL_DATA_Y_AUX1_LSB:
        fprintf(stream, "ACCEL_DATA_Y_AUX1_LSB");
        break;
    case AUX1_FSYNC_TAG_TO_ACCEL_DATA_Z_AUX1_LSB:
        fprintf(stream, "ACCEL_DATA_Z_AUX1_LSB");
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)sel);
        break;
    }
    fprintf(stream, "\n");
}

void icm45686_decode_AUX1_FSYNC_FLAG_CLEAR_SEL(enum AUX1_FSYNC_FLAG_CLEAR_SEL sel, FILE *stream, const char *tag)
{
    fprintf(stream, "%s AUX1 FSYNC flag clear: ", tag);
    switch (sel)
    {
    case AUX1_FSYNC_CLEAR_ON_REGISTER_UPDATE:
        fprintf(stream, "On register update");
        break;
    case AUX1_FSYNC_CLEAR_ON_REGISTER_READ:
        fprintf(stream, "On register read");
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)sel);
        break;
    }
    fprintf(stream, "\n");
}

void icm45686_decode_APEX_ODR(enum APEX_ODR odr, FILE *stream, const char *tag)
{
    fprintf(stream, "%s APEX ODR: ", tag);
    switch (odr)
    {
    case APEX_ODR_25HZ:
        fprintf(stream, "25Hz");
        break;
    case APEX_ODR_50HZ:
        fprintf(stream, "50Hz");
        break;
    case APEX_ODR_100HZ:
        fprintf(stream, "100Hz");
        break;
    case APEX_ODR_200HZ:
        fprintf(stream, "200Hz");
        break;
    case APEX_ODR_400HZ:
        fprintf(stream, "400Hz");
        break;
    case APEX_ODR_800HZ:
        fprintf(stream, "800Hz");
        break;
    case _APEX_ODR_RES1:
    case _APEX_ODR_RES2:
        fprintf(stream, "reserved (0b%b)", (int)odr);
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)odr);
        break;
    }
    fprintf(stream, "\n");
}

void icm45686_decode_I2CM_EXT_ODR(enum I2CM_EXT_ODR odr, FILE *stream, const char *tag)
{
    fprintf(stream, "%s I2CM external sensor ODR: ", tag);
    switch (odr)
    {
    case I2CM_EXT_ODR_3P125HZ:
        fprintf(stream, "3.125Hz");
        break;
    case I2CM_EXT_ODR_6P25HZ:
        fprintf(stream, "6.25Hz");
        break;
    case I2CM_EXT_ODR_12P5HZ:
        fprintf(stream, "12.5Hz");
        break;
    case I2CM_EXT_ODR_25HZ:
        fprintf(stream, "25Hz");
        break;
    case I2CM_EXT_ODR_50HZ:
        fprintf(stream, "50Hz");
        break;
    case I2CM_EXT_ODR_100HZ:
        fprintf(stream, "100Hz");
        break;
    case I2CM_EXT_ODR_200HZ:
        fprintf(stream, "200Hz");
        break;
    case I2CM_EXT_ODR_400HZ:
        fprintf(stream, "400Hz");
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)odr);
        break;
    }
    fprintf(stream, "\n");
}

void icm45686_decode_ACCEL_FIFO_ODR_DEC(enum ACCEL_FIFO_ODR_DEC dec, FILE *stream, const char *tag)
{
    fprintf(stream, "%s Accel FIFO ODR decimation: ", tag);
    switch (dec)
    {
    case ACCEL_FIFO_ODR_DEC_1:
        fprintf(stream, "1 (disabled)");
        break;
    case ACCEL_FIFO_ODR_DEC_2:
        fprintf(stream, "2");
        break;
    case ACCEL_FIFO_ODR_DEC_4:
        fprintf(stream, "4");
        break;
    case ACCEL_FIFO_ODR_DEC_8:
        fprintf(stream, "8");
        break;
    case ACCEL_FIFO_ODR_DEC_16:
        fprintf(stream, "16");
        break;
    case ACCEL_FIFO_ODR_DEC_32:
        fprintf(stream, "32");
        break;
    case ACCEL_FIFO_ODR_DEC_64:
        fprintf(stream, "64");
        break;
    case ACCEL_FIFO_ODR_DEC_128:
        fprintf(stream, "128");
        break;
    case ACCEL_FIFO_ODR_DEC_256:
        fprintf(stream, "256");
        break;
    case ACCEL_FIFO_ODR_DEC_512:
        fprintf(stream, "512");
        break;
    case ACCEL_FIFO_ODR_DEC_1024:
        fprintf(stream, "1024");
        break;
    case ACCEL_FIFO_ODR_DEC_2048:
        fprintf(stream, "2048");
        break;
    case ACCEL_FIFO_ODR_DEC_4096:
        fprintf(stream, "4096");
        break;
    case _ACCEL_FIFO_ODR_DEC_RES1:
    case _ACCEL_FIFO_ODR_DEC_RES2:
    case _ACCEL_FIFO_ODR_DEC_RES3:
        fprintf(stream, "reserved (0b%b)", (int)dec);
        break;
    default:
        fprintf(stream, "unexpected error (0b%b)", (int)dec);
        break;
    }
    fprintf(stream, "\n");
}