#include "types.h"

typedef struct Unk8038E038Item {
    /* 0x00 */ u8 pad0[0x38];
    /* 0x38 */ u8 unk38;
} Unk8038E038Item;

typedef struct Unk8038E038Rec {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u16 unkC;
    /* 0x0E */ u16 unkE;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
} Unk8038E038Rec;

typedef struct Unk8038E038 {
    /* 0x000 */ Unk8038E038Item* lists[3][4];
    /* 0x030 */ u32 counts[3];
    /* 0x03C */ u8 mutex[0x54 - 0x3C];
    /* 0x054 */ Unk8038E038Rec recs[4];
    /* 0x0D4 */ u32 recCount;
    /* 0x0D8 */ u8 padD8[0x108 - 0xD8];
} Unk8038E038;

extern Unk8038E038 lbl_8038E038;

void OSLockMutex(void* mutex);
void OSUnlockMutex(void* mutex);

typedef struct Unk800D5D8CInfo {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ u16 unk2;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
} Unk800D5D8CInfo;

typedef struct Unk800D5D8CHandle {
    /* 0x0 */ Unk800D5D8CInfo* info;
} Unk800D5D8CHandle;

Unk800D5D8CHandle* fn_80150E34(void* a, void* b);

void fn_800D5D8C(s32 id, void* a, void* b) {
    u32 n = lbl_8038E038.recCount;
    Unk8038E038Rec* rec;
    Unk800D5D8CHandle* h;

    if (n + 1 <= 4) {
        h = fn_80150E34(a, b);
        rec = &lbl_8038E038.recs[n];
        rec->unk0 = id;
        rec->unk4 = h->info->unk8;
        rec->unk8 = h->info->unk4;
        rec->unkC = h->info->unk2;
        rec->unkE = h->info->unk0;
        rec->unk10 = h->info->unkC;
        rec->unk14 = h->info->unk10;
        rec->unk18 = 1;
        rec->unk1C = 1;
        lbl_8038E038.recCount = n + 1;
    }
}
