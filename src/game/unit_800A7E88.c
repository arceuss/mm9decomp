#include "types.h"

typedef struct Unk800A7E88 {
    /* 0x00 */ u16* unk0;
    /* 0x04 */ u8 pad4[0x8 - 0x4];
    /* 0x08 */ u16 unk8;
} Unk800A7E88;

void fn_800AA8C4(s32 arg0, u16 index, u16 slot);
void fn_800AA6D8(s32 arg0, u16* index, s32 count);
void fn_800AA9A4(void);
void fn_800A7D8C(Unk800A7E88* s);

void fn_800A7E88(Unk800A7E88* s) {
    u32 i;
    u16 e;
    u16 index;

    for (i = 0; i < (u8)s->unk8; i++) {
        e = s->unk0[i];
        if (e & 0x2000) {
            u16 slot = 0x1FF - ((e >> 10) & 7);
            index = e & 0x3FF;
            fn_800AA8C4(1, index, slot);
            fn_800AA8C4(2, index, slot);
        } else {
            index = e & 0x3FF;
            fn_800AA6D8(1, &index, 1);
            fn_800AA6D8(2, &index, 1);
        }
    }
    fn_800AA9A4();
    fn_800A7D8C(s);
}
