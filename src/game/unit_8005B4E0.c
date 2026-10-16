#include "types.h"

typedef struct Unk8005B4E0 {
    /* 0x00 */ u8 pad0[0x12];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x50 - 0x13];
    /* 0x50 */ struct {
        u32 hi : 30;
        u32 layer : 2;
    } bits50;
    /* 0x54 */ u8 pad54[0x60 - 0x54];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
} Unk8005B4E0;

typedef struct Unk804EE984 {
    /* 0x00 */ u8 pad0[0x64];
    /* 0x64 */ s32 y;
} Unk804EE984;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[1];
} Unk80304B90;

extern u8 lbl_8031BF70[];
extern Unk804EE984* lbl_804EE984;
extern Unk80304B90 lbl_80304B90;

void fn_800E946C(Unk8005B4E0* obj, s32 arg1);
void fn_800E9750(Unk8005B4E0* obj, u16 arg1);
u16 fn_8009E894(s32 x, s32 y);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);
void fn_80042D30(Unk8005B4E0* obj);

void fn_8005B4E0(Unk8005B4E0* obj) {
    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0);
        obj->vx = *(s32*)(lbl_8031BF70 + 0x4CEEC);
        obj->vy = 0xA0;
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        if (fn_8009E894(obj->x, obj->y) == 0x200 || fn_8009E894(obj->x, obj->y + 0x1000) == 0x200 ||
            fn_8009E894(obj->x - 0xF00, obj->y - 0x800) == 0x200 ||
            fn_8009E894(obj->x + 0xF00, obj->y - 0x800) == 0x200 ||
            fn_8009E894(obj->x, obj->y - 0xC00) == 0x200) {
            obj->bits50.layer = 3;
        } else {
            obj->bits50.layer = 2;
        }
        obj->x += obj->vx;
        obj->y += obj->vy;
        if (obj->y > lbl_804EE984->y && fn_80080484(lbl_80304B90.unk21C, &obj->x, 1) > 0x1400) {
            fn_80042D30(obj);
        }
        break;
    }
}
