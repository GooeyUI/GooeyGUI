/*
 Copyright (c) 2025 Yassine Ahmed Ali

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

#include "widgets/gooey_tabs.h"
#if (ENABLE_TABS)
#include "backends/gooey_backend_internal.h"
#include "logger/pico_logger_internal.h"
#include "widgets/gooey_tabs_internal.h"
#include "widgets/gooey_window_internal.h"

GooeyTabs *GooeyTabs_Create(int x, int y, int width, int height, bool is_sidebar)
{

    GooeyTabs *tabs_widget = calloc(1, sizeof(GooeyTabs));
    if (tabs_widget == NULL)
    {
        LOG_ERROR("Unable to allocate memory to tabs widget");
        return NULL;
    }
    *tabs_widget = (GooeyTabs){0};
    tabs_widget->core.type = WIDGET_TABS;
    tabs_widget->core.x = x;
    tabs_widget->core.y = y;
    tabs_widget->core.width = width;
    tabs_widget->core.height = height;
    tabs_widget->tabs = malloc(sizeof(GooeyTab) * MAX_TABS);
    tabs_widget->tab_count = 0;
    tabs_widget->active_tab_id = 0; // default active tab is the first one.
    tabs_widget->is_sidebar = is_sidebar;
    tabs_widget->is_open = false;
    tabs_widget->core.sprite = active_backend->CreateSpriteForWidget(x, y, width, height);

    return tabs_widget;
}

void GooeyTabs_Sidebar_Open(GooeyTabs *tabs_widget)
{
    if (tabs_widget->is_open)
        return;
    for (size_t i = 0; i < tabs_widget->tab_count; i++)
    {

        for (size_t j = 0; j < tabs_widget->tabs[i].widget_count; j++)
        {
            GooeyWidget *widget = (GooeyWidget *)tabs_widget->tabs[i].widgets[j];
            widget->x += TAB_WIDTH;
        }
    }
    tabs_widget->is_open = true;
}

void GooeyTabs_Sidebar_Close(GooeyTabs *tabs_widget)
{
    if (!tabs_widget->is_open)
        return;
    for (size_t i = 0; i < tabs_widget->tab_count; i++)
    {
        for (size_t j = 0; j < tabs_widget->tabs[i].widget_count; j++)
        {
            GooeyWidget *widget = (GooeyWidget *)tabs_widget->tabs[i].widgets[j];
            widget->x -= TAB_WIDTH;
        }
    }
    tabs_widget->is_open = false;
}

void GooeyTabs_InsertTab(GooeyTabs *tab_widget, char *tab_name)
{

    if (!tab_widget)
    {
        LOG_ERROR("Couldn't insert tab, tab widget is invalid.");
        return;
    }

    size_t tab_id = tab_widget->tab_count;
    GooeyTab *tab = &tab_widget->tabs[tab_widget->tab_count++];
    tab->tab_id = tab_id;
    tab->widgets = (void **)calloc(MAX_WIDGETS, sizeof(void *));
    tab->widget_count = 0;

    if (tab_name)
    {
        strncpy(tab->tab_name, tab_name, sizeof(tab->tab_name) - 1);
        tab->tab_name[sizeof(tab->tab_name) - 1] = '\0';
    }
    else
    {
        LOG_WARNING("Invalid tab name, sticking to default.");
        //  snprintf(tdWab->tab_name, sizeof(tab->tab_name), "Tab %ld", tab_id);
    }
}

void GooeyTabs_AddWidget(GooeyWindow *window, GooeyTabs *tabs, size_t tab_id, void *widget)
{
    GooeyTab *selected_tab = (GooeyTab *)&tabs->tabs[tab_id];
    if (!tabs || !selected_tab || !widget)
    {
        LOG_ERROR("Couldn't add widget.");
        return;
    }

    GooeyWidget *core = (GooeyWidget *)widget;
    if (!tabs->is_sidebar)
    {
        core->x += tabs->core.x;
        core->y += tabs->is_open ? tabs->core.y + TAB_HEIGHT : tabs->core.y;
    }
    else
    {
        core->x += tabs->is_open ? tabs->core.x + TAB_WIDTH : tabs->core.x;
        core->y += tabs->core.y;
    }

    selected_tab->widgets[selected_tab->widget_count++] = widget;
    GooeyWindow_Internal_RegisterWidget(window, widget);
}

void GooeyTabs_SetActiveTab(GooeyTabs *tabs, size_t tab_id)
{
    if (!tabs || tab_id > tabs->tab_count)
    {
        LOG_ERROR("Couldn't set active tab.");
        return;
    }

    tabs->active_tab_id = tab_id;
}
#endif