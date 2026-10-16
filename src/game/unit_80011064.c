#include "types.h"

extern u8 lbl_80262100[];
void fn_800E946C(u8* obj, s32 a);
void fn_8009996C(u8* a, u8* b);
void fn_800E9750(u8*, u16);
void fn_800C7608(void);

void fn_80011064(u8* obj) {
    switch (obj[0x12]) {
    case 0:
        fn_800E946C(obj, 1);
        fn_8009996C(obj + 0x88, lbl_80262100);
        obj[0x0A] |= 1;
        obj[0x16] = 30;
        obj[0x12]++;
    case 1:
        if (*(u32*)(obj + 0xA0) & 1) {
            obj[0x11] = 4;
            obj[0x12] = 0;
        } else {
            if (--obj[0x16] == 0) {
                obj[0x11] = 3;
                obj[0x12] = 0;
            }
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    }
}
