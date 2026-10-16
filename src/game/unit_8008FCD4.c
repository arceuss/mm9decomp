#include "types.h"

typedef struct Unk8008FCD4 {
    /* 0x0000 */ u8 pad0[0x3];
    /* 0x0003 */ u8 stage;
    /* 0x0004 */ u8 pad4[0xFF8 - 0x4];
    /* 0x0FF8 */ u8 cursor;
    /* 0x0FF9 */ u8 unkFF9;
    /* 0x0FFA */ u8 dirty;
    /* 0x0FFB */ u8 padFFB[0x1000 - 0xFFB];
    /* 0x1000 */ u32 unk1000;
    /* 0x1004 */ u16 unk1004;
    /* 0x1006 */ u8 pad1006[0x1008 - 0x1006];
    /* 0x1008 */ u8 unk1008;
    /* 0x1009 */ u8 pad1009[0x1010 - 0x1009];
    /* 0x1010 */ u8* tilemap;
} Unk8008FCD4;

typedef struct Unk80319DA0 {
    /* 0x000 */ u8 pad0[0x860];
    /* 0x860 */ u32 trig;
    /* 0x864 */ u16 repeat;
} Unk80319DA0;

extern Unk80319DA0 lbl_80319DA0;

void fn_800D5234(s32 se);
void fn_8009BF98(u16 arg0, void* dst, s32 arg2);

static inline void Redraw(Unk8008FCD4* obj) {
    u32 i;

    for (i = 0; i < 5; i++) {
        fn_8009BF98(obj->unk1004, &obj->tilemap[((u8)i + 0x16) * 64 + 0x802], 0x3C);
    }
}

void fn_8008FCD4(Unk8008FCD4* obj) {
    if ((lbl_80319DA0.trig & 0x10) || (lbl_80319DA0.trig & 0x40)) {
        fn_800D5234(1);
        if (obj->cursor == 0) {
            obj->unkFF9 = 0;
            obj->stage += 5;
        } else {
            obj->stage += 3;
        }
    } else if (lbl_80319DA0.trig & 0x20) {
        if (obj->cursor != 0) {
            fn_800D5234(0);
        }
        Redraw(obj);
        obj->dirty = 1;
        obj->cursor = 0;
        obj->unk1000 = 0;
        obj->stage++;
    } else if (lbl_80319DA0.repeat & 4) {
        fn_800D5234(0);
        Redraw(obj);
        obj->dirty = 1;
        if (obj->cursor == 0) {
            obj->cursor = 8;
        } else {
            obj->cursor--;
        }
        obj->unk1008 = obj->cursor;
        obj->unk1000 = 0;
        obj->stage++;
    } else if (lbl_80319DA0.repeat & 8) {
        fn_800D5234(0);
        obj->unk1000 = 0;
        obj->cursor = (u8)(obj->cursor + 1) % 9;
        obj->unk1008 = obj->cursor;
        Redraw(obj);
        obj->dirty = 1;
        obj->stage++;
    }
}
