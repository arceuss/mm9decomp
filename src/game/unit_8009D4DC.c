#include "types.h"

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3008];
    /* 0x3008 */ u8* unk3008;
} Unk80316D78;

typedef struct Unk80319DA0Pad {
    /* 0x000 */ u8 pad0[0x840];
    /* 0x840 */ s32 unk840;
    /* 0x844 */ s32 unk844;
    /* 0x848 */ s32 unk848;
    /* 0x84C */ u8 pad84C[0x850 - 0x84C];
    /* 0x850 */ s32 unk850;
    /* 0x854 */ s32 unk854;
    /* 0x858 */ s32 trig;
    /* 0x85C */ u16 unk85C;
    /* 0x85E */ u8 unk85E;
    /* 0x85F */ u8 unk85F;
    /* 0x860 */ s32 unk860;
    /* 0x864 */ s32 unk864;
    /* 0x868 */ u16 unk868;
    /* 0x86A */ u8 pad86A[0x86C - 0x86A];
} Unk80319DA0Pad;

typedef struct Unk80319DA0 {
    /* 0x0000 */ void* heap;
    /* 0x0004 */ void* unk4;
    /* 0x0008 */ Unk80319DA0Pad pads[4];
    /* 0x21B8 */ u16 unk21B8;
    /* 0x21BA */ u8 pad21BA[0x21C0 - 0x21BA];
} Unk80319DA0;

extern Unk80316D78 lbl_80316D78;
extern Unk80319DA0 lbl_80319DA0;
extern u8 lbl_8031BF60[];

void* fn_80116104(void* start, u32 size, s32 arg2);
void fn_801165E0(void* arg0, void* heap, s32 arg2);
void fn_8009D494(void);
void fn_8009D4A8(void);
void fn_8015726C(void (*alloc)(void), void (*free)(void));
void fn_801538BC(void);
void fn_80153BB0(void);
void fn_80158738(s32 chan, s32 arg1);
void fn_80153C50(s32 chan);
void fn_8009D780(void);

static inline void InitPad(Unk80319DA0Pad* pad) {
    pad->unk848 = 0xFD;
    pad->unk85C = 0;
    pad->trig = 0;
    pad->unk854 = 0;
    pad->unk850 = 0;
    pad->unk864 = 0;
    pad->unk860 = 0;
    pad->unk868 = 0;
    pad->unk840 = 0;
    pad->unk844 = 0;
    pad->unk85E = 0x18;
    pad->unk85F = 4;
}

void fn_8009D4DC(void) {
    s32 i;

    lbl_80319DA0.heap = fn_80116104(lbl_80316D78.unk3008 + 0x1000, 0x18000, 0);
    lbl_80319DA0.unk4 = lbl_8031BF60;
    fn_801165E0(lbl_8031BF60, lbl_80319DA0.heap, 0x20);
    fn_8015726C(fn_8009D494, fn_8009D4A8);
    fn_801538BC();
    fn_80153BB0();
    for (i = 0; i < 4; i++) {
        fn_80158738(i, 6);
        fn_80153C50(i);
    }
    InitPad(&lbl_80319DA0.pads[0]);
    InitPad(&lbl_80319DA0.pads[1]);
    InitPad(&lbl_80319DA0.pads[2]);
    InitPad(&lbl_80319DA0.pads[3]);
    fn_8009D780();
    lbl_80319DA0.unk21B8 = 0;
}
