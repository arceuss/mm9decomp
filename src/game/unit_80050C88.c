#include "types.h"

typedef struct Unk80050C88 {
    u8 pad0[0xA];
    u8 unkA;
    u8 padB[0x12-0xB];
    u8 step;
    u8 pad13[3];
    u8 unk16;
    u8 pad17[0x54-0x17];
    u32 hi54:21;
    u32 face:1;
    u32 lo54:10;
    u8 pad58[8];
    s32 x;
    s32 y;
    s32 vx;
    s32 vy;
    u8 pad70[4];
    s32 ay;
    u8 pad78[0x88-0x78];
    u8 unk88[0xCC-0x88];
    u8 unkCC;
    u8 unkCD;
    u8 unkCE;
} Unk80050C88;

typedef struct Unk80304B90 {
    u8 pad0[0x21C];
    u8 cam[4];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern Unk80050C88* lbl_804EE984;
extern u32 lbl_804EE988;
extern u8 lbl_802661D8[];
extern u8 lbl_802661A8[];
u32 fn_80080484(void*, s32*, s32);
void fn_80042D30(Unk80050C88*);
void fn_800E946C(Unk80050C88*, u8);
void fn_800E9750(Unk80050C88*, u16);
void fn_8009996C(void*, void*);
void fn_800D5234(s32);
s32 fn_800A3FAC(s32, s32);
s32 fn_800A3CD4(s32, s32);
s32 fn_800A39F0(s32, s32);
s32 fn_800A36F8(s32, s32);

static inline void Face(Unk80050C88* obj) {
    u32 bit = lbl_804EE984->x - obj->x > 0;
    if (bit) obj->unkA |= 0x10;
    else obj->unkA &= 0xEF;
    obj->face = bit;
}

void fn_80050C88(Unk80050C88* obj) {
    s32 d;
    u8 hits;
    u32 rnd;
    if (fn_80080484(lbl_80304B90.cam, &obj->x, 1) > 0x2000) {
        fn_80042D30(obj);
        return;
    }
    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 4);
        Face(obj);
        fn_8009996C(obj->unk88, lbl_802661D8);
        obj->vy = -0x500;
        obj->ay = 0x40;
        obj->vx = -((lbl_804EE984->x - obj->x) * 256 / ((obj->vy * 256 / obj->ay) * 2));
        if (__abs(obj->vx) > 0x200) {
            obj->vx = (((obj->unkA >> 3) & 2) - 1) * 0x200;
        }
        obj->step++;
    case 1:
        hits = 0;
        fn_800E9750(obj, 0xFFFF);
        obj->x += obj->vx;
        d = fn_800A3FAC(obj->x - 0xF00, obj->y - 0xE00);
        if (d > 0) obj->x += d;
        d = fn_800A3FAC(obj->x - 0xF00, obj->y);
        if (d > 0) obj->x += d;
        d = fn_800A3CD4(obj->x + 0xF00, obj->y - 0xE00);
        if (d < 0) obj->x += d;
        d = fn_800A3CD4(obj->x + 0xF00, obj->y);
        if (d < 0) obj->x += d;
        obj->y += obj->vy;
        obj->vy += obj->ay;
        d = fn_800A39F0(obj->x, obj->y - 0xE00);
        if (d > 0) { obj->y += d; obj->vy = 0; }
        d = fn_800A39F0(obj->x - 0xF00, obj->y - 0xE00);
        if (d > 0) { obj->y += d; obj->vy = 0; }
        d = fn_800A39F0(obj->x + 0xF00, obj->y - 0xE00);
        if (d > 0) { obj->y += d; obj->vy = 0; }
        d = fn_800A36F8(obj->x, obj->y);
        if (d < 0) { hits = 1; obj->y += d; }
        d = fn_800A36F8(obj->x - 0xF00, obj->y);
        if (d < 0) { hits++; obj->y += d; }
        d = fn_800A36F8(obj->x + 0xF00, obj->y);
        if (d < 0) { hits++; obj->y += d; }
        if (hits) {
            if (obj->unkCC == 0) obj->step++;
            else { obj->unkCC--; obj->step = 0; }
        }
        break;
    case 2:
        fn_800E946C(obj, 3);
        fn_800D5234(0x41);
        fn_8009996C(obj->unk88, lbl_802661A8);
        obj->unk16 = 0x14;
        obj->step++;
    case 3:
        Face(obj);
        fn_800E9750(obj, 0xFFFF);
        if (--obj->unk16 == 0) {
            obj->step = 0;
            rnd = lbl_804EE988 * 0x343FD;
            rnd += 0x269EC3;
            lbl_804EE988 = rnd & 0x7FFFFFFF;
            obj->unkCC = (rnd >> 16) & 1;
            if (obj->unkCD == obj->unkCC) {
                if (++obj->unkCE == 3) obj->unkCC = !obj->unkCC;
            } else obj->unkCE = 0;
            obj->unkCD = obj->unkCC;
        }
        break;
    }
}
