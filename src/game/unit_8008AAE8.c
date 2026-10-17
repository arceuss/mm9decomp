#include "types.h"

typedef struct Unk8008AAE8 {
    /* 0x0000 */ u8 pad0[0x2];
    /* 0x0002 */ u8 unk2;
    /* 0x0003 */ u8 pad3[0x2154 - 0x3];
    /* 0x2154 */ u32 unk2154;
    /* 0x2158 */ u8 pad2158[0x215C - 0x2158];
    /* 0x215C */ u8 unk215C[0x21E0 - 0x215C];
    /* 0x21E0 */ u8 unk21E0[0x221C - 0x21E0];
    /* 0x221C */ u8 unk221C[0x2244 - 0x221C];
    /* 0x2244 */ u8 unk2244[0x227C - 0x2244];
    /* 0x227C */ u8 unk227C;
    /* 0x227D */ u8 pad227D[0x2290 - 0x227D];
    /* 0x2290 */ u32 unk2290;
    /* 0x2294 */ u8 pad2294[0x2298 - 0x2294];
} Unk8008AAE8;

typedef struct Unk80304B90 {
    /* 0x000 */ u8 pad0[0x2DC];
    /* 0x2DC */ u32 unk2DC;
} Unk80304B90;

typedef struct Unk8038DC58 {
    /* 0x00 */ u8 pad0[0x90];
    /* 0x90 */ u8 unk90[0x10];
} Unk8038DC58;

extern Unk8008AAE8 lbl_803140C0;
extern Unk80304B90 lbl_80304B90;
extern u8 lbl_803051D8[];
extern Unk8038DC58 lbl_8038DC58;

void fn_800BB244(void);
void fn_8009E75C(void);
void fn_800D432C(void);
void fn_800833EC(s32 arg0, s32 arg1);
void fn_8008C07C(Unk8008AAE8* obj, s32 arg1);
void fn_800C7D00(u32 arg0);
void fn_8007DC78(void);
void fn_800B730C(u32 arg0, void* arg1);
void fn_8007D924(void* arg0);
void fn_800833D8(void* arg0);
void fn_800C6744(void* arg0);
void fn_800C66D8(void* arg0);
void fn_800E65FC(void);
void fn_800E666C(void);

void fn_8008AAE8(Unk8008AAE8* obj) {
    u32 id = obj->unk2154;
    u32 k;

    fn_800BB244();
    fn_8009E75C();
    fn_800D432C();
    switch (obj->unk227C) {
    case 0:
    case 1:
    case 2:
        if (obj->unk2 == 0) {
            fn_800833EC(8, 0x11);
            fn_8008C07C(obj, 8);
        } else if (obj->unk2 == 1) {
            k = id & 0xFFF;
            if (k - 1 < 8) {
                if (lbl_80304B90.unk2DC & (1 << k)) {
                    fn_8008C07C(obj, 0x108);
                } else {
                    fn_8008C07C(obj, 6);
                }
            } else {
                fn_8008C07C(obj, 3);
            }
            fn_800C7D00(id);
            lbl_80304B90.unk2DC |= 1 << k;
            fn_8007DC78();
        } else if (obj->unk2 == 2) {
            fn_8008C07C(&lbl_803140C0, 0x407);
        } else if (obj->unk2 == 3) {
            fn_8008C07C(obj, 9);
        }
        fn_800B730C(lbl_803140C0.unk2290, obj->unk21E0);
        fn_8007D924(obj->unk221C);
        lbl_803051D8[2] &= ~8;
        fn_800833D8(obj->unk2244);
        fn_800C6744(obj->unk215C);
        fn_800C66D8(lbl_8038DC58.unk90);
        break;
    case 3:
        fn_800E65FC();
        fn_800E666C();
        break;
    case 4:
        fn_800E65FC();
        fn_800E666C();
        break;
    }
}
