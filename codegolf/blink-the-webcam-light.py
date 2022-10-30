#!/usr/bin/env python

"""

This challenge is inspired by Blink the CAPS LOCK by zeppelin.

Most webcams feature a small integrated LED light, indicating if the webcam is in use, as controlled by a hardware mechanism to prevent spying.
Your task is to blink it:

Turn it on.
Wait for 0.5 (±0.1) seconds.
Turn it off again.
Wait for 0.5 (±0.1) seconds;
Repeat.
Please include a GIF or video of the webcam blinking, if possible. If an answer doesn't have the GIF, please add a GIF of the program running.

Rules
If your language is missing a subsecond sleep command, your program may use a 1 second delay instead, at a penalty of an additional byte. (replacing .5 with 1)
If your language, for some reason, doesn't support .5, your penalty is 2 bytes. (replacing 0.5 with 1)
Your program must loop unless halted by the user.
Your LED can start either on or off; whichever is more beneficial can be used.
If your LED has a turning-off delay, then it doesn't have to be taken into account, unless if you want to provide an additional version.
See this comment and its answer for more information.
Scoring
This is code-golf, which means the shortest answer in bytes wins.

"""

import cv2
import time

def blinks(duration):
    while True:
        cap = cv2.VideoCapture(0)
        time.sleep(duration)
        cap.release()
        time.sleep(duration)

def main():
    blinks(0.5)

main()
