#include "types.h"

typedef struct Unk8009F428Rec {
    /* 0x0 */ u32 tile;
    /* 0x4 */ u32 off;
} Unk8009F428Rec;

typedef struct Unk8009F428Ent {
    /* 0x0 */ u32 count;
    /* 0x4 */ Unk8009F428Rec recs[1];
} Unk8009F428Ent;

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

extern Unk80316D78 lbl_80316D78;
extern u8 lbl_80368F50[];

void fn_800BAEE0(u32 dst);
void fn_800BAE68(u32 dst, void* src, u32 size);

static inline Unk8009F428Ent* Ent(u32 idx) {
    u32 R = (u32)lbl_80316D78.unk3004 + 0xCD5000;
    u32 a = *(u32*)(R + 0xC) >> 1;

    return (Unk8009F428Ent*)(a + R + ((u32*)(a + R))[idx + 1]);
}

void fn_8009F428(u32 a, u32 b, u32 dst) {
    u32 n;
    u32 i;
    u32 size;
    u32 n1;
    u32 i1;
    u8* src;

    if (dst < 0x10004000) {
        return;
    }
    if (b < 0xF) {
        n1 = Ent(b)->count;
        for (i1 = 0; i1 < n1; i1++) {
            fn_800BAEE0(dst + (Ent(b)->recs[i1].tile << 9));
        }
    }
    if (a < 0xF) {
        src = lbl_80368F50 + ((((dst >> 13) & 3) - 2) << 13);
        n = Ent(a)->count;
        for (i = 0; i < n; i++) {
            Unk8009F428Rec* r = &Ent(a)->recs[i];

            size = (r[1].off - r->off + 3) & 0xFFFC;
            if (size > 0x200) {
                size = 0x200;
            }
            fn_800BAE68(dst + (r->tile << 9), src + (r->tile << 9), size);
        }
    }
}
