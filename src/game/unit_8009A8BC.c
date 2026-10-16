#include "types.h"
typedef struct Unk8009A8BC {
    /* 0x00 */ u8 pad00[0x18];
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u8 pad1C[0x7];
    /* 0x23 */ u8 unk23a:4;
    /* 0x23 */ u8 unk23b:4;
    /* 0x24 */ u8 pad24[0xA];
    /* 0x2E */ s16 unk2E;
} Unk8009A8BC;
typedef struct Unk8009A8BCNode {
    /* 0x00 */ struct Unk8009A8BCNode* unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ Unk8009A8BC* unk08;
} Unk8009A8BCNode;
typedef struct Unk8009A8BCWork {
    /* 0x00 */ u8 unk00;
    /* 0x01 */ u8 unk01;
    /* 0x02 */ u8 pad02[0x910 - 2];
    /* 0x910 */ Unk8009A8BCNode* unk910[3];
} Unk8009A8BCWork;
extern Unk8009A8BCWork lbl_80316398;
void fn_8009A8BC(s32 unused) {
    s32 i;
    Unk8009A8BCNode* n;
    for (i = 0; i < 3; i++) {
        if (lbl_80316398.unk01 & (1 << i)) {
            n = lbl_80316398.unk910[i];
            while (n) {
                n->unk08->unk23b = 0;
                if (n->unk08->unk2E != 0) {
                    n->unk08->unk2E = 0;
                    n->unk08->unk18 |= 0x201;
                } else n->unk08->unk18 |= 0x200;
                n = n->unk00;
            }
        }
    }
}
