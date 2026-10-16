#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk80081260Obj {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 pad11[0x60 - 0x11];
    /* 0x60 */ Vec2i pos;
} Unk80081260Obj;

typedef struct Unk80081260Slot {
    /* 0x0 */ Unk80081260Obj* obj;
    /* 0x4 */ u8 pad4[0x10 - 0x4];
} Unk80081260Slot;

typedef struct Unk80081260 {
    /* 0x000 */ u8 pad0;
    /* 0x001 */ u8 flags1;
    /* 0x002 */ u8 pad2[0x2C - 0x2];
    /* 0x02C */ Unk80081260Slot slots[(0xEC - 0x2C) / 0x10];
    /* 0x0EC */ u32 frame;
    /* 0x0F0 */ u8 padF0[0xF5 - 0xF0];
    /* 0x0F5 */ u8 flagsF5;
    /* 0x0F6 */ u16 inputMode;
    /* 0x0F8 */ u8 padF8[0x138 - 0xF8];
    /* 0x138 */ Vec2i unk138;
    /* 0x140 */ u8 pad140[0x174 - 0x140];
    /* 0x174 */ u16 prevPad;
    /* 0x176 */ u8 pad176[0x17C - 0x176];
    /* 0x17C */ u16 pad;
    /* 0x17E */ u8 pad17E[0x184 - 0x17E];
    /* 0x184 */ u16 trig;
    /* 0x186 */ u8 pad186[0x18C - 0x186];
    /* 0x18C */ s32 unk18C;
    /* 0x190 */ u8 pad190[0x192 - 0x190];
    /* 0x192 */ u16 unk192;
    /* 0x194 */ Unk80081260Obj* unk194;
    /* 0x198 */ u8 pad198[0x1A0 - 0x198];
    /* 0x1A0 */ s32 unk1A0;
    /* 0x1A4 */ s32 unk1A4;
    /* 0x1A8 */ Vec2i focusPos;
} Unk80081260;

typedef struct Unk80319DA0 {
    /* 0x000 */ u8 pad0[0x858];
    /* 0x858 */ u32 unk858;
} Unk80319DA0;

extern Unk80319DA0 lbl_80319DA0;
extern u32 lbl_804EE988;

void fn_80080BDC(Unk80081260* obj);
BOOL fn_800816F0(Unk80081260* obj);
void fn_80023F64(void);
void fn_80023FCC(void);
void fn_80024020(void);
void fn_80024034(void);
void fn_800818A0(Unk80081260* obj);
void fn_80080BFC(u32 n, Vec2i* pos);
void fn_800817D0(Unk80081260* obj);

BOOL fn_80081260(Unk80081260* obj) {
    BOOL ret = FALSE;
    u16 mode;
    u32 rnd;
    s32 n;
    Unk80081260Obj* t;

    fn_80080BDC(obj);
    obj->focusPos = obj->slots[0].obj->pos;
    if (obj->flags1 & 1) {
        ret = fn_800816F0(obj);
    }
    mode = obj->inputMode;
    obj->frame++;
    obj->prevPad = obj->pad;
    if (mode == 0) {
        obj->pad = lbl_80319DA0.unk858 & 0xFFF;
    } else if (mode == 0xFFFE) {
        obj->pad = (lbl_80319DA0.unk858 & 0x60) | 0x8000;
        if (obj->unk18C == 0) {
            obj->inputMode = 0;
        }
    } else if (mode == 0xFFFF) {
        obj->pad = 0xFFFF;
    } else {
        obj->pad = mode | (lbl_80319DA0.unk858 & 0x60);
    }
    obj->trig = obj->pad & (obj->prevPad ^ obj->pad);
    if (!(obj->flagsF5 & 0x80) || obj->unk18C == 0) {
        obj->flagsF5 &= 0x7F;
        if (obj->flagsF5 & 1) {
            fn_80023F64();
        } else {
            fn_80023FCC();
        }
        if (obj->flagsF5 & 2) {
            fn_80024020();
        } else {
            fn_80024034();
        }
    }
    fn_800818A0(obj);
    if (obj->unk192 != 0) {
        lbl_804EE988 = (lbl_804EE988 * 0x343FD + 0x269EC3) & 0x7FFFFFFF;
        n = (lbl_804EE988 >> 16) & 0xF;
        if (n <= (u8)obj->unk192) {
            fn_80080BFC(n, &obj->unk138);
        }
    }
    if (obj->unk194 != NULL && obj->unk194->unk10 == 4) {
        obj->unk194 = NULL;
    }
    t = obj->slots[0].obj;
    if (obj->flags1 & 4) {
        obj->flags1 &= 0xFFFB;
    }
    if (obj->unk1A0 > 0) {
        t->pos.x = obj->unk1A0;
        t->pos.y = obj->unk1A4;
    }
    fn_800817D0(obj);
    return ret;
}
