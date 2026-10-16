#include "types.h"

typedef struct Unk800ACCBC {
    /* 0x000 */ u8 pad0[0x9];
    /* 0x009 */ u8 kind;
    /* 0x00A */ u8 padA[0x12 - 0xA];
    /* 0x012 */ u8 step;
    /* 0x013 */ u8 unk13;
    /* 0x014 */ u8 player;
    /* 0x015 */ u8 pad15[0x68 - 0x15];
    /* 0x068 */ s32 vx;
    /* 0x06C */ s32 vy;
    /* 0x070 */ u8 pad70[0x7F - 0x70];
    /* 0x07F */ u8 unk7F;
    /* 0x080 */ u8 pad80[0xD8 - 0x80];
    /* 0x0D8 */ u16 unkD8;
    /* 0x0DA */ u16 unkDA;
    /* 0x0DC */ u16 unkDC;
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
    /* 0x108 */ u8 pad108[0x138 - 0x108];
    /* 0x138 */ s32 idle;
} Unk800ACCBC;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x2A0];
    /* 0x2A0 */ u16 buttons[(0x300 - 0x2A0) / 2];
} Unk80304B90;

typedef struct Unk8038DC58 {
    /* 0x00 */ u8 pad0[0x15];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x128 - 0x16];
} Unk8038DC58;

extern void** lbl_8027EB60[];
extern Unk80304B90 lbl_80304B90;
extern Unk8038DC58 lbl_8038DC58;

u32 fn_800B5828(Unk800ACCBC* obj, s32 arg1);
void fn_800B9F74(Unk800ACCBC* obj, void* anim);
void fn_800B4938(Unk800ACCBC* obj, s32 speed, s32 arg2);

static inline void SetStep(Unk800ACCBC* obj, u8 step) {
    obj->prevStep = obj->step;
    obj->step = step;
    obj->prev13 = obj->unk13;
    obj->unk13 = 0;
}

static inline void SetAnim(Unk800ACCBC* obj, u8 anim) {
    obj->anim = anim;
    fn_800B9F74(obj, lbl_8027EB60[obj->kind][anim]);
}

void fn_800ACCBC(Unk800ACCBC* obj) {
    u32 ground;

    obj->unk104 &= ~3;
    switch (obj->step) {
    case 0:
        ground = obj->unkEF;
        obj->vy = 0;
        obj->unkD8 = 0;
        obj->unkDA = 0;
        obj->unkDC = 0;
        obj->unkDE = 0;
        obj->idle = 0;
        if (ground == 0) {
            ground = fn_800B5828(obj, 0);
        }
        if (obj->unkEC == 4) {
            obj->vx = (obj->vx != 0 ? ((obj->vx >> 31) * 2 + 1) : 0) * 0x160;
        }
        if (ground == 3) {
            SetStep(obj, 2);
        } else if (obj->anim == 1 || obj->anim == 4) {
            SetStep(obj, 1);
        } else {
            SetStep(obj, 2);
            SetAnim(obj, 0);
        }
    case 1:
        if (obj->unkEF == 3) {
            SetStep(obj, 2);
        } else if (obj->anim != 0 && obj->unk7F == 3) {
            SetStep(obj, 2);
            SetAnim(obj, 0);
        }
    case 2:
        if (obj->unkEF != 3 && obj->anim != 0) {
            SetAnim(obj, 0);
        }
        fn_800B4938(obj, 0, 5);
        if (!(lbl_80304B90.buttons[obj->player] & 0x8000)) {
            obj->idle++;
        }
        if (obj->idle >= 0x78) {
            lbl_8038DC58.unk15 |= 0x10;
        }
        break;
    }
}
