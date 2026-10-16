#include "types.h"

typedef struct Unk8001A638 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x18 - 0x15];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ struct Unk8001A638* parent;
    /* 0x38 */ u8 pad38[0xA0 - 0x38];
    /* 0xA0 */ u32 hitFlags;
    /* 0xA4 */ u8 padA4[0xB6 - 0xA4];
    /* 0xB6 */ s16 hp;
} Unk8001A638;

extern void** lbl_802638A0[];
extern void (*lbl_804EC798[2])(Unk8001A638* obj);
extern void (*lbl_80262B00[])(Unk8001A638* obj);
extern void (*lbl_80262B14[])(Unk8001A638* obj);

void fn_800E9244(Unk8001A638* obj);
void fn_800C75D0(void);
void fn_800E9C90(Unk8001A638* obj);

static inline void SetMode(Unk8001A638* obj, u8 mode) {
    obj->unk18 = lbl_802638A0[obj->kind][mode];
    obj->unk10 = mode;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

static inline BOOL CheckDead(Unk8001A638* obj) {
    if ((obj->hitFlags & 0x200) || obj->hp == 0) {
        obj->unk18 = lbl_802638A0[obj->kind][2];
        obj->unk10 = 2;
        obj->unk13 = 0;
        obj->state = 0;
        obj->step = 0;
        return TRUE;
    }
    return FALSE;
}

void fn_8001A638(Unk8001A638* obj) {
    if (obj->unk14 == 1 && obj->parent->unk10 >= 2) {
        obj->flagsA &= ~1;
        obj->flagsA &= 0xFD;
        fn_800E9244(obj);
        SetMode(obj, 3);
        return;
    }
    if (obj->state != 0 && obj->unk14 != 1) {
        fn_800C75D0();
        if (CheckDead(obj)) {
            if (obj->unk14 == 1 && obj->parent->unk10 >= 2) {
                obj->flagsA &= ~1;
                obj->flagsA &= 0xFD;
                fn_800E9244(obj);
                SetMode(obj, 3);
                return;
            }
            lbl_804EC798[obj->state](obj);
            return;
        }
    }
    lbl_80262B00[obj->state](obj);
    lbl_80262B14[obj->state](obj);
    if (obj->unk14 == 0) {
        fn_800E9C90(obj);
    }
}
