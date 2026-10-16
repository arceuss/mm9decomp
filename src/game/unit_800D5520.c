#include "types.h"

typedef struct Unk80280440 {
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u8 pad2[0x4 - 0x2];
} Unk80280440;

extern Unk80280440 lbl_80280440[0x5F];

s32 fn_800D4624(u16 id);

s32 fn_800D5520(s32 index) {
    if (index < 0x5F) {
        return fn_800D4624(lbl_80280440[index].unk0);
    }
    return 0;
}
