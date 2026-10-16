#include "types.h"

typedef struct Unk80280390Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk80280390Entry;

typedef struct Unk800117B0 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 flagsB;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x20 - 0x1C];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 pad22[0x2A - 0x22];
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 pad2D;
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ u8 pad30[0x34 - 0x30];
    /* 0x34 */ struct Unk800117B0* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xAC - 0x68];
    /* 0xAC */ void (*unkAC)(void*);
    /* 0xB0 */ u8 padB0[0xC8 - 0xB0];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 padCD[0xE8 - 0xCD];
    /* 0xE8 */ s32 unkE8;
    /* 0xEC */ s32 unkEC;
} Unk800117B0;

extern Unk80280390Entry* lbl_802638A0[];

extern void (*lbl_804EC6B8[2])(Unk800117B0* obj);

void fn_800E9244(Unk800117B0* obj);
s32 fn_800EB16C(s32 dx, s32 dy);
void fn_800E9758(Unk800117B0* obj);

void fn_800117B0(Unk800117B0* obj) {
    s32 dx;
    s32 dy;
    s32 dist;
    s32 speed;
    s32 vx;
    s32 vy;

    switch (obj->step) {
    case 0:
        fn_800E9244(obj);
        obj->step++;
    case 1:
        dx = obj->unkE8 - obj->unk60;
        dy = obj->unkEC - obj->unk64;
        dist = fn_800EB16C(dx, dy);
        if (dist <= 0x800) {
            obj->unk18 = lbl_802638A0[obj->unk9]->unk8;
            obj->unk10 = 2;
            obj->unk13 = 0;
            obj->state = 1;
            obj->step = 0;
            lbl_804EC6B8[1](obj);
            break;
        }
        speed = 0x100 - (dist << 8) / 0x2000;
        if (speed < 0x40) {
            speed = 0x40;
        }
        vx = (dx << 8) / dist;
        vy = (dy << 8) / dist;
        speed = (speed << 10) / 256;
        obj->unk60 += vx * speed / 256;
        obj->unk64 += vy * speed / 256;
        fn_800E9758(obj);
        break;
    }
}
