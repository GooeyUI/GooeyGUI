

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
    /*set_logging_enabled(true);
    set_minimum_log_level(DEBUG_LEVEL_INFO);

    Gooey_Init(GLPS);

    GooeyWindow *win = GooeyWindow_Create("Gooey Showcase", 400, 900, 1);
    GooeyTheme *theme = GooeyWindow_LoadTheme("dark.json");
    GooeyWindow_SetTheme(win, theme);
    GooeyImage_Add(win, "gooey.png",46, 80, 64, 64, image_click_callback);

   msgBox = GooeyMessageBox_Create("Exception thrown!", "This is a Simple MessageBox window, it is useful for displaying error messages, warnings and informational content!", MSGBOX_FAIL, messageBoxCallback);
 msgBox2 = GooeyMessageBox_Create("Exception thrown!", "This is a Simple MessageBox window, it is useful for displaying error messages, warnings and informational content!", MSGBOX_SUCCES, messageBox2Callback);

    signal = GooeySignal_Create();
    GooeySignal_Link(&signal, signal_callback, "hello");
    GooeySignal_Link(&signal, signal_callback2, "hello");
    GooeySignal_Emit(&signal, "world");

    GooeyButton_Add(win, "Click here", 50, 150, 80, 30, onButtonClick);
    GooeyCheckbox_Add(win, 50, 220, "Enable Option 1", onCheckboxToggle);
    GooeyCheckbox_Add(win, 50, 260, "Enable Option 2", onCheckboxToggle);
    GooeyCheckbox_Add(win, 50, 300, "Enable Option 3", onCheckboxToggle);

    GooeyRadioButton_Add(win, 200, 220, "Option A", onRadioButtonSelect);
    GooeyRadioButton_Add(win, 200, 260, "Option B", onRadioButtonSelect);
    GooeyRadioButton_Add(win, 200, 300, "Option C", onRadioButtonSelect);

    GooeySlider_Add(win, 50, 250, 350, 0, 100, true, onSliderChange);

    const char *options[] = {"Option 1", "Option 2", "Option 3"};
    GooeyDropdown_Add(win, 50, 350, 400, 30, options, 3, onDropdownChange);

    GooeyTextBox_Add(win, 50, 300, 200, 25, "test", onTextChange);

    GooeyMenu *menu = GooeyMenu_Set(win);
    GooeyMenuChild *fileMenu = GooeyMenu_AddChild(win, "File");
    GooeyMenuChild_AddElement(fileMenu, "Open", NULL);
    GooeyMenuChild_AddElement(fileMenu, "Save", NULL);

    GooeyMenuChild *editMenu = GooeyMenu_AddChild(win, "Settings");
    GooeyMenuChild_AddElement(editMenu, "Dark Theme", activateDarkTheme);
    GooeyMenuChild_AddElement(editMenu, "Light Theme", activateLightTheme);
    GooeyRadioButtonGroup *rbg = GooeyRadioButtonGroup_Create(win);
    GooeyRadioButtonGroup_AddChild(win, rbg, 50, 440, NULL, NULL);

    GooeyRadioButtonGroup_AddChild(win, rbg, 50, 470, NULL, NULL);

    GooeyRadioButtonGroup_AddChild(win, rbg, 50, 500, NULL, NULL);

    GooeyRadioButtonGroup_AddChild(win, rbg, 50, 530, NULL, NULL);

    LOG_PERFORMANCE(NULL);
    
    GooeyWindow_Run(3, win, msgBox, msgBox2);
    LOG_PERFORMANCE("GooeyWindow_Run");

    save_log_file("logs.txt");

    GooeyWindow_Cleanup(3, win, msgBox, msgBox2);*/
    

    return 0;
}