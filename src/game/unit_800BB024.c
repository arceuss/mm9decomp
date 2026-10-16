#include "types.h"

typedef struct Unk8043CA80Entry {
    /* 0x0 */ u32 kind : 2;
    /* 0x0 */ u32 size : 30;
    /* 0x4 */ void* dst;
    /* 0x8 */ void* src;
} Unk8043CA80Entry;

typedef struct Unk8043CA80 {
    /* 0x000 */ s32 count;
    /* 0x004 */ Unk8043CA80Entry entries[0x30];
    /* 0x244 */ u8 pad244[0x258 - 0x244];
    /* 0x258 */ u8* unk258[2];
    /* 0x260 */ u32 unk260[2];
} Unk8043CA80;

extern Unk8043CA80 lbl_8038B2F8;

void fn_800BB024(void* src, void* dst, u32 size) {
    Unk8043CA80Entry* entry;

    if (lbl_8038B2F8.count < 0x20) {
        entry = &lbl_8038B2F8.entries[lbl_8038B2F8.count];
        entry->kind = 3;
        entry->size = size;
        entry->dst = dst;
        entry->src = src;
        lbl_8038B2F8.count++;
    }
}
