#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk80075EFC {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x60 - 0x1C];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0xAB - 0x68];
    /* 0xAB */ u8 hitHi : 4;
    /* 0xAB */ u8 hitType : 4;
} Unk80075EFC;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;
extern void** lbl_80270168[];
extern void (*lbl_8026FD2C[])(Unk80075EFC* obj);

void fn_800E9244(Unk80075EFC* obj);
void fn_80040AD0(s32 arg0, Vec2i* pos, s32 arg2, s32 arg3);
void fn_8009C308(s32 item, Vec2i* pos, s32 arg2);
BOOL fn_80076714(Unk80075EFC* obj);
void fn_800D5234(s32 id);

static inline void SetMode(Unk80075EFC* obj, u8 mode) {
    obj->unk18 = lbl_80270168[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

void fn_80075EFC(Unk80075EFC* obj) {
    Vec2i drop;
    Vec2i pos;

    if (lbl_803051D8.unk2 & 0x20) {
        obj->flagsA &= ~1;
        obj->flagsA &= 0xFD;
        fn_800E9244(obj);
        SetMode(obj, 3);
        return;
    }
    if ((lbl_803051D8.unk2 & 0x10) && (obj->flagsA & 1)) {
        fn_800E9244(obj);
        obj->flagsA &= 0xFD;
        obj->flagsA &= ~1;
        drop.x = obj->x;
        drop.y = obj->y;
        fn_80040AD0(2, &drop, 0, 0);
        fn_8009C308(4, &drop, 0);
        SetMode(obj, 4);
        return;
    }
    if (fn_80076714(obj)) {
        pos.x = obj->x;
        pos.y = obj->y;
        fn_800E9244(obj);
        obj->flagsA &= ~1;
        if (obj->hitType != 5 && obj->hitType != 8) {
            fn_80040AD0(2, &pos, 0, 0);
            fn_800D5234(0x14);
        }
        SetMode(obj, 4);
    } else {
        lbl_8026FD2C[obj->state](obj);
    }
}
