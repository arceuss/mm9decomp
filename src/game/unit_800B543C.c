#include "types.h"

typedef struct UnkB543C {
    /* 0x000 */ u8 pad000[0x9];
    /* 0x009 */ u8 unk009;
    /* 0x00A */ u8 unk00A;
    /* 0x00B */ u8 unk00B;
    /* 0x00C */ u8 pad00C[0x11 - 0xC];
    /* 0x011 */ u8 unk011;
    /* 0x012 */ u8 unk012;
    /* 0x013 */ u8 unk013;
    /* 0x014 */ u8 pad014[0x20 - 0x14];
    /* 0x020 */ u8 unk020;
    /* 0x021 */ u8 unk021;
    /* 0x022 */ u8 pad022[0x0EC - 0x22];
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
    /* 0x0F6 */ u8 pad0F6[0x0FC - 0xF6];
    /* 0x0FC */ u8 unk0FC;
    /* 0x0FD */ u8 pad0FD[0x104 - 0xFD];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 pad108[0x19C - 0x108];
    /* 0x19C */ u32 unk19C;
} UnkB543C;

typedef struct Unk8027EB60 {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u8 pad04[0x1C - 0x4];
    /* 0x1C */ u32 unk1C;
} Unk8027EB60;

extern Unk8027EB60* lbl_8027EB60[];

s32 fn_800B79D4(UnkB543C* obj, u32 arg, s32 zero);
s32 fn_800B911C(u32* a, u32* b, u32* c, s32 d, u32 e, s32 f);
void fn_800B9F74(UnkB543C* obj, u32 arg);

void fn_800B543C(UnkB543C* obj) {
    obj->unk00B |= 0x20;
    obj->unk021 = obj->unk020;
    if (obj->unk104 & 2) {
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
        obj->unk104 = obj->unk104 | 2;
    } else {
        if (((1 << obj->unk009) & 4) == 0) {
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
        } else {
            if (obj->unk0EC == 4) {
                u32* p = &obj->unk19C;
                s32 r = fn_800B79D4(obj, lbl_8027EB60[obj->unk009]->unk00, 0);
                if (fn_800B911C((u32*)((u8*)obj + 0x60), (u32*)((u8*)obj + 0xC8), p, r, *p,
                                (obj->unk00A >> 4) & 1)) {
                    obj->unk0FC = 7;
                    fn_800B9F74(obj, lbl_8027EB60[obj->unk009]->unk1C);
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
                    goto clear;
                }
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
        }
    clear:
        obj->unk104 &= ~2;
    }
}
