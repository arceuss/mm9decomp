#include "types.h"

typedef struct Unk8038DD8C {
    /* 0x000 */ u8 pad0[0x154];
    /* 0x154 */ u8 player[0x18C - 0x154];
    /* 0x18C */ u32 count;
    /* 0x190 */ u8 pad190[0x23C - 0x190];
    /* 0x23C */ u8 unk23C[0x240 - 0x23C];
    /* 0x240 */ u8 mutex240[0x258 - 0x240];
    /* 0x258 */ u8 unk258[0x270 - 0x258];
    /* 0x270 */ u8 mutex[0x290 - 0x270];
    /* 0x290 */ u16 flags;
} Unk8038DD8C;

extern Unk8038DD8C lbl_8038DD8C;

void OSLockMutex(void* mutex);
void OSUnlockMutex(void* mutex);

extern u8 lbl_804EE928;

void fn_8019A3FC(void* handle, s32 arg1);
u32 fn_80199D50(void* player, u8 id);
u32 fn_8018D3E8(void* heap);
void fn_80199B08(void* player, u8 id, void* handle, s32 arg3);
void fn_8019A3A8(void* handle);

void fn_800D4230(void) {
    Unk8038DD8C* snd = &lbl_8038DD8C;
    u8* id;
    void* mutex;
    u32 need;
    u32 free;

    if (!(snd->flags & 2)) {
        fn_8019A3FC(snd->unk23C, 0);
        id = &lbl_804EE928;
        mutex = snd->mutex240;
        need = fn_80199D50(snd->player, *id);
        OSLockMutex(mutex);
        free = fn_8018D3E8(snd->unk258);
        OSUnlockMutex(mutex);
        if (free >= need) {
            fn_80199B08(snd->player, *id, snd->unk23C, 0);
        }
        fn_8019A3A8(lbl_8038DD8C.unk23C);
    }
    lbl_8038DD8C.flags &= 0xFFFE;
}
