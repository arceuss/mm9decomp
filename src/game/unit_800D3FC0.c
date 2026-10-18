#include "types.h"

typedef struct Unk8038DD8C {
    /* 0x000 */ u8 pad0[0x150];
    /* 0x150 */ void* unk150;
    /* 0x154 */ u8 player[0x18C - 0x154];
    /* 0x18C */ u32 count;
    /* 0x190 */ u8 pad190[0x23C - 0x190];
    /* 0x23C */ u8 unk23C[0x240 - 0x23C];
    /* 0x240 */ u8 mutex240[0x258 - 0x240];
    /* 0x258 */ u8 unk258[0x270 - 0x258];
    /* 0x270 */ u8 mutex[0x288 - 0x270];
    /* 0x288 */ u32 base;
    /* 0x28C */ u32 cur;
    /* 0x290 */ u16 flags;
    /* 0x292 */ u8 pad292[0x294 - 0x292];
    /* 0x294 */ u32 size;
} Unk8038DD8C;

typedef struct Unk800D3FC0Cfg {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
} Unk800D3FC0Cfg;

extern Unk8038DD8C lbl_8038DD8C;
extern u8 lbl_804EE928;

s32 fn_80109968(void);
void fn_80109970(s32 a);
void fn_80109DC0(void);
u32 fn_8019B64C(Unk800D3FC0Cfg* cfg);
void fn_8019B71C(Unk800D3FC0Cfg* cfg, u32 buf, u32 size);
void OSInitMutex(void* mutex);
void fn_8018DA74(Unk8038DD8C* snd, void* arg);
u32 fn_80196FEC(void* player, void* heap);
u32 fn_80197148(void* player, void* heap);
void fn_80196DE8(void* player, void* heap, u32 a, u32 asize, u32 b, u32 bsize);
void OSLockMutex(void* mutex);
void OSUnlockMutex(void* mutex);
void fn_8019A3FC(void* handle, s32 arg1);
u32 fn_80199D50(void* player, u8 id);
u32 fn_8018D3E8(void* heap);
void fn_80199B08(void* player, u8 id, void* handle, s32 arg3);
void fn_8019A3A8(void* handle);
void fn_800D5088(void);

static inline u32 Alloc(u32 size) {
    u32 p = 0;

    if (size < lbl_8038DD8C.size - (lbl_8038DD8C.cur - lbl_8038DD8C.base)) {
        p = lbl_8038DD8C.cur;
        if (p & 0x1F) {
            p = (p + 0x20) & ~0x1F;
        }
        lbl_8038DD8C.cur = p + size;
    }
    return p;
}

static inline void Prepare(void) {
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

void fn_800D3FC0(u32 mem, u32 size, void* arg) {
    Unk800D3FC0Cfg cfg;
    u32 n;
    u32 p;
    u32 a;
    u32 m;

    lbl_8038DD8C.base = mem;
    lbl_8038DD8C.cur = mem;
    lbl_8038DD8C.size = size;
    cfg.unk0 = 4;
    cfg.unk4 = 0x4000;
    cfg.unk8 = 3;
    cfg.unkC = 0x4000;
    if (!fn_80109968()) {
        fn_80109970(0);
        fn_80109DC0();
    }
    cfg.unk0 = 4;
    cfg.unk4 = 0x4000;
    cfg.unk8 = 3;
    cfg.unkC = 0x4000;
    n = fn_8019B64C(&cfg);
    fn_8019B71C(&cfg, Alloc(n), n);
    OSInitMutex(lbl_8038DD8C.mutex);
    fn_8018DA74(&lbl_8038DD8C, arg);
    lbl_8038DD8C.unk150 = &lbl_8038DD8C;
    n = fn_80196FEC(lbl_8038DD8C.player, &lbl_8038DD8C);
    a = Alloc(n);
    m = fn_80197148(lbl_8038DD8C.player, lbl_8038DD8C.unk150);
    p = Alloc(n);
    fn_80196DE8(lbl_8038DD8C.player, lbl_8038DD8C.unk150, a, n, p, m);
    lbl_8038DD8C.flags |= 2;
    Prepare();
    fn_800D5088();
}
