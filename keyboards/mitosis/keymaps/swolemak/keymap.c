#include "mitosis.h"

enum mitosis_layers
{
	_DEFAULT,
	_SHIFT,
	_FNKEY,
	_LAMBDA
};

enum mitosis_keycodes 
{
	FNKEY = SAFE_RANGE,
	SHIFT,
	LAMBDA
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Some specials
#define SM_STAB LSFT(KC_TAB) /* Left Shift + TAB */

// Swedish letters
#define SV_AA UC(0x00E5) /* Å */
#define SV_AE UC(0x00E4) /* Ä */
#define SV_OE UC(0x00F6) /* Ö */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_DEFAULT] = { /* Swedish Colemak layout (Swolemak) for Mitosis */
		{KC_Q,     KC_W,     KC_F,      KC_P,     KC_G,      KC_J,      KC_L,     KC_U,     KC_Y,       SV_AA     },
		{KC_A,     KC_R,     KC_S,      KC_T,     KC_D,      KC_H,      KC_N,     KC_E,     KC_I,       KC_O      },
		{KC_Z,     KC_X,     KC_C,      KC_V,     KC_B,      KC_K,      KC_M,     SV_AE,    SV_OE,      KC_SLASH  },

		{XXXXXXX,  KC_ESC,   KC_TAB,    KC_HYPR,  KC_COMMA,  KC_DOT,    KC_BSPC,  SM_STAB,  KC_RSHIFT,  XXXXXXX   },
		{XXXXXXX,  KC_LALT,  KV_LCTRL,  SHIFT,    KC_SPACE,  KC_ENTER,  LAMBDA,   FNKEY,    KC_RALT,    XXXXXXX   }
	},

	[_SHIFT] = {
		{_______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ },
		{_______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ },
		{_______, _______, _______, _______, _______,       _______, _______, _______, _______, KC_QUES },

		{XXXXXXX, _______, _______, _______, KC_LABK,       KC_COLN, KC_DEL,  _______, _______, XXXXXXX },
		{XXXXXXX, _______, _______, XXXXXXX, _______,       _______, XXXXXXX, _______, _______, XXXXXXX }
	},

	[_FNKEY] = {
		{KC_TILD,  XXXXXXX,  KC_UP,    XXXXXXX,  KC_F10,   KC_UNDS,  KC_F7,    KC_F8,    KC_F9,    KC_RCBR  },
		{KC_DQT,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_F11,   KC_RBRC,  KC_F4,    KC_F5,    KC_F6,    KC_RPRN  },
		{XXXXXXX,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_F12,   KC_PLUS,  KC_F1,    KC_F2,    KC_F3,    KC_PIPE  },

		{XXXXXXX,  _______,  KC_END,   _______,  _______,  _______,  _______,  KC_HOME,  KC_INS,   XXXXXXX  },
		{XXXXXXX,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX  }
	},

	[_LAMBDA] = {
		{KC_GRV,   KC_AMPR,  KC_ASTR,  XXXXXXX,  KC_VOLU,  KC_MINS,  KC_7,     KC_8,     KC_9,     KC_10    },
		{KC_QUOT,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_MUTE,  KC_LBRC,  KC_4,     KC_5,     KC_6,     KC_LPRN  },
		{XXXXXXX,  KC_EXCL,  KC_AT,    KC_HASH,  KC_VOLD,  KC_EQL,   KC_1,     KC_2,     KC_3,     KC_BSLS  },
		{XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_SCLN,  KC_RABK,  XXXXXXX,  KC_0,     XXXXXX,   XXXXXXX  },
		{XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX  }
	}
};
