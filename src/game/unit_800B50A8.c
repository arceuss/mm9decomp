#include "types.h"

typedef struct UnkB50A8 {
    /* 0x000 */ u8 pad000[0x9];
    /* 0x009 */ u8 unk009;
    /* 0x00A */ u8 pad00A[0x14 - 0xA];
    /* 0x014 */ u8 unk014;
    /* 0x015 */ u8 pad015[0x60 - 0x15];
    /* 0x060 */ u8 unk060[0x6C - 0x60];
    /* 0x06C */ s32 vy;
    /* 0x070 */ u8 pad070[0x74 - 0x70];
    /* 0x074 */ s32 ay;
    /* 0x078 */ u8 pad078[0xD8 - 0x78];
    /* 0x0D8 */ s16 unk0D8;
    /* 0x0DA */ u8 pad0DA[0xDC - 0xDA];
    /* 0x0DC */ s16 unk0DC;
    /* 0x0DE */ u8 pad0DE[0xE0 - 0xDE];
    /* 0x0E0 */ s16 unk0E0;
    /* 0x0E2 */ u8 pad0E2[0xE6 - 0xE2];
    /* 0x0E6 */ s16 unk0E6;
    /* 0x0E8 */ s32 unk0E8;
    /* 0x0EC */ u8 unk0EC;
    /* 0x0ED */ u8 pad0ED[0xEF - 0xED];
    /* 0x0EF */ u8 unk0EF;
    /* 0x0F0 */ u8 pad0F0[0xFC - 0xF0];
    /* 0x0FC */ u8 unk0FC;
    /* 0x0FD */ u8 pad0FD[0x104 - 0xFD];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 pad108[0x120 - 0x108];
    /* 0x120 */ u8 unk120;
    /* 0x121 */ u8 pad121;
    /* 0x122 */ u8 unk122;
    /* 0x123 */ u8 unk123;
    /* 0x124 */ u8 pad124[0x18C - 0x124];
    /* 0x18C */ u16 unk18C;
    /* 0x18E */ u8 pad18E[0x19C - 0x18E];
    /* 0x19C */ u32 unk19C;
    /* 0x1A0 */ u8 pad1A0[0x1E0 - 0x1A0];
    /* 0x1E0 */ u16 unk1E0;
    /* 0x1E2 */ u8 pad1E2[0x1F3 - 0x1E2];
    /* 0x1F3 */ u8 unk1F3;
    /* 0x1F4 */ u8 unk1F4;
} UnkB50A8;

typedef struct Unk8027EB60 {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ u32 unkC;
} Unk8027EB60;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x2A0];
    /* 0x2A0 */ u16 unk2A0[4];
} Unk80304B90;

typedef struct Unk8038DC58 {
    /* 0x00 */ u8 pad0[0x1D];
    /* 0x1D */ u8 unk1D;
} Unk8038DC58;

extern Unk8027EB60* lbl_8027EB60[];
extern Unk80304B90 lbl_80304B90;
extern u8 lbl_8027F3D8[];
extern Unk8038DC58 lbl_8038DC58;

void fn_800B7844(UnkB50A8* obj);
void fn_800B9F74(UnkB50A8* obj, u32 anim);
s32 fn_800B9458(void* pos, u32 box, s32 arg2);
s32 fn_800A80C0(s32 v, s32 a, s32 b);

static inline void Jump(UnkB50A8* obj, s32 vy) {
    obj->vy = vy;
    obj->ay = 0x40;
    if (obj->unk0EF != 3) {
        obj->unk0FC = 3;
        fn_800B9F74(obj, lbl_8027EB60[obj->unk009]->unkC);
    }
}

s32 fn_800B50A8(UnkB50A8* obj) {
    s32 t;
    s32 m;
    s32 jump;
    s32 p;
    s32 a;
    s32 s;
    s32 vy;
    s32 g;
    s32 w;
    s32 r;

    obj->unk0D8 = 0x160;
    if ((s32)obj->unk120 >= 100) {
        t = 0;
    } else {
        t = 0x160 - obj->unk120 * 0x160 / 100;
    }
    obj->unk0DC = t;
    obj->unk0E0 = t;
    fn_800B7844(obj);
    if (((1 << obj->unk0EC) & 0x13) && ((obj->unk1E0 & 0xF) || (u32)(obj->unk1E0 & 0x40) == 0x40)) {
        if (obj->unk0E6 < 0) {
            Jump(obj, obj->unk0E6);
            return 1;
        }
        if (obj->unk104 & 0x8000) {
            jump = 0;
        } else {
            m = 0x20;
            if (lbl_80304B90.unk2A0[obj->unk014] & 0x8000) {
                m = 0x100;
            }
            jump = (obj->unk18C & m) ? m : 0;
        }
        if (jump) {
            lbl_8038DC58.unk1D = (lbl_8038DC58.unk1D < lbl_8027F3D8[1] - 1) ? lbl_8038DC58.unk1D + 1 : lbl_8027F3D8[1];
            if ((s32)obj->unk120 >= 100) {
                s = 0;
            } else {
                if ((s32)obj->unk1F3 < 0x32) {
                    p = obj->unk1F3 * 100 / 50;
                } else {
                    p = 100;
                }
                a = 0x500 - obj->unk120 * 0x500 / 100;
                s = a * (100 - p * 0x4B / 100) / 100;
                if ((u32)(0x40 - s) <= 0x80) {
                    s = 0x40;
                }
            }
            Jump(obj, -s);
            return 1;
        }
    }
    vy = obj->vy;
    obj->unk1F4 = fn_800B9458(obj->unk060, obj->unk19C, 0);
    g = obj->unk122;
    w = obj->unk123;
    if (g > w) {
        g = w;
    }
    g = (g << 6) / 100;
    w = obj->unk1F4;
    if (w != 0) {
        w = 100;
    }
    if (g < 0) {
        a = g * 100 / (100 - w * 65 / 100);
    } else {
        a = g * (100 - w * 65 / 100) / 100;
    }
    if (a == 0) {
        a = 1;
    }
    obj->ay = a + obj->unk0E6;
    vy += obj->ay;
    obj->vy = vy;
    r = fn_800A80C0(vy, 0x700, 0x700);
    if (obj->unk0E8 != 0 && r < -obj->unk0E8) {
        r = -obj->unk0E8;
    }
    obj->vy = r;
    return 0;
}
