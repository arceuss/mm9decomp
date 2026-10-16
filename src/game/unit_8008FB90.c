#include "types.h"

typedef struct Unk8008FB90 {
    /* 0x000 */ u8 pad0[0x3];
    /* 0x003 */ u8 unk3;
    /* 0x004 */ u8 pad4[0xFF4 - 0x4];
    /* 0xFF4 */ u8 unkFF4;
    /* 0xFF5 */ u8 cursor;
} Unk8008FB90;

typedef struct Unk80319DA0 {
    /* 0x000 */ u8 pad0[0x860];
    /* 0x860 */ u32 unk860;
    /* 0x864 */ u16 unk864;
} Unk80319DA0;

extern Unk80319DA0 lbl_80319DA0;

void fn_800D5234(s32 id);
void fn_800BB7B8(s32 arg0);

void fn_8008FB90(Unk8008FB90* obj) {
    if ((lbl_80319DA0.unk860 & 0x10) || (lbl_80319DA0.unk860 & 0x40)) {
        fn_800D5234(1);
        fn_800BB7B8(0);
        obj->unk3++;
        return;
    }
    if (lbl_80319DA0.unk864 & 1) {
        fn_800D5234(0);
        if (obj->unkFF4 == 0) {
            if (obj->cursor == 0) {
                obj->cursor = 3;
            } else {
                obj->cursor--;
            }
        } else if (obj->cursor == 0) {
            obj->cursor = 2;
        } else {
            obj->cursor--;
        }
    } else if ((lbl_80319DA0.unk864 & 2) || (lbl_80319DA0.unk864 & 0x80)) {
        fn_800D5234(0);
        if (obj->unkFF4 == 0) {
            obj->cursor = (u8)(obj->cursor + 1) % 4;
        } else {
            obj->cursor = (u8)(obj->cursor + 1) % 3;
        }
    }
}
