#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk8007497C {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 padA[0x10 - 0xA];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x60 - 0x1C];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0xA0 - 0x68];
    /* 0xA0 */ u32 hitFlags;
    /* 0xA4 */ u8 padA4[0xAB - 0xA4];
    /* 0xAB */ u8 hitHi : 4;
    /* 0xAB */ u8 hitType : 4;
} Unk8007497C;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[1];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern void** lbl_80270168[];

void fn_80040AD0(s32 arg0, Vec2i* pos, s32 arg2, s32 arg3);
void fn_800D5234(s32 id);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);

BOOL fn_8007497C(Unk8007497C* obj) {
    Vec2i pos;

    if (obj->state != 1 && obj->hitType == 3) {
        obj->state = 1;
        obj->step = 0;
        return FALSE;
    }
    if (obj->state != 2 && obj->hitType == 5) {
        obj->state = 2;
        obj->step = 0;
        return FALSE;
    }
    if ((obj->hitFlags & 0x100) || (obj->hitFlags & 0x80000)) {
        obj->unk18 = lbl_80270168[obj->kind][2];
        obj->unk10 = 2;
        obj->unk13 = 0;
        obj->state = 0;
        obj->step = 0;
        pos.x = obj->x;
        pos.y = obj->y;
        fn_80040AD0(2, &pos, 0, 0);
        fn_800D5234(0x14);
        return TRUE;
    }
    if (fn_80080484(lbl_80304B90.unk21C, &obj->x, 1) > 0x800) {
        obj->unk18 = lbl_80270168[obj->kind][2];
        obj->unk10 = 2;
        obj->unk13 = 0;
        obj->state = 0;
        obj->step = 0;
        return TRUE;
    }
    return FALSE;
}
