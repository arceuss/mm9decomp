#include "types.h"

typedef struct Unk80086E98 {
    /* 0x0000 */ u8 pad0[0x2];
    /* 0x0002 */ u8 mode;
    /* 0x0003 */ u8 step;
    /* 0x0004 */ s16 timer;
    /* 0x0006 */ u8 pad6[0xFF4 - 0x6];
    /* 0x0FF4 */ u8 unkFF4;
    /* 0x0FF5 */ u8 unkFF5;
    /* 0x0FF6 */ u8 unkFF6;
    /* 0x0FF7 */ u8 padFF7;
    /* 0x0FF8 */ u8* unkFF8;
    /* 0x0FFC */ u8 padFFC[0x1001 - 0xFFC];
    /* 0x1001 */ u8 unk1001;
    /* 0x1002 */ u8 pad1002;
    /* 0x1003 */ u8 unk1003;
    /* 0x1004 */ u8 pad1004[0x2255 - 0x1004];
    /* 0x2255 */ u8 unk2255;
} Unk80086E98;

typedef struct Unk8038E738 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u16 unkA;
} Unk8038E738;

extern Unk8038E738 lbl_8038E738;

void fn_800DBCE0(Unk80086E98* obj, s32 a, s32 b);
u32 fn_800BB6C8(u32 id);
void fn_800E5910(s32 id);

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

extern Unk80316D78 lbl_80316D78;
extern u8 lbl_804ECD10[8];

void fn_800BB7B8(u32 id);
void fn_800BB4E8(s32 a, s32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
u32 fn_8000EF20(s32 a);
void fn_800E83A4(void* a, u32 b);
void fn_800BAF48(void* a, s32 b);
void fn_8000ECB8(s32 a, void* font, s32 tile, s32 x, s32 y);

#define ARC (lbl_80316D78.unk3004 + 0xCD5000)

static inline void Play(u32 id, s32 x, s32 idx, s32 size) {
    u32 R;
    u32 a;
    u32 b;

    R = (u32)ARC;
    a = *(u32*)(R + 0x14) >> 1;
    b = (*(u32*)(R + 0x18) >> 1) + R;
    fn_800BB4E8(id, x, a + R + ((u32*)(a + R))[idx], b + ((u32*)b)[idx], size, 0, b, a + R);
}

void fn_80086E98(Unk80086E98* obj) {
    u8* p;
    u32 ok;
    u8* q;

    switch (obj->step) {
    case 0:
        fn_800DBCE0(obj, 3, 0);
        fn_800DBCE0(obj, 3, 1);
        fn_800DBCE0(obj, 3, 2);
        fn_800DBCE0(obj, 3, 8);
        obj->unk1001 = 2;
        obj->unk1003 = 1;
        Play(0, 0, 0, 0x40);
        obj->timer = 0;
        obj->unkFF4++;
        obj->step++;
    case 1:
        if (obj->unk1001 == 0 && ++obj->timer == 0x78) {
            obj->step++;
        }
        fn_800BB6C8(0);
        break;
    case 2:
        fn_800E5910(0xC09);
        obj->unkFF4++;
        obj->step++;
    case 3:
        if (lbl_8038E738.unkA == 0) {
            obj->step++;
        }
        fn_800BB6C8(0);
        break;
    case 4:
        fn_800E5910(0xC0A);
        obj->unkFF4++;
        obj->step++;
    case 5:
        if (lbl_8038E738.unkA == 0) {
            obj->step++;
        }
        fn_800BB6C8(0);
        break;
    case 6:
        fn_800E5910(0xC0B);
        obj->unkFF4++;
        obj->step++;
    case 7:
        if (lbl_8038E738.unkA == 0) {
            obj->timer = 0;
            obj->step++;
        }
        fn_800BB6C8(0);
        break;
    case 8:
        if (++obj->timer != 0x3C) {
            fn_800BB6C8(0);
            break;
        }
        obj->unk1001 = 4;
        obj->unk1003 = 1;
        obj->unkFF4++;
        obj->step++;
    case 9:
        if (obj->unk1001 == 0) {
            obj->step++;
        }
        fn_800BB6C8(0);
        break;
    case 10:
        fn_800BB7B8(0);
        p = obj->unkFF8;
        fn_800E83A4((void*)((*(u32*)(p + 8) >> 1) + (u32)p), fn_8000EF20(0x38));
        p = obj->unkFF8;
        fn_800BAF48((u8*)((*(u32*)(p + 8) >> 1) + (u32)p) + 0xC, 0);
        p = obj->unkFF8;
        fn_8000ECB8(0x38, (void*)((*(u32*)(p + 4) >> 1) + (u32)p), lbl_804ECD10[obj->unk2255 - 1], 0, 0);
        obj->unk1001 = 2;
        obj->unk1003 = 1;
        obj->unkFF4++;
        obj->step++;
    case 11:
        if (obj->unk1001 == 0) {
            obj->step++;
        }
        break;
    case 12:
        fn_800E5910(0xC0C);
        obj->unkFF4++;
        obj->step++;
    case 13:
        if (lbl_8038E738.unkA == 0) {
            obj->step++;
        }
        break;
    case 14:
        fn_800E5910(0xC0D);
        obj->unkFF4++;
        obj->step++;
    case 15:
        if (lbl_8038E738.unkA == 0) {
            obj->step++;
        }
        break;
    case 16:
        fn_800E5910(0xC0E);
        obj->unkFF4++;
        obj->step++;
    case 17:
        if (lbl_8038E738.unkA == 0) {
            obj->step++;
        }
        break;
    case 18:
        fn_800E5910(0xC0F);
        obj->unkFF4++;
        obj->step++;
    case 19:
        if (lbl_8038E738.unkA == 0) {
            obj->step++;
        }
        break;
    case 20:
        fn_800E5910(0xC10);
        obj->unkFF4++;
        obj->step++;
    case 21:
        if (lbl_8038E738.unkA == 0) {
            obj->step++;
        }
        break;
    case 22:
        fn_800E5910(0xC11);
        obj->timer = 0;
        obj->unkFF4++;
        obj->step++;
    case 23:
        if (lbl_8038E738.unkA == 0 && ++obj->timer == 0x5A) {
            obj->step++;
        }
        break;
    case 24:
        fn_800E5910(0xC12);
        obj->timer = 0;
        obj->unkFF4++;
        obj->step++;
    case 25:
        if (lbl_8038E738.unkA == 0 && ++obj->timer == 0x3C) {
            obj->unk1001 = 4;
            obj->unk1003 = 1;
            obj->step++;
        }
        break;
    case 26:
        if (obj->unk1001 == 0) {
            p = obj->unkFF8;
            fn_8000ECB8(0x38, (void*)((*(u32*)(p + 4) >> 1) + (u32)p), 8, 0, 0);
            obj->unk1001 = 2;
            obj->unk1003 = 1;
            obj->unkFF4++;
            obj->step++;
    case 27:
            if (obj->unk1001 == 0) {
                obj->step++;
            }
        }
        break;
    case 28:
        fn_800E5910(0xC13);
        obj->timer = 0;
        obj->unkFF4++;
        obj->step++;
    case 29:
        if (lbl_8038E738.unkA == 0 && ++obj->timer == 0x3C) {
            obj->unk1001 = 4;
            obj->unk1003 = 1;
            obj->step++;
        }
        break;
    case 30:
        if (obj->unk1001 == 0) {
            q = ARC;
            fn_800E83A4((void*)((*(u32*)(q + 8) >> 1) + (u32)q), fn_8000EF20(0x38));
            q = ARC;
            fn_800BAF48((u8*)((*(u32*)(q + 8) >> 1) + (u32)q) + 0xC, 0);
            q = ARC;
            fn_8000ECB8(0x38, (void*)((*(u32*)(q + 4) >> 1) + (u32)q), 0, 0, 0);
            obj->unk1001 = 2;
            obj->unk1003 = 1;
            Play(0, 0, 0, 0x40);
            obj->timer = 0;
            obj->unkFF4++;
            obj->step++;
    case 31:
            if (obj->unk1001 == 0 && ++obj->timer == 0x5A) {
                obj->step++;
            }
            fn_800BB6C8(0);
        }
        break;
    case 32:
        fn_800E5910(0xC14);
        obj->timer = 0;
        obj->unkFF4++;
        obj->step++;
    case 33:
        if (lbl_8038E738.unkA == 0 && ++obj->timer == 0x78) {
            obj->step++;
        }
        fn_800BB6C8(0);
        break;
    case 34:
        Play(1, 1, 0, 0x40);
        Play(2, 0, 1, 0);
        Play(3, 0, 2, 0x20);
        Play(4, 0, 3, 0x60);
        obj->unkFF4++;
        obj->step++;
    case 35:
        ok = ((u8)fn_800BB6C8(1) == 3) & 1;
        ok &= (u8)fn_800BB6C8(2) == 3;
        ok &= (u8)fn_800BB6C8(3) == 3;
        if (ok & ((u8)fn_800BB6C8(4) == 3)) {
            obj->timer = 0;
            obj->step++;
        }
        break;
    case 36:
        if (++obj->timer != 0x3C) {
            break;
        }
        fn_800DBCE0(obj, 3, 5);
        obj->unkFF5 = 0;
        obj->timer = 0;
        obj->unkFF4++;
        obj->step++;
    case 37:
        if (obj->unkFF5 == 1 && ++obj->timer == 0x3C) {
            obj->step++;
        }
        break;
    case 38:
        obj->unk1001 = 4;
        obj->unk1003 = 1;
        obj->unkFF4++;
        obj->step++;
    case 39:
        if (obj->unk1001 == 0) {
            fn_800BB7B8(1);
            fn_800BB7B8(2);
            fn_800BB7B8(3);
            fn_800BB7B8(4);
            obj->unkFF4 = 0xFF;
            obj->unkFF6 = 0;
            obj->mode = 2;
            obj->step = 0;
        }
        break;
    }
}
