#include "types.h"
typedef struct Unk80081DD8 {
    /* 0x00 */ u8 pad00[0x28];
    /* 0x28 */ u8* unk28;
    /* 0x2C */ u8 unk2C[0xCC];
    /* 0xF8 */ u8 unkF8[0x1C];
    /* 0x114 */ s8 unk114;
    /* 0x115 */ u8 pad115[0x93];
    /* 0x1A8 */ s32 unk1A8[2];
} Unk80081DD8;
extern s32 fn_800BB428(void);
extern void fn_8009E1F4(s32);
extern void fn_80080194(void*, void*);
extern void fn_800800AC(void*);
s32 fn_80081DD8(Unk80081DD8* p) {
    u8* a;
    u8* view = p->unkF8;
    s32* pos;
    u8* q;
    a = *(u8**)(p->unk28 + 4);
    if (p->unk114 == 0) fn_8009E1F4(fn_800BB428());
    fn_80080194(view, a);
    if (a[0] != 1) {
        q = *(u8**)(p->unk2C + a[2] * 16);
        if (!q) return 0;
        if (a[2] == 0) pos = p->unk1A8;
        else pos = (s32*)(q + 0x60);
        *(s32**)(view + 0x50) = pos;
        fn_800800AC(view);
        if (a[1] & 8) { *(s32*)(view + 0x38) = pos[0]; *(s32*)(view + 0x3C) = pos[1]; }
    }
    return 0;
}
