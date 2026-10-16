#include "types.h"

typedef struct Unk8008F9C0 {
    /* 0x0 */ u8 step;
    /* 0x1 */ u8 mode;
    /* 0x2 */ s8 level;
    /* 0x3 */ u8 speed;
} Unk8008F9C0;

typedef struct Unk8038B2F8Sub {
    /* 0x0000 */ u8 pad0[0x2500];
    /* 0x2500 */ s8 unk2500;
} Unk8038B2F8Sub;

typedef struct Unk8038B2F8 {
    /* 0x0000 */ u8 pad0[0x184];
    /* 0x0184 */ Unk8038B2F8Sub* unk184;
    /* 0x0188 */ u8 pad188[0x26C0 - 0x188];
} Unk8038B2F8;

extern Unk8038B2F8 lbl_8038B2F8;

void fn_8008F9C0(Unk8008F9C0* fade) {
    switch (fade->step) {
    case 0:
        if (fade->mode == 0) {
            return;
        }
        fade->step++;
    case 1:
        if (fade->mode & 2) {
            if (fade->mode & 1) {
                fade->level = 0x40;
            } else {
                fade->level = 0;
            }
        } else {
            fade->level = 0x20;
        }
        fade->step++;
    case 2:
        if (fade->mode & 2) {
            if (fade->mode & 1) {
                fade->level -= fade->speed;
                if (fade->level <= 0x20) {
                    fade->level = 0x20;
                    fade->mode = 0;
                    fade->step = 0;
                }
                lbl_8038B2F8.unk184->unk2500 = fade->level;
            } else {
                fade->level += fade->speed;
                if (fade->level >= 0x20) {
                    fade->level = 0x20;
                    fade->mode = 0;
                    fade->step = 0;
                }
                lbl_8038B2F8.unk184->unk2500 = fade->level;
            }
        } else if (fade->mode & 4) {
            if (fade->mode & 1) {
                fade->level += fade->speed;
                if (fade->level >= 0x40) {
                    fade->level = 0x40;
                    fade->mode = 0;
                    fade->step = 0;
                }
                lbl_8038B2F8.unk184->unk2500 = fade->level;
            } else {
                fade->level -= fade->speed;
                if (fade->level <= 0) {
                    fade->level = 0;
                    fade->mode = 0;
                    fade->step = 0;
                }
                lbl_8038B2F8.unk184->unk2500 = fade->level;
            }
        } else {
            fade->mode = 0;
            fade->step = 0;
        }
        break;
    }
}
