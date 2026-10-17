#include "types.h"
typedef struct Unk8007E950 {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 unk0B;
    /* 0x0C */ u8 pad0C[0x60 - 0xC];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
} Unk8007E950;
typedef struct Unk8007E950Work {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ Unk8007E950* unk08;
    /* 0x0C */ u8 pad0C[0x124 - 0xC];
    /* 0x124 */ u8 unk124;
    /* 0x125 */ u8 unk125;
    /* 0x126 */ u8 pad126[0x2D8 - 0x126];
    /* 0x2D8 */ u32 unk2D8;
    /* 0x2DC */ u32 unk2DC;
} Unk8007E950Work;
extern Unk8007E950Work lbl_80304B90;
extern u8 lbl_80271228[], lbl_803140C0[];
extern void fn_8008123C(void*, void*);
s32 fn_800B6450(Unk8007E950* p);
s32 fn_8007E950(Unk8007E950* p) {
    u8* data = lbl_80271228;
    Unk8007E950* q = lbl_80304B90.unk08;
    switch (p->unk0B) {
    case 0:
        if (q->unk60 > 0xB0000 && q->unk60 < 0xC0000 && q->unk64 > 0xE000 && q->unk64 < 0x1C000 && (q->unk0A & 1) && fn_800B6450(q) == 0) {
            if (!(lbl_80304B90.unk2DC & 0x200)) {
                fn_8008123C(&lbl_80304B90.unk124, data + 0x10);
                p->unk0B++;
            } else p->unk0B = 4;
        }
        break;
    case 1:
        if (q->unk60 > 0xC0000 && q->unk60 < 0xD0000 && q->unk64 > 0xE000 && q->unk64 < 0x1C000) {
            fn_8008123C(&lbl_80304B90.unk124, data + 0x40);
            p->unk0B++;
        }
        break;
    case 2:
        if (!(lbl_80304B90.unk125 & 1)) p->unk0B++;
        break;
    case 3:
        if (lbl_80304B90.unk2D8 & 2) p->unk0B++;
        break;
    case 4:
        if (q->unk60 > 0xC0000 && q->unk60 < 0xD0000 && q->unk64 > 0xE000 && q->unk64 < 0x1C000) {
            if (lbl_803140C0[0x227C] == 3)
                fn_8008123C(&lbl_80304B90.unk124, data + 0x110);
            else fn_8008123C(&lbl_80304B90.unk124, data + 0xA0);
            lbl_80304B90.unk125 &= 0xFFFD;
            p->unk0B++;
        }
        break;
    }
    return 0;
}
