#include "types.h"

typedef struct Unk80059474Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk80059474Pos;

typedef struct Unk80059474 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 pad18[0x60 - 0x18];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ u8 pad6C[0x7D - 0x6C];
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 pad7E[0x88 - 0x7E];
    /* 0x88 */ u8 unk88[0xC8 - 0x88];
    /* 0xC8 */ u8 facing;
    /* 0xC9 */ u8 shot;
    /* 0xCA */ u8 padCA[0xCC - 0xCA];
    /* 0xCC */ s32 homeX;
} Unk80059474;

extern u8 lbl_80266BC0[];
extern Unk80059474* lbl_804EE984;
extern s32 lbl_804ECAC0[2];
extern s32 lbl_804ECAC8[2];
extern s32 lbl_804ECAD0[2];
extern s32 lbl_804ECAD8[2];

void fn_800E946C(Unk80059474* obj, s32 arg1);
void fn_8009996C(void* arg0, void* arg1);
void fn_800E9750(Unk80059474* obj, u16 arg1);
void fn_800780B4(Unk80059474Pos* pos, s32 kind, u8 angle, s32 arg3);

static inline void Shoot(Unk80059474* obj, s32 dx, s32 dy, s32 angle, s32 kind) {
    Unk80059474Pos pos;

    pos.x = obj->x + dx * ((lbl_804EE984->x - obj->x > 0) * 2 - 1);
    pos.y = obj->y - dy;
    fn_800780B4(&pos, kind, angle * ((lbl_804EE984->x - obj->x > 0) * 2 - 1) + 0x40, 0);
}

void fn_80059474(Unk80059474* obj) {
    s32 dx;
    s32 diff;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 1);
        obj->timer = 0x2A;
        fn_8009996C(obj->unk88, lbl_80266BC0);
        diff = lbl_804EE984->x - obj->x;
        dx = lbl_804ECAC0[obj->shot];
        obj->vx = 0;
        obj->facing = diff > 0;
        Shoot(obj, dx, lbl_804ECAC8[obj->shot], lbl_804ECAD0[obj->shot], lbl_804ECAD8[obj->shot]);
        if (obj->shot == 0) {
            obj->shot = 1;
        } else {
            obj->shot = 0;
        }
        obj->homeX = obj->x;
        obj->unk7D = 1;
        obj->unk17 = 0;
        obj->step++;
    case 1:
        fn_800E9750(obj, 0xFFFF);
        if (--obj->timer == 0) {
            obj->x = obj->homeX;
            obj->state = 0;
            obj->step = 0;
        }
        break;
    }
}
