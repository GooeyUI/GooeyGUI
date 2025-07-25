#include "widgets/gooey_textbox_internal.h"
#if (ENABLE_TEXTBOX)
#include "backends/gooey_backend_internal.h"
#include "virtual/gooey_keyboard_internal.h"
#include "event/gooey_event_internal.h"
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

void GooeyTextbox_Draw(GooeyWindow *win)
{
  for (size_t index = 0; index < win->textboxes_count; ++index)
  {
    GooeyTextbox *textbox = (GooeyTextbox *)win->textboxes[index];
    if (!textbox->core.is_visible)
      continue;

    active_backend->FillRectangle(textbox->core.x, textbox->core.y,
                                  textbox->core.width, textbox->core.height,
                                  win->active_theme->base, win->creation_id,
                                  false, 0.0f, textbox->core.sprite);

    active_backend->DrawRectangle(textbox->core.x, textbox->core.y,
                                  textbox->core.width, textbox->core.height,
                                  textbox->focused ? win->active_theme->primary
                                                   : win->active_theme->neutral,
                                  1.0f, win->creation_id, false, 0.0f, textbox->core.sprite);

    int text_x = textbox->core.x + 5;
    int text_y = textbox->core.y + (textbox->core.height / 2) + 5;

    int max_text_width = textbox->core.width - 10;
    size_t len = strlen(textbox->text);
    size_t start_index = textbox->scroll_offset;

    while (start_index < len &&
           active_backend->GetTextWidth(textbox->text + start_index,
                                        len - start_index) > max_text_width)
    {
      start_index++;
    }

    char display_text[256];
    strncpy(display_text, textbox->text + start_index,
            sizeof(display_text) - 1);
    display_text[sizeof(display_text) - 1] = '\0';

    if (textbox->is_password)
    {
      memset(display_text, '*', strlen(display_text));
    }

    active_backend->DrawText(text_x, text_y, display_text,
                             win->active_theme->neutral, 0.27f,
                             win->creation_id, textbox->core.sprite);

    if (textbox->focused)
    {
      int cursor_x = text_x + active_backend->GetTextWidth(display_text, strlen(display_text) + textbox->cursor_pos);

      active_backend->DrawLine(cursor_x, textbox->core.y + 5, cursor_x,
                               textbox->core.y + textbox->core.height - 5,
                               win->active_theme->neutral, win->creation_id, textbox->core.sprite);
    }
    else if (textbox->placeholder[0] != '\0' && strlen(textbox->text) == 0)
    {
      active_backend->DrawText(text_x, text_y, textbox->placeholder,
                               win->active_theme->neutral, 0.27f,
                               win->creation_id, textbox->core.sprite);
    }
  }
}

void GooeyTextbox_HandleKeyPress(GooeyWindow *win, void *key_event)
{
  if (!win || !key_event)
    return;

  GooeyEvent *event = (GooeyEvent *)key_event;
  static bool is_capslock_on = false;
  char *buf = event->key_press.value;

  for (size_t i = 0; i < win->textboxes_count; i++)
  {
    if (!win->textboxes[i] || !win->textboxes[i]->focused)
      continue;

    size_t text_max = sizeof(win->textboxes[i]->text) - 1;
    size_t len = strnlen(win->textboxes[i]->text, text_max);

    switch (event->key_press.keycode)
    {
    case 22: 
      if (len > 0)
      {
        int abs_pos = (int)len + win->textboxes[i]->cursor_pos;
        if (abs_pos > 0)
        {
          memmove(&win->textboxes[i]->text[abs_pos - 1],
                  &win->textboxes[i]->text[abs_pos], len - abs_pos + 1);

          if (win->textboxes[i]->scroll_offset > 0)
            win->textboxes[i]->scroll_offset--;

          if (win->textboxes[i]->callback)
            win->textboxes[i]->callback(win->textboxes[i]->text);
        }
      }
      break;

    case 36: 
      win->textboxes[i]->focused = false;
      if (win->vk)
        GooeyVK_Internal_Hide(win->vk);
      break;

    case 66: 
      is_capslock_on = !is_capslock_on;
      break;

    case 65: 
      if (len < text_max)
      {
        int abs_pos = (int)len + win->textboxes[i]->cursor_pos;
        if (abs_pos < (int)text_max)
        {
          memmove(&win->textboxes[i]->text[abs_pos + 1],
                  &win->textboxes[i]->text[abs_pos], len - abs_pos + 1);
          win->textboxes[i]->text[abs_pos] = ' ';

          if (win->textboxes[i]->callback)
            win->textboxes[i]->callback(win->textboxes[i]->text);
        }
      }
      break;

    case 23: 
      break;

    case 113: 
      if (win->textboxes[i]->cursor_pos > -(int)len)
        win->textboxes[i]->cursor_pos--;
      break;

    case 114: 
      if (win->textboxes[i]->cursor_pos < 0)
        win->textboxes[i]->cursor_pos++;
      break;

    default:
      if (buf && isprint((unsigned char)buf[0]) && len < text_max)
      {
        char ch = buf[0];
        if (is_capslock_on && islower((unsigned char)ch))
          ch = toupper((unsigned char)ch);

        int abs_pos = (int)len + win->textboxes[i]->cursor_pos;
        if (abs_pos >= 0 && abs_pos <= (int)len)
        {
          if (len > 0 && abs_pos < (int)len)
          {
            memmove(&win->textboxes[i]->text[abs_pos + 1],
                    &win->textboxes[i]->text[abs_pos], len - abs_pos + 1);
          }

          win->textboxes[i]->text[abs_pos] = ch;

          len = strnlen(win->textboxes[i]->text, text_max);

          if (win->textboxes[i]->callback)
            win->textboxes[i]->callback(win->textboxes[i]->text);

          int text_width = active_backend->GetTextWidth(win->textboxes[i]->text, len + 1);
          int max_text_width = win->textboxes[i]->core.width - 10;

          if (text_width > max_text_width && win->textboxes[i]->cursor_pos == 0)
            win->textboxes[i]->scroll_offset++;
        }
      }
      break;
    }
  }
}

bool GooeyTextbox_HandleClick(GooeyWindow *win, int x, int y)
{
  for (size_t i = 0; i < win->textboxes_count; i++)
  {
    GooeyTextbox *textbox = win->textboxes[i];
    if (!textbox || !textbox->core.is_visible)
      continue;

    if (x >= textbox->core.x && x <= textbox->core.x + textbox->core.width &&
        y >= textbox->core.y && y <= textbox->core.y + textbox->core.height)
    {
      textbox->focused = true;

      
      if (win->vk && !win->vk->is_shown)
      {
        GooeyVK_Internal_Show(win->vk);
        
        GooeyVK_Internal_SetText(win->vk, textbox->text);
      }

      for (size_t j = 0; j < win->textboxes_count; j++)
      {
        if (j != i)
          win->textboxes[j]->focused = false;
      }
      return true;
    }

    
    for (size_t j = 0; j < win->textboxes_count; j++)
    {
      if (j != i)
        win->textboxes[j]->focused = false;
    }
  }
  return false;
}

void GooeyTextbox_Internal_HandleVK(GooeyWindow* win)
{
  if(!win || !win->vk) return;
  for (size_t i = 0; i < win->textboxes_count; ++i)
  {
    GooeyTextbox *textbox = win->textboxes[i];
    if (!textbox || !textbox->core.is_visible)
      continue;

      // attribute VK output to Focused textbox
      strncpy(textbox->text, GooeyVK_Internal_GetText(win->vk), sizeof(textbox->text));
  }
}

void GooeyTextbox_HandleHover(GooeyWindow *win, int x, int y)
{
  static bool was_hovered_over = false;
  bool is_hovered_over = false;

  for (size_t i = 0; i < win->textboxes_count; ++i)
  {
    GooeyTextbox *textbox = win->textboxes[i];
    if (!textbox || !textbox->core.is_visible)
      continue;

    if (x >= textbox->core.x && x <= textbox->core.x + textbox->core.width &&
        y >= textbox->core.y && y <= textbox->core.y + textbox->core.height)
    {
      is_hovered_over = true;
      break;
    }
  }

  if (is_hovered_over != was_hovered_over)
  {
    active_backend->CursorChange(is_hovered_over ? GOOEY_CURSOR_TEXT : GOOEY_CURSOR_ARROW);
    was_hovered_over = is_hovered_over;
  }
}

#endif 
