/* ==========================================================================
* Synopsys DesignWare Sensor and Control IP Subsystem IO Software Driver and
* documentation (hereinafter, "Software") is an Unsupported proprietary work
* of Synopsys, Inc. unless otherwise expressly agreed to in writing between
* Synopsys and you.
*
* The Software IS NOT an item of Licensed Software or Licensed Product under
* any End User Software License Agreement or Agreement for Licensed Product
* with Synopsys or any supplement thereto. You are permitted to use and
* redistribute this Software in source and binary forms, with or without
* modification, provided that redistributions of source code must retain this
* notice. You may not view, use, disclose, copy or distribute this file or
* any information contained herein except pursuant to this license grant from
* Synopsys. If you do not agree with this notice, including the disclaimer
* below, then you are not authorized to use the Software.
*
* THIS SOFTWARE IS BEING DISTRIBUTED BY SYNOPSYS SOLELY ON AN "AS IS" BASIS
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE HEREBY DISCLAIMED. IN NO EVENT SHALL SYNOPSYS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
* ========================================================================== */

/**
 * @file
 *
 * @brief Designware ADC header file
 */

#ifndef DW_ADC_H_
#define DW_ADC_H_

#include <stdint.h>
#include <adc.h>

/* EAI ADC device registers */
#define     ADC_SET         (0x00)
#define     ADC_DIVSEQSTAT  (0x01)
#define     ADC_SEQ         (0x02)
#define     ADC_CTRL        (0x03)
#define     ADC_INTSTAT     (0x04)
#define     ADC_SAMPLE      (0x05)

/* Additional device registers */
#define     MST_CTL         (0x00)
#define     SLV_OBSR        (0x00)

/*  Sensor Subsystem Interrupt Routing Mask */
#define INT_SS_ADC_ERR_MASK             (0x400)
#define INT_SS_ADC_IRQ_MASK             (0x404)

/* ADC Specific macros */
#define     ADC_POP_SAMPLE              (0x80000000)
#define     ADC_FLUSH_RX                (0x40000000)
#define     ADC_FTL_SET_MASK            (0x00ffffff)
#define     ADC_SEQ_SIZE_SET_MASK       (0x3fc0ffff)
#define     ADC_SEQ_MODE_SET_MASK       (0x3fffdfff)
#define     ADC_CONFIG_SET_MASK         (0x3fffe000)
#define     ADC_CLK_RATIO_MASK          (0x1fffff)
#define     ADC_CLR_UNDRFLOW            (1 << 18)
#define     ADC_CLR_OVERFLOW            (1 << 17)
#define     ADC_CLR_DATA_A              (1 << 16)
#define     ADC_SEQ_TABLE_RST           (0x0040)
#define     ADC_SEQ_PTR_RST             (0x0020)
#define     ADC_SEQ_START               (0x0010)
#define     ADC_SEQ_STOP_MASK           (0x078ec)
#define     ADC_INT_ENA_MASK            (0x001e)
#define     ADC_INT_DSB                 (0x0F00)
#define     ADC_INT_ENABLE              (0x0000)
#define     ADC_CLK_ENABLE              (0x0004)
#define     ADC_ENABLE                  (0x0002)
#define     ADC_DISABLE                 (0x0)
#define     ADC_RESET                   (0x1)
#define     ADC_INT_DATA_A              (0x1)
#define     ADC_INT_ERR                 (0x6)

#define ADC_STATE_CLOSED        0
#define ADC_STATE_DISABLED      1
#define ADC_STATE_IDLE          2
#define ADC_STATE_SAMPLING      3

/* ADC control commands */
#define IO_ADC0_FS (32)
#define IO_ADC0_SE (32)
#define IO_ADC0_INT_ERR (18)
#define IO_ADC0_INT_IRQ (19)

#define IO_ADC_SET_CLK_DIVIDER          (0x20)
#define IO_ADC_SET_CONFIG               (0x21)
#define IO_ADC_SET_SEQ_TABLE            (0x22)
#define IO_ADC_SET_SEQ_MODE             (0x23)
#define IO_ADC_SET_SEQ_STOP             (0x24)
#define IO_ADC_SET_RX_THRESHOLD         (0x25)

#define IO_ADC_INPUT_SINGLE_END       0
#define IO_ADC_INPUT_DIFF             1
#define IO_ADC_OUTPUT_PARAL           0
#define IO_ADC_OUTPUT_SERIAL          1
#define IO_ADC_CAPTURE_RISING_EDGE    0
#define IO_ADC_CAPTURE_FALLING_EDGE   1

#define IO_ADC_SEQ_MODE_SINGLESHOT    0
#define IO_ADC_SEQ_MODE_REPETITIVE    1

#define ENABLE_SSS_INTERRUPTS           ~(0x01 << 8)

/** mV = 3.3V*/
#define ADC_VREF 3300

/**
 *
 * @brief Converts ADC raw data into mV
 *
 * The ADC raw data readings are converted into mV:
 * result = (data * ADC_VREF) / (2^resolution).
 *
 * @param _data_ Raw data to be converted.
 * @param _resolution_ Resolution used during the data sampling.
 *
 * @return data read in mVolts.
 */
#define ss_adc_data_to_mv(_data_, _resolution_) \
	((_data_ * ADC_VREF) / (1 << _resolution_))

/**
 *
 * @brief ADC Initialization function.
 *
 * Inits device model for the ADC IP from Dataware.
 *
 * @param dev Pointer to the device structure descriptor that
 * will be initialized.
 *
 * @return Integer: 0 for success, error otherwise.
 */
int dw_adc_init(struct device *dev);

#endif  /*  DW_ADC_H_ */
