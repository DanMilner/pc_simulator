/*
 * wheel_gui.c
 *
 *  Created on: 1 Aug. 2018
 *      Author: Daniel
 */
#include "wheel_gui.h"


void run_wheel_gui(void){
	/*Create a Label on the currently active screen*/
	lv_obj_t * label1 = lv_label_create(lv_scr_act(), NULL);

	/*Modify the Label's text*/
	lv_label_set_text(label1, "Steering Wheel! TEST");

	/* Align the Label to the center
	 * NULL means align on parent (which is the screen now)
	 * 0, 0 at the end means an x, y offset after alignment*/
	lv_obj_align(label1, NULL, LV_ALIGN_CENTER, 0, 0);
}
