#include "types.h"
typedef struct Unk800698C8Pair { /* 0x00 */ s32 unk0; /* 0x04 */ s32 unk4; } Unk800698C8Pair;
typedef struct Unk800698C8Obj {
    /* 0x00 */ u8 pad00[0x60];
    /* 0x60 */ Unk800698C8Pair unk60;
    /* 0x68 */ u8 pad68[0xC8 - 0x68];
    /* 0xC8 */ Unk800698C8Pair unkC8;
} Unk800698C8Obj;
typedef struct Unk800698C8 {
    /* 0x00 */ u8 pad00[0xC];
    /* 0x0C */ struct Unk800698C8* unk0C;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u8 pad18[0x23 - 0x18];
    /* 0x23 */ u8 unk23a:4;
                 u8 unk23b:4;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ Unk800698C8Obj* unk28;
} Unk800698C8;
extern void fn_800B5ECC(Unk800698C8Obj*, Unk800698C8Pair*);
void fn_800698C8(Unk800698C8* p) {
    Unk800698C8Obj* a = p->unk28;
    Unk800698C8Obj* b = p->unk0C->unk28;
    Unk800698C8Pair v;
    if (p->unk14 & 1) {
        if (p->unk23b == 3) a->unkC8 = b->unk60;
        if (p->unk23b == 8) {
            v.unk0 = a->unk60.unk0;
            v.unk4 = a->unk60.unk4;
            if (!(p->unk14 & 8)) fn_800B5ECC(b, &v);
        }
    }
}
