#include "types.h"
#include "game/obj.h"

typedef struct Unk41A78 {
    /* 0x00 */ u8 pad00[9];
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[5];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[2];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x60 - 0x1C];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[8];
    /* 0x70 */ s32 unk70;
} Unk41A78;
typedef struct Unk41A78Global {
    /* 0x00000 */ u8 pad00000[0x4AEB8];
    /* 0x4AEB8 */ s32 unk4AEB8;
} Unk41A78Global;
extern Unk41A78Global lbl_8031BF70;
extern u8 lbl_80304B90[];
extern u8 lbl_803051D8[];
extern void** lbl_80265138[];
extern const s16 lbl_802537E8[256];
void fn_800E9750(Obj*, u16);
u32 fn_8009E894(s32, s32);
s32 fn_80080484(void*, void*, s32);

void fn_80041A78(Unk41A78* obj) {
    if (lbl_803051D8[2] & 0x20) {
        obj->unk0A &= ~1;
        obj->unk0A &= 0xFD;
        obj->unk18 = lbl_80265138[obj->unk09][3];
        obj->unk10 = 3;
        obj->unk11 = 0;
        obj->unk12 = 0;
        obj->unk13 = 0;
    } else {
        fn_800E9750((Obj*)obj, 0xFFFF);
        obj->unk16 += 0x16;
        obj->unk60 = obj->unk70 + (lbl_802537E8[obj->unk16] * 0xBF) / 256;
        obj->unk64 -= 0x100;
        if (!(fn_8009E894(obj->unk60, obj->unk64) & 0x8000) && obj->unk64 <= lbl_8031BF70.unk4AEB8) {
            obj->unk18 = lbl_80265138[obj->unk09][2];
            obj->unk10 = 2;
            obj->unk11 = 0;
            obj->unk12 = 0;
            obj->unk13 = 0;
        } else if (fn_80080484(lbl_80304B90 + 0x21C, &obj->unk60, 1)) {
            obj->unk18 = lbl_80265138[obj->unk09][2];
            obj->unk10 = 2;
            obj->unk11 = 0;
            obj->unk12 = 0;
            obj->unk13 = 0;
        }
    }
}
