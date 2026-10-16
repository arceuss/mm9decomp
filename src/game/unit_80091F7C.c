#include "types.h"

typedef struct Unk91F7C {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u8 unk02;
    /* 0x03 */ u8 unk03;
} Unk91F7C;

extern u8 lbl_8038E738[];

void fn_800E5910(s32);

void fn_80091F7C(Unk91F7C* p) {
    switch (p->unk03) {
    case 0:
        fn_800E5910(0x800);
        p->unk03++;
    case 1:
        if (*(u16*)(lbl_8038E738 + 0xA) == 0) {
            p->unk02 = 2;
            p->unk03 = 0;
        }
        break;
    }
}
