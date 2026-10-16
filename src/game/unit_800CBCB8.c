#include "types.h"
#include "game/obj.h"

typedef struct Unk80280390Entry {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800CBCB8 {
    /* 0x00 */ u8 pad00[9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[5];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[2];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x60 - 0x1C];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[4];
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[4];
    /* 0x74 */ s32 unk74;
} Unk800CBCB8;

typedef struct Unk804EE984C {
    /* 0x00 */ u8 pad[0x64];
    /* 0x64 */ s32 unk64;
} Unk804EE984C;

extern Unk80280390Entry* lbl_80280390[];
extern Unk804EE984C* lbl_804EE984;
extern u8 lbl_80304B90[];

s32 fn_800B6010(void*, void*);
void fn_800E946C(Obj*, s32);
void fn_800D5234(s32);
void fn_800E9750(Unk800CBCB8*, u16);
u32 fn_80080484(void*, void*, s32);

void fn_800CBCB8(Unk800CBCB8* obj) {
    switch (obj->unk12) {
    case 0:
        fn_800E946C((Obj*)obj, 0);
        obj->unk12++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        if (fn_800B6010(lbl_804EE984, obj) != 0) {
            obj->unk12++;
        }
        break;
    case 2:
        obj->unk16 = 8;
        obj->unk64 += 0x300;
        obj->unk12++;
    case 3:
        if (obj->unk16 == 0) {
            obj->unk64 -= 0x300;
            obj->unk12++;
        } else {
            obj->unk16--;
        }
        break;
    case 4:
        obj->unk6C = -0x180;
        obj->unk74 = -0x20;
        fn_800D5234(0x38);
        obj->unk12++;
    case 5:
        fn_800E9750(obj, 0xFFFF);
        obj->unk6C += obj->unk74;
        obj->unk64 += obj->unk6C;
        if (obj->unk6C < -0x5c0) {
            obj->unk6C = -0x5c0;
        }
        if (fn_80080484(lbl_80304B90 + 0x21C, &obj->unk60, 1) >= 0x800) {
            obj->unk0A &= ~1;
            obj->unk0A &= 0xFD;
            fn_800E9244((Obj*)obj);
            obj->unk18 = lbl_80280390[obj->unk9]->unkC;
            obj->unk10 = 3;
            obj->unk11 = 0;
            obj->unk12 = 0;
            obj->unk13 = 0;
        }
        break;
    }
}
