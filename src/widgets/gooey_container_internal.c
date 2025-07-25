//
// Created by overflow on 6/10/2025.
//

#include "widgets/gooey_container_internal.h"
#include "logger/pico_logger_internal.h"
#include "backends/gooey_backend_internal.h"
#if (ENABLE_CONTAINER)

void GooeyContainer_Draw(GooeyWindow *window)
{
    if (!window)
    {
        LOG_ERROR("Couldn't draw container.");
        return;
    }

    for (size_t i = 0; i < window->container_count; ++i)
    {
        GooeyContainers *container = (GooeyContainers *)window->containers[i];
        if (!container)
        {
            continue;
        }

        for (size_t j = 0; j < container->container_count; j++)
        {
            GooeyContainer *cont = &container->container[j];
            for (size_t k = 0; k < cont->widget_count; ++k)
            {
                void *widget = cont->widgets[k];
                GooeyWidget *core = (GooeyWidget *)widget;

                // Widgets
                if (container->active_container_id == cont->id)
                {
                    core->is_visible = container->core.is_visible;
                }
                else
                {
                    
                    core->is_visible = false;
                    if(core->sprite) active_backend->ClearOldWidget(core->sprite);
                }
            }
        }
    }
}
#endif