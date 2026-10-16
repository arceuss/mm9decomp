#include "types.h"

typedef struct Unk8043CA80Entry {
    /* 0x0 */ u32 kind : 2;
    /* 0x0 */ u32 size : 30;
    /* 0x4 */ void* dst;
    /* 0x8 */ void* src;
} Unk8043CA80Entry;

typedef struct Unk800BAF48Sub {
    /* 0x0000 */ u8 pad0[0x10];
} Unk800BAF48Sub;

typedef struct Unk8043CA80 {
    /* 0x000 */ s32 count;
    /* 0x004 */ Unk8043CA80Entry entries[0x20];
    /* 0x184 */ u8* unk184;
} Unk8043CA80;

extern Unk8043CA80 lbl_8038B2F8;

typedef struct Unk800BAF48Src {
    /* 0x0 */ s32 offset;
    /* 0x4 */ u16 size;
    /* 0x6 */ u8 flags;
    /* 0x7 */ u8 unk7;
} Unk800BAF48Src;

void fn_80120A18(void* src, void* dst);
void fn_8009C110(void* src, void* dst, u32 size);

void fn_800BAF48(Unk800BAF48Src* src, u32 dst) {
    Unk8043CA80Entry* entry;
    u8* p;

    if (dst < 0x10000000) {
        p = lbl_8038B2F8.unk184 + (dst & 0xFFFF) + (src->unk7 << 5);
        if ((src->flags >> 7) & 1) {
            fn_80120A18((u8*)src + src->offset, p);
        } else {
            fn_8009C110((u8*)src + src->offset, p, src->size);
        }
        return;
    }
    if (lbl_8038B2F8.count < 0x20) {
        entry = &lbl_8038B2F8.entries[lbl_8038B2F8.count];
        entry->kind = 0;
        entry->dst = (void*)dst;
        entry->src = src;
        lbl_8038B2F8.count++;
    }
}
