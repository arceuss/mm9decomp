#include "types.h"

typedef struct Unk800CA8EC {
    /* 0x00 */ u8 pad0[0xB];
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u8 padC[0x11 - 0xC];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 pad18[0x34 - 0x18];
    /* 0x34 */ struct Unk800CA8EC* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ u8 pad6C[0xD0 - 0x6C];
    /* 0xD0 */ s32 unkD0;
    /* 0xD4 */ s32 unkD4;
} Unk800CA8EC;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x126];
    /* 0x126 */ u8 unk126;
    /* 0x127 */ u8 pad127[0x239 - 0x127];
    /* 0x239 */ u8 unk239;
    /* 0x23A */ u8 pad23A[0x242 - 0x23A];
    /* 0x242 */ s16 unk242;
    /* 0x244 */ u8 pad244[0x26C - 0x244];
    /* 0x26C */ void* unk26C;
    /* 0x270 */ u8 pad270[0x2CC - 0x270];
    /* 0x2CC */ u8 unk2CC[4];
} Unk80304B90;

typedef struct Unk8043CD28 {
    /* 0x000 */ u8 pad0[0x2E4];
    /* 0x2E4 */ u8 unk2E4;
    /* 0x2E5 */ u8 pad2E5[0x2E8 - 0x2E5];
} Unk8043CD28;

extern u8 lbl_803051D8[];
extern Unk80304B90 lbl_80304B90;
extern Unk8043CD28 lbl_8043CD28;

void fn_800E9244(Unk800CA8EC* obj);
void fn_800D5234(s32 se);
void fn_800CAE94(Unk800CA8EC* obj, u8 idx, s32 mode);
void fn_800C798C(void);
void fn_800B5DD4(Unk800CA8EC* obj);

void fn_800CA8EC(Unk800CA8EC* obj) {
    Unk800CA8EC* parent = obj->parent;

    switch (obj->step) {
    case 0:
        lbl_803051D8[2] |= 0x20;
        lbl_8043CD28.unk2E4 = 0;
        fn_800E9244(obj);
        obj->unkB &= 0xEF;
        if (!(obj->unk14 & 0x10)) {
            obj->step = 2;
            break;
        }
        fn_800D5234(5);
        obj->timer = 4;
        obj->unk17 = 0;
        obj->step++;
    case 1:
        if (--obj->timer == 0) {
            fn_800CAE94(obj, obj->unk17, 0);
            if (++obj->unk17 >= 4) {
                obj->step++;
            }
            obj->timer = 4;
        }
        break;
    case 2:
        if (obj->unk13 == 1) {
            obj->unkD0 = obj->x + 0x2000;
        } else {
            obj->unkD0 = obj->x - 0x2000;
        }
        obj->unkD4 = parent->y;
        lbl_80304B90.unk26C = &obj->unkD0;
        lbl_80304B90.unk242 = 0;
        lbl_80304B90.unk239 = 0x40;
        obj->timer = 0x40;
        obj->vx = (obj->unkD0 - parent->x) / obj->timer;
        obj->step++;
    case 3:
        parent->x += obj->vx;
        if (--obj->timer == 0) {
            if (obj->unk14 & 0x10) {
                obj->step++;
            } else {
                obj->step = 6;
            }
        }
        break;
    case 4:
        fn_800D5234(5);
        obj->timer = 4;
        obj->step++;
    case 5:
        if (--obj->timer == 0) {
            fn_800CAE94(obj, --obj->unk17, 1);
            if (obj->unk17 == 0) {
                obj->step++;
            }
            obj->timer = 4;
        }
        break;
    case 6:
        if (lbl_80304B90.unk239 & 0xC0) {
            break;
        }
        lbl_80304B90.unk26C = lbl_80304B90.unk2CC;
        lbl_80304B90.unk126 &= ~1;
        obj->step++;
    case 7:
        obj->unk11 = 0;
        obj->step = 0;
        lbl_803051D8[2] &= ~0x20;
        lbl_8043CD28.unk2E4 = 1;
        if ((obj->unk14 & 0x10) && obj->unk15 == 0) {
            fn_800C798C();
        }
        fn_800B5DD4(parent);
        break;
    }
}
