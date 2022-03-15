#pragma once

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 150

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

#define UNICODE_SELECTED_MODES UC_LNX, UC_MAC, UC_WINC, UC_WIN

// qmk-vim config
#define VIM_FOR_MAC
#define VIM_FOR_ALL
#define BETTER_VISUAL_MODE
#define VIM_I_TEXT_OBJECTS
#define VIM_A_TEXT_OBJECTS
#define VIM_G_MOTIONS
#define VIM_COLON_CMDS
#define VIM_PASTE_BEFORE
#define VIM_REPLACE
#define VIM_DOT_REPEAT
#define VIM_W_BEGINNING_OF_WORD

