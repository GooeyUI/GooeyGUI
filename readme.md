
# Gooey - Cross-Platform GUI Library

The elegant way to build cross-platform applications with native performance.

<img src="website/example_screenshot_login.png" style="max-width:600px;"/>

<img src="website/example_screenshot.png" style="max-width:600px;"/>


## Warning

For production code disable address sanitizer, it will cause high memory usage.

## Features

- **Cross-Platform**: Write once, build anywhere (Windows, Linux)
- **Lightweight**: Minimal footprint with maximum functionality
- **Customizable**: Tailor every aspect of your UI
- **Minimal Dependencies**: Built with minimal dependencies
- **Pure C**: Portable code perfect for embedded solutions
- **Community Driven**: Open-source under GPL v2 license

## Quick Start

### Installation

Download the latest release from our [GitHub Releases](https://github.com/GooeyUI/GooeyGUI/releases) page.

### Basic Example

```c
#include <Gooey/gooey.h>

int main()
{
    Gooey_Init();
    GooeyWindow *win = GooeyWindow_Create("My Window", 400, 400, true);

    GooeyLabel *label_0 = GooeyLabel_Create("Hello World!", 0.26f, 164, 159);

    GooeyWindow_RegisterWidget(win, label_0);

    GooeyWindow_Run(1, win);
    GooeyWindow_Cleanup(1, win);

    return 0;
}
```

## Documentation

Explore our comprehensive documentation:

- [API Reference](https://gooeyui.github.io/GooeyGUI/website/docs/files.html)
- [Examples Directory](https://github.com/GooeyUI/GooeyGUI/tree/main/examples)
- [Web Builder Tool](https://gooeyui.github.io/GooeyBuilder/)

## Customize your build

You can customize your build by modifying the user_config.h header file in the include/ folder.

```c++
#ifndef USER_CONFIG_H
#define USER_CONFIG_H

// DEBUG/PROD
#define PROJECT_BRANCH 1 // 0=debug 1=prod TODO

// MAX
#define MAX_TIMERS 100 /** Maximum number of timer objects. */
#define MAX_WIDGETS 100 /** Maximum number of widgets that can be added to a window. */
#define MAX_MENU_CHILDREN 10 /** Maximum number of menu children. */
#define MAX_RADIO_BUTTONS 10 /** Maximum number of radio buttons in a group. */
#define MAX_PLOT_COUNT 100 /** Maximum number of plots. */
#define MAX_TABS 50 /** Maximum number of tabs. */

// ENABLE/DISABLE WIDGETS
#define ENABLE_BUTTON 1
#define ENABLE_CANVAS 1
#define ENABLE_CHECKBOX 1
#define ENABLE_CTX_MENU 1 // TODO
#define ENABLE_DEBUG_OVERLAY 1
#define ENABLE_DROP_SURFACE 1
#define ENABLE_DROPDOWN 1
#define ENABLE_IMAGE 1
#define ENABLE_LABEL 1
#define ENABLE_LAYOUT 1
#define ENABLE_LIST 1
#define ENABLE_MENU 1
#define ENABLE_METER 1
#define ENABLE_PLOT 1
#define ENABLE_PROGRESSBAR 1
#define ENABLE_RADIOBUTTON 1
#define ENABLE_SLIDER 1
#define ENABLE_TABS 1
#define ENABLE_TEXTBOX 1

#endif
```

## Building from Source

1. Clone the repository:
   ```bash
   git clone https://github.com/GooeyUI/GooeyGUI.git GooeyGUI
   cd GooeyGUI
   ```

2. Get Submodules:
	```bash
	git submodule init
	git submodule update --remote --merge
   ```

4. Build the library:
   ```bash
   cmake -S . -B build
   cd build && make
   # Install if you encounter missing packages
   sudo apt install libdrm-dev libgbm-dev libegl-dev libgl-dev libwayland-dev libxkbcommon-dev mesa-utils
   ```

5. Install (optional):
   ```bash
   sudo make install
   ```
6. Building a example
   ```bash
   gcc example.c  -o example -L/usr/local/lib/ -lfreetype -lGooeyGUI -lGLPS  -lm -I/usr/local/include/   -fsanitize=address,undefined && ./example
   ```
## Contributing

We welcome contributions!

## License

Gooey is released under the **GNU General Public License v2.0**.

## Community

Join our growing community:

- [GitHub Discussions](https://github.com/GooeyUI/GooeyGUI/discussions)
- [Report Issues](https://github.com/GooeyUI/GooeyGUI/issues)

## Special Thanks

To all our [contributors](https://github.com/GooeyUI/GooeyGUI/graphs/contributors) who help make Gooey better!

---

© 2025 Gooey GUI Library | [Website](https://gooeyui.github.io/GooeyGUI/website/)
