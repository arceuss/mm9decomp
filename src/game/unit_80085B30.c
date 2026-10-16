#include "types.h"

typedef struct Unk80085B30 {
    /* 0x0000 */ u8 unk0;
    /* 0x0001 */ u8 unk1;
    /* 0x0002 */ u8 pad2[0xFF6 - 0x2];
    /* 0x0FF6 */ u8 unkFF6;
} Unk80085B30;

extern s32 lbl_802731F8[];
extern void* lbl_804EE948;

void fn_800BB7B8(s32 id);
BOOL fn_800D57BC(s32 id);
void fn_800D56A4(s32 id);
void fn_800D5478(void);
void fn_800E5798(void);
void fn_800A576C(void);
void fn_800E8BB8(void* list);
void fn_8008C07C(Unk80085B30* s, s32 arg1);

void fn_80085B30(Unk80085B30* s) {
    fn_800BB7B8(0);
    fn_800BB7B8(1);
    fn_800BB7B8(2);
    fn_800BB7B8(3);
    fn_800BB7B8(4);
    fn_800BB7B8(5);
    fn_800BB7B8(6);
    fn_800BB7B8(7);
    fn_800BB7B8(8);
    fn_800BB7B8(9);
    fn_800BB7B8(10);
    fn_800BB7B8(11);
    if (fn_800D57BC(lbl_802731F8[s->unk1])) {
        fn_800D56A4(lbl_802731F8[s->unk1]);
    }
    fn_800D5478();
    fn_800E5798();
    fn_800A576C();
    fn_800E8BB8(lbl_804EE948);
    if (s->unkFF6 == 0) {
        fn_8008C07C(s, 2);
    } else if (s->unkFF6 == 1) {
        fn_8008C07C(s, 9);
    }
}
