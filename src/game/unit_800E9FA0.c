#include "types.h"

typedef struct Unk8043CD28 {
    /* 0x000 */ void* unk0;
    /* 0x004 */ void* unk4;
    /* 0x008 */ void* unk8;
    /* 0x00C */ u8 padC[0x254 - 0xC];
    /* 0x254 */ s32 bits[0x20];
    /* 0x2D4 */ s32 unk2D4;
    /* 0x2D8 */ s32 unk2D8;
    /* 0x2DC */ u16 unk2DC;
    /* 0x2DE */ u16 unk2DE;
    /* 0x2E0 */ u8 unk2E0;
    /* 0x2E1 */ u8 unk2E1;
    /* 0x2E2 */ u8 unk2E2;
    /* 0x2E3 */ u8 unk2E3;
    /* 0x2E4 */ u8 unk2E4;
    /* 0x2E5 */ u8 pad2E5[0x2E8 - 0x2E5];
} Unk8043CD28;

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

typedef struct Unk800E9FA0Hdr {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 offs[1];
} Unk800E9FA0Hdr;

typedef struct Unk800E9FA0Data {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
    /* 0x8 */ u32 unk8;
} Unk800E9FA0Data;

extern Unk8043CD28 lbl_8043CD28;
extern Unk80316D78 lbl_80316D78;

static inline Unk800E9FA0Data* StageData(u8 stage) {
    u8* base = lbl_80316D78.unk3004 + 0xDAD000;

    return (Unk800E9FA0Data*)(base + (((Unk800E9FA0Hdr*)base)->offs[stage] >> 1));
}

void fn_800E9FA0(u8 stage, u8 arg1) {
    Unk800E9FA0Data* d;
    s32 i;

    lbl_8043CD28.unk2DE = 1;
    lbl_8043CD28.unk2E0 = stage;
    lbl_8043CD28.unk2E1 = arg1;
    lbl_8043CD28.unk2E3 = 0;
    lbl_8043CD28.unk4 = NULL;
    lbl_8043CD28.unk2E4 = 1;
    d = StageData(stage);
    lbl_8043CD28.unk4 = (u8*)d + d->unk4;
    d = StageData(stage);
    lbl_8043CD28.unk0 = (u8*)d + d->unk0;
    lbl_8043CD28.unk2E2 = 0xFF;
    for (i = 0; i < 0x20; i++) {
        lbl_8043CD28.bits[i] = -1;
    }
    d = StageData(stage);
    lbl_8043CD28.unk8 = (u8*)d + d->unk8;
    lbl_8043CD28.unk2D4 = 0x80000000;
    lbl_8043CD28.unk2D8 = 0x7FFFFFFF;
}
