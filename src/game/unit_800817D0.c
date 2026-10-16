#include "types.h"
#include "game/work_8031BF70.h"

typedef struct Unk800817D0 {
    /* 0x000 */ u8 pad0[0x2C];
    /* 0x02C */ void* unk2C;
    /* 0x030 */ u8 pad30[0x114 - 0x30];
    /* 0x114 */ s8 unk114;
    /* 0x115 */ u8 pad115[0x138 - 0x115];
    /* 0x138 */ s32 unk138;
    /* 0x13C */ u8 pad13C[0x164 - 0x13C];
    /* 0x164 */ s32 unk164;
    /* 0x168 */ s32 unk168;
    /* 0x16C */ s32 unk16C;
    /* 0x170 */ s32 unk170;
} Unk800817D0;

void fn_800B63B0(void* obj, s32 left, s32 top, s32 right, s32 bottom);

void fn_800817D0(Unk800817D0* cam) {
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;

    if (cam->unk2C == NULL) {
        return;
    }
    left = 0;
    top = 0;
    right = 0x400000;
    bottom = 0x380000;
    if (cam->unk114 >= 4) {
        left = cam->unk164;
        top = cam->unk16C;
        right = cam->unk168;
        bottom = cam->unk170;
    } else if (cam->unk114 == 3) {
        left = cam->unk138 - 0x8000;
        right = cam->unk138 + 0x7FFF;
    }
    if (left < lbl_8031BF70.unk4AEC0) {
        left = lbl_8031BF70.unk4AEC0;
    }
    if (top < lbl_8031BF70.unk4AEC4) {
        top = lbl_8031BF70.unk4AEC4;
    }
    if (right > lbl_8031BF70.unk4AEC8) {
        right = lbl_8031BF70.unk4AEC8;
    }
    if (bottom > lbl_8031BF70.unk4AECC) {
        bottom = lbl_8031BF70.unk4AECC;
    }
    fn_800B63B0(cam->unk2C, left, top, right, bottom);
}
