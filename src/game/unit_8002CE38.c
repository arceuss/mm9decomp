#include "types.h"

typedef void (*UnkFn2CE38)(void*);

extern UnkFn2CE38 lbl_80263FA8[];
extern u32 lbl_804EE948;

extern void fn_800E6A78(void* p);
extern void fn_800E8D30(u32 a, s32 b);
extern void fn_800E8FC4(u32 a, void* b);
extern void fn_800E69E8(void* p);

void fn_8002CE38(u8* o) {
    fn_800E6A78(o + 0x48);
    lbl_80263FA8[o[5]](o);
    fn_800E8D30(lbl_804EE948, 0x100);
    fn_800E8FC4(lbl_804EE948, o + 0x48);
    fn_800E69E8(o + 0x48);
}
