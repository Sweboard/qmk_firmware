// vim:expandtab ts=2 sw=2

#include "mitosis.h"
#include "keymap_swedish.h"

enum mitosis_layers {
  _DEFAULT,
  _SHIFT,
  _FN,
  _LAMBDA
};

enum mitosis_keycodes {
  CM_LSFT = SAFE_RANGE,
  CM_RSFT
};

enum unicode_names {
  BANG,
  XI
};

const uint32_t PROGMEM unicode_map[] = {
  [BANG] = 0x203D, // ‽ (?!)
  [XI] = 0x03BE    // ξ
};

#define FN MO(_FN)
#define LAMBDA MO(_LAMBDA)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Default layout (Swedish Colemak/Swolemak)
   * .--------------------------------------------..--------------------------------------------.
   * | q      | w      | f      | p      | g      || j      | l      | u      | y      | ö      |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * | a      | r      | s      | t      | d      || h      | n      | e      | i      | o      |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * | z      | x      | c      | v      | b      || k      | m      | ä      | å      | /      |
   * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
   *          | ESC    | LCTRL  | TAB    | COMMA  || DOT    | BSPC   | RCTRL  | SUPER  |
   *          |--------+--------+--------+--------||--------+--------+--------+--------|
   *          | LALT   | FN     | LSHIFT | SPACE  || ENTER  | RSHIFT | LAMBDA | ALGR   |
   *          '-----------------------------------''-----------------------------------'
   */
  [_DEFAULT] = {
    {KC_Q,     KC_W,     KC_F,      KC_P,     KC_G,      KC_J,      KC_L,     KC_U,      KC_Y,     NO_OSLH  },
    {KC_A,     KC_R,     KC_S,      KC_T,     KC_D,      KC_H,      KC_N,     KC_E,      KC_I,     KC_O     },
    {KC_Z,     KC_X,     KC_C,      KC_V,     KC_B,      KC_K,      KC_M,     NO_AE,     NO_AA,    NO_SLSH  },
    {XXXXXXX,  KC_ESC,   KC_LCTRL,  KC_TAB,   KC_COMMA,  KC_DOT,    KC_BSPC,  KC_RCTRL,  KC_LGUI,  XXXXXXX  },
    {XXXXXXX,  KC_LALT,  FN,        CM_LSFT,  KC_SPACE,  KC_ENTER,  CM_RSFT,  LAMBDA,    NO_ALGR,  XXXXXXX  }
  },

  /* Shift layout
   * .--------------------------------------------..--------------------------------------------.
   * | Q      | W      | F      | P      | G      || J      | L      | U      | Y      | Å      |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * | A      | R      | S      | T      | D      || H      | N      | E      | I      | O      |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * | Z      | X      | C      | V      | B      || K      | M      | Ä      | Ö      | \      |
   * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
   *          |        |        |        | ;      || :      |        |        |        |
   *          |--------+--------+--------+--------||--------+--------+--------+--------|
   *          |        |        |        |        ||        |        |        |        |
   *          '-----------------------------------''-----------------------------------'
   */
  [_SHIFT] = {
    {_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______  },
    {_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______  },
    {_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  NO_BSLS  },
    {XXXXXXX,  _______,  _______,  _______,  NO_SCLN,  NO_COLN,  _______,  _______,  _______,  XXXXXXX  },
    {XXXXXXX,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  XXXXXXX  }
  },

  /* Fn layout
   * .--------------------------------------------..--------------------------------------------.
   * | ~      | ‽ (?!) | UP     | £      | F10    || _      | F7     | F8     | F9     | {      |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * | "      | LEFT   | DOWN   | RGHT   | F11    || ]      | F4     | F5     | F6     | }      |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * | €      | MPRV   | MPLY   | MNXT   | F12    || [      | F1     | F2     | F3     | |      |
   * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
   *          |        |        |        |        ||        | DEL    | HOME   | INS    |
   *          |--------+--------+--------+--------||--------+--------+--------+--------|
   *          |        |        |        |        ||        |        |        | END    |
   *          '-----------------------------------''-----------------------------------'
   */
  [_FN] = {
    {NO_TILD,  X(BANG),  KC_UP,    NO_PND,   KC_F10,   NO_UNDS,  KC_F7,    KC_F8,    KC_F9,   NO_LCBR  },
    {NO_QUO2,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_F11,   NO_LBRC,  KC_F4,    KC_F5,    KC_F6,   NO_RCBR  },
    {NO_EURO,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_F12,   NO_PLUS,  KC_F1,    KC_F2,    KC_F3,   NO_PIPE  },
    {XXXXXXX,  _______,  _______,  _______,  _______,  _______,  KC_DEL,   KC_HOME,  KC_INS,  XXXXXXX  },
    {XXXXXXX,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_END,  XXXXXXX  }
  },

  /* Lambda layout
   * .--------------------------------------------..--------------------------------------------.
   * | `      | &      | ?      | $      | VOLU   || -      | 7      | 8      | 9      | (      |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * | '      | !      | @      | #      | VOLD   || +      | 4      | 5      | 6      | )      |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * | ´      | ξ      | %      | ^      | MUTE   || =      | 1      | 2      | 3      | *      |
   * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
   *          |        |        | STAB   | <      || >      |        | 0      |        |
   *          |--------+--------+--------+--------||--------+--------+--------+--------|
   *          |        |        |        |        ||        |        |        |        |
   *          '-----------------------------------''-----------------------------------'
   */
  [_LAMBDA] = {
    {NO_GRV,   NO_AMPR,  NO_QUES,  NO_DLR,     KC_VOLU,  NO_MINS,  KC_7,     KC_8,     KC_9,     NO_LPRN  },
    {NO_APOS,  KC_EXLM,  NO_AT,    KC_HASH,    KC_VOLD,  NO_PLUS,  KC_4,     KC_5,     KC_6,     NO_RPRN  },
    {NO_ACUT,  X(XI),    KC_PERC,  NO_CIRC,    KC_MUTE,  NO_EQL,   KC_1,     KC_2,     KC_3,     NO_ASTR  },
    {XXXXXXX,  _______,  _______,  S(KC_TAB),  NO_LESS,  NO_GRTR,  _______,  KC_0,     _______,  XXXXXXX  },
    {XXXXXXX,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  XXXXXXX  }
  }
};

void custom_shift(keyrecord_t *record, uint16_t mod, uint16_t keycode) {
      if (record->event.pressed) {
        register_code(keycode);
        layer_on(_SHIFT);
      } else {
        layer_off(_SHIFT);
        unregister_code(keycode);
      }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case NO_LESS:
      clear_mods(); // ignore shift key (will interfere for sv-latin1 layout with < key)
      register_code(keycode);
      return true;
    case CM_LSFT:
      custom_shift(record, keycode, KC_LSFT);
      return true;
    case CM_RSFT:
      custom_shift(record, keycode, KC_RSFT);
      return true;
  }

  return true;
}

void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

  switch (layer) {
    case _DEFAULT:
      set_led_off;
      break;

    case _SHIFT:
      set_led_red;
      break;

    case _LAMBDA:
      set_led_yellow;
      break;

    case _FN:
      set_led_blue;
  }
}
