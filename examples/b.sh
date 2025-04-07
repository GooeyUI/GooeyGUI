#!/bin/bash

cd .. && cd build && make && sudo make install && cd .. && cd examples && gcc showcase.c  -o showcase -L/usr/local/lib -lfreetype -lGooeyGUI -I/usr/local/include/Gooey/ -I/usr/local/include/GLPS/ -lGLPS  -lm -fsanitize=address,undefined && ./showcase
