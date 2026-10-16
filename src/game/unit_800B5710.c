#include "types.h"

typedef struct UnkVec2 {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} UnkVec2;

extern s32* lbl_8027EB60[];

s32 fn_800B916C(s32* a, u8* b, s32 c, s32 d, s32 e, s32 f, s32 g);
s32 fn_800B93AC(s32* a, u8* b, s32 c, s32 d);
void fn_800B9F74(u8* obj, s32 v);

void fn_800B5710(u8* obj) {
    UnkVec2 local;
    s32 r31 = 5;
    u8* p;

    local = *(UnkVec2*)(obj + 0x60);
    local.y -= ((obj[0xFC] == 6) ? 0x100 : 0x160) -
               obj[0x120] * ((obj[0xFC] == 6) ? 0x100 : 0x160) / 100;
    p = obj + 0x19C;
    if (fn_800B916C((s32*)&local, p, *(s32*)p, 0, 0, 0,
                    ((obj[0xA] << 14) & 0x40000)) == 0) {
        if (fn_800B93AC((s32*)&local, p, *(s32*)p, 0x10000) == 0) {
            r31 = 6;
        }
    }
    obj[0xFC] = r31;
    fn_800B9F74(obj, ((s32**)lbl_8027EB60)[obj[9]][r31]);
}
