#include "types.h"

typedef struct Unk8008D0B0 {
    /* 0x0000 */ u8 pad0[0x2];
    /* 0x0002 */ u8 mode;
    /* 0x0003 */ u8 step;
    /* 0x0004 */ s16 unk4;
    /* 0x0006 */ u8 pad6[0x8 - 0x6];
    /* 0x0008 */ s16 unk8;
    /* 0x000A */ u8 padA[0xFF4 - 0xA];
    /* 0x0FF4 */ u8 unkFF4;
    /* 0x0FF5 */ u8 cursor;
    /* 0x0FF6 */ u8 padFF6;
    /* 0x0FF7 */ u8 unkFF7;
    /* 0x0FF8 */ u8 padFF8[0xFFC - 0xFF8];
    /* 0x0FFC */ u8 next[8];
} Unk8008D0B0;

extern u8 lbl_80316D78[];

u32 fn_800BB6C8(u32 a);
void fn_800BB7B8(s32 a);
void fn_800BB4E8(s32 a, s32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void fn_800D7CC8(Unk8008D0B0* obj, s32 arg1, s32 arg2);
void fn_8008FB90(Unk8008D0B0* obj);

void fn_8008D0B0(Unk8008D0B0* obj) {
    u32 R;
    u32 a;
    u32 b;

    switch (obj->step) {
    case 0:
        fn_800BB7B8(1);
        if (obj->unkFF4 == 0 || obj->unk8 != 0) {
            R = *(u32*)(lbl_80316D78 + 0x3004) + 0xCD5000;
            a = *(u32*)(R + 0x14) >> 1;
            b = *(u32*)(R + 0x18) >> 1;
            fn_800BB4E8(0, 0, R + a + *(u32*)(R + a), R + b + *(u32*)(R + b), 0x20, 0, R + b, R + a);
        }
        obj->unkFF7 = 1;
        obj->unk4 = 0;
        obj->step++;
    case 1:
        if (obj->unkFF4 != 0 && obj->unk8 == 0) {
            if (obj->unk4 == 0) {
                fn_800D7CC8(obj, 0, 0);
                obj->unk4 = 1;
                obj->unk8 = 1;
            }
            fn_8008FB90(obj);
        } else if ((u8)fn_800BB6C8(0) == 3) {
            if (obj->unk4 == 0) {
                fn_800D7CC8(obj, 0, 0);
                obj->unk4 = 1;
            }
            fn_8008FB90(obj);
        }
        break;
    case 2:
        fn_800BB7B8(0);
        if ((u8)(obj->cursor + 0xFE) <= 1) {
            R = *(u32*)(lbl_80316D78 + 0x3004) + 0xCD5000;
            a = *(u32*)(R + 0x14) >> 1;
            b = *(u32*)(R + 0x18) >> 1;
            fn_800BB4E8(1, 1, R + a + *(u32*)(R + a), R + b + *(u32*)(R + b), 0x20, 0, R + b, R + a);
        }
        obj->unkFF7 = 0;
        obj->step++;
    case 3:
        if ((u8)(obj->cursor + 0xFE) <= 1) {
            if ((u8)fn_800BB6C8(1) == 3) {
                obj->mode = obj->next[obj->cursor];
                obj->step = 0;
            }
        } else {
            obj->mode = obj->next[obj->cursor];
            obj->step = 0;
        }
        break;
    }
}
