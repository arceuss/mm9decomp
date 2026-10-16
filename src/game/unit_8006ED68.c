#include "types.h"
typedef struct Unk8006ED68Pair { /* 0x00 */ s32 unk0; /* 0x04 */ s32 unk4; } Unk8006ED68Pair;
typedef struct Unk8006ED68Obj {
    /* 0x00 */ u8 pad00[0x60];
    /* 0x60 */ Unk8006ED68Pair unk60;
    /* 0x68 */ u8 pad68[0xA0 - 0x68];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u8 padA4[0xC8 - 0xA4];
    /* 0xC8 */ Unk8006ED68Pair unkC8;
} Unk8006ED68Obj;
typedef struct Unk8006ED68 {
    /* 0x00 */ u8 pad00[0xC];
    /* 0x0C */ struct Unk8006ED68* unk0C;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u8 pad18[0x23 - 0x18];
    /* 0x23 */ u8 unk23a:4;
                 u8 unk23b:4;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ Unk8006ED68Obj* unk28;
} Unk8006ED68;
extern void fn_800B5ECC(Unk8006ED68Obj*, Unk8006ED68Pair*);
extern void fn_800B5F38(Unk8006ED68Obj*, s32);
void fn_8006ED68(Unk8006ED68* p) {
    Unk8006ED68Obj* a = p->unk28;
    Unk8006ED68Obj* b = p->unk0C->unk28;
    Unk8006ED68Pair v;
    if (p->unk14 & 1) {
        if (p->unk23b == 3) a->unkC8 = b->unk60;
        if (p->unk23b == 8) {
            v.unk0 = a->unk60.unk0; v.unk4 = a->unk60.unk4 - 0x600;
            fn_800B5ECC(b, &v);
        }
        if (p->unk23b == 2 && (a->unkA0 & 0x200)) fn_800B5F38(b, 0);
    }
}
