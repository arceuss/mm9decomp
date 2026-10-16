#include "game/obj.h"

Obj* fn_80063FA0(s32 arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4, u8 arg5) {
    Obj* obj = fn_800E8C44(lbl_804EE738);

    if (obj != NULL) {
        fn_80042DA0(obj, 0x21);
        obj->unk34 = arg0;
        obj->unk60 = arg1;
        obj->unk64 = arg2;
        obj->unk14 = arg3;
        obj->unkC8 = arg4;
        obj->unkCC = arg5;
    }
    return obj;
}
