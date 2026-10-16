#include "types.h"
typedef struct Unk8007ED0C {
    /* 0x00 */ u8 pad00[0xB];
    /* 0x0B */ u8 unk0B;
    /* 0x0C */ u8 pad0C[0x60 - 0xC];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
} Unk8007ED0C;
typedef struct Unk8007ED0CWork {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ Unk8007ED0C* unk08;
    /* 0x0C */ u8 pad0C[0x124 - 0xC];
    /* 0x124 */ u8 unk124;
    /* 0x125 */ u8 unk125;
    /* 0x126 */ u8 pad126[0x2D8 - 0x126];
    /* 0x2D8 */ u32 unk2D8;
    /* 0x2DC */ u32 unk2DC;
} Unk8007ED0CWork;
extern Unk8007ED0CWork lbl_80304B90;
extern u8 lbl_80271668[], lbl_803140C0[];
extern void fn_8008123C(void*, void*);
s32 fn_8007ED0C(Unk8007ED0C* p) {
    u8* data = lbl_80271668;
    Unk8007ED0C* q = lbl_80304B90.unk08;
    switch (p->unk0B) {
    case 0:
        if (q->unk60 > 0x100000 && q->unk60 < 0x110000 && q->unk64 > 0x38000 && q->unk64 < 0x46000) {
            if (!(lbl_80304B90.unk2DC & 0x800)) {
                fn_8008123C(&lbl_80304B90.unk124, data + 0x10);
                p->unk0B++;
            } else p->unk0B = 3;
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
            fn_8008123C(&lbl_80304B90.unk124, data + 0x108);
        else fn_8008123C(&lbl_80304B90.unk124, data + 0x98);
        lbl_80304B90.unk125 &= 0xFFFD;
        p->unk0B++;
        break;
    }
    return 0;
}
