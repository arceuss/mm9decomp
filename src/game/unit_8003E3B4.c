#include "types.h"
#include "game/sound.h"

extern u8 lbl_803017A0[];

extern void fn_8008C004(void);
extern void fn_800D606C(void* p, void* q, s32 n);
extern void fn_800E6534(s32 a, void (*fn)(void));
extern s32 fn_800E6654(s32 a);
extern s32 fn_800D57BC(s32 a);
extern void fn_800D5564(s32 a);

void fn_8003E3B4(u8* o) {
    switch (o[6]) {
    case 0:
        fn_800E6534(1, fn_8008C004);
        o[6] = o[6] + 1;
        /* fall through */
    case 1:
        if (fn_800E6654(1) != 0) {
            s32 t;
            fn_800D606C(o + 0x1C, lbl_803017A0, 0x40);
            o[5] = 2;
            o[6] = 0;
            o[7] = 0;
            t = o[0x2B0] + o[0x26C];
            o[0x2AC] = t;
            o[0x2AD] = 0;
            o[0x2B0] = 0;
            if ((u8)t >= 9) {
                o[0x2B0] = (u8)t - 8;
                o[0x2AC] = 8;
            }
            if (fn_800D57BC(BGM_PASSWORD) == 0) {
                fn_800D5564(BGM_PASSWORD);
            }
        }
        break;
    }
}
