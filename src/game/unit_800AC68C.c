#include "types.h"

typedef struct UnkAC68C {
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
    /* 0x0F6 */ u8 pad0F6[0x104 - 0xF6];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 pad108[0x19C - 0x108];
    /* 0x19C */ u32 unk19C;
} UnkAC68C;

typedef struct Unk8027EB60 {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u8 pad04[0x0C - 0x4];
    /* 0x0C */ u32 unk0C;
    /* 0x10 */ u8 pad10[0x1C - 0x10];
    /* 0x1C */ u32 unk1C;
} Unk8027EB60;

extern Unk8027EB60* lbl_8027EB60[];

s32 fn_800B417C(void);
s32 fn_800B4450(UnkAC68C* obj);
s32 fn_800B4478(UnkAC68C* obj);
s32 fn_800B45D0(UnkAC68C* obj);
s32 fn_800B490C(UnkAC68C* obj);
s32 fn_800B79D4(UnkAC68C* obj, u32 arg, s32 zero);
s32 fn_800B911C(u32* a, u32* b, u32* c, s32 d, u32 e, s32 f);

s32 fn_800AC68C(UnkAC68C* obj) {
    s32 r = fn_800B417C();

    if ((u32)r != 4)
        return r;
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
    {
        u32* p = &obj->unk19C;

        if (fn_800B911C((u32*)((u8*)obj + 0x60), (u32*)((u8*)obj + 0xC8), p,
                        fn_800B79D4(obj, lbl_8027EB60[obj->unk009]->unk0C, 0), *p,
                        (obj->unk00A >> 4) & 1) == 0) {
            if ((fn_800B4478(obj) != 0 && fn_800B45D0(obj) == 0) || obj->unk0E6 < 0) {
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
            if (obj->unk104 & 0x1000) {
                if (fn_800B490C(obj) != 0) {
                    obj->unk0EC = obj->unk011;
                    obj->unk011 = 1;
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
                    obj->unk0F5 = 1;
                    return 1;
                }
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
        }
    }
    return 4;
}
