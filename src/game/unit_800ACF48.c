#include "types.h"

typedef struct Unk800ACF48 {
    /* 0x000 */ u8 pad0[0x9];
    /* 0x009 */ u8 kind;
    /* 0x00A */ u8 padA[0x12 - 0xA];
    /* 0x012 */ u8 step;
    /* 0x013 */ u8 unk13;
    /* 0x014 */ u8 pad14[0x16 - 0x14];
    /* 0x016 */ u8 timer;
    /* 0x017 */ u8 pad17[0x68 - 0x17];
    /* 0x068 */ s32 vx;
    /* 0x06C */ s32 vy;
    /* 0x070 */ u8 pad70[0xDA - 0x70];
    /* 0x0DA */ u16 unkDA;
    /* 0x0DC */ u8 padDC[0xDE - 0xDC];
    /* 0x0DE */ u16 unkDE;
    /* 0x0E0 */ u8 padE0[0xEC - 0xE0];
    /* 0x0EC */ u8 unkEC;
    /* 0x0ED */ u8 prevStep;
    /* 0x0EE */ u8 prev13;
    /* 0x0EF */ u8 unkEF;
    /* 0x0F0 */ u8 padF0[0xFC - 0xF0];
    /* 0x0FC */ u8 anim;
    /* 0x0FD */ u8 padFD[0x104 - 0xFD];
    /* 0x104 */ u32 unk104;
} Unk800ACF48;

extern void** lbl_8027EB60[];

u32 fn_800B5828(Unk800ACF48* obj, s32 arg1);
void fn_800B9F74(Unk800ACF48* obj, void* anim);
void fn_800B7844(Unk800ACF48* obj);
void fn_800B4938(Unk800ACF48* obj, s32 speed, s32 arg2);

static inline void SetStep(Unk800ACF48* obj, u8 step) {
    obj->prevStep = obj->step;
    obj->step = step;
    obj->prev13 = obj->unk13;
    obj->unk13 = 0;
}

static inline void SetAnim(Unk800ACF48* obj, u8 anim) {
    obj->anim = anim;
    fn_800B9F74(obj, lbl_8027EB60[obj->kind][anim]);
}

void fn_800ACF48(Unk800ACF48* obj) {
    s32 speed = 0;
    u8 next;
    u32 ground;

    obj->unk104 &= ~3;
    switch (obj->step) {
    case 0:
        ground = obj->unkEF;
        obj->vy = 0;
        obj->unkDA = 0;
        obj->unkDE = 0;
        if (ground == 0) {
            ground = fn_800B5828(obj, 1);
        }
        next = 2;
        if (obj->unkEC == 0) {
            obj->timer = 7;
            speed = 0x100;
            next = 1;
            if (ground != 3) {
                SetAnim(obj, 1);
            }
        } else if (obj->unkEC == 4) {
            obj->vx = (obj->vx != 0 ? ((obj->vx >> 31) * 2 + 1) : 0) * 0x160;
        }
        SetStep(obj, next);
    case 1:
        if (obj->step == 1 && --obj->timer == 0) {
            SetStep(obj, 2);
        }
    case 2:
        if (obj->step == 2) {
            if (obj->unkEF != 3 && obj->anim != 2) {
                SetAnim(obj, 2);
            }
            speed = 0x160;
        }
        fn_800B7844(obj);
        fn_800B4938(obj, speed, 5);
        break;
    }
}
