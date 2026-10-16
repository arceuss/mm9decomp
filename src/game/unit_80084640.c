#include "types.h"

typedef struct Unk80084640 {
    /* 0x0000 */ u8 pad0[0x2];
    /* 0x0002 */ u8 step;
    /* 0x0003 */ u8 pad3;
    /* 0x0004 */ s16 fade;
    /* 0x0006 */ u8 pad6[0x8 - 0x6];
    /* 0x0008 */ s16 timer;
    /* 0x000A */ s16 speed;
    /* 0x000C */ u8 padC[0xDD0 - 0xC];
    /* 0x0DD0 */ u8 unkDD0[0xFF5 - 0xDD0];
    /* 0x0FF5 */ u8 cursor;
    /* 0x0FF6 */ u8 padFF6[0x2154 - 0xFF6];
    /* 0x2154 */ s32 unk2154;
} Unk80084640;

typedef struct Unk8038B2F8Sub {
    /* 0x0000 */ u8 pad0[0x2500];
    /* 0x2500 */ u8 unk2500;
} Unk8038B2F8Sub;

typedef struct Unk8038B2F8 {
    /* 0x0000 */ u8 pad0[0x184];
    /* 0x0184 */ Unk8038B2F8Sub* unk184;
    /* 0x0188 */ u8 pad188[0x26BC - 0x188];
    /* 0x26BC */ s16 unk26BC;
    /* 0x26BE */ u8 pad26BE[0x26C0 - 0x26BE];
} Unk8038B2F8;

extern u8 lbl_80316D78[];
extern Unk8038B2F8 lbl_8038B2F8;
extern void* lbl_804EE948;
extern u8 lbl_8043CD08[];
extern s32 lbl_80272FD8[];
extern u8 lbl_803140C0[];

void fn_800D5564(s32 arg0);
void fn_800BB938(s32 arg0, u32 data, s32 arg2);
void fn_800DB280(Unk80084640* obj, s32 arg1, u8 arg2);
void fn_800E8BB8(void* arg0);
void fn_800D432C(void);
void fn_8008C07C(void* work, s32 arg1);
void fn_800E6A78(void* arg0);
void fn_8009C04C(s32 arg0, void* arg1, s32 arg2);
void fn_800A78AC(void);
void fn_800E8D30(void* arg0, s32 arg1);
void fn_800E8FC4(void* arg0, void* arg1);
void fn_800E69E8(void* arg0);

void fn_80084640(Unk80084640* obj) {
    u32 R;
    u32 a;

    switch (obj->step) {
    case 0:
        obj->fade += 2;
        if (obj->fade < 0x20) {
            break;
        }
        fn_800D5564(6);
        obj->timer = 0;
        obj->speed = 0xC;
        obj->step++;
    case 1:
        obj->timer += obj->speed;
        if (obj->timer < 0x1000) {
            break;
        }
        obj->step++;
    case 2:
        R = *(u32*)(lbl_80316D78 + 0x3004) + 0xCD5000;
        a = *(u32*)(R + 0x14) >> 1;
        fn_800BB938(1, R + a + *(u32*)(R + a), 0);
        obj->timer = 0;
        obj->step++;
    case 3:
        obj->timer++;
        if (obj->timer < 0x38) {
            if (!(obj->timer & 8)) {
                lbl_8038B2F8.unk26BC = 0;
            } else {
                lbl_8038B2F8.unk26BC = 0x7FFF;
            }
            break;
        }
        lbl_8038B2F8.unk26BC = 0;
        fn_800DB280(obj, 3, obj->cursor);
        obj->timer = 0xB4;
        obj->step++;
    case 4:
        if (--obj->timer > 0) {
            break;
        }
        obj->step++;
    case 5:
        obj->fade -= 2;
        if (obj->fade > 0) {
            break;
        }
        fn_800E8BB8(lbl_804EE948);
        fn_800D432C();
        obj->unk2154 = lbl_80272FD8[obj->cursor];
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
