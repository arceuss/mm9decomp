#include "types.h"

typedef struct UnkP {
    /* 0x000 */ u8 pad0[0x9];
    /* 0x009 */ u8 unk9;
    /* 0x00A */ u8 flagsA;
    /* 0x00B */ u8 padB[0x11 - 0xB];
    /* 0x011 */ u8 state;
    /* 0x012 */ u8 pad12[0x26 - 0x12];
    /* 0x026 */ u16 unk26;
    /* 0x028 */ u8 pad28[0x54 - 0x28];
    /* 0x054 */ u32 flags54_hi : 21;
    /* 0x054 */ u32 facing : 1;
    /* 0x054 */ u32 flags54_lo : 10;
    /* 0x058 */ u8 pad58[0x7D - 0x58];
    /* 0x07D */ u8 frame;
    /* 0x07E */ u8 pad7E[0xF8 - 0x7E];
    /* 0x0F8 */ u32 animCode;
    /* 0x0FC */ u8 padFC[0x100 - 0xFC];
    /* 0x100 */ u8 unk100;
    /* 0x101 */ u8 unk101;
    /* 0x102 */ u8 pad102[0x104 - 0x102];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 pad108[0x10C - 0x108];
    /* 0x10C */ u8 weapon;
} UnkP;

void fn_800BBB18(UnkP* p);

void fn_800BA550(UnkP* p) {
    if (!((1 << p->unk9) & 0x300)) {
        fn_800BBB18(p);
    }
}
