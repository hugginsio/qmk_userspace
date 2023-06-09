#pragma once

#define LAYER_STATE_8BIT
#define NO_MUSIC_MODE

#ifdef SPLIT_KEYBOARD
#define MASTER_RIGHT
#endif

#ifdef MOUSEKEY_ENABLE
#define PIMORONI
#define POINTING_DEVICE_ROTATION_90
#ifdef TRACKBALL_RIGHT
#define POINTING_DEVICE_INVERT_X
#define POINTING_DEVICE_INVERT_Y
#endif

#define MOUSEKEY_INTERVAL 15 // Time between cursor movements in milliseconds
#define MOUSEKEY_MAX_SPEED 9
#define MOUSEKEY_MOVE_DELTA 10 // Step size for acceleration
#define MOUSEKEY_TIME_TO_MAX 80
#define MOUSEKEY_WHEEL_DELAY 16
#define MOUSEKEY_WHEEL_INTERVAL 30
#define MOUSEKEY_WHEEL_MAX_SPEED 10
#define MOUSEKEY_WHEEL_TIME_TO_MAX 95
#endif
