#include "types.h"
typedef struct Unk8007E518 {
    /* 0x00 */ u8 pad00[0xB];
    /* 0x0B */ u8 unk0B;
    /* 0x0C */ u8 pad0C[0x60 - 0xC];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
} Unk8007E518;
typedef struct Unk8007E518Work {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ Unk8007E518* unk08;
    /* 0x0C */ u8 pad0C[0x124 - 0xC];
    /* 0x124 */ u8 unk124;
    /* 0x125 */ u8 unk125;
    /* 0x126 */ u8 pad126[0x2D8 - 0x126];
    /* 0x2D8 */ u32 unk2D8;
    /* 0x2DC */ u32 unk2DC;
} Unk8007E518Work;
extern Unk8007E518Work lbl_80304B90;
extern u8 lbl_80270C08[], lbl_803140C0[];
extern void fn_8008123C(void*, void*);
s32 fn_8007E518(Unk8007E518* p) {
    u8* data = lbl_80270C08;
    Unk8007E518* q = lbl_80304B90.unk08;
    switch (p->unk0B) {
    case 0:
        if (q->unk60 > 0xd0000 && q->unk60 < 0xe0000 && q->unk64 > 0x2a000 && q->unk64 < 0x38000) {
            if (!(lbl_80304B90.unk2DC & 0x40)) {
                fn_8008123C(&lbl_80304B90.unk124, data + 0x20);
                p->unk0B++;
            } else p->unk0B = 5;
        }
        break;
    case 1:
        if (!(lbl_80304B90.unk125 & 1)) p->unk0B++;
        break;
    case 2:
        if (lbl_80304B90.unk2D8 & 2) p->unk0B++;
        break;
    case 3:
        if (lbl_803140C0[0x227C] == 3)
            fn_8008123C(&lbl_80304B90.unk124, data + 0x198);
        else fn_8008123C(&lbl_80304B90.unk124, data + 0xa8);
        lbl_80304B90.unk125 &= 0xFFFD;
        p->unk0B++;
        break;
    case 5:
        fn_8008123C(&lbl_80304B90.unk124, data + 0x168);
        p->unk0B++;
        break;
    }
    return 0;
}
