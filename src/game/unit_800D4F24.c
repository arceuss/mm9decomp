#include "types.h"

typedef struct Unk8038DD8C {
    /* 0x000 */ u8 pad0[0x154];
    /* 0x154 */ u8 player[0x23C - 0x154];
    /* 0x23C */ u8 unk23C[0x268 - 0x23C];
    /* 0x268 */ u8 unk268[0x270 - 0x268];
    /* 0x270 */ u8 mutex[0x290 - 0x270];
    /* 0x290 */ u16 unk290;
} Unk8038DD8C;

extern Unk8038DD8C lbl_8038DD8C;
extern u8 lbl_8038DD80[];

void fn_8018D9D0(void* p);
void fn_80196938(void* p);
void fn_800D4FB8(void);
void fn_8019A280(void);
void fn_8019A2C8(void);
void fn_800D455C(void);
void fn_800D4568(void);
void fn_80181FE4(void* p, void* a, void* b, s32 c, s32 d);
void __register_global_object(void* obj, void* dtor, void* ref);

void fn_800D4F24(void) {
    Unk8038DD8C* const s = &lbl_8038DD8C;

    fn_8018D9D0(s);
    fn_80196938(s->player);
    fn_80181FE4(s->unk23C, fn_8019A280, fn_8019A2C8, 0x2C, 1);
    fn_80181FE4(s->unk268, fn_800D455C, fn_800D4568, 4, 2);
    __register_global_object(s, fn_800D4FB8, lbl_8038DD80);
}
