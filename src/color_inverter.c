#include <pebble.h>
#include "color_inverter.h"

#ifdef PBL_SDK_3

static const uint8_t s_default_palette[64] = {
    (uint8_t)0b11000000 | (uint8_t)(~GColorBlackARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorOxfordBlueARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorDukeBlueARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorBlueARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorDarkGreenARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorMidnightGreenARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorCobaltBlueARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorBlueMoonARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorIslamicGreenARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorJaegerGreenARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorTiffanyBlueARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorVividCeruleanARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorGreenARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorMalachiteARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorMediumSpringGreenARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorCyanARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorBulgarianRoseARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorImperialPurpleARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorIndigoARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorElectricUltramarineARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorArmyGreenARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorDarkGrayARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorLibertyARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorVeryLightBlueARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorKellyGreenARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorMayGreenARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorCadetBlueARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorPictonBlueARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorBrightGreenARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorScreaminGreenARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorMediumAquamarineARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorElectricBlueARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorDarkCandyAppleRedARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorJazzberryJamARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorPurpleARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorVividVioletARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorWindsorTanARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorRoseValeARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorPurpureusARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorLavenderIndigoARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorLimerickARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorBrassARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorLightGrayARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorBabyBlueEyesARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorSpringBudARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorInchwormARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorMintGreenARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorCelesteARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorRedARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorFollyARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorFashionMagentaARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorMagentaARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorOrangeARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorSunsetOrangeARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorBrilliantRoseARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorShockingPinkARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorChromeYellowARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorRajahARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorMelonARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorRichBrilliantLavenderARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorYellowARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorIcterineARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorPastelYellowARGB8),
    (uint8_t)0b11000000 | (uint8_t)(~GColorWhiteARGB8),
};

void s_grect_normalization(GRect *rect, GRect frame) {
    grect_standardize(rect);
    
    if (frame.size.w < rect->origin.x) {
        rect->origin.x = frame.size.w;
    }
    if (frame.size.h < rect->origin.y) {
        rect->origin.y = frame.size.h;
    }
    if (frame.size.w < (rect->origin.x + rect->size.w)) {
        rect->size.w = frame.size.w - rect->origin.x;
    }
    if (frame.size.h < (rect->origin.y + rect->size.h)) {
        rect->size.h = frame.size.h - rect->origin.y;
    }
}

static void s_color_inverter_with_palette(struct Layer *layer, GContext *ctx, GRect rect, const uint8_t palette[64]) {
    GRect layer_bounds = layer_get_bounds(layer);
    s_grect_normalization(&rect, layer_bounds);

    GBitmap *bmp = graphics_capture_frame_buffer(ctx);
    uint16_t padding = gbitmap_get_bytes_per_row(bmp) - layer_bounds.size.w;
    uint8_t *raw = gbitmap_get_data(bmp);

    for (int y = rect.origin.y; y < (rect.origin.y + rect.size.h); y++) {
        for (int x = rect.origin.x; x < (rect.origin.x + rect.size.w); x++) {
            int index = x + (y * (layer_bounds.size.w + padding));
            raw[index] = palette[raw[index] & 0x3F];
        }
    }

    graphics_release_frame_buffer(ctx, bmp);
}

void color_inverter(struct Layer *layer, GContext *ctx, GRect rect) {
    s_color_inverter_with_palette(layer, ctx, rect, s_default_palette);
}

#endif /* PBL_SDK_3 */