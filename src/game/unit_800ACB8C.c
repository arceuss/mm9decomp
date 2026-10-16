#include "types.h"

typedef struct Unk800ACB8C {
    /* 0x000 */ u8 pad0[0xA];
    /* 0x00A */ u8 flagsA;
    /* 0x00B */ u8 padB[0x11 - 0xB];
    /* 0x011 */ u8 state;
    /* 0x012 */ u8 step;
    /* 0x013 */ u8 unk13;
    /* 0x014 */ u8 pad14[0x60 - 0x14];
    /* 0x060 */ u8 unk60[0xA0 - 0x60];
    /* 0x0A0 */ u32 flagsA0;
    /* 0x0A4 */ u8 padA4[0xC8 - 0xA4];
    /* 0x0C8 */ u8 unkC8[0xEC - 0xC8];
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
    /* 0x0F6 */ u8 padF6[0xFD - 0xF6];
    /* 0x0FD */ u8 unkFD;
    /* 0x0FE */ u8 padFE[0x101 - 0xFE];
    /* 0x101 */ u8 unk101;
    /* 0x102 */ u8 pad102[0x117 - 0x102];
    /* 0x117 */ u8 unk117;
    /* 0x118 */ u8 pad118[0x19C - 0x118];
    /* 0x19C */ s32 unk19C[2];
} Unk800ACB8C;

u32 fn_800B417C(Unk800ACB8C* obj);
void fn_800B7A28(void* pos, void* box, s32* bounds, s32 x, s32 y, u32 flags);
void fn_800ABE2C(Unk800ACB8C* obj);

u32 fn_800ACB8C(Unk800ACB8C* obj) {
    u32 result = fn_800B417C(obj);
    s32* bounds;

    if (result != 13) {
        return result;
    }
    if (!(obj->flagsA0 & 0x400)) {
        obj->unk117 = 0;
        obj->unkFD = 0xFF;
        if (obj->unk101 == 15) {
            obj->unk101 = 0xFF;
        }
        bounds = obj->unk19C;
        fn_800B7A28(obj->unk60, obj->unkC8, bounds, bounds[0], bounds[1], ((obj->flagsA & 0x10) << 14) | 0x380001);
        fn_800ABE2C(obj);
        result = obj->state;
        if (obj->state == 13) {
            obj->savedState = obj->state;
            obj->state = 0;
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
            obj->unkF5 = 0;
            result = 0;
        }
    } else {
        result = 13;
    }
    return result;
}
