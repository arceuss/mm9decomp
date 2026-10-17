#include "types.h"

typedef struct Unk802819B0Entry {
    /* 0x0 */ u8 pad0[0xC];
    /* 0xC */ s32 unkC;
} Unk802819B0Entry;

extern Unk802819B0Entry* lbl_802819B0[];

typedef struct Unk800E47B4 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
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
    /* 0x1C */ u8 pad1C[0x2E - 0x1C];
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ u8 pad30[0x32 - 0x30];
    /* 0x32 */ s16 unk32;
    /* 0x34 */ struct Unk800E47B4Parent* parent;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
} Unk800E47B4;

typedef struct Unk800E47B4Parent {
    /* 0x0000 */ u8 pad0[0x100E];
    /* 0x100E */ u8 unk100E;
    /* 0x100F */ u8 pad100F;
    /* 0x1010 */ s32 unk1010;
    /* 0x1014 */ s32 unk1014;
    /* 0x1018 */ u8 pad1018[0x227C - 0x1018];
    /* 0x227C */ u8 unk227C;
} Unk800E47B4Parent;

typedef struct Unk802817E0Entry {
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
} Unk802817E0Entry;

extern Unk802817E0Entry lbl_802817E0[];
extern u8 lbl_8027EBA8[][0x10];
extern u8 lbl_8027ECD8[];

typedef struct Unk8037CC40Slot {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ u8 unk8;
    /* 0x9 */ u8 pad9[0x10 - 0x9];
} Unk8037CC40Slot;

typedef struct Unk8037CC40 {
    /* 0x0000 */ u8 pad0[0x1618];
    /* 0x1618 */ Unk8037CC40Slot slots[(0x1FDC - 0x1618) / 0x10];
    /* 0x1FD8 */ u8 pad1FD8[0x1FDC - 0x1FD8];
    /* 0x1FDC */ u8 unk1FDC;
} Unk8037CC40;

extern Unk8037CC40 lbl_8037CC40;
extern u8 lbl_803051D8[];

void fn_800E9A84(Unk800E47B4* obj, s32 id);
void fn_800E9424(Unk800E47B4* obj, u16 anim);
void fn_800E9474(Unk800E47B4* obj, u8 anim);
void fn_800E9750(Unk800E47B4* obj, u16 arg1);
void fn_800E9AA0(Unk800E47B4* obj, s32 a, s32 b);
void fn_800E9CB8(Unk800E47B4* obj);
void fn_800E9C90(Unk800E47B4* obj);
void fn_800BAFDC(void* src, u32 dst, s32 size);

static inline Unk8037CC40Slot* Slot(u8 idx) {
    Unk8037CC40Slot* p = NULL;

    if (idx != 0xFF) {
        p = &lbl_8037CC40.slots[idx];
    }
    return p;
}

void fn_800E47B4(Unk800E47B4* obj) {
    Unk800E47B4Parent* parent = obj->parent;
    s32 px = parent->unk1010;
    s32 py = parent->unk1014;

    switch (obj->step) {
    case 0:
        obj->unk17 = lbl_802817E0[obj->unk15].unk2;
        if (obj->unk15 == 0x23) {
            obj->unk2F = 1;
        } else if (obj->unk15 == 0x1A) {
            u32 v = 0;

            if (parent->unk227C == 1) {
                obj->unk17 = 0x15;
                v = 0x10;
            }
            fn_800E9A84(obj, 0x144);
            {
                u8* src = lbl_8027EBA8[v];
                u8 b2 = lbl_8037CC40.unk1FDC;
                u32 n;

                if (Slot(b2) != NULL) {
                    n = Slot(b2)->unk8;
                } else {
                    n = 0;
                }
                fn_800BAFDC(src, (n << 5) + 0x200, 8);
            }
            {
                u8* src = lbl_8027ECD8;
                u8 b2 = lbl_8037CC40.unk1FDC;
                u32 n;

                if (Slot(b2) != NULL) {
                    n = Slot(b2)->unk8;
                } else {
                    n = 0;
                }
                fn_800BAFDC(src, (n << 5) + 0x208, 8);
            }
        } else if (obj->unk15 == 0x18) {
            if (parent->unk227C == 1) {
                obj->unk17 = 9;
            } else if (lbl_803051D8[3] & 0x20) {
                obj->unk17 = 0xF;
            }
        }
        fn_800E9424(obj, lbl_802817E0[obj->unk15].unk0);
        fn_800E9474(obj, obj->unk17);
        obj->unk2E = (lbl_802817E0[obj->unk15].unk3 & 0xF) + 0x10;
        obj->unk2F = lbl_802817E0[obj->unk15].unk3 >> 4;
        if (obj->unk15 == 0x25) {
            fn_800E9AA0(obj, 0, 0);
        }
        obj->step++;
    case 1:
        if (parent->unk100E == 1) {
            obj->step++;
        }
        break;
    case 2:
        fn_800E9474(obj, obj->unk17 + 1);
        obj->step++;
    case 3:
        if (parent->unk100E == 2) {
            obj->step++;
        }
        break;
    case 4:
        fn_800E9474(obj, obj->unk17 + 2);
        obj->step++;
    case 5:
        if (parent->unk100E == 3) {
            fn_800E9CB8(obj);
            obj->unkA &= ~1;
            obj->unkA &= 0xFD;
            obj->unk18 = lbl_802819B0[obj->unk9]->unkC;
            obj->unk10 = 3;
            obj->state = 0;
            obj->step = 0;
            obj->unk13 = 0;
            return;
        }
        break;
    }
    obj->unk60 = px;
    obj->unk60 = px + (lbl_802817E0[obj->unk15].unk4 << 8);
    obj->unk64 = py;
    obj->unk64 = py + (lbl_802817E0[obj->unk15].unk6 << 8);
    fn_800E9750(obj, obj->unk32);
    if (obj->unk15 == 0x25) {
        fn_800E9C90(obj);
    }
}
