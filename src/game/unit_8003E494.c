#include "types.h"

typedef struct Unk8003E494Hdr {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ u32 unk8;
} Unk8003E494Hdr;

typedef struct Unk8003E494 {
    /* 0x000 */ u8 pad0[0x288];
    /* 0x288 */ Unk8003E494Hdr* unk288;
    /* 0x28C */ u8 pad28C[0x2B0 - 0x28C];
    /* 0x2B0 */ u8 unk2B0;
} Unk8003E494;

typedef struct Unk8038E140 {
    /* 0x000 */ u32 bits;
    /* 0x004 */ u8 pad4[0x140 - 0x4];
} Unk8038E140;

typedef struct Unk80383E70 {
    /* 0x0000 */ u8 pad0[0x7480];
    /* 0x7480 */ u32 unk7480;
} Unk80383E70;

extern u8 lbl_80264B94[];
extern Unk8038E140 lbl_8038E140;
extern Unk80383E70 lbl_80383E70;

void fn_8000ECB8(s32 arg0, void* data, u8 tile, s32 arg3, s8 y);

void fn_8003E494(Unk8003E494* p) {
    BOOL locked = FALSE;
    s32 i;
    s32 y = 0;
    u8 slot = p->unk2B0;

    for (i = 0; i < 9; i++) {
        if (!locked) {
            fn_8000ECB8(0x38, (void*)((p->unk288->unk8 >> 1) + (u32)p->unk288), lbl_80264B94[slot], 3, y + 8);
        } else {
            fn_8000ECB8(0x38, (void*)((p->unk288->unk8 >> 1) + (u32)p->unk288), 0x19, 3, y + 8);
        }
        slot++;
        if (slot == 8) {
            locked = FALSE;
            if (!(lbl_8038E140.bits & 4)) {
                locked = TRUE;
            }
        }
        if (slot == 12) {
            locked = FALSE;
            if (!(lbl_80383E70.unk7480 & 0x10)) {
                locked = TRUE;
            }
        }
        y += 2;
    }
}
