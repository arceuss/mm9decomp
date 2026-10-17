#include "types.h"

typedef struct Unk800328ECEntry {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
} Unk800328ECEntry;

typedef struct Unk800328EC {
    /* 0x000 */ u8 pad0[0x26C];
    /* 0x26C */ u8 next;
    /* 0x26D */ u8 pad26D[0x274 - 0x26D];
    /* 0x274 */ u8 unk274;
    /* 0x275 */ u8 unk275;
    /* 0x276 */ u8 unk276;
    /* 0x277 */ u8 unk277;
    /* 0x278 */ u8 unk278;
    /* 0x279 */ u8 unk279;
    /* 0x27A */ u8 unk27A;
    /* 0x27B */ u8 unk27B;
    /* 0x27C */ u8 unk27C;
    /* 0x27D */ u8 unk27D;
    /* 0x27E */ u8 unk27E;
    /* 0x27F */ u8 unk27F;
    /* 0x280 */ u8 unk280;
    /* 0x281 */ u8 unk281;
    /* 0x282 */ u8 unk282;
    /* 0x283 */ u8 unk283;
    /* 0x284 */ u8 unk284;
    /* 0x285 */ u8 unk285;
    /* 0x286 */ u8 unk286;
    /* 0x287 */ u8 unk287;
    /* 0x288 */ u8 unk288;
    /* 0x289 */ u8 unk289;
    /* 0x28A */ u8 unk28A;
    /* 0x28B */ u8 unk28B;
    /* 0x28C */ u8 unk28C;
    /* 0x28D */ u8 unk28D;
    /* 0x28E */ u8 unk28E;
    /* 0x28F */ u8 unk28F;
} Unk800328EC;

typedef struct Unk80319DA0 {
    /* 0x000 */ u8 pad0[0x860];
    /* 0x860 */ u32 trig;
} Unk80319DA0;

typedef struct Unk80383E70 {
    /* 0x0000 */ u8 pad0[0x7480];
    /* 0x7480 */ u32 heard;
    /* 0x7484 */ u8 pad7484[0x7488 - 0x7484];
} Unk80383E70;

extern Unk800328ECEntry lbl_802643F8[];
extern Unk800328ECEntry lbl_8026441C[];
extern u8 lbl_80316D78[];
extern Unk80319DA0 lbl_80319DA0;
extern Unk80383E70 lbl_80383E70;

u32 fn_800BB6C8(u32 a);
void fn_800BB7B8(s32 a);
void fn_800BB4E8(s32 a, s32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void fn_800D5234(s32 se);
void fn_800352A8(Unk800328EC* obj, s32 arg1);
void fn_80033674(Unk800328EC* obj);

static inline void Leave(Unk800328EC* obj) {
    obj->unk276 = 0;
    fn_800BB7B8(1);
    obj->unk286 = 0;
    obj->next = obj->unk27B + 0x15;
}

void fn_800328EC(Unk800328EC* obj) {
    u32 R;
    u32 a;
    u32 b;

    if (obj->unk281 == 0) {
        obj->unk281 = 1;
        obj->unk274 = lbl_802643F8[obj->unk28A].unk4;
        obj->unk275 = lbl_8026441C[obj->unk28A].unk4;
        obj->unk283 = 4;
        R = *(u32*)(lbl_80316D78 + 0x3004) + 0xC29000;
        a = *(u32*)(R + 0x10) >> 1;
        b = (*(u32*)(R + 0x14) >> 1) + R;
        fn_800BB4E8(0, 0, a + R + *(u32*)(a + R), b + *(u32*)b, 0x20, 0, b, a + R);
        fn_800352A8(obj, 0);
        obj->unk28F = 1;
        obj->unk28E = 0;
    } else {
        obj->unk283 = 4;
        obj->unk284 = obj->unk27C;
        obj->unk28F = 1;
        obj->unk28E = 0;
    }
    fn_800BB6C8(0);
    if (obj->unk276 == 1) {
        if (obj->unk286 == 1) {
            if ((u8)fn_800BB6C8(1) == 3) {
                fn_800352A8(obj, 1);
                Leave(obj);
                return;
            }
        } else {
            Leave(obj);
            return;
        }
    } else if ((u8)fn_800BB6C8(0) == 3) {
        fn_80033674(obj);
    }
    if ((u8)fn_800BB6C8(0) == 3 && obj->unk276 != 1) {
        obj->unk285 = 1;
        if (!(lbl_80319DA0.trig & 0x50)) {
            if (lbl_80319DA0.trig & 0x20) {
                if (obj->unk27B != 3) {
                    fn_800D5234(0);
                }
                obj->unk27B = 3;
            } else {
                return;
            }
        } else {
            fn_800D5234(1);
            obj->unk285 = 0;
            fn_800BB7B8(0);
            if (obj->unk27B == 3) {
                R = *(u32*)(lbl_80316D78 + 0x3004) + 0xC29000;
                a = *(u32*)(R + 0x10) >> 1;
                b = (*(u32*)(R + 0x14) >> 1) + R;
                fn_800BB4E8(1, 1, a + R + *(u32*)(a + R), b + *(u32*)b, 0x20, 0, b, a + R);
                obj->unk286 = 1;
            }
            obj->unk276 = 1;
        }
    }
}
