#include "types.h"

typedef void (*UnkFn31650)(u8* obj);
extern UnkFn31650 lbl_802642F0[];
extern u8 lbl_80301420[];
extern u8 lbl_80316D28[];
void fn_800E65B0(void);
void fn_800E65E8(void);
void fn_800E65FC(void);
void fn_800E6610(s32);
void fn_800D58B0(void);

void fn_80031650(void) {
    fn_800E65B0();
    for (;;) {
        fn_800E65E8();
        if (lbl_80316D28[3] == 0 && lbl_80316D28[4] < 2) {
            fn_800D58B0();
            lbl_802642F0[lbl_80301420[4]](lbl_80301420);
        }
        fn_800E65FC();
        fn_800E6610(1);
    }
}
