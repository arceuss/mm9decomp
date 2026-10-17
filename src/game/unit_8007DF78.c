#include "types.h"
typedef struct Unk8007DF78 {
    /* 0x00 */ u8 pad00[0xB];
    /* 0x0B */ u8 unk0B;
    /* 0x0C */ u8 pad0C[0x60 - 0xC];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
} Unk8007DF78;
typedef struct Unk8007DF78Work {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ Unk8007DF78* unk08;
    /* 0x0C */ u8 pad0C[0x124 - 0xC];
    /* 0x124 */ u8 unk124;
    /* 0x125 */ u8 unk125;
    /* 0x126 */ u8 pad126[0x2D8 - 0x126];
    /* 0x2D8 */ u32 unk2D8;
    /* 0x2DC */ u32 unk2DC;
} Unk8007DF78Work;
extern Unk8007DF78Work lbl_80304B90;
extern u8 lbl_802703D0[], lbl_803140C0[];
extern void fn_8008123C(void*, void*);
s32 fn_8007DF78(Unk8007DF78* p) {
    u8* data = lbl_802703D0;
    Unk8007DF78* q = lbl_80304B90.unk08;
    switch (p->unk0B) {
    case 0:
        if (q->unk60 > 0xf0000 && q->unk60 < 0x100000 && q->unk64 > 0x70000 && q->unk64 < 0x7e000) {
            if (!(lbl_80304B90.unk2DC & 0x4)) {
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
        else fn_8008123C(&lbl_80304B90.unk124, data + 0xb8);
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
