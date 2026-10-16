#include "types.h"

typedef struct Unk80062774 {
    /* 0x00 */ u8 pad0[0x60];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0xC8 - 0x68];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 unkC9;
} Unk80062774;

s32 fn_800A3CD4(s32 x, s32 y);
s32 fn_800A3FAC(s32 x, s32 y);
s32 fn_800A39F0(s32 x, s32 y);
s32 fn_800A36F8(s32 x, s32 y);
u16 fn_8009E894(s32 x, s32 y);
BOOL fn_800629C0(Unk80062774* obj);
BOOL fn_80062B4C(Unk80062774* obj);

static inline BOOL CheckRight(Unk80062774* obj) {
    s32 d = fn_800A3CD4(obj->x + 0x500, obj->y);

    if (d < 0) {
        obj->x += d;
        if (obj->unkC9 == 3) {
            obj->unkC8 = 2;
            obj->unkC9 = 0;
        } else {
            obj->unkC8 = 3;
            obj->unkC9 = 0;
        }
        return TRUE;
    }
    return FALSE;
}

static inline BOOL CheckLeft(Unk80062774* obj) {
    s32 d = fn_800A3FAC(obj->x - 0x500, obj->y);

    if (d > 0) {
        obj->x += d;
        if (obj->unkC9 == 3) {
            obj->unkC8 = 2;
            obj->unkC9 = 1;
        } else {
            obj->unkC8 = 3;
            obj->unkC9 = 1;
        }
        return TRUE;
    }
    return FALSE;
}

static inline BOOL CheckUp(Unk80062774* obj) {
    s32 d = fn_800A39F0(obj->x, obj->y - 0x500);

    if (d > 0) {
        obj->y += d;
        if (obj->unkC9 == 0) {
            obj->unkC8 = 1;
            obj->unkC9 = 2;
        } else {
            obj->unkC8 = 0;
            obj->unkC9 = 2;
        }
        return TRUE;
    }
    return FALSE;
}

static inline BOOL CheckDown(Unk80062774* obj) {
    s32 x = obj->x;
    s32 y = obj->y + 0x500;
    s32 d;

    if ((fn_8009E894(x, y) & 0xF) != 3 && (d = fn_800A36F8(x, y)) < 0) {
        obj->y += d;
        if (obj->unkC9 == 0) {
            obj->unkC8 = 1;
            obj->unkC9 = 3;
        } else {
            obj->unkC8 = 0;
            obj->unkC9 = 3;
        }
        return TRUE;
    }
    return FALSE;
}

void fn_80062774(Unk80062774* obj) {
    switch (obj->unkC8) {
    case 0:
        if (!CheckRight(obj)) {
            fn_800629C0(obj);
        }
        break;
    case 1:
        if (!CheckLeft(obj)) {
            fn_800629C0(obj);
        }
        break;
    case 2:
        if (!CheckUp(obj)) {
            fn_80062B4C(obj);
        }
        break;
    case 3:
        if (!CheckDown(obj)) {
            fn_80062B4C(obj);
        }
        break;
    }
}
