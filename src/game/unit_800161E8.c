#include "types.h"
#include "game/work_8031BF70.h"

typedef struct Unk802638A0Entry {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk802638A0Entry;

typedef struct Unk800161E8Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk800161E8Pos;

typedef struct Unk800161E8Child {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u8 unk10;
} Unk800161E8Child;

typedef struct Unk800161E8 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x38 - 0x1C];
    /* 0x38 */ Unk800161E8Child* child;
    /* 0x3C */ u8 pad3C[0x60 - 0x3C];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
} Unk800161E8;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x125];
    /* 0x125 */ u8 unk125;
    /* 0x126 */ u8 pad126[0x2D8 - 0x126];
    /* 0x2D8 */ u32 unk2D8;
    /* 0x2DC */ u32 weapons;
    /* 0x2E0 */ u8 pad2E0[0x300 - 0x2E0];
} Unk80304B90;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 pad12[0x38 - 0x12];
} Unk803051D8;

extern Unk802638A0Entry* lbl_802638A0[];
extern Unk80304B90 lbl_80304B90;
extern Unk803051D8 lbl_803051D8;
extern void* lbl_804EE984;

void fn_800E9244(Unk800161E8* obj);
void fn_800C7770(void* player);
void fn_800C675C(s32 arg0);
void fn_800D56A4(s32 arg0);
void fn_80040D50(Unk800161E8Pos* pos);
BOOL fn_800B58F8(void* player, s32 arg1);
Unk800161E8Child* fn_8009CF58(s32 kind, Unk800161E8Pos* pos);

#define BIT(w, n) (((w) >> (n)) & 1)
#define HAS(w, n) (((w) & (1 << (n))) != 0)

void fn_800161E8(Unk800161E8* obj) {
    Unk800161E8Pos pos;
    u32 w;
    u32 m1;
    u32 m2;
    u32 m3;
    u32 m4;
    u32 m5;
    u32 m6;
    u32 m7;
    u32 m8;

    switch (obj->step) {
    case 0:
        fn_800E9244(obj);
        obj->flagsA &= ~1;
        if (!(lbl_80304B90.unk2D8 & 1)) {
            fn_800C7770(lbl_804EE984);
            if ((lbl_8031BF70.unk28C & 0x7F) != 0xC) {
                fn_800C675C(0x60);
            } else {
                fn_800C675C(0x20);
            }
        }
        fn_800D56A4(0xA);
        obj->step++;
        break;
    case 1:
        pos.x = obj->x;
        pos.y = obj->y;
        fn_80040D50(&pos);
        obj->child = NULL;
        if (!fn_800B58F8(lbl_804EE984, 2)) {
            w = lbl_80304B90.weapons;
            m1 = w & 0x2;
            m2 = w & 0x4;
            m3 = w & 0x8;
            m4 = w & 0x10;
            m5 = w & 0x20;
            m6 = w & 0x40;
            m7 = w & 0x80;
            m8 = w & 0x100;
            if (BIT(w, 1) + BIT(w, 2) + BIT(w, 3) + BIT(w, 4) + BIT(w, 5) + BIT(w, 6) + BIT(w, 7) + BIT(w, 8) == 3) {
                obj->child = fn_8009CF58(0, &pos);
            } else if ((m1 != 0) + (m2 != 0) + (m3 != 0) + (m4 != 0) + (m5 != 0) + (m6 != 0) + (m7 != 0) + (m8 != 0) == 7) {
                lbl_803051D8.unk11 = lbl_8031BF70.unk28C & 0x7F;
                obj->child = fn_8009CF58(1, &pos);
            }
        }
        obj->step++;
    case 2:
        if (obj->child != NULL) {
            if (obj->child->unk10 >= 2) {
                obj->child = NULL;
            }
            break;
        }
        if (!(lbl_80304B90.unk2D8 & 1)) {
            lbl_80304B90.unk2D8 |= 2;
        }
        obj->step++;
        break;
    case 3:
        lbl_80304B90.unk125 |= 2;
        lbl_80304B90.unk2D8 &= 0xFFFD;
        obj->unk18 = lbl_802638A0[obj->kind]->unk10;
        obj->unk10 = 4;
        obj->state = 0;
        obj->step = 0;
        obj->unk13 = 0;
        break;
    }
}
