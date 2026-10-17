#include "types.h"

typedef struct UnkB6984 {
    /* 0x000 */ u8 pad0[0x11];
    /* 0x011 */ u8 unk11;
    /* 0x012 */ u8 pad12[0x14 - 0x12];
    /* 0x014 */ u8 unk14;
    /* 0x015 */ u8 pad15[0x60 - 0x15];
    /* 0x060 */ s32 x;
    /* 0x064 */ s32 y;
    /* 0x068 */ u8 pad68[0x88 - 0x68];
    /* 0x088 */ u8 unk88[0xA0 - 0x88];
    /* 0x0A0 */ u32 unkA0;
    /* 0x0A4 */ u8 padA4[0xB6 - 0xA4];
    /* 0x0B6 */ s16 unkB6;
    /* 0x0B8 */ u8 padB8[0x104 - 0xB8];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 pad108[0x115 - 0x108];
    /* 0x115 */ u8 unk115;
} UnkB6984;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x2A0];
    /* 0x2A0 */ u16 unk2A0[4];
} Unk80304B90;

typedef struct Unk8038DC58 {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 padD[0x15 - 0xD];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x19 - 0x16];
    /* 0x19 */ u8 unk19;
} Unk8038DC58;

extern Unk80304B90 lbl_80304B90;
extern u8 lbl_803051D8[];
extern Unk8038DC58 lbl_8038DC58;

s32 fn_800B6E30(UnkB6984* obj);
s32 fn_800B6B94(UnkB6984* obj);
void fn_8009A770(void* a, s32 b, s32 c);
u8 fn_8009E8E4(s32 x, s32 y);

u32 fn_800B6984(UnkB6984* obj) {
    u32 f;
    s32 shielded = 0;
    s32 used = 0;
    s32 n;
    s32 x;
    s32 y;
    s32 ok;

    if (obj->unk11 == 7) {
        return 0x3C;
    }
    if (!(obj->unkA0 & 0x200) && obj->unkB6 != 0 && (lbl_80304B90.unk2A0[obj->unk14] & 0x8000)) {
        obj->unk115 = 0;
        return 0;
    }
    f = 0;
    if (fn_800B6E30(obj)) {
        f |= 0x10;
    }
    if (fn_800B6B94(obj)) {
        f |= 0x20;
    }
    if ((f & 0x10) && (n = lbl_803051D8[0xE]) > 0) {
        f &= ~0x10;
        fn_8009A770(obj->unk88, 0, 0);
        lbl_803051D8[0xE] = n - 1;
        used = 1;
    }
    if (!((1 << obj->unk11) & ~0x720)) {
        ok = 0;
    } else {
        x = obj->x;
        y = obj->y;
        if (fn_8009E8E4(x, y) && fn_8009E8E4(x, y - 0x1800)) {
            ok = 1;
        } else {
            ok = 0;
        }
    }
    if (ok) {
        f |= 8;
        lbl_8038DC58.unkC |= 0x40;
    }
    if ((f & 8) && (obj->unk104 & 0x10) && lbl_803051D8[0xC] != 0) {
        shielded = 1;
    }
    if (obj->unkA0 & 1) {
        f |= 1;
        if ((obj->unkA0 & 0x200) || obj->unkB6 == 0) {
            f |= 4;
        }
    }
    if (f != 0 && !shielded && !used) {
        lbl_8038DC58.unkC |= 4;
        lbl_8038DC58.unk15 |= 4;
        lbl_8038DC58.unk19 |= 0x20;
    }
    obj->unk115 = f;
    return f;
}
