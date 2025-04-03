#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "printf.h"

enum Layers {
    _BASE = 0,
    _SYM  = 1,
    _NAV  = 2,
    _FN   = 3,
    _RGB  = 4,
};

enum Encoder {
    _ENCODER_LEFT  = 0,
    _ENCODER_RIGHT = 1,
};

// clang-format off

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( \
                      DE_K          , DE_DOT        , DE_O          , DE_COMM       , DE_Y          ,                                 DE_V          , DE_G          , DE_C          , DE_L          , DE_SS         ,                \
     KC_TAB         , LGUI_T(DE_H)  , LALT_T(DE_A)  , LCTL_T(DE_E)  , LT(_SYM, DE_I), DE_U          ,                                 DE_D          , LT(_SYM, DE_T), RCTL_T(DE_R)  , RALT_T(DE_N)  , RGUI_T(DE_S)  , DE_F          ,\
     LCTL(DE_CIRC)  , DE_X          , DE_Q          , DE_ADIA       , DE_UDIA       , DE_ODIA       , KC_MUTE       , KC_MPLY       , DE_B          , DE_P          , DE_W          , DE_M          , DE_J          , DE_Z          ,\
                                                      KC_ESC        , LSFT_T(KC_SPC), KC_BSPC       , MO(_NAV)      , MO(_NAV)      , KC_ENT        , RSFT_T(KC_SPC), KC_TAB       \
  ),
   [_SYM] = LAYOUT( \
                      _______       , DE_UNDS       , DE_LBRC       , DE_RBRC       , DE_CIRC       ,                                 DE_EXLM       , DE_LABK       , DE_RABK       , DE_EQL        , DE_AMPR       ,                \
    _______         , DE_BSLS       , DE_SLSH       , DE_LCBR       , DE_RCBR       , DE_ASTR       ,                                 DE_QUES       , DE_LPRN       , DE_RPRN       , DE_MINS       , DE_COLN       , DE_AT         ,\
    _______         , DE_HASH       , DE_DLR        , DE_PIPE       , DE_TILD       , DE_GRV        , _______       , _______       , DE_PLUS       , DE_PERC       , DE_DQUO       , DE_QUOT       , DE_SCLN       , _______       ,\
                                                      _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       \
  ),
   [_NAV] = LAYOUT( \
                      KC_PGUP       , KC_BSPC       , KC_UP         , KC_DELETE     , KC_PGDN       ,                                 _______       , KC_7          , KC_8          , KC_9          , DE_PLUS       ,                \
    _______         , KC_HOME       , KC_LEFT       , KC_DOWN       , KC_RIGHT      , KC_END        ,                                 _______       , LT(_SYM,KC_4) , RCTL_T(KC_5)  , RALT_T(KC_6)  ,RGUI_T(DE_COMM), DE_DOT        ,\
    _______         , KC_ESC        , KC_TAB        , _______       , KC_ENT        , _______       , _______       , _______       , _______       , KC_1          , KC_2          , KC_3          , DE_SCLN       , _______       ,\
                                                      _______       , _______       , _______       , _______       , _______       , _______       , KC_0          , _______       \
  ),
  [_FN] = LAYOUT( \
                      _______       , KC_BTN1       , KC_MS_U       , KC_BTN2       , KC_PSCR       ,                                 _______       , KC_F7         , KC_F8         , KC_F9         , _______       ,                \
    _______         , _______       , LGUI(KC_PGUP) , KC_MS_D       , LGUI(KC_PGDN) , _______       ,                                 _______       , KC_F4         , KC_F5         , KC_F6         , _______       , _______       ,\
    QK_BOOT         , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , KC_F1         , KC_F2         , KC_F3         , _______       , _______       ,\
                                                      KC_MPLY       , _______       , _______       , _______       , _______       , _______       , _______       , KC_AUDIO_MUTE \
  ),
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
    [_SYM]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NAV]  = { ENCODER_CCW_CW(KC_WH_R, KC_WH_L), ENCODER_CCW_CW(KC_WH_R, KC_WH_L) },
    [_FN]   = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) }
};

// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _FN);
}

void keyboard_post_init_user(void) {
    // debug_config.enable = true;
    // debug_config.matrix = true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_SPC):
        case RSFT_T(KC_SPC):
            return true;
        default:
            return false;
    }
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    // Allow hold between any pair of mod-tap keys.
    // if (IS_QK_MOD_TAP(tap_hold_keycode) && IS_QK_MOD_TAP(other_keycode)) {
    //     return true;
    // }

    if ((IS_QK_LAYER_TAP(tap_hold_keycode) && IS_QK_MOMENTARY(other_keycode)) || (IS_QK_LAYER_TAP(other_keycode) && IS_QK_MOMENTARY(tap_hold_keycode))) {
        return true;
    }

    // Exceptionally allow some one-handed chords for hotkeys.
    switch (tap_hold_keycode) {
        case LSFT_T(KC_SPC):
        case RSFT_T(KC_SPC):
            return true;
    }

    // Otherwise defer to the opposite hands rule.
    return get_chordal_hold_default(tap_hold_record, other_record);
}
