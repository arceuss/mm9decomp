#include "types.h"
typedef struct Unk800A67EC {
    /* 0x00 */ u8 pad00[0x41C];
    /* 0x41C */ u8* unk41C;
    /* 0x420 */ u8 unk420;
} Unk800A67EC;
extern Unk800A67EC lbl_8037BF30;
extern void fn_8004024C(s32);
extern void fn_8003FE8C(s32, void*);
void fn_800A67EC(u32 index) {
    u8* text;
    u8* data = lbl_8037BF30.unk41C;
    if (data) {
        u8* table = data + (*(u32*)(data + lbl_8037BF30.unk420 * 4 + 4) >> 1);
        if (index < *(u32*)table) {
            text = table + *(u32*)(table + ((index + 1) << 2));
            goto dispatch;
        }
    }
    text = 0;
dispatch:
    if (text) { fn_8004024C(0); fn_8003FE8C(0, text); }
}
