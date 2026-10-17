#include "types.h"

typedef struct UnkADFCCPos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} UnkADFCCPos;

typedef struct UnkADFCCBox {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ u16 unk4;
} UnkADFCCBox;

typedef struct UnkADFCC {
    /* 0x000 */ u8 pad000[0x9];
    /* 0x009 */ u8 unk009;
    /* 0x00A */ u8 unk00A;
    /* 0x00B */ u8 pad00B[0x11 - 0xB];
    /* 0x011 */ u8 unk011;
    /* 0x012 */ u8 unk012;
    /* 0x013 */ u8 unk013;
    /* 0x014 */ u8 pad014[0x60 - 0x14];
    /* 0x060 */ UnkADFCCPos pos;
    /* 0x068 */ s32 vx;
    /* 0x06C */ s32 vy;
    /* 0x070 */ u8 pad070[0xC8 - 0x70];
    /* 0x0C8 */ u8 unk0C8[0xEC - 0xC8];
    /* 0x0EC */ u8 unk0EC;
    /* 0x0ED */ u8 unk0ED;
    /* 0x0EE */ u8 unk0EE;
    /* 0x0EF */ u8 unk0EF;
    /* 0x0F0 */ u8 unk0F0;
    /* 0x0F1 */ u8 unk0F1;
    /* 0x0F2 */ u8 unk0F2;
    /* 0x0F3 */ u8 unk0F3;
    /* 0x0F4 */ u8 unk0F4;
    /* 0x0F5 */ u8 unk0F5;
    /* 0x0F6 */ u8 pad0F6[0xFC - 0xF6];
    /* 0x0FC */ u8 unk0FC;
    /* 0x0FD */ u8 pad0FD[0x104 - 0xFD];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 unk108;
    /* 0x109 */ u8 unk109;
    /* 0x10A */ u8 pad10A[0x19C - 0x10A];
    /* 0x19C */ UnkADFCCBox* unk19C;
} UnkADFCC;

typedef struct Unk8027EB60 {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u8 pad4[0x1C - 0x4];
    /* 0x1C */ u32 unk1C;
} Unk8027EB60;

extern Unk8027EB60* lbl_8027EB60[];

u8 fn_800B7844(UnkADFCC* obj);
void fn_80040AD0(s32 arg0, UnkADFCCPos* pos, u8 arg2, s32 arg3);
void fn_800B9F74(UnkADFCC* obj, u32 anim);
UnkADFCCBox* fn_800B79D4(UnkADFCC* obj, u32 arg, s32 zero);
s32 fn_800B9094(UnkADFCCPos* pos, void* vel, UnkADFCCBox** box, UnkADFCCBox* k, u32 dir);
s32 fn_800B911C(UnkADFCCPos* pos, void* vel, UnkADFCCBox** box, UnkADFCCBox* k, UnkADFCCBox* cur, u32 dir);
void fn_800B4938(UnkADFCC* obj, s32 arg1, s32 arg2);
s32 fn_800B490C(UnkADFCC* obj);

static inline void Shift(UnkADFCC* obj, u8 v) {
    obj->unk0EC = obj->unk011;
    obj->unk011 = v;
    obj->unk0ED = obj->unk012;
    obj->unk012 = 0;
    obj->unk0EE = obj->unk013;
    obj->unk013 = 0;
    obj->unk0F2 = obj->unk0EF;
    obj->unk0EF = 0;
    obj->unk0F3 = obj->unk0F0;
    obj->unk0F0 = 0;
    obj->unk0F4 = obj->unk0F1;
    obj->unk0F1 = 0;
    obj->unk0F5 = v;
}

void fn_800ADFCC(UnkADFCC* obj) {
    UnkADFCCBox** box;
    s32 t;
    u8 r;
    UnkADFCCPos p;
    s32 w;
    s32 v;

    obj->unk104 = (obj->unk104 & ~2) | 1;
    switch (obj->unk012) {
    case 0:
        obj->vy = 0;
        r = fn_800B7844(obj);
        obj->unk109 = r;
        fn_80040AD0(0, &obj->pos, r, 0);
        obj->unk0FC = 7;
        fn_800B9F74(obj, lbl_8027EB60[obj->unk009]->unk1C);
        obj->unk108 = 0x19;
        obj->unk0ED = obj->unk012;
        obj->unk012 = 1;
        obj->unk0EE = obj->unk013;
        obj->unk013 = 0;
    case 1:
        box = &obj->unk19C;
        if (fn_800B9094(&obj->pos, obj->unk0C8, box, fn_800B79D4(obj, lbl_8027EB60[obj->unk009]->unk1C, 0), (obj->unk00A >> 4) & 1)) {
            if ((t = obj->unk108 - 1) > 0) {
                obj->unk108 = t;
            }
            fn_800B4938(obj, 0x280, 5);
        } else {
            obj->vx = 0;
        }
        fn_800B7844(obj);
        if (obj->vx == 0) {
            t = 0;
        }
        if (((obj->unk00A >> 4) & 1) != obj->unk109) {
            t = 0;
            obj->unk109 = (obj->unk00A & 0x10) != 0;
        }
        if (t <= 0) {
            p = obj->pos;
            v = fn_800B911C(&p, obj->unk0C8, box, fn_800B79D4(obj, lbl_8027EB60[obj->unk009]->unk0, 0), *box, (obj->unk00A >> 4) & 1);
            if (v != 0) {
                w = (*box)->unk4 - (*box)->unk0;
                w -= 1;
                w -= fn_800B79D4(obj, lbl_8027EB60[obj->unk009]->unk0, 0)->unk0;
                w *= ((obj->unk00A >> 3) & 2) - 1;
                p.x += w;
                v = fn_800B911C(&p, obj->unk0C8, box, fn_800B79D4(obj, lbl_8027EB60[obj->unk009]->unk0, 0), *box, (obj->unk00A >> 4) & 1);
            }
            if (v == 0) {
                obj->pos = p;
                obj->vx = (obj->vx != 0 ? ((obj->vx >> 31) * 2 + 1) : 0) * 0x160;
                if (fn_800B490C(obj)) {
                    Shift(obj, 1);
                } else {
                    Shift(obj, 0);
                }
            }
        }
        break;
    }
}
