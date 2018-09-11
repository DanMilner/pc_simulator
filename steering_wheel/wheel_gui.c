/*
 * wheel_gui.c
 *
 *  Created on: 1 Aug. 2018
 *      Author: Daniel
 */
#include "wheel_gui.h"

static lv_obj_t * gauge1;
int val = 0;

static lv_res_t btn_click_action(lv_obj_t * btn)
{
	lv_gauge_set_value(gauge1, 0, val);
	val+=10;

    return LV_RES_OK;
}

static void write_create(lv_obj_t *parent)
{
	static lv_color_t needle_colors[] = {LV_COLOR_BLUE};

	gauge1 = lv_gauge_create(parent, NULL);
	lv_gauge_set_needle_count(gauge1, 1, needle_colors);
	lv_obj_align(gauge1, NULL, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_size(gauge1, 150,150);
    lv_page_set_style(parent, LV_PAGE_STYLE_BG, &lv_style_transp_fit);
    lv_page_set_style(parent, LV_PAGE_STYLE_SCRL, &lv_style_transp_fit);
}

static void memes_create(lv_obj_t *parent)
{
	lv_obj_t * label = lv_label_create(parent, NULL);
	lv_label_set_text(label, "Hey");
	lv_obj_align(label, NULL, LV_ALIGN_IN_TOP_MID, 0, 5);

	lv_obj_t * btn1 = lv_btn_create(parent, NULL);
	lv_cont_set_fit(btn1, true, true); /*Enable resizing horizontally and vertically*/
	lv_obj_align(btn1, label, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
	lv_obj_set_free_num(btn1, 1);   /*Set a unique number for the button*/
	lv_btn_set_action(btn1, LV_BTN_ACTION_CLICK, btn_click_action);
}

void run_wheel_gui(void){
    lv_obj_t *tv = lv_tabview_create(lv_scr_act(), NULL);
    lv_obj_t *tab1 = lv_tabview_add_tab(tv, "One");
    lv_obj_t *tab2 = lv_tabview_add_tab(tv, "Two");
    lv_obj_t *tab3 = lv_tabview_add_tab(tv, "Three");
    lv_obj_t *tab4 = lv_tabview_add_tab(tv, "Four");
    lv_obj_t *tab5 = lv_tabview_add_tab(tv, "Five");
    lv_obj_t *tab6 = lv_tabview_add_tab(tv, "Six");

    write_create(tab1);
    memes_create(tab2);
}

void set_gauge_value(int value){
	lv_gauge_set_value(gauge1, 0, value);
}
