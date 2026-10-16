#include "types.h"

typedef struct Unk80068D84 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x11 - 0xB];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 pad17[0x34 - 0x17];
    /* 0x34 */ struct Unk80068D84* parent;
    /* 0x38 */ struct Unk80068D84* child;
    /* 0x3C */ u8 pad3C[0x60 - 0x3C];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0x7F - 0x70];
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[0x88 - 0x80];
    /* 0x88 */ u8 unk88[0xC8 - 0x88];
    /* 0xC8 */ u8 unkC8;
} Unk80068D84;

extern u8 lbl_804ECC34[4];
extern u8 lbl_80267F58[];
extern void* lbl_804EE738;

void fn_800E946C(Unk80068D84* obj, u8 anim);
s32 fn_800A36F8(s32 x, s32 y);
s32 fn_800A4098(s32 x, s32 y);
void fn_8009996C(void* arg0, void* arg1);
Unk80068D84* fn_800E8C44(void* pool);
void fn_80042DA0(Unk80068D84* obj, s32 kind);
void fn_800E9750(Unk80068D84* obj, u16 arg1);

void fn_80068D84(Unk80068D84* obj) {
    s32 d;
    s32 gy;
    u8 k;
    Unk80068D84* child;
    s32 cx;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 0xF);
        obj->vy = 0x600;
        obj->timer = 8;
        obj->step++;
    case 1:
        obj->y += obj->vy;
        if (obj->timer == 0) {
            d = fn_800A36F8(obj->x, obj->y + 0x3000);
            if (d != 0) {
                obj->y += d;
                obj->step++;
            }
        } else {
            obj->timer--;
        }
        break;
    case 2:
        fn_800E946C(obj, 0x10);
        obj->y = fn_800A4098(obj->x, obj->y) - 0x1800;
        obj->step++;
    case 3:
        if (obj->unk7F == 3) {
            obj->step++;
        }
        break;
    case 4:
        fn_800E946C(obj, lbl_804ECC34[obj->unk14]);
        fn_8009996C(obj->unk88, lbl_80267F58);
        gy = fn_800A4098(obj->x, obj->y);
        obj->y = gy;
        cx = obj->x + (((obj->flagsA >> 3) & 2) - 1) * 0x3C00;
        k = obj->unk14;
        child = fn_800E8C44(lbl_804EE738);
        if (child != NULL) {
            fn_80042DA0(child, 0x26);
            child->parent = obj;
            child->x = cx;
            child->y = gy;
            child->unk14 = 2;
            child->unkC8 = k;
        }
        obj->child = child;
        obj->timer = 0x14;
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
