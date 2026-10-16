#include "types.h"

typedef struct Unk800AF4D0 {
    /* 0x000 */ u8 pad0[0x9];
    /* 0x009 */ u8 kind;
    /* 0x00A */ u8 flagsA;
    /* 0x00B */ u8 padB[0x12 - 0xB];
    /* 0x012 */ u8 step;
    /* 0x013 */ u8 unk13;
    /* 0x014 */ u8 pad14[0x54 - 0x14];
    /* 0x054 */ u32 unk54_hi : 20;
    /* 0x054 */ u32 flipX : 1;
    /* 0x054 */ u32 unk54_lo : 11;
    /* 0x058 */ u8 pad58[0x64 - 0x58];
    /* 0x064 */ s32 y;
    /* 0x068 */ u8 pad68[0x6C - 0x68];
    /* 0x06C */ s32 unk6C;
    /* 0x070 */ u8 pad70[0xD8 - 0x70];
    /* 0x0D8 */ u16 unkD8;
    /* 0x0DA */ u16 unkDA;
    /* 0x0DC */ u16 unkDC;
    /* 0x0DE */ u16 unkDE;
    /* 0x0E0 */ u8 padE0[0xED - 0xE0];
    /* 0x0ED */ u8 prevStep;
    /* 0x0EE */ u8 prev13;
    /* 0x0EF */ u8 padEF[0xFC - 0xEF];
    /* 0x0FC */ u8 anim;
    /* 0x0FD */ u8 padFD[0x104 - 0xFD];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 pad108[0x115 - 0x108];
    /* 0x115 */ u8 unk115;
    /* 0x116 */ u8 pad116[0x12C - 0x116];
    /* 0x12C */ s32 baseY;
    /* 0x130 */ u16 radius;
    /* 0x132 */ u16 angle;
} Unk800AF4D0;

extern void** lbl_8027EB60[];

void fn_800D5234(s32 se);
void fn_800B9F74(Unk800AF4D0* obj, void* anim);

static inline void SetStep(Unk800AF4D0* obj, u8 step) {
    obj->prevStep = obj->step;
    obj->step = step;
    obj->prev13 = obj->unk13;
    obj->unk13 = 0;
}

void fn_800AF4D0(Unk800AF4D0* obj) {
    u32 flip;
    u32 anim;

    obj->unk104 &= ~3;
    switch (obj->step) {
    case 0:
        obj->unk6C = 0;
        obj->unkD8 = 0;
        obj->unkDA = 0;
        obj->unkDC = 0;
        obj->unkDE = 0;
        SetStep(obj, 1);
    case 1:
        if (obj->unk115 & 1) {
            fn_800D5234(0xF);
        }
        if (obj->angle < 0x1600) {
            anim = 0xE;
            flip = 0;
        } else if (obj->angle < 0x4000) {
            anim = 0xF;
            flip = 0;
        } else if (obj->angle < 0x6A00) {
            anim = 0x10;
            flip = 1;
        } else if (obj->angle < 0x9600) {
            anim = 0x11;
            flip = 1;
        } else if (obj->angle < 0xC000) {
            anim = 0x12;
            flip = 1;
        } else if (obj->angle < 0xEA00) {
            anim = 0x13;
            flip = 0;
        } else {
            anim = 0xE;
            flip = 0;
        }
        obj->y = obj->radius * (flip * 2 - 1) + obj->baseY;
        if (anim != obj->anim) {
            obj->anim = anim;
            fn_800B9F74(obj, lbl_8027EB60[obj->kind][anim]);
        }
        if (flip != ((obj->flagsA >> 5) & 1)) {
            obj->flipX = flip;
            if (obj->flipX) {
                obj->flagsA |= 0x20;
            } else {
                obj->flagsA &= 0xDF;
            }
        }
        break;
    }
}
