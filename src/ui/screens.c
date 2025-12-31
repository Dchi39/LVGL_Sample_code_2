#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff33b6b2), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 213, 49);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffce2929), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Welcome to my Home Page");
        }
        {
            // Main00Btn
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.main00_btn = obj;
            lv_obj_set_pos(obj, 609, 374);
            lv_obj_set_size(obj, 163, 83);
            lv_obj_add_event_cb(obj, action_set_global_eez_event, LV_EVENT_CLICKED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1a415f), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Next");
                }
            }
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
}

void create_screen_screen00() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen00 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff309954), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Screen00BtnNext
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.screen00_btn_next = obj;
            lv_obj_set_pos(obj, 609, 374);
            lv_obj_set_size(obj, 163, 83);
            lv_obj_add_event_cb(obj, action_set_global_eez_event, LV_EVENT_CLICKED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1a415f), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Next");
                }
            }
        }
        {
            // Screen00BtnBack
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.screen00_btn_back = obj;
            lv_obj_set_pos(obj, 106, 375);
            lv_obj_set_size(obj, 163, 83);
            lv_obj_add_event_cb(obj, action_set_global_eez_event, LV_EVENT_CLICKED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1a415f), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Back");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 323, 58);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff834c10), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Screen Page");
        }
        {
            // Screen00BtnLed
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.screen00_btn_led = obj;
            lv_obj_set_pos(obj, 350, 200);
            lv_obj_set_size(obj, 163, 83);
            lv_obj_add_event_cb(obj, action_set_global_eez_event, LV_EVENT_CLICKED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff745a20), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff3b421), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj2 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "LED ON");
                }
            }
        }
    }
    
    tick_screen_screen00();
}

void tick_screen_screen00() {
}

void create_screen_screen01() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen01 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe1b3b3), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 293, 56);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff834c10), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Dulitha Page");
        }
        {
            // Screen01ArcPwm
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.screen01_arc_pwm = obj;
            lv_obj_set_pos(obj, 293, 140);
            lv_obj_set_size(obj, 258, 259);
            lv_arc_set_value(obj, 25);
            lv_obj_add_event_cb(obj, action_set_global_eez_event, LV_EVENT_RELEASED, (void *)0);
        }
        {
            // Screen01BtnBack_1
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.screen01_btn_back_1 = obj;
            lv_obj_set_pos(obj, 101, 370);
            lv_obj_set_size(obj, 163, 83);
            lv_obj_add_event_cb(obj, action_set_global_eez_event, LV_EVENT_CLICKED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1a415f), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Back");
                }
            }
        }
        {
            // Screen01BtnNext_1
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.screen01_btn_next_1 = obj;
            lv_obj_set_pos(obj, 609, 374);
            lv_obj_set_size(obj, 163, 83);
            lv_obj_add_event_cb(obj, action_set_global_eez_event, LV_EVENT_CLICKED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1a415f), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Next");
                }
            }
        }
        {
            // Screen01LabelPWM
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.screen01_label_pwm = obj;
            lv_obj_set_pos(obj, 391, 240);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffd80d0d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "100%");
        }
    }
    
    tick_screen_screen01();
}

void tick_screen_screen01() {
}

void create_screen_screen02() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen02 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 315, 69);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff834c10), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "LAST Page");
        }
        {
            // Screen01BtnBack_2
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.screen01_btn_back_2 = obj;
            lv_obj_set_pos(obj, 97, 368);
            lv_obj_set_size(obj, 163, 83);
            lv_obj_add_event_cb(obj, action_set_global_eez_event, LV_EVENT_CLICKED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1a415f), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Back");
                }
            }
        }
        {
            // Screen02BtnNext_2
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.screen02_btn_next_2 = obj;
            lv_obj_set_pos(obj, 604, 368);
            lv_obj_set_size(obj, 163, 83);
            lv_obj_add_event_cb(obj, action_set_global_eez_event, LV_EVENT_CLICKED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1a415f), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Next");
                }
            }
        }
        {
            // Screen02Bar
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.screen02_bar = obj;
            lv_obj_set_pos(obj, 203, 216);
            lv_obj_set_size(obj, 469, 49);
            lv_bar_set_range(obj, 0, 4095);
            lv_bar_set_value(obj, 100, LV_ANIM_ON);
        }
        {
            // Screen2_BarVal
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.screen2_bar_val = obj;
            lv_obj_set_pos(obj, 394, 281);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff834c10), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "4095");
        }
    }
    
    tick_screen_screen02();
}

void tick_screen_screen02() {
}

void create_screen_screen03() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen03 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Screen03_Testarea
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.screen03_testarea = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 153);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, action_set_global_eez_event, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Screen03_keyboard
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.screen03_keyboard = obj;
            lv_obj_set_pos(obj, 11, 153);
            lv_obj_set_size(obj, 764, 327);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_event_cb(obj, action_set_global_eez_event, LV_EVENT_CANCEL, (void *)0);
            lv_obj_add_event_cb(obj, action_set_global_eez_event, LV_EVENT_READY, (void *)0);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_screen03();
}

void tick_screen_screen03() {
}



typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_screen00,
    tick_screen_screen01,
    tick_screen_screen02,
    tick_screen_screen03,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_screen00();
    create_screen_screen01();
    create_screen_screen02();
    create_screen_screen03();
}
