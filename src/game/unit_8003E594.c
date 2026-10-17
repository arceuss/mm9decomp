#include "types.h"

typedef struct Unk8003E594Hdr {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ u32 unk8;
} Unk8003E594Hdr;

typedef struct Unk8003E594 {
    /* 0x000 */ u8 pad0[0x288];
    /* 0x288 */ Unk8003E594Hdr* unk288;
} Unk8003E594;

void fn_8000ECB8(s32 arg0, void* data, u8 tile, s32 arg3, s8 y);

void fn_8003E594(Unk8003E594* p, u32 value) {
    u8 sec;
    u32 t;
    u8 min;

    if (value != -1) {
        min = value / 60 / 60;
        fn_8000ECB8(0x38, (void*)((p->unk288->unk8 >> 1) + (u32)p->unk288), min / 10 + 0xF, 0x15, 4);
        fn_8000ECB8(0x38, (void*)((p->unk288->unk8 >> 1) + (u32)p->unk288), min % 10 + 0xF, 0x16, 4);
        sec = value / 60 % 60;
        fn_8000ECB8(0x38, (void*)((p->unk288->unk8 >> 1) + (u32)p->unk288), sec / 10 + 0xF, 0x18, 4);
        fn_8000ECB8(0x38, (void*)((p->unk288->unk8 >> 1) + (u32)p->unk288), sec % 10 + 0xF, 0x19, 4);
        t = value * 100;
        sec = t / 600 % 10;
        fn_8000ECB8(0x38, (void*)((p->unk288->unk8 >> 1) + (u32)p->unk288), sec + 0xF, 0x1b, 4);
        sec = t / 60 % 10;
        fn_8000ECB8(0x38, (void*)((p->unk288->unk8 >> 1) + (u32)p->unk288), sec + 0xF, 0x1c, 4);
    } else {
        fn_8000ECB8(0x38, (void*)((p->unk288->unk8 >> 1) + (u32)p->unk288), 0x1A, 0x15, 4);
        fn_8000ECB8(0x38, (void*)((p->unk288->unk8 >> 1) + (u32)p->unk288), 0x1A, 0x16, 4);
        fn_8000ECB8(0x38, (void*)((p->unk288->unk8 >> 1) + (u32)p->unk288), 0x1A, 0x18, 4);
        fn_8000ECB8(0x38, (void*)((p->unk288->unk8 >> 1) + (u32)p->unk288), 0x1A, 0x19, 4);
        fn_8000ECB8(0x38, (void*)((p->unk288->unk8 >> 1) + (u32)p->unk288), 0x1A, 0x1b, 4);
        fn_8000ECB8(0x38, (void*)((p->unk288->unk8 >> 1) + (u32)p->unk288), 0x1A, 0x1c, 4);
    }
}
