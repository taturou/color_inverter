#pragma once

#ifdef PBL_SDK_3

/*
 * This function inverts the color of the frame of the layer.
 * Call me in a LayerUpdateProc function.
 */
void color_inverter(struct Layer *layer, GContext *ctx, GRect frame);

#endif /* PBL_SDK_3 */