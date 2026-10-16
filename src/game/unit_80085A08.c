#include "types.h"

typedef struct Unk80085A08 {
    /* 0x0000 */ u8 unk0;
    /* 0x0001 */ u8 unk1;
    /* 0x0002 */ u8 unk2;
    /* 0x0003 */ u8 unk3;
    /* 0x0004 */ u8 pad4[0xDD0 - 0x4];
    /* 0x0DD0 */ u8 unkDD0[0xFF4 - 0xDD0];
    /* 0x0FF4 */ u8 unkFF4;
    /* 0x0FF5 */ u8 padFF5;
    /* 0x0FF6 */ u8 unkFF6;
    /* 0x0FF7 */ u8 unkFF7;
    /* 0x0FF8 */ u8 padFF8[0x1000 - 0xFF8];
    /* 0x1000 */ u8 unk1000;
    /* 0x1001 */ u8 unk1001;
    /* 0x1002 */ u8 unk1002;
    /* 0x1003 */ u8 unk1003;
} Unk80085A08;

typedef struct Unk80319DA0 {
    /* 0x000 */ u8 pad0[0x860];
    /* 0x860 */ u32 unk860;
} Unk80319DA0;

extern Unk80319DA0 lbl_80319DA0;
extern u32 lbl_8043CD08[8];
extern void (*lbl_80273148[])(Unk80085A08* s);
extern void* lbl_804EE730;
extern void* lbl_804EE948;

void fn_800E6A78(void* arg0);
void fn_8009C04C(u32 fill, void* dst, u32 size);
void fn_800A78AC(void);
void fn_800E8D30(void* list, s32 arg1);
void fn_800E57E4(void);
void fn_800E8FC4(void* list, void* arg1);
void fn_800E69E8(void* arg0);
void fn_800891A0(void* arg0);

void fn_80085A08(Unk80085A08* s) {
    fn_800E6A78(s->unkDD0);
    fn_8009C04C(0, lbl_8043CD08, 0x20);
    fn_800A78AC();
    if ((lbl_80319DA0.unk860 & 0x40) && s->unkFF7 == 0) {
        s->unk1001 = 4;
        s->unk1003 = 4;
        s->unkFF7 = 1;
    }
    if (s->unkFF7 == 0) {
        lbl_80273148[s->unk1](s);
        fn_800E8D30(lbl_804EE730, 0x100);
        fn_800E8D30(lbl_804EE948, 0x100);
        fn_800E57E4();
    } else if (s->unk1001 == 0) {
        s->unkFF4 = 0xFF;
        s->unkFF6 = s->unk1 == 4;
        s->unk2 = 2;
        s->unk3 = 0;
    }
    fn_800E8FC4(lbl_804EE730, s->unkDD0);
    fn_800E8FC4(lbl_804EE948, s->unkDD0);
    fn_800E69E8(s->unkDD0);
    fn_800891A0(&s->unk1000);
}
