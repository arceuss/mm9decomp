#include "types.h"

typedef struct Unk8007DA00Ops {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ void (*init)(void* work);
} Unk8007DA00Ops;

typedef struct Unk80304B90 {
    /* 0x000 */ struct Unk8007DA00Ops* ops;
    /* 0x004 */ u8 pad4[0x8 - 0x4];
    /* 0x008 */ void* unk8;
    /* 0x00C */ u8 padC[0x10 - 0xC];
    /* 0x010 */ u8 unk10[0x124 - 0x10];
    /* 0x124 */ u8 unk124;
    /* 0x125 */ u8 unk125;
    /* 0x126 */ u8 pad126[0x2D8 - 0x126];
    /* 0x2D8 */ u32 unk2D8;
    /* 0x2DC */ u8 pad2DC[0x300 - 0x2DC];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;

extern u8 lbl_802728D0[];
extern u8 lbl_80272830[];

void fn_8009C04C(s32 value, void* dst, s32 size);
void fn_800810FC(void* anim, void* player, s32 arg2);
BOOL fn_800B58F8(void* player, s32 arg1);
void fn_8008123C(void* anim, void* data);

void fn_8007DA00(s32 arg0) {
    Unk8007DA00Ops* ops = lbl_80304B90.ops;

    fn_8009C04C(0, lbl_80304B90.unk10, 0x114);
    lbl_80304B90.unk2D8 &= 0xFFFE;
    lbl_80304B90.unk2D8 &= 0xFFFD;
    lbl_80304B90.unk125 &= 0xFFFD;
    fn_800810FC(&lbl_80304B90.unk124, lbl_80304B90.unk8, arg0);
    ops->init(lbl_80304B90.unk10);
    if (!(lbl_80304B90.unk125 & 1)) {
        if (fn_800B58F8(lbl_80304B90.unk8, 2)) {
            fn_8008123C(&lbl_80304B90.unk124, lbl_802728D0);
        } else {
            fn_8008123C(&lbl_80304B90.unk124, lbl_80272830);
        }
    }
}
