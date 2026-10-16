#include "types.h"

typedef struct Unk800D6CE4 {
    /* 0x00 */ u8 pad0[0x12];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 weapon;
    /* 0x16 */ u8 pad16[0x88 - 0x16];
    /* 0x88 */ u8 unk88;
} Unk800D6CE4;

typedef struct Unk800D6CE4Gfx {
    /* 0x0000 */ u8 pad0[0x1000];
    /* 0x1000 */ u8 weapon;
    /* 0x1001 */ u8 pad1001;
    /* 0x1002 */ u8 unk1002;
} Unk800D6CE4Gfx;

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

typedef struct Unk8036CF50 {
    /* 0x0 */ s32 stage;
    /* 0x4 */ u8 pad4[0xEFE0 - 0x4];
} Unk8036CF50;

extern void* lbl_804EE984;
extern u8 lbl_80280818[];
extern Unk8036CF50 lbl_8036CF50;
extern Unk80316D78 lbl_80316D78;

BOOL fn_800B58F8(void* player, s32 arg1);
void fn_800E946C(Unk800D6CE4* obj, u8 anim);
void fn_800E97F0(Unk800D6CE4* obj, u8 arg1);
void fn_800E9750(Unk800D6CE4* obj, u16 arg1);

#define GFX ((Unk800D6CE4Gfx*)(lbl_80316D78.unk3004 + 0xD40000))

void fn_800D6CE4(Unk800D6CE4* obj) {
    u8 n;

    switch (obj->step) {
    case 0:
        if (fn_800B58F8(lbl_804EE984, 2)) {
            if (obj->unk14 == 0) {
                if ((u8)(obj->weapon + 0xF7) <= 1) {
                    if (lbl_8036CF50.stage == 0) {
                        fn_800E946C(obj, lbl_80280818[obj->weapon + 2]);
                    } else {
                        fn_800E946C(obj, lbl_80280818[obj->weapon + 4]);
                    }
                } else {
                    fn_800E946C(obj, lbl_80280818[obj->weapon]);
                }
            } else if (obj->unk14 == 5) {
                switch (obj->weapon) {
                case 9:
                    n = 0;
                    goto shared;
                case 10:
                    n = 1;
                shared:
                    fn_800E946C(obj, n + lbl_8036CF50.stage * 3 + 0x43);
                    break;
                case 0:
                    fn_800E946C(obj, lbl_8036CF50.stage * 3 + 0x42);
                    break;
                default:
                    fn_800E946C(obj, lbl_80280818[obj->weapon] + lbl_8036CF50.stage * 0xB);
                    break;
                }
            }
        } else if (obj->unk14 == 5) {
            fn_800E946C(obj, lbl_80280818[obj->weapon] + lbl_8036CF50.stage * 0xB);
        } else {
            fn_800E946C(obj, lbl_80280818[obj->weapon]);
        }
        fn_800E97F0(obj, obj->unk88 + 1);
        obj->step++;
    case 1:
        if (GFX->unk1002 == 0 && GFX->weapon == obj->weapon) {
            fn_800E97F0(obj, obj->unk88);
        } else {
            fn_800E97F0(obj, obj->unk88 + 1);
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
