#include "types.h"
#include "game/sound.h"
typedef struct Unk8006A4E8Pair { /* 0x00 */ s32 unk0; /* 0x04 */ s32 unk4; } Unk8006A4E8Pair;
typedef struct Unk8006A4E8Obj {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ s8 unk08;
    /* 0x09 */ u8 pad09[0x14 - 9];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x60 - 0x15];
    /* 0x60 */ Unk8006A4E8Pair unk60;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0xC8 - 0x6C];
    /* 0xC8 */ union { Unk8006A4E8Pair pair; u8 bytes[8]; } unkC8;
} Unk8006A4E8Obj;
typedef struct Unk8006A4E8 {
    /* 0x00 */ u8 pad00[0xC];
    /* 0x0C */ struct Unk8006A4E8* unk0C;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u8 pad18[0x23 - 0x18];
    /* 0x23 */ u8 unk23a:4;
                 u8 unk23b:4;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ Unk8006A4E8Obj* unk28;
} Unk8006A4E8;
extern void fn_800C7608(Unk8006A4E8*);
extern void fn_800D5234(s32);
void fn_8006A4E8(Unk8006A4E8* p) {
    Unk8006A4E8Obj* a = p->unk28;
    Unk8006A4E8Obj* b = p->unk0C->unk28;
    if (p->unk14 & 1) {
        if (a->unk14 == 2 || a->unk14 == 3 || a->unk14 == 4 || a->unk14 == 5) {
            if (p->unk23b == 3) a->unkC8.pair = b->unk60;
        } else fn_800C7608(p);
    }
    if (a->unk14 == 2) {
        if (p->unk14 & 8) {
            if (b->unk08 == 1 || b->unk08 == 3) a->unkC8.bytes[0] = 1;
            else {
                a->unkC8.bytes[0] = 2;
                if (a->unk68 > 0 && ++a->unkC8.bytes[1] < 3) fn_800D5234(SE_REFLECT);
            }
        }
        if (p->unk14 & 4) {
            if (b->unk08 == 0) a->unkC8.bytes[2] = 1;
            else a->unkC8.bytes[2] = 2;
        }
    }
}
