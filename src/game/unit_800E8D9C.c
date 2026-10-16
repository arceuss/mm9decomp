#include "types.h"

typedef struct Unk800E8D9CObj {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ struct Unk800E8D9CObj* next;
    /* 0x08 */ u8 pad8[0xB - 0x8];
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x18 - 0xC];
    /* 0x18 */ void (*func)(struct Unk800E8D9CObj* obj);
    /* 0x1C */ u8 pad1C[0x20 - 0x1C];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 pad21[0x30 - 0x21];
    /* 0x30 */ u16 unk30;
    /* 0x32 */ u16 unk32;
    /* 0x34 */ u8 pad34[0x3C - 0x34];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u8 pad40[0x60 - 0x40];
    /* 0x60 */ s32 unk60;
} Unk800E8D9CObj;

typedef struct Unk800E8D9CList {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ Unk800E8D9CObj* iter;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ Unk800E8D9CObj head;
} Unk800E8D9CList;

void fn_800E8BD0(Unk800E8D9CList* list);
void fn_800A5148(u8 arg0, u16 arg1, s32* pos, s32 arg3);

void fn_800E8D9C(Unk800E8D9CList* list, u16 arg1) {
    Unk800E8D9CObj* obj;

    fn_800E8BD0(list);
    while ((obj = list->iter = list->iter->next) != &list->head) {
        obj->unk32 = arg1;
        obj->func(obj);
        if (obj->flagsB & 0x10) {
            fn_800A5148(obj->unk20, obj->unk30, &obj->unk60, obj->unk3C);
        }
    }
}
