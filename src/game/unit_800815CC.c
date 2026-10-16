#include "types.h"
typedef struct Unk800815CC {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[0x9];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x6];
    /* 0x1C */ void* unk1C;
    /* 0x20 */ u8 pad20[0x40];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
} Unk800815CC;
typedef struct Unk800815CCNode {
    /* 0x00 */ Unk800815CC* unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u8 unk08;
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u16 unk0A;
    /* 0x0C */ u16 unk0C;
    /* 0x0E */ u16 unk0E;
} Unk800815CCNode;
typedef struct Unk800815CCArg {
    /* 0x00 */ u8 unk00;
    /* 0x01 */ u8 unk01;
    /* 0x02 */ u8 unk02;
    /* 0x03 */ u8 unk03;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s8 unk0C;
    /* 0x0D */ s8 unk0D;
} Unk800815CCArg;
extern u8 lbl_80301308[];
extern Unk800815CC* fn_800EA8DC(s32, s32);
void fn_800815CC(void* p, u8 n, Unk800815CCArg* a) {
    Unk800815CCNode* node = (Unk800815CCNode*)((u8*)p + 0x2C) + n;
    Unk800815CC* q;
    if (n != 0 && node->unk00 == 0) {
        q = fn_800EA8DC(a->unk00, a->unk01);
        node->unk00 = q;
        if (q) {
            q->unk0A |= 0x80; q->unk1C = node;
            q->unk14 = a->unk02; q->unk15 = a->unk03;
            q->unk60 = a->unk04; q->unk64 = a->unk08;
            if (a->unk0C) q->unk0A |= 0x10; else q->unk0A &= 0xEF;
            if (a->unk0D) q->unk0A |= 0x20; else q->unk0A &= 0xDF;
            node->unk08 = n; node->unk09 = 0;
            node->unk0E = 0; node->unk0C = 0; node->unk0A = 0; node->unk04 = 0;
            if (n == 1) *(Unk800815CC**)(lbl_80301308 + 4) = q;
        }
    }
}
