struct ButtonState {
    bool isDown;
    bool changed;
};

enum {
    BUTTON_UP,
    BUTTON_DOWN,
    BUTTON_W,
    BUTTON_S,

    BUTTON_COUNT, //Should be the last item
};

struct Input {
    ButtonState buttons [BUTTON_COUNT];
};
