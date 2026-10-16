#include "types.h"
#include "game/obj.h"

typedef struct Unk41840 {
    /* 0x00000 */ u8 pad00000[0x4AEB8];
    /* 0x4AEB8 */ s32 unk4AEB8;
} Unk41840;
extern Unk41840 lbl_8031BF70;
u32 fn_8009E894(s32, s32);

s32 fn_80041840(Obj* obj) {
    s32 x;
    s32 y;
    s32 result = 0;
    x = obj->unk60;
    y = obj->unk64;
    y &= ~0xFFF;
    if ((fn_8009E894(x, y) & 0x8000) || obj->unk64 >= lbl_8031BF70.unk4AEB8) {
        do {
            y -= 0x1000;
        } while (fn_8009E894(x, y) & 0x8000);
        y += 0x1000;
        if (y > lbl_8031BF70.unk4AEB8) {
            y = lbl_8031BF70.unk4AEB8;
        }
        obj->unk64 = y;
    } else {
        do {
            y += 0x1000;
        } while (!(fn_8009E894(x, y) & 0x8000) && y < obj->unk64 + 0x8000);
        if (y > lbl_8031BF70.unk4AEB8) {
            y = lbl_8031BF70.unk4AEB8;
        }
        if (y < obj->unk64 + 0x8000) {
            obj->unk64 = y;
        } else {
            result = 1;
        }
    }
    return result;
}
