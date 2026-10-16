#include "types.h"

typedef struct UnkB1924 {
    /* 0x000 */ u8 pad000[0x1F8];
    /* 0x1F8 */ u8 unk1F8;
} UnkB1924;

void fn_800B1924(UnkB1924* obj) {
    obj->unk1F8 = 0;
}
