#ifndef GOOEY_TEXTBOX_INTERNAL_H
#define GOOEY_TEXTBOX_INTERNAL_H

#include "common/gooey_common.h"
#include <stdbool.h>

#if (ENABLE_TEXTBOX)

/**
 * @brief Draws the textbox on the window.
 *
 * This function renders the textbox on the specified window. It should be called after
 * the textbox's state has been updated to reflect the changes visually.
 *
 * @param win The window to draw the textbox on.
 */
void GooeyTextbox_Draw(GooeyWindow *win);
void GooeyTextbox_Internal_HandleVK(GooeyWindow *win);
/**
 * @brief Handles textbox click events.
 *
 * This function is responsible for detecting and processing click events on the textbox.
 * If the textbox is clicked, it will enter an active state.
 *
 * @param win The window containing the textbox.
 * @param x The x-coordinate of the click event.
 * @param y The y-coordinate of the click event.
 * 
 * @return True if the textbox was clicked, false otherwise.
 */
bool GooeyTextbox_HandleClick(GooeyWindow *win, int x, int y);

/**
 * @brief Handles key press events for the textbox.
 *
 * This function processes key events, allowing the user to type text inside the textbox.
 * The textbox's content is updated in real-time as the user types.
 *
 * @param win The window containing the textbox.
 * @param event The key event to handle.
 */
void GooeyTextbox_HandleKeyPress(GooeyWindow *win, void *event);

/**
 * @brief Handles hover events over the textbox.
 *
 * @param win The window containing the textbox.
 * @param x The x-coordinate of the mouse cursor.
 * @param y The y-coordinate of the mouse cursor.
 */
void GooeyTextbox_HandleHover(GooeyWindow *win, int x, int y);

#endif // ENABLE_TEXTBOX

#endif /* GOOEY_TEXTBOX_INTERNAL_H */
