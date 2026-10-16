#include "types.h"
typedef struct Unk80081CD4 {
    /* 0x00 */ u8 pad00[0x28];
    /* 0x28 */ u8* unk28;
    /* 0x2C */ u8 pad2C[0xC9];
    /* 0xF5 */ u8 unkF5;
} Unk80081CD4;
extern u8 fn_80024010(void);
extern u8 fn_80024048(void);
s32 fn_80081CD4(Unk80081CD4* p) {
    u8* cmd = p->unk28;
    p->unkF5 &= 0x7F;
    switch (cmd[1]) {
    case 0:
        if (*(s16*)(cmd + 2) == 0) p->unkF5 &= ~1;
        else p->unkF5 |= 1;
        break;
    case 1:
        if (*(s16*)(cmd + 2) == 0) p->unkF5 &= 0xFD;
        else p->unkF5 |= 2;
        break;
    case 2:
        if (fn_80024010()) { p->unkF5 &= ~1; p->unk28 -= 8; return 1; }
        break;
    case 3:
        if (fn_80024048()) { p->unkF5 &= 0xFD; p->unk28 -= 8; return 1; }
        break;
    }
    return 0;
}
