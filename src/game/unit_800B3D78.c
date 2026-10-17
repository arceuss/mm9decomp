#include "types.h"

typedef struct UnkB3D78Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} UnkB3D78Pos;

typedef struct UnkB3D78Child {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 pad11[0x60 - 0x11];
    /* 0x60 */ UnkB3D78Pos pos;
    /* 0x68 */ u8 pad68[0x88 - 0x68];
    /* 0x88 */ u8 unk88;
} UnkB3D78Child;

typedef struct UnkB3D78Box {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
} UnkB3D78Box;

typedef struct UnkB3D78 {
    /* 0x000 */ u8 pad000[0xA];
    /* 0x00A */ u8 unk00A;
    /* 0x00B */ u8 pad00B[0x11 - 0xB];
    /* 0x011 */ u8 unk011;
    /* 0x012 */ u8 pad012[0x50 - 0x12];
    /* 0x050 */ struct {
        u32 hi : 30;
        u32 lo : 2;
    } unk050;
    /* 0x054 */ u8 pad054[0x60 - 0x54];
    /* 0x060 */ UnkB3D78Pos pos;
    /* 0x068 */ u8 pad068[0xC8 - 0x68];
    /* 0x0C8 */ u8 unk0C8[0xE4 - 0xC8];
    /* 0x0E4 */ s16 unk0E4;
    /* 0x0E6 */ s16 unk0E6;
    /* 0x0E8 */ s32 unk0E8;
    /* 0x0EC */ u8 pad0EC[0xFC - 0xEC];
    /* 0x0FC */ u8 unk0FC;
    /* 0x0FD */ u8 pad0FD[0x104 - 0xFD];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 pad108[0x123 - 0x108];
    /* 0x123 */ u8 unk123;
    /* 0x124 */ u8 pad124[0x128 - 0x124];
    /* 0x128 */ u32 unk128;
    /* 0x12C */ u8 pad12C[0x140 - 0x12C];
    /* 0x140 */ UnkB3D78Child* unk140;
    /* 0x144 */ UnkB3D78Child* unk144;
    /* 0x148 */ s32 unk148;
    /* 0x14C */ u8 pad14C[0x19C - 0x14C];
    /* 0x19C */ UnkB3D78Box* unk19C;
    /* 0x1A0 */ u32 unk1A0;
    /* 0x1A4 */ u8 pad1A4[0x1F3 - 0x1A4];
    /* 0x1F3 */ u8 unk1F3;
    /* 0x1F4 */ u8 unk1F4;
    /* 0x1F5 */ u8 unk1F5;
} UnkB3D78;

void fn_800B7A28(UnkB3D78Pos* pos, void* vel, UnkB3D78Box** box, UnkB3D78Box* cur, u32 arg4, u32 flags);
s32 fn_800B9610(UnkB3D78Box** box);
void fn_800B76BC(UnkB3D78* obj);
void fn_800BA464(UnkB3D78* obj);
void fn_800B67F8(UnkB3D78* obj);
s32 fn_800B9840(UnkB3D78Box** box, UnkB3D78Pos* pos, void* vel, u32 dir);
u8 fn_800B95CC(UnkB3D78Pos* pos, UnkB3D78Box* box, s32 arg2);
s32 fn_800B9458(UnkB3D78Pos* pos, UnkB3D78Box* box, s32 arg2);
UnkB3D78Child* fn_8004196C(UnkB3D78Pos* pos);
UnkB3D78Child* fn_800415A8(UnkB3D78Pos* pos);
s32 fn_800D5520(s32 se);
void fn_800D5234(s32 se);
void fn_800D5458(s32 se);

static inline void Loop(u32 flags, u32 bit, s32 se) {
    if (flags & bit) {
        if (fn_800D5520(se) == 0) {
            fn_800D5234(se);
        }
    } else if (fn_800D5520(se) != 0) {
        fn_800D5458(se);
    }
}

void fn_800B3D78(UnkB3D78* obj) {
    UnkB3D78Box** box;
    s32 on;
    s32 r;
    u8 v;
    u8 prev;
    UnkB3D78Pos pos;

    obj->unk104 = (obj->unk104 & ~0x1F800) | 0x10;
    obj->unk148 = 0;
    if (((1 << obj->unk011) & 0x6053) && !(obj->unk104 & 2)) {
        on = 1;
    } else {
        on = 0;
    }
    if (on) {
        box = &obj->unk19C;
        fn_800B7A28(&obj->pos, obj->unk0C8, box, *box, obj->unk1A0, ((obj->unk00A & 0x10) << 14) | 0x180800);
        r = fn_800B9610(box);
        if (r > 0) {
            obj->pos.y += r;
            fn_800B7A28(&obj->pos, obj->unk0C8, box, *box, obj->unk1A0, ((obj->unk00A & 0x10) << 14) | 0x80001);
        }
    }
    fn_800B76BC(obj);
    fn_800BA464(obj);
    fn_800B67F8(obj);
    if (obj->unk011 == 0xC) {
        if ((u32)(obj->unk0FC - 0xF) <= 1) {
            obj->unk050.lo = 3;
        } else {
            obj->unk050.lo = 2;
        }
    } else if (fn_800B9840(&obj->unk19C, &obj->pos, obj->unk0C8, (obj->unk00A >> 4) & 1)) {
        obj->unk050.lo = 3;
    } else {
        obj->unk050.lo = 2;
    }
    obj->unk0E4 = 0;
    obj->unk0E6 = 0;
    obj->unk0E8 = 0;
    obj->unk1F3 = fn_800B95CC(&obj->pos, obj->unk19C, 0);
    obj->unk123 = 100;
    if (obj->unk144 == NULL || obj->unk144->unk10 >= 2) {
        obj->unk144 = NULL;
    }
    if (obj->unk140 == NULL || obj->unk140->unk10 >= 2) {
        obj->unk140 = NULL;
    }
    prev = obj->unk1F5;
    v = fn_800B9458(&obj->pos, obj->unk19C, 0);
    obj->unk1F4 = v;
    if (obj->unk011 != 7 && obj->unk011 != 9 && obj->unk011 != 10) {
        if (v >= 0x32) {
            pos = obj->pos;
            pos.y += obj->unk19C->unk2;
            if (obj->unk144 == NULL) {
                obj->unk144 = fn_8004196C(&pos);
            }
        }
        if ((u32)(v - 1) <= 0x62 && (u32)(prev - 1) > 0x62) {
            if (obj->unk140 == NULL) {
                obj->unk140 = fn_800415A8(&obj->pos);
            } else {
                obj->unk140->unk88 = 1;
                obj->unk140->pos = obj->pos;
            }
        }
    }
    Loop(obj->unk128, 1, 0x23);
    Loop(obj->unk128, 2, 0x28);
    Loop(obj->unk128, 4, 0x29);
    Loop(obj->unk128, 8, 0x30);
    Loop(obj->unk128, 0x10, 0x31);
    obj->unk128 = 0;
}
