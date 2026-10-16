#include "types.h"

typedef struct Unk800E867C {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u32 unk10_0 : 30;
    /* 0x10 */ u32 unk10_30 : 2;
    /* 0x14 */ u32 unk14_0 : 20;
    /* 0x14 */ u32 unk14_20 : 2;
    /* 0x14 */ u32 unk14_22 : 1;
    /* 0x14 */ u32 unk14_23 : 3;
    /* 0x14 */ u32 unk14_26 : 6;
    /* 0x18 */ u8 unk18;
} Unk800E867C;

void fn_800E7960(Unk800E867C* node, void (*func)(Unk800E867C* node, void* ctx));
void fn_800E8700(Unk800E867C* node, void* ctx);

void fn_800E867C(Unk800E867C* node, s32 arg1, s32 arg2) {
    fn_800E7960(node, fn_800E8700);
    node->unk8 = arg1;
    node->unkC = arg2;
    node->unk10_0 = 0;
    node->unk10_30 = 2;
    node->unk14_20 = 0;
    node->unk14_22 = 1;
    node->unk14_23 = 0;
    node->unk18 = 0;
}
