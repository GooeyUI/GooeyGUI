#include <Gooey/gooey.h>

int main()
{
    Gooey_Init();
    GooeyWindow *win = GooeyWindow_Create("My Window", 800, 600, true);

    GooeyLayout *verticallayout_0 = GooeyLayout_Create(LAYOUT_VERTICAL, 0, 0, 777, 542);
        GooeyButton *button_1 = GooeyButton_Create("Button", 0, 0, 100, 30, NULL);
    GooeyLayout_AddChild(verticallayout_0, button_1);
        GooeySlider *slider_2 = GooeySlider_Create(0, 0, 150, 0, 100, false, NULL);
    GooeyLayout_AddChild(verticallayout_0, slider_2);
        GooeyTextbox *input_3 = GooeyTextBox_Create(0, 0, 150, 24, "", NULL);
    GooeyLayout_AddChild(verticallayout_0, input_3);
    GooeyLayout_Build(verticallayout_0);

        GooeyWindow_RegisterWidget(win, button_1);
        GooeyWindow_RegisterWidget(win, slider_2);
        GooeyWindow_RegisterWidget(win, input_3);
    GooeyWindow_RegisterWidget(win, verticallayout_0);

    GooeyWindow_Run(1, win);
    GooeyWindow_Cleanup(1, win);

    return 0;
}