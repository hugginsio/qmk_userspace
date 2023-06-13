#include QMK_KEYBOARD_H

// Left-hand home row mods
#define HOME_A LSFT_T(KC_A)
#define HOME_S LCTL_T(KC_S)
#define HOME_D LALT_T(KC_D)
#define HOME_F LGUI_T(KC_F)

// Right-hand home row mods
#define HOME_J RGUI_T(KC_J)
#define HOME_K LALT_T(KC_K)
#define HOME_L RCTL_T(KC_L)
#define HOME_SCLN RSFT_T(KC_SCLN)

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return TAPPING_TERM;
    }
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }

    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == DRAG_SCROLL && record->event.pressed) {
        set_scrolling = !set_scrolling;
    }

    return true;
}

void pointing_device_init_user(void) {
    set_auto_mouse_layer(4);
    set_auto_mouse_enable(true);
}

enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
};

bool set_scrolling = false;

enum custom_layers {
    QWERTY,
    NBR_ARROWS,
    SYM,
    FUNC
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT(
        KC_TAB,        KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,       KC_Y, KC_U,   KC_I,    KC_O,   KC_P,      KC_BSPC,
        LT(2, KC_ESC), HOME_A, HOME_S, HOME_D, HOME_F, KC_G,       KC_H, HOME_J, HOME_K,  HOME_L, HOME_SCLN, KC_QUOT,
        KC_LSFT,       KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,       KC_N, KC_M,   KC_COMM, KC_DOT, KC_SLSH,   MO(3),
                                     KC_LCTL, KC_LALT, KC_LGUI,    MO(1), KC_SPC, KC_ENT
    ), 
    [NBR_ARROWS] = LAYOUT(
        KC_TRNS, KC_1,    KC_2,  KC_3,  KC_4,  KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
        KC_TRNS, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,      KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [SYM] = LAYOUT(
        KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
        KC_TRNS, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,       KC_EQL,  KC_LBRC, KC_MINS, KC_RBRC, KC_BSLS, KC_GRV,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [FUNC] = LAYOUT(
        KC_TRNS, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_DEL,
        QK_BOOT, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15,    KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO,  KC_NO,
        KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [MOUSE] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_BTN2, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                             KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO
    )
}
