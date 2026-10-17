#include "types.h"

typedef struct Unk80090840 {
    /* 0x0000 */ u8 pad0[0x2];
    /* 0x0002 */ u8 mode;
    /* 0x0003 */ u8 stage;
    /* 0x0004 */ u8 pad4[0xFF8 - 0x4];
    /* 0x0FF8 */ u8 cursor;
    /* 0x0FF9 */ u8 unkFF9;
    /* 0x0FFA */ u8 dirty;
    /* 0x0FFB */ u8 unkFFB;
    /* 0x0FFC */ u8 padFFC[0x1000 - 0xFFC];
    /* 0x1000 */ u32 unk1000;
    /* 0x1004 */ u16 unk1004;
    /* 0x1006 */ u8 pad1006[0x1008 - 0x1006];
    /* 0x1008 */ u8 unk1008;
    /* 0x1009 */ u8 pad1009[0x100C - 0x1009];
    /* 0x100C */ s32 voice;
    /* 0x1010 */ u8* tilemap;
} Unk80090840;

typedef struct Unk80319DA0 {
    /* 0x000 */ u8 pad0[0x860];
    /* 0x860 */ u32 trig;
    /* 0x864 */ u16 repeat;
} Unk80319DA0;

extern Unk80319DA0 lbl_80319DA0;

typedef struct Unk803140C0Rec {
    /* 0x000 */ u8 unlocked;
    /* 0x001 */ u8 visited;
    /* 0x002 */ u8 pad2[0x124 - 0x2];
    /* 0x124 */ u8 talkA;
    /* 0x125 */ u8 talkB;
    /* 0x126 */ u8 pad126[0x134 - 0x126];
} Unk803140C0Rec;

typedef struct Unk803140C0 {
    /* 0x0000 */ u8 pad0[0x220];
    /* 0x0220 */ Unk803140C0Rec recs[8];
    /* 0x0BC0 */ u8 padBC0[0x2298 - 0xBC0];
} Unk803140C0;

typedef struct Unk80383E70 {
    /* 0x0000 */ u8 pad0[0x7480];
    /* 0x7480 */ u32 heard;
    /* 0x7484 */ u8 pad7484[0x7488 - 0x7484];
} Unk80383E70;

typedef struct Unk8036CF50 {
    /* 0x0 */ s32 stage;
    /* 0x4 */ u8 pad4[0xEFE0 - 0x4];
} Unk8036CF50;

extern Unk803140C0 lbl_803140C0;
extern Unk80383E70 lbl_80383E70;
extern Unk8036CF50 lbl_8036CF50;

void fn_800A7084(s32 arg0, s32 id, s32 arg2, s32 arg3, s32 arg4);

void fn_800D5234(s32 se);
void fn_8009BF98(u16 arg0, void* dst, s32 arg2);

static inline void Redraw(Unk80090840* obj) {
    u32 i;

    for (i = 0; i < 5; i++) {
        fn_8009BF98(obj->unk1004, &obj->tilemap[((u8)i + 0x16) * 64 + 0x802], 0x3C);
    }
}

void fn_80090840(Unk80090840* obj) {
    u32 slot;
    u32 bit;

    if ((lbl_80319DA0.trig & 0x10) || (lbl_80319DA0.trig & 0x40)) {
        if (obj->cursor == 0) {
            fn_800D5234(1);
            obj->unkFF9 = 0;
            obj->unkFFB = 4;
            obj->mode = 6;
            obj->stage = 0;
            return;
        }
        slot = obj->cursor - 1;
        bit = 1 << slot;
        if ((lbl_803140C0.recs[0].unlocked & bit) && (lbl_803140C0.recs[0].visited & bit)) {
        if (lbl_803140C0.recs[slot].talkA == 1 && !(lbl_80383E70.heard & 1)) {
            if (lbl_8036CF50.stage == 0) {
                fn_800A7084(0, 0x97, 0x18, 0, 0);
            } else {
                fn_800A7084(0, 0x97, 0x18, 1, 0);
                obj->voice = 1;
            }
        } else if (lbl_803140C0.recs[slot].talkB == 1 && !(lbl_80383E70.heard & 2)) {
            if (lbl_8036CF50.stage == 0) {
                fn_800A7084(0, 0x9A, 0x18, 0, 0);
            } else {
                fn_800A7084(0, 0x9A, 0x18, 1, 0);
                obj->voice = 2;
            }
        } else if (lbl_803140C0.recs[slot].talkB == 2 && !(lbl_80383E70.heard & 4)) {
            if (lbl_8036CF50.stage == 0) {
                fn_800A7084(0, 0x9D, 0x18, 0, 0);
            } else {
                fn_800A7084(0, 0x9D, 0x18, 1, 0);
                obj->voice = 3;
            }
        } else {
            fn_800D5234(1);
            obj->stage += 5;
        }
        } else {
            fn_800D5234(2);
        }
    } else if (lbl_80319DA0.trig & 0x20) {
        if (obj->cursor != 0) {
            fn_800D5234(0);
        }
        Redraw(obj);
        obj->dirty = 1;
        obj->cursor = 0;
        obj->unk1000 = 0;
        obj->stage += 3;
    } else if (lbl_80319DA0.repeat & 4) {
        fn_800D5234(0);
        if (obj->cursor == 0) {
            obj->cursor = 8;
        } else {
            obj->cursor--;
        }
        obj->unk1008 = obj->cursor;
        obj->unk1000 = 0;
        obj->stage += 3;
    } else if (lbl_80319DA0.repeat & 8) {
        fn_800D5234(0);
        obj->cursor = (u8)(obj->cursor + 1) % 9;
        obj->unk1008 = obj->cursor;
        obj->unk1000 = 0;
        obj->stage += 3;
    }
}
