#include "types.h"

typedef struct Unk8003F64C {
    /* 0x000 */ u8 pad0[0x5];
    /* 0x005 */ u8 step;
    /* 0x006 */ u8 pad6[0x8 - 0x6];
    /* 0x008 */ s16 timer;
    /* 0x00A */ s16 rate;
    /* 0x00C */ u8 padC[0x48 - 0xC];
    /* 0x048 */ u8 unk48[0x26C - 0x48];
    /* 0x26C */ u8 unk26C;
    /* 0x26D */ u8 unk26D;
    /* 0x26E */ u8 pad26E[0x270 - 0x26E];
    /* 0x270 */ s16 unk270;
    /* 0x272 */ s16 unk272;
    /* 0x274 */ s16 unk274;
} Unk8003F64C;

typedef struct Unk80319DA0 {
    /* 0x000 */ u8 pad0[0x860];
    /* 0x860 */ u32 trig;
} Unk80319DA0;

typedef struct Unk8038B2F8Sub {
    /* 0x0000 */ u8 pad0[0x2500];
    /* 0x2500 */ u8 unk2500;
} Unk8038B2F8Sub;

typedef struct Unk8038B2F8 {
    /* 0x000 */ u8 pad0[0x184];
    /* 0x184 */ Unk8038B2F8Sub* unk184;
} Unk8038B2F8;

extern u8 lbl_80316D78[];
extern Unk80319DA0 lbl_80319DA0;
extern Unk8038B2F8 lbl_8038B2F8;
extern u8 lbl_8043CD08[];
extern void* lbl_804EE948;

u32 fn_800BB6C8(u32 a);
void fn_800BB7B8(s32 a);
void fn_800BB4E8(s32 a, s32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void fn_800D5234(s32 se);
void fn_8003F988(Unk8003F64C* obj);
void fn_800D5564(s32 arg0);
void fn_800D8F5C(Unk8003F64C* obj, s32 arg1, s32 arg2);
void fn_800D432C(void);
void fn_800316C8(Unk8003F64C* obj, s32 next);
void fn_800E6A78(void* arg0);
void fn_8009C04C(s32 arg0, void* arg1, s32 arg2);
void fn_800A78AC(void);
void fn_800E8D30(void* arg0, s32 arg1);
void fn_800E8FC4(void* arg0, void* arg1);
void fn_800E69E8(void* arg0);
void fn_8003FB88(s16 x, s16 y);

void fn_8003F64C(Unk8003F64C* obj) {
    u32 R;
    u32 a;
    u32 b;

    switch (obj->step) {
    case 0:
        fn_8003F988(obj);
        obj->step++;
    case 1:
        if (++obj->unk26C < 0x20) {
            break;
        }
        obj->step++;
    case 2:
        if (obj->unk270 > 0) {
            obj->unk270 -= obj->unk274;
        }
        if ((obj->unk272 += obj->unk274) < 0) {
            break;
        }
        obj->unk270 = 0;
        obj->unk272 = 0;
        obj->timer = 0x1000;
        obj->rate = 0x200;
        obj->step++;
    case 3:
        if ((obj->timer -= obj->rate) > 0) {
            break;
        }
        R = *(u32*)(lbl_80316D78 + 0x3004) + 0xC29000;
        a = *(u32*)(R + 0x10) >> 1;
        b = (*(u32*)(R + 0x14) >> 1) + R;
        fn_800BB4E8(0x8000, 0, a + R + *(u32*)(a + R), b + *(u32*)b, 0x20, 0, b, a + R);
        obj->step++;
    case 4:
        if ((u8)fn_800BB6C8(0x8000) != 3) {
            break;
        }
        fn_800BB7B8(0x8000);
        obj->timer = 0x1000;
        obj->rate = 0x80;
        obj->step++;
    case 5:
        if ((obj->timer -= obj->rate) > 0) {
            break;
        }
        fn_800D5564(0x18);
        fn_800D8F5C(obj, 0, 0);
        obj->timer = 0x1000;
        obj->rate = 3;
        obj->step++;
    case 6:
        if ((obj->timer -= obj->rate) <= 0) {
            obj->step = 0x14;
            obj->unk26D = 1;
            break;
        }
        if (!(lbl_80319DA0.trig & 0x40)) {
            break;
        }
        fn_800D5234(1);
        obj->unk26D = 1;
        obj->unk274 = 0x80;
        obj->step++;
    case 7:
        if ((obj->unk272 += obj->unk274) < 0x800) {
            break;
        }
        obj->step++;
    case 8:
        if (obj->unk272 < 0xFFF) {
            obj->unk272 += obj->unk274;
        } else {
            obj->unk272 = 0xFFF;
        }
        if (--obj->unk26C == 0) {
            fn_800D432C();
            fn_800316C8(obj, 7);
        }
        break;
    case 0x14:
        if (--obj->unk26C == 0) {
            fn_800D432C();
            fn_800316C8(obj, 3);
        }
        break;
    }
    fn_800E6A78(obj->unk48);
    fn_8009C04C(0, lbl_8043CD08, 0x20);
    fn_800A78AC();
    fn_800E8D30(lbl_804EE948, 0x100);
    fn_800E8FC4(lbl_804EE948, obj->unk48);
    fn_800E69E8(obj->unk48);
    fn_8003FB88(obj->unk270, obj->unk272);
    lbl_8038B2F8.unk184->unk2500 = obj->unk26C;
}
