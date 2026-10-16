#include "types.h"

typedef struct UnkB3AB8 {
    /* 0x000 */ u8 pad000[0x68];
    /* 0x068 */ u32 unk68;
    /* 0x06C */ u32 unk6C;
    /* 0x070 */ u8 pad070[0xD8 - 0x70];
    /* 0x0D8 */ u16 unkD8;
    /* 0x0DA */ u16 unkDA;
    /* 0x0DC */ u16 unkDC;
    /* 0x0DE */ u16 unkDE;
    /* 0x0E0 */ u8 pad0E0[0xE4 - 0xE0];
    /* 0x0E4 */ u16 unkE4;
    /* 0x0E6 */ u16 unkE6;
    /* 0x0E8 */ u32 unkE8;
    /* 0x0EC */ u8 pad0EC[0x104 - 0xEC];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 unk108;
    /* 0x109 */ u8 pad109[0x116 - 0x109];
    /* 0x116 */ u8 unk116;
    /* 0x117 */ u8 pad117[0x124 - 0x117];
    /* 0x124 */ u32 unk124;
    /* 0x128 */ u32 unk128;
    /* 0x12C */ u8 pad12C[0x140 - 0x12C];
    /* 0x140 */ u32 unk140;
    /* 0x144 */ u32 unk144;
} UnkB3AB8;

typedef struct B3AB8Flags {
    /* 0x104 */ u32 f00 : 4;
    /* 0x104 */ u32 f04 : 7;
    /* 0x104 */ u32 f11 : 8;
    /* 0x104 */ u32 f19 : 13;
} B3AB8Flags;
void fn_800B9D84(void*);

void fn_800B3AB8(UnkB3AB8* obj) {
    fn_800B9D84(obj);
    obj->unkE4 = 0;
    ((B3AB8Flags*)((u8*)obj + 0x104))->f00 = 0;
    ((B3AB8Flags*)((u8*)obj + 0x104))->f11 = 0;
    obj->unkE6 = 0;
    obj->unkE8 = 0;
    obj->unk116 &= 1;
    obj->unk140 = 0;
    obj->unk144 = 0;
    obj->unk108 = 0;
    obj->unk124 = 0;
    obj->unk128 = 0;
    obj->unk68 = 0;
    obj->unk6C = 0;
    obj->unkD8 = 0;
    obj->unkDA = 0;
    obj->unkDC = 0;
    obj->unkDE = 0;
}
