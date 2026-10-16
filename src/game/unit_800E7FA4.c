#include "types.h"

typedef struct Unk803BB320_58 {
    /* 0x0 */ u8 pad0[0x10];
} Unk803BB320_58;

typedef struct Unk803BB320 {
    /* 0x0000 */ u8 pad0[0xC];
    /* 0x000C */ s32 unkC;
    /* 0x0010 */ u8 pad10[0x58 - 0x10];
    /* 0x0058 */ Unk803BB320_58 unk58[4];
    /* 0x0098 */ u8 pad98[0x1760 - 0x98];
} Unk803BB320;

extern Unk803BB320 lbl_803BB320;

typedef struct Unk8038B2F8_184 {
    /* 0x0000 */ u8 pad0[0x2500];
    /* 0x2500 */ u8 unk2500;
} Unk8038B2F8_184;

typedef struct Unk8038B2F8 {
    /* 0x000 */ u8 pad0[0x184];
    /* 0x184 */ Unk8038B2F8_184* unk184;
} Unk8038B2F8;

extern Unk8038B2F8 lbl_8038B2F8;

void fn_800BB2B0(void);
void fn_800BAE64(void);
void fn_800BA908(void);
void fn_800BAAB8(void);
void fn_800E8024(u32 index);

void fn_800E7FA4(void) {
    u32 i;

    fn_800BB2B0();
    fn_800BAE64();
    fn_800BA908();
    fn_800BAAB8();
    lbl_803BB320.unkC = lbl_8038B2F8.unk184->unk2500;
    for (i = 0; i < 4; i++) {
        fn_800E8024(i);
    }
}
