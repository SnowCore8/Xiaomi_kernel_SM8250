#pragma once
#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/soc.h>
#include <linux/types.h>


#define ELLIPTIC_OBJ_ID_CALIBRATION_DATA 1
#define ELLIPTIC_OBJ_ID_VERSION_INFO 2
#define ELLIPTIC_OBJ_ID_BRANCH_INFO 3
#define ELLIPTIC_OBJ_ID_CALIBRATION_V2_DATA 4
#define ELLIPTIC_OBJ_ID_DIAGNOSTICS_DATA 5
#define ELLIPTIC_OBJ_ID_TAG_INFO 6
#define ELLIPTIC_OBJ_ID_ML_DATA 7

#define ELLIPTIC_SYSTEM_CONFIGURATION_SIZE		96
#define ELLIPTIC_CALIBRATION_DATA_SIZE          64
#define ELLIPTIC_CALIBRATION_V2_DATA_SIZE      448
#define ELLIPTIC_DIAGNOSTICS_DATA_SIZE         448
#define ELLIPTIC_DIAGNOSTICS_U32_DATA_VALUES   (ELLIPTIC_DIAGNOSTICS_DATA_SIZE>>2)
#define ELLIPTIC_SENSOR_DATA_SIZE              68
#define ELLIPTIC_SENSOR_U32_DATA_VALUES   (ELLIPTIC_SENSOR_DATA_SIZE>>2)
#define ELLIPTIC_VERSION_INFO_SIZE              16
#define ELLIPTIC_BRANCH_INFO_SIZE               32
#define ELLIPTIC_BRANCH_INFO_MAX_SIZE          128
#define ELLIPTIC_TAG_INFO_SIZE                  32
#define ELLIPTIC_ML_DATA_SIZE				   432

#define ELLIPTIC_ULTRASOUND_DISABLE				0
#define ELLIPTIC_ULTRASOUND_ENABLE				1
#define ELLIPTIC_ULTRASOUND_SET_PARAMS			2
#define ELLIPTIC_ULTRASOUND_GET_PARAMS			3
#define ELLIPTIC_ULTRASOUND_RAMP_DOWN			4

/** register */
#define ELLIPTIC_CALIBRATION				1
/** bits */
#define ELLIPTIC_CALIBRATION_STATE			0
#define ELLIPTIC_CALIBRATION_PROFILE		1
#define ELLIPTIC_ULTRASOUND_GAIN			2

/** custom settings */
#define ELLIPTIC_SYSTEM_CONFIGURATION_CUSTOM_SETTING_COUNT 16
#define ELLIPTIC_SYSTEM_CONFIGURATION_CUSTOM_SETTING_MAX_VALUE 0x7FFFFFFF


/** register */
#define ELLIPTIC_SYSTEM_CONFIGURATION			0
/** bits */
#define ELLIPTIC_SYSTEM_CONFIGURATION_LATENCY		0
#define ELLIPTIC_SYSTEM_CONFIGURATION_SENSITIVITY	1
#define ELLIPTIC_SYSTEM_CONFIGURATION_SPEAKER_SCALING	2
#define ELLIPTIC_SYSTEM_CONFIGURATION_MICROPHONE_INDEX	3
#define ELLIPTIC_SYSTEM_CONFIGURATION_OPERATION_MODE		4
#define ELLIPTIC_SYSTEM_CONFIGURATION_OPERATION_MODE_FLAGS	5
#define ELLIPTIC_SYSTEM_CONFIGURATION_LOG_LEVEL	6
#define ELLIPTIC_SYSTEM_CONFIGURATION_CUSTOM_SETTING_0	7
#define ELLIPTIC_SYSTEM_CONFIGURATION_CUSTOM_SETTING_1	8
#define ELLIPTIC_SYSTEM_CONFIGURATION_CUSTOM_SETTING_2	9
#define ELLIPTIC_SYSTEM_CONFIGURATION_CUSTOM_SETTING_3	10
#define ELLIPTIC_SYSTEM_CONFIGURATION_CUSTOM_SETTING_4	11
#define ELLIPTIC_SYSTEM_CONFIGURATION_CUSTOM_SETTING_5	12
#define ELLIPTIC_SYSTEM_CONFIGURATION_CUSTOM_SETTING_6	13
#define ELLIPTIC_SYSTEM_CONFIGURATION_CUSTOM_SETTING_7	14
#define ELLIPTIC_SYSTEM_CONFIGURATION_CUSTOM_SETTING_8	15
#define ELLIPTIC_SYSTEM_CONFIGURATION_CUSTOM_SETTING_9	16
#define ELLIPTIC_SYSTEM_CONFIGURATION_CUSTOM_SETTING_10	17
#define ELLIPTIC_SYSTEM_CONFIGURATION_CUSTOM_SETTING_11	18
#define ELLIPTIC_SYSTEM_CONFIGURATION_CUSTOM_SETTING_12	19
#define ELLIPTIC_SYSTEM_CONFIGURATION_CUSTOM_SETTING_13	20
#define ELLIPTIC_SYSTEM_CONFIGURATION_CUSTOM_SETTING_14	21
#define ELLIPTIC_SYSTEM_CONFIGURATION_CUSTOM_SETTING_15	22

#define ELLIPTIC_SYSTEM_CONFIGURATION_SUSPEND 23
#define ELLIPTIC_SYSTEM_CONFIGURATION_INPUT_ENABLED 24
#define ELLIPTIC_SYSTEM_CONFIGURATION_OUTPUT_ENABLED 25
#define ELLIPTIC_SYSTEM_CONFIGURATION_EXTERNAL_EVENT 26
#define ELLIPTIC_SYSTEM_CONFIGURATION_CALIBRATION_METHOD 27
#define ELLIPTIC_SYSTEM_CONFIGURATION_DEBUG_MODE 28
#define ELLIPTIC_SYSTEM_CONFIGURATION_NUMBER_OF_RUNS 29
#define ELLIPTIC_SYSTEM_CONFIGURATION_CONTEXT 30
#define ELLIPTIC_SYSTEM_CONFIGURATION_CAPTURE 31
#define ELLIPTIC_SYSTEM_CONFIGURATION_INPUT_CHANNELS 32
#define ELLIPTIC_SYSTEM_CONFIGURATION_REPORT_NONE 33

#define ELLIPTIC_SYSTEM_CONFIGURATION_MAX_CONTEXT_VALUE 0x7FFFFFFF


struct elliptic_engine_version_info {
	uint32_t major;
	uint32_t minor;
	uint32_t build;
	uint32_t revision;
};

struct elliptic_shared_data_block {
	uint32_t object_id;
	size_t size;
	void *buffer;
};

struct elliptic_shared_data_block *elliptic_get_shared_obj(uint32_t
	object_id);

extern unsigned int elliptic_add_component_controls(void *component);

void elliptic_set_calibration_data(uint8_t *calib_data, size_t size);

enum elliptic_system_configuration_parameter_type {

	ESCPT_SPEAKER_SCALING = 1,
	ESCPT_CHANNEL_SENSITIVITY,
	ESCPT_LATENCY,
	ESCPT_MICROPHONE_INDEX,
	ESCPT_OPERATION_MODE,
	ESCPT_OPERATION_MODE_FLAGS,
	ESCPT_COMPONENT_GAIN_CHANGE,
	ESCPT_CALIBRATION_STATE,
	ESCPT_ENGINE_VERSION,
	ESCPT_CALIBRATION_PROFILE,
	ESCPT_ULTRASOUND_GAIN,
	ESCPT_LOG_LEVEL,
	ESCPT_BUILD_BRANCH, //13
	
	ESCPT_FSELECTION,
	ESCPT_ENGINE_DIAGNOSTICS,
	ESCPT_ENGINE_CUSTOM_SETTING_0,
	ESCPT_ENGINE_CUSTOM_SETTING_1,
	ESCPT_ENGINE_CUSTOM_SETTING_2,
	ESCPT_ENGINE_CUSTOM_SETTING_3,
	ESCPT_ENGINE_CUSTOM_SETTING_4,
	ESCPT_ENGINE_CUSTOM_SETTING_5,
	ESCPT_ENGINE_CUSTOM_SETTING_6,
	ESCPT_ENGINE_CUSTOM_SETTING_7,
	ESCPT_ENGINE_CUSTOM_SETTING_8,
	ESCPT_ENGINE_CUSTOM_SETTING_9,
	ESCPT_ENGINE_CUSTOM_SETTING_10,
	ESCPT_ENGINE_CUSTOM_SETTING_11,
	ESCPT_ENGINE_CUSTOM_SETTING_12,
	ESCPT_ENGINE_CUSTOM_SETTING_13,
	ESCPT_ENGINE_CUSTOM_SETTING_14,
	ESCPT_ENGINE_CUSTOM_SETTING_15,
	ESCPT_SUSPEND, // 32
	ESCPT_INPUT_ENABLED,
	ESCPT_OUTPUT_ENABLED,
	ESCPT_EXTERNAL_EVENT,
	ESCPT_ENGINE_TAG, //36
	ESCPT_CALIBRATION_METHOD,
	ESCPT_DEBUG_MODE,
	ESCPT_NUMBER_OF_RUNS,
	ESCPT_CONTEXT,
	ESCPT_CAPTURE,
	ESCPT_INPUT_CHANNELS,
};

struct elliptic_system_configuration_parameters_cache {
	int32_t speaker_scaling[2];
	int32_t sensitivity;
	int32_t latency;
	int32_t microphone_index;
	int32_t operation_mode;
	int32_t operation_mode_flags;
	int32_t component_gain_change;
	int32_t calibration_state;
	int32_t engine_version;
	int32_t calibration_profile;
	int32_t ultrasound_gain;
	int32_t	log_level;
	int32_t custom_settings[ELLIPTIC_SYSTEM_CONFIGURATION_CUSTOM_SETTING_COUNT];
	int32_t engine_suspend;
	int32_t input_enabled;
	int32_t output_enabled;
	int32_t external_event;
	int32_t calibration_method;
	int32_t debug_mode;
	int32_t number_of_runs;
	int32_t context;
	int32_t capture;
	int32_t input_channels;
};


int elliptic_trigger_version_msg(void);

int elliptic_trigger_branch_msg(void);

int elliptic_trigger_tag_msg(void);

int elliptic_trigger_diagnostics_msg(void);
