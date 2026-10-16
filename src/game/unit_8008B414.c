#include "types.h"

typedef struct Unk8008B414 {
    /* 0x0000 */ u8 pad0[0x2];
    /* 0x0002 */ u8 step;
    /* 0x0003 */ u8 pad3;
    /* 0x0004 */ s16 fade;
    /* 0x0006 */ s16 unk6;
    /* 0x0008 */ s16 timer;
    /* 0x000A */ s16 unkA;
    /* 0x000C */ u8 padC[0xDD0 - 0xC];
    /* 0x0DD0 */ u8 unkDD0[0x10];
} Unk8008B414;

typedef struct Unk8038B2F8Sub {
    /* 0x0000 */ u8 pad0[0x2500];
    /* 0x2500 */ u8 unk2500;
} Unk8038B2F8Sub;

typedef struct Unk8038B2F8 {
    /* 0x0000 */ u8 pad0[0x184];
    /* 0x0184 */ Unk8038B2F8Sub* unk184;
    /* 0x0188 */ u8 pad188[0x26C0 - 0x188];
} Unk8038B2F8;

extern Unk8038B2F8 lbl_8038B2F8;
extern void* lbl_804EE948;
extern u8 lbl_8043CD08[];
extern u8 lbl_803140C0[];

u32 VIGetTvFormat(void);
void fn_8008B6CC(Unk8008B414* obj);
void fn_8008BAF0(Unk8008B414* obj);
void fn_8008BF48(Unk8008B414* obj);
void fn_800E8BB8(void* arg0);
void fn_800D56A4(s32 music);
void fn_8008C07C(void* work, s32 arg1);
void fn_800E6A78(void* arg0);
void fn_8009C04C(s32 arg0, void* arg1, s32 arg2);
void fn_800A78AC(void);
void fn_800E8D30(void* arg0, s32 arg1);
void fn_800E8FC4(void* arg0, void* arg1);
void fn_800E69E8(void* arg0);

void fn_8008B414(Unk8008B414* obj) {
    switch (obj->step) {
    case 0:
        obj->fade += 2;
        if (obj->fade < 0x20) {
            fn_8008B6CC(obj);
            break;
        }
        obj->step++;
    case 1:
        if (VIGetTvFormat() == 1) {
            obj->timer += 9;
        } else {
            obj->timer += 8;
        }
        if (obj->timer < 0x100) {
            fn_8008B6CC(obj);
            break;
        }
        if (VIGetTvFormat() == 1) {
            obj->timer = 0xD;
        } else {
            obj->timer = 0x10;
        }
        obj->step++;
    case 2:
        if (--obj->timer > 0) {
            fn_8008BAF0(obj);
            break;
        }
        obj->unk6 = 1;
        if (VIGetTvFormat() == 1) {
            obj->timer = 0x1A;
        } else {
            obj->timer = 0x20;
        }
        obj->step++;
    case 3:
        if (--obj->timer > 0) {
            fn_8008BAF0(obj);
            break;
        }
        if (VIGetTvFormat() == 1) {
            obj->timer = 0x6A;
        } else {
            obj->timer = 0x80;
        }
        obj->unkA = 0;
        obj->step++;
    case 4:
        if (--obj->timer > 0) {
            fn_8008BAF0(obj);
            fn_8008BF48(obj);
            break;
        }
        if (VIGetTvFormat() == 1) {
            obj->timer = 0xA0;
        } else {
            obj->timer = 0xC0;
        }
        obj->step++;
    case 5:
        if (--obj->timer > 0) {
            fn_8008BAF0(obj);
            break;
        }
        obj->step++;
    case 6:
        obj->fade -= 2;
        if (obj->fade > 0) {
            fn_8008BAF0(obj);
            break;
        }
        fn_800E8BB8(lbl_804EE948);
        fn_800D56A4(1);
        fn_8008C07C(lbl_803140C0, 0x700);
        break;
    }
    fn_800E6A78(obj->unkDD0);
    fn_8009C04C(0, lbl_8043CD08, 0x20);
    fn_800A78AC();
    fn_800E8D30(lbl_804EE948, 0x100);
    fn_800E8FC4(lbl_804EE948, obj->unkDD0);
    fn_800E69E8(obj->unkDD0);
    lbl_8038B2F8.unk184->unk2500 = obj->fade;
}
