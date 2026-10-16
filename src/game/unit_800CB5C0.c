#include "types.h"

typedef struct Unk800CB5C0 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
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
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(struct Unk800CB5C0* obj);
} Unk800CB5C0;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;
extern void** lbl_80280390[];
extern u8 lbl_804ECFD0[4];
extern void (*lbl_804ECFC8[2])(Unk800CB5C0* obj);

void fn_800E9424(Unk800CB5C0* obj, u16 id);
void fn_800E9244(Unk800CB5C0* obj);
void fn_800CB5BC(Unk800CB5C0* obj);
s32 fn_800A36F8(s32 x, s32 y);
s32 fn_800A43B4(s32 x, s32 y);

static inline void SetMode(Unk800CB5C0* obj, u8 mode) {
    obj->unk18 = lbl_80280390[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

void fn_800CB5C0(Unk800CB5C0* obj) {
    s32 d;
    u32 st;

    st = lbl_804ECFD0[obj->unk14];
    obj->unk18 = lbl_80280390[obj->kind][1];
    obj->unk10 = 1;
    obj->step = 0;
    obj->unk13 = 0;
    obj->state = st;
    fn_800E9424(obj, 0x18);
    fn_800E9244(obj);
    obj->unkAC = fn_800CB5BC;
    obj->flagsA &= ~1;
    d = fn_800A36F8(obj->x, obj->y);
    if (d < 0) {
        obj->y = d + obj->y + 0x100;
    } else {
        d = fn_800A43B4(obj->x, obj->y);
        if (d != 0 && d != 0x7FFFFFFF && d != -1) {
            obj->y = d + 0x100;
        }
    }
    if (lbl_803051D8.unk2 & 0x20) {
        obj->flagsA &= ~1;
        obj->flagsA &= 0xFD;
        fn_800E9244(obj);
        SetMode(obj, 3);
        return;
    }
    lbl_804ECFC8[obj->state](obj);
}
