#include "types.h"

typedef struct Unk8043CD28 {
    /* 0x000 */ u8 pad0[0x8];
    /* 0x008 */ u8* unk8;
    /* 0x00C */ u8 padC[0x2D4 - 0xC];
    /* 0x2D4 */ s32 unk2D4;
    /* 0x2D8 */ s32 unk2D8;
    /* 0x2DC */ u8 pad2DC[0x2E2 - 0x2DC];
    /* 0x2E2 */ u8 unk2E2;
    /* 0x2E3 */ u8 pad2E3[0x2E5 - 0x2E3];
    /* 0x2E5 */ u8 unk2E5;
    /* 0x2E6 */ u8 pad2E6[0x2];
} Unk8043CD28;

extern Unk8043CD28 lbl_8043CD28;

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
    /* 0x3008 */ u8 pad3008[0x3028 - 0x3008];
} Unk80316D78;

extern Unk80316D78 lbl_80316D78;

extern char* lbl_80281F7C[];

void fn_800AA554(char* name, u16 arg1, void* dst);
void fn_800AA9A4(void);

void fn_800E9D0C(u8 index) {
    fn_800AA554(lbl_80281F7C[index], 0xFFFF, lbl_80316D78.unk3004 + 0xDAD000);
    fn_800AA9A4();
    lbl_8043CD28.unk2E5 = index;
}
