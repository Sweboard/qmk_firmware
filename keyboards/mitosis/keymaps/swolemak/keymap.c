// vim:expandtab ts=2 sw=2

#include "mitosis.h"

enum mitosis_layers
{
  _DEFAULT,
  _SHIFT,
  _FN,
  _LAMBDA
};

#define FN MO(_FN)
#define SHIFT MO(_SHIFT)
#define LAMBDA MO(_LAMBDA)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Some specials
#define LSTAB LSFT(KC_TAB) /* Left Shift + TAB */

// Swedish letters
#define SV_AA UC(0x00E5) /* Å */
#define SV_AE UC(0x00E4) /* Ä */
#define SV_OE UC(0x00F6) /* Ö */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  /* Default layout (Swedish Colemak/Swolemak)
   * .--------------------------------------------..--------------------------------------------.
   * | q      | w      | f      | p      | g      || j      | l      | u      | y      | å      |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * | a      | r      | s      | t      | d      || h      | n      | e      | i      | o      |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * | z      | x      | c      | v      | b      || k      | m      | ä      | ö      | /      |
   * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
   *          | ESC    | TAB    | HYPR   | COMMA  || DOT    | BSPC   | LSTAB  | RSHIFT |
   *          |--------+--------+--------+--------||--------+--------+--------+--------|
   *          | LALT   | LCTRL  | SHIFT  | SPACE  || ENTER  | LAMBDA | FN     | RALT   |
   *          '-----------------------------------''-----------------------------------'
   */
  [_DEFAULT] = {
    {KC_Q,     KC_W,     KC_F,      KC_P,     KC_G,       KC_J,      KC_L,     KC_U,     KC_Y,       SV_AA     },
    {KC_A,     KC_R,     KC_S,      KC_T,     KC_D,       KC_H,      KC_N,     KC_E,     KC_I,       KC_O      },
    {KC_Z,     KC_X,     KC_C,      KC_V,     KC_B,       KC_K,      KC_M,     SV_AE,    SV_OE,      KC_SLASH  },

    {XXXXXXX,  KC_ESC,   KC_TAB,    KC_HYPR,  KC_COMMA,   KC_DOT,    KC_BSPC,  LSTAB,    KC_RSHIFT,  XXXXXXX   },
    {XXXXXXX,  KC_LALT,  KC_LCTRL,  SHIFT,    KC_SPACE,   KC_ENTER,  LAMBDA,   FN,       KC_RALT,    XXXXXXX   }
  },

  /* Shift layout
   * .--------------------------------------------..--------------------------------------------.
   * | Q      | W      | F      | P      | G      || J      | L      | U      | Y      | Å      |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * | A      | R      | S      | T      | D      || H      | N      | E      | I      | O      |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * | Z      | X      | C      | V      | B      || K      | M      | Ä      | Ö      | ?      |
   * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
   *          | ______ | ______ | ______ | <      || :      | DEL    | ______ | ______ |
   *          |--------+--------+--------+--------||--------+--------+--------+--------|
   *          | ______ | ______ |        | ______ || ______ |        | ______ | ______ |
   *          '-----------------------------------''-----------------------------------'
   */
  [_SHIFT] = {
    {_______, _______, _______, _______, _______,         _______, _______, _______, _______, _______ },
    {_______, _______, _______, _______, _______,         _______, _______, _______, _______, _______ },
    {_______, _______, _______, _______, _______,         _______, _______, _______, _______, KC_QUES },

    {XXXXXXX, _______, _______, _______, KC_LABK,         KC_COLN, KC_DEL,  _______, _______, XXXXXXX },
    {XXXXXXX, _______, _______, XXXXXXX, _______,         _______, XXXXXXX, _______, _______, XXXXXXX }
  },

  /* Fn layout
   * .--------------------------------------------..--------------------------------------------.
   * | ~      |        | UP     |        | F10    || _      | F7     | F8     | F9     | }      |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * | "      | LEFT   | DOWN   | RGHT   | F11    || ]      | F4     | F5     | F6     | )      |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * |        | MPRV   | MPLY   | MNXT   | F12    || +      | F1     | F2     | F3     | |      |
   * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
   *          | ______ | END    | ______ |        ||        |        | HOME   | INS    |
   *          |--------+--------+--------+--------||--------+--------+--------+--------|
   *          | ______ | ______ |        | ______ || ______ |        | ______ | ______ |
   *          '-----------------------------------''-----------------------------------'
   */
  [_FN] = {
    {KC_TILD,  XXXXXXX,  KC_UP,    XXXXXXX,  KC_F10,      KC_UNDS,  KC_F7,    KC_F8,    KC_F9,    KC_RCBR  },
    {KC_DQT,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_F11,      KC_RBRC,  KC_F4,    KC_F5,    KC_F6,    KC_RPRN  },
    {XXXXXXX,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_F12,      KC_PLUS,  KC_F1,    KC_F2,    KC_F3,    KC_PIPE  },

    {XXXXXXX,  _______,  KC_END,   _______,  _______,     _______,  _______,  KC_HOME,  KC_INS,   XXXXXXX  },
    {XXXXXXX,  _______,  _______,  _______,  _______,     _______,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX  }
  },

  /* Lambda layout
   * .--------------------------------------------..--------------------------------------------.
   * | `      |        | *      |        | VOLU   || -      | 7      | 8      | 9      | {      |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * | '      | $      | %      | ^      | MUTE   || [      | 4      | 5      | 6      | (      |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * |        | !      | @      | #      | VOLD   || =      | 1      | 2      | 3      | \      |
   * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
   *          |        |        |        | ;      || >      | 0      |        |        |
   *          |--------+--------+--------+--------||--------+--------+--------+--------|
   *          |        |        |        |        ||        |        |        |        |
   *          '-----------------------------------''-----------------------------------'
   */
  [_LAMBDA] = {
    {KC_GRV,   KC_AMPR,  KC_ASTR,  XXXXXXX,  KC_VOLU,     KC_MINS,  KC_7,     KC_8,     KC_9,     KC_LCBR  },
    {KC_QUOT,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_MUTE,     KC_LBRC,  KC_4,     KC_5,     KC_6,     KC_LPRN  },
    {XXXXXXX,  KC_EXLM,  KC_AT,    KC_HASH,  KC_VOLD,     KC_EQL,   KC_1,     KC_2,     KC_3,     KC_BSLS  },
    {XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_SCLN,     KC_RABK,  XXXXXXX,  KC_0,     XXXXXXX,  XXXXXXX  },
    {XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX  }
  }
};


void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

  switch (layer) {
    case _DEFAULT:
      set_led_off;
      break;

    case _SHIFT:
      set_led_red;
      break;

    case _FN:
      set_led_blue;
  }
}
