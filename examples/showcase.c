

#include "gooey.h"
#include <stdio.h>

bool state = 0;
GooeyWindow *childWindow;
GooeyWindow *msgBox, *msgBox2;
GooeySignal signal;
GooeyCanvas *canvas;


void messageBoxCallback(int option)
{
   // LOG_INFO("%d", option);
}

void messageBox2Callback(int option)
{
   // LOG_INFO("2 %d", option);
}



void signal_callback(void *context, void *data)
{
   // LOG_INFO("Recieved signal %s %s", (char *)context, (char *)data);
}

void signal_callback2(void *context, void *data)
{
  //  LOG_INFO("Recieved signal %s %s", (char *)context, (char *)data);
}

void onButtonClick()
{
 //  LOG_INFO("Button clicked!");
}

void onCheckboxToggle(bool checked)
{
    printf("Checkbox toggled: %s\n", checked ? "Checked" : "Unchecked");
}

void onRadioButtonSelect(bool selected)
{
    printf("Radio button selected: %s\n", selected ? "Yes" : "No");
}

void onSliderChange(long int value)
{
    printf("Slider value changed: %ld\n", value);
}

void onDropdownChange(int selectedIndex)
{
    printf("Dropdown selected index: %d\n", selectedIndex);
}

void onTextChange(char *text)
{
    printf("Text changed: %s\n", text);
}
GooeyTheme theme;
void activateDarkTheme()
{
 //   GooeyWindow_SetTheme(win, "dark.json");
}

void activateLightTheme()
{
  //  GooeyWindow_SetTheme(win, "light.json");
}

void image_click_callback()
{
  //  LOG_INFO("Clicked!");
}

int main()
{
    Gooey_Init();

    GooeyWindow *win = GooeyWindow_Create("window", 800, 600, true);

    //GooeyWindow_SetContinuousRedraw(win);
   GooeyWindow_EnableDebugOverlay(win, true);

    GooeyMenu* menu = GooeyMenu_Set(win);

    GooeyMenuChild* file_child= GooeyMenu_AddChild(win, "File");

    GooeyMenuChild_AddElement(file_child, "New", NULL);
    GooeyMenuChild_AddElement(file_child, "Open", NULL);
    GooeyMenuChild_AddElement(file_child, "Save", NULL);
    GooeyMenuChild_AddElement(file_child, "Exit", NULL);

    GooeyMenuChild* settings_child= GooeyMenu_AddChild(win, "Settings");

    GooeyMenuChild_AddElement(settings_child, "New", NULL);
    GooeyMenuChild_AddElement(settings_child, "Open", NULL);
    GooeyMenuChild_AddElement(settings_child, "Save", NULL);
    GooeyMenuChild_AddElement(settings_child, "Exit", NULL);

    GooeyMenuChild* about_child= GooeyMenu_AddChild(win, "About");

    GooeyMenuChild_AddElement(about_child, "New", NULL);
    GooeyMenuChild_AddElement(about_child, "Open", NULL);
    GooeyMenuChild_AddElement(about_child, "Save", NULL);
    GooeyMenuChild_AddElement(about_child, "Exit", NULL);


    GooeyButton* button = GooeyButton_Create("Hello World", 40, 40, 120, 40, NULL);

    GooeyWindow_RegisterWidget(win, button);
    
    GooeyWindow_Run(1, win);


    GooeyWindow_Cleanup(1, win);
    

    return 0;
}