#include "types.h"

typedef struct Unk80301320 {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ u32 flags;
    /* 0x08 */ u8 pad8[0x68 - 0x8];
} Unk80301320;

typedef struct Unk80301388Entry {
    /* 0x0 */ u8 pad0[0x4];
    /* 0x4 */ u16 id;
    /* 0x6 */ u16 flags;
    /* 0x8 */ u8 pad8[0xC - 0x8];
    /* 0xC */ u32 size;
} Unk80301388Entry;

typedef struct Unk80301388 {
    /* 0x00 */ u8 pad0[0x2C];
    /* 0x2C */ Unk80301388Entry* entries;
    /* 0x30 */ u32 count;
} Unk80301388;

extern Unk80301320 lbl_80301320;
extern Unk80301388 lbl_80301388;

char* fn_80027394(s32 key);
s32 fn_80177360(const char* str, char** end, s32 base);
void fn_8024D950(s32 arg0, s32* arg1, s32* arg2);

static inline BOOL Locked(Unk80301388Entry* e, u8 n, u8 id) {
    s32 j;

    for (j = 0; j < n; j++) {
        if (id == e[j].id && (e[j].flags & 0x4000)) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline u32 SizeOf(Unk80301388Entry* e, u8 n, u8 id) {
    s32 k;

    for (k = 0; k < n; k++) {
        if (id == e[k].id) {
            return e[k].size;
        }
    }
    return 0;
}

u32 fn_800265F4(s32 mode) {
    s32 a;
    s32 b;
    u32 blocks;
    s32 value;
    char* str;
    u32 extra;
    u32 i;

    switch (mode) {
    case 0:
        str = fn_80027394(0xC);
        value = str != NULL ? fn_80177360(str, NULL, 10) : 0;
        blocks = (u32)(value + 0x3FFF) >> 14;
        fn_8024D950(1, &a, &b);
        blocks += a;
        break;
    case 1:
        str = fn_80027394(0xC);
        value = str != NULL ? fn_80177360(str, NULL, 10) : 0;
        str = fn_80027394(0xA);
        value -= str != NULL ? fn_80177360(str, NULL, 10) : 0;
        blocks = (u32)(value + 0x3FFF) >> 14;
        fn_8024D950(1, &a, &b);
        blocks += a;
        if (lbl_80301320.flags & 0x80) {
            fn_8024D950(0, &a, &b);
            extra = 0;
            blocks += a;
            if (lbl_80301388.entries != NULL && lbl_80301388.count != 0) {
                for (i = 0; i < lbl_80301388.count; i++) {
                    if (!Locked(lbl_80301388.entries, lbl_80301388.count, i)) {
                        extra += (SizeOf(lbl_80301388.entries, lbl_80301388.count, i) + 0x3FFF) >> 14;
                    }
                }
            }
            blocks += extra;
        }
        break;
    }
    return blocks;
}
