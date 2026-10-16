#include "types.h"

typedef struct Unk8043CA80Entry {
    /* 0x0 */ u32 info;
    /* 0x4 */ u32 addr;
    /* 0x8 */ void* src;
} Unk8043CA80Entry;

typedef struct Unk8043CA80Copy {
    /* 0x0 */ u32 size;
    /* 0x4 */ void* src;
    /* 0x8 */ u32 addr;
    /* 0xC */ void* clear;
} Unk8043CA80Copy;

typedef struct Unk8043CA80 {
    /* 0x000 */ u32 count;
    /* 0x004 */ Unk8043CA80Entry entries[0x30];
    /* 0x244 */ Unk8043CA80Copy* pending;
    /* 0x248 */ u8 pad248[0x258 - 0x248];
    /* 0x258 */ u8* vram0;
    /* 0x25C */ u8* vram1;
    /* 0x260 */ u8 pad260[0x268 - 0x260];
} Unk8043CA80;

extern Unk8043CA80 lbl_8043CA80;

void fn_8009C100(void* src, void* dst, u32 size);
void fn_8009C04C(u32 fill, void* dst, u32 size);
void fn_800E83A4(void* src, u32 addr);

static inline u8* Vram(u32 addr) {
    return (addr < 0x400000 ? lbl_8043CA80.vram0 : lbl_8043CA80.vram1) + (addr & 0xFFFFF);
}

void fn_800E8278(void) {
    Unk8043CA80Copy* copy = lbl_8043CA80.pending;
    Unk8043CA80Entry* e;
    u32 i = 0;
    u32 type;

    if (copy->src != NULL) {
        fn_8009C100(copy->src, Vram(copy->addr), copy->size);
        fn_8009C04C((u32)copy->clear, copy->src, copy->size);
    }
    for (e = lbl_8043CA80.entries; i < lbl_8043CA80.count; e++, i++) {
        type = e->info >> 30;
        if (type != 0) {
            if (type == 1) {
                fn_8009C100(e->src, Vram(e->addr), e->info & 0x3FFFFFFF);
            } else {
                fn_8009C04C((u32)e->src, Vram(e->addr), e->info & 0x3FFFFFFF);
            }
        } else {
            fn_800E83A4(e->src, e->addr);
        }
    }
    lbl_8043CA80.count = 0;
}
