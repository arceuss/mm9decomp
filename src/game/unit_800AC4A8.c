#include "types.h"

typedef struct Unk800AC4A8 {
    /* 0x000 */ u8 pad0[0x11];
    /* 0x011 */ u8 state;
    /* 0x012 */ u8 step;
    /* 0x013 */ u8 unk13;
    /* 0x014 */ u8 unk14;
    /* 0x015 */ u8 pad15[0xEC - 0x15];
    /* 0x0EC */ u8 savedState;
    /* 0x0ED */ u8 savedStep;
    /* 0x0EE */ u8 savedUnk13;
    /* 0x0EF */ u8 unkEF;
    /* 0x0F0 */ u8 unkF0;
    /* 0x0F1 */ u8 unkF1;
    /* 0x0F2 */ u8 savedEF;
    /* 0x0F3 */ u8 savedF0;
    /* 0x0F4 */ u8 savedF1;
    /* 0x0F5 */ u8 unkF5;
    /* 0x0F6 */ u8 padF6[0x104 - 0xF6];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 pad108[0x188 - 0x108];
    /* 0x188 */ u16 unk188;
} Unk800AC4A8;

u32 fn_800B417C(Unk800AC4A8* obj);
BOOL fn_800B462C(Unk800AC4A8* obj);

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x2A0];
    /* 0x2A0 */ u16 unk2A0[4];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;

u32 fn_800AC4A8(Unk800AC4A8* obj) {
    u32 result = fn_800B417C(obj);
    u16 mask;
    u16 held;
    u8 step;

    if (result != 2) {
        return result;
    }
    if (fn_800B462C(obj)) {
        obj->savedState = obj->state;
        obj->state = 3;
        obj->savedStep = obj->step;
        obj->step = 0;
        obj->savedUnk13 = obj->unk13;
        obj->unk13 = 0;
        obj->savedEF = obj->unkEF;
        obj->unkEF = 0;
        obj->savedF0 = obj->unkF0;
        obj->unkF0 = 0;
        obj->savedF1 = obj->unkF1;
        obj->unkF1 = 0;
        obj->unkF5 = 3;
        return 3;
    }
    step = obj->step;
    if (step == 1) {
        held = obj->unk188;
        mask = 0x20;
        if (lbl_80304B90.unk2A0[obj->unk14] & 0x8000) {
            mask = 0x100;
        }
        if (!(held & mask) || (obj->unk104 & 0x8000)) {
            obj->savedStep = step;
            obj->step = 2;
            obj->savedUnk13 = obj->unk13;
            obj->unk13 = 0;
        }
    }
    return 2;
}
