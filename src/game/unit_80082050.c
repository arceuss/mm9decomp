#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk80082050Sub {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ s8 unk1C;
    /* 0x1D */ u8 unk1D;
    /* 0x1E */ u8 pad1E[0x26 - 0x1E];
    /* 0x26 */ s16 unk26;
    /* 0x28 */ u8 pad28[0x40 - 0x28];
    /* 0x40 */ Vec2i unk40;
    /* 0x48 */ u8 pad48[0x50 - 0x48];
    /* 0x50 */ Vec2i* unk50;
    /* 0x54 */ u8 pad54[0x5C - 0x54];
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ u8 pad60[0x64 - 0x60];
    /* 0x64 */ s32 unk64;
} Unk80082050Sub;

typedef struct Unk80082050Data {
    /* 0x0 */ u8 pad0;
    /* 0x1 */ u8 unk1;
} Unk80082050Data;

typedef struct Unk80082050 {
    /* 0x000 */ u8 pad0[0x28];
    /* 0x028 */ Unk80082050Data* unk28;
    /* 0x02C */ u8 pad2C[0xF8 - 0x2C];
    /* 0x0F8 */ Unk80082050Sub unkF8;
    /* 0x160 */ u8 pad160[0x1A8 - 0x160];
    /* 0x1A8 */ Vec2i unk1A8;
} Unk80082050;

typedef struct Unk80316398 {
    /* 0x000 */ u8 unk0;
    /* 0x001 */ u8 unk1;
    /* 0x002 */ u8 pad2[0x938 - 0x2];
} Unk80316398;

extern Unk80316398 lbl_80316398;

void fn_800BB428(void);
void fn_8009E1F4(void);
void fn_80080168(Unk80082050Sub* sub, s32 arg1);
s32 fn_800800AC(Unk80082050Sub* sub);

s32 fn_80082050(Unk80082050* p) {
    Unk80082050Sub* sub;
    Vec2i* pos;

    if (p->unk28->unk1 == 0) {
        sub = &p->unkF8;
        if (sub->unk1C == 0) {
            fn_800BB428();
            fn_8009E1F4();
            fn_80080168(sub, 5);
            sub->unk1D = 8;
            sub->unk26 = 0;
        }
        pos = &p->unk1A8;
        sub->unk50 = pos;
        sub->unk40 = *pos;
        sub->unk5C = 0;
        sub->unk64 = 0;
        fn_800800AC(sub);
        lbl_80316398.unk1 = 0;
        lbl_80316398.unk0 &= 0x7F;
    } else {
        lbl_80316398.unk0 &= 0x7F;
        lbl_80316398.unk1 = 0;
    }
    return 0;
}
