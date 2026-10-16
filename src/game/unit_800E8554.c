#include "types.h"

typedef struct Unk8043CA80Entry {
    /* 0x0 */ u32 mode : 2;
    /* 0x0 */ u32 rest : 30;
    /* 0x4 */ u32 b;
    /* 0x8 */ u32 a;
} Unk8043CA80Entry;

typedef struct Unk8043CA80 {
    /* 0x000 */ u32 count;
    /* 0x004 */ Unk8043CA80Entry entries[0x30];
} Unk8043CA80;

extern Unk8043CA80 lbl_8043CA80;

void fn_800E8554(u32 a, u32 b) {
    u32 i;
    Unk8043CA80Entry* e;

    for (i = 0; i < lbl_8043CA80.count; i++) {
        if (a == lbl_8043CA80.entries[i].a && b == lbl_8043CA80.entries[i].b) {
            return;
        }
    }
    if (lbl_8043CA80.count >= 0x30) {
        return;
    }
    e = &lbl_8043CA80.entries[i];
    e->mode = 0;
    e->b = b;
    e->a = a;
    lbl_8043CA80.count++;
}
