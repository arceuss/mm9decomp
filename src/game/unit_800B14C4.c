#include "types.h"

extern u8 lbl_804ECE64[4];
extern u32 lbl_8027EB60[];
extern void (*lbl_8027E7F0[])(u8*);

void fn_800B7844(void);
s32 fn_800B34FC(u8* obj);
void fn_800C71F8(u32 v);
void fn_800B5918(u8* obj, s32 v);
void fn_800B9F74(u8* obj, u32 v);

s32 fn_800B14C4(u8* obj) {
    switch (obj[0xF0]) {
    case 0:
        fn_800B7844();
        obj[0xF3] = obj[0xF0];
        obj[0xF0] = 1;
        obj[0xF4] = obj[0xF1];
        obj[0xF1] = 0;
    case 1: {
        u32 r = fn_800B34FC(obj);

        if (13 - r > 1) {
            obj[0xF2] = obj[0xEF];
            obj[0xEF] = 1;
            obj[0xF3] = obj[0xF0];
            obj[0xF0] = 0;
            obj[0xF4] = obj[0xF1];
            obj[0xF1] = 0;
            return 0;
        }
        fn_800C71F8(r & 0xFF);
        if (r == 12) {
            obj[0xF2] = obj[0xEF];
            obj[0xEF] = 1;
            obj[0xF3] = obj[0xF0];
            obj[0xF0] = 0;
            obj[0xF4] = obj[0xF1];
            obj[0xF1] = 0;
            return 0;
        }
        fn_800B5918(obj, 1);
        obj[0xF3] = obj[0xF0];
        obj[0xF0] = 2;
        obj[0xF4] = obj[0xF1];
        obj[0xF1] = 0;
        obj[0xFC] = lbl_804ECE64[obj[0xF5]];
        fn_800B9F74(obj, *(u32*)(lbl_8027EB60[obj[9]] + lbl_804ECE64[obj[0xF5]] * 4));
        obj[0x10E] = 0x10;
    }
    case 2: {
        u8 t = lbl_804ECE64[obj[0xF5]];

        if (obj[0xFC] != t) {
            if (obj[0xF5] != 1 || obj[0x12] >= 2) {
                obj[0xFC] = t;
                fn_800B9F74(obj, *(u32*)(lbl_8027EB60[obj[9]] + lbl_804ECE64[obj[0xF5]] * 4));
            }
        }
        {
            s32 _t = obj[0x10E] - 1;
            obj[0x10E] = _t;
            if (_t <= 0) {
                obj[0xF2] = obj[0xEF];
                obj[0xEF] = 1;
                obj[0xF3] = obj[0xF0];
                obj[0xF0] = 0;
                obj[0xF4] = obj[0xF1];
                obj[0xF1] = 0;
                lbl_8027E7F0[obj[0xF5]](obj);
            }
        }
        break;
    }
    }
    return 0;
}
