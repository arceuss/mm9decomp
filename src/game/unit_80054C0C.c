#include "types.h"
#include "game/obj.h"

typedef struct Unk80054C0C {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[5];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 pad11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x34 - 0x15];
    /* 0x34 */ struct Unk80054C0C* unk34;
    /* 0x38 */ struct Unk80054C0C* unk38;
} Unk80054C0C;

void fn_80042CF8(Obj*, s32);

void fn_80054C0C(Unk80054C0C* obj) {
    Unk80054C0C* a;
    Unk80054C0C* b;

    switch (obj->unk12) {
    case 0:
        fn_800E9244((Obj*)obj);
        obj->unk0A &= ~1;
        obj->unk12++;
    case 1:
        if (obj->unk14 == 2) {
            a = obj->unk34;
            b = obj->unk38;
            if (a != NULL && a->unk10 >= 2) {
                goto hit;
            }
            if (b != NULL && b->unk10 >= 2) {
                goto hit;
            }
        } else if (obj->unk14 != 1) {
            goto hit;
        } else if (obj->unk38 != NULL && obj->unk38->unk10 >= 2) {
            goto hit;
        }
        break;
    }
    return;
hit:
    fn_80042CF8((Obj*)obj, 4);
}
