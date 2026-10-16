#include "types.h"
typedef struct Unk80099804 {
    /* 0x00 */ u8 pad00[0x2];
    /* 0x02 */ u8 unk02;
    /* 0x03 */ u8 pad03[0x901];
    /* 0x904 */ u32 unk904;
    /* 0x908 */ u32 unk908;
    /* 0x90C */ u32 unk90C;
    /* 0x910 */ u32 unk910;
    /* 0x914 */ u32 unk914;
    /* 0x918 */ u32 unk918;
    /* 0x91C */ u32 unk91C;
    /* 0x920 */ u32 unk920;
    /* 0x924 */ u32 unk924;
    /* 0x928 */ u32 unk928;
    /* 0x92C */ u32 unk92C;
    /* 0x930 */ u32 unk930;
} Unk80099804;
extern Unk80099804 lbl_80316398;
extern void fn_8009A8BC(s32);
extern void fn_8009A954(u32, u32);
extern void fn_8009AA24(u32, u32);
void fn_80099804(s32 a) {
    fn_8009A8BC(a);
    if (lbl_80316398.unk02) lbl_80316398.unk02--;
    else if (!a) {
        lbl_80316398.unk928 = 0; lbl_80316398.unk92C = 0; lbl_80316398.unk930 = 0;
        fn_8009A954(lbl_80316398.unk904, lbl_80316398.unk920);
        fn_8009A954(lbl_80316398.unk904, lbl_80316398.unk924);
        fn_8009A954(lbl_80316398.unk908, lbl_80316398.unk91C);
        fn_8009A954(lbl_80316398.unk908, lbl_80316398.unk924);
        fn_8009A954(lbl_80316398.unk90C, lbl_80316398.unk920);
        fn_8009A954(lbl_80316398.unk90C, lbl_80316398.unk91C);
        fn_8009A954(lbl_80316398.unk90C, lbl_80316398.unk924);
        fn_8009AA24(lbl_80316398.unk904, lbl_80316398.unk914);
        fn_8009AA24(lbl_80316398.unk904, lbl_80316398.unk918);
        fn_8009AA24(lbl_80316398.unk908, lbl_80316398.unk910);
        fn_8009AA24(lbl_80316398.unk908, lbl_80316398.unk918);
        fn_8009AA24(lbl_80316398.unk90C, lbl_80316398.unk914);
        fn_8009AA24(lbl_80316398.unk90C, lbl_80316398.unk910);
        fn_8009AA24(lbl_80316398.unk90C, lbl_80316398.unk918);
    }
}
