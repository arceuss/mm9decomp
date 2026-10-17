#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk8005B37C {
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
    /* 0x34 */ struct Unk8005B37C* parent;
    /* 0x38 */ struct Unk8005B37C* child;
    /* 0x3C */ u8 pad3C[0x60 - 0x3C];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Unk8005B37C;


typedef struct Unk8005B37CNode {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ struct Unk8005B37CNode* next;
    /* 0x08 */ u8 pad8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 padA[0x14 - 0xA];
    /* 0x14 */ u8 unk14;
} Unk8005B37CNode;

typedef struct Unk8005B37CList {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ Unk8005B37CNode* iter;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ Unk8005B37CNode head;
} Unk8005B37CList;

extern Unk8005B37CList* lbl_804EE738;

void fn_800E8BD0(Unk8005B37CList* list);
Unk8005B37C* fn_800E8C44(Unk8005B37CList* list);
void fn_80042DA0(Unk8005B37C* obj, s32 kind);

extern s32 lbl_804EE988;
extern u8 lbl_80266D80[];

static inline s32 Rand(void) {
    lbl_804EE988 = (lbl_804EE988 * 0x343FD + 0x269EC3) & 0x7FFFFFFF;
    return lbl_804EE988 >> 16;
}

void fn_8005B37C(Unk8005B37C* obj) {
    u8 count;
    Unk8005B37CNode* saved;
    Unk8005B37CNode* node;
    Unk8005B37C* child;

    switch (obj->step) {
    case 0:
        obj->unk16 = lbl_80266D80[Rand() & 0xF];
        obj->step++;
    case 1:
        if (obj->unk16 == 0) {
        if (obj->child == NULL) {
            count = 0;
            saved = lbl_804EE738->iter;
            fn_800E8BD0(lbl_804EE738);
            while ((node = lbl_804EE738->iter = lbl_804EE738->iter->next) != &lbl_804EE738->head) {
                if (node->unk9 == 0x19 && node->unk14 == 1) {
                    count++;
                }
            }
            lbl_804EE738->iter = saved;
            if (count < 3) {
                child = fn_800E8C44(lbl_804EE738);
                if (child != NULL) {
                    fn_80042DA0(child, 0x19);
                    child->unk60 = obj->unk60;
                    child->unk64 = obj->unk64;
                    child->unk14 = 1;
                }
                obj->child = child;
            }
        } else if (obj->child != NULL && obj->child->unk10 >= 2) {
            obj->child = NULL;
            obj->step = 0;
        }
        } else {
            obj->unk16--;
        }
        break;
    }
}
