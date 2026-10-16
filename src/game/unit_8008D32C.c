#include "types.h"

typedef struct Unk8008D32C {
    /* 0x000 */ u8 pad0[0x2];
    /* 0x002 */ u8 state;
    /* 0x003 */ u8 step;
    /* 0x004 */ u8 pad4[0xFFB - 0x4];
    /* 0xFFB */ u8 unkFFB;
} Unk8008D32C;

void fn_8008D32C(Unk8008D32C* work) {
    switch (work->step) {
    case 0:
        work->step++;
    case 1:
        work->unkFFB = 1;
        work->state = 6;
        work->step = 0;
        break;
    }
}
