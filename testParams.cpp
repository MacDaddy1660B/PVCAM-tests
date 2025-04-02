#include <iostream>

#include "pvcam/master.h"
#include "pvcam/pvcam.h"

/*
This simple test program checks if
the following Class 2 Parameter IDs
are available:

CCD Clearing:
PARAM_ANTI_BLOOMING 
PARAM_CLEAR_CYCLES
PARAM_CLEAR_MODE
PARAM_CLN_WHILE_EXPO
PARAM_CONT_CLEARS
PARAM_MIN_BLOCK
PARAM_NUM_MIN_BLOCK
PARAM_NUM_OF_STRIPS_PER_CLR
PARAM_PREEXP_CLEANS
PARAM_SKIP_AT_ONCE_BLK
PARAM_SKIP_SREG_CLEAN
PARAM_POSTSCAN

Temperature Control:
PARAM_COOLING_FAN_CTRL
PARAM_COOLING_MODE
PARAM_HEAD_COOLING_CTRL
PARAM_TEMP
PARAM_TEMP_SETPOINT

CCD Physical Attributes:
PARAM_COLOR_MODE
PARAM_CUSTOM_CHIP
PARAM_FTSCAN
PARAM_FWELL_CAPACITY
PARAM_KIN_WIN_SIZE
PARAM_PAR_SIZE
PARAM_PIX_PAR_DIST
PARAM_PIX_PAR_SIZE
PARAM_PIX_SER_DIST
PARAM_PIX_SER_SIZE
PARAM_POSTMASK
PARAM_PIX_TIME
PARAM_PREMASK
PARAM_PRESCAN
PARAM_SER_SIZE
PARAM_SUMMING_WELL

Gain:
PARAM_GAIN_INDEX
PARAM_GAIN_MULT_ENABLE
PARAM_GAIN_MULT_FACTOR
PARAM_INTENSIFIER_GAIN
PARAM_PREAMP_DELAY
PARAM_PREAMP_OFF_CONTROL

Shutter:
PARAM_EXPOSURE_MODE
PARAM_PREFLASH
PARAM_SHTR_CLOSE_DELAY
PARAM_SHTR_CLOSE_DELAY_UNIT
PARAM_SHTR_GATE_MODE
PARAM_SHTR_OPEN_DELAY
PARAM_SHTR_OPEN_MODE
PARAM_SHTR_RES
PARAM_SHTR_STATUS

I/O:
PARAM_IO_ADDR
PARAM_IO_BITDEPTH
PARAM_IO_DIRECTION
PARAM_IO_STATE
PARAM_IO_TYPE
PARAM_LOGIC_OUTPUT
PARAM_LOGIC_OUTPUT_INVERT

CCD Readout:
PARAM_CCS_STATUS
PARAM_CUSTOM_TIMING
PARAM_EDGE_TRIGGER
PARAM_PAR_SHIFT_TIME
PARAM_PAR_SHIFT_INDEX
PARAM_READOUT_TIME
PARAM_SER_SHIFT_TIME

ADC Attributes:
PARAM_ADC_OFFSET
PARAM_BIT_DEPTH
PARAM_SPDTAB_INDEX

Cabilities:
PARAM_ACCUM_CAPABLE
PARAM_FRAME_CAPABLE
PARAM_MPP_CAPABLE

Other:
PARAM_CAM_FW_VERSION
PARAM_CAM_FW_FULL_VERSION
PARAM_CHIP_NAME
PARAM_CONTROLLER_ALIVE
PARAM_HEAD_SER_NUM_ALPHA
PARAM_PCI_FW_VERSION
PARAM_SERIAL_NUM
PARAM_TG_OPTION_BD_TYPE
*/
/*
uns32 pList[76] = {
	PARAM_ANTI_BLOOMING,        	"PARAM_ANTI_BLOOMING "
	PARAM_CLEAR_CYCLES,         	"PARAM_CLEAR_CYCLES"
	PARAM_CLEAR_MODE,           	"PARAM_CLEAR_MODE"
	PARAM_CLN_WHILE_EXPO,       	"PARAM_CLN_WHILE_EXPO"
	PARAM_CONT_CLEARS,          	"PARAM_CONT_CLEARS"
	PARAM_MIN_BLOCK,            	"PARAM_MIN_BLOCK"
	PARAM_NUM_MIN_BLOCK,        	"PARAM_NUM_MIN_BLOCK"
	PARAM_NUM_OF_STRIPS_PER_CLR,	"PARAM_NUM_OF_STRIPS_PER_CLR"
	PARAM_PREEXP_CLEANS,        	"PARAM_PREEXP_CLEANS"
	PARAM_SKIP_AT_ONCE_BLK,     	"PARAM_SKIP_AT_ONCE_BLK"
	PARAM_SKIP_SREG_CLEAN,      	"PARAM_SKIP_SREG_CLEAN"
	PARAM_POSTSCAN,             	"PARAM_POSTSCAN"
	PARAM_COOLING_FAN_CTRL,     	"PARAM_COOLING_FAN_CTRL"
	PARAM_COOLING_MODE,         	"PARAM_COOLING_MODE"
	PARAM_HEAD_COOLING_CTRL,    	"PARAM_HEAD_COOLING_CTRL"
	PARAM_TEMP,                 	"PARAM_TEMP"
	PARAM_TEMP_SETPOINT,        	"PARAM_TEMP_SETPOINT"
	PARAM_COLOR_MODE,           	"PARAM_COLOR_MODE"
	PARAM_CUSTOM_CHIP,          	"PARAM_CUSTOM_CHIP"
	PARAM_FTSCAN,               	"PARAM_FTSCAN"
	PARAM_FWELL_CAPACITY,       	"PARAM_FWELL_CAPACITY"
	PARAM_KIN_WIN_SIZE,         	"PARAM_KIN_WIN_SIZE"
	PARAM_PAR_SIZE,             	"PARAM_PAR_SIZE"
	PARAM_PIX_PAR_DIST,         	"PARAM_PIX_PAR_DIST"
	PARAM_PIX_PAR_SIZE,         	"PARAM_PIX_PAR_SIZE"
	PARAM_PIX_SER_DIST,         	"PARAM_PIX_SER_DIST"
	PARAM_PIX_SER_SIZE,         	"PARAM_PIX_SER_SIZE"
	PARAM_POSTMASK,             	"PARAM_POSTMASK"
	PARAM_PIX_TIME,             	"PARAM_PIX_TIME"
	PARAM_PREMASK,              	"PARAM_PREMASK"
	PARAM_PRESCAN,              	"PARAM_PRESCAN"
	PARAM_SER_SIZE,             	"PARAM_SER_SIZE"
	PARAM_SUMMING_WELL,         	"PARAM_SUMMING_WELL"
	PARAM_GAIN_INDEX,           	"PARAM_GAIN_INDEX"
	PARAM_GAIN_MULT_ENABLE,     	"PARAM_GAIN_MULT_ENABLE"
	PARAM_GAIN_MULT_FACTOR,     	"PARAM_GAIN_MULT_FACTOR"
	PARAM_INTENSIFIER_GAIN,     	"PARAM_INTENSIFIER_GAIN"
	PARAM_PREAMP_DELAY,         	"PARAM_PREAMP_DELAY"
	PARAM_PREAMP_OFF_CONTROL,   	"PARAM_PREAMP_OFF_CONTROL"
	PARAM_EXPOSURE_MODE,        	"PARAM_EXPOSURE_MODE"
	PARAM_PREFLASH,             	"PARAM_PREFLASH"
	PARAM_SHTR_CLOSE_DELAY,     	"PARAM_SHTR_CLOSE_DELAY"
	PARAM_SHTR_CLOSE_DELAY_UNIT,	"PARAM_SHTR_CLOSE_DELAY_UNIT"
	PARAM_SHTR_GATE_MODE,       	"PARAM_SHTR_GATE_MODE"
	PARAM_SHTR_OPEN_DELAY,      	"PARAM_SHTR_OPEN_DELAY"
	PARAM_SHTR_OPEN_MODE,       	"PARAM_SHTR_OPEN_MODE"
	PARAM_SHTR_RES,             	"PARAM_SHTR_RES"
	PARAM_SHTR_STATUS,          	"PARAM_SHTR_STATUS"
	PARAM_IO_ADDR,              	"PARAM_IO_ADDR"
	PARAM_IO_BITDEPTH,          	"PARAM_IO_BITDEPTH"
	PARAM_IO_DIRECTION,         	"PARAM_IO_DIRECTION"
	PARAM_IO_STATE,             	"PARAM_IO_STATE"
	PARAM_IO_TYPE,              	"PARAM_IO_TYPE"
	PARAM_LOGIC_OUTPUT,         	"PARAM_LOGIC_OUTPUT"
	PARAM_LOGIC_OUTPUT_INVERT,  	"PARAM_LOGIC_OUTPUT_INVERT"
	PARAM_CCS_STATUS,           	"PARAM_CCS_STATUS"
	PARAM_CUSTOM_TIMING,        	"PARAM_CUSTOM_TIMING"
	PARAM_EDGE_TRIGGER,         	"PARAM_EDGE_TRIGGER"
	PARAM_PAR_SHIFT_TIME,       	"PARAM_PAR_SHIFT_TIME"
	PARAM_PAR_SHIFT_INDEX,      	"PARAM_PAR_SHIFT_INDEX"
	PARAM_READOUT_TIME,         	"PARAM_READOUT_TIME"
	PARAM_SER_SHIFT_TIME,       	"PARAM_SER_SHIFT_TIME"
	PARAM_ADC_OFFSET,           	"PARAM_ADC_OFFSET"
	PARAM_BIT_DEPTH,            	"PARAM_BIT_DEPTH"
	PARAM_SPDTAB_INDEX,         	"PARAM_SPDTAB_INDEX"
	PARAM_ACCUM_CAPABLE,        	"PARAM_ACCUM_CAPABLE"
	PARAM_FRAME_CAPABLE,        	"PARAM_FRAME_CAPABLE"
	PARAM_MPP_CAPABLE,          	"PARAM_MPP_CAPABLE"
	PARAM_CAM_FW_VERSION,       	"PARAM_CAM_FW_VERSION"
	PARAM_CAM_FW_FULL_VERSION,  	"PARAM_CAM_FW_FULL_VERSION "
	PARAM_CHIP_NAME,            	"PARAM_CHIP_NAME"
	PARAM_CONTROLLER_ALIVE,     	"PARAM_CONTROLLER_ALIVE"
	PARAM_HEAD_SER_NUM_ALPHA,   	"PARAM_HEAD_SER_NUM_ALPHA"
	PARAM_PCI_FW_VERSION,       	"PARAM_PCI_FW_VERSION"
	PARAM_SERIAL_NUM,           	"PARAM_SERIAL_NUM"
	PARAM_TG_OPTION_BD_TYPE,    	"PARAM_TG_OPTION_BD_TYPE"
	};
*/

#define PARAM_FORCE_READOUT_MODE ((CLASS2<<16) + (TYPE_UNS32<<24) + 326)

rs_bool plGetErrorMessage(void);

int main() {
	uns32 paramList[3] = {1,2,3};
	rs_bool param_value;
	uns16 param_valueUns16;
	int16 param_valueInt16;
	uns32 param_valueUns32;
	flt64 param_valueFlt64;
	rs_bool rs;
	char cam_name[CAM_NAME_LEN];
	int16 hCam; 

	/* Init PVCam library and open the camera. */
	pl_pvcam_init();
	pl_cam_get_name(0, cam_name);
	pl_cam_open(cam_name, &hCam, OPEN_EXCLUSIVE);

	/*for (int i=0; i<3; i++) {
		//rs = pl_get_param(hCam, param, ATTR_AVAIL, &param_value);
		std::cout << paramList[i] << "\n";
	}*/

	std::cout << "Parameter\t\t\tisAvailable\n";
	
	try {
		rs = pl_get_param( hCam, PARAM_COOLING_MODE, ATTR_AVAIL, (void *)&param_value);
		std::cout << "PARAM_COOLING_MODE:\t\t" << param_value << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_EDGE_TRIGGER, ATTR_AVAIL, (void *)&param_value);
		std::cout << "PARAM_EDGE_TRIGGER:\t\t" << param_value << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_FORCE_READOUT_MODE, ATTR_AVAIL, (void *)&param_value);
		std::cout << "*CUSTOM PARAM_FORCE_READOUT_MODE:\t" << param_value << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_TEMP_SETPOINT, ATTR_AVAIL, (void *)&param_value);
		std::cout << "PARAM_TEMP_SETPOINT:\t\t" << param_value << "\n";
	}
	catch(...) {throw;}

	try {
		rs = pl_get_param( hCam, PARAM_SPDTAB_INDEX, ATTR_AVAIL, (void *)&param_value);
		std::cout << "PARAM_SPDTAB_INDEX:\t\t" << param_value << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_GAIN_INDEX, ATTR_AVAIL, (void *)&param_value);
		std::cout << "PARAM_GAIN_INDEX: \t\t" << param_value << "\n";
	}
	catch(...) {throw;}

	try {
		rs = pl_get_param( hCam, PARAM_CLEAR_CYCLES, ATTR_AVAIL, (void *)&param_value);
		std::cout << "PARAM_CLEAR_CYCLES:\t\t" << param_value << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_CUSTOM_CHIP, ATTR_AVAIL, (void *)&param_value);
		std::cout << "PARAM_CUSTOM_CHIP:\t\t" << param_value << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_SER_SIZE, ATTR_AVAIL, (void *)&param_value);
		std::cout << "PARAM_SER_SIZE:\t\t\t" << param_value << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_PAR_SIZE, ATTR_AVAIL, (void *)&param_value);
		std::cout << "PARAM_PAR_SIZE:\t\t\t" << param_value << "\n";
	}
	catch(...) {throw;}

	try {
		rs = pl_get_param( hCam, PARAM_READOUT_TIME, ATTR_AVAIL, (void *)&param_value);
		std::cout << "PARAM_READOUT_TIME:\t\t\t" << param_value << "\n";
	}
	catch(...) {throw;}

	
	// Check the gain attributes.
	std::cout << "\nPARAM_GAIN_INDEX\n";
	try {
		rs = pl_get_param( hCam, PARAM_GAIN_INDEX, ATTR_ACCESS, (void *)&param_valueUns16);
		std::cout << "Access Mode:\t"<< param_valueUns16;
		if (param_valueUns16 == ACC_ERROR) std::cout << " (ERROR)\n";
		else if (param_valueUns16 == ACC_READ_ONLY) std::cout << " (READ ONLY)\n";
		else if (param_valueUns16 == ACC_READ_WRITE) std::cout << " (READ/WRITE)\n";
		else if (param_valueUns16 == ACC_EXIST_CHECK_ONLY) std::cout << " (EXIST/CHECK ONLY)\n";
		else if (param_valueUns16 == ACC_WRITE_ONLY) std::cout << " (WRITE ONLY)\n";
		else std::cout << " (UNKNOWN)\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_GAIN_INDEX, ATTR_CURRENT, (void *)&param_valueInt16);
		std::cout << "Current value:\t" << param_valueInt16 << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_GAIN_INDEX, ATTR_DEFAULT, (void *)&param_valueInt16);
		std::cout << "Default value:\t" << param_valueInt16 << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_GAIN_INDEX, ATTR_INCREMENT, (void *)&param_valueInt16);
		std::cout << "Increment value:\t" << param_valueInt16 << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_GAIN_INDEX, ATTR_MIN, (void *)&param_valueInt16);
		std::cout << "Minimum value:\t" << param_valueInt16 << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_GAIN_INDEX, ATTR_MAX, (void *)&param_valueInt16);
		std::cout << "Maximum value:\t" << param_valueInt16 << "\n";
	}
	catch(...) {throw;}
	
	// Set gain to a bunch of different values.
	std::cout << "\nAllowable gain settings should be 1, 2, and 3.\n";
	std::cout << "Setting gain to 1 (should succeed)... ";
	param_valueInt16 = 1;
	try {
		rs = pl_set_param( hCam, PARAM_GAIN_INDEX, (void*)&param_valueInt16 );
	}
	catch(...) {throw;}
	plGetErrorMessage();
	std::cout << "Setting gain to 2 (should succeed)... ";
	param_valueInt16 = 2;
	try {
		rs = pl_set_param( hCam, PARAM_GAIN_INDEX, (void*)&param_valueInt16 );
	}
	catch(...) {throw;}
	plGetErrorMessage();
	std::cout << "Setting gain to 3 (should succeed)... ";
	param_valueInt16 = 3;
	try {
		rs = pl_set_param( hCam, PARAM_GAIN_INDEX, (void*)&param_valueInt16 );
	}
	catch(...) {throw;}
	plGetErrorMessage();
	std::cout << "Setting gain to 4 (should fail)... ";
	param_valueInt16 = 4;
	try {
		rs = pl_set_param( hCam, PARAM_GAIN_INDEX, (void*)&param_valueInt16 );
	}
	catch(...) {throw;}
	plGetErrorMessage();
	std::cout << "Setting gain to 5 (should fail)... ";
	param_valueInt16 = 5;
	try {
		rs = pl_set_param( hCam, PARAM_GAIN_INDEX, (void*)&param_valueInt16 );
	}
	catch(...) {throw;}
	plGetErrorMessage();
	std::cout << "Setting gain to 0 (should fail)... ";
	param_valueInt16 = 0;
	try {
		rs = pl_set_param( hCam, PARAM_GAIN_INDEX, (void*)&param_valueInt16 );
	}
	catch(...) {throw;}
	plGetErrorMessage();
	std::cout << "Setting gain to 1 again (should succeed again)... ";
	param_valueInt16 = 1;
	try {
		rs = pl_set_param( hCam, PARAM_GAIN_INDEX, (void*)&param_valueInt16 );
	}
	catch(...) {throw;}
	plGetErrorMessage();

	// Check readout speed attributes.
	std::cout << "\nPARAM_SPDTAB_INDEX\n";
	try {
		rs = pl_get_param( hCam, PARAM_SPDTAB_INDEX, ATTR_ACCESS, (void *)&param_valueUns16);
		std::cout << "Access Mode:\t"<< param_valueUns16;
		if (param_valueUns16 == ACC_ERROR) std::cout << " (ERROR)\n";
		else if (param_valueUns16 == ACC_READ_ONLY) std::cout << " (READ ONLY)\n";
		else if (param_valueUns16 == ACC_READ_WRITE) std::cout << " (READ/WRITE)\n";
		else if (param_valueUns16 == ACC_EXIST_CHECK_ONLY) std::cout << " (EXIST/CHECK ONLY)\n";
		else if (param_valueUns16 == ACC_WRITE_ONLY) std::cout << " (WRITE ONLY)\n";
		else std::cout << " (UNKNOWN)\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_SPDTAB_INDEX, ATTR_CURRENT, (void *)&param_valueInt16);
		std::cout << "Current value:\t" << param_valueInt16 << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_SPDTAB_INDEX, ATTR_DEFAULT, (void *)&param_valueInt16);
		std::cout << "Default value:\t" << param_valueInt16 << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_SPDTAB_INDEX, ATTR_INCREMENT, (void *)&param_valueInt16);
		std::cout << "Increment value:\t" << param_valueInt16 << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_SPDTAB_INDEX, ATTR_MIN, (void *)&param_valueInt16);
		std::cout << "Minimum value:\t" << param_valueInt16 << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_SPDTAB_INDEX, ATTR_MAX, (void *)&param_valueInt16);
		std::cout << "Maximum value:\t" << param_valueInt16 << "\n";
	}
	catch(...) {throw;}

	// Change readout speed to a bunch of values.
	std::cout << "\nAllowable readout speeds should be 0 (slow) and 1 (fast).\n";
	std::cout << "Setting readout speed to 0 (should succeed)... ";
	param_valueInt16 = 0;
	try {
		rs = pl_set_param( hCam, PARAM_SPDTAB_INDEX, (void*)&param_valueInt16 );
	}
	catch(...) {throw;}
	plGetErrorMessage();
	std::cout << "Setting readout speed to 1 (should succeed)... ";
	param_valueInt16 = 1;
	try {
		rs = pl_set_param( hCam, PARAM_SPDTAB_INDEX, (void*)&param_valueInt16 );
	}
	catch(...) {throw;}
	plGetErrorMessage();
	std::cout << "Setting readout speed to 2 (should fail)... ";
	param_valueInt16 = 2;
	try {
		rs = pl_set_param( hCam, PARAM_SPDTAB_INDEX, (void*)&param_valueInt16 );
	}
	catch(...) {throw;}
	plGetErrorMessage();
	std::cout << "Setting readout speed to 3 (should fail)... ";
	param_valueInt16 = 3;
	try {
		rs = pl_set_param( hCam, PARAM_SPDTAB_INDEX, (void*)&param_valueInt16 );
	}
	catch(...) {throw;}
	plGetErrorMessage();
	std::cout << "Setting readout speed to 4 (should fail)... ";
	param_valueInt16 = 4;
	try {
		rs = pl_set_param( hCam, PARAM_SPDTAB_INDEX, (void*)&param_valueInt16 );
	}
	catch(...) {throw;}
	plGetErrorMessage();
	std::cout << "Setting readout speed to 1 again (should succeed again)... ";
	param_valueInt16 = 1;
	try {
		rs = pl_set_param( hCam, PARAM_SPDTAB_INDEX, (void*)&param_valueInt16 );
	}
	catch(...) {throw;}
	plGetErrorMessage();
	std::cout << "Setting readout speed to -1 (should fail)... ";
	param_valueInt16 = -1;
	try {
		rs = pl_set_param( hCam, PARAM_SPDTAB_INDEX, (void*)&param_valueInt16 );
	}
	catch(...) {throw;}
	plGetErrorMessage();

	// Check readout time attributes.	
	std::cout << "\nPARAM_READOUT_TIME\n";
	try {
		rs = pl_get_param( hCam, PARAM_READOUT_TIME, ATTR_ACCESS, (void *)&param_valueUns16);
		std::cout << "Access Mode:\t"<< param_valueUns16;
		if (param_valueUns16 == ACC_ERROR) std::cout << " (ERROR)\n";
		else if (param_valueUns16 == ACC_READ_ONLY) std::cout << " (READ ONLY)\n";
		else if (param_valueUns16 == ACC_READ_WRITE) std::cout << " (READ/WRITE)\n";
		else if (param_valueUns16 == ACC_EXIST_CHECK_ONLY) std::cout << " (EXIST/CHECK ONLY)\n";
		else if (param_valueUns16 == ACC_WRITE_ONLY) std::cout << " (WRITE ONLY)\n";
		else std::cout << " (UNKNOWN)\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_READOUT_TIME, ATTR_CURRENT, (void *)&param_valueFlt64);
		std::cout << "Current value:\t" << param_valueFlt64 << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_READOUT_TIME, ATTR_DEFAULT, (void *)&param_valueFlt64);
		std::cout << "Default value:\t" << param_valueFlt64 << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_READOUT_TIME, ATTR_INCREMENT, (void *)&param_valueFlt64);
		std::cout << "Increment value:\t" << param_valueFlt64 << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_READOUT_TIME, ATTR_MIN, (void *)&param_valueFlt64);
		std::cout << "Minimum value:\t" << param_valueFlt64 << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_READOUT_TIME, ATTR_MAX, (void *)&param_valueFlt64);
		std::cout << "Maximum value:\t" << param_valueFlt64 << "\n";
	}
	catch(...) {throw;}

	/* Close the camera and uninitialize the library. */
	pl_cam_close( hCam );
	pl_pvcam_uninit();
	return 0;

}


rs_bool plGetErrorMessage(void) {
	rs_bool	rc;
	int16	err_code;
	char	msg[ERROR_MSG_LEN];
	
	err_code = pl_error_code();
	rc = pl_error_message( err_code, msg);

	std::cout << msg << std::endl;

	return rc;
}
