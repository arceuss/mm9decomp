#include "types.h"

typedef struct Unk800B8C4C {
    /* 0x00 */ u8 pad0[0x4C];
    /* 0x4C */ u16 unk4C[4];
} Unk800B8C4C;

static inline u32 Edge(u32 a) {
    u32 m = 0;

    if ((a & 0x800) == 0x800) {
        m |= 0x800;
    } else {
        m |= 1;
    }
    return m;
}

u32 fn_800B8C4C(Unk800B8C4C* obj, u32 a, u32 b, u32 flags) {
    u32 dir = (flags >> 16) & 3;
    u32 r;
    u32 v;
    u32 e;
    u32 c;

    if (a != 0) {
        r = obj->unk4C[dir];
        if ((a & 0x80) == 0x80) {
            c = a;
            if (b == 0) {
                r = 0;
            }
        } else {
            c = b;
            if ((a & 0x40) == 0x40) {
                r |= 0x40;
            }
        }
        a = c;
        if (a == 0) {
            return r;
        }
        if (dir == 0) {
            e = Edge(a);
            v = a & 0x6000;
            flags = e;
            if ((v == 0x4000) ^ (v == 0x2000)) {
                flags = e | 0x2000;
                if (v == 0x4000) {
                    flags = e | 0x4000;
                }
            }
        } else if (dir == 1) {
            flags = Edge(a);
        } else {
            flags = Edge(a);
        }
        return r | flags;
    }
    return 0;
}
