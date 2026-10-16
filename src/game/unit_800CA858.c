#include "types.h"

typedef struct Unk800CA858 {
    /* 0x00 */ u8 pad0[0x12];
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0xAC - 0x15];
    /* 0xAC */ void (*unkAC)(void*);
} Unk800CA858;

extern u8 lbl_8027F750[];

void fn_800E91F0(Unk800CA858* obj, void* data, s32 arg2);
void fn_800CA614(void*);

void fn_800CA858(Unk800CA858* obj) {
    u8* p;
    u8* t = lbl_8027F750;

    if (obj->unk12 == 0) {
        if (obj->unk14 & 3) {
            if (obj->unk14 & 0x10) {
                p = t + 0x50;
            } else {
                p = t + 0x20;
            }
        } else {
            p = t + 0x38;
            if (obj->unk14 & 0x10) {
                p = t + 0x68;
            }
        }
        fn_800E91F0(obj, p, 0);
        obj->unkAC = fn_800CA614;
        obj->unk12++;
    }
}
