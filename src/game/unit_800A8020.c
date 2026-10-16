#include "types.h"
typedef struct Unk800A8020Work { /* 0x00 */ u32 unk00; /* 0x04 */ void* unk04[2048]; } Unk800A8020Work;
extern Unk800A8020Work lbl_80383E70;
extern u8 lbl_8037CC40[];
extern s32 fn_800A9524(void*, void*, u32, s32, s32);
extern void fn_800AA0E4(void*, s32, s32, s32, s32, s32, s32, s32);
s32 fn_800A8020(u32 id, u32 source, s32 frame, s32 a, s32 b) {
    s32 result = fn_800A9524(lbl_8037CC40 + 0x1008, lbl_80383E70.unk04[id], id, frame, 0);
    *(u8*)(lbl_8037CC40 + (u16)result + 0x1E98) = *(u8*)(lbl_8037CC40 + source + 0x1E98);
    fn_800AA0E4(lbl_8037CC40 + 0x1008, (u16)result, frame, 0, a, b, 0, 1);
    return result;
}
