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

    GooeyLayout *verticallayout_0 = GooeyLayout_Create(LAYOUT_VERTICAL,0, 0, 766, 520);
        GooeyLayout *horizontallayout_1 = GooeyLayout_Create(LAYOUT_HORIZONTAL,0, 0, 742, 135);
            GooeyTextbox *input_2 = GooeyTextBox_Create(0, 0, 100, 30, "", input_callback);
        GooeyLayout_AddChild(horizontallayout_1, input_2);
            GooeyButton *button_3 = GooeyButton_Create("Button", 0, 0, 100, 30, button_callback);
        GooeyLayout_AddChild(horizontallayout_1, button_3);
GooeyLayout_Build(horizontallayout_1); 
    GooeyLayout_AddChild(verticallayout_0, button_3);
        GooeyLabel *label_4 = GooeyLabel_Create("Label", 0.26f, 0, 0);
    GooeyLayout_AddChild(verticallayout_0, label_4);
        GooeySlider *slider_5 = GooeySlider_Create(0, 0, 100, 0, 100, false, slider_callback);
    GooeyLayout_AddChild(verticallayout_0, slider_5);
        GooeyButton *button_6 = GooeyButton_Create("Button", 0, 0, 100, 30, button_callback);
    GooeyLayout_AddChild(verticallayout_0, button_6);
GooeyLayout_Build(verticallayout_0); 

    // Register all widgets with the window
            GooeyWindow_RegisterWidget(win, input_2);
            GooeyWindow_RegisterWidget(win, button_3);
        GooeyWindow_RegisterWidget(win, horizontallayout_1);
        GooeyWindow_RegisterWidget(win, label_4);
        GooeyWindow_RegisterWidget(win, slider_5);
        GooeyWindow_RegisterWidget(win, button_6);
    GooeyWindow_RegisterWidget(win, verticallayout_0);

    GooeyWindow_Run(1, win);
    GooeyWindow_Cleanup(1, win);

    return 0;
}
