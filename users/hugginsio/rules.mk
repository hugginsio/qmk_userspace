# Copyright (c) Kyle Huggins
# SPDX-License-Identifier: GPL-2.0+

# Common configuration
AUDIO_ENABLE = no
BACKLIGHT_ENABLE = no
BOOTMAGIC_ENABLE = no
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
ENCODER_ENABLE = no
EXTRAKEY_ENABLE = yes
GRAVE_ESC_ENABLE = no
LTO_ENABLE = yes
MAGIC_ENABLE = no
MOUSEKEY_ENABLE = no
MUSIC_ENABLE = no
NKRO_ENABLE = yes
OLED_DRIVER = SSD1306
OLED_ENABLE = no
RGBLIGHT_ENABLE = no
RGB_MATRIX_DRIVER = WS2812
RGB_MATRIX_ENABLE = no
SPACE_CADET_ENABLE = no
SPLIT_KEYBOARD = yes
VIA_ENABLE = no

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), crkbd/rev1))
	MOUSEKEY_ENABLE = yes
	POINTING_DEVICE_DRIVER = pimoroni_trackball
	POINTING_DEVICE_ENABLE = yes
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), keebio/iris/rev6))
	NKRO_ENABLE = no
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), kbdfans/kbd75/rev1))
	SPLIT_KEYBOARD = no
endif
