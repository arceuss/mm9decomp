#include "types.h"

typedef struct Unk80091530 {
    u8 pad0[2];
    u8 step;
    u8 pad3;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    u8 padC[0xDD0-0xC];
    u8 unkDD0[0x2154-0xDD0];
    u32 unk2154;
    u8 pad2158[0x2220-0x2158];
    u32 unk2220;
    u8 pad2224[0x227C-0x2224];
    u8 unk227C;
} Unk80091530;

typedef struct Unk80319DA0 {
    u8 pad0[0x860];
    u32 unk860;
} Unk80319DA0;

typedef struct Unk8038B2F8 {
    u8 pad0[0x184];
    u8* unk184;
    u8 pad188[0x26BC-0x188];
    u16 unk26BC;
} Unk8038B2F8;

extern Unk80319DA0 lbl_80319DA0;
extern Unk8038B2F8 lbl_8038B2F8;
extern u32 lbl_80273E90[];
extern u8 lbl_803140C0[];
extern u8 lbl_8043CD08[];
extern void* lbl_804EE948;
void fn_800D5564(s32);
void fn_800D56A4(s32);
void fn_800D5234(s32);
void fn_8008C07C(void*, s32);
void fn_800E8BB8(void*);
void fn_800E6A78(void*);
void fn_8009C04C(s32, void*, s32);
void fn_800A78AC(void);
void fn_800E8D30(void*, u16);
void fn_800E8FC4(void*, void*);
void fn_800E69E8(void*);

static inline void Flash(Unk80091530* obj) {
    if ((obj->unk8 >> 3) & 1) lbl_8038B2F8.unk26BC = 0;
    else lbl_8038B2F8.unk26BC = 0x7FFF;
}

void fn_80091530(Unk80091530* obj) {
    s32 old;
    s32 n;
    u32 rows;
    switch (obj->step) {
    case 0:
        obj->unk4 += 2;
        if (obj->unk4 < 0x20) break;
        obj->unk8 = 0x40;
        obj->step++;
    case 1:
        if ((obj->unk2220 & 2) && (obj->unk2220 & 4) && (obj->unk2220 & 8) && (obj->unk2220 & 0x10) && (obj->unk2220 & 0x20) && (obj->unk2220 & 0x40) && (obj->unk2220 & 0x80) && (obj->unk2220 & 0x100) && obj->unkA == 0) {
            obj->unk8--;
            if (obj->unk8 > 0) { Flash(obj); break; }
            obj->unkA = 1;
            lbl_8038B2F8.unk26BC = 0;
        }
        fn_800D5564(0);
        obj->step++;
    case 2:
        rows = (obj->unk227C != 1) + 3;
        n = old = obj->unk6;
        if (old < 9) {
            if (lbl_80319DA0.unk860 & 4) n = ((u32)old + 2) % 3 + ((u32)old / 3) * 3;
            else if (lbl_80319DA0.unk860 & 8) n = ((u32)old + 4) % 3 + ((u32)old / 3) * 3;
        }
        if (n < 9) {
            if (lbl_80319DA0.unk860 & 1) n = (u32)n % 3 + (((u32)n / 3 + rows - 1) % rows) * 3;
            else if (lbl_80319DA0.unk860 & 2) n = (u32)n % 3 + (((u32)n / 3 + rows + 1) % rows) * 3;
        } else {
            if (lbl_80319DA0.unk860 & 1) n = 7;
            else if (lbl_80319DA0.unk860 & 2) n = 1;
        }
        if (n != old) fn_800D5234(0);
        if ((lbl_80319DA0.unk860 & 0x50) && (obj->unkA != 0 || n != 4)) {
            if (n == 4) { obj->unk8 = 0; obj->step = 4; }
            else if (n >= 9) { obj->unk8 = 0; obj->step = 4; }
            else if (obj->unk2220 & (1 << (lbl_80273E90[n] & 0xFFF))) { obj->unk8 = 0; obj->step = 4; }
            else { obj->unk8 = 0x40; obj->step = 3; }
            fn_800D56A4(0);
            fn_800D5234(1);
        }
        obj->unk6 = n;
        break;
    case 3:
        obj->unk8--;
        if (obj->unk8 > 0x10) { Flash(obj); break; }
        obj->step++;
    case 4:
        obj->unk4 -= 2;
        if (obj->unk4 > 0) {
            if (obj->unk8 != 0) {
                obj->unk8--;
            if (obj->unk8 > 0) Flash(obj);
            }
        } else {
            lbl_8038B2F8.unk26BC = 0;
            if (obj->unk6 >= 9) fn_8008C07C(lbl_803140C0, 5);
            else if (obj->unk6 == 4) fn_8008C07C(lbl_803140C0, 3);
            else {
                obj->unk2154 = lbl_80273E90[obj->unk6];
                if (obj->unk2220 & (1 << (obj->unk2154 & 0xFFF))) fn_8008C07C(lbl_803140C0, 0x700);
                else fn_8008C07C(lbl_803140C0, 4);
            }
            fn_800E8BB8(lbl_804EE948);
        }
        break;
    }
    fn_800E6A78(obj->unkDD0);
    fn_8009C04C(0, lbl_8043CD08, 0x20);
    fn_800A78AC();
    fn_800E8D30(lbl_804EE948, 0x100);
    fn_800E8FC4(lbl_804EE948, obj->unkDD0);
    fn_800E69E8(obj->unkDD0);
    lbl_8038B2F8.unk184[0x2500] = obj->unk4;
}
