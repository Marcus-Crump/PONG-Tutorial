#include "util.cpp"

internal void 
renderBackground () {
    unsigned int* pixel = (unsigned int*)renderState.memory;
        for (int y = 0; y < renderState.height; y++) {
            for (int x = 0; x < renderState.width; x++) {
                *pixel++ = 0xff00ff*x + 0x00ff00*y;
            }
        }
}

internal void
clearScreen(unsigned int color) {
    unsigned int* pixel = (unsigned int*)renderState.memory;
        for (int y = 0; y < renderState.height; y++) {
            for (int x = 0; x < renderState.width; x++) {
                *pixel++ = color;
            }
        }
}

internal void
drawRectinPixels ( int x0, int y0, int x1, int y1, u32 color) {
    x0 = clamp(0, x0, renderState.width);
    x1 = clamp(0, x1, renderState.width);
    y0 = clamp(0, y0, renderState.height);
    y1 = clamp(0, y1, renderState.height);
    for (int y = y0; y < y1; y++) {
        u32* pixel = (unsigned int*)renderState.memory + x0 + y*renderState.width;
        for (int x = x0; x < x1; x++) {
            *pixel++ = color;
        }
    }
}

global_variable float renderScale = 0.01f;

internal void
drawRect(float x, float y, float halfSizeX, float halfSizeY, u32 color) {

    x *= renderState.height*renderScale;
    y *= renderState.height*renderScale;
    halfSizeX *= renderState.height*renderScale;
    halfSizeY *= renderState.height*renderScale;

    x += renderState.width / 2.f;
    y += renderState.height/ 2.f;
    //Change to pixels 
    int x0 = x - halfSizeX;
    int x1 = x + halfSizeX;
    int y0 = y - halfSizeY;
    int y1 = y + halfSizeY;
    drawRectinPixels(x0, y0, x1, y1, color);
}