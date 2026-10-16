#include "types.h"

typedef struct Unk56Rec {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 padA[0xFC - 0xA];
    /* 0xFC */ u8 unkFC;
} Unk56Rec;

extern u8 lbl_8027EB60[];

void fn_800B9F74(void*, void*);

void fn_800B56A4(Unk56Rec* rec) {
    rec->unkFC = 0;
    fn_800B9F74(rec, *(void**)((u8*)*(void**)(lbl_8027EB60 + rec->unk9 * 4) + 0));
}
