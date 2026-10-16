#include "types.h"

typedef struct Unk800B68FC {
    /* 0x000 */ u8 pad0[0x9];
    /* 0x009 */ u8 unk9;
    /* 0x00A */ u8 padA[0x13C - 0xA];
    /* 0x13C */ void* anim;
    /* 0x140 */ u8 pad140[0x19C - 0x140];
    /* 0x19C */ s32 unk19C;
} Unk800B68FC;

extern void** lbl_8027EA58[];

s32 fn_800B79D4(Unk800B68FC* p, u32 code, s32 frame);

void fn_800B68FC(Unk800B68FC* p, u32 code, s32 frame) {
    u32 index = (code >> 16) & 0x7F;

    p->anim = ((code >> 23) & 1) ? ((void**)lbl_8027EA58[p->unk9][index])[frame] : lbl_8027EA58[p->unk9][index];
    p->unk19C = fn_800B79D4(p, code, frame);
}
