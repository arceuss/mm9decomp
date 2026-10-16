#include "types.h"

typedef struct Unk80080FE0 {
    /* 0x000 */ u8 unk0;
    /* 0x001 */ u8 unk1;
    /* 0x002 */ u8 unk2;
    /* 0x003 */ u8 pad3[0xEC - 0x3];
    /* 0x0EC */ s32 unkEC;
    /* 0x0F0 */ s32 unkF0;
    /* 0x0F4 */ u8 unkF4;
    /* 0x0F5 */ u8 unkF5;
    /* 0x0F6 */ u16 unkF6;
    /* 0x0F8 */ u8 unkF8[0x115 - 0xF8];
    /* 0x115 */ u8 unk115;
    /* 0x116 */ u8 pad116[0x11E - 0x116];
    /* 0x11E */ u16 unk11E;
    /* 0x120 */ u8 pad120[0x148 - 0x120];
    /* 0x148 */ void* unk148;
    /* 0x14C */ u8 pad14C[0x174 - 0x14C];
    /* 0x174 */ s16 unk174[4];
    /* 0x17C */ s16 unk17C[4];
    /* 0x184 */ s16 unk184[4];
    /* 0x18C */ s32 unk18C;
    /* 0x190 */ s16 unk190;
    /* 0x192 */ s16 unk192;
    /* 0x194 */ s32 unk194;
    /* 0x198 */ s32 unk198;
    /* 0x19C */ u8 pad19C[0x1A0 - 0x19C];
    /* 0x1A0 */ s32 unk1A0;
    /* 0x1A4 */ s32 unk1A4;
    /* 0x1A8 */ u8 unk1A8[0x1B0 - 0x1A8];
    /* 0x1B0 */ s32 unk1B0;
} Unk80080FE0;

typedef struct Unk8038B2F8Sub {
    /* 0x0000 */ u8 pad0[0x2500];
    /* 0x2500 */ u8 unk2500;
    /* 0x2501 */ u8 unk2501;
    /* 0x2502 */ u8 unk2502;
    /* 0x2503 */ u8 unk2503;
    /* 0x2504 */ u8 pad2504[0x2510 - 0x2504];
    /* 0x2510 */ s32 unk2510;
} Unk8038B2F8Sub;

typedef struct Unk8038B2F8 {
    /* 0x0000 */ u8 pad0[0x184];
    /* 0x0184 */ Unk8038B2F8Sub* unk184;
    /* 0x0188 */ u8 pad188[0x26BC - 0x188];
    /* 0x26BC */ u16 unk26BC;
    /* 0x26BE */ u8 pad26BE[0x26C0 - 0x26BE];
} Unk8038B2F8;

extern Unk8038B2F8 lbl_8038B2F8;

void fn_80080020(void* arg0, s32 arg1, s32 arg2);
void fn_80080168(void* arg0, s32 arg1);

void fn_80080FE0(Unk80080FE0* p, s32 arg1) {
    s32 i;

    p->unk0 = 0;
    p->unk2 = 0;
    p->unkEC = 0;
    p->unkF0 = 0;
    p->unkF4 = 0;
    p->unkF5 = 0;
    p->unkF6 = 0x8000;
    for (i = 0; i < 4; i++) {
        p->unk174[i] = 0;
        p->unk17C[i] = 0;
        p->unk184[i] = 0;
    }
    p->unk1A4 = -1;
    p->unk1A0 = -1;
    p->unk18C = 0;
    p->unk190 = 0;
    p->unk192 = 0;
    p->unk194 = 0;
    p->unk198 = -1;
    p->unk1B0 = 0;
    p->unk1 = 0;
    lbl_8038B2F8.unk26BC = 0;
    lbl_8038B2F8.unk184->unk2500 = 0;
    lbl_8038B2F8.unk184->unk2510 = 1;
    lbl_8038B2F8.unk184->unk2503 = 0x20;
    lbl_8038B2F8.unk184->unk2502 = 0x20;
    lbl_8038B2F8.unk184->unk2501 = 0x20;
    fn_80080020(p->unkF8, 0, arg1);
    fn_80080168(p->unkF8, 0);
    p->unk148 = p->unk1A8;
    p->unk115 = 8;
    p->unk11E = 0;
}
