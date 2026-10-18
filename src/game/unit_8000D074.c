#include "types.h"

typedef struct Unk802BDCC0 {
    /* 0x0000 */ u8 pad0[0xF0A8];
    /* 0xF0A8 */ u16 unkF0A8;
    /* 0xF0AA */ u8 padF0AA[0xF0AC - 0xF0AA];
    /* 0xF0AC */ s32 unkF0AC;
} Unk802BDCC0;

extern Unk802BDCC0 lbl_802BDCC0;
extern u8 lbl_802CCDC0[];
extern u8 lbl_802E49C0[];
extern u8 lbl_802E492C[];
extern char* lbl_80261C20[];
extern u32 lbl_80261B70[];

void fn_8000E900(void);
void fn_8000E91C(void);
void* memset(void* dst, s32 c, u32 n);
s32 fn_8011A540(const char* path, s32 a, s32 b, void (*cb)(void), void* ctx);
s32 fn_8011B6EC(const char* path, void* fi, s32 mode, void (*cb)(void), void* ctx);
s32 fn_8011AA58(void* fi, void* buf, u32 size, void (*cb)(void), void* ctx);
s32 fn_8011B8C0(void* fi, void (*cb)(void), void* ctx);

static inline s32 Wait(void) {
    volatile Unk802BDCC0* w = &lbl_802BDCC0;

    while (w->unkF0A8 == 0) {
    }
    return w->unkF0AC;
}

s32 fn_8000D074(u8 idx) {

    memset(lbl_802E49C0, 0, 0x180);
    lbl_802BDCC0.unkF0A8 = 0;
    if (fn_8011A540(lbl_80261C20[idx], 0x30, 0, fn_8000E900, lbl_802CCDC0 + 0x178)) {
        fn_8000E91C();
        return 0;
    }
    if (Wait() != 0) {
        fn_8000E91C();
        return 0;
    }
    lbl_802BDCC0.unkF0A8 = 0;
    if (fn_8011B6EC(lbl_80261C20[idx], lbl_802E492C, 2, fn_8000E900, lbl_802CCDC0 + 0x234)) {
        fn_8000E91C();
        return 0;
    }
    if (Wait() != 0) {
        fn_8000E91C();
        return 0;
    }
    lbl_802BDCC0.unkF0A8 = 0;
    if (fn_8011AA58(lbl_802E492C, lbl_802E49C0, lbl_80261B70[idx], fn_8000E900, lbl_802CCDC0 + 0x468)) {
        fn_8000E91C();
        return 0;
    }
    if (Wait() != lbl_80261B70[idx]) {
        fn_8000E91C();
        lbl_802BDCC0.unkF0A8 = 0;
        if (fn_8011B8C0(lbl_802E492C, fn_8000E900, lbl_802CCDC0 + 0x524)) {
            fn_8000E91C();
            return 0;
        }
        if (Wait() != 0) {
            fn_8000E91C();
        }
        return 0;
    }
    lbl_802BDCC0.unkF0A8 = 0;
    if (fn_8011B8C0(lbl_802E492C, fn_8000E900, lbl_802CCDC0 + 0x524)) {
        fn_8000E91C();
        return 0;
    }
    if (Wait() != 0) {
        fn_8000E91C();
        return 0;
    }
    return 1;
}
