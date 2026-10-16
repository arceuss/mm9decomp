#include "types.h"

typedef struct Unk800DA244 {
    /* 0x00 */ u8 pad0[0x8F];
    /* 0x8F */ u8 unk8F;
} Unk800DA244;

void fn_800DA258(Unk800DA244* obj);
void fn_800DA460(Unk800DA244* obj);

void fn_800DA244(Unk800DA244* obj) {
    if (obj->unk8F == 0) {
        fn_800DA258(obj);
    } else {
        fn_800DA460(obj);
    }
}
