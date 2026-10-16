#include "types.h"

typedef struct Unk8038B2F8 {
    /* 0x0000 */ u8 pad0[0x26BC];
    /* 0x26BC */ u16 unk26BC;
    /* 0x26BE */ u8 pad26BE[0x26C0 - 0x26BE];
} Unk8038B2F8;

typedef struct Unk803B92C0 {
    /* 0x00 */ u8 pad0[0x3C];
    /* 0x3C */ void* fb[2];
    /* 0x44 */ u8 cur;
} Unk803B92C0;

extern Unk8038B2F8 lbl_8038B2F8;
extern Unk803B92C0 lbl_803B92C0;
extern u8 lbl_8039B2C0[];
extern u8 lbl_8039B240[];

void fn_800E6BA0(void);
void fn_800E79A0(void);
void fn_800E7410(u16 arg0);
void fn_800E7D2C(void);
void fn_800E6CF8(u32 line, u32 layer);
void fn_800E7AE0(u32 line, u32 layer);
void fn_800E6E04(void);
void fn_800E7BC0(void);
void fn_8011133C(void);
void fn_80111C2C(u32 x, u32 y, u32 w, u32 h);
void fn_80111C90(u16 w, u16 h, s32 fmt, s32 arg3);
void fn_8011249C(void* dst, s32 clear);
void fn_801113FC(void);
void DCFlushRange(void* addr, u32 size);
void fn_80112360(void* fb, s32 arg1);
void fn_800D5C38(s32 arg0, void* arg1, s32 arg2);

void fn_800E7308(void) {
    u32 line;
    s32 layer;

    fn_800E6BA0();
    fn_800E79A0();
    fn_800E7410(lbl_8038B2F8.unk26BC);
    for (line = 0; line < 0xE0; line++) {
        fn_800E7D2C();
        for (layer = 3; layer >= 0; layer--) {
            fn_800E6CF8(line, layer);
            fn_800E7AE0(line, layer);
        }
    }
    fn_800E6E04();
    fn_800E7BC0();
    fn_8011133C();
    fn_80111C2C(0, 0, 0x100, 0xF0);
    fn_80111C90(0x100, 0xF0, 4, 0);
    fn_8011249C(lbl_8039B2C0, 1);
    fn_801113FC();
    DCFlushRange(lbl_8039B2C0, 0x1E000);
    fn_80112360(lbl_803B92C0.fb[lbl_803B92C0.cur], 1);
    fn_800D5C38(2, lbl_8039B240, 3);
}
