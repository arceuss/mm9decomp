#include "types.h"

typedef struct Unk80065488 { /* 0x00 */ u16 unk0; } Unk80065488;
extern const Unk80065488 lbl_804EF638, lbl_804EF63A, lbl_804EF63C;
extern u16 fn_8009E850(s32, s32);
extern void fn_8009EF24(s32, s32, u16*);

void fn_80065488(s32 a, s32 b) {
    Unk80065488 values[3];
    s32 value;
    u16 tile;
    values[0] = lbl_804EF638;
    values[1] = lbl_804EF63A;
    values[2] = lbl_804EF63C;
    tile = fn_8009E850(a, b);
    value = 0;
    switch (tile) {
    case 0xC0: value = 0xC2; break;
    case 0xC1: value = 0xC3; break;
    case 0xC2: value = 0xC0; break;
    case 0xC3: value = 0xC1; break;
    case 0xC4: value = 0xC6; break;
    case 0xC5: value = 0xC7; break;
    case 0xC6: value = 0xC4; break;
    case 0xC7: value = 0xC5; break;
    case 0xC8: value = 0xCA; break;
    case 0xC9: value = 0xCB; break;
    case 0xCA: value = 0xC8; break;
    case 0xCB: value = 0xC9; break;
    case 0xCC: value = 0xCE; break;
    case 0xCD: value = 0xCF; break;
    case 0xCE: value = 0xCC; break;
    case 0xCF: value = 0xCD; break;
    }
    if (value != 0) {
        values[2].unk0 = value;
        fn_8009EF24(a >> 12, b >> 12, (u16*)values);
    }
}
