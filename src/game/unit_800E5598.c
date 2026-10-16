#include "game/work_802BDCC0.h"

typedef struct Unk800E5598Block {
    /* 0x00 */ u32 data[0x64 / 4];
} Unk800E5598Block;

typedef struct Unk8038E140 {
    /* 0x000 */ u32 pad0[0xC0 / 4];
    /* 0x0C0 */ Unk800E5598Block unkC0;
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

void fn_800E5598(Unk800E5598Block* block) {
    lbl_8038E140.unkC0 = *block;
    Commit();
}
