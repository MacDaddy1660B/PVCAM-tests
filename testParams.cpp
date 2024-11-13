#include <iostream>

#include "pvcam/master.h"
#include "pvcam/pvcam.h"

/*
 * AUTHOR:
 * Gordon A. MacDonald, Ph.D, 
 * Apache Point Observatory
 * Sunspot, NM
 *
 * This simple test program checks if
 * the following Class 2 Parameter IDs
 * are available to PVCAM and camera:
 * 
 * 	PARAM_COOLING_MODE
 * 	PARAM_EDGE_TRIGGER
 * 	*CUSTOM PARAM_FORCE_READOUT_MODE
 * 	PARAM_TEMP_SETPOINT
 * 	PARAM_SPDTAB_INDEX
 * 	PARAM_GAIN_INDEX
 * 	PARAM_CLEAR_CYCLES
 * 	PARAM_CUSTOM_CHIP
 * 	PARAM_SER_SIZE
 * 	PARAM_PAR_SIZE
 * 
 * Note: PARAM_FORCE_READOUT_MODE is an undocumented feature
 * for this camera. It is defined in the Agile ICC code and
 * again below for the purposes of this test.
 * 
 * The test also prints the following information about the 
 * PARAM_GAIN_INDEX parameter:
 * 
 * 	Access Mode
 * 	Current value
 * 	Default value
 * 	Increment value
 * 	Minimum value
 * 	Maximum value
 *
 * Note: access mode reports PARAM_GAIN_INDEX is
 * is read-only, read-write, exists, or write-only.
 */

// We need this constant for undocumented camera features,
// as stated by RO and Anjum in the original Agile ICC code.
#define PARAM_FORCE_READOUT_MODE ((CLASS2<<16) + (TYPE_UNS32<<24) + 326)

int main() {
	// Some variables for parameter returns.
	rs_bool param_value;
	uns16 param_valueUns16;
	int16 param_valueInt16;
	// Variable for return status.
	rs_bool rs;
	// This char array will become the camera name.
	char cam_name[CAM_NAME_LEN];
	// Camera handle.
	int16 hCam; 

	/* Init PVCam library and open the camera. */
	pl_pvcam_init();
	pl_cam_get_name(0, cam_name);
	pl_cam_open(cam_name, &hCam, OPEN_EXCLUSIVE);

	// Start printing the ATTR_AVAIL results for each parameter.
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

	// Start printing the detailed information about PARAM_GAIN_INDEX	
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
		std::cout << "Current value:\t" << param_value << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_GAIN_INDEX, ATTR_DEFAULT, (void *)&param_valueInt16);
		std::cout << "Default value:\t" << param_value << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_GAIN_INDEX, ATTR_INCREMENT, (void *)&param_valueInt16);
		std::cout << "Increment value:\t" << param_value << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_GAIN_INDEX, ATTR_MIN, (void *)&param_valueInt16);
		std::cout << "Minimum value:\t" << param_value << "\n";
	}
	catch(...) {throw;}
	
	try {
		rs = pl_get_param( hCam, PARAM_GAIN_INDEX, ATTR_MAX, (void *)&param_valueInt16);
		std::cout << "Maximum value:\t" << param_value << "\n";
	}
	catch(...) {throw;}
	/* Close the camera and uninitialize the library. */
	pl_cam_close( hCam );
	pl_pvcam_uninit();
	return 0;

}
