#include <windows.h>

//the boolean that runs the while loop to keep the program running while true
bool running = true;


//This function deals with the messages sent from the data class and behaves according
//to the message recieved by the switch statement below
LRESULT CALLBACK window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    LRESULT result = 0;//default result value

    /*I know I said that this wouldn't have explanations for the fundamentals, and I feel like 
    this could be considered as such. BUT, I didn't learn what this was until I followed the
    Youtube tutorial I follwed while writing this program
    https://learn.microsoft.com/en-us/cpp/c-language/switch-statement-c?view=msvc-170*/

    /*This is the switch statement that recieves the message from the window.*/
    switch (uMsg) {

        //minimize?
        case WM_CLOSE:

        /*I guess this is the message to close the window
        which ends up stopping the while loop keeping the program runnning*/
        case WM_DESTROY: {
            running = false;
        } break;

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

    while (running) {
        //Input
        MSG message;
        while (PeekMessage(&message, window, 0, 0, PM_REMOVE)) {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
        //Simulate

        //Render
    }
    return 0;
}