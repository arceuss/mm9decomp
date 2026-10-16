#include "game/work_8038DC58.h"

typedef struct Unk8037C3D8 {
    /* 0x00 */ u8 pad0[0x5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 pad6[0x50 - 0x6];
} Unk8037C3D8;

typedef struct Unk800C6ED4Ctx {
    /* 0x00 */ u8 pad0[0x20];
} Unk800C6ED4Ctx;

extern Unk8037C3D8 lbl_8037C3D8;

void fn_800E689C(Unk800C6ED4Ctx* ctx, s32 arg1, s32 arg2);
void fn_800A70D0(void);

void fn_800C6ED4(void) {
    Unk800C6ED4Ctx ctx;
    Unk8038DC58* save;
    u8 mode;

    if ((lbl_8038DC58.unk0 == 2 || lbl_8038DC58.unk0 == 3) && lbl_8037C3D8.unk5 == 2) {
        save = &lbl_8038DC58;
        mode = save->unk3;
        if (save->unk120 != 0xFF) {
            if (mode == 0) {
                save->unkF4 = 0x2000;
                save->unkF8 = 0x800;
            } else {
                save->unkF4 = 0x2000;
                save->unkF8 = 0x6800;
            }
            fn_800E689C(&ctx, 0, 0);
            save->unk108.func(&save->unk108, &ctx);
        }
    }
    fn_800A70D0();
}
