#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800218F8 {
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
    /* 0x34 */ struct Unk800218F8* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk800218F8;


typedef struct Unk800218F8Node {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ struct Unk800218F8Node* next;
    /* 0x08 */ u8 pad8;
    /* 0x09 */ u8 unk9;
} Unk800218F8Node;

typedef struct Unk800218F8List {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ Unk800218F8Node* iter;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ Unk800218F8Node head;
} Unk800218F8List;

extern Unk800218F8List* lbl_804EE738;

void fn_800E946C(Unk800218F8* obj, u8 id);
void fn_8006A46C(Unk800218F8* obj, s32 x, s32 y, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void fn_800E8BD0(Unk800218F8List* list);
void fn_800E9750(Unk800218F8* obj, u16 arg1);

void fn_800218F8(Unk800218F8* obj) {
    u8 count;
    Unk800218F8Node* saved;
    Unk800218F8Node* node;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 1);
        fn_8006A46C(obj, obj->unk60, obj->unk64 + 0x1000, 5, 0, 0, 0);
        obj->unk16 = 90;
        obj->step++;
    case 1:
        if (obj->unk16 == 0) {
            count = 0;
            saved = lbl_804EE738->iter;
            fn_800E8BD0(lbl_804EE738);
            while ((node = lbl_804EE738->iter = lbl_804EE738->iter->next) != &lbl_804EE738->head) {
                if (node->unk9 == 0x28) {
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
