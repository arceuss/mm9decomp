#include "types.h"

typedef struct Unk8001DFD4 {
    /* 0x00 */ u8 pad00[0x11];
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0x60 - 0x13];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ u8 pad64[0xD8 - 0x64];
    /* 0xD8 */ u8 unkD8;
    /* 0xD9 */ u8 unkD9;
    /* 0xDA */ u8 padDA[0xE0 - 0xDA];
    /* 0xE0 */ u8 unkE0;
} Unk8001DFD4;

extern u32 lbl_804EE988;
extern Unk8001DFD4* lbl_804EE984;
extern u8* lbl_80263020[4];

void fn_8001DFD4(Unk8001DFD4* obj) {
    u32 rnd = lbl_804EE988 * 0x343FD + 0x269EC3;
    s32 dist;
    s32 range;
    u8 v;
    u8* tbl;

    lbl_804EE988 = rnd & 0x7FFFFFFF;
    v = (rnd >> 16) & 0xF;
    dist = (obj->unk60 - lbl_804EE984->unk60) < 0 ? -(obj->unk60 - lbl_804EE984->unk60) : (obj->unk60 - lbl_804EE984->unk60);
    if (dist <= 0x1F00) {
        range = 0;
    } else if (dist <= 0x4F00) {
        range = 1;
    } else {
        range = dist <= 0xAF00 ? 2 : 3;
    }
    tbl = lbl_80263020[(u8)range];
    v = tbl[v];
    if (v == obj->unkD8) {
        if (++obj->unkD9 == 2) {
            while (v == obj->unkD8) {
                rnd = lbl_804EE988 * 0x343FD + 0x269EC3;
                lbl_804EE988 = rnd & 0x7FFFFFFF;
                v = tbl[(rnd >> 16) & 0xF];
            }
            obj->unkD9 = 0;
        }
    } else {
        obj->unkD9 = 0;
    }
    if (obj->unkD8 == 1 && v == 1) {
        while (v == 1) {
            rnd = lbl_804EE988 * 0x343FD + 0x269EC3;
            lbl_804EE988 = rnd & 0x7FFFFFFF;
            v = lbl_80263020[(u8)range][(rnd >> 16) & 0xF];
        }
        obj->unkD9 = 0;
    }
    if (v != 1) {
        if (++obj->unkE0 == 4) {
            obj->unkE0 = 0;
            v = 1;
        }
    } else {
        obj->unkE0 = 0;
    }
    obj->unk11 = v;
    obj->unk12 = 0;
    obj->unkD8 = v;
}
