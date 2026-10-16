#include "types.h"
typedef struct Unk80073608 {
    /* 0x00 */ u8 pad00[0x9];
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[0x5];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x3];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x90];
    /* 0xAC */ void (*unkAC)(void*);
} Unk80073608;
extern void** lbl_80270168[];
extern u8 lbl_8026FB60[], lbl_804EE818[8];
extern void fn_800E9424(Unk80073608*, s32);
extern void fn_800E91F0(Unk80073608*, void*, s32);
extern void fn_800735CC(void*);
extern void fn_800736B0(Unk80073608*);
void fn_80073608(Unk80073608* p) {
    fn_800E9424(p, 9);
    p->unk0A |= 3;
    fn_800E91F0(p, lbl_8026FB60, 0);
    p->unkAC = fn_800735CC;
    p->unk18 = lbl_80270168[p->unk09][1];
    p->unk10 = 1; p->unk11 = 0; p->unk12 = 0; p->unk13 = 0;
    p->unk11 = lbl_804EE818[p->unk14];
    fn_800736B0(p);
}
