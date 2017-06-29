#include <rtl-sdr.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


#define DEFAULT_BUF_NUMBER  15
#define DEFAULT_BUF_LENGTH  (16 * 32 * 512)

enum rtlsdr_async_status {
    RTLSDR_INACTIVE = 0,
    RTLSDR_CANCELING,
    RTLSDR_RUNNING
};

struct rtlsdr_dev {
//     libusb_context *ctx;
//     struct libusb_device_handle *devh;
    uint32_t xfer_buf_num;
    uint32_t xfer_buf_len;
//     struct libusb_transfer **xfer;
    unsigned char **xfer_buf;
    rtlsdr_read_async_cb_t cb;
    void *cb_ctx;
    enum rtlsdr_async_status async_status;
//     int async_cancel;
//     /* rtl demod context */
//     uint32_t rate; /* Hz */
//     uint32_t rtl_xtal; /* Hz */
//     int fir[FIR_LEN];
//     int direct_sampling;
//     /* tuner context */
//     enum rtlsdr_tuner tuner_type;
//     rtlsdr_tuner_iface_t *tuner;
//     uint32_t tun_xtal; /* Hz */
//     uint32_t freq; /* Hz */
//     uint32_t bw;
//     uint32_t offs_freq; /* Hz */
//     int corr; /* ppm */
//     int gain; /* tenth dB */
//     struct e4k_state e4k_s;
//     struct r82xx_config r82xx_c;
//     struct r82xx_priv r82xx_p;
//     /* status */
//     int dev_lost;
//     int driver_active;
//     unsigned int xfer_errors;
    uint32_t center_freq;
    uint32_t sample_rate;

    int num_gain_values;
    int *possible_gain_values;
};

uint32_t rtlsdr_get_device_count(void) {
    return 1;
}

static char *fake_name = "fakertl";

const char* rtlsdr_get_device_name(uint32_t index) {
    return fake_name;
}

int rtlsdr_get_device_usb_strings(
    uint32_t index,
    char *manufact,
    char *product,
    char *serial
) {
    strncpy(manufact, "FakeRTL", 8);
    strncpy(product, "FakeRTL", 8);
    strncpy(serial, "00000000", 9);
    return 0;
}

int rtlsdr_get_index_by_serial(const char *serial) {
    return 0;
}

int rtlsdr_open(rtlsdr_dev_t **out_dev, uint32_t index) {
    // TODO: fill out
    rtlsdr_dev_t *dev = NULL;
    dev = malloc(sizeof(rtlsdr_dev_t));
    if (NULL == dev)
        return -ENOMEM;

    *out_dev = dev;
    return 0;
}

int rtlsdr_close(rtlsdr_dev_t *dev) {
    return 0;
}

int rtlsdr_set_xtal_freq(rtlsdr_dev_t *dev, uint32_t rtl_freq,
                         uint32_t tuner_freq) {
    return 0;
}

int rtlsdr_get_xtal_freq(rtlsdr_dev_t *dev, uint32_t *rtl_freq,
                         uint32_t *tuner_freq) {
    *rtl_freq = 28800000;
    *tuner_freq = 28800000;
    return 0;
}

int rtlsdr_get_usb_strings(rtlsdr_dev_t *dev, char *manufact,
                           char *product, char *serial) {
    return rtlsdr_get_device_usb_strings(0, manufact, product, serial);
}

int rtlsdr_write_eeprom(rtlsdr_dev_t *dev, uint8_t *data,
                        uint8_t offset, uint16_t len) {
    return -3;
}

int rtlsdr_read_eeprom(rtlsdr_dev_t *dev, uint8_t *data,
                       uint8_t offset, uint16_t len) {
    return -3;
}

int rtlsdr_set_center_freq(rtlsdr_dev_t *dev, uint32_t freq) {
    // TODO implement
    dev->center_freq = freq;
    return 0;
}

int rtlsdr_set_if_freq(rtlsdr_dev_t *dev, uint32_t freq) {
    // TODO implement?
    return 0;
}

int rtlsdr_set_if_bandwidth(rtlsdr_dev_t *dev, int bw) {
    // TODO implement?
    return 0;
}

uint32_t rtlsdr_get_center_freq(rtlsdr_dev_t *dev) {
    return dev->center_freq;
}

int rtlsdr_set_freq_correction(rtlsdr_dev_t *dev, int ppm) {
    return 0;
}

int rtlsdr_get_freq_correction(rtlsdr_dev_t *dev) {
    return 0;
}

enum rtlsdr_tuner rtlsdr_get_tuner_type(rtlsdr_dev_t *dev) {
    return RTLSDR_TUNER_R820T;
}

int rtlsdr_get_tuner_gains(rtlsdr_dev_t *dev, int *gains) {
    if (gains == NULL) {
        return dev->num_gain_values;
    } else {
        for (int i=0; i<dev->num_gain_values; i++) {
            gains[i] = dev->possible_gain_values[i];
        }
        return dev->num_gain_values;
    }
}

int rtlsdr_set_tuner_gain(rtlsdr_dev_t *dev, int gain) {
    // TODO: implement
    return 0;
}

int rtlsdr_set_tuner_if_gain(rtlsdr_dev_t *dev, int stage, int gain) {
    // TODO: implement
    return 0;
}

int rtlsdr_set_tuner_gain_mode(rtlsdr_dev_t *dev, int manual) {
    // TODO: implement
    return 0;
}

int rtlsdr_set_sample_rate(rtlsdr_dev_t *dev, uint32_t rate) {
    // TODO: implement-
    dev->sample_rate = rate;
    return 0;
}

uint32_t rtlsdr_get_sample_rate(rtlsdr_dev_t *dev) {
    return dev->sample_rate;
}

int rtlsdr_set_testmode(rtlsdr_dev_t *dev, int on) {
    return -1;
}

int rtlsdr_set_agc_mode(rtlsdr_dev_t *dev, int on) {
    // TODO: implement
    return 0;
}

int rtlsdr_set_direct_sampling(rtlsdr_dev_t *dev, int on) {
    return -1;
}

int rtlsdr_get_direct_sampling(rtlsdr_dev_t *dev) {
    return -1;
}

int rtlsdr_set_offset_tuning(rtlsdr_dev_t *dev, int on) {
    // TODO: maybe implement
    return -1;
}

int rtlsdr_get_offset_tuning(rtlsdr_dev_t *dev) {
    return -1;
}

int rtlsdr_set_dithering(rtlsdr_dev_t *dev, int dither) {
    return -1;
}

int rtlsdr_reset_buffer(rtlsdr_dev_t *dev) {
    if (!dev) {
        return -1;
    }
    return 0;
}

int rtlsdr_read_sync(rtlsdr_dev_t *dev, void *buf, int len, int *n_read) {
    return -1;
}

int rtlsdr_wait_async(rtlsdr_dev_t *dev, rtlsdr_read_async_cb_t cb, void *ctx) {
    return -1;
}

static int _rtlsdr_alloc_async_buffers(rtlsdr_dev_t *dev)
{
    unsigned int i;

    if (!dev)
        return -1;

    if (!dev->xfer_buf) {
        dev->xfer_buf = malloc(dev->xfer_buf_num *
                       sizeof(unsigned char *));

        for(i = 0; i < dev->xfer_buf_num; ++i)
            dev->xfer_buf[i] = malloc(dev->xfer_buf_len);
    }

    return 0;
}

static int _rtlsdr_free_async_buffers(rtlsdr_dev_t *dev)
{
    unsigned int i;

    if (!dev)
        return -1;

    if (dev->xfer_buf) {
        for(i = 0; i < dev->xfer_buf_num; ++i) {
            if (dev->xfer_buf[i])
                free(dev->xfer_buf[i]);
        }

        free(dev->xfer_buf);
        dev->xfer_buf = NULL;
    }

    return 0;
}


int rtlsdr_read_async(rtlsdr_dev_t *dev,
                      rtlsdr_read_async_cb_t cb,
                      void *ctx,
                      uint32_t buf_num,
                      uint32_t buf_len) {
    // TODO: implement

    enum rtlsdr_async_status next_status = RTLSDR_INACTIVE;

    dev->async_status = RTLSDR_RUNNING;
    dev->cb = cb;
    dev->cb_ctx = ctx;

    if (buf_num > 0)
        dev->xfer_buf_num = buf_num;
    else
        dev->xfer_buf_num = DEFAULT_BUF_NUMBER;

    if (buf_len > 0 && buf_len % 512 == 0) /* len must be multiple of 512 */
        dev->xfer_buf_len = buf_len;
    else
        dev->xfer_buf_len = DEFAULT_BUF_LENGTH;

    _rtlsdr_alloc_async_buffers(dev);

    while (RTLSDR_INACTIVE != dev->async_status) {

        if (RTLSDR_CANCELING == dev->async_status) {
            next_status = RTLSDR_INACTIVE;
            break;
        }

        for(int i = 0; i < dev->xfer_buf_num; ++i) {
            dev->cb(dev->xfer_buf[i], dev->xfer_buf_len, dev->cb_ctx);
        }
    }

    _rtlsdr_free_async_buffers(dev);
    dev->async_status = next_status;

    return 0;
}

int rtlsdr_cancel_async(rtlsdr_dev_t *dev) {
    if (!dev)
        return -1;

    /* if streaming, try to cancel gracefully */
    if (RTLSDR_RUNNING == dev->async_status) {
        dev->async_status = RTLSDR_CANCELING;
        return 0;
    }
    return -2;
}
