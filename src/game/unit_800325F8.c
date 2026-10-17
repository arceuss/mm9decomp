#include "types.h"

typedef struct Unk800325F8Entry {
    /* 0x0 */ u8 pad0[0x3];
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 pad4[0x6 - 0x4];
} Unk800325F8Entry;

typedef struct Unk800325F8 {
    /* 0x000 */ u8 pad0[0x26C];
    /* 0x26C */ u8 next;
    /* 0x26D */ u8 pad26D[0x274 - 0x26D];
    /* 0x274 */ u8 unk274;
    /* 0x275 */ u8 unk275;
    /* 0x276 */ u8 leaving;
    /* 0x277 */ u8 pad277[0x27A - 0x277];
    /* 0x27A */ u8 choice;
    /* 0x27B */ u8 pad27B;
    /* 0x27C */ u8 unk27C;
    /* 0x27D */ u8 pad27D[0x280 - 0x27D];
    /* 0x280 */ u8 started;
    /* 0x281 */ u8 pad281[0x283 - 0x281];
    /* 0x283 */ u8 unk283;
    /* 0x284 */ u8 unk284;
    /* 0x285 */ u8 unk285;
    /* 0x286 */ u8 unk286;
    /* 0x287 */ u8 pad287[0x28A - 0x287];
    /* 0x28A */ u8 stage;
    /* 0x28B */ u8 pad28B[0x28E - 0x28B];
    /* 0x28E */ u8 unk28E;
    /* 0x28F */ u8 unk28F;
} Unk800325F8;

typedef struct Unk80319DA0 {
    /* 0x000 */ u8 pad0[0x860];
    /* 0x860 */ u32 trig;
} Unk80319DA0;

extern Unk800325F8Entry lbl_802643F8[];
extern Unk800325F8Entry lbl_8026441C[];
extern u8 lbl_80316D78[];
extern Unk80319DA0 lbl_80319DA0;

u32 fn_800BB6C8(u32 a);
void fn_800BB7B8(s32 a);
void fn_800BB4E8(s32 a, s32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void fn_80034D90(Unk800325F8* obj, s32 arg1);
void fn_800335C0(Unk800325F8* obj);
void fn_800D5234(s32 se);

static inline void SetFlag(Unk800325F8* obj) {
    if ((u8)(obj->stage + 0xFD) > 2 && obj->stage > 1) {
        if (obj->stage == 2) {
            obj->unk28F = 1;
        }
    } else {
        obj->unk28F = 0;
    }
    obj->unk28E = 0;
}

void fn_800325F8(Unk800325F8* obj) {
    u32 R;
    u32 a;
    u32 b;

    if (obj->started == 0) {
        obj->started = 1;
        obj->unk274 = lbl_802643F8[obj->stage].unk3;
        obj->unk275 = lbl_8026441C[obj->stage].unk3;
        obj->unk283 = 3;
        R = *(u32*)(lbl_80316D78 + 0x3004) + 0xC29000;
        a = *(u32*)(R + 0x10) >> 1;
        b = (*(u32*)(R + 0x14) >> 1) + R;
        fn_800BB4E8(0, 0, a + R + *(u32*)(a + R), b + *(u32*)b, 0x20, 0, b, a + R);
        fn_80034D90(obj, 0);
        SetFlag(obj);
    } else {
        obj->unk283 = 3;
        obj->unk284 = obj->unk27C;
        SetFlag(obj);
    }
    fn_800BB6C8(0);
    if (obj->leaving == 1) {
        if (obj->unk286 == 1) {
            if ((u8)fn_800BB6C8(1) == 3) {
                fn_80034D90(obj, 1);
                obj->leaving = 0;
                fn_800BB7B8(1);
                obj->unk286 = 0;
                obj->next = obj->choice + 0x11;
            }
        } else {
            obj->leaving = 0;
            fn_800BB7B8(1);
            obj->unk286 = 0;
            obj->next = obj->choice + 0x11;
        }
        return;
    }
    if ((u8)fn_800BB6C8(0) == 3) {
        fn_800335C0(obj);
    }
    if ((u8)fn_800BB6C8(0) == 3 && obj->leaving != 1) {
        obj->unk285 = 1;
        if (!(lbl_80319DA0.trig & 0x50)) {
            if (lbl_80319DA0.trig & 0x20) {
                if (obj->choice != 3) {
                    fn_800D5234(0);
                }
                obj->choice = 3;
            } else {
                return;
            }
        } else {
            fn_800D5234(1);
            obj->unk285 = 0;
            fn_800BB7B8(0);
            if (obj->choice == 3) {
                R = *(u32*)(lbl_80316D78 + 0x3004) + 0xC29000;
                a = *(u32*)(R + 0x10) >> 1;
                b = (*(u32*)(R + 0x14) >> 1) + R;
                fn_800BB4E8(1, 1, a + R + *(u32*)(a + R), b + *(u32*)b, 0x20, 0, b, a + R);
                obj->unk286 = 1;
            }
            obj->leaving = 1;
        }
    }
}
