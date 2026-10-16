#include "types.h"
typedef struct Unk8007EB34 {
    /* 0x00 */ u8 pad00[0xB];
    /* 0x0B */ u8 unk0B;
    /* 0x0C */ u8 pad0C[0x60 - 0xC];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
} Unk8007EB34;
typedef struct Unk8007EB34Work {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ Unk8007EB34* unk08;
    /* 0x0C */ u8 pad0C[0x124 - 0xC];
    /* 0x124 */ u8 unk124;
    /* 0x125 */ u8 unk125;
    /* 0x126 */ u8 pad126[0x2D8 - 0x126];
    /* 0x2D8 */ u32 unk2D8;
    /* 0x2DC */ u32 unk2DC;
} Unk8007EB34Work;
extern Unk8007EB34Work lbl_80304B90;
extern u8 lbl_802713A8[], lbl_803140C0[];
extern void fn_8008123C(void*, void*);
s32 fn_8007EB34(Unk8007EB34* p) {
    u8* data = lbl_802713A8;
    Unk8007EB34* q = lbl_80304B90.unk08;
    switch (p->unk0B) {
    case 0:
        if (q->unk60 > 0x60000 && q->unk60 < 0x70000 && q->unk64 > 0x1C000 && q->unk64 < 0x2A000) {
            if (!(lbl_80304B90.unk2DC & 0x400)) {
                fn_8008123C(&lbl_80304B90.unk124, data + 0x30);
                p->unk0B++;
            } else p->unk0B = 7;
        }
        break;
    case 1:
        if (!(lbl_80304B90.unk125 & 1)) p->unk0B++;
        break;
    case 2:
        if (lbl_80304B90.unk2D8 & 2) {
            lbl_80304B90.unk125 &= 0xFFFD;
            fn_8008123C(&lbl_80304B90.unk124, data + 0xC0);
            p->unk0B++;
        }
        break;
    case 3:
        if (!(lbl_80304B90.unk125 & 1)) p->unk0B++;
        break;
    case 4:
        if (lbl_80304B90.unk2D8 & 2) {
            lbl_80304B90.unk125 &= 0xFFFD;
            fn_8008123C(&lbl_80304B90.unk124, data + 0x140);
            p->unk0B++;
        }
        break;
    case 5:
        if (!(lbl_80304B90.unk125 & 1)) p->unk0B++;
        break;
    case 6:
        if (lbl_80304B90.unk2D8 & 2) p->unk0B++;
        break;
    case 7:
        if (lbl_803140C0[0x227C] == 3)
            fn_8008123C(&lbl_80304B90.unk124, data + 0x230);
        else fn_8008123C(&lbl_80304B90.unk124, data + 0x1C0);
        lbl_80304B90.unk125 &= 0xFFFD;
        p->unk0B++;
        break;
    }
    return 0;
}
