#include "types.h"
#include "game/obj.h"

typedef struct Unk43794 {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 pad0B[5];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0x34 - 0x13];
    /* 0x34 */ struct Unk43794* unk34;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ u32 unk54hi : 21;
    /* 0x54 */ u32 unk54bit : 1;
    /* 0x54 */ u32 unk54lo : 10;
    /* 0x58 */ u8 pad58[8];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x7C - 0x68];
    /* 0x7C */ u8 unk7C;
} Unk43794;
extern void* lbl_804EE984;
s32 fn_800B58F8(void*, s32);
void fn_800E946C(Obj*, s32);
void fn_800E9A84(Obj*, s32);
void fn_800E9750(Obj*, u16);
void fn_80042D30(Obj*);

void fn_80043794(Unk43794* obj) {
    Unk43794* other = obj->unk34;
    switch (obj->unk12) {
    case 0:
        if (fn_800B58F8(lbl_804EE984, 2)) {
            fn_800E946C((Obj*)obj, 14);
        } else {
            fn_800E946C((Obj*)obj, 9);
        }
        fn_800E9A84((Obj*)obj, 0x144);
        obj->unk12++;
    case 1:
        if (other == 0) {
            fn_80042D30((Obj*)obj);
            break;
        }
        if (other->unk10 >= 2) {
            fn_80042D30((Obj*)obj);
            break;
        }
        if (fn_800B58F8(lbl_804EE984, 2)) {
            u8 anim = other->unk7C + 10;
            if (obj->unk7C != anim) {
                u32 flip;
                fn_800E946C((Obj*)obj, anim);
                flip = (other->unk0A >> 4) & 1;
                if (flip) {
                    obj->unk0A |= 0x10;
                } else {
                    obj->unk0A &= 0xEF;
                }
                obj->unk54bit = flip;
            }
        } else {
            u8 anim = other->unk7C + 5;
            if (obj->unk7C != anim) {
                u32 flip;
                fn_800E946C((Obj*)obj, anim);
                flip = (other->unk0A >> 4) & 1;
                if (flip) {
                    obj->unk0A |= 0x10;
                } else {
                    obj->unk0A &= 0xEF;
                }
                obj->unk54bit = flip;
            }
        }
        obj->unk60 = other->unk60;
        obj->unk64 = other->unk64;
        fn_800E9750((Obj*)obj, 0xFFFF);
        break;
    }
}
