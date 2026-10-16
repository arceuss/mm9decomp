#include "types.h"

typedef struct Unk80044188 {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 state;
} Unk80044188;

typedef struct Unk803051D8 {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x38 - 0x3];
} Unk803051D8;

extern u8 lbl_80265268[];
extern Unk803051D8 lbl_803051D8;

void fn_80042D30(Unk80044188* obj);
u8 fn_80044A2C(Unk80044188* obj);
void fn_800C7C24(s32 arg0, s32 arg1, s32 arg2);

void fn_80044188(Unk80044188* obj) {
    if (lbl_803051D8.unk2 & 0x20) {
        fn_80042D30(obj);
    } else if (fn_80044A2C(obj)) {
        fn_800C7C24(6, 1, 0);
        ((void (**)(Unk80044188*))(lbl_80265268 + 0x38))[obj->state](obj);
    } else {
        ((void (**)(Unk80044188*))(lbl_80265268 + 0x18))[obj->state](obj);
        ((void (**)(Unk80044188*))(lbl_80265268 + 0x28))[obj->state](obj);
    }
}
