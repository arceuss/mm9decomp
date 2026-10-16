#include "game/work_802BDCC0.h"

typedef struct Unk8038E140 {
    /* 0x000 */ u8 pad0[0x68];
    /* 0x068 */ u32 unk68[7][2];
    /* 0x0A0 */ u32 padA0;
    /* 0x0A4 */ u32 unkA4;
    /* 0x0A8 */ u8 padA8[0xC0 - 0xA8];
    /* 0x0C0 */ u8 unkC0[0x124 - 0xC0];
} Unk8038E140;

extern Unk8038E140 lbl_8038E140;
extern Unk8038E140 lbl_8038E280;

void fn_8009C04C(u32 fill, void* dst, u32 size);
void fn_800C6660(void* arg0);
BOOL fn_8000C5A4(s32 kind, u32 size);
void fn_8000D6F0(s32 kind, void* data, u32 size);

static inline void InitSave(Unk8038E140* save) {
    u8 i;

    fn_8009C04C(0, save, 0x124);
    for (i = 0; i < 7; i++) {
        save->unk68[i][0] = 0x8CA0;
        save->unk68[i][1] = 0x8CA0;
    }
    save->unkA4 = 0x14996FF;
    fn_800C6660(save->unkC0);
}

void fn_800E504C(void) {
    InitSave(&lbl_8038E140);
    InitSave(&lbl_8038E280);
    if (fn_8000C5A4(8, 0x124)) {
        fn_8000D6F0(8, &lbl_8038E280, 0x124);
    } else {
        lbl_802BDCC0.unkF0BE = 1;
    }
}
