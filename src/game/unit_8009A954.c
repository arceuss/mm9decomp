#include "types.h"
typedef struct Unk8009A954 {
    /* 0x00 */ struct Unk8009A954* unk00;
    /* 0x04 */ u8 pad04[0x4];
    /* 0x08 */ void* unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u16 unk14;
    /* 0x16 */ u16 unk16;
} Unk8009A954;
extern void fn_8009AAF4(Unk8009A954*, Unk8009A954*);
void fn_8009A954(Unk8009A954* p, Unk8009A954* other) {
    s32 x, y;
    u32 w, h, a, b;
    Unk8009A954* q;
    if (!p || !other) return;
    while (p) {
        x = p->unk0C; y = p->unk10; w = p->unk14; h = p->unk16;
        q = other;
        while (q) {
            if (p->unk08 != q->unk08) {
                a = w + q->unk14; b = h + q->unk16;
                if ((u32)(x - q->unk0C + (a >> 1)) < a && (u32)(y - q->unk10 + (b >> 1)) < b) fn_8009AAF4(p, q);
            }
            q = q->unk00;
        }
        p = p->unk00;
    }
}
