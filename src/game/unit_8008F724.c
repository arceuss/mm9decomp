#include "types.h"

typedef struct Unk8008F724 {
    /* 0x0000 */ u8 pad0[0xFFA];
    /* 0x0FFA */ u8 dirty;
    /* 0x0FFB */ u8 padFFB[0x1010 - 0xFFB];
    /* 0x1010 */ u8* tilemap;
} Unk8008F724;

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

extern Unk80316D78 lbl_80316D78;

void fn_8000ED10(s32 arg0, void* dst, void* font, u8 tile, s32 x, s32 y);

#define ARC (lbl_80316D78.unk3004 + 0xCD5000)

static inline void Put(Unk8008F724* obj, u8 tile, s32 x) {
    u8* a = ARC;

    fn_8000ED10(0x38, obj->tilemap + 0x800, (void*)((*(u32*)(a + 4) >> 1) + (u32)a), tile, x, 7);
}

void fn_8008F724(Unk8008F724* obj, u32 frames) {
    u32 v;
    u32 sec;
    u32 d;

    sec = frames / 60;
    if (sec >= 360000) {
        sec = 359999;
    }
    v = sec / 3600;
    sec -= v * 3600;
    v %= 100;
    d = v / 10;
    v -= d * 10;
    Put(obj, d + 1, 0x13);
    Put(obj, v + 1, 0x14);
    Put(obj, 0xB, 0x15);
    v = sec / 60;
    sec -= v * 60;
    d = v / 10;
    v -= d * 10;
    Put(obj, d + 1, 0x16);
    Put(obj, v + 1, 0x17);
    Put(obj, 0xB, 0x18);
    d = sec / 10;
    sec -= d * 10;
    Put(obj, d + 1, 0x19);
    Put(obj, sec + 1, 0x1A);
    obj->dirty = 1;
}
