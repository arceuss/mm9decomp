#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk8001EBD4 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x20 - 0x1C];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 pad22[0x2A - 0x22];
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 pad2D;
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ u8 pad30[0x34 - 0x30];
    /* 0x34 */ struct Unk8001EBD4* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x7C - 0x68];
    /* 0x7C */ u8 unk7C;
    /* 0x7D */ u8 pad7D[0x7F - 0x7D];
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[0x84 - 0x80];
    /* 0x84 */ s32 unk84;
    /* 0x88 */ u8 pad88[0xAC - 0x88];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xD8 - 0xCD];
    /* 0xD8 */ struct Unk8001EBD4* unkD8;
    /* 0xDC */ struct Unk8001EBD4* unkDC;
    /* 0xE0 */ struct Unk8001EBD4* unkE0;
    /* 0xE4 */ struct Unk8001EBD4* unkE4;
    /* 0xE8 */ u8 unkE8;
    /* 0xE9 */ u8 unkE9;
    /* 0xEA */ u8 unkEA;
    /* 0xEB */ u8 unkEB;
    /* 0xEC */ u8 unkEC;
} Unk8001EBD4;

extern u32 lbl_804EE988;

void fn_800E946C(Unk8001EBD4* obj, u8 id);
void fn_800E9750(Unk8001EBD4* obj, u16 arg1);

void fn_8001EBD4(Unk8001EBD4* obj) {
    Unk8001EBD4* a = obj->unkD8;
    Unk8001EBD4* b = obj->unkDC;
    Unk8001EBD4* c = obj->unkE0;
    Unk8001EBD4* d = obj->unkE4;
    u32 rnd;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 5);
        obj->unkE8 = 0;
        rnd = lbl_804EE988 * 0x343FD + 0x269EC3;
        lbl_804EE988 = rnd & 0x7FFFFFFF;
        obj->unkE9 = (rnd >> 16) & 1;
        if (obj->unkE9 == obj->unkEA) {
            if (++obj->unkEB == 3) {
                while (obj->unkE9 == obj->unkEA) {
                    rnd = lbl_804EE988 * 0x343FD + 0x269EC3;
                    lbl_804EE988 = rnd & 0x7FFFFFFF;
                    obj->unkE9 = (rnd >> 16) & 1;
                }
                obj->unkEB = 0;
            }
        } else {
            obj->unkEB = 0;
        }
        obj->unkEA = obj->unkE9;
        obj->step++;
    case 1:
        if (obj->unk7C == 5 && obj->unk7F == 4) {
            if (obj->unkEC <= 1) {
                fn_800E946C(obj, 0);
            } else {
                obj->unkEC--;
            }
        }
        if (a->unk10 >= 2 && b->unk10 >= 2 && c->unk10 >= 2 && d->unk10 >= 2) {
            obj->state = 1;
            obj->step = 0;
            obj->unk84 = 0x80;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
