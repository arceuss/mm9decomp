#include "types.h"

typedef struct Unk8006EAC4 {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s8 unk8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 padA[0x10 - 0xA];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13;
    /* 0x14 */ u8 type;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x34 - 0x16];
    /* 0x34 */ struct Unk8006EAC4* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 pos[2];
    /* 0x68 */ u8 pad68[0xA0 - 0x68];
    /* 0xA0 */ u32 hit;
    /* 0xA4 */ u8 padA4[0xAB - 0xA4];
    /* 0xAB */ struct {
        u8 hi : 4;
        u8 lo : 4;
    } unkAB;
    /* 0xAC */ u8 padAC[0xD0 - 0xAC];
    /* 0xD0 */ u8 unkD0;
    /* 0xD1 */ u8 unkD1;
} Unk8006EAC4;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 cam[0x40];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern u8 lbl_803051D8[];
extern void (*lbl_802686E8[])(Unk8006EAC4* obj);

void fn_80042D30(Unk8006EAC4* obj);
u32 fn_80080484(void* cam, s32* pos, s32 arg2);
void fn_80042CF8(Unk8006EAC4* obj, s32 a);
void fn_800C7C24(s32 a, u8 b, u8 c);

s32 fn_8006EAC4(Unk8006EAC4* obj) {
    s32 ret = 0;
    s32 hit = 1;
    u8* const flags = lbl_803051D8;
    Unk8006EAC4* p;

    if (flags[2] & 0x20) {
        fn_80042D30(obj);
        return 1;
    }
    if (fn_80080484(lbl_80304B90.cam, obj->pos, 1) >= 0x800) {
        fn_80042D30(obj);
        return 1;
    }
    if ((flags[2] & 0x10) && (obj->type != 3 || obj->unk15 < 2)) {
        fn_80042CF8(obj, 2);
        obj->state = 4;
        ret = 1;
    } else if (obj->state != 4 && obj->unkAB.lo == 3) {
        obj->state = 4;
        obj->step = 0;
    } else if (obj->state != 5 && obj->unkAB.lo == 5) {
        obj->state = 5;
        obj->step = 0;
    } else if ((obj->hit & 1) && obj->unkAB.lo == 8) {
        fn_80042CF8(obj, 2);
        obj->state = 2;
        ret = 1;
    } else if ((obj->hit & 0x200) && obj->unkAB.lo == 2) {
        fn_80042CF8(obj, 2);
        obj->state = 3;
        ret = 1;
    } else if (obj->hit & 0x200) {
        fn_80042CF8(obj, 2);
        obj->state = 0;
        ret = 1;
    } else {
        hit = 0;
    }
    if (obj->type == 2) {
        p = obj->parent;
        if (p != NULL && p->unk10 < 2 && p->unkD0 == 0) {
            if (p->state == 4) {
                fn_80042D30(obj);
                return 1;
            }
            if (p->state == 5) {
                fn_80042D30(obj);
                return 1;
            }
            if (hit) {
                p->unkD0 = 1;
                p->unkD1 = 0x10;
            }
        }
    }
    if (ret) {
        if (obj->step == 0) {
            if (obj->type == 1) {
                fn_800C7C24(obj->unk8, obj->unk9, obj->type);
            }
            obj->step++;
        }
        lbl_802686E8[obj->state](obj);
    }
    return ret;
}
