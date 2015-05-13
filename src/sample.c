#include <pebble.h>
#include "color_inverter.h"
    
static Window *window;
static Layer *layer;
static bool is_invert = false;

static void click_handler(ClickRecognizerRef recognizer, void *context) {
    is_invert = is_invert == true ? false : true;
    layer_mark_dirty(layer);
}

static void click_config_provider(void *context) {
    window_single_click_subscribe(BUTTON_ID_SELECT, click_handler);
    window_single_click_subscribe(BUTTON_ID_UP, click_handler);
    window_single_click_subscribe(BUTTON_ID_DOWN, click_handler);
}

static void layer_update_proc(struct Layer *layer, GContext *ctx) {
#ifdef PBL_SDK_3
    GRect bounds = layer_get_bounds(layer);
    uint16_t rect_h = bounds.size.h / 64;

    for (uint16_t i = 0; i < 64; i++) {
        graphics_context_set_fill_color(ctx, (GColor8){.argb = 0b11000000 + i});
        graphics_fill_rect(ctx, GRect(0, i * rect_h, bounds.size.w, rect_h), 0, GCornerNone);
    }

    if (is_invert == true) {
        color_inverter(layer, ctx, GRect(bounds.size.w/2, 0, bounds.size.w/2, bounds.size.h));
    }
#endif /* PBL_SDK_3 */
}

static void window_load(Window *window) {
    Layer *window_layer = window_get_root_layer(window);
    GRect window_bounds = layer_get_bounds(window_layer);

    layer = layer_create(window_bounds);
    layer_set_update_proc(layer, layer_update_proc);
    layer_add_child(window_layer, layer);
}

static void window_unload(Window *window) {
    layer_destroy(layer);
}

static void init(void) {
    window = window_create();
    window_set_click_config_provider(window, click_config_provider);
    window_set_window_handlers(window, (WindowHandlers) {
        .load = window_load,
        .unload = window_unload,
    });
    const bool animated = true;
    window_stack_push(window, animated);
}

static void deinit(void) {
    window_destroy(window);
}

int main(void) {
    init();
    app_event_loop();
    deinit();
}