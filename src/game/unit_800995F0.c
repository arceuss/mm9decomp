#include "types.h"

extern u8 lbl_803B92C0[];

void fn_80114628(s32, s32, s32);
void fn_801145D0(s32);
void fn_80112360(u32, s32);
void fn_8011133C(void);
void fn_800E766C(void);

void fn_800995F0(void) {
    fn_80114628(1, 3, 1);
    fn_801145D0(1);
    fn_80112360(*(u32*)(lbl_803B92C0 + (*(u8*)(lbl_803B92C0 + 0x44) << 2) + 0x3C), 1);
    fn_8011133C();
    fn_800E766C();
}
