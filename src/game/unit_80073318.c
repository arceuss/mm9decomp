#include "types.h"

typedef struct Unk80073318 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 padA[0x10 - 0xA];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x18 - 0x15];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x60 - 0x1C];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0xA0 - 0x68];
    /* 0xA0 */ u32 hitFlags;
    /* 0xA4 */ u8 padA4[0xAB - 0xA4];
    /* 0xAB */ u8 hitHi : 4;
    /* 0xAB */ u8 hitType : 4;
    /* 0xAC */ u8 padAC[0xCC - 0xAC];
    /* 0xCC */ u8 unkCC;
} Unk80073318;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[1];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern void** lbl_80270168[];

u32 fn_80080484(void* cam, s32* pos, s32 arg2);
u16 fn_800A3458(s32 x, s32 y);

static inline void SetMode(Unk80073318* obj, u8 mode) {
    obj->unk18 = lbl_80270168[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

BOOL fn_80073318(Unk80073318* obj) {
    if (obj->state != 1 && obj->hitType == 3) {
        obj->state = 1;
        obj->step = 0;
        obj->unkCC = 0;
        return FALSE;
    }
    if (obj->state != 2 && obj->hitType == 5) {
        obj->state = 2;
        obj->step = 0;
        obj->unkCC = 0;
        return FALSE;
    }
    if (((obj->hitFlags & 0x100) && !(obj->hitFlags & 0x1000)) || (obj->hitFlags & 0x80000)) {
        SetMode(obj, 2);
        return TRUE;
    }
    if (fn_80080484(lbl_80304B90.unk21C, &obj->x, 1) > 0x1000) {
        SetMode(obj, 2);
        return TRUE;
    }
    if (obj->unk14 != 0 && fn_800A3458(obj->x, obj->y) != 0) {
        SetMode(obj, 2);
        return TRUE;
    }
    if (obj->unkCC != 0) {
        SetMode(obj, 2);
        return TRUE;
    }
    return FALSE;
}
