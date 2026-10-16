#include "types.h"

typedef struct Unk80099F24Hit {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ u8 kind;
    /* 0x9 */ u8 flags;
} Unk80099F24Hit;

typedef struct Unk80099F24Target {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ Unk80099F24Hit* hit;
    /* 0x08 */ u8 pad8[0x3B - 0x8];
    /* 0x3B */ u8 flags;
} Unk80099F24Target;

typedef struct Unk80099F24Weapon {
    /* 0x0 */ u8 pad0[0x2];
    /* 0x2 */ u8 level;
    /* 0x3 */ u8 pad3;
    /* 0x4 */ u8 id;
} Unk80099F24Weapon;

typedef struct Unk80099F24Owner {
    /* 0x0 */ u8 pad0[0x4];
    /* 0x4 */ Unk80099F24Hit* hit;
} Unk80099F24Owner;

typedef struct Unk80099F24Attack {
    /* 0x00 */ Unk80099F24Weapon* base;
    /* 0x04 */ Unk80099F24Weapon* weapon;
    /* 0x08 */ u8 pad8[0xC - 0x8];
    /* 0x0C */ Unk80099F24Owner* owner;
    /* 0x10 */ u8 pad10[0x37 - 0x10];
    /* 0x37 */ u8 power;
    /* 0x38 */ u8 slot;
} Unk80099F24Attack;

typedef struct Unk80316398 {
    /* 0x000 */ u8 unk0;
    /* 0x001 */ u8 pad1[0x934 - 0x1];
    /* 0x934 */ u8 unk934;
    /* 0x935 */ u8 unk935;
} Unk80316398;

extern Unk80316398 lbl_80316398;
extern s32 lbl_80274540[][9];
extern s32 lbl_80274588[][13];

s32 fn_80099F24(Unk80099F24Attack* atk, Unk80099F24Target* t) {
    Unk80099F24Hit* h = t->hit;
    u8 flags = h->flags | t->flags;
    u8 kind;
    u8 w;
    s32 d;

    if (lbl_80316398.unk0 & 0x80) {
        return 0;
    }
    kind = h->kind;
    if (kind == 0xFF) {
        return 0;
    }
    if (flags & 2) {
        return 0;
    }
    if (kind == 1) {
        d = lbl_80274540[kind][atk->slot];
        if (d == 9) {
            return 0;
        }
        d = (atk->power * d) >> 2;
    } else {
        w = atk->weapon->id;
        if (w != 6) {
            d = lbl_80274588[kind - 2][atk->base->id];
        } else {
            d = lbl_80274588[atk->owner->hit->kind - 2][w];
        }
    }
    if (atk->weapon->level == 1) {
        d += lbl_80316398.unk934;
    }
    if (atk->weapon->level == 0) {
        d += lbl_80316398.unk935;
    }
    d <<= 8;
    if (flags & 0x40) {
        d /= 2;
    }
    if (flags & 0x80) {
        d <<= 1;
    }
    d >>= 8;
    if (d != 0) {
        return d;
    }
    return 1;
}
