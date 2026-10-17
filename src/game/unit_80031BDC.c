#include "types.h"

typedef struct Unk80031BDCEntry {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 pad1;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 pad4[0x6 - 0x4];
} Unk80031BDCEntry;

typedef struct Unk80031BDC {
    /* 0x000 */ u8 pad0[0x26C];
    /* 0x26C */ u8 next;
    /* 0x26D */ u8 pad26D[0x274 - 0x26D];
    /* 0x274 */ u8 unk274;
    /* 0x275 */ u8 unk275;
    /* 0x276 */ u8 leaving;
    /* 0x277 */ u8 choice;
    /* 0x278 */ u8 unk278;
    /* 0x279 */ u8 unk279;
    /* 0x27A */ u8 pad27A[0x27C - 0x27A];
    /* 0x27C */ u8 unk27C;
    /* 0x27D */ u8 started;
    /* 0x27E */ u8 unk27E;
    /* 0x27F */ u8 unk27F;
    /* 0x280 */ u8 pad280[0x283 - 0x280];
    /* 0x283 */ u8 unk283;
    /* 0x284 */ u8 unk284;
    /* 0x285 */ u8 unk285;
    /* 0x286 */ u8 unk286;
    /* 0x287 */ u8 pad287[0x28A - 0x287];
    /* 0x28A */ u8 stage;
    /* 0x28B */ u8 pad28B[0x28E - 0x28B];
    /* 0x28E */ u8 unk28E;
    /* 0x28F */ u8 unk28F;
} Unk80031BDC;

typedef struct Unk80319DA0 {
    /* 0x000 */ u8 pad0[0x860];
    /* 0x860 */ u32 trig;
} Unk80319DA0;

extern Unk80031BDCEntry lbl_802643F8[];
extern Unk80031BDCEntry lbl_8026441C[];
extern u8 lbl_80316D78[];
extern Unk80319DA0 lbl_80319DA0;

typedef struct Unk80383E70 {
    /* 0x0000 */ u8 pad0[0x7480];
    /* 0x7480 */ u32 heard;
    /* 0x7484 */ u8 pad7484[0x7488 - 0x7484];
} Unk80383E70;

extern Unk80383E70 lbl_80383E70;

u32 fn_800BB6C8(u32 a);
void fn_800BB7B8(s32 a);
void fn_800BB4E8(s32 a, s32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void fn_800D9228(Unk80031BDC* obj, s32* size, s32 arg2, s32 arg3);
void fn_80033890(Unk80031BDC* obj, s32 arg1);
void fn_8003345C(Unk80031BDC* obj);
void fn_800D5234(s32 se);

static inline void Leave(Unk80031BDC* obj) {
    obj->leaving = 0;
    obj->started = 0;
    fn_800BB7B8(1);
    obj->unk286 = 0;
    obj->next = obj->choice + 1;
}

void fn_80031BDC(Unk80031BDC* obj) {
    s32 size[2];
    u32 R;
    u32 a;
    u32 b;

    size[0] = 0x10;
    size[1] = 0x10;
    if (obj->started == 0) {
        obj->started = 1;
        obj->unk274 = lbl_802643F8[obj->stage].unk0;
        obj->unk275 = lbl_8026441C[obj->stage].unk0;
        obj->unk283 = 0;
        fn_800D9228(obj, size, 0, 0);
        R = *(u32*)(lbl_80316D78 + 0x3004) + 0xC29000;
        a = *(u32*)(R + 0x10) >> 1;
        b = (*(u32*)(R + 0x14) >> 1) + R;
        fn_800BB4E8(0, 0, a + R + *(u32*)(a + R), b + *(u32*)b, 0x20, 0, b, a + R);
        fn_80033890(obj, 0);
    } else {
        obj->unk283 = 0;
        obj->unk27E = 0;
        obj->unk27F = 0;
        obj->unk284 = obj->unk27C;
        obj->unk278 = 0;
        obj->unk279 = 0;
    }
    fn_800BB6C8(0);
    if (obj->leaving == 1) {
        if (obj->unk286 == 1) {
            if ((u8)fn_800BB6C8(1) == 3) {
                fn_80033890(obj, 1);
                Leave(obj);
                return;
            }
        } else {
            Leave(obj);
            return;
        }
    } else if ((u8)fn_800BB6C8(0) == 3) {
        fn_8003345C(obj);
    }
    if ((u8)fn_800BB6C8(0) == 3 && obj->leaving != 1) {
        obj->unk285 = 1;
        if (!(lbl_80319DA0.trig & 0x50)) {
            if (lbl_80319DA0.trig & 0x20) {
                if (obj->choice != 5) {
                    fn_800D5234(0);
                }
                obj->choice = 5;
            } else {
                return;
            }
        } else {
            fn_800D5234(1);
            obj->unk285 = 0;
            fn_800BB7B8(0);
            if ((u8)(obj->choice + 0xFD) > 2 && obj->choice != 1) {
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
