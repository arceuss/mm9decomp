#include "types.h"

typedef struct Unk8008C840 {
    /* 0x0000 */ u8 pad0[0xFF4];
    /* 0x0FF4 */ u8 unkFF4;
    /* 0x0FF5 */ u8 padFF5[0xFFB - 0xFF5];
    /* 0x0FFB */ u8 unkFFB;
    /* 0x0FFC */ u8 padFFC[0x1006 - 0xFFC];
    /* 0x1006 */ u16 unk1006;
    /* 0x1008 */ u8 pad1008[0x215A - 0x1008];
    /* 0x215A */ u8 unk215A;
    /* 0x215B */ u8 pad215B[0x21E0 - 0x215B];
    /* 0x21E0 */ u8 unk21E0[0x2220 - 0x21E0];
    /* 0x2220 */ u32 weapons;
    /* 0x2224 */ u8 pad2224[0x227C - 0x2224];
    /* 0x227C */ u8 unk227C;
    /* 0x227D */ u8 pad227D[0x2298 - 0x227D];
} Unk8008C840;

extern Unk8008C840 lbl_803140C0;

void fn_800BB7B8(u32 id);
void fn_800D56A4(u16 id);
void fn_8008C07C(Unk8008C840* obj, s32 next);
void fn_800B5AC0(void* a);
void fn_800E65FC(void);
void fn_800E666C(void);

#define BIT(w, n) (((w) >> (n)) & 1)
#define HAS(w, n) (((w) & (1 << (n))) != 0)

void fn_8008C840(Unk8008C840* obj) {
    u32 w;
    u32 b1;
    u32 b2;
    u32 b3;
    u32 b4;
    u32 b5;
    u32 b6;
    u32 b7;
    u32 b8;

    fn_800BB7B8(0);
    fn_800BB7B8(1);
    fn_800BB7B8(2);
    fn_800BB7B8(3);
    switch (obj->unkFFB) {
    case 0:
        fn_800D56A4(obj->unk1006);
        if (obj->unkFF4 == 1 && obj->unk227C != 1) {
            w = obj->weapons;
            b1 = w & 0x2;
            b2 = w & 0x4;
            b3 = w & 0x8;
            b4 = w & 0x10;
            b5 = w & 0x20;
            b6 = w & 0x40;
            b7 = w & 0x80;
            b8 = w & 0x100;
            if ((BIT(w, 1) + BIT(w, 2) + BIT(w, 3) + BIT(w, 4) + BIT(w, 5) + BIT(w, 6) + BIT(w, 7) + BIT(w, 8)) == 1 && !(obj->unk215A & 1)) {
                obj->unk215A |= 1;
                fn_8008C07C(&lbl_803140C0, 7);
                break;
            }
            if (((b1 != 0) + (b2 != 0) + (b3 != 0) + (b4 != 0) + (b5 != 0) + (b6 != 0) + (b7 != 0) + (b8 != 0)) == 4 && !(obj->unk215A & 2)) {
                obj->unk215A |= 2;
                fn_8008C07C(&lbl_803140C0, 0x107);
                break;
            }
            if (((b1 != 0) + (b2 != 0) + (b3 != 0) + (b4 != 0) + (b5 != 0) + (b6 != 0) + (b7 != 0) + (b8 != 0)) == 5 && !(obj->unk215A & 4)) {
                obj->unk215A |= 4;
                fn_8008C07C(&lbl_803140C0, 0x207);
                break;
            }
            if (((b1 != 0) + (b2 != 0) + (b3 != 0) + (b4 != 0) + (b5 != 0) + (b6 != 0) + (b7 != 0) + (b8 != 0)) == 8 && !(obj->unk215A & 8)) {
                obj->unk215A |= 8;
                fn_8008C07C(&lbl_803140C0, 0x307);
                break;
            }
        }
        fn_8008C07C(obj, 2);
        break;
    case 1:
        fn_800D56A4(obj->unk1006);
        fn_800B5AC0(obj->unk21E0);
        fn_8008C07C(obj, 0x700);
        break;
    case 2:
        fn_800D56A4(obj->unk1006);
        fn_800E65FC();
        fn_800E666C();
        break;
    case 3:
        fn_800D56A4(obj->unk1006);
        fn_8008C07C(&lbl_803140C0, 0x100);
        break;
    case 4:
        fn_8008C07C(obj, 0x208);
        fn_800E65FC();
        fn_800E666C();
        break;
    }
}
