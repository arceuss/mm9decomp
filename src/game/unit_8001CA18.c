#include "types.h"

typedef struct Vec2i8001CA18 {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i8001CA18;

typedef struct Unk8001CA18 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x12 - 0xB];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x54 - 0x17];
    /* 0x54 */ struct {
        u32 hi : 21;
        u32 flip : 1;
        u32 low : 10;
    } bits54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0x74 - 0x70];
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0x7C - 0x78];
    /* 0x7C */ u8 unk7C;
    /* 0x7D */ u8 pad7D[0x88 - 0x7D];
    /* 0x88 */ u8 unk88[4];
} Unk8001CA18;

extern Unk8001CA18* lbl_804EE984;
extern void* lbl_80262E98[];

void fn_800E946C(Unk8001CA18* obj, u8 anim);
void fn_800E9750(Unk8001CA18* obj, u16 arg1);
void fn_800E9758(Unk8001CA18* obj);
void fn_800E947C(Unk8001CA18* obj, u8 id, s32 arg2, s32 arg3);
void fn_8009996C(void* dst, void* src);
void fn_80040AD0(s32 kind, Vec2i8001CA18* pos, s32 arg2, s32 arg3);
void fn_80080BFC(s32 kind, s32* pos);
s32 fn_800A3FAC(s32 x, s32 y);
s32 fn_800A3CD4(s32 x, s32 y);
s32 fn_800A36F8(s32 x, s32 y);
void fn_800D5234(s32 id);
void fn_8001DFD4(Unk8001CA18* obj);

void fn_8001CA18(Unk8001CA18* obj) {
    Vec2i8001CA18 v;
    s32 d;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 5);
        fn_8009996C(obj->unk88, lbl_80262E98[obj->unk7C]);
        d = lbl_804EE984->x - obj->x;
        obj->bits54.flip = (u32)(-d & ~d) >> 31;
        if (obj->bits54.flip) {
            obj->flagsA |= 0x10;
        } else {
            obj->flagsA &= 0xEF;
        }
        obj->unk16 = 0x10;
        obj->step++;
    case 1:
        fn_800E9758(obj);
        if (obj->unk16 == 0) {
            obj->step++;
        } else {
            obj->unk16--;
        }
        return;
    case 2:
        obj->unk68 = (((obj->flagsA >> 3) & 2) - 1) * 0x400;
        v.x = obj->x;
        v.y = obj->unk64;
        fn_80040AD0(0, &v, (obj->flagsA >> 4) & 1, 0);
        obj->step++;
    case 3:
        obj->x += obj->unk68;
        if (obj->unk68 < 0) {
            d = fn_800A3FAC(obj->x - 0xE00, obj->unk64);
        } else {
            d = fn_800A3CD4(obj->x + 0xE00, obj->unk64);
        }
        if (d == 0) {
            break;
        }
        fn_80080BFC(1, &obj->x);
        obj->x += d;
        obj->step++;
        break;
    case 4:
        fn_800D5234(0x57);
        obj->unk68 = -(((obj->flagsA >> 3) & 2) - 1) * 0x80;
        obj->unk6C = -0x500;
        obj->unk74 = 0x40;
        obj->unk16 = 0xA;
        obj->step++;
    case 5:
        obj->x += obj->unk68;
        obj->unk64 += obj->unk6C;
        obj->unk6C += obj->unk74;
        if (obj->unk6C > 0) {
            if (obj->unk7C != 3) {
                fn_800E947C(obj, 3, 0, 0);
                fn_8009996C(obj->unk88, lbl_80262E98[obj->unk7C]);
                obj->bits54.flip = !(obj->flagsA & 0x10);
                if (obj->bits54.flip) {
                    obj->flagsA |= 0x10;
                } else {
                    obj->flagsA &= 0xEF;
                }
            }
            d = fn_800A36F8(obj->x, obj->unk64);
            if (d != 0) {
                obj->unk64 += d;
                obj->step++;
            }
        }
        break;
    case 6:
        fn_800E946C(obj, 0);
        obj->unk16 = 0x10;
        obj->step++;
    case 7:
        if (obj->unk16 == 0) {
            fn_8001DFD4(obj);
        } else {
            obj->unk16--;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
