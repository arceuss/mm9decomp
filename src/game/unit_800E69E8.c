#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk800E689CSrc {
    /* 0x0 */ Vec2i* a;
    /* 0x4 */ Vec2i* b;
    /* 0x8 */ u8 pad8[0xC - 0x8];
    /* 0xC */ u16 unkC;
} Unk800E689CSrc;

typedef struct Unk800E689C {
    /* 0x00 */ Vec2i a;
    /* 0x08 */ Vec2i center;
    /* 0x10 */ Vec2i b;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u16 unk1C;
} Unk800E689C;

typedef struct Unk800E69E8Node {
    /* 0x0 */ struct Unk800E69E8Node* next;
    /* 0x4 */ void (*func)(struct Unk800E69E8Node* node, Unk800E689C* ctx);
} Unk800E69E8Node;

typedef struct Unk800E69E8 {
    /* 0x000 */ u8 pad0[0x200];
    /* 0x200 */ Unk800E69E8Node** buckets;
    /* 0x204 */ Unk800E689CSrc* src;
    /* 0x208 */ s32 unk208;
} Unk800E69E8;

void fn_800E689C(Unk800E689C* out, Unk800E689CSrc* src, s32 arg2);

void fn_800E69E8(Unk800E69E8* mgr) {
    Unk800E689C ctx;
    Unk800E69E8Node** bucket;
    Unk800E69E8Node* node;
    s32 i;

    if (mgr->src != NULL) {
        fn_800E689C(&ctx, mgr->src, mgr->unk208);
        bucket = mgr->buckets;
        for (i = 0; i < 0x80; i++) {
            for (node = *bucket++; node != NULL; node = node->next) {
                node->func(node, &ctx);
            }
        }
    }
}
