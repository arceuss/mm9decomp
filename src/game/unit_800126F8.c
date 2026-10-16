#include "types.h"

typedef struct Unk802638A0Entry {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk802638A0Entry;

typedef struct Unk800126F8Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800126F8Pos;

typedef struct Unk800126F8 {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s8 unk8;
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x16 - 0x14];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 count;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x60 - 0x1C];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x6C - 0x68];
    /* 0x6C */ s32 vy;
} Unk800126F8;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[0x38 - 0x4];
} Unk803051D8;

extern Unk802638A0Entry* lbl_802638A0[];
extern s32 lbl_80262358[];
extern s32 lbl_8026236C[];
extern Unk803051D8 lbl_803051D8;

void fn_800E9244(Unk800126F8* obj);
void fn_80040AD0(s32 arg0, Unk800126F8Pos* pos, s32 arg2, s32 arg3);
void fn_800D5234(s32 se);
void fn_800E9AA0(Unk800126F8* obj, s32 arg1, s32 arg2);
void fn_800E9C90(Unk800126F8* obj);
void fn_800C7C24(s32 arg0, u8 kind, s32 arg2);

static inline void Boom(Unk800126F8* obj, Unk800126F8Pos* pos) {
    obj->y += obj->vy;
    if (obj->timer == 0) {
        pos->x = obj->x + -(((obj->flagsA >> 3) & 2) - 1) * lbl_80262358[obj->count];
        pos->y = obj->y + lbl_8026236C[obj->count];
        fn_80040AD0(3, pos, 0, 0);
        fn_800D5234(0x13);
        obj->timer = 0x10;
        obj->count++;
    } else {
        obj->timer--;
    }
}

void fn_800126F8(Unk800126F8* obj) {
    Unk800126F8Pos pos;

    switch (obj->step) {
    case 0:
        fn_800E9244(obj);
        obj->vy = 0x40;
        obj->timer = 0;
        obj->count = 0;
        obj->step++;
    case 1:
        Boom(obj, &pos);
        if (obj->count == 2) {
            obj->step++;
        }
        break;
    case 2:
        fn_800E9AA0(obj, 2, 0);
        obj->step++;
    case 3:
        fn_800E9C90(obj);
        Boom(obj, &pos);
        if (obj->count == 5) {
            obj->step++;
        }
        break;
    case 4:
        obj->flagsA &= ~1;
        lbl_803051D8.unk3 &= ~8;
        fn_800C7C24(obj->unk8, obj->kind, 0);
        obj->unk18 = lbl_802638A0[obj->kind]->unk10;
        obj->unk10 = 4;
        obj->state = 0;
        obj->step = 0;
        obj->unk13 = 0;
        break;
    }
}
