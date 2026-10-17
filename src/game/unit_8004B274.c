#include "types.h"
#include "game/sound.h"

typedef struct Unk804EE984 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x60 - 0xB];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0xB6 - 0x68];
    /* 0xB6 */ s16 unkB6;
} Unk804EE984;

extern Unk804EE984* lbl_804EE984;
extern void* lbl_804EE77C;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x21C];
    /* 0x21C */ u8 unk21C[0xBC];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;
extern u8 lbl_80265D98[];

typedef struct Unk8004B274 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 padB[0x12 - 0xB];
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x40 - 0x17];
    /* 0x40 */ u8 unk40[8];
    /* 0x48 */ void* unk48;
    /* 0x4C */ u8 pad4C[0x54 - 0x4C];
    /* 0x54 */ u32 unk54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0x88 - 0x78];
    /* 0x88 */ u8 unk88[0x18];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u8 padA4[0xD0 - 0xA4];
    /* 0xD0 */ u8 unkD0;
    /* 0xD1 */ u8 unkD1;
    /* 0xD2 */ u8 unkD2;
    /* 0xD3 */ u8 unkD3;
} Unk8004B274;

void fn_8004AE04(void);
void fn_800D5234(s32 id);
void fn_800E7960(void* node, void* func);
void fn_800E9244(Unk8004B274* obj);
void fn_800E9424(Unk8004B274* obj, s32 arg);
void fn_800E946C(Unk8004B274* obj, u8 arg);
void fn_800E9750(Unk8004B274* obj, u16 arg);
void fn_800E9758(Unk8004B274* obj);
void fn_8009996C(void* arg0, void* arg1);
u32 fn_80080484(void* cam, s32* pos, s32 arg);
void fn_800B63C4(Unk804EE984* p, s32 arg);
void fn_800B6430(Unk804EE984* p);
void fn_800B60CC(Unk804EE984* p, s32 arg);

void fn_8004B274(Unk8004B274* obj) {
    Unk804EE984* p;

    switch (obj->unk12) {
    case 0:
        fn_800E946C(obj, 0);
        if (obj->unk14 == 0) {
            obj->unk0A |= 0x10;
            obj->unk54 |= 0x400;
        } else {
            obj->unk0A &= 0xEF;
            obj->unk54 &= ~0x400;
        }
        fn_8009996C(obj->unk88, 0);
        obj->unk12++;
    case 1:
        fn_800E9758(obj);
        if (__abs(obj->unk60 - lbl_804EE984->x) < 0x2000) {
            obj->unk12++;
        }
        break;
    case 2:
        obj->unk6C = 0x580;
        obj->unk16 = 0;
        obj->unk12++;
    case 3:
        obj->unk64 += obj->unk6C;
        fn_800E9758(obj);
        if (obj->unk16 == 0) {
            if (fn_80080484(lbl_80304B90.unk21C, &obj->unk60, 1) == 0) {
                fn_8009996C(obj->unk88, lbl_80265D98);
                obj->unk16++;
            }
        }
        if (obj->unkA0 & 4) {
            lbl_804EE77C = obj;
            p = lbl_804EE984;
            fn_800B63C4(p, 1);
            fn_800B63C4(p, 2);
            fn_800B63C4(p, 4);
            fn_800B63C4(p, 8);
            fn_800B6430(p);
            obj->unk64 = lbl_804EE984->y - 0x1800;
            obj->unk12++;
        }
        break;
    case 4:
        fn_800E7960(obj->unk40, fn_8004AE04);
        obj->unk48 = obj;
        obj->unk0A &= 0xF7;
        fn_800D5234(SE_EM_JET);
        obj->unkD3 = 1;
        obj->unk0A |= 8;
        fn_800E946C(obj, 1);
        obj->unk68 = 0;
        obj->unk70 = (((obj->unk0A >> 4) & 1) * 2 - 1) * 32;
        obj->unk16 = 0xB4;
        obj->unk12++;
    case 5:
        fn_800E9750(obj, 0xFFFF);
        obj->unk68 += obj->unk70;
        obj->unkD0++;
        if (obj->unkD0 > 3) {
            if (obj->unkD1 == 0) {
                obj->unkD1++;
            } else {
                obj->unkD1--;
            }
            obj->unkD0 = 0;
        }
        if (__abs(obj->unk68) > 0x300) {
            obj->unk68 = (((obj->unk0A >> 4) & 1) * 2 - 1) * 0x300;
        }
        p = lbl_804EE984;
        fn_800B63C4(p, 1);
        fn_800B63C4(p, 2);
        fn_800B63C4(p, 4);
        fn_800B63C4(p, 8);
        fn_800B6430(p);
        fn_800B60CC(lbl_804EE984, obj->unk68);
        obj->unk16--;
        if (!((p->flagsA & 1) && lbl_804EE77C == obj && p->unkB6 != 0 &&
              obj->unk16 != 0)) {
            obj->unk12++;
        }
        break;
    case 6:
        fn_800E9424(obj, 0xE);
        fn_800E946C(obj, 0);
        obj->unk6C = 0;
        obj->unk74 = -0x20;
        obj->unk12++;
    case 7:
        fn_800E9750(obj, 0xFFFF);
        obj->unk64 += obj->unk6C;
        obj->unk6C += obj->unk74;
        break;
    }
    obj->unkD2 = 0;
}
