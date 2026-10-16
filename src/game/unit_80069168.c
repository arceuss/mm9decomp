#include "types.h"

typedef struct Unk80069168 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17[0x38 - 0x17];
    /* 0x38 */ struct Unk80069168* target;
    /* 0x3C */ u8 pad3C[0x60 - 0x3C];
    /* 0x60 */ s32 x;
    /* 0x64 */ u8 pad64[0x88 - 0x64];
    /* 0x88 */ u8 unk88[0x10];
} Unk80069168;

extern u8 lbl_804ECC38[4];
extern u8 lbl_804ECC44[4];
extern u8 lbl_804ECC34[4];
extern u8 lbl_80267FE8[];
extern u8 lbl_80267F58[];
extern Unk80069168* lbl_804EE984;

void fn_800E946C(Unk80069168* obj, u8 anim);
void fn_8009996C(void* arg0, void* arg1);
void fn_800D5234(s32 se);
void fn_800B6430(Unk80069168* player);
void fn_800B60CC(Unk80069168* player, s32 arg1);
void fn_800E9750(Unk80069168* obj, u16 arg1);

void fn_80069168(Unk80069168* obj) {
    Unk80069168* player;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, lbl_804ECC38[obj->unk14]);
        obj->timer = 8;
        obj->step++;
    case 1:
        if (obj->timer == 0) {
            obj->step++;
        } else {
            obj->timer--;
        }
        break;
    case 2:
        fn_800E946C(obj, lbl_804ECC44[obj->unk14]);
        fn_8009996C(obj->unk88, lbl_80267FE8);
        fn_800D5234(0x46);
        obj->step++;
    case 3:
        player = lbl_804EE984;
        fn_800B6430(player);
        if (player->x < obj->x - 0x3C00) {
            fn_800B60CC(player, 0x100);
        }
        if (obj->x - obj->target->x <= 0x4C00) {
            obj->step++;
        }
        break;
    case 4:
        fn_800E946C(obj, lbl_804ECC34[obj->unk14]);
        fn_8009996C(obj->unk88, lbl_80267F58);
        obj->timer = 0x1E;
        obj->step++;
    case 5:
        if (obj->timer == 0) {
            obj->state = 2;
            obj->step = 0;
        } else {
            obj->timer--;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
