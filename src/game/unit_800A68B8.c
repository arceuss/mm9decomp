#include "types.h"

typedef struct Unk8037C358 {
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u8 pad2[0x4 - 0x2];
    /* 0x4 */ u8 unk4[0x10 - 0x4];
} Unk8037C358;

extern Unk8037C358 lbl_8037C358[8];

void fn_800C9F8C(void* arg0);

void fn_800A68B8(void) {
    Unk8037C358* entry = lbl_8037C358;
    s32 i;

    for (i = 0; i < 8; i++) {
        if (entry->unk0 != 0) {
            fn_800C9F8C(entry->unk4);
        }
        entry++;
    }
}
