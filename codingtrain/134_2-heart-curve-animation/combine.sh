#!/bin/sh

ffmpeg -f image2 -framerate 30 -i frame-%03d.png combine.gif
