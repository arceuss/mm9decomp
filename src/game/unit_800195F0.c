#include "types.h"

typedef struct Unk800195F0 {
    /* 0x00 */ u8 pad00[0x11];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0x60 - 0x13];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ u8 pad64[0xD8 - 0x64];
    /* 0xD8 */ u8 unkD8;
    /* 0xD9 */ u8 unkD9;
} Unk800195F0;

typedef struct Unk800195F0Data {
    /* 0x000 */ u8 pad0[0x1D8];
    /* 0x1D8 */ u8 near[16];
    /* 0x1E8 */ u8 mid[16];
    /* 0x1F8 */ u8 far[16];
    /* 0x208 */ u8 farthest[16];
} Unk800195F0Data;

extern u32 lbl_804EE988;
extern Unk800195F0* lbl_804EE984;
extern Unk800195F0Data lbl_802627E0;

static inline u8 Pick(Unk800195F0Data* d, s32 dist, u32 idx) {
    u8* tbl;

    if (dist < 0x4800) {
        tbl = d->near;
    } else if (dist < 0x7000) {
        tbl = d->mid;
    } else if (dist < 0xAF00) {
        tbl = d->far;
    } else {
        tbl = d->farthest;
    }
    return tbl[idx];
}

void fn_800195F0(Unk800195F0* obj) {
    Unk800195F0Data* d = &lbl_802627E0;
    u32 rnd = lbl_804EE988 * 0x343FD + 0x269EC3;
    s32 dist;
    u32 idx;
    u8 v;

    lbl_804EE988 = rnd & 0x7FFFFFFF;
    idx = (rnd >> 16) & 0xF;
    dist = __abs(obj->unk60 - lbl_804EE984->unk60);
    v = Pick(d, dist, idx);

    if (v == obj->unkD8) {
        if (++obj->unkD9 == 2) {
            while (v == obj->unkD8) {
                rnd = lbl_804EE988 * 0x343FD + 0x269EC3;
                lbl_804EE988 = rnd & 0x7FFFFFFF;
                v = Pick(d, dist, (rnd >> 16) & 0xF);
            }
            obj->unkD9 = 0;
        }
    } else {
        obj->unkD9 = 0;
    }
    obj->unk11 = v;
    obj->unk12 = 0;
    obj->unkD8 = v;
}
