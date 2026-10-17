#include "types.h"

typedef struct Unk80012EB8 Unk80012EB8;

struct Unk80012EB8 {
    /* 0x000 */ u8 pad0[0x10];
    /* 0x010 */ u8 unk10;
    /* 0x011 */ u8 pad11;
    /* 0x012 */ u8 unk12;
    /* 0x013 */ u8 pad13[0x16 - 0x13];
    /* 0x016 */ u8 unk16;
    /* 0x017 */ u8 pad17[0xB6 - 0x17];
    /* 0x0B6 */ s16 unkB6;
    /* 0x0B8 */ s16 unkB8;
    /* 0x0BA */ u8 padBA[0xD8 - 0xBA];
    /* 0x0D8 */ Unk80012EB8* unkD8;
    /* 0x0DC */ Unk80012EB8* unkDC;
    /* 0x0E0 */ Unk80012EB8* unkE0;
    /* 0x0E4 */ Unk80012EB8* unkE4;
    /* 0x0E8 */ u8 padE8[0xEC - 0xE8];
    /* 0x0EC */ u8 unkEC;
    /* 0x0ED */ u8 unkED;
    /* 0x0EE */ u8 unkEE;
    /* 0x0EF */ u8 unkEF;
    /* 0x0F0 */ u8 unkF0;
    /* 0x0F1 */ u8 unkF1;
};

extern u8 lbl_80262380[];

void* fn_80063FA0(Unk80012EB8* obj, s32 x, s32 y, s32 arg3, s32 arg4, s32 arg5);

void fn_80012EB8(Unk80012EB8* obj) {
    switch (obj->unk12) {
    case 0:
        obj->unk16 = 0;
        obj->unk12++;
    case 1:
        if (obj->unkD8) {
            if (obj->unkD8->unk10 == 4) {
                obj->unkB8 = (u8)(obj->unkB6 - 2);
                obj->unkB6 = obj->unkB8;
                obj->unkD8 = 0;
                if (obj->unkF0 == 0) {
                    obj->unkF1++;
                } else {
                    obj->unkF1 = 0;
                }
                obj->unkF0 = 0;
            }
        } else if (obj->unkF1 < 2 && obj->unk16 < 0xA) {
            obj->unkEC = 1;
            obj->unkD8 = fn_80063FA0(obj, 0xCE000, 0x10000, 1, lbl_80262380[obj->unk16], 0);
            obj->unk16++;
        }
        if (obj->unkDC) {
            if (obj->unkDC->unk10 == 4) {
                obj->unkB8 = (u8)(obj->unkB6 - 2);
                obj->unkB6 = obj->unkB8;
                obj->unkDC = 0;
                if (obj->unkF0 == 1) {
                    obj->unkF1++;
                } else {
                    obj->unkF1 = 0;
                }
                obj->unkF0 = 1;
            }
        } else if (obj->unkF1 < 2 && obj->unk16 < 0xA) {
            obj->unkED = 1;
            obj->unkDC = fn_80063FA0(obj, 0xCE000, 0x13000, 1, lbl_80262380[obj->unk16], 1);
            obj->unk16++;
        }
        if (obj->unkE0) {
            if (obj->unkE0->unk10 == 4) {
                obj->unkB8 = (u8)(obj->unkB6 - 2);
                obj->unkB6 = obj->unkB8;
                obj->unkE0 = 0;
                if (obj->unkF0 == 2) {
                    obj->unkF1++;
                } else {
                    obj->unkF1 = 0;
                }
                obj->unkF0 = 2;
            }
        } else if (obj->unkF1 < 2 && obj->unk16 < 0xA) {
            obj->unkEE = 1;
            obj->unkE0 = fn_80063FA0(obj, 0xCE000, 0x16000, 1, lbl_80262380[obj->unk16], 2);
            obj->unk16++;
        }
        if (obj->unkE4) {
            if (obj->unkE4->unk10 == 4) {
                obj->unkB8 = (u8)(obj->unkB6 - 2);
                obj->unkB6 = obj->unkB8;
                obj->unkE4 = 0;
                if (obj->unkF0 == 3) {
                    obj->unkF1++;
                } else {
                    obj->unkF1 = 0;
                }
                obj->unkF0 = 3;
            }
        } else if (obj->unkF1 < 2 && obj->unk16 < 0xA) {
            obj->unkEF = 1;
            obj->unkE4 = fn_80063FA0(obj, 0xCE000, 0x19000, 1, lbl_80262380[obj->unk16], 3);
            obj->unk16++;
        }
        break;
    }
}
