#include "types.h"

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3000];
    /* 0x3000 */ u16 unk3000;
    /* 0x3002 */ u16 unk3002;
    /* 0x3004 */ u8 pad3004[0x3010 - 0x3004];
} Unk80316D78;

typedef struct Unk80316D28 {
    /* 0x0 */ u8 pad0[0x3];
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 pad5[0x10 - 0x5];
} Unk80316D28;

typedef struct Unk802BDCC0 {
    /* 0x0000 */ u8 pad0[0xF0AA];
    /* 0xF0AA */ u8 unkF0AA;
    /* 0xF0AB */ u8 padF0AB[0xF100 - 0xF0AB];
} Unk802BDCC0;

typedef struct Unk80301420 {
    /* 0x000 */ u8 pad0[0x18];
    /* 0x018 */ void* unk18;
    /* 0x01C */ u8 pad1C[0x380 - 0x1C];
} Unk80301420;

typedef struct Unk803140C0 {
    /* 0x0000 */ u8 pad0[0xC];
    /* 0x000C */ void* unkC;
    /* 0x0010 */ u8 pad10[0x2298 - 0x10];
} Unk803140C0;

extern Unk80316D78 lbl_80316D78;
extern Unk80316D28 lbl_80316D28;
extern Unk802BDCC0 lbl_802BDCC0;
extern Unk80301420 lbl_80301420;
extern Unk803140C0 lbl_803140C0;
extern u8 lbl_804EE880;
extern u8 lbl_804EE881;

void fn_800E5204(void);
void fn_8000BFC4(void);
void fn_800D5918(s32 arg0);
void fn_8009D780(void);
void fn_8009B304(void);
void fn_80099200(void);
void fn_800A5784(void);
void fn_800A5788(void);
void fn_800E8678(void);
void fn_800E7FA4(void);
void fn_800E7308(void);
void fn_80099394(void);
void fn_800D5990(void);
void fn_80083730(void);
void fn_8009B6FC(void);
void fn_800995F0(void);
void fn_8009964C(void);
void fn_800AA9A8(void);
void fn_800D42E8(void);
void fn_800D50C0(void);
void fn_800D432C(void);
void fn_800E7500(void);
void fn_800F69DC(s32 arg0);
void fn_8009B7B4(void);
void fn_801E1EF4(void);
void fn_800F68C0(void);

void fn_8009DCB8(void) {
    BOOL paused = FALSE;

    lbl_80316D78.unk3000 = 0;
    lbl_80316D78.unk3002 = !lbl_80316D78.unk3002;
    fn_800E5204();
    fn_8000BFC4();
    if (lbl_80316D28.unk3 != 0 || lbl_80316D28.unk4 >= 2) {
        paused = TRUE;
    }
    if (!paused) {
        fn_800D5918(2);
    }
    fn_8009D780();
    fn_8009B304();
    fn_80099200();
    fn_800A5784();
    fn_800A5788();
    fn_800E8678();
    fn_800E7FA4();
    if (!paused) {
        fn_800E7308();
    }
    fn_80099394();
    fn_800D5990();
    fn_80083730();
    fn_8009B6FC();
    fn_800995F0();
    fn_8009964C();
    fn_800AA9A8();
    fn_800D42E8();
    fn_800D50C0();
    if ((lbl_804EE880 != 0 || lbl_804EE881 != 0) && lbl_802BDCC0.unkF0AA == 0 && lbl_80301420.unk18 != NULL &&
        lbl_803140C0.unkC != NULL) {
        fn_800D432C();
        if (lbl_804EE880 != 0) {
            if (lbl_80316D28.unk3 == 0 || lbl_80316D28.unk4 != 3) {
                fn_800E7500();
                fn_800F69DC(0);
            } else {
                fn_8009B7B4();
            }
            lbl_804EE880 = 0;
        }
        if (lbl_804EE881 != 0) {
            fn_800E7500();
            fn_801E1EF4();
            fn_800F68C0();
        }
    }
}
