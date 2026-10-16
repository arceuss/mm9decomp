#include "types.h"

typedef struct Unk8027F228Obj {
    /* 0x0 */ u8 pad0[8];
    /* 0x8 */ u32 unk8;
    /* 0xC */ u8 padC[4];
    /* 0x10 */ u32 unk10;
} Unk8027F228Obj;

typedef struct Unk803051D8 {
    /* 0x0 */ u8 pad0[2];
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 pad3[0xB - 0x3];
    /* 0xB */ u8 unkB;
} Unk803051D8;

extern Unk803051D8 lbl_803051D8;
extern Unk8027F228Obj* lbl_8027F228[];
extern u8 lbl_80304B90[];

u32 fn_80080484(u8* a, u8* b, int c);
void fn_800E9244(u8* obj);

int fn_800C24C0(u8* obj) {
    if ((lbl_803051D8.unk2 & 0x20) != 0) {
        *(u32*)(obj + 0x18) = lbl_8027F228[obj[9]]->unk8;
        obj[0x10] = 2;
        obj[0x11] = 0;
        obj[0x12] = 0;
        obj[0x13] = 0;
        if (obj[0xCB] == 0) {
            lbl_803051D8.unkB++;
        }
        *(u32*)(obj + 0x18) = lbl_8027F228[obj[9]]->unk10;
        obj[0x10] = 4;
        obj[0x11] = 0;
        obj[0x12] = 0;
        obj[0x13] = 0;
        fn_800E9244(obj);
        obj[0xA] &= ~1;
        return 1;
    }
    if (fn_80080484(lbl_80304B90 + 0x21C, obj + 0x60, 1) > 0x1000) {
        *(u32*)(obj + 0x18) = lbl_8027F228[obj[9]]->unk8;
        obj[0x10] = 2;
        obj[0x11] = 0;
        obj[0x12] = 0;
        obj[0x13] = 0;
        if (obj[0xCB] == 0) {
            lbl_803051D8.unkB++;
        }
        *(u32*)(obj + 0x18) = lbl_8027F228[obj[9]]->unk10;
        obj[0x10] = 4;
        obj[0x11] = 0;
        obj[0x12] = 0;
        obj[0x13] = 0;
        fn_800E9244(obj);
        obj[0xA] &= ~1;
        return 1;
    }
    return 0;
}
