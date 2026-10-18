#include "types.h"

typedef struct Unk8038DD8C {
    /* 0x000 */ u8 pad0[0x154];
    /* 0x154 */ u8 player[0x160 - 0x154];
    /* 0x160 */ u8 unk160[0x18C - 0x160];
    /* 0x18C */ u32 count;
    /* 0x190 */ u8 pad190[0x23C - 0x190];
    /* 0x23C */ u8 unk23C[0x240 - 0x23C];
    /* 0x240 */ u8 mutex240[0x258 - 0x240];
    /* 0x258 */ u8 unk258[0x268 - 0x258];
    /* 0x268 */ u8 unk268[0x26C - 0x268];
    /* 0x26C */ u8 unk26C[0x270 - 0x26C];
    /* 0x270 */ u8 mutex[0x290 - 0x270];
    /* 0x290 */ u16 flags;
} Unk8038DD8C;

extern Unk8038DD8C lbl_8038DD8C;

void OSLockMutex(void* mutex);
void OSUnlockMutex(void* mutex);

void fn_801820DC(void* array, void* dtor, u32 size, u32 count);
void fn_80196D14(void* player, s32 flags);
void fn_8018DA1C(void* self, s32 flags);
void dtor_8018223C(void* p);
void* fn_800D4568(void* self, s32 flags);
void* fn_8019A2C8(void* self, s32 flags);

// deleting destructor of the sound manager at lbl_8038DD8C: member arrays,
// then the player and the base, newest first
Unk8038DD8C* fn_800D4FB8(Unk8038DD8C* self, s32 flags) {
    if (self != NULL) {
        fn_801820DC(self->unk268, fn_800D4568, 4, 2);
        fn_801820DC(self->unk23C, fn_8019A2C8, 0x2C, 1);
        fn_80196D14(self->player, -1);
        fn_8018DA1C(self, -1);
        if (flags > 0) {
            dtor_8018223C(self);
        }
    }
    return self;
}
