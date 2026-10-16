#include "game/work_802BDCC0.h"

typedef struct Unk8038E140 {
    /* 0x000 */ u32 bits[0x124 / 4];
} Unk8038E140;

typedef struct Unk8038E140Copy {
    /* 0x000 */ u32 data[0x124 / 4];
} Unk8038E140Copy;

extern Unk8038E140 lbl_8038E140;
extern Unk8038E140Copy lbl_8038E280;
extern u8 lbl_804EE958;

void fn_8000D664(s32 kind, void* data, u32 size);

static inline void Commit(void) {
    s16 slot;

    lbl_8038E280 = *(Unk8038E140Copy*)&lbl_8038E140;
    if (lbl_802BDCC0.unkF0AA == 2) {
        slot = 0;
    } else {
        slot = lbl_802BDCC0.unkF0BC;
    }
    if (slot != 0) {
        fn_8000D664(8, &lbl_8038E280, 0x124);
    } else {
        lbl_804EE958 = 1;
    }
}


static inline BOOL TestBit(u16 n) {
    return lbl_8038E140.bits[n >> 5] & (1 << (n & 31));
}

static inline void SetBit(u32 n) {
    lbl_8038E140.bits[n / 32] |= 1 << (n % 32);
}

static inline void ClearBit(u32 n) {
    lbl_8038E140.bits[n / 32] &= ~(1 << (n % 32));
}

void fn_800E534C(u16 n) {
    BOOL changed = FALSE;

    if (TestBit(n)) {
        changed = TRUE;
    }
    ClearBit(n);
    if (changed) {
        Commit();
    }
}
