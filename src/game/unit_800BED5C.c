#include "types.h"
typedef struct UnkDisp {
    u8 pad0[0x9];
    u8 unk9;
    u8 unkA;
    u8 padB[0x10 - 0xB];
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 pad15[0x18 - 0x15];
    s32 unk18;
} UnkDisp;
extern u8 lbl_8027F228[0x28];
extern u8 lbl_804ECF4C[4];
extern void (*lbl_804ECF40[2])(UnkDisp*);
void fn_800E9244(UnkDisp* rec);
void fn_800BED5C(UnkDisp* rec) {
    s32 idx;
    rec->unk18 = *(s32*)((u8*)*(u32**)(lbl_8027F228 + rec->unk9 * 4) + 0x10);
    rec->unk10 = 4;
    rec->unk11 = 0;
    rec->unk12 = 0;
    rec->unk13 = 0;
    fn_800E9244(rec);
    rec->unkA = rec->unkA & 0xFE;
    idx = lbl_804ECF4C[rec->unk14];
    lbl_804ECF40[idx](rec);
}
