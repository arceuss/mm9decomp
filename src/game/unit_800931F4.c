#include "types.h"

typedef struct Unk800931F4 {
    u8 pad0[2];
    u8 step;
    u8 pad3;
    s16 unk4;
    u8 pad6[0xDD0-6];
    u8 unkDD0[0xFF4-0xDD0];
    u32 unkFF4;
    u32 unkFF8;
    u8 padFFC[0x1020-0xFFC];
    u16 unk1020;
    u8 unk1022;
    u8 pad1023[0x1070-0x1023];
    u32 unk1070;
    u8 pad1074[0x227C-0x1074];
    u8 unk227C;
} Unk800931F4;

typedef struct Unk80316D78 {
    u8 pad0[0x3004];
    u8* unk3004;
} Unk80316D78;

typedef struct Unk8038B2F8 {
    u8 pad0[0x184];
    u8* unk184;
} Unk8038B2F8;

extern Unk80316D78 lbl_80316D78;
extern Unk8038B2F8 lbl_8038B2F8;
extern u32 lbl_80383E70[];
extern u8 lbl_803051D8[];
extern u8 lbl_803140C0[];
extern u8 lbl_8043CD08[];
extern void* lbl_804EE948;
extern void* lbl_804EE730;
void fn_800D5564(s32);
void fn_800936C8(Unk800931F4*);
void fn_800939EC(Unk800931F4*);
void fn_80093C1C(Unk800931F4*);
void fn_80093E9C(Unk800931F4*);
void fn_800A7860(void);
void fn_800A7C78(s32);
void* fn_8000EF20(s32);
void fn_800E83A4(void*, void*);
void fn_800BAF48(void*, s32);
void fn_8000ECB8(s32, void*, s32, s32, s32);
void fn_800BB4E8(s32, s32, u32, u32, u32, u32, u32, u32);
u8 fn_800BB6C8(s32);
void fn_800BB7B8(s32);
void fn_800E4668(Unk800931F4*, s32, s32);
void fn_800E8BB8(void*);
void fn_800D432C(void);
void fn_8008C07C(void*, s32);
void fn_800E6A78(void*);
void fn_8009C04C(s32, void*, s32);
void fn_800A78AC(void);
void fn_800E8D30(void*, u16);
void fn_800E8FC4(void*, void*);
void fn_800E69E8(void*);

static inline void Draw(Unk800931F4* obj) {
    fn_800936C8(obj);
    fn_800939EC(obj);
    fn_80093C1C(obj);
}

void fn_800931F4(Unk800931F4* obj) {
    u32 R;
    u32 a;
    u32 b;
    void* p;
    switch (obj->step) {
    case 0:
        obj->unkFF4 = 0;
        obj->unkFF8 = 0x59;
        obj->unk4 = 0;
        fn_800D5564(0x1A);
        obj->step++;
    case 1:
        obj->unk4 += 2;
        if (obj->unk4 < 0x20) { Draw(obj); break; }
        obj->step++;
    case 2:
        obj->unkFF4 += (obj->unkFF8 * obj->unk1020) >> 8;
        if (obj->unkFF4 < 0x100000) { Draw(obj); break; }
        fn_800A7860();
        lbl_80383E70[0] = obj->unk1070;
        fn_800A7C78(0);
        fn_800A7C78(0x5D);
        if (obj->unk227C == 1) fn_800A7C78(0x180);
        else if (lbl_803051D8[3] & 0x20) fn_800A7C78(0x141);
        else fn_800A7C78(0x140);
        R = (u32)lbl_80316D78.unk3004 + 0xCD5000;
        p = fn_8000EF20(0x38);
        fn_800E83A4((u8*)((*(u32*)(R+8) >> 1) + R) + 0xA0, p);
        R = (u32)lbl_80316D78.unk3004 + 0xCD5000;
        fn_800BAF48((u8*)((*(u32*)(R+8) >> 1) + R) + 0xAC, 0);
        R = (u32)lbl_80316D78.unk3004 + 0xCD5000;
        fn_8000ECB8(0x38, (void*)((*(u32*)(R+4) >> 1) + R), 0x32, 0, 0);
        R = (u32)lbl_80316D78.unk3004 + 0xCD5000;
        a = *(u32*)(R+0x14) >> 1;
        b = (*(u32*)(R+0x18) >> 1) + R;
        fn_800BB4E8(0x8100, 0, a + R + ((u32*)(a+R))[1], b + ((u32*)b)[1], 0, 0, b, a + R);
        obj->step++;
    case 3:
        if (fn_800BB6C8(0x8100) != 3) { fn_80093E9C(obj); break; }
        fn_800BB7B8(0x8100);
        obj->unkFF4 = 0;
        obj->unkFF8 = 0x4444;
        obj->step++;
    case 4:
        obj->unkFF4 += (obj->unkFF8 * obj->unk1020) >> 8;
        if (obj->unkFF4 < 0x100000) { fn_80093E9C(obj); break; }
        obj->unk1022 = 0;
        fn_800E4668(obj, 1, 0);
        obj->unkFF4 = 0;
        obj->unkFF8 = 0x2D82;
        obj->step++;
    case 5:
        obj->unkFF4 += (obj->unkFF8 * obj->unk1020) >> 8;
        if (obj->unkFF4 < 0x100000) { fn_80093E9C(obj); break; }
        obj->unk1022 = 1;
        obj->unkFF4 = 0;
        obj->unkFF8 = 0x1111;
        obj->step++;
    case 6:
        obj->unkFF4 += (obj->unkFF8 * obj->unk1020) >> 8;
        if (obj->unkFF4 < 0x100000) { fn_80093E9C(obj); break; }
        obj->unk1022 = 2;
        obj->unkFF4 = 0;
        obj->unkFF8 = 0x888;
        obj->step++;
    case 7:
        obj->unkFF4 += (obj->unkFF8 * obj->unk1020) >> 8;
        if (obj->unkFF4 < 0x100000) { fn_80093E9C(obj); break; }
        obj->step++;
    case 8:
        obj->unk4 -= 2;
        if (obj->unk4 > 0) { fn_80093E9C(obj); break; }
        fn_800E8BB8(lbl_804EE948);
        fn_800E8BB8(lbl_804EE730);
        fn_800D432C();
        obj->unkFF4 = 0;
        obj->unkFF8 = 0x4444;
        obj->step++;
    case 9:
        obj->unkFF4 += (obj->unkFF8 * obj->unk1020) >> 8;
        if (obj->unkFF4 >= 0x100000) fn_8008C07C(lbl_803140C0, 0xF00);
        break;
    }
    fn_800E6A78(obj->unkDD0);
    fn_8009C04C(0, lbl_8043CD08, 0x20);
    fn_800A78AC();
    fn_800E8D30(lbl_804EE948, obj->unk1020);
    fn_800E8D30(lbl_804EE730, obj->unk1020);
    fn_800E8FC4(lbl_804EE948, obj->unkDD0);
    fn_800E8FC4(lbl_804EE730, obj->unkDD0);
    fn_800E69E8(obj->unkDD0);
    lbl_8038B2F8.unk184[0x2500] = obj->unk4;
}
