#include "types.h"
typedef struct Unk800814EC {
    /* 0x00 */ u8 pad00[0x2C];
    /* 0x2C */ u8* unk2C;
    /* 0x30 */ u8 pad30[0xC8];
    /* 0xF8 */ u8 unkF8[0x1C];
    /* 0x114 */ s8 unk114;
    /* 0x115 */ u8 pad115[0x77];
    /* 0x18C */ u32 unk18C;
    /* 0x190 */ u8 pad190[0x18];
    /* 0x1A8 */ s32 unk1A8[2];
} Unk800814EC;
extern u8 lbl_8038B2F8[];
extern void fn_80024058(s32);
extern void fn_800800B8(void*);
extern void fn_8009E1A4(void*);
extern void fn_800800AC(void*);
extern void fn_800800F8(void*);
void fn_800814EC(Unk800814EC* p, void* a, s32 b) {
    if (p->unk18C) {
        u32 v;
        p->unk18C += 0x80000;
        v = p->unk18C >> 16;
        if (!(p->unk18C & 1)) v = 0x80 - v;
        (*(u8**)(lbl_8038B2F8 + 0x184))[0x2500] = v >> 2;
        if (p->unk18C > 0x800000) p->unk18C = 0;
    }
    fn_80024058(0);
    if (b == 0) fn_800800B8(p->unkF8);
    if (p->unk114) fn_8009E1A4(a);
    { typedef struct { /* 0x00 */ s32 unk0; /* 0x04 */ s32 unk4; } Unk800814ECPair; *(Unk800814ECPair*)p->unk1A8 = *(Unk800814ECPair*)(p->unk2C + 0x60); }
    fn_800800AC(p->unkF8); fn_800800F8(p->unkF8);
}
