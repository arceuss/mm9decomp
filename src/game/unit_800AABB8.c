#include "types.h"

typedef struct Unk80383E70 {
    /* 0x0000 */ u8 pad0[0x2018];
    /* 0x2018 */ u8 unk2018[0x7488 - 0x2018];
} Unk80383E70;

typedef struct Unk800AABB8Ctx {
    /* 0x00 */ u8 pad0[0x20];
} Unk800AABB8Ctx;

extern Unk80383E70 lbl_80383E70;

void fn_801E263C(s32 arg0, Unk800AABB8Ctx* ctx, void* buf);
void fn_800AB27C(void);
s32 fn_800AAC38(Unk800AABB8Ctx* ctx, s32 arg1, s32 arg2, s32 arg3);
void fn_801E2648(Unk800AABB8Ctx* ctx);

s32 fn_800AABB8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Unk800AABB8Ctx ctx;
    s32 result;

    fn_801E263C(arg0, &ctx, lbl_80383E70.unk2018);
    fn_800AB27C();
    result = fn_800AAC38(&ctx, arg1, arg2, arg3);
    fn_801E2648(&ctx);
    fn_800AB27C();
    return result;
}
