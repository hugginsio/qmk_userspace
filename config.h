#pragma once

#define LAYER_STATE_8BIT
#define NO_MUSIC_MODE

#ifdef SPLIT_KEYBOARD
    #define EE_HANDS
    #define MASTER_LEFT
#endif

#ifdef MOUSEKEY_ENABLE
    #define POINTING_DEVICE_ROTATION_90
    #define PIMORONI
    #ifdef TRACKBALL_RIGHT
        #define POINTING_DEVICE_INVERT_X
        #define POINTING_DEVICE_INVERT_Y
    #endif
#endif
