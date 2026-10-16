#include "types.h"
typedef struct Unk800503A8Pair { /* 0x00 */ s32 unk0; /* 0x04 */ s32 unk4; } Unk800503A8Pair;
typedef struct Unk800503A8Obj {
    /* 0x00 */ u8 pad00[0x60];
    /* 0x60 */ Unk800503A8Pair unk60;
    /* 0x68 */ u8 pad68[0x7C - 0x68];
    /* 0x7C */ u8 unk7C;
    /* 0x7D */ u8 pad7D[0xA0 - 0x7D];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u8 padA4[0xC8 - 0xA4];
    /* 0xC8 */ Unk800503A8Pair unkC8;
} Unk800503A8Obj;
typedef struct Unk800503A8 {
    /* 0x00 */ u8 pad00[0xC];
    /* 0x0C */ struct Unk800503A8* unk0C;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u8 pad18[0x23 - 0x18];
    /* 0x23 */ u8 unk23a:4;
                 u8 unk23b:4;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ Unk800503A8Obj* unk28;
} Unk800503A8;
extern void fn_800B5ECC(Unk800503A8Obj*, Unk800503A8Pair*);
extern void fn_800B5F38(Unk800503A8Obj*, s32);
void fn_800503A8(Unk800503A8* p) {
    Unk800503A8Obj* a = p->unk28;
    Unk800503A8Obj* b = p->unk0C->unk28;
    Unk800503A8Pair v;
    if (p->unk14 & 1) {
        if (p->unk23b == 3) a->unkC8 = b->unk60;
        else if (p->unk23b == 8) {
            v.unk0 = a->unk60.unk0; v.unk4 = a->unk60.unk4;
            if (a->unk7C != 2 && a->unk7C != 1) v.unk4 -= 0x800;
            fn_800B5ECC(b, &v);
        }
        if (p->unk23b == 2 && (a->unkA0 & 0x200)) fn_800B5F38(b, 0);
    }
}
