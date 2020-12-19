#ifndef __BQ25790_HEADER__
#define __BQ25790_HEADER__

#define BQ25790_MINI_SYS_VOLT			0x00
#define BQ25790_VSYSMIN_MASK			0x3F
#define BQ25790_VSYSMIN_SHIFT			0
#define BQ25790_VSYSMIN_BASE			2500
#define BQ25790_VSYSMIN_LSB			250

#define BQ25790_REG_CHARGE_VOLT			0x01
#define BQ25790_VREG_MASK			0x7FF
#define BQ25790_VREG_SHIFT			0
#define BQ25790_VREG_BASE			0
#define BQ25790_VREG_LSB			10

#define BQ25790_REG_CHARGE_CURRENT		0x03
#define BQ25790_ICHG_MASK			0x1FF
#define BQ25790_ICHG_SHIFT			0
#define BQ25790_ICHG_BASE			0
#define BQ25790_ICHG_LSB			10

#define BQ25790_REG_VINDPM			0x05
#define BQ25790_VINDPM_TH_MASK			0xFF
#define BQ25790_VINDPM_TH_SHIFT			0
#define BQ25790_VINDPM_TH_BASE			0
#define BQ25790_VINDPM_TH_LSB			100

#define BQ25790_REG_IINDPM			0x06
#define BQ25790_IINDPM_TH_MASK			0x1FF
#define BQ25790_IINDPM_TH_SHIFT			0
#define BQ25790_IINDPM_TH_BASE			0
#define BQ25790_IINDPM_TH_LSB			10

#define BQ25790_REG_PRECHG_CTRL			0x08
#define BQ25790_IPRECHG_MASK			0x3F
#define BQ25790_IPRECHG_SHIFT			0
#define BQ25790_IPRECHG_BASE			0
#define BQ25790_IPRECHG_LSB			40

#define BQ25790_REG_ITERM_CTRL			0x09
#define BQ25790_ITERM_MASK			0x1F
#define BQ25790_ITERM_SHIFT			0
#define BQ25790_ITERM_BASE			0
#define BQ25790_ITERM_LSB			40
#define BQ25790_ITERM_MAX			1000

#define BQ25790_REG_RECHAEGE_CTRL		0x0A
#define BQ25790_CELL_MASK			0xC0
#define BQ25790_CELL_SHIFT			6
#define BQ25790_CELL_1				0
#define BQ25790_CELL_2				1
#define BQ25790_CELL_3				2
#define BQ25790_CELL_4				3
#define BQ25790_VRECHG_MASK			0xF
#define BQ25790_VRECHG_SHIFT			0
#define BQ25790_VRECHG_BASE			50
#define BQ25790_VRECHG_LSB			50
#define BQ25790_VRECHG_MAX			800

#define BQ25790_REG_IOTG_REGULATION		0x0D
#define BQ25790_PRECHG_TMR_MASK			0x80
#define BQ25790_PRECHG_TMR_SHIFT		7
#define BQ25790_PRECHG_0_5H			0
#define BQ25790_PRECHG_2H			1

#define BQ25790_REG_TIMER_CTRL			0x0E
#define BQ25790_SAFETY_TIMER_EN_MASK		0x08
#define BQ25790_SAFETY_TIMER_EN_SHIFT		3
#define BQ25790_SAFETY_TIMER_ENABLE		1
#define BQ25790_SAFETY_TIMER_DISABLE		0
#define BQ25790_SAFETY_TIMER_MASK		0x06
#define BQ25790_SAFETY_TIMER_SHIFT		1
#define BQ25790_SAFETY_TIMER_5H			0
#define BQ25790_SAFETY_TIMER_8H			1
#define BQ25790_SAFETY_TIMER_12H		2
#define BQ25790_SAFETY_TIMER_24H		3

#define BQ25790_REG_CHG_CTRL0			0x0F
#define BQ25790_HIZ_DISABLE			0
#define BQ25790_HIZ_ENABLE			1
#define BQ25790_EN_HIZ_MASK			0x04
#define BQ25790_EN_HIZ_SHIFT			2
#define BQ25790_ICO_DISABLE			0
#define BQ25790_ICO_ENABLE			1
#define BQ25790_EN_ICO_MASK			0x10
#define BQ25790_EN_ICO_SHIFT			4
#define BQ25790_FORCE_ICO			1
#define BQ25790_FORCE_ICO_MASK			0x08
#define BQ25790_FORCE_ICO_SHIFT			3
#define BQ25790_CHARGE_DISABLE			0
#define BQ25790_CHARGE_ENABLE			1
#define BQ25790_CHARGE_EN_MASK			0x20
#define BQ25790_CHARGE_EN_SHIFT			5
#define BQ25790_DIS_TERM			0
#define BQ25790_EN_TERM				1
#define BQ25790_EN_TERM_MASK			0x02
#define BQ25790_EN_TERM_SHIFT			1

#define BQ25790_REG_CHG_CTRL1			0x10
#define BQ25790_WDT_TIMER_MASK			0x07
#define BQ25790_WDT_TIMER_SHIFT			0
#define BQ25790_WDT_TIMER_DISABLE		0
#define BQ25790_WDT_TIMER_05S			1
#define BQ25790_WDT_TIMER_1S			2
#define BQ25790_WDT_TIMER_2S			3
#define BQ25790_WDT_TIMER_20S			4
#define BQ25790_WDT_TIMER_40S			5
#define BQ25790_WDT_TIMER_80S			6
#define BQ25790_WDT_TIMER_160S			7
#define BQ25790_WDT_RESET_MASK			0x08
#define BQ25790_WDT_RESET_SHIFT			3
#define BQ25790_WDT_RESET			1
#define	BQ25790_VAC_OVP_MASK			0x30
#define	BQ25790_VAC_OVP_SHIFT			3
#define	BQ25790_VAC_OVP_26V			0
#define	BQ25790_VAC_OVP_18V			1
#define	BQ25790_VAC_OVP_12V			2
#define	BQ25790_VAC_OVP_7V			3

#define BQ25790_REG_CHG_CTRL2			0x11
#define BQ25790_FORCE_INDET			1
#define BQ25790_FORCE_INDET_MASK		0x80
#define BQ25790_FORCE_INDET_SHIFT		7
#define BQ25790_AUTO_INDET_EN			1
#define BQ25790_AUTO_INDET_DIS			0
#define BQ25790_AUTO_INDET_MASK			0x40
#define BQ25790_AUTO_INDET_SHIFT		6

#define BQ25790_REG_CHG_CTRL3			0x12
#define BQ25790_OTG_EN_MASK			0x40
#define BQ25790_OTG_EN_SHIFT			6
#define BQ25790_OTG_DISABLE			0
#define BQ25790_OTG_ENABLE			1
#define BQ25790_PFM_FWD_DIS			1
#define BQ25790_PFM_FWD_EN			0
#define BQ25790_PFM_FWD_DIS_MASK		0x10
#define BQ25790_PFM_FWD_DIS_SHIFT		4
#define BQ25790_DIS_FWD_OOA			1
#define BQ25790_EN_FWD_OOA			0
#define BQ25790_DIS_FWD_OOA_MASK		0x1
#define BQ25790_DIS_FWD_OOA_SHIFT		0

#define BQ25790_REG_CHG_CTRL5			0x14
#define BQ25790_EN_EXTILIM_MASK			0x02
#define BQ25790_EN_EXTILIM_SHIFT		1
#define BQ25790_EN_EXTILIM			1
#define BQ25790_DIS_EXTILIM			0

#define BQ25790_REG_CHG_STATUS0			0x1B
#define BQ25790_PG_STAT_MASK			0x08

#define BQ25790_REG_CHG_STATUS1			0x1C
#define BQ25790_CHRG_STAT_MASK			0xE0
#define BQ25790_CHRG_STAT_SHIFT			5
#define BQ25790_CHRG_STAT_NOT_CHARGING		0
#define BQ25790_CHRG_STAT_TRICKLE		1
#define BQ25790_CHRG_STAT_PRECHG		2
#define BQ25790_CHRG_STAT_FAST			3
#define BQ25790_CHRG_STAT_TAPER			4
#define BQ25790_CHRG_STAT_RSVED			5
#define BQ25790_CHRG_STAT_TOP_OFF		6
#define BQ25790_CHRG_STAT_DONE			7
#define BQ25790_VBUS_STAT_MASK			0x0F
#define BQ25790_VBUS_STAT_SHIFT			1
#define BQ25790_VBUS_OTG_MODE			0x07

#define BQ25790_REG_CHG_INT_MASK0		0x28
#define BQ25790_REG_CHG_INT_MASK1		0x29
#define BQ25790_REG_CHG_INT_MASK2		0x2A
#define BQ25790_REG_CHG_INT_MASK3		0x2B
#define BQ25790_REG_CHG_FAULT_MASK0		0x2C
#define BQ25790_REG_CHG_FAULT_MASK1		0x2D
#define BQ25790_REG_ADC_CTRL_REG		0x2E
#define BQ25790_ADC_EN_MASK			0x80
#define BQ25790_ADC_EN_SHIFT			7
#define BQ25790_ADC_EN				1
#define BQ25790_ADC_DIS				0
#define BQ25790_REG_ADC_DISABLE_REG		0x2F

#define BQ25790_ADC_CONTROL_REG			0x2E
#define BQ25790_ADC_SAMPLE_15BIT		0x0
#define BQ25790_ADC_SAMPLE_14BIT		0x1
#define BQ25790_ADC_SAMPLE_13BIT		0x2
#define BQ25790_ADC_SAMPLE_12BIT		0x3
#define BQ25790_ADC_SAMPLE_MASK			0x30
#define BQ25790_ADC_SAMPLE_SHFIT		4

#define BQ25790_REG_IBUS_ADC_1                    0x31
#define BQ25790_IBUS_ADC_HB_MASK                  0xFF
#define BQ25790_IBUS_ADC_HB_SHIFT                 0
#define BQ25790_IBUS_ADC_HB_BASE                  0
#define BQ25790_IBUS_ADC_HB_LSB                   1

#define BQ25790_REG_IBUS_ADC_0                    0x32
#define BQ25790_IBUS_ADC_LB_MASK                  0xFF
#define BQ25790_IBUS_ADC_LB_SHIFT                 0
#define BQ25790_IBUS_ADC_LB_BASE                  0
#define BQ25790_IBUS_ADC_LB_LSB                   1

#define BQ25790_REG_IBAT_ADC_1                    0x33
#define BQ25790_ICHG_ADC_HB_MASK                  0xFF
#define BQ25790_ICHG_ADC_HB_SHIFT                 0
#define BQ25790_ICHG_ADC_HB_BASE                  0
#define BQ25790_ICHG_ADC_HB_LSB                   1

#define BQ25790_REG_IBAT_ADC_0                    0x34
#define BQ25790_ICHG_ADC_LB_MASK                  0xFF
#define BQ25790_ICHG_ADC_LB_SHIFT                 0
#define BQ25790_ICHG_ADC_LB_BASE                  0
#define BQ25790_ICHG_ADC_LB_LSB                   1

#define BQ25790_REG_VBUS_ADC_1                    0x35
#define BQ25790_VBUS_ADC_HB_MASK                  0xFF
#define BQ25790_VBUS_ADC_HB_SHIFT                 0
#define BQ25790_VBUS_ADC_HB_BASE                  0
#define BQ25790_VBUS_ADC_HB_LSB                   1

#define BQ25790_REG_VBUS_ADC_0                    0x36
#define BQ25790_VBUS_ADC_LB_MASK                  0xFF
#define BQ25790_VBUS_ADC_LB_SHIFT                 0
#define BQ25790_VBUS_ADC_LB_BASE                  0
#define BQ25790_VBUS_ADC_LB_LSB                   1

#define BQ25790_REG_VBAT_ADC_1                    0x3B
#define BQ25790_VBAT_ADC_HB_MASK                  0xFF
#define BQ25790_VBAT_ADC_HB_SHIFT                 0
#define BQ25790_VBAT_ADC_HB_BASE                  0
#define BQ25790_VBAT_ADC_HB_LSB                   1

#define BQ25790_REG_VBAT_ADC_0                    0x3C
#define BQ25790_VBAT_ADC_LB_MASK                  0xFF
#define BQ25790_VBAT_ADC_LB_SHIFT                 0
#define BQ25790_VBAT_ADC_LB_BASE                  0
#define BQ25790_VBAT_ADC_LB_LSB                   1

#define BQ25790_REG_VSYS_ADC_1                    0x3D
#define BQ25790_VSYS_ADC_HB_MASK                  0xFF
#define BQ25790_VSYS_ADC_HB_SHIFT                 0
#define BQ25790_VSYS_ADC_HB_BASE                  0
#define BQ25790_VSYS_ADC_HB_LSB                   1

#define BQ25790_REG_VSYS_ADC_0                    0x3E
#define BQ25790_VSYS_ADC_LB_MASK                  0xFF
#define BQ25790_VSYS_ADC_LB_SHIFT                 0
#define BQ25790_VSYS_ADC_LB_BASE                  0
#define BQ25790_VSYS_ADC_LB_LSB                   1

#define BQ25790_REG_TS_ADC_1                      0x3F
#define BQ25790_TS_ADC_HB_MASK                    0xFF
#define BQ25790_TS_ADC_HB_SHIFT                   0
#define BQ25790_TS_ADC_HB_BASE                    0
#define BQ25790_TS_ADC_HB_LSB                     1

#define BQ25790_REG_TS_ADC_0                      0x40
#define BQ25790_TS_ADC_LB_MASK                    0xFF
#define BQ25790_TS_ADC_LB_SHIFT                   0
#define BQ25790_TS_ADC_LB_BASE                    0
#define BQ25790_TS_ADC_LB_LSB                     1

#define BQ25790_REG_TDIE_ADC_1                    0x41
#define BQ25790_TDIE_ADC_HB_MASK                  0xFF
#define BQ25790_TDIE_ADC_HB_SHIFT                 0
#define BQ25790_TDIE_ADC_HB_BASE                  0
#define BQ25790_TDIE_ADC_HB_LSB                   1

#define BQ25790_REG_TDIE_ADC_0                    0x42
#define BQ25790_TDIE_ADC_LB_MASK                  0xFF
#define BQ25790_TDIE_ADC_LB_SHIFT                 0
#define BQ25790_TDIE_ADC_LB_BASE                  0
#define BQ25790_TDIE_ADC_LB_LSB                   1

#define BQ25790_REG_PART_NUM			0x48
#define BQ25790_PART_NO_MASK			0x3C
#define BQ25790_PART_NO_SHIFT			3
#define BQ25790_PART_NO_BQ25790			0
#define BQ25790_REVISION_MASK			0x07
#define BQ25790_REVISION_SHIFT			0
#define BQ25790_REV_A0_A3			0x3
#define BQ25790_REV_B0_B3			0x7

#endif
