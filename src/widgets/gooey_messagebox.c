/*
 Copyright (c) 2024 Yassine Ahmed Ali

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include "widgets/gooey_messagebox.h"
#include "widgets/gooey_layout.h"
#include "widgets/gooey_label.h"
#include "widgets/gooey_button.h"
#include "backends/gooey_backend_internal.h"
#include "core/gooey_window.h"
#include "logger/pico_logger_internal.h"
#include "widgets/gooey_layout_internal.h"

void (*MessageBoxCallback[100])(int option);
GooeyWindow *CurrentMessageBox = NULL;

void __msgbox_ok(void)
{
    void (*callback)(int option) = MessageBoxCallback[active_backend->GetCurrentClickedWindow() - 1];
    if (callback)
    {
        callback(0);
    }
    active_backend->HideCurrentChild();
}

void __msgbox_cancel(void)
{

    void (*callback)(int option) = MessageBoxCallback[active_backend->GetCurrentClickedWindow() - 1];
    if (callback)
    {
        callback(1);
    }
    active_backend->HideCurrentChild();
}
GooeyWindow *GooeyMessageBox_Create(const char *title, const char *message, MSGBOX_TYPE type, void (*callback)(int option))
{


       GooeyWindow *window = GooeyWindow_Create(title, 500, 195, 0);

    GooeyWindow_MakeResizable(window, 0);
    MessageBoxCallback[window->creation_id] = callback;
    window->type = WINDOW_MSGBOX;
    unsigned long msgbox_title_color;

    switch (type)
    {
    case MSGBOX_INFO:
        msgbox_title_color = window->active_theme->info;
        break;
    case MSGBOX_FAIL:
        msgbox_title_color = window->active_theme->danger;
        break;
    case MSGBOX_SUCCES:
        msgbox_title_color = window->active_theme->success;
        break;
    default:
        break;
    }

    GooeyLayout *layout = GooeyLayout_Create(LAYOUT_VERTICAL, 20, 40, 400, 200);
    GooeyLayout *button_layout = GooeyLayout_Create(LAYOUT_HORIZONTAL, 0, 0, 200, 110);

    GooeyLabel *title_label = GooeyLabel_Create(title, 0.5f, 50, 50);
    GooeyWindow_RegisterWidget(window, title_label);
    GooeyLabel_SetColor(title_label, msgbox_title_color);
    GooeyLayout_AddChild(window, layout, title_label);
    GooeyLabel* message_label = GooeyLabel_Create(message, 0.3f, 0, 0);
    GooeyWindow_RegisterWidget(window, message_label);
    GooeyLayout_AddChild(window, layout, message_label);
    GooeyLayout_AddChild(window, layout, button_layout);
    GooeyButton *ok_button = GooeyButton_Create("Ok", 0, 0, 20, 40, __msgbox_ok);
    GooeyWindow_RegisterWidget(window, ok_button);

    GooeyButton_SetHighlight(ok_button, 1);
    GooeyLayout_AddChild(window, button_layout, ok_button);
    GooeyLayout_AddChild(window, button_layout, GooeyButton_Create("Cancel", 0, 0, 20, 40, __msgbox_cancel));

    GooeyLayout_Build(layout);

    return window;


    return NULL;
 
}

void GooeyMessageBox_Show(GooeyWindow *msgBoxWindow)
{
    CurrentMessageBox = msgBoxWindow;
    GooeyWindow_MakeVisible(msgBoxWindow, 1);
}
