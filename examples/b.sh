#!/bin/bash

# cd .. && cmake -S . -B build -DCMAKE_POLICY_VERSION_MINIMUM=3.5 && cd build && make -j 12 && sudo make install && cd .. && cd examples && gcc image_example.c  -o bin/IoT_dashboard -L/usr/local/lib/ -lfreetype -lGooeyGUI -lpaho-mqtt3cs -I/usr/local/include/ -I/usr/local/include/Gooey/ -I/usr/local/include/GLPS/ -lGLPS  -lm && ./bin/IoT_dashboard
cd .. && cmake -S . -B build -DCMAKE_POLICY_VERSION_MINIMUM=3.5 && cd build && make -j 4 && sudo make install && cd .. && cd examples &&  gcc switch_example.c  -o switch -L/usr/local/lib/ -lfreetype -lGooeyGUI -I/usr/local/include/ -I/usr/local/include/Gooey/ -I/usr/local/include/GLPS/ -lGLPS  -lm && ./switch
