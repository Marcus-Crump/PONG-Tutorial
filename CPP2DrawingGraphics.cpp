#include <windows.h>

#define global_variable static
#define internal static

global_variable bool running = true;

struct RenderState {
    int height, width;
    void* memory;

    BITMAPINFO bitmapinfo;
};

global_variable RenderState renderState;
#include "renderer.cpp"


LRESULT CALLBACK window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    LRESULT result = 0;

    
    switch (uMsg) {
        case WM_CLOSE:
        case WM_DESTROY: {
            running = false;
        } break;

        case WM_SIZE: {
            RECT rect;
            GetClientRect(hwnd, &rect);
            renderState.width = rect.right - rect.left;
            renderState.height = rect.bottom - rect.top;

            int bufferSize = renderState.width * renderState.height * sizeof(u32);

            if (renderState.memory) { VirtualFree(renderState.memory, 0, MEM_RELEASE); }
            renderState.memory = VirtualAlloc(0, bufferSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

            renderState.bitmapinfo.bmiHeader.biSize = sizeof(renderState.bitmapinfo.bmiHeader);
            renderState.bitmapinfo.bmiHeader.biWidth = renderState.width;
            renderState.bitmapinfo.bmiHeader.biHeight = renderState.height;
            renderState.bitmapinfo.bmiHeader.biPlanes = 1;
            renderState.bitmapinfo.bmiHeader.biBitCount = 32;
            renderState.bitmapinfo.bmiHeader.biCompression = BI_RGB;
        }break;

        default: {
            result = DefWindowProc(hwnd, uMsg, wParam, lParam);
        }
    }

    return result;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    //Create Window class
    WNDCLASS window_class = {};
    window_class.style = CS_HREDRAW | CS_VREDRAW;
    window_class.lpszClassName = "Game Window Class" ;
    window_class.lpfnWndProc = window_callback;

    //Register Class
    RegisterClass(&window_class);
    //Create Window
    HWND window = CreateWindow(window_class.lpszClassName, "My First Game", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, 0,0 , hInstance, 0);
    HDC hdc = GetDC(window);
    while (running) {
        //Input
        MSG message;
        while (PeekMessage(&message, window, 0, 0, PM_REMOVE)) {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
        //Simulate
        //sets background color
        clearScreen(0x000000);
        //various rectangles drawn within the window
        drawRect(0, 0, 1.6, 1.6, 0x660066);//V
        drawRect(0, 0, .8, .8, 0x000080);//I
        drawRect(0, 0, .4, .4, 0x0000ff);//B
        drawRect(0, 0, .2, .2, 0x00ff22);//G
        drawRect(0, 0, .1, .1, 0xffd700);//Y
        drawRect(0, 0, .05, .05, 0xffa500);//O
        drawRect(0, 0, .025, .025, 0xff0000);//R
        
        //renderBackground();
        //Render
        StretchDIBits(hdc, 0, 0, renderState.width, renderState.height, 0, 0, renderState.width, renderState.height, renderState.memory, &renderState.bitmapinfo, DIB_RGB_COLORS, SRCCOPY);
    }
    return 0;
}