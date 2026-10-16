#include "types.h"
#include "game/obj.h"

typedef struct Unk46204 {
    /* 0x00 */ u8 pad00[0x11];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0xA0 - 0x13];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u8 padA4[7];
    /* 0xAB */ u8 unkAB;
} Unk46204;

extern u8 lbl_803051D8[];

s32 fn_8005BB08(Unk46204* obj) {
    if (lbl_803051D8[2] & 0x10) {
        fn_80042CF8((Obj*)obj, 2);
        obj->unk11 = 4;
        return 1;
    }
    if (obj->unk11 != 2 && (obj->unkAB & 0xFU) == 3) {
        obj->unk11 = 2;
        obj->unk12 = 0;
        return 0;
    }
    if (obj->unk11 != 3 && (obj->unkAB & 0xFU) == 5) {
        obj->unk11 = 3;
        obj->unk12 = 0;
        return 0;
    }
    if ((obj->unkAB & 0xFU) == 8) {
        fn_80042CF8((Obj*)obj, 2);
        obj->unk11 = 2;
        return 1;
    }
    if ((obj->unkA0 & 0x200) && (obj->unkAB & 0xFU) == 2) {
        fn_80042CF8((Obj*)obj, 2);
        obj->unk11 = 3;
        return 1;
    }
    if (obj->unkA0 & 0x200) {
        fn_80042CF8((Obj*)obj, 2);
        obj->unk11 = 0;
        obj->unk12 = 0;
        return 1;
    }
    return 0;
}
