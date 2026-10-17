#include "types.h"

typedef struct Unk8008A7FCSave {
    /* 0x00 */ u32 unk0[0x50 / 4];
} Unk8008A7FCSave;

typedef struct Unk803140C0 {
    /* 0x0000 */ u8 pad0[0x20F4];
    /* 0x20F4 */ Unk8008A7FCSave save;
    /* 0x2144 */ u8 pad2144[0x214C - 0x2144];
    /* 0x214C */ u8 unk214C;
    /* 0x214D */ u8 unk214D;
    /* 0x214E */ u8 unk214E;
    /* 0x214F */ u8 pad214F;
    /* 0x2150 */ s32 unk2150;
} Unk803140C0;

typedef struct Unk8038B2F8Sub {
    /* 0x0000 */ u8 pad0[0x2500];
    /* 0x2500 */ u8 unk2500;
    /* 0x2501 */ u8 unk2501;
    /* 0x2502 */ u8 unk2502;
    /* 0x2503 */ u8 unk2503;
} Unk8038B2F8Sub;

typedef struct Unk8038B2F8 {
    /* 0x0000 */ u8 pad0[0x184];
    /* 0x0184 */ Unk8038B2F8Sub* unk184;
    /* 0x0188 */ u8 pad188[0x26BC - 0x188];
    /* 0x26BC */ s16 unk26BC;
} Unk8038B2F8;

typedef struct Unk8008A7FC {
    /* 0x0000 */ u8 pad0[0x3];
    /* 0x0003 */ u8 step;
    /* 0x0004 */ s16 timer;
    /* 0x0006 */ u8 pad6[0xBC4 - 0x6];
    /* 0x0BC4 */ u8 unkBC4[0x2148 - 0xBC4];
    /* 0x2148 */ s32 unk2148;
} Unk8008A7FC;

extern Unk803140C0 lbl_803140C0;
extern Unk8038B2F8 lbl_8038B2F8;
extern Unk8008A7FCSave lbl_8037C3D8;
extern u8 lbl_8043CD08[];
extern void* lbl_804EE908;
extern void* lbl_804EE8F8;
extern void* lbl_804EE664;
extern void* lbl_804EE738;
extern void* lbl_804EE8AC;
extern void* lbl_804EE8C0;
extern void* lbl_804EE810;
extern void* lbl_804EE8A0;
extern void* lbl_804EE730;
extern void* lbl_804EE878;
extern void* lbl_804EE6C0;

void fn_800A70F8(void);
void fn_800AA508(void);
void fn_800A78C8(void);
void fn_8009E1F4(void);
void fn_800BB428(void);
void fn_80024058(s32 arg0);
void fn_800C6ED4(void);
void fn_800E6A78(void* arg0);
void fn_800997E4(void);
void fn_8009C04C(s32 arg0, void* arg1, s32 arg2);
void fn_800A78AC(void);
void fn_800E90D0(void* list, void* arg1);
void fn_800E8FC4(void* list, void* arg1);
void fn_800A78C0(void);
void fn_8007DC04(s32 arg0);
void fn_8008C07C(Unk8008A7FC* obj, s32 arg1);

void fn_8008A7FC(Unk8008A7FC* obj) {
    if (obj->step == 0) {
        lbl_8038B2F8.unk184->unk2501 = lbl_803140C0.unk214C;
        lbl_8038B2F8.unk184->unk2502 = lbl_803140C0.unk214D;
        lbl_8038B2F8.unk184->unk2503 = lbl_803140C0.unk214E;
        lbl_8037C3D8 = lbl_803140C0.save;
        fn_800A70F8();
        fn_800AA508();
        fn_800A78C8();
        fn_8009E1F4();
        lbl_8038B2F8.unk26BC = lbl_803140C0.unk2150;
        fn_800BB428();
        obj->timer = 0;
        fn_80024058(0);
        obj->step++;
    }
    fn_800C6ED4();
    fn_800E6A78(obj->unkBC4);
    fn_800997E4();
    fn_8009C04C(0, lbl_8043CD08, 0x20);
    fn_800A78AC();
    fn_800E90D0(lbl_804EE908, obj->unkBC4);
    fn_800E90D0(lbl_804EE8F8, obj->unkBC4);
    fn_800E90D0(lbl_804EE664, obj->unkBC4);
    fn_800E90D0(lbl_804EE738, obj->unkBC4);
    fn_800E90D0(lbl_804EE8AC, obj->unkBC4);
    fn_800E90D0(lbl_804EE8C0, obj->unkBC4);
    fn_800E8FC4(lbl_804EE810, obj->unkBC4);
    fn_800E8FC4(lbl_804EE8A0, obj->unkBC4);
    fn_800E8FC4(lbl_804EE730, obj->unkBC4);
    fn_800E90D0(lbl_804EE878, obj->unkBC4);
    fn_800E8FC4(lbl_804EE6C0, obj->unkBC4);
    fn_800A78C0();
    fn_8007DC04(1);
    obj->timer += 2;
    lbl_8038B2F8.unk184->unk2500 = obj->timer;
    if (obj->timer == 0x20) {
        obj->unk2148 = 0;
        fn_8008C07C(obj, 0xA00);
    }
}
