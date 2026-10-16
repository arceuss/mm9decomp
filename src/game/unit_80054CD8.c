#include "types.h"

typedef struct Unk80054CD8Child {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u8 unk10;
} Unk80054CD8Child;

typedef struct Unk80054CD8 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x12 - 0xB];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x34 - 0x15];
    /* 0x34 */ Unk80054CD8Child* a;
    /* 0x38 */ Unk80054CD8Child* b;
    /* 0x3C */ u8 pad3C[0x60 - 0x3C];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
} Unk80054CD8;

typedef struct Unk80054CD8Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk80054CD8Pos;

void fn_800E9244(void);
void fn_80040AD0(s32 arg0, Unk80054CD8Pos* pos, s32 arg2, s32 arg3);
void fn_80042CF8(Unk80054CD8* obj, s32 mode);

void fn_80054CD8(Unk80054CD8* obj) {
    Unk80054CD8Pos pos;

    switch (obj->step) {
    case 0:
        fn_800E9244();
        obj->flagsA &= ~1;
        pos.x = obj->x;
        pos.y = obj->y;
        fn_80040AD0(2, &pos, 0, 0);
        obj->step++;
    case 1:
        if (obj->unk14 == 2) {
            Unk80054CD8Child* a = obj->a;
            Unk80054CD8Child* b = obj->b;

            if ((a == NULL || a->unk10 < 2) && (b == NULL || b->unk10 < 2)) {
                break;
            }
        } else if (obj->unk14 == 1) {
            if (obj->b == NULL || obj->b->unk10 < 2) {
                break;
            }
        }
        fn_80042CF8(obj, 4);
        break;
    }
}
