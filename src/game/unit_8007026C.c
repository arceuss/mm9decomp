#include "types.h"

typedef struct Unk8007026CPos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk8007026CPos;

typedef struct Unk8007026C {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 pad13[0x16 - 0x13];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 shots;
    /* 0x18 */ u8 pad18[0x60 - 0x18];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x7C - 0x68];
    /* 0x7C */ u8 unk7C;
    /* 0x7D */ s8 unk7D;
    /* 0x7E */ s8 unk7E;
    /* 0x7F */ u8 pad7F[0x84 - 0x7F];
    /* 0x84 */ s32 wait;
    /* 0x88 */ u8 unk88[0xD0 - 0x88];
    /* 0xD0 */ s16 unkD0;
    /* 0xD2 */ u8 aim;
} Unk8007026C;

extern u8 lbl_802688C0[];
extern s16 lbl_802689C0[];
extern Unk8007026C* lbl_804EE984;
extern u32 lbl_804EE988;

void fn_800E946C(Unk8007026C* obj, u8 anim);
void fn_8009996C(void* arg0, void* arg1);
void fn_800E9750(Unk8007026C* obj, u16 arg1);
void fn_800E947C(Unk8007026C* obj, s32 anim, s32 arg2, s32 arg3);
void fn_8007D080(Unk8007026C* obj, Unk8007026CPos* pos, Unk8007026CPos* vel);
void fn_800D5234(s32 se);

void fn_8007026C(Unk8007026C* obj) {
    Unk8007026CPos pos;
    Unk8007026CPos vel;
    u32 rnd;
    u32 v;

    switch (obj->step) {
    case 0:
        obj->wait = 0x20;
        obj->step++;
    case 1:
        if (obj->unk7C != 2) {
            fn_800E946C(obj, 2);
        }
        fn_8009996C(obj->unk88, lbl_802688C0);
        obj->unkD0 = -0x2600;
        obj->step++;
    case 2:
        if (--obj->wait == 0) {
            obj->step++;
        } else if ((u32)(obj->x - lbl_804EE984->x + 0x6000) >= 0xC000) {
            obj->state = 3;
            obj->step = 0;
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 3:
        rnd = lbl_804EE988 * 0x343FD + 0x269EC3;
        lbl_804EE988 = rnd & 0x7FFFFFFF;
        obj->step++;
        obj->shots = 4;
        obj->aim = ((rnd >> 16) & 0x7FFF) % 12;
    case 4:
        fn_800E947C(obj, 3, obj->unk7D, obj->unk7E);
        v = obj->aim;
        pos.x = obj->x;
        pos.y = obj->y - 0x2E00;
        vel.x = lbl_802689C0[v];
        vel.y = -0x3E0;
        fn_8007D080(obj, &pos, &vel);
        rnd = lbl_804EE988 * 0x343FD + 0x269EC3;
        lbl_804EE988 = rnd & 0x7FFFFFFF;
        obj->aim = (v + 3 + ((rnd >> 16) & 1)) % 12;
        fn_800D5234(0x4B);
        obj->timer = 0x20;
        obj->step++;
    case 5:
        v = obj->timer;
        if (v - 1 == 0) {
            if (--obj->shots == 0) {
                obj->wait = 0x20;
                obj->step = 1;
            } else {
                obj->step = 4;
            }
        } else if (v - 1 <= 0x18 && obj->unk7C != 2) {
            fn_800E947C(obj, 2, obj->unk7D, obj->unk7E);
        }
        obj->timer = v - 1;
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
