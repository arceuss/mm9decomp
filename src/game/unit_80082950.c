#include "types.h"
typedef struct Unk80082950 {
    /* 0x00 */ u8 pad00[0x28];
    /* 0x28 */ u8* unk28;
    /* 0x2C */ u8 pad2C[0x16C];
    /* 0x198 */ s32 unk198;
    /* 0x19C */ u32 unk19C;
} Unk80082950;
extern u16 lbl_80272E44[];
extern void fn_800D56A4(s32);
extern void fn_800D5564(s32);
extern s32 fn_800D57BC(s32);
extern void fn_800D5838(s32, u16);
s32 fn_80082950(Unk80082950* p) {
    u16 value;
    switch (p->unk28[1]) {
    case 0:
        if (p->unk198 != -1) fn_800D56A4(p->unk198);
        fn_800D5564(*(u32*)(p->unk28 + 4));
        p->unk198 = *(u32*)(p->unk28 + 4);
        break;
    case 1:
        value = lbl_80272E44[p->unk19C & 0xFFF];
        if (value == 0xFFFF) {
            if (p->unk198 != -1) fn_800D56A4(p->unk198);
        } else {
            if (p->unk198 != value) {
                if (p->unk198 != -1) fn_800D56A4(p->unk198);
                fn_800D5564(value);
            }
            p->unk198 = value;
        }
        break;
    case 2:
        if (p->unk198 != -1) { fn_800D56A4(p->unk198); p->unk198 = -1; }
        break;
    case 3:
        if (p->unk198 != -1 && fn_800D57BC(p->unk198)) { p->unk28 -= 8; return 1; }
        break;
    case 6:
        if (p->unk198 != -1) {
            if ((u32)p->unk198 == *(u32*)(p->unk28 + 4)) break;
            fn_800D56A4(p->unk198);
        }
        fn_800D5564(*(u32*)(p->unk28 + 4));
        p->unk198 = *(u32*)(p->unk28 + 4);
        break;
    case 7:
        if (p->unk198 != -1) { fn_800D5838(p->unk198, *(u32*)(p->unk28 + 4)); p->unk198 = -1; }
        break;
    }
    return 0;
}
