#include "types.h"

typedef struct Unk80280440 {
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u8 pad2[0x4 - 0x2];
} Unk80280440;

extern Unk80280440 lbl_80280440[0x5F];

void fn_800D443C(u16 id);

void fn_800D5458(s32 index) {
    if (index < 0x5F) {
        fn_800D443C(lbl_80280440[index].unk0);
    }
}
