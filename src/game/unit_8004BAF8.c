#include "types.h"
#include "game/obj.h"

typedef struct Unk8004BAF8 {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[6];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0x60 - 0x13];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xA0 - 0x68];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u8 padA4[0xAB - 0xA4];
    /* 0xAB */ u8 unkAB_hi : 4;
    /* 0xAB */ u8 hitType : 4;
    /* 0xAC */ u8 padAC[0xD3 - 0xAC];
    /* 0xD3 */ u8 unkD3;
} Unk8004BAF8;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;
extern u8 lbl_80304B90[];

void fn_80042CF8(Obj*, s32);
void fn_800D5458(s32 id);
u32 fn_80080484(void*, void*, s32);

BOOL fn_8004BAF8(Unk8004BAF8* obj) {
    u8 t;

    if (lbl_803051D8.unk2 & 0x10) {
        if (fn_80080484(lbl_80304B90 + 0x21C, &obj->unk60, 1) == 0) {
            obj->unk11 = 4;
            return TRUE;
        }
    }
    if (obj->unk11 != 1 && obj->hitType == 3) {
        if (obj->unkD3 != 0) {
            fn_800D5458(0x42);
        }
        obj->unk11 = 1;
        obj->unk12 = 0;
        return FALSE;
    }
    if (obj->unk11 != 2 && obj->hitType == 5) {
        if (obj->unkD3 != 0) {
            fn_800D5458(0x42);
        }
        obj->unk11 = 2;
        obj->unk12 = 0;
        return FALSE;
    }
    t = obj->hitType;
    if (t == 8) {
        fn_80042CF8((Obj*)obj, 2);
        obj->unk11 = 2;
        return TRUE;
    }
    if ((obj->unkA0 & 0x200) && t == 2) {
        fn_80042CF8((Obj*)obj, 2);
        obj->unk11 = 3;
        return TRUE;
    }
    if (obj->unkA0 & 0x200) {
        fn_80042CF8((Obj*)obj, 2);
        obj->unk11 = 0;
        obj->unk12 = 0;
        return TRUE;
    }
    return FALSE;
}
