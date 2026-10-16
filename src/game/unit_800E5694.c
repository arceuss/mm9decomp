#include "types.h"

typedef struct Unk8038E738 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 unkD_hi : 4;
    /* 0x0D */ u8 unkD_lo : 4;
    /* 0x0E */ u8 padE[0x14 - 0xE];
    /* 0x14 */ u8 state;
    /* 0x15 */ u8 step;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 pad18[0x1F - 0x18];
    /* 0x1F */ u8 unk1F;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x38 - 0x30];
    /* 0x38 */ u8 unk38;
    /* 0x39 */ u8 unk39;
    /* 0x3A */ u8 pad3A[0x88 - 0x3A];
} Unk8038E738;

extern Unk8038E738 lbl_8038E738;


typedef struct Unk80301280Table {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ u16 unk8[1];
} Unk80301280Table;

typedef struct Unk80301280 {
    /* 0x00 */ u8 pad0[0x40];
    /* 0x40 */ Unk80301280Table* unk40;
    /* 0x44 */ u8 pad44[0x48 - 0x44];
} Unk80301280;

extern Unk80301280 lbl_80301280;
extern u8 lbl_8038E3A8[];

s32 fn_8000EEFC(s32 id);
void fn_800A59F4(void* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7,
                 s32 arg8, s32 arg9, s32 arg10, s32 arg11, s32 arg12);

static inline void Reset(void) {
    lbl_8038E738.unk8 = 0;
    lbl_8038E738.unkD_hi = 0;
    lbl_8038E738.unkD_lo = 0;
    lbl_8038E738.unk1F = 0;
    lbl_8038E738.unkC = 0;
    lbl_8038E738.unk24 = lbl_8038E738.unk20;
    lbl_8038E738.unk28 = 0;
    lbl_8038E738.unk2C = 0;
    lbl_8038E738.state = 0;
    lbl_8038E738.step = 0;
    lbl_8038E738.unk16 = 0;
    lbl_8038E738.unk17 = 0;
    lbl_8038E738.unkA = 0;
}

void fn_800E5694(s32 id, s32 arg1, u8 arg2) {
    u16 flags;
    s32 ret;

    lbl_8038E738.unk0 = 0;
    lbl_8038E738.unk4 = arg1;
    lbl_8038E738.unk39 = 0;
    lbl_8038E738.unk38 = 0;
    flags = lbl_80301280.unk40->unk8[id >> 4];
    ret = fn_8000EEFC(id);
    fn_800A59F4(lbl_8038E3A8, 0, 0x5C00, arg2 << 5, 0x18, 5, 4, 1, flags & 0x1F00, flags & 0xC000, ret, 4, 0x17);
    Reset();
}
