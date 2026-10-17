#include "types.h"

typedef struct UnkAC170 {
    /* 0x000 */ u8 pad000[0x9];
    /* 0x009 */ u8 unk009;
    /* 0x00A */ u8 unk00A;
    /* 0x00B */ u8 pad00B[0x11 - 0xB];
    /* 0x011 */ u8 unk011;
    /* 0x012 */ u8 unk012;
    /* 0x013 */ u8 unk013;
    /* 0x014 */ u8 pad014[0x0E6 - 0x14];
    /* 0x0E6 */ s16 unk0E6;
    /* 0x0E8 */ u8 pad0E8[0x0EC - 0xE8];
    /* 0x0EC */ u8 unk0EC;
    /* 0x0ED */ u8 unk0ED;
    /* 0x0EE */ u8 unk0EE;
    /* 0x0EF */ u8 unk0EF;
    /* 0x0F0 */ u8 unk0F0;
    /* 0x0F1 */ u8 unk0F1;
    /* 0x0F2 */ u8 unk0F2;
    /* 0x0F3 */ u8 unk0F3;
    /* 0x0F4 */ u8 unk0F4;
    /* 0x0F5 */ u8 unk0F5;
    /* 0x0F6 */ u8 pad0F6[0x1E0 - 0xF6];
    /* 0x1E0 */ s16 unk1E0;
    /* 0x1E2 */ u8 pad1E2[0x1E8 - 0x1E2];
    /* 0x1E8 */ s16 unk1E8;
} UnkAC170;

s32 fn_800B417C(void);
s32 fn_800B4450(UnkAC170* obj);
s32 fn_800B44D0(UnkAC170* obj);
s32 fn_800B4478(UnkAC170* obj);
s32 fn_800B45D0(UnkAC170* obj);
s32 fn_800B490C(UnkAC170* obj);
s32 fn_800B462C(UnkAC170* obj);
s32 fn_800B4754(UnkAC170* obj);

s32 fn_800AC170(UnkAC170* obj) {
    s32 r = fn_800B417C();

    if ((u32)r != 1) {
        return r;
    }
    if (fn_800B4450(obj) != 0) {
        obj->unk0EC = obj->unk011;
        obj->unk011 = 2;
        obj->unk0ED = obj->unk012;
        obj->unk012 = 0;
        obj->unk0EE = obj->unk013;
        obj->unk013 = 0;
        obj->unk0F2 = obj->unk0EF;
        obj->unk0EF = 0;
        obj->unk0F3 = obj->unk0F0;
        obj->unk0F0 = 0;
        obj->unk0F4 = obj->unk0F1;
        obj->unk0F1 = 0;
        obj->unk0F5 = 2;
        return 2;
    }
    if (obj->unk0E6 < 0) {
        obj->unk0EC = obj->unk011;
        obj->unk011 = 2;
        obj->unk0ED = obj->unk012;
        obj->unk012 = 0;
        obj->unk0EE = obj->unk013;
        obj->unk013 = 0;
        obj->unk0F2 = obj->unk0EF;
        obj->unk0EF = 0;
        obj->unk0F3 = obj->unk0F0;
        obj->unk0F0 = 0;
        obj->unk0F4 = obj->unk0F1;
        obj->unk0F1 = 0;
        obj->unk0F5 = 2;
        return 2;
    }
    if (fn_800B44D0(obj) != 0) {
        obj->unk0EC = obj->unk011;
        obj->unk011 = 4;
        obj->unk0ED = obj->unk012;
        obj->unk012 = 0;
        obj->unk0EE = obj->unk013;
        obj->unk013 = 0;
        obj->unk0F2 = obj->unk0EF;
        obj->unk0EF = 0;
        obj->unk0F3 = obj->unk0F0;
        obj->unk0F0 = 0;
        obj->unk0F4 = obj->unk0F1;
        obj->unk0F1 = 0;
        obj->unk0F5 = 4;
        return 4;
    }
    if (fn_800B4478(obj) != 0 && fn_800B45D0(obj) == 0) {
        obj->unk0EC = obj->unk011;
        obj->unk011 = 2;
        obj->unk0ED = obj->unk012;
        obj->unk012 = 0;
        obj->unk0EE = obj->unk013;
        obj->unk013 = 0;
        obj->unk0F2 = obj->unk0EF;
        obj->unk0EF = 0;
        obj->unk0F3 = obj->unk0F0;
        obj->unk0F0 = 0;
        obj->unk0F4 = obj->unk0F1;
        obj->unk0F1 = 0;
        obj->unk0F5 = 2;
        return 2;
    }
    if (fn_800B490C(obj) == 0) {
        obj->unk0EC = obj->unk011;
        obj->unk011 = 0;
        obj->unk0ED = obj->unk012;
        obj->unk012 = 0;
        obj->unk0EE = obj->unk013;
        obj->unk013 = 0;
        obj->unk0F2 = obj->unk0EF;
        obj->unk0EF = 0;
        obj->unk0F3 = obj->unk0F0;
        obj->unk0F0 = 0;
        obj->unk0F4 = obj->unk0F1;
        obj->unk0F1 = 0;
        obj->unk0F5 = 0;
        return 0;
    }
    if (fn_800B462C(obj) != 0) {
        obj->unk0EC = obj->unk011;
        obj->unk011 = 3;
        obj->unk0ED = obj->unk012;
        obj->unk012 = 0;
        obj->unk0EE = obj->unk013;
        obj->unk013 = 0;
        obj->unk0F2 = obj->unk0EF;
        obj->unk0EF = 0;
        obj->unk0F3 = obj->unk0F0;
        obj->unk0F0 = 0;
        obj->unk0F4 = obj->unk0F1;
        obj->unk0F1 = 0;
        obj->unk0F5 = 3;
        return 3;
    }
    if (fn_800B4754(obj) != 0) {
        obj->unk0EC = obj->unk011;
        obj->unk011 = 3;
        obj->unk0ED = obj->unk012;
        obj->unk012 = 0;
        obj->unk0EE = obj->unk013;
        obj->unk013 = 0;
        obj->unk0F2 = obj->unk0EF;
        obj->unk0EF = 0;
        obj->unk0F3 = obj->unk0F0;
        obj->unk0F0 = 0;
        obj->unk0F4 = obj->unk0F1;
        obj->unk0F1 = 0;
        obj->unk0F5 = 3;
        return 3;
    }
    return 1;
}
