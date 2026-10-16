#include "types.h"

typedef struct Unk8001777C {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x12 - 0xB];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17[0x54 - 0x17];
    /* 0x54 */ u32 unk54_hi : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_lo : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x7C - 0x68];
    /* 0x7C */ u8 unk7C;
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 pad7E;
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[0x88 - 0x80];
    /* 0x88 */ u8 unk88[0xDA - 0x88];
    /* 0xDA */ u8 phase;
} Unk8001777C;

extern u8 lbl_804EC754[4];
extern u8 lbl_804EC758[4];
extern u8 lbl_80262720[];
extern u8 lbl_802626F0[];
extern Unk8001777C* lbl_804EE984;
extern u32 lbl_804EE988;

void fn_800E946C(Unk8001777C* obj, u8 anim);
void fn_8009996C(void* arg0, void* arg1);
void fn_80066010(Unk8001777C* obj, s32 x, s32 y, s32 arg3, s32 dir);
void fn_80017CC4(Unk8001777C* obj);
void fn_800E9750(Unk8001777C* obj, u16 arg1);

void fn_8001777C(Unk8001777C* obj) {
    u32 rnd;
    s32 d;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, lbl_804EC754[obj->phase]);
        d = lbl_804EE984->x - obj->x;
        obj->flipX = (u32)(-d & ~d) >> 31;
        if (obj->flipX) {
            obj->flagsA |= 0x10;
        } else {
            obj->flagsA &= 0xEF;
        }
        obj->step++;
    case 1:
        if (obj->unk7C == 3 && obj->unk7D != 0) {
            fn_8009996C(obj->unk88, lbl_80262720);
        }
        if (obj->unk7F == 4) {
            obj->step++;
        }
        break;
    case 2:
        obj->timer = 0x4A;
        rnd = lbl_804EE988 * 0x343FD + 0x269EC3;
        lbl_804EE988 = rnd & 0x7FFFFFFF;
        if ((rnd >> 16) & 1) {
            fn_80066010(obj, obj->x, obj->y, 1, 1);
            fn_80066010(obj, obj->x, obj->y, 1, 4);
            fn_80066010(obj, obj->x, obj->y, 1, 5);
        } else {
            fn_80066010(obj, obj->x, obj->y, 1, 2);
            fn_80066010(obj, obj->x, obj->y, 1, 3);
            fn_80066010(obj, obj->x, obj->y, 1, 6);
        }
        obj->step++;
    case 3:
        if (obj->timer == 0) {
            obj->step++;
        } else {
            obj->timer--;
        }
        break;
    case 4:
        fn_800E946C(obj, lbl_804EC758[obj->phase]);
        fn_8009996C(obj->unk88, lbl_802626F0);
        obj->timer = 0x3C;
        obj->step++;
    case 5:
        if (obj->timer == 0) {
            fn_80017CC4(obj);
        } else {
            obj->timer--;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
