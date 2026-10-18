#include "types.h"

typedef struct Unk800E9AA0Slot {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ u8 unk8;
    /* 0x9 */ u8 pad9[0x10 - 0x9];
} Unk800E9AA0Slot;

typedef struct Unk8037CC40 {
    /* 0x0000 */ u8 pad0[0x1618];
    /* 0x1618 */ Unk800E9AA0Slot slots[(0x1E98 - 0x1618) / 0x10];
    /* 0x1E98 */ u8 index[0x100];
} Unk8037CC40;

typedef struct Unk800E9AA0Info {
    /* 0x0 */ u8 pad0[0xA];
    /* 0xA */ u16 unkA;
} Unk800E9AA0Info;

typedef struct Unk800E9AA0Bank {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ u32 off8;
    /* 0xC */ u32 offC;
} Unk800E9AA0Bank;

typedef struct Unk80383E70 {
    /* 0x0000 */ u8 pad0[0x4];
    /* 0x0004 */ Unk800E9AA0Info* info[0x200];
    /* 0x0804 */ Unk800E9AA0Bank* bank[0x200];
} Unk80383E70;

typedef struct Unk800E9AA0 {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s8 unk8;
    /* 0x09 */ u8 pad9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 unkD;
    /* 0x0E */ u8 unkE;
    /* 0x0F */ u8 padF[0x20 - 0xF];
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 pad21[0x24 - 0x21];
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u16 unk26;
    /* 0x28 */ u8 pad28[0x2C - 0x28];
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 unk2D;
} Unk800E9AA0;

extern Unk8037CC40 lbl_8037CC40;
extern Unk80383E70 lbl_80383E70;

void fn_800BB4E8(s32 id, s32 a, void* seq, void* bank, u32 size, s32 b, s32 c, void* base);

static inline Unk800E9AA0Slot* Slot(u8 idx) {
    Unk800E9AA0Slot* p = NULL;

    if (idx != 0xFF) {
        p = &lbl_8037CC40.slots[idx];
    }
    return p;
}

void fn_800E9AA0(Unk800E9AA0* obj, s32 a, s32 b) {
    u16 id;
    u16 key;
    u8 vol;
    u8 n;
    Unk800E9AA0Bank* bank;

    if (!(obj->unkA & 8)) {
        return;
    }
    id = obj->unk24;
    key = obj->unk26;
    if (obj->unkB & 8) {
        vol = 0;
    } else if (!(obj->unkB & 0x40)) {
        if (obj->unkC & 1) {
        key = obj->unkD | (obj->unkE << 8);
        {
            u8 c = obj->unk2C;
            u8 b2 = lbl_8037CC40.index[key];
            u32 m;

            if (Slot(b2) != NULL) {
                m = Slot(b2)->unk8;
            } else {
                m = 0;
            }
            vol = c + m;
        }
    } else {
        {
            u8 c = obj->unk2C;
            u8 b2 = lbl_8037CC40.index[key];
            u32 m;

            if (Slot(b2) != NULL) {
                m = Slot(b2)->unk8;
            } else {
                m = 0;
            }
            vol = c + m;
        }
        }
    } else {
        vol = obj->unk2D;
    }
    bank = lbl_80383E70.bank[id];
    if (((lbl_80383E70.info[id]->unkA >> 5) & 0xFF) == 4) {
        fn_800BB4E8((obj->unk8 << 8) | obj->unk20, a, (u8*)bank + bank->off8, (u8*)bank + bank->offC + 4,
                    (vol << 5) + 0x200, b, obj->unk8, bank);
    } else {
        fn_800BB4E8((obj->unk8 << 8) | obj->unk20, a, (u8*)bank + bank->off8, (u8*)bank + bank->offC + 4,
                    (vol << 9) + 0x20000000, b, obj->unk8, bank);
    }
    obj->unkC |= 2;
}
