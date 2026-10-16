#include "types.h"
#include "game/sound.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk80021710 {
    /* 0x00 */ struct Unk80021710* prev;
    /* 0x04 */ struct Unk80021710* next;
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
    /* 0x34 */ struct Unk80021710* parent;
    /* 0x38 */ struct Unk80021710* unk38;
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
} Unk80021710;

typedef struct Unk80021710List {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ Unk80021710* iter;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ Unk80021710 head;
} Unk80021710List;

extern Unk80280390Entry* lbl_802638A0[];
extern void (*lbl_80261EA0[])(Unk80021710* obj);
extern Unk80021710List* lbl_804EE738;

void fn_800E9750(Unk80021710* obj, u16 arg1);
void fn_800E8BD0(Unk80021710List* list);

void* fn_8006A46C(Unk80021710* obj, s32 x, s32 y, s32 kind, s32 arg4, s32 arg5, s32 arg6);
void fn_800E946C(Unk80021710* obj, u8 id);
void fn_800D5234(s32 id);

void fn_80021710(Unk80021710* obj) {
    u8 count;
    Unk80021710* saved;
    Unk80021710* it;
    s32 x;
    s32 y;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 1);
        obj->unk16 = 0;
        obj->unk17 = 0;
        obj->unk38 = NULL;
        obj->step++;
    case 1:
        if (obj->unk16 == 0) {
            if (obj->unk17 == 3) {
                obj->step++;
                break;
            }
            y = obj->unk64 + 0x1000;
            x = obj->unk60;
            if (obj->unk17 == 0) {
                obj->unk38 = fn_8006A46C(obj, x, y, 4, 0, obj->unk17, 0);
            } else {
                fn_8006A46C(obj, x, y, 4, 0, obj->unk17, 0);
            }
            fn_8006A46C(obj, x, y, 4, 1, 0, 0);
            fn_800D5234(SE_EM_UFOSHOT);
            obj->unk16 = 10;
            obj->unk17++;
        } else {
            obj->unk16--;
        }
        break;
    case 2:
        obj->unk16 = 0x3C;
        obj->step++;
    case 3:
        if (obj->unk16 == 0) {
            count = 0;
            saved = lbl_804EE738->iter;
            fn_800E8BD0(lbl_804EE738);
            while ((it = lbl_804EE738->iter = lbl_804EE738->iter->next) != &lbl_804EE738->head) {
                if (it->unk9 == 0x28) {
                    count++;
                }
            }
            lbl_804EE738->iter = saved;
            if (count == 0) {
                obj->state = 6;
                obj->step = 0;
            }
        } else {
            obj->unk16--;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
