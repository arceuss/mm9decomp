#include "types.h"

typedef struct Unk80092A04 {
    /* 0x0000 */ u8 pad0[0x2];
    /* 0x0002 */ u8 mode;
    /* 0x0003 */ u8 step;
    /* 0x0004 */ u8 pad4[0x1008 - 0x4];
    /* 0x1008 */ u8 sel;
} Unk80092A04;

typedef struct Unk80319DA0 {
    /* 0x000 */ u8 pad0[0x860];
    /* 0x860 */ u32 trig;
    /* 0x864 */ u16 repeat;
} Unk80319DA0;

extern Unk80319DA0 lbl_80319DA0;

u8 fn_80092CC4(Unk80092A04* obj);
void fn_800D5234(s32 se);

static inline void SetRow(Unk80092A04* obj, s32 n) {
    obj->sel = obj->sel % 5 + n % 3 * 5;
}

static inline void Set(Unk80092A04* obj, s32 row, u8 col) {
    obj->sel = col % 5 + row * 5;
}

void fn_80092A04(Unk80092A04* obj) {
    s32 v;

    if (lbl_80319DA0.trig & 0x10) {
        if (fn_80092CC4(obj)) {
            obj->step = 10;
        } else if (obj->sel >= 10) {
            fn_800D5234(1);
            obj->mode = 3;
            obj->step = 0;
        } else {
            fn_800D5234(10);
            obj->step++;
        }
    } else if (lbl_80319DA0.trig & 0x20) {
        if (obj->sel < 10) {
            fn_800D5234(0);
            obj->sel = 0xE;
        }
    } else if (lbl_80319DA0.repeat & 1) {
        v = obj->sel;
        fn_800D5234(0);
        v += 10;
        v %= 15;
        v /= 5;
        v %= 3;
        obj->sel = obj->sel % 5 + v * 5;
    } else if (lbl_80319DA0.repeat & 2) {
        v = obj->sel;
        fn_800D5234(0);
        v += 5;
        v /= 5;
        v %= 3;
        obj->sel = obj->sel % 5 + v * 5;
    } else if (lbl_80319DA0.repeat & 4) {
        if (obj->sel < 10) {
            fn_800D5234(0);
            Set(obj, obj->sel / 5, (u8)(obj->sel + 5) - 1);
        }
    } else if (lbl_80319DA0.repeat & 8) {
        if (obj->sel < 10) {
            fn_800D5234(0);
            Set(obj, obj->sel / 5, obj->sel + 1);
        }
    }
}
