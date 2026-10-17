#include "types.h"

typedef struct Unk8008DF4C {
    /* 0x0000 */ u8 pad0[0x2];
    /* 0x0002 */ u8 mode;
    /* 0x0003 */ u8 stage;
    /* 0x0004 */ s16 fade;
    /* 0x0006 */ u8 pad6[0xFF6 - 0x6];
    /* 0x0FF6 */ u8 unkFF6;
    /* 0x0FF7 */ u8 unkFF7;
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
} Unk8008DF4C;

typedef struct Unk80319DA0 {
    /* 0x000 */ u8 pad0[0x860];
    /* 0x860 */ u32 trig;
    /* 0x864 */ u16 repeat;
} Unk80319DA0;

extern Unk80319DA0 lbl_80319DA0;

typedef struct Unk803140C0Rec {
    /* 0x000 */ u8 unlocked;
    /* 0x001 */ u8 visited;
    /* 0x002 */ u8 pad2[0x4 - 0x2];
    /* 0x004 */ u8 unk4[0x124 - 0x4];
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

typedef struct Unk80273690Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk80273690Pos;

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

extern Unk80316D78 lbl_80316D78;
extern Unk80273690Pos lbl_80273690[];

void fn_800BB7B8(s32 a);
void fn_800BB4E8(s32 a, s32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void fn_80090840(Unk8008DF4C* obj);
void fn_8008E8A4(Unk8008DF4C* obj, void* rec);
void fn_8000ED10(s32 arg0, void* dst, void* gfx, s32 tile, s8 x, s8 y);
void fn_800D7CC8(Unk8008DF4C* obj, s32 arg1, s32 arg2);
void fn_80090B8C(Unk8008DF4C* obj);

void fn_800D5234(s32 se);
void fn_8009BF98(u16 arg0, void* dst, s32 arg2);

#define ARC (lbl_80316D78.unk3004 + 0xCD5000)

static inline void Fill(Unk8008DF4C* obj, u8 row, u8 col, u32 rows, s32 len) {
    u32 i;

    for (i = 0; i < rows; i++) {
        fn_8009BF98(obj->unk1004, &obj->tilemap[((u8)i + row) * 64 + 0x800 + col * 2], len);
    }
    obj->dirty = 1;
}

static inline void Tile(Unk8008DF4C* obj, s32 idx) {
    u8* arc = ARC;
    Unk80273690Pos* p = &lbl_80273690[lbl_8036CF50.stage * 30 + idx];

    fn_8000ED10(0x38, obj->tilemap + 0x800, (void*)((*(u32*)(arc + 4) >> 1) + (u32)arc), idx, p->x, p->y);
}

void fn_8008DF4C(Unk8008DF4C* obj) {
    u32 R;
    u32 a;
    u32 b;
    u32 slot;
    u32 bit;

    switch (obj->stage) {
    case 0:
        fn_800BB7B8(3);
        R = (u32)ARC;
        a = *(u32*)(R + 0x14) >> 1;
        b = *(u32*)(R + 0x18) >> 1;
        fn_800BB4E8(3, 3, R + a + *(u32*)(R + a), R + b + *(u32*)(R + b), 0x20, 0, R + b, R + a);
        obj->stage++;
    case 1:
        fn_80090840(obj);
        break;
    case 2:
        obj->stage++;
    case 3:
        obj->stage++;
        break;
    case 4:
        obj->stage++;
    case 5:
        Fill(obj, 4, 4, 4, 0x18);
        Fill(obj, 4, 0x11, 4, 0x16);
        Fill(obj, 10, 4, 10, 0x30);
        Fill(obj, 0x16, 1, 5, 0x3C);
        if (obj->cursor != 0) {
            slot = obj->cursor - 1;
            bit = 1 << slot;
            if ((lbl_803140C0.recs[0].unlocked & bit) && (lbl_803140C0.recs[0].visited & bit)) {
                fn_8008E8A4(obj, lbl_803140C0.recs[slot].unk4);
            } else {
                Tile(obj, 0x16);
                obj->dirty = 1;
                Tile(obj, 0x1D);
                obj->dirty = 1;
            }
        }
        fn_800BB7B8(3);
        obj->stage = 0;
        break;
    case 6:
        obj->unkFF7 = 2;
        obj->unkFF6 = 1;
        fn_800D7CC8(obj, 0, 1);
        Tile(obj, 0x19);
        obj->dirty = 1;
        obj->fade = 0;
        obj->stage++;
    case 7:
        fn_80090B8C(obj);
        break;
    }
}
