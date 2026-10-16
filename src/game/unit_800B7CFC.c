#include "types.h"
#include "game/work_8031BF70.h"

typedef struct Unk800B7CFCObj {
    /* 0x00 */ u8 pad0[0x24];
    /* 0x24 */ s32 unk24;
} Unk800B7CFCObj;

BOOL fn_800B7CFC(Unk8031BF70Vec* pos, Unk800B7CFCObj* obj, Unk8031BF70Vec* a, Unk8031BF70Vec* b, s32 index, u32 flags) {
    Unk8031BF70_290* rec;
    s32 d;
    s32 dir;
    s32 by = b->y;
    s32 ay = a->y;

    if (!((flags >> 19) & 1) || by == ay) {
        rec = &lbl_8031BF70.unk290[index];
        if ((u32)(rec->unk4 + (pos->x - rec->unk8)) < (u32)(rec->unk4 * 2)) {
            return TRUE;
        }
        dir = (s32)((flags >> 17) & 2) - 1;
        d = obj->unk24 - pos->x;
        if (d == 0 || d * dir > 0) {
            return FALSE;
        }
        return TRUE;
    }
    return by < ay;
}
