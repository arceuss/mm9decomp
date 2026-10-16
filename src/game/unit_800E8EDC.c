#include "types.h"

typedef struct Unk800E8EDCObj {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ struct Unk800E8EDCObj* next;
    /* 0x08 */ u8 pad8[0xA - 0x8];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x18 - 0xC];
    /* 0x18 */ void (*func)(struct Unk800E8EDCObj* obj);
    /* 0x1C */ u8 pad1C[0x20 - 0x1C];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 pad22[0x30 - 0x22];
    /* 0x30 */ u16 unk30;
    /* 0x32 */ u16 unk32;
    /* 0x34 */ u8 pad34[0x3C - 0x34];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u8 pad40[0x60 - 0x40];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ u8 pad64[0x88 - 0x64];
    /* 0x88 */ u8* unk88;
    /* 0x8C */ u8 pad8C[0xA0 - 0x8C];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u32 unkA4;
    /* 0xA8 */ u8 unkA8;
} Unk800E8EDCObj;

typedef struct Unk800E8EDCList {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ Unk800E8EDCObj* iter;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ Unk800E8EDCObj head;
} Unk800E8EDCList;

extern u32 lbl_8043CD08[];
extern u8 lbl_804EE980;
extern u8 lbl_804EE981;

void fn_800E8BD0(Unk800E8EDCList* list);

void fn_800E8EDC(Unk800E8EDCList* list) {
    Unk800E8EDCObj* obj;

    fn_800E8BD0(list);
    while ((obj = list->iter = list->iter->next) != &list->head) {
        if (!(obj->flagsA & 4)) {
            continue;
        }
        if (!(obj->flagsB & 0x20)) {
            continue;
        }
        if ((obj->unkA8 & 2) || (obj->unkA0 & 0x10000001) || (obj->unkA4 & 0x10000001)) {
            lbl_8043CD08[obj->unk21 >> 5] |= 1 << (obj->unk21 & 31);
        }
        if (lbl_804EE981 == 0 && (obj->unkA0 & 0x10000001) && obj->unk88[1] != 0) {
            lbl_804EE980 = 1;
        }
    }
}
