#include "types.h"
typedef struct Unk8000BF80 { s32 unk0, unk4, unk8, unkC; } Unk8000BF80;
void fn_8000BF80(Unk8000BF80* p, s32 a, s32 b, s32 c, s32 d) {
    p->unk0 = a; p->unk4 = b; p->unk8 = c; p->unkC = d;
}
