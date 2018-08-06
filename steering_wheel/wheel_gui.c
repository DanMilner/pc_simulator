/*
 * wheel_gui.c
 *
 *  Created on: 1 Aug. 2018
 *      Author: Daniel
 */
#include "wheel_gui.h"

LV_FONT_DECLARE(lv_font_dejavu_40);

void run_wheel_gui(void){
	//Create style with large font.
	lv_style_t style;
	lv_style_copy(&style, &lv_style_plain);
	style.text.font = &lv_font_dejavu_40;

	//Create speed label
	lv_obj_t * speed_label = lv_label_create(lv_scr_act(), NULL);
	lv_label_set_text(speed_label, "Speed");
	lv_label_set_style(speed_label, &style);
	lv_obj_align(speed_label, NULL, LV_ALIGN_CENTER, 0, 0);

	//create battery label
	lv_obj_t * battery1 = lv_label_create(lv_scr_act(), NULL);
	lv_label_set_text(battery1, "100%"SYMBOL_BATTERY_FULL);
	lv_label_set_style(battery1, &style);
	lv_obj_align(battery1, NULL, LV_LABEL_ALIGN_LEFT, -160, -130);
}
