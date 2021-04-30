 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
  * 
  * This program is free software: you can redistribute it and/or modify 
  * it under the terms of the GNU General Public License as published by 
  * the Free Software Foundation, either version 2 of the License, or 
  * (at your option) any later version. 
  * 
  * This program is distributed in the hope that it will be useful, 
  * but WITHOUT ANY WARRANTY; without even the implied warranty of 
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
  * GNU General Public License for more details. 
  * 
  * You should have received a copy of the GNU General Public License 
  * along with this program.  If not, see <http://www.gnu.org/licenses/>. 
  */

//Setting up what encoder rotation does. If your encoder can be pressed as a button, that function can be set in Via.
uint16_t encoder_mode = 0;
uint16_t encoder_mode_mod = 0;
    
#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
      switch (encoder_mode_mod) {
            case 0:
                if (clockwise) { // Ctrl + I
                    tap_code16(KC_VOLU);
                } else { // Shift + F3
                    tap_code16(KC_VOLD);
                }
                break;
            case 1:
                // History scrubbing. For Adobe products, hold shift while moving
                // backward to go forward instead.
                if (clockwise) {
                    tap_code16(KC_PGDN);
                } else {
                    tap_code16(KC_PGUP);
                }
                break;
            default:
                // Nothing
                break;
        }
    } else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case 0:
                // Scroll by letter horizontally
                if (clockwise) {
                    tap_code16(KC_RGHT);
                } else {
                    tap_code16(KC_LEFT);
                }
            case 1:
                // Nothing
                break;
            default:
                // Nothing
                break;
        }
    }
}
#endif
