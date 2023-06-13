#pragma once
#include QMK_KEYBOARD_H

// Tap-hold decision helper macros (@filterpaper/qmk_userspace)
#define IS_TYPING() (timer_elapsed_fast(tap_timer) < TAPPING_TERM * 2)
#define IS_HOMEROW(r) (r->event.key.row == 1 || r->event.key.row == 5)
#define IS_MOD_TAP_SHIFT(kc) (QK_MOD_TAP_GET_MODS(kc) & MOD_LSFT)
