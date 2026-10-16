#include "game/work_802BDCC0.h"

typedef struct Unk8038E140 {
    /* 0x000 */ u32 bits;
    /* 0x004 */ u8 unk4[0x24 - 0x4];
    /* 0x024 */ u32 unk24[(0x124 - 0x24) / 4];
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


static inline u32 GetValue(u16 id) {
    return lbl_8038E140.unk24[id];
}

static inline void SetValue(s32 id, u32 value) {
    lbl_8038E140.unk24[id] = value;
}

void fn_800E5424(u16 id, u32 value) {
    BOOL changed = FALSE;

    if (value != GetValue(id)) {
        changed = TRUE;
    }
    SetValue(id, value);
    if (changed) {
        Commit();
    }
}
