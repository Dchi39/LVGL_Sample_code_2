#include <lvgl.h>
#include <WiFi.h>
#include <SPI.h>
#include <Adafruit_NeoPixel.h>
#include "lovyanGfxSetup.h"
#include "ui/ui.h"
#include "ui/actions.h"
#include "ui/images.h"

//Define Global Variables

#define TFT_HOR_RES SCREEN_WIDTH
#define TFT_VER_RES SCREEN_HEIGHT
#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES / 10 * (LV_COLOR_DEPTH / 8))

#define PIXEL_LED 6

LGFX tft;
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

Adafruit_NeoPixel strip(5, PIXEL_LED, NEO_GRB + NEO_KHZ800);

//Display Flush Function

void my_disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map)
{
    uint32_t w = lv_area_get_width(area);
    uint32_t h = lv_area_get_height(area);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.writePixels((lgfx::rgb565_t *)px_map, w * h);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}

//Read Touchpad Function

void my_touchpad_read(lv_indev_t *indev, lv_indev_data_t *data)
{
    uint16_t x, y;
    bool touched = tft.getTouch(&x, &y);

    if (!touched)
    {
        data->state = LV_INDEV_STATE_RELEASED;
    }
    else
    {
        data->state = LV_INDEV_STATE_PRESSED;
        data->point.x = x;
        data->point.y = y;
    }
}

void setup()
{
    Serial.begin(115200);


    strip.begin();
    strip.clear();
    strip.show();

    tft.begin();
    tft.setRotation(0);
    tft.setBrightness(255);

    lv_init();
    lv_tick_set_cb((lv_tick_get_cb_t)millis);

    /* Display */
    lv_display_t *disp = lv_display_create(TFT_HOR_RES, TFT_VER_RES);
    lv_display_set_flush_cb(disp, my_disp_flush);
    lv_display_set_buffers(
        disp,
        draw_buf,
        NULL,
        sizeof(draw_buf),
        LV_DISPLAY_RENDER_MODE_PARTIAL);

    /* Touch */
    lv_indev_t *indev = lv_indev_create();
    lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(indev, my_touchpad_read);

    /* EEZ UI */
    create_screens();
    loadScreen(SCREEN_ID_MAIN);

    Serial.println("Setup complete");
}

void loop()
{
    lv_timer_handler();
    ui_tick();
    delay(5);

    // Example of handling the global event - When Pressing buttons, this will print the object address
    if (g_eez_event_available == true) {
        lv_obj_t *obj = lv_event_get_target(&g_eez_event);
        Serial.printf("Received event for object: %u\n", obj);
        g_eez_event_available = false;

        if(obj == objects.main00_btn1) {
            //Serial.println("Button 1 on Main Screen Pressed");
            lv_scr_load(objects.screen00);
         }else if(obj == objects.screen00_btn_back) {
            //Serial.println("Back Button on Screen 00 Pressed");
            lv_scr_load(objects.main);
         }
         else if(obj == objects.screen00_btnled) {
            Serial.println("LED Toggle Button Pressed");
            static bool led_on = false;
            led_on = !led_on;   
            if(led_on) {
                strip.fill(strip.Color(0, 150, 0)); // Green
            } else {
                strip.fill(strip.Color(0, 0, 0)); // Off
            }
            // Add additional actions here
         }else if(obj == objects.Screen00_btn_next) {
            //Serial.println("Next Button on Screen 00 Pressed");
            lv_scr_load(objects.screen01);  
        }else if(obj == objects.screen01_btn_back_1) {
            lv_scr_load(objects.screen00);
         }else if(obj == objects.screen01_btn_next_1) {
            // lv_scr_load(objects.main);
         }else if(obj == objects.screen01_arc_pwm) {
            int32_t angle = lv_arc_get_value(objects.screen01_arc_pwm);
            Serial.printf("Arc PWM Value: %3d\n", angle);
            lv_label_set_text(objects.screen01_label_pwm_value, "%d", angle);
         }else if(obj == objects.screen02_btn_back_2) {
            lv_scr_load(objects.screen01);
    }else if(obj == objects.screen02_btn_next_2) {
            lv_scr_load(objects.screen03);
        }
    }

    // if(objects.screen03_testarea) {
    //     const char *txt = lv_textarea_get_text(objects.screen03_testarea);
    //     Serial.printf("Textarea content: %s\n", txt);
    // }
}

