#include "types.h"

typedef struct Unk800B73B8 {
    /* 0x000 */ u8 pad0[0x11C];
    /* 0x11C */ u8 unk11C;
    /* 0x11D */ u8 pad11D[0x18C - 0x11D];
    /* 0x18C */ u16 unk18C;
} Unk800B73B8;

extern u16 lbl_8027EAE8[8];
extern u8 lbl_8027EAD8[16];

void fn_800B748C(Unk800B73B8* p);
void fn_800B75D0(Unk800B73B8* p);

void fn_800B73B8(Unk800B73B8* p) {
    s32 sum = 0;
    s32 i;

    fn_800B748C(p);
    fn_800B75D0(p);
    for (i = 0; i < 7; i++) {
        if (p->unk18C & lbl_8027EAE8[i]) {
            sum += lbl_8027EAD8[i];
        }
    }
    p->unk11C = sum;
}
