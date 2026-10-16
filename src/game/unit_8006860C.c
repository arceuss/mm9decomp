#include "types.h"
typedef struct Unk8006860C {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[7];
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0x54 - 0x13];
    /* 0x54 */ u32 unk54a:20;
                 u32 unk54b:1;
                 u32 unk54c:1;
                 u32 unk54d:10;
    /* 0x58 */ u8 pad58[0x64 - 0x58];
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0x7F - 0x70];
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[0xCA - 0x80];
    /* 0xCA */ u8 unkCA;
} Unk8006860C;
extern void fn_800E946C(Unk8006860C*, s32);
extern void fn_800E9750(Unk8006860C*, u16);
extern void fn_80042D30(Unk8006860C*);
void fn_8006860C(Unk8006860C* p) {
    switch (p->unk12) {
    case 0:
        fn_800E946C(p, 14);
        p->unk6C = 0x100;
        switch (p->unkCA) {
        case 0:
            p->unk0A &= 0xEF; p->unk54c = 0;
            p->unk0A &= 0xDF; p->unk54b = 0;
            break;
        case 1:
            p->unk0A |= 0x10; p->unk54c = 1;
            p->unk0A &= 0xDF; p->unk54b = 0;
            break;
        case 2:
            p->unk0A &= 0xEF; p->unk54c = 0;
            p->unk0A |= 0x20; p->unk54b = 1;
            break;
        case 3:
            p->unk0A |= 0x10; p->unk54c = 1;
            p->unk0A |= 0x20; p->unk54b = 1;
            break;
        }
        p->unk12++;
    case 1:
        p->unk64 += p->unk6C;
        if (p->unk7F == 3) { fn_80042D30(p); return; }
        break;
    }
    fn_800E9750(p, 0xFFFF);
}
