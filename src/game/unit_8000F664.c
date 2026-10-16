#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk8000F664 {
    /* 0x00 */ struct Unk8000F664* prev;
    /* 0x04 */ struct Unk8000F664* next;
    /* 0x08 */ u8 pad8;
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
    /* 0x34 */ struct Unk8000F664* parent;
    /* 0x38 */ struct Unk8000F664* unk38;
    /* 0x3C */ u8 pad3C[0x60 - 0x3C];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0xAC - 0x78];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xB6 - 0xB0];
    /* 0xB6 */ s16 unkB6;
    /* 0xB8 */ s16 unkB8;
    /* 0xBA */ u8 padBA[0xC8 - 0xBA];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xD8 - 0xCD];
    /* 0xD8 */ u8 unkD8;
} Unk8000F664;

typedef struct Unk8000F664List {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ Unk8000F664* iter;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ Unk8000F664 head;
} Unk8000F664List;

extern Unk80280390Entry* lbl_802638A0[];
extern void (*lbl_80261EA0[])(Unk8000F664* obj);
extern Unk8000F664List* lbl_804EE738;

void fn_800E9750(Unk8000F664* obj, u16 arg1);
void fn_800E8BD0(Unk8000F664List* list);

void fn_8000F664(Unk8000F664* obj) {
    s32 i;
    u8 count;
    Unk8000F664* saved;
    Unk8000F664* it;

    obj->unkB6 = obj->unkB8 = obj->unk38->unkB6;
    if (obj->unkD8 == 3) {
        obj->unk18 = lbl_802638A0[obj->unk9]->unk8;
        obj->unk10 = 2;
        obj->unk13 = 0;
        obj->state = 0;
        obj->step = 0;
        lbl_80261EA0[obj->state](obj);
        return;
    }
    switch (obj->step) {
    case 0:
        obj->unk68 = 0;
        obj->unk70 = obj->unk64;
        obj->unk6C = 0;
        obj->unk74 = -2;
        for (i = 0; i < 0x62; i += 2) {
            obj->unk68 += i;
        }
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        obj->unk64 += obj->unk6C;
        obj->unk6C += obj->unk74;
        if (obj->unk6C < 0) {
            if (obj->unk6C < -0x60) {
                obj->unk6C = -0x60;
            }
        } else if (obj->unk6C > 0x60) {
            obj->unk6C = 0x60;
        }
        if (obj->unk74 < 0) {
            if (obj->unk64 <= obj->unk70 + obj->unk68 - 0x2801) {
                obj->unk74 = 2;
            } else {
                obj->unk74 = -2;
            }
        } else if (obj->unk64 >= obj->unk70 + 0x2801 - obj->unk68) {
            obj->unk74 = -2;
        } else {
            obj->unk74 = 2;
        }
        if (obj->unkD8 == 0) {
            count = 0;
            saved = lbl_804EE738->iter;
            fn_800E8BD0(lbl_804EE738);
            while ((it = lbl_804EE738->iter = lbl_804EE738->iter->next) != &lbl_804EE738->head) {
                if (it->unk9 == 0x1E && it->unk14 == 2) {
                    count++;
                }
            }
            lbl_804EE738->iter = saved;
            if (count == 0) {
                obj->unkD8 = 1;
            }
        }
        break;
    }
}
