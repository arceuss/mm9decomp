#include "types.h"

typedef struct Unk80098FD4 {
    /* 0x0000 */ u8 pad0[0x8];
    /* 0x0008 */ s16 unk8;
    /* 0x000A */ s16 unkA;
    /* 0x000C */ u8 padC[0x10F8 - 0xC];
    /* 0x10F8 */ u16 unk10F8[30];
} Unk80098FD4;

typedef struct Unk8043CA80 {
    /* 0x000 */ u8 pad0[0x258];
    /* 0x258 */ u8* unk258;
    /* 0x25C */ u8 pad25C[0x268 - 0x25C];
} Unk8043CA80;

extern Unk8043CA80 lbl_8043CA80;

s32 fn_8000EECC(s32 range);

void fn_80098FD4(Unk80098FD4* p) {
    s32 offset;

    if (p->unkA < 30 && (0x80 - p->unk8) / 4 >= p->unkA) {
        offset = fn_8000EECC(0x38);
        ((u16*)(lbl_8043CA80.unk258 + offset + 0x484))[p->unkA] = p->unk10F8[p->unkA];
        p->unkA++;
    }
}
