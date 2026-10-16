#include "types.h"

typedef struct Unk8027EB60Entry {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ s32 unk14;
} Unk8027EB60Entry;

typedef struct Unk800AF0E4 {
    /* 0x000 */ u8 pad0[0x9];
    /* 0x009 */ u8 unk9;
    /* 0x00A */ u8 flagsA;
    /* 0x00B */ u8 padB[0x12 - 0xB];
    /* 0x012 */ u8 step;
    /* 0x013 */ u8 pad13[0x54 - 0x13];
    /* 0x054 */ u32 flags54_hi : 21;
    /* 0x054 */ u32 flags54_b10 : 1;
    /* 0x054 */ u32 flags54_lo : 10;
    /* 0x058 */ u8 pad58[0x60 - 0x58];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ u8 pad64[0xD0 - 0x64];
    /* 0x0D0 */ s32 unkD0;
    /* 0x0D4 */ u8 padD4[0xFC - 0xD4];
    /* 0x0FC */ u8 unkFC;
    /* 0x0FD */ u8 padFD[0x116 - 0xFD];
    /* 0x116 */ u8 unk116;
} Unk800AF0E4;

typedef struct Unk80316398 {
    /* 0x000 */ u8 unk0;
    /* 0x001 */ u8 pad1[0x938 - 0x1];
} Unk80316398;

extern Unk80316398 lbl_80316398;
extern Unk8027EB60Entry* lbl_8027EB60[];

void fn_800B9F74(Unk800AF0E4* obj, s32 arg1);

void fn_800AF0E4(Unk800AF0E4* obj) {
    switch (obj->step) {
    case 0:
        if (obj->unkFC == 13 || obj->unkFC == 23) {
            obj->unkFC = 5;
            fn_800B9F74(obj, lbl_8027EB60[obj->unk9]->unk14);
        }
        lbl_80316398.unk0 |= 1;
        obj->step = 1;
        obj->unk116 |= 4;
    case 1:
        if (obj->unk60 != obj->unkD0) {
            obj->flags54_b10 = obj->unk60 < obj->unkD0;
            if (obj->flags54_b10) {
                obj->flagsA |= 0x10;
            } else {
                obj->flagsA &= 0xEF;
            }
        }
        break;
    }
}
