#include "types.h"

typedef struct Unk800865A0 {
    /* 0x0000 */ u8 pad0[0x2];
    /* 0x0002 */ u8 mode;
    /* 0x0003 */ u8 step;
    /* 0x0004 */ s16 timer;
    /* 0x0006 */ u8 pad6[0xFF4 - 0x6];
    /* 0x0FF4 */ u8 unkFF4;
    /* 0x0FF5 */ u8 unkFF5;
    /* 0x0FF6 */ u8 unkFF6;
    /* 0x0FF7 */ u8 padFF7[0x1001 - 0xFF7];
    /* 0x1001 */ u8 unk1001;
    /* 0x1002 */ u8 pad1002;
    /* 0x1003 */ u8 unk1003;
} Unk800865A0;

typedef struct Unk8038E738 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u16 unkA;
} Unk8038E738;

extern Unk8038E738 lbl_8038E738;

void fn_800DBCE0(Unk800865A0* obj, s32 a, s32 b);
u32 fn_800BB6C8(u32 id);
void fn_800E5910(s32 id);

void fn_800865A0(Unk800865A0* obj) {
    switch (obj->step) {
    case 0:
        fn_800DBCE0(obj, 1, 1);
        fn_800DBCE0(obj, 1, 2);
        fn_800DBCE0(obj, 1, 8);
        obj->unk1001 = 2;
        obj->unk1003 = 1;
        obj->unkFF4++;
        obj->step++;
    case 1:
        if (obj->unk1001 == 0) {
            obj->step++;
        }
        fn_800BB6C8(0);
        break;
    case 2:
        fn_800DBCE0(obj, 1, 0);
        obj->unkFF5 = 0;
        obj->timer = 0;
        obj->unkFF4++;
        obj->step++;
    case 3:
        if (obj->unkFF5 == 1 && ++obj->timer == 0x1E) {
            obj->step++;
        }
        fn_800BB6C8(0);
        break;
    case 4:
        fn_800E5910(0xC03);
        obj->unkFF4++;
        obj->step++;
    case 5:
        if (lbl_8038E738.unkA == 0) {
            obj->step++;
        }
        fn_800BB6C8(0);
        break;
    case 6:
        fn_800E5910(0xC04);
        obj->unkFF4++;
        obj->step++;
    case 7:
        if (lbl_8038E738.unkA == 0) {
            obj->step++;
        }
        fn_800BB6C8(0);
        break;
    case 8:
        fn_800E5910(0xC05);
        obj->unkFF4++;
        obj->step++;
    case 9:
        if (lbl_8038E738.unkA == 0) {
            obj->timer = 0;
            obj->step++;
        }
        fn_800BB6C8(0);
        break;
    case 10:
        if (++obj->timer != 0x3C) {
            fn_800BB6C8(0);
            break;
        }
        obj->unk1001 = 4;
        obj->unk1003 = 1;
        obj->unkFF4++;
        obj->step++;
    case 11:
        if (obj->unk1001 == 0) {
            obj->unkFF4 = 0xFF;
            obj->unkFF6 = 0;
            obj->mode = 2;
            obj->step = 0;
        }
        fn_800BB6C8(0);
        break;
    }
}
