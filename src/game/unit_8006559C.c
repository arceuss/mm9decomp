#include "types.h"

typedef struct Unk8006559C {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x34 - 0x17];
    /* 0x34 */ void* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0xC8 - 0x70];
    /* 0xC8 */ u8 speedIdx;
} Unk8006559C;

extern void* lbl_804EE738;
extern const s16 lbl_802537E8[256];
extern s32 lbl_804ECBF8[2];

Unk8006559C* fn_800E8C44(void* pool);
void fn_80042DA0(Unk8006559C* obj, s32 id);

Unk8006559C* fn_8006559C(void* parent, s32 x, s32 y, u8 arg3, u8 speedIdx, u8 angle) {
    Unk8006559C* obj = fn_800E8C44(lbl_804EE738);

    if (obj != NULL) {
        fn_80042DA0(obj, 0x22);
        obj->parent = parent;
        obj->x = x;
        obj->y = y;
        obj->unk14 = arg3;
        obj->speedIdx = speedIdx;
        obj->unk16 = angle;
        angle += 0x80;
        obj->vx = lbl_804ECBF8[speedIdx] * lbl_802537E8[(u8)(angle + 0x40)] / 256;
        obj->vy = lbl_804ECBF8[obj->speedIdx] * lbl_802537E8[angle] / 256;
    }
    return obj;
}
