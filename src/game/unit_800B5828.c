#include "types.h"

typedef struct UnkB5828 {
    /* 0x000 */ u8 pad0[0xEF];
    /* 0x0EF */ u8 unkEF;
    /* 0x0F0 */ u8 unkF0;
    /* 0x0F1 */ u8 unkF1;
    /* 0x0F2 */ u8 unkF2;
    /* 0x0F3 */ u8 unkF3;
    /* 0x0F4 */ u8 unkF4;
    /* 0x0F5 */ u8 pad0F5[0x10C - 0x0F5];
    /* 0x10C */ u8 unk10C;
} UnkB5828;

extern s32 (*lbl_8027E830[][4])(void);

s32 fn_800B5828(UnkB5828* obj, u32 idx) {
    if (obj->unkF2 >= 2) {
        s32 (*f)(void) = lbl_8027E830[obj->unk10C][idx];
        if (f) {
            return f();
        }
    }
    obj->unkF2 = obj->unkEF;
    obj->unkEF = 1;
    obj->unkF3 = obj->unkF0;
    obj->unkF0 = 0;
    obj->unkF4 = obj->unkF1;
    obj->unkF1 = 0;
    return 1;
}
