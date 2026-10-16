#include "types.h"

typedef struct UnkB730C {
    /* 0x000 */ u32 unk000;
    /* 0x004 */ u32 unk004;
} UnkB730C;

void fn_800B730C(u8* src, u8* dst) {
    *(UnkB730C*)(dst + 0x00) = *(UnkB730C*)(src + 0x14C);
    *(UnkB730C*)(dst + 0x08) = *(UnkB730C*)(src + 0x154);
    *(UnkB730C*)(dst + 0x10) = *(UnkB730C*)(src + 0x15C);
    *(UnkB730C*)(dst + 0x18) = *(UnkB730C*)(src + 0x164);
    *(UnkB730C*)(dst + 0x20) = *(UnkB730C*)(src + 0x16C);
    *(UnkB730C*)(dst + 0x28) = *(UnkB730C*)(src + 0x174);
    *(UnkB730C*)(dst + 0x30) = *(UnkB730C*)(src + 0x17C);
    *(u32*)(dst + 0x38) = *(u32*)(src + 0x184);
}
