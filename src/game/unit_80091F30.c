#include "types.h"

typedef struct Unk91F30 {
    /* 0x0000 */ u8 pad0[1];
    /* 0x0001 */ u8 unk01;
    /* 0x0002 */ u8 unk02;
    /* 0x0003 */ u8 unk03;
    /* 0x0004 */ u8 pad04[0x1011 - 0x4];
    /* 0x1011 */ u8 unk1011;
    /* 0x1012 */ u8 pad1012[1];
    /* 0x1013 */ u8 unk1013;
} Unk91F30;

void fn_80091F30(Unk91F30* p) {
    switch (p->unk03) {
    case 0:
        p->unk1011 = 2;
        p->unk1013 = 2;
        p->unk03 = p->unk03 + 1;
    case 1:
        if (p->unk1011 == 0) {
            p->unk02 = 1;
            p->unk03 = 0;
        }
        break;
    }
}
