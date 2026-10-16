#include "types.h"
typedef struct Unk80080194 {
    /* 0x00 */ u8 pad00[0x18];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 unk1C;
    /* 0x1D */ u8 unk1D;
    /* 0x1E */ u16 unk1E;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u16 unk24;
    /* 0x26 */ s16 unk26;
    /* 0x28 */ u8 pad28[0x10];
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u8 pad40[0x8];
    /* 0x48 */ s32 unk48;
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ s32 unk50;
    /* 0x54 */ u8 pad54[0x8];
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
    /* 0x74 */ s32 unk74;
    /* 0x78 */ s32 unk78;
} Unk80080194;
typedef struct Unk80080194Arg {
    /* 0x00 */ u8 unk00;
    /* 0x01 */ u8 unk01;
    /* 0x02 */ u8 pad02[2];
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
} Unk80080194Arg;
extern void* lbl_802727E8[];
void fn_80080194(Unk80080194* p, Unk80080194Arg* a) {
    if (!a) {
        p->unk1C = 0; p->unk20 = 0; p->unk24 = 0; p->unk1E = 0;
        p->unk18 = lbl_802727E8[0];
        p->unk50 = 0; p->unk1D = 0; p->unk26 = 0; p->unk38 = 0; p->unk3C = 0;
        return;
    }
    p->unk1C = a->unk00; p->unk20 = 0; p->unk24 = 0; p->unk1E = 0;
    p->unk18 = lbl_802727E8[p->unk1C];
    p->unk1D = a->unk01; p->unk26 = 0; p->unk50 = 0;
    if (a->unk00 == 1) { p->unk38 = a->unk04; p->unk3C = a->unk08; }
    p->unk48 = a->unk0C; p->unk4C = a->unk10;
    p->unk5C = a->unk14; p->unk60 = a->unk16; p->unk64 = a->unk18; p->unk68 = a->unk1A;
    p->unk6C = a->unk1C; p->unk70 = a->unk20; p->unk74 = a->unk24; p->unk78 = a->unk28;
}
