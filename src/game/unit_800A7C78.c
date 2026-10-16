#include "types.h"

typedef struct Unk8037CC40 {
    /* 0x0000 */ u8 pad0[0x1008];
    /* 0x1008 */ u8 unk1008[0x1C18 - 0x1008];
    /* 0x1C18 */ u8 unk1C18[0x400];
} Unk8037CC40;

typedef struct Unk80383E70 {
    /* 0x0000 */ u32 unk0;
    /* 0x0004 */ void* unk4[0x200];
    /* 0x0804 */ u8 pad804[0x7488 - 0x804];
} Unk80383E70;

extern Unk8037CC40 lbl_8037CC40;
extern Unk80383E70 lbl_80383E70;

void fn_800AA6D8(s32 kind, u16* ids, s32 count);
void fn_800AA9A4(void);
void fn_800A9090(void* arg0, void* arg1, u16 arg2, u16 arg3, s32 arg4, s32 arg5, s32 arg6);
void fn_800AA0E4(void* arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);

static inline void Start(u16 id) {
    fn_800AA0E4(lbl_8037CC40.unk1008, id, 0, 0, 0, 0, 1, 0);
}

void fn_800A7C78(u32 arg0) {
    u32 id = arg0 & 0x3FF;
    u16 ids;

    ids = id;
    if (lbl_8037CC40.unk1C18[id] == 0xFF) {
        fn_800AA6D8(1, &ids, 1);
        fn_800AA6D8(2, &ids, 1);
        fn_800AA9A4();
        if (arg0 & 0x4000) {
            fn_800A9090(lbl_8037CC40.unk1008, lbl_80383E70.unk4[(u16)id], id, id, 0, 1, 0);
        } else {
            fn_800A9090(lbl_8037CC40.unk1008, lbl_80383E70.unk4[(u16)id], id, id, 0, 1, 1);
        }
        Start(id);
    }
}
