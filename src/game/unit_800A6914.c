#include "types.h"
typedef struct Unk800A6914 {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ u16 unk02;
    /* 0x04 */ u16* unk04;
    /* 0x08 */ u8 unk08;
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 pad0A[6];
} Unk800A6914;
extern Unk800A6914 lbl_8037C358[8];
extern u8 lbl_80383E70[];
extern void fn_800A7F64(s32, s32, s32, s32);
void fn_800A6914(void) {
    s32 i;
    u8* work = lbl_80383E70;
    Unk800A6914* p = lbl_8037C358;
    for (i = 0; i < 8; i++, p++) {
        if (p->unk00 != 0) {
            u8 index = *((u8*)(p->unk04 + p->unk09) + p->unk04[p->unk08]);
            u8* data = *(u8**)(work + 0x800 + p->unk00 * 4);
            u8* frames = data + *(u32*)data;
            fn_800A7F64(p->unk02, frames[index * 4 + 7], 0, 0);
        }
    }
}
