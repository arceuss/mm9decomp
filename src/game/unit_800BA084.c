#include "types.h"

typedef struct Unk800BA084 {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 padA[0x1A];
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u8 pad26[0xD2];
    /* 0xF8 */ u32 unkF8;
} Unk800BA084;

extern u8* lbl_8027EB54[];

void fn_800E9424(Unk800BA084* obj, u16 v);
void fn_800E947C(Unk800BA084* obj, u8 a1, s8 a2, s8 a3);
void fn_800B68FC(Unk800BA084* obj, u32 a1, s32 a2);

void fn_800BA084(Unk800BA084* obj, u32 a1, s32 a2, s32 a3) {
    u16 v;

    obj->unkF8 = a1;
    v = ((u16*)lbl_8027EB54[obj->unk9])[(a1 >> 8) & 0xF];
    if (v != obj->unk24) {
        fn_800E9424(obj, v);
    }
    fn_800E947C(obj, a1, a2, a3);
    fn_800B68FC(obj, a1, a2);
}
