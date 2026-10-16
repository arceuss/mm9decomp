#include "types.h"

typedef struct Unk800AC5B8 {
    /* 0x000 */ u8 pad0[0x11];
    /* 0x011 */ u8 state;
    /* 0x012 */ u8 step;
    /* 0x013 */ u8 unk13;
    /* 0x014 */ u8 pad14[0xEC - 0x14];
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
} Unk800AC5B8;

u32 fn_800B417C(Unk800AC5B8* obj);
BOOL fn_800B4478(Unk800AC5B8* obj);
BOOL fn_800B4814(Unk800AC5B8* obj);
BOOL fn_800B4890(Unk800AC5B8* obj);

u32 fn_800AC5B8(Unk800AC5B8* obj) {
    u32 result = fn_800B417C(obj);

    if (result != 3) {
        return result;
    }
    if ((fn_800B4478(obj) || (obj->unk104 & 0x4000)) && !fn_800B4814(obj) && !fn_800B4890(obj)) {
        obj->savedState = obj->state;
        obj->state = 2;
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
        obj->unkF5 = 2;
        return 2;
    }
    return 3;
}
