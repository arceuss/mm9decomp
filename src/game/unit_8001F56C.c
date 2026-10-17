#include "types.h"

typedef struct Unk8001F56C Unk8001F56C;

struct Unk8001F56C {
    /* 0x000 */ u8 pad0[0xA];
    /* 0x00A */ u8 flagsA;
    /* 0x00B */ u8 padB[0x10 - 0xB];
    /* 0x010 */ u8 unk10;
    /* 0x011 */ u8 state;
    /* 0x012 */ u8 step;
    /* 0x013 */ u8 pad13[0x16 - 0x13];
    /* 0x016 */ u8 unk16;
    /* 0x017 */ u8 pad17[0x54 - 0x17];
    /* 0x054 */ struct {
        u32 hi : 21;
        u32 flip : 1;
        u32 low : 10;
    } bits54;
    /* 0x058 */ u8 pad58[0x60 - 0x58];
    /* 0x060 */ s32 x;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ s32 unk68;
    /* 0x06C */ s32 unk6C;
    /* 0x070 */ u8 pad70[0x74 - 0x70];
    /* 0x074 */ s32 unk74;
    /* 0x078 */ u8 pad78[0x7C - 0x78];
    /* 0x07C */ u8 unk7C;
    /* 0x07D */ u8 pad7D[0xD8 - 0x7D];
    /* 0x0D8 */ Unk8001F56C* unkD8;
    /* 0x0DC */ Unk8001F56C* unkDC;
    /* 0x0E0 */ Unk8001F56C* unkE0;
    /* 0x0E4 */ u8 unkE4;
    /* 0x0E5 */ u8 unkE5;
};

extern u32 lbl_804EE988;

void fn_800E946C(Unk8001F56C* obj, u8 anim);
void fn_800E9750(Unk8001F56C* obj, u16 arg1);
void fn_800E947C(Unk8001F56C* obj, u8 id, s32 arg2, s32 arg3);
s32 fn_800A36F8(s32 x, s32 y);
s32 fn_800A3FAC(s32 x, s32 y);
s32 fn_800A3CD4(s32 x, s32 y);

void fn_8001F56C(Unk8001F56C* obj) {
    Unk8001F56C* a;
    Unk8001F56C* b;
    Unk8001F56C* c;
    u8 hit;
    u8 blocked;
    s32 d;
    s32 e;
    u32 rnd;
    u8 r;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 2);
        obj->unk68 = (((obj->flagsA >> 3) & 2) - 1) * 0x1C0;
        obj->unk6C = 0;
        obj->unk74 = 0x40;
        obj->step++;
    case 1:
        obj->unk64 += obj->unk6C;
        obj->unk6C += obj->unk74;
        hit = 0;
        blocked = 0;
        d = fn_800A36F8(obj->x, obj->unk64);
        if (d != 0) {
            obj->unk6C = 0;
            obj->unk64 += d;
            if (obj->unk7C != 2) {
                fn_800E946C(obj, 2);
            }
        }
        if (obj->unk7C == 2) {
            if (!(obj->flagsA & 0x10)) {
                if (fn_800A36F8(obj->x - 0x800, obj->unk64 + 0x100) == 0) {
                    blocked = 1;
                }
            } else {
                if (fn_800A36F8(obj->x + 0x800, obj->unk64 + 0x100) == 0) {
                    blocked = 1;
                }
            }
        }
        obj->x += obj->unk68;
        if (!(obj->flagsA & 0x10)) {
            d = fn_800A3FAC(obj->x - 0x1000, obj->unk64);
            e = fn_800A3FAC(obj->x - 0x1000, obj->unk64 - 0x1000);
            if (d != 0 && e != 0) {
                obj->x += d;
                hit = 1;
            } else if (d != 0) {
                blocked = 1;
            }
        } else {
            d = fn_800A3CD4(obj->x + 0x1000, obj->unk64);
            e = fn_800A3CD4(obj->x + 0x1000, obj->unk64 - 0x1000);
            if (d != 0 && e != 0) {
                obj->x += d;
                hit = 1;
            } else if (d != 0) {
                blocked = 1;
            }
        }
        if (hit) {
            obj->bits54.flip = !(obj->flagsA & 0x10);
            if (obj->bits54.flip) {
                obj->flagsA |= 0x10;
            } else {
                obj->flagsA &= 0xEF;
            }
            obj->unk68 = (((obj->flagsA >> 3) & 2) - 1) * 0x1C0;
            a = obj->unkD8;
            b = obj->unkDC;
            c = obj->unkE0;
            if (a->unk10 >= 2 && b->unk10 >= 2 && c->unk10 >= 2) {
                obj->state = 2;
                obj->step = 0;
                break;
            }
            rnd = lbl_804EE988 * 0x343FD + 0x269EC3;
            lbl_804EE988 = rnd & 0x7FFFFFFF;
            r = (rnd >> 16) & 1;
            if (r == obj->unkE4) {
                if (++obj->unkE5 == 3) {
                    while (r == obj->unkE4) {
                        rnd = lbl_804EE988 * 0x343FD;
                        rnd += 0x269EC3;
                        lbl_804EE988 = rnd & 0x7FFFFFFF;
                        r = (rnd >> 16) & 1;
                    }
                    obj->unkE5 = 0;
                }
            } else {
                obj->unkE5 = 0;
            }
            obj->unkE4 = r;
            if (r != 0) {
                obj->state = 2;
                obj->step = 0;
            }
        } else if (blocked) {
            fn_800E947C(obj, 1, 1, 0);
            obj->unk6C = -0x300;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
