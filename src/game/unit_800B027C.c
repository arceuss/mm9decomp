#include "types.h"

typedef struct UnkB027C {
    /* 0x000 */ u8 pad000[0xEF];
    /* 0x0EF */ u8 unkEF;
    /* 0x0F0 */ u8 unkF0;
    /* 0x0F1 */ u8 unkF1;
    /* 0x0F2 */ u8 unkF2;
    /* 0x0F3 */ u8 unkF3;
    /* 0x0F4 */ u8 unkF4;
    /* 0x0F5 */ u8 pad0F5[0x10C - 0xF5];
    /* 0x10C */ u8 unk10C;
} UnkB027C;

extern u32 (*lbl_8027E794[])(UnkB027C*);
extern void (*lbl_8027E768[])(UnkB027C*);

void fn_800B027C(UnkB027C* obj) {
    u32 v = obj->unk10C;
    if (obj->unkF0 != 0) {
        v = lbl_8027E794[v](obj);
        obj->unk10C = v;
    }
    lbl_8027E768[v](obj);
}
