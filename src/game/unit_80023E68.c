#include "types.h"

typedef struct Unk80023E68 {
    /* 0x00 */ u8 pad00[0x0A];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 pad0B[0x12 - 0x0B];
    /* 0x12 */ u8 state;
    /* 0x13 */ u8 pad13[0x60 - 0x13];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
} Unk80023E68;

extern u32 lbl_80304B90[];

void fn_800E9244(Unk80023E68* obj);
void fn_80040D50(s32* pos);

void fn_80023E68(Unk80023E68* obj) {
    if (obj->state == 0) {
        s32 pos[2];
        fn_800E9244(obj);
        obj->flagsA &= ~1;
        pos[0] = obj->unk60;
        pos[1] = obj->unk64 - 0x800;
        fn_80040D50(pos);
        if ((lbl_80304B90[0xB6] & 1) == 0) {
            lbl_80304B90[0xB6] |= 2;
        }
        obj->state++;
    }
}
