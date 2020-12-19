/**
 * @file   idtp9220.h
 * @author  <roy@ROY-PC>
 * @date   Sun Nov 22 11:49:55 2015
 *
 * @brief
 *
 *
 */
#ifndef __IDTP9220_H__
#define __IDTP9220_H__

#include <linux/types.h>
#include <linux/device.h>
#include <linux/workqueue.h>
#include "idtp9415_fw.h"
#define IDT_DRIVER_NAME      "idtp9415"
#define IDT_I2C_ADDR         0x61

#define HSCLK                60000

#define ADJUST_METE_MV       35
#define IDTP9220_DELAY       2000
#define CHARGING_FULL        100
#define CHARGING_NEED        95

/* status low regiter bits define */
#define STATUS_VOUT_ON       (1 << 7)
#define STATUS_VOUT_OFF      (1 << 6)
#define STATUS_TX_DATA_RECV  (1 << 4)
#define STATUS_OV_TEMP       (1 << 2)
#define STATUS_OV_VOL        (1 << 1)
#define STATUS_OV_CURR       (1 << 0)

#define OVER_EVENT_OCCUR     (STATUS_OV_TEMP | STATUS_OV_VOL | STATUS_OV_CURR)
#define TOGGLE_LDO_ON_OFF    (1 << 1)

/* interrupt register bits define */
#define INT_RPP_READ      (1 << 17)
#define INT_EXT5V_FAIL    (1 << 16)
#define INT_VSWITCH_FAIL  (1 << 15)
#define INT_SLEEPMODE     (1 << 14)
#define INT_IDAUTH_SUCESS (1 << 13)
#define INT_IDAUTH_FAIL   (1 << 12)
#define INT_SEND_SUCESS   (1 << 11)
#define INT_SEND_TIMEOUT  (1 << 10)
#define INT_AUTH_SUCESS   (1 << 9)
#define INT_AUTH_FAIL     (1 << 8)
#define INT_VOUT_OFF      (1 << 7)
#define INT_VOUT_ON       (1 << 6)
#define INT_MODE_CHANGE   (1 << 5)
#define INT_TX_DATA_RECV  (1 << 4)
#define INT_VSWITCH_SUCESS  (1 << 3)
#define INT_OV_TEMP       (1 << 2)
#define INT_OV_VOL        (1 << 1)
#define INT_OV_CURR       (1 << 0)

/*TRX int bits define*/
#define INT_INIT_TX        (1 << 7)
#define INT_GET_DPING      (1 << 6)
#define INT_GET_PPP        (1 << 5)
#define INT_GET_CFG        (1 << 4)
#define INT_GET_ID         (1 << 3)
#define INT_GET_SS         (1 << 2)
#define INT_START_DPING    (1 << 1)
#define INT_EPT_TYPE       (1 << 0)

#define TX_TOGGLE          BIT(6) // toggle work mode(148K or 190K)
#define TX_FOD_EN          BIT(5) // enable FOD
#define TX_WD              BIT(4) // enable WD
#define TX_SEND_FSK        BIT(3) // SEND_FSK
#define TX_DIS             BIT(2) // disable tx
#define TX_CLRINT          BIT(1) // clr int
#define TX_EN              BIT(0) // enable tx mode

/* used registers define */
#define REG_CHIP_ID_L        0x0000
#define REG_CHIP_ID_H        0x0001
#define REG_CHIP_REV         0x0002
#define REG_CTM_ID           0x0003
#define REG_OTPFWVER_ADDR    0x0004 // OTP firmware version
#define REG_EPRFWVER_ADDR    0x001c // EEPROM firmware version
#define REG_SYS_INT_CLR      0x0028 // int clear
#define REG_SYS_INT          0x0030 // interrupt
#define REG_STATUS_L         0x0034
#define REG_STATUS_H         0x0035
#define REG_INTR_L           0x0036
#define REG_INTR_H           0x0037
#define REG_INTR_EN_L        0x0038
#define REG_INTR_EN_H        0x0039
#define REG_CHG_STATUS       0x003A
#define REG_ADC_VOUT_L       0x003C
#define REG_ADC_VOUT_H       0x003D
#define REG_VOUT_SET         0x003E
#define REG_VRECT_ADJ        0x003F
#define REG_ADC_VRECT        0x0040
#define REG_RX_LOUT_L        0x0044
#define REG_RX_LOUT_H        0x0045
#define REG_FREQ_ADDR        0x0048 // Operating Frequency, Fop(KHz) = 64 * 6000 /value * 256)
#define REG_ILIM_SET         0x004A
#define REG_SIGNAL_STRENGTH  0x004B
#define REG_WPC_MODE         0x004D
#define REG_SSCMND           0x004e // Command Register, COM (0x4E)
#define REG_RX_RESET         0x004F
#define REG_PROPPKT          0x0050 // Proprietary Packet Header Register, PPP_Header (0x50)
#define REG_PPPDATA          0x0051 // PPP Data Value Register(0X51, 0x52, 0x53, 0x54, 0x55)
#define REG_SSINTCLR         0x0056 // Interrupt Clear Registers, INT_Clear_L (0x56)
#define REG_BCHEADER         0x0058 // Back Channel Packet Register (0x58)
#define REG_BCDATA           0x0059 // Back Channel Packet Register (0x59, 0x5A, 0x5B, 0x5C)
#define REG_FC_VOLTAGE_L     0x0078 // Fast Charging Voltage Register
#define REG_FC_VOLTAGE_H     0x0079
#define REG_REGULATOR_L      0x000C
#define REG_REGULATOR_H      0x000d
#define REG_POWER_MAX        0x0084 //Get the TX power on EPP mode.
#define REG_TX_TYPE          0x00A2 //Get the TX type.
#define REG_BLE_FLAG         0x00A4 //Get the rx ble flag.
#define REG_CEP              0x00A5 //Get the CEP.
#define REG_RPP              0x00A6 //Get the RPP.

/*add for reverse charge*/
#define REG_EPT_TYPE         0x0074
#define REG_TX_CMD           0x0076
#define REG_TX_DATA          0x0078
#define REG_WROK_MODE        0x007B
#define REG_FOD_LOW          0x0092
#define REG_FOD_HIGH         0x0093

#define EPT_POCP             BIT(15)
#define EPT_OTP              BIT(14)
#define EPT_FOD              BIT(13)
#define EPT_LVP              BIT(12)
#define EPT_OVP              BIT(11)
#define EPT_OCP              BIT(10)
#define EPT_RPP_TIMEOUT      BIT(9)
#define EPT_CEP_TIMEOUT      BIT(8)
#define EPT_CMD              BIT(0)

#define REG_EXTERNAL_5V      0x00dc //external 5v enable

// RX -> TX
#define PROPRIETARY18        0x18
#define PROPRIETARY28        0x28
#define PROPRIETARY38        0x38
#define PROPRIETARY48        0x48
#define PROPRIETARY58        0x58

// bitmap for customer command
#define BC_NONE               0x00
#define BC_SET_FREQ           0x03
#define BC_GET_FREQ           0x04
#define BC_READ_FW_VER        0x05
#define BC_READ_Iin           0x06
#define BC_READ_Vin           0x07
#define BC_SET_Vin            0x0a

#define BC_ADAPTER_TYPE       0x0b
#define BC_RESET              0x0c
#define BC_READ_I2C           0x0d
#define BC_WRITE_I2C          0x0e
#define BC_VI2C_INIT          0x10
#define BC_RX_ID_AUTH         0x3b
#define BC_TX_COMPATIBLE_HWID 0x3f
#define BC_TX_HWID            0x4c
#define BC_TX_TOGGLE          0xc4
#define CMD_GET_BLEMAC_2_0    0xb6
#define CMD_GET_BLEMAC_5_3    0xb7

//Factory test command
#define BC_READ_IOUT          0x12
#define BC_READ_VOUT          0x13
#define BC_RX_CHIP_VERSION    0x23
#define BC_RX_FW_VERSION      0x24
#define BC_START_CHARGE       0x30
#define BC_SET_AP_OVERLOAD    0x31
#define BC_ENABLE_FAST_CHARGE 0x32

/* Adapter_list = {0x00:'ADAPTER_UNKNOWN',  */
/*            0x01:'SDP 500mA',  */
/*            0x02:'CDP 1.1A',  */
/*            0x03:'DCP 1.5A',  */
/*            0x05:'QC2.0',  */
/*            0x06:'QC3.0',  */
/*            0x07:'PD',} */
//define adapter type
#define ADAPTER_NONE 0x00
#define ADAPTER_SDP  0x01
#define ADAPTER_CDP  0x02
#define ADAPTER_DCP  0x03
#define ADAPTER_QC2  0x05
#define ADAPTER_QC3  0x06
#define ADAPTER_PD   0x07
#define ADAPTER_AUTH_FAILED   0x08
#define ADAPTER_XIAOMI_QC3    0x09
#define ADAPTER_XIAOMI_PD     0x0a
#define ADAPTER_ZIMI_CAR_POWER    0x0b
#define ADAPTER_XIAOMI_PD_40W     0x0c
#define ADAPTER_VOICE_BOX     0x0d
#define ADAPTER_XIAOMI_PD_50W 0x0e

#define NORMAL_MODE 0x1
#define TAPER_MODE  0x2
#define FULL_MODE   0x3
#define RECHG_MODE  0x4

//fw version to update
#define FW_VERSION  0x23

//add for crc verify
#define CRC_VERIFY_LOW  0x22
#define CRC_VERIFY_HIGH 0x26

//add for reverse fod
#define REVERSE_FOD 600

// bitmap for status flags
// 1: indicates a pending interrupt for LDO Vout state change – from OFF to ON
#define VOUTCHANGED          BIT(7) // Stat_Vout_ON
// 1: indicates a pending interrupt for TX Data Received. (Change from “No Received Data” state to “Data Received” state)
#define TXDATARCVD           BIT(4) // TX Data Received

// bitmap for SSCmnd register 0x4e
#define VSWITCH              BIT(7)
// If AP sets this bit to "1" then IDTP9220 M0 clears the interrupt corresponding to the bit(s) which has a value of “1”
#define CLRINT               BIT(5) // Clear Interrupt
// If AP sets this bit to "1" then IDTP9220 M0 toggles LDO output once (from on to off, or from off to on), and then sets this bit to “0”
#define LDOTGL               BIT(1) // Toggle LDO On/OFF
// If AP sets this bit to “1” then IDTP9220 M0 sends the Proprietary Packet
#define SENDPROPP            BIT(0) //  SEND RX Data

#define SEND_DEVICE_AUTH     BIT(2)

enum VOUT_SET_VAL {
  VOUT_VAL_3500_MV = 0,
  VOUT_VAL_3600_MV,
  VOUT_VAL_3700_MV,
  VOUT_VAL_3800_MV,
  VOUT_VAL_3900_MV,
  VOUT_VAL_4000_MV,
  VOUT_VAL_4100_MV,
  VOUT_VAL_4200_MV,
  VOUT_VAL_4300_MV,
  VOUT_VAL_4400_MV,
  VOUT_VAL_4500_MV,
  VOUT_VAL_4600_MV,
  VOUT_VAL_4700_MV,
  VOUT_VAL_4800_MV,
  VOUT_VAL_4900_MV,
  VOUT_VAL_5000_MV,
  VOUT_VAL_5100_MV,
  VOUT_VAL_5200_MV,
  VOUT_VAL_5300_MV,
  VOUT_VAL_5400_MV,
  VOUT_VAL_5500_MV,
  VOUT_VAL_5600_MV,
  VOUT_VAL_5700_MV,
  VOUT_VAL_5800_MV,
  VOUT_VAL_5900_MV,
  VOUT_VAL_6000_MV,
  VOUT_VAL_6100_MV,
  VOUT_VAL_6200_MV,
  VOUT_VAL_6300_MV,
  VOUT_VAL_6400_MV,
  VOUT_VAL_6500_MV,
  VOUT_VAL_6600_MV,
  VOUT_VAL_6700_MV,
  VOUT_VAL_6800_MV,
  VOUT_VAL_6900_MV,
  VOUT_VAL_7000_MV,
  VOUT_VAL_7100_MV,
  VOUT_VAL_7200_MV,
  VOUT_VAL_7300_MV,
  VOUT_VAL_7400_MV,
  VOUT_VAL_7500_MV,
  VOUT_VAL_7600_MV,
  VOUT_VAL_7700_MV,
  VOUT_VAL_7800_MV,
  VOUT_VAL_7900_MV,
  VOUT_VAL_8000_MV,
};

enum IMIL_SET_VAL {
  CURR_VAL_100_MA = 0,
  CURR_VAL_200_MA,
  CURR_VAL_300_MA,
  CURR_VAL_400_MA,
  CURR_VAL_500_MA,
  CURR_VAL_600_MA,
  CURR_VAL_700_MA,
  CURR_VAL_800_MA,
  CURR_VAL_900_MA,
  CURR_VAL_1000_MA,
  CURR_VAL_1100_MA,
  CURR_VAL_1200_MA,
  CURR_VAL_1300_MA,
};

struct vol_curr_table {
  int index;
  char *val;
};
/*
struct idtp9220_platform_data {
  enum VOUT_SET_VAL vout_val_default;
  enum IMIL_SET_VAL curr_val_default;
  unsigned long gpio_en;
};
*/
typedef struct {        // write to structure at SRAM address 0x0400
  u16 status;           // Read/Write by both 9220 and 9220 host
  u16 startAddr;        // OTP image address of the current packet
  u16 codeLength;       // The size of the OTP image data in the current packet
  u16 dataChksum;       // Checksum of the current packet
  u8  dataBuf[128];     // OTP image data of the current packet
}idtp9220_packet_t;

// proprietary packet type
typedef struct {
  u8 header;            // The header consists of a single byte that indicates the Packet type.
  u8 cmd;               // Back channel command
  u8 data[4];           // Send data buffer
} ProPkt_Type;

#if 1
static char bootloader_data[] = {
    0x00, 0x02, 0x00, 0x20, 0x99, 0x00, 0x00, 0x00, 0x9d, 0x00, 0x00, 0x00, 0x9f, 0x00, 0x00, 0x00,  /// 0x10
    0x00, 0xf0, 0x02, 0xf8, 0x00, 0xf0, 0x30, 0xf8, 0x0c, 0xa0, 0x30, 0xc8, 0x08, 0x38, 0x24, 0x18,  /// 0x20
    0x2d, 0x18, 0xa2, 0x46, 0x67, 0x1e, 0xab, 0x46, 0x54, 0x46, 0x5d, 0x46, 0xac, 0x42, 0x01, 0xd1,  /// 0x30
    0x00, 0xf0, 0x22, 0xf8, 0x7e, 0x46, 0x0f, 0x3e, 0x0f, 0xcc, 0xb6, 0x46, 0x01, 0x26, 0x33, 0x42,  /// 0x40
    0x00, 0xd0, 0xfb, 0x1a, 0xa2, 0x46, 0xab, 0x46, 0x33, 0x43, 0x18, 0x47, 0xa8, 0x06, 0x00, 0x00,  /// 0x50
    0xb8, 0x06, 0x00, 0x00, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26, 0x10, 0x3a, 0x01, 0xd3,  /// 0x60
    0x78, 0xc1, 0xfb, 0xd8, 0x52, 0x07, 0x00, 0xd3, 0x30, 0xc1, 0x00, 0xd5, 0x0b, 0x60, 0x70, 0x47,  /// 0x70
    0x1f, 0xb5, 0x1f, 0xbd, 0x10, 0xb5, 0x10, 0xbd, 0x00, 0xf0, 0x09, 0xfb, 0x11, 0x46, 0xff, 0xf7,  /// 0x80
    0xf7, 0xff, 0x00, 0xf0, 0x45, 0xfa, 0x00, 0xf0, 0x21, 0xfb, 0x03, 0xb4, 0xff, 0xf7, 0xf2, 0xff,  /// 0x90
    0x03, 0xbc, 0x00, 0xf0, 0x27, 0xfb, 0x00, 0x00, 0x05, 0x48, 0x00, 0x47, 0xfe, 0xe7, 0xfe, 0xe7,  /// 0xa0
    0xfe, 0xe7, 0x00, 0x00, 0x03, 0x48, 0x04, 0x49, 0x02, 0x4a, 0x04, 0x4b, 0x70, 0x47, 0x00, 0x00,  /// 0xb0
    0x11, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x20, 0x60, 0x01, 0x00, 0x20, 0x60, 0x00, 0x00, 0x20,  /// 0xc0
    0xfe, 0xb5, 0x04, 0x46, 0x00, 0x20, 0x02, 0x90, 0x10, 0x20, 0x20, 0x40, 0x00, 0x28, 0x64, 0xd0,  /// 0xd0
    0x01, 0x20, 0xfa, 0x4e, 0x30, 0x80, 0x80, 0x1e, 0x30, 0x81, 0x01, 0x46, 0xf8, 0x4e, 0x31, 0x83,  /// 0xe0
    0x08, 0x0c, 0x70, 0x83, 0x00, 0x22, 0x44, 0xe0, 0xf6, 0x48, 0x40, 0x88, 0x80, 0x18, 0x83, 0xb2,  /// 0xf0
    0x01, 0x93, 0xd8, 0x13, 0x00, 0x28, 0x03, 0xd1, 0x01, 0x20, 0xc0, 0x03, 0x18, 0x43, 0x01, 0x90,  /// 0x100
    0xef, 0x48, 0xc2, 0x81, 0x03, 0x80, 0xee, 0x4e, 0x01, 0x98, 0x70, 0x80, 0x01, 0x98, 0x05, 0x78,  /// 0x110
    0xea, 0x48, 0x85, 0x80, 0x30, 0x46, 0x85, 0x80, 0x30, 0x20, 0x20, 0x40, 0x10, 0x28, 0x07, 0xd1,  /// 0x120
    0x00, 0xbf, 0xe6, 0x48, 0x00, 0x88, 0x40, 0x06, 0xc0, 0x0f, 0x00, 0x28, 0xf9, 0xd1, 0x1e, 0xe0,  /// 0x130
    0x00, 0x20, 0x00, 0x90, 0x18, 0xe0, 0xc8, 0x0f, 0x07, 0x27, 0x00, 0x9e, 0xbe, 0x1b, 0x2f, 0x46,  /// 0x140
    0x37, 0x41, 0xfe, 0x07, 0xf6, 0x0f, 0x70, 0x40, 0x00, 0x28, 0x01, 0xd0, 0xde, 0x48, 0x00, 0xe0,  /// 0x150
    0x00, 0x20, 0x4e, 0x00, 0x70, 0x40, 0x01, 0x46, 0xd9, 0x4e, 0x31, 0x83, 0x08, 0x0c, 0x70, 0x83,  /// 0x160
    0x00, 0x98, 0x40, 0x1c, 0xc0, 0xb2, 0x00, 0x90, 0x00, 0x98, 0x07, 0x28, 0xe3, 0xdd, 0x50, 0x1c,  /// 0x170
    0x82, 0xb2, 0xd4, 0x48, 0x80, 0x88, 0x90, 0x42, 0xb6, 0xdc, 0x30, 0x20, 0x20, 0x40, 0x10, 0x28,  /// 0x180
    0x13, 0xd1, 0xce, 0x48, 0x00, 0x89, 0xce, 0x4e, 0x70, 0x82, 0xcc, 0x48, 0x00, 0x89, 0xcd, 0x4e,  /// 0x190
    0xf6, 0x88, 0xb0, 0x42, 0x02, 0xd1, 0x00, 0x20, 0x02, 0x90, 0x2f, 0xe0, 0x01, 0x20, 0x02, 0x90,  /// 0x1a0
    0xc6, 0x48, 0x00, 0x89, 0xc7, 0x4e, 0xf0, 0x80, 0x28, 0xe0, 0x88, 0xb2, 0xc5, 0x4e, 0xf6, 0x88,  /// 0x1b0
    0xb0, 0x42, 0x01, 0xd1, 0x01, 0x20, 0x00, 0xe0, 0x00, 0x20, 0x0e, 0x02, 0x36, 0x0e, 0xc1, 0x4f,  /// 0x1c0
    0x3f, 0x7a, 0xbe, 0x42, 0x01, 0xd1, 0x01, 0x26, 0x00, 0xe0, 0x00, 0x26, 0x30, 0x40, 0x0e, 0x0e,  /// 0x1d0
    0xbc, 0x4f, 0x7f, 0x7a, 0xbe, 0x42, 0x01, 0xd1, 0x01, 0x26, 0x00, 0xe0, 0x00, 0x26, 0x30, 0x40,  /// 0x1e0
    0x00, 0x28, 0x02, 0xd0, 0x00, 0x20, 0x02, 0x90, 0x08, 0xe0, 0x01, 0x20, 0x02, 0x90, 0xb5, 0x4e,  /// 0x1f0
    0xf1, 0x80, 0x08, 0x02, 0x00, 0x0e, 0x30, 0x72, 0x08, 0x0e, 0x70, 0x72, 0x02, 0x98, 0xfe, 0xbd,  /// 0x200
    0x10, 0xb5, 0x02, 0x46, 0xae, 0x4b, 0x1b, 0x8a, 0x04, 0x24, 0x23, 0x43, 0xac, 0x4c, 0x23, 0x82,  /// 0x210
    0x00, 0x23, 0xae, 0x4c, 0xa3, 0x81, 0x93, 0x00, 0x19, 0x60, 0xad, 0x4b, 0x1b, 0x88, 0xa4, 0x14,  /// 0x220
    0x23, 0x40, 0x18, 0x46, 0xa6, 0x4b, 0x1b, 0x8a, 0x04, 0x24, 0xa3, 0x43, 0xa4, 0x4c, 0x23, 0x82,  /// 0x230
    0xa8, 0x4b, 0xa6, 0x4c, 0xa3, 0x81, 0x10, 0xbd, 0x10, 0xb5, 0x02, 0x46, 0xa0, 0x4b, 0x1b, 0x8a,  /// 0x240
    0x02, 0x24, 0x23, 0x43, 0x9e, 0x4c, 0x23, 0x82, 0x00, 0x23, 0xa0, 0x4c, 0xa3, 0x81, 0x11, 0x70,  /// 0x250
    0x9f, 0x4b, 0x1b, 0x88, 0xa4, 0x14, 0x23, 0x40, 0x18, 0x46, 0x99, 0x4b, 0x1b, 0x8a, 0x02, 0x24,  /// 0x260
    0xa3, 0x43, 0x97, 0x4c, 0x23, 0x82, 0x9b, 0x4b, 0x98, 0x4c, 0xa3, 0x81, 0x10, 0xbd, 0xf1, 0xb5,  /// 0x270
    0x88, 0xb0, 0x08, 0x9d, 0x00, 0x20, 0x00, 0x90, 0x91, 0x48, 0x00, 0x8a, 0x08, 0x21, 0x88, 0x43,  /// 0x280
    0x8f, 0x49, 0x08, 0x82, 0x8f, 0x48, 0x00, 0x88, 0x00, 0x07, 0x00, 0x0f, 0x03, 0x90, 0x8d, 0x48,  /// 0x290
    0x40, 0x88, 0x02, 0x90, 0x8b, 0x48, 0x80, 0x88, 0x01, 0x90, 0x01, 0x99, 0x02, 0x98, 0x40, 0x18,  /// 0x2a0
    0x40, 0x1e, 0x80, 0xb2, 0x05, 0x90, 0x05, 0x98, 0xc0, 0x13, 0x00, 0x28, 0x04, 0xd1, 0x01, 0x21,  /// 0x2b0
    0xc9, 0x03, 0x05, 0x98, 0x08, 0x43, 0x05, 0x90, 0x02, 0x98, 0x07, 0x90, 0x01, 0x99, 0x07, 0x98,  /// 0x2c0
    0x40, 0x18, 0x80, 0xb2, 0x07, 0x90, 0x00, 0x27, 0x08, 0xe0, 0x7e, 0x48, 0x08, 0x30, 0xc1, 0x5d,  /// 0x2d0
    0x07, 0x98, 0x08, 0x18, 0x80, 0xb2, 0x07, 0x90, 0x78, 0x1c, 0x87, 0xb2, 0x01, 0x98, 0x87, 0x42,  /// 0x2e0
    0xf3, 0xdb, 0x77, 0x49, 0x07, 0x98, 0x48, 0x82, 0x76, 0x48, 0xc1, 0x88, 0x07, 0x98, 0x81, 0x42,  /// 0x2f0
    0x73, 0xd1, 0x03, 0x98, 0x01, 0x28, 0x01, 0xd1, 0x00, 0x20, 0x0c, 0xe0, 0x03, 0x98, 0x03, 0x28,  /// 0x300
    0x01, 0xd1, 0x04, 0x20, 0x07, 0xe0, 0x03, 0x98, 0x05, 0x28, 0x01, 0xd1, 0x24, 0x20, 0x02, 0xe0,  /// 0x310
    0x6f, 0x48, 0x20, 0x30, 0x00, 0x89, 0x6e, 0x49, 0x20, 0x31, 0x08, 0x81, 0x00, 0x27, 0xbe, 0xe0,  /// 0x320
    0x02, 0x98, 0xc0, 0x19, 0x80, 0xb2, 0x06, 0x90, 0x30, 0x0a, 0x66, 0x49, 0x08, 0x31, 0xc9, 0x5d,  /// 0x330
    0x09, 0x06, 0x08, 0x43, 0x06, 0x46, 0x06, 0x9c, 0x61, 0x48, 0xc7, 0x81, 0x60, 0x49, 0x06, 0x98,  /// 0x340
    0x08, 0x80, 0x30, 0x0c, 0xc8, 0x80, 0x8e, 0x80, 0x06, 0x98, 0xc0, 0x13, 0x00, 0x28, 0x03, 0xd1,  /// 0x350
    0x89, 0x13, 0x06, 0x98, 0x08, 0x43, 0x04, 0x46, 0x04, 0x98, 0x00, 0x0a, 0x21, 0x78, 0x09, 0x06,  /// 0x360
    0x08, 0x43, 0x04, 0x90, 0x56, 0x48, 0x44, 0x80, 0x04, 0x98, 0x00, 0x0c, 0x54, 0x49, 0x48, 0x81,  /// 0x370
    0x04, 0x98, 0x08, 0x81, 0x03, 0x98, 0x01, 0x28, 0x02, 0xd0, 0x03, 0x98, 0x03, 0x28, 0x16, 0xd1,  /// 0x380
    0x04, 0x98, 0x00, 0x0e, 0x31, 0x0e, 0x88, 0x42, 0x0d, 0xd0, 0x31, 0x0e, 0x20, 0x46, 0xff, 0xf7,  /// 0x390
    0x53, 0xff, 0x00, 0x28, 0x08, 0xd1, 0x20, 0x78, 0x04, 0x90, 0x31, 0x0e, 0x04, 0x98, 0x81, 0x42,  /// 0x3a0
    0x79, 0xd0, 0x68, 0x1c, 0x85, 0xb2, 0x76, 0xe0, 0x68, 0x1c, 0x85, 0xb2, 0x73, 0xe0, 0x03, 0x98,  /// 0x3b0
    0x05, 0x28, 0x70, 0xd1, 0xa0, 0x07, 0x80, 0x0f, 0x00, 0x28, 0x07, 0xd1, 0x01, 0x20, 0x00, 0x90,  /// 0x3c0
    0x3f, 0x48, 0x00, 0x8a, 0x08, 0x21, 0x08, 0x43, 0x3d, 0x49, 0x08, 0x82, 0x42, 0x49, 0x05, 0x98,  /// 0x3d0
    0x08, 0x40, 0xa0, 0x42, 0x02, 0xd1, 0x01, 0x20, 0x01, 0xe0, 0x65, 0xe0, 0x00, 0x20, 0x05, 0x99,  /// 0x3e0
    0x89, 0x07, 0x89, 0x0f, 0x03, 0x29, 0x01, 0xd0, 0x01, 0x21, 0x00, 0xe0, 0x00, 0x21, 0x08, 0x40,  /// 0x3f0
    0x00, 0x28, 0x07, 0xd0, 0x00, 0x20, 0x00, 0x90, 0x31, 0x48, 0x00, 0x8a, 0x08, 0x21, 0x88, 0x43,  /// 0x400
    0x2f, 0x49, 0x08, 0x82, 0x00, 0x98, 0x00, 0x28, 0x20, 0xd1, 0x31, 0x48, 0x20, 0x30, 0x00, 0x89,  /// 0x410
    0x20, 0x21, 0x88, 0x43, 0x2e, 0x49, 0x20, 0x31, 0x08, 0x81, 0x08, 0x46, 0x00, 0x89, 0x04, 0x21,  /// 0x420
    0x08, 0x43, 0x2b, 0x49, 0x20, 0x31, 0x08, 0x81, 0x31, 0x0e, 0x20, 0x46, 0xff, 0xf7, 0x04, 0xff,  /// 0x430
    0x00, 0x28, 0x08, 0xd1, 0x20, 0x78, 0x04, 0x90, 0x31, 0x0e, 0x04, 0x98, 0x81, 0x42, 0x2a, 0xd0,  /// 0x440
    0x68, 0x1c, 0x85, 0xb2, 0x27, 0xe0, 0x68, 0x1c, 0x85, 0xb2, 0x24, 0xe0, 0xa0, 0x07, 0x80, 0x0f,  /// 0x450
    0x03, 0x28, 0x20, 0xd1, 0x1e, 0x48, 0x20, 0x30, 0x00, 0x89, 0x20, 0x21, 0x08, 0x43, 0x1c, 0x49,  /// 0x460
    0x20, 0x31, 0x08, 0x81, 0x08, 0x46, 0x00, 0x89, 0x04, 0x21, 0x08, 0x43, 0x18, 0x49, 0x20, 0x31,  /// 0x470
    0x08, 0x81, 0xa0, 0x10, 0x31, 0x46, 0xff, 0xf7, 0xc3, 0xfe, 0x00, 0x28, 0x09, 0xd1, 0xa0, 0x10,  /// 0x480
    0x80, 0x00, 0x00, 0x68, 0x04, 0x90, 0x04, 0x98, 0xb0, 0x42, 0x04, 0xd0, 0x28, 0x1d, 0x85, 0xb2,  /// 0x490
    0x01, 0xe0, 0x28, 0x1d, 0x85, 0xb2, 0x0a, 0x48, 0x85, 0x81, 0x78, 0x1c, 0x87, 0xb2, 0x01, 0x98,  /// 0x4a0
    0x87, 0x42, 0x00, 0xda, 0x3c, 0xe7, 0x06, 0xe0, 0x06, 0x48, 0x80, 0x88, 0x40, 0x19, 0x85, 0xb2,  /// 0x4b0
    0x01, 0x20, 0xc0, 0x03, 0x05, 0x43, 0x28, 0x46, 0x09, 0xb0, 0xf0, 0xbd, 0x00, 0x70, 0x00, 0x40,  /// 0x4c0
    0x00, 0x05, 0x00, 0x20, 0x00, 0x04, 0x00, 0x20, 0xb7, 0x1d, 0xc1, 0x04, 0x40, 0x30, 0x00, 0x40,  /// 0x4d0
    0x00, 0x5c, 0x00, 0x40, 0xff, 0x1f, 0x00, 0x00, 0xfc, 0xff, 0x00, 0x00, 0x0c, 0xb5, 0x00, 0x21,  /// 0x4e0
    0x01, 0x91, 0x10, 0xe0, 0x00, 0x21, 0x00, 0x91, 0x04, 0xe0, 0x69, 0x46, 0x09, 0x88, 0x49, 0x1c,  /// 0x4f0
    0x8a, 0xb2, 0x00, 0x92, 0x69, 0x46, 0x09, 0x88, 0x02, 0x29, 0xf6, 0xdb, 0x69, 0x46, 0x89, 0x88,  /// 0x500
    0x49, 0x1c, 0x8a, 0xb2, 0x01, 0x92, 0x69, 0x46, 0x89, 0x88, 0x81, 0x42, 0xea, 0xdb, 0x0c, 0xbd,  /// 0x510
    0x5a, 0x20, 0x53, 0x49, 0x08, 0x80, 0x05, 0x20, 0x88, 0x80, 0x18, 0x20, 0x88, 0x83, 0x04, 0x20,  /// 0x520
    0x08, 0x81, 0x50, 0x48, 0x88, 0x81, 0x50, 0x20, 0xff, 0xf7, 0xd8, 0xff, 0x4e, 0x48, 0x4c, 0x49,  /// 0x530
    0x88, 0x82, 0x4e, 0x48, 0x08, 0x82, 0x08, 0x46, 0x00, 0x8b, 0x17, 0x21, 0x49, 0x02, 0x08, 0x43,  /// 0x540
    0x47, 0x49, 0x08, 0x83, 0x08, 0x46, 0x00, 0x8b, 0x2e, 0x21, 0x08, 0x43, 0x44, 0x49, 0x08, 0x83,  /// 0x550
    0x08, 0x20, 0xff, 0xf7, 0xc3, 0xff, 0x42, 0x48, 0x80, 0x8b, 0x01, 0x21, 0x08, 0x43, 0x40, 0x49,  /// 0x560
    0x88, 0x83, 0x32, 0x20, 0x42, 0x49, 0x08, 0x80, 0x94, 0x20, 0x42, 0x49, 0x08, 0x80, 0x15, 0x20,  /// 0x570
    0x08, 0x80, 0x08, 0x46, 0x80, 0x8a, 0x60, 0x21, 0x88, 0x43, 0x3e, 0x49, 0x88, 0x82, 0x00, 0x20,  /// 0x580
    0x3d, 0x49, 0x08, 0x80, 0x3d, 0x49, 0x08, 0x80, 0x48, 0x80, 0x00, 0x24, 0x00, 0x27, 0x01, 0x25,  /// 0x590
    0x00, 0x26, 0x06, 0xe0, 0x00, 0x20, 0x71, 0x00, 0x39, 0x4a, 0x89, 0x18, 0x08, 0x80, 0x70, 0x1c,  /// 0x5a0
    0x86, 0xb2, 0x10, 0x2e, 0xf6, 0xdb, 0x5a, 0xe0, 0x34, 0x48, 0x00, 0x88, 0xc0, 0x07, 0xc0, 0x0f,  /// 0x5b0
    0x00, 0x28, 0x54, 0xd0, 0x31, 0x48, 0x00, 0x88, 0xc0, 0xb2, 0x30, 0x49, 0x08, 0x80, 0x5a, 0x20,  /// 0x5c0
    0x30, 0x49, 0x08, 0x82, 0x00, 0x20, 0x26, 0x49, 0x60, 0x31, 0x08, 0x80, 0x2b, 0x48, 0x00, 0x88,  /// 0x5d0
    0x11, 0x21, 0x08, 0x40, 0x01, 0x28, 0x27, 0xd1, 0x01, 0x25, 0x28, 0x48, 0x00, 0x88, 0xc0, 0xb2,  /// 0x5e0
    0x29, 0x02, 0x08, 0x43, 0x25, 0x49, 0x08, 0x80, 0x25, 0x48, 0x00, 0x8a, 0x01, 0x21, 0x08, 0x43,  /// 0x5f0
    0x23, 0x49, 0x08, 0x82, 0x00, 0x20, 0xff, 0xf7, 0x3a, 0xfe, 0x04, 0x46, 0x20, 0x48, 0x00, 0x8a,  /// 0x600
    0xa8, 0x43, 0x1f, 0x49, 0x08, 0x82, 0x60, 0x04, 0x40, 0x0c, 0xc0, 0x19, 0x87, 0xb2, 0x88, 0x13,  /// 0x610
    0x20, 0x40, 0x00, 0x28, 0x01, 0xd0, 0x08, 0x20, 0x04, 0xe0, 0x00, 0x2c, 0x01, 0xd0, 0x04, 0x20,  /// 0x620
    0x00, 0xe0, 0x02, 0x20, 0x05, 0x46, 0x11, 0xe0, 0x01, 0x25, 0x14, 0x48, 0x00, 0x88, 0xc0, 0xb2,  /// 0x630
    0x29, 0x02, 0x08, 0x43, 0x11, 0x49, 0x08, 0x80, 0x08, 0x88, 0xff, 0xf7, 0x41, 0xfd, 0x04, 0x46,  /// 0x640
    0x00, 0x2c, 0x01, 0xd0, 0x08, 0x20, 0x00, 0xe0, 0x02, 0x20, 0x05, 0x46, 0x0b, 0x48, 0x47, 0x80,  /// 0x650
    0x00, 0x88, 0xfe, 0x21, 0x08, 0x40, 0x29, 0x02, 0x08, 0x43, 0x08, 0x49, 0x08, 0x80, 0xa3, 0xe7,  /// 0x660
    0x00, 0x30, 0x00, 0x40, 0x01, 0x04, 0x00, 0x00, 0x0a, 0x18, 0x00, 0x00, 0xff, 0x07, 0x00, 0x00,  /// 0x670
    0x40, 0x54, 0x00, 0x40, 0x00, 0x58, 0x00, 0x40, 0x40, 0x6c, 0x00, 0x40, 0x00, 0x04, 0x00, 0x20,  /// 0x680
    0x00, 0x05, 0x00, 0x20, 0x40, 0x5c, 0x00, 0x40, 0x70, 0x47, 0x70, 0x47, 0x70, 0x47, 0x75, 0x46,  /// 0x690
    0x00, 0xf0, 0x24, 0xf8, 0xae, 0x46, 0x05, 0x00, 0x69, 0x46, 0x53, 0x46, 0xc0, 0x08, 0xc0, 0x00,  /// 0x6a0
    0x85, 0x46, 0x18, 0xb0, 0x20, 0xb5, 0xff, 0xf7, 0xfd, 0xfc, 0x60, 0xbc, 0x00, 0x27, 0x49, 0x08,  /// 0x6b0
    0xb6, 0x46, 0x00, 0x26, 0xc0, 0xc5, 0xc0, 0xc5, 0xc0, 0xc5, 0xc0, 0xc5, 0xc0, 0xc5, 0xc0, 0xc5,  /// 0x6c0
    0xc0, 0xc5, 0xc0, 0xc5, 0x40, 0x3d, 0x49, 0x00, 0x8d, 0x46, 0x70, 0x47, 0x10, 0xb5, 0x04, 0x46,  /// 0x6d0
    0xc0, 0x46, 0xc0, 0x46, 0x20, 0x46, 0xff, 0xf7, 0xd8, 0xfc, 0x10, 0xbd, 0x00, 0x48, 0x70, 0x47,  /// 0x6e0
    0x00, 0x00, 0x00, 0x20, 0x01, 0x49, 0x18, 0x20, 0xab, 0xbe, 0xfe, 0xe7, 0x26, 0x00, 0x02, 0x00,  /// 0x6f0
    0x70, 0x47, 0x00, 0x00, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x60, 0x01, 0x00, 0x00,  /// 0x700
    0x54, 0x00, 0x00, 0x00,
};

#endif

extern uint32_t get_hw_version_major(void);

#endif