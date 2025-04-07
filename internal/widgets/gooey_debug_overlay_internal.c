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

#include "gooey_debug_overlay_internal.h"
#include "backends/gooey_backend_internal.h"
#include "event/gooey_event_internal.h"
#include <time.h>

#define OVERLAY_POS 20

void GooeyDebugOverlay_Draw(GooeyWindow *win)
{
    GooeyEvent *event = (GooeyEvent*) win->current_event;

    if (win->enable_debug_overlay)
    {
        int window_width, window_height;
        active_backend->GetWinDim(&window_width, &window_height, win->creation_id);

        // Calculate text positions
        int x_pos = 500;
        int y_pos = 50;
        int line_height = 18;

        // Draw semi-transparent background
        active_backend->FillRectangle(x_pos - 10, y_pos - 10,
                                      300, 150,
                                      0x3333AAAA, win->creation_id);
         y_pos += line_height;
        // Frame rate info
        char fps_text[64];
        snprintf(fps_text, sizeof(fps_text), "FPS: %.1f",
              active_backend->GetWinFramerate(win->creation_id));
        active_backend->DrawText(x_pos, y_pos, fps_text,
                                 win->active_theme->neutral, 0.27f, win->creation_id);
        y_pos += line_height;

        // Window info
        char win_text[64];
        snprintf(win_text, sizeof(win_text), "Window: %dx%d",
                 window_width, window_height);
        active_backend->DrawText(x_pos, y_pos, win_text,
                                 win->active_theme->neutral, 0.27f, win->creation_id);
        y_pos += line_height;

        // Mouse position
        char mouse_text[64];
        snprintf(mouse_text, sizeof(mouse_text), "Mouse: %d,%d",
                                                     event->mouse_move.x, event->mouse_move.y);
        active_backend->DrawText(x_pos, y_pos, mouse_text,
                                 win->active_theme->neutral, 0.27f, win->creation_id);
        y_pos += line_height;

        // Memory usage (simplified)
        char mem_text[64];
        snprintf(mem_text, sizeof(mem_text), "Memory: %.2f MB",
                 90000000 / (1024.0 * 1024.0));
        active_backend->DrawText(x_pos, y_pos, mem_text,
                                 win->active_theme->neutral, 0.27f, win->creation_id);
        y_pos += line_height;

        // Widget count
        char widget_text[64];
        snprintf(widget_text, sizeof(widget_text), "Widgets: %d",
                 win->widget_count);
        active_backend->DrawText(x_pos, y_pos, widget_text,
                                 win->active_theme->neutral, 0.27f, win->creation_id);
        y_pos += line_height;

        // Render stats
        char render_text[64];
        snprintf(render_text, sizeof(render_text), "Draw calls: %d",
                 2);
        active_backend->DrawText(x_pos, y_pos, render_text,
                                 win->active_theme->neutral, 0.27f, win->creation_id);
        y_pos += line_height;

        // System time
        time_t now = time(NULL);
        char time_text[64];
        strftime(time_text, sizeof(time_text), "%H:%M:%S", localtime(&now));
        active_backend->DrawText(x_pos, y_pos, time_text,
                                 win->active_theme->neutral, 0.27f, win->creation_id);
    }
}