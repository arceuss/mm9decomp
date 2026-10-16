#include "types.h"

typedef struct Unk91E44 {
    /* 0x0000 */ u8 pad0[2];
    /* 0x0002 */ u8 unk02;
    /* 0x0003 */ u8 pad3[0xDD0 - 0x3];
    /* 0x0DD0 */ u8 unkDD0[0x1010 - 0xDD0];
    /* 0x1010 */ u8 unk1010[4];
} Unk91E44;

extern u8 lbl_8043CD08[];
extern u32 lbl_80273F3C[];
extern void* lbl_804EE948;

void fn_800E6A78(void*);
void fn_8009C04C(s32, void*, s32);
void fn_800A78AC(void);
s32 fn_800C688C(void);
void fn_800E57E4(void);
void fn_800E8D30(void*, u32);
void fn_800E8FC4(void*, void*);
void fn_800E69E8(void*);
void fn_80092834(void*);

void fn_80091E44(Unk91E44* p) {
    fn_800E6A78(p->unkDD0);
    fn_8009C04C(0, lbl_8043CD08, 0x20);
    fn_800A78AC();
    if (fn_800C688C() == 0) {
        ((void (*)(Unk91E44*))lbl_80273F3C[p->unk02])(p);
        fn_800E57E4();
        fn_800E8D30(lbl_804EE948, 0x100);
    }
    fn_800E8FC4(lbl_804EE948, p->unkDD0);
    fn_800E69E8(p->unkDD0);
    fn_80092834(p->unk1010);
}
