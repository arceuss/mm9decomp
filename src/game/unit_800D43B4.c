#include "types.h"

typedef struct Unk8038DD8C {
    /* 0x000 */ u8 pad0[0x154];
    /* 0x154 */ u8 player[0x160 - 0x154];
    /* 0x160 */ u8 unk160[0x18C - 0x160];
    /* 0x18C */ u32 count;
    /* 0x190 */ u8 pad190[0x23C - 0x190];
    /* 0x23C */ u8 unk23C[0x240 - 0x23C];
    /* 0x240 */ u8 mutex240[0x258 - 0x240];
    /* 0x258 */ u8 unk258[0x26C - 0x258];
    /* 0x26C */ u8 unk26C[0x270 - 0x26C];
    /* 0x270 */ u8 mutex[0x290 - 0x270];
    /* 0x290 */ u16 flags;
} Unk8038DD8C;

extern Unk8038DD8C lbl_8038DD8C;

void fn_800F615C(void* mutex);
void fn_800F6238(void* mutex);

void fn_8019B5EC(void* starter, void* handle, u32 id, s32 arg3);

void fn_800D43B4(u32 id) {
    fn_800F615C(lbl_8038DD8C.mutex);
    if (!(lbl_8038DD8C.flags & 1) && id != 0xFFFF) {
        fn_800F615C(lbl_8038DD8C.mutex);
        fn_8019B5EC(lbl_8038DD8C.unk160, lbl_8038DD8C.unk26C, id, 0);
        fn_800F6238(lbl_8038DD8C.mutex);
    }
    fn_800F6238(lbl_8038DD8C.mutex);
}
