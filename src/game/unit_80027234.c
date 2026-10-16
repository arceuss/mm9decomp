#include "types.h"

typedef struct Unk80027234List {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ u32* items;
    /* 0x10 */ u8 pad10[0x12 - 0x10];
    /* 0x12 */ u16 count;
} Unk80027234List;

typedef struct Unk80027234State {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ Unk80027234List* list;
} Unk80027234State;

typedef struct Unk80301320 {
    /* 0x00 */ u8 pad0[0x5C];
    /* 0x5C */ Unk80027234State* state;
    /* 0x60 */ u8 pad60[0x68 - 0x60];
} Unk80301320;

extern Unk80301320 lbl_80301320;
extern u32 lbl_80263B30[14];

u8 fn_80027234(u32* out, u32 mask, BOOL withList) {
    u8 n = 0;
    s32 i;

    if (mask != 0) {
        for (i = 0; i < 14; i++) {
            if (mask & (1 << i)) {
                out[n++] = lbl_80263B30[i];
            }
        }
        if (withList) {
            for (i = 0; i < lbl_80301320.state->list->count; i++) {
                out[n] = lbl_80301320.state->list->items[i];
                n++;
            }
        }
    }
    return n;
}
