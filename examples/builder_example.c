#include <Gooey/gooey.h>

// Callback functions
void button_callback()
{
    printf("Button clicked!\n");
}

void slider_callback(int value)
{
    printf("Slider value: %d\n", value);
}

void checkbox_callback(bool checked)
{
    printf("Checkbox %s\n", checked ? "checked" : "unchecked");
}

void input_callback(const char* text)
{
    printf("Input changed: %s\n", text);
}

int main()
{
    Gooey_Init();
    GooeyWindow *win = GooeyWindow_Create("Hello World", 800, 600, true);

    GooeyDropSurface *dropsurface_0 = GooeyDropSurface_Create(11, 10, 150, 150, "testing..", NULL);

    // Register all widgets with the window
    GooeyWindow_RegisterWidget(win, dropsurface_0);

    GooeyWindow_Run(1, win);
    GooeyWindow_Cleanup(1, win);

    return 0;
}
