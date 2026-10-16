#include "types.h"

typedef struct Unk80280440 {
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u8 pad2[0x4 - 0x2];
} Unk80280440;

extern Unk80280440 lbl_80280440[0x5F];

void fn_800D474C(u16 id, s32 arg1);

void fn_800D5544(s32 index, s32 arg1) {
    if (index < 0x5F) {
        fn_800D474C(lbl_80280440[index].unk0, arg1);
    }
}
