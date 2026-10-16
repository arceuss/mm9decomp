#include "types.h"

typedef struct Unk8039B240 {
    /* 0x00 */ u8 pad0[0x80];
} Unk8039B240;

typedef struct Unk8039B2C0 {
    /* 0x00000 */ u8 pad0[0x1CD8A];
} Unk8039B2C0;

extern Unk8039B240 lbl_8039B240;
extern Unk8039B2C0 lbl_8039B2C0;

void fn_800A5678(void);
void fn_800E8618(void);
void fn_800E7D3C(void);
void fn_800E6AC8(void);
void fn_800E7968(void);
void fn_800D5CD0(Unk8039B240* view, s16 width, s16 height);
void fn_800D5D08(Unk8039B240* view, Unk8039B2C0* buf, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

void fn_800E7244(void) {
    fn_800A5678();
    fn_800E8618();
    fn_800E7D3C();
    fn_800E6AC8();
    fn_800E7968();
    fn_800D5CD0(&lbl_8039B240, 640, 480);
    fn_800D5D08(&lbl_8039B240, &lbl_8039B2C0, 0, 256, 240, 0, 0);
}
