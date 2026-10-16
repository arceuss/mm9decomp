#include "types.h"

typedef struct Unk800E8E34Obj {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ struct Unk800E8E34Obj* next;
    /* 0x08 */ u8 pad8[0xA - 0x8];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x18 - 0xC];
    /* 0x18 */ void (*func)(struct Unk800E8E34Obj* obj);
    /* 0x1C */ u8 pad1C[0x20 - 0x1C];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 pad21[0x30 - 0x21];
    /* 0x30 */ u16 unk30;
    /* 0x32 */ u16 unk32;
    /* 0x34 */ u8 pad34[0x3C - 0x34];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u8 pad40[0x60 - 0x40];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ u8 pad64[0x88 - 0x64];
    /* 0x88 */ u8 unk88[1];
} Unk800E8E34Obj;

typedef struct Unk800E8E34List {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ Unk800E8E34Obj* iter;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ Unk800E8E34Obj head;
} Unk800E8E34List;

void fn_800E8BD0(Unk800E8E34List* list);
void fn_80099DA4(void* sprite, s32 arg1, s32 arg2);
void fn_80099C74(void* sprite, s32 arg1);
void fn_80099B18(void* sprite, s32 arg1);
void fn_800999FC(void* sprite);

void fn_800E8E34(Unk800E8E34List* list) {
    Unk800E8E34Obj* obj;
    void* sprite;

    fn_800E8BD0(list);
    while ((obj = list->iter = list->iter->next) != &list->head) {
        if (obj->flagsA & 4) {
            sprite = obj->unk88;
            if (obj->flagsB & 0x80) {
                if (obj->flagsA & 2) {
                    fn_80099DA4(sprite, 6, (obj->flagsA >> 4) & 3);
                } else {
                    fn_80099C74(sprite, 6);
                }
            } else {
                if (obj->flagsA & 2) {
                    fn_80099B18(sprite, (obj->flagsA >> 4) & 3);
                } else {
                    fn_800999FC(sprite);
                }
            }
        }
    }
}
