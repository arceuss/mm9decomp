#include "types.h"

typedef struct Unk8008E8A4 {
    /* 0x000 */ u8 pad0[0x84];
    /* 0x084 */ u8 unk84;
    /* 0x085 */ u8 pad85[0x9C - 0x85];
    /* 0x09C */ u32 flags;
    /* 0x0A0 */ u8 padA0[0xEB - 0xA0];
    /* 0x0EB */ u8 unkEB;
    /* 0x0EC */ u8 padEC[0xF1 - 0xEC];
    /* 0x0F1 */ u8 unkF1;
    /* 0x0F2 */ u8 unkF2;
    /* 0x0F3 */ u8 unkF3;
    /* 0x0F4 */ u8 unkF4;
    /* 0x0F5 */ u8 unkF5;
    /* 0x0F6 */ u8 unkF6;
    /* 0x0F7 */ u8 padF7[0x100 - 0xF7];
    /* 0x100 */ u32 unk100;
    /* 0x104 */ u8 pad104[0x11C - 0x104];
    /* 0x11C */ u32 unk11C;
    /* 0x120 */ u8 unk120;
    /* 0x121 */ u8 unk121;
} Unk8008E8A4;

void fn_8008E9D4(void* arg0, u8 arg1, u32 arg2, u16 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7, u32 arg8,
                 u32 arg9, u32 arg10, u32 arg11, u32 arg12, u32 arg13, u8 arg14, u32 arg15, u32 arg16, u32 arg17,
                 u32 arg18, u32 arg19, u32 arg20, u32 arg21, u32 arg22, u32 arg23, u32 arg24);

void fn_8008E8A4(void* arg0, Unk8008E8A4* p) {
    u32 a = 0;
    u32 b = 1;
    u32 c = 0;

    if (p->unkEB & 0x20) {
        a = 1;
    } else if (p->unk120 == 1) {
        a = 2;
    }
    if ((p->flags & 0x200) && p->unk120 == 1) {
        b = 2;
    }
    if (p->flags & 0x400) {
        c = (p->unk120 == 1) + 1;
    }
    fn_8008E9D4(arg0, p->unk84, a, p->unk100, p->flags & 1, p->flags & 2, p->flags & 4, p->flags & 8,
                p->flags & 0x20, p->flags & 0x10, p->flags & 0x40, p->flags & 0x80, p->flags & 0x100, b, c,
                p->unkF1, p->unkF2, p->unkF3, p->unkF5, p->unkF4, p->unkF6, (p->unkEB >> 7) & 1,
                (p->unkEB & 0x20) != 0, p->unk121, p->unk11C);
}
