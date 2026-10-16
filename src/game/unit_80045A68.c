#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk80045A68 {
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
    /* 0x34 */ struct Unk80045A68* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk80045A68;


typedef struct Unk80045A68Node {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ struct Unk80045A68Node* next;
    /* 0x08 */ u8 pad8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 padA[0x14 - 0xA];
    /* 0x14 */ u8 unk14;
} Unk80045A68Node;

typedef struct Unk80045A68List {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ Unk80045A68Node* iter;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ Unk80045A68Node head;
} Unk80045A68List;

extern Unk80045A68List* lbl_804EE738;

void fn_800E8BD0(Unk80045A68List* list);
Unk80045A68* fn_800E8C44(Unk80045A68List* list);
void fn_80042DA0(Unk80045A68* obj, s32 kind);

void fn_80045A68(Unk80045A68* obj) {
    u8 count;
    Unk80045A68Node* saved;
    Unk80045A68Node* node;
    u8 v;
    Unk80045A68* child;

    switch (obj->step) {
    case 0:
        obj->unk16 = 120;
        obj->step++;
    case 1:
        if (--obj->unk16 == 0) {
            count = 0;
            saved = lbl_804EE738->iter;
            fn_800E8BD0(lbl_804EE738);
            while ((node = lbl_804EE738->iter = lbl_804EE738->iter->next) != &lbl_804EE738->head) {
                if (node->unk9 == 3 && node->unk14 == 1) {
                    count++;
                }
            }
            lbl_804EE738->iter = saved;
            if (count < 3) {
                v = obj->unk15;
                child = fn_800E8C44(lbl_804EE738);
                if (child != NULL) {
                    fn_80042DA0(child, 3);
                    child->unk60 = obj->unk60;
                    child->unk64 = obj->unk64;
                    child->unk14 = 1;
                    child->unk15 = v;
                }
            }
            obj->step = 0;
        }
        break;
    }
}
