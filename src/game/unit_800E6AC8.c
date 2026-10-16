#include "types.h"

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

typedef struct Unk8039B190 {
    /* 0x00 */ u8* bufs[4];
    /* 0x10 */ u8 pad10[0x90 - 0x10];
    /* 0x90 */ u8 flags[4];
    /* 0x94 */ s32 vals[4];
} Unk8039B190;

extern Unk80316D78 lbl_80316D78;
extern Unk8039B190 lbl_8039B190;
extern s32 lbl_80281E48[4];

void fn_8000EB5C(void);

void fn_800E6AC8(void) {
    u8* base = lbl_80316D78.unk3004 + 0xA20000;
    s32 i;
    u32 j;

    for (i = 0; i < 4; i++) {
        lbl_8039B190.bufs[i] = base + i * 0x40000;
    }
    for (i = 0; i < 4; i++) {
        j = lbl_80281E48[i] >> 4;
        lbl_8039B190.flags[j] = 0;
        lbl_8039B190.vals[j] = 0;
    }
    fn_8000EB5C();
}
