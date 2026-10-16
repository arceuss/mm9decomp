#include "types.h"
typedef struct Unk8006DC74Pair { /* 0x00 */ s32 unk0; /* 0x04 */ s32 unk4; } Unk8006DC74Pair;
typedef struct Unk8006DC74Obj {
    /* 0x00 */ u8 pad00[0x14];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x60 - 0x15];
    /* 0x60 */ Unk8006DC74Pair unk60;
    /* 0x68 */ u8 pad68[0xA0 - 0x68];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u8 padA4[0xC8 - 0xA4];
    /* 0xC8 */ Unk8006DC74Pair unkC8;
} Unk8006DC74Obj;
typedef struct Unk8006DC74 {
    /* 0x00 */ u8 pad00[0xC];
    /* 0x0C */ struct Unk8006DC74* unk0C;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u8 pad18[0x23 - 0x18];
    /* 0x23 */ u8 unk23a:4;
                 u8 unk23b:4;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ Unk8006DC74Obj* unk28;
} Unk8006DC74;
extern s32 lbl_80304B58[];
extern void fn_800B5ECC(Unk8006DC74Obj*, Unk8006DC74Pair*);
extern void fn_800B5F38(Unk8006DC74Obj*, s32);
void fn_8006DC74(Unk8006DC74* p) {
    Unk8006DC74Obj* a = p->unk28;
    Unk8006DC74Obj* b = p->unk0C->unk28;
    Unk8006DC74Pair v;
    if (p->unk14 & 1) {
        if (p->unk23b == 3) a->unkC8 = b->unk60;
        if (p->unk23b == 8) {
            v.unk0 = a->unk60.unk0; v.unk4 = a->unk60.unk4;
            fn_800B5ECC(b, &v);
        }
        if (p->unk23b == 2 && (a->unkA0 & 0x200)) fn_800B5F38(b, lbl_80304B58[a->unk14]);
    }
}
