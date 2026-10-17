#include "types.h"

typedef struct Unk3107CItem {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ u16 unk20;
    /* 0x22 */ s16 unk22;
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u16 unk26;
} Unk3107CItem;

typedef struct Unk3107C {
    /* 0x000 */ u8 pad0[0x280];
    /* 0x280 */ Unk3107CItem* unk280;
    /* 0x284 */ u8 pad284[0x28C - 0x284];
    /* 0x28C */ u8 unk28C;
} Unk3107C;

typedef struct Unk3107CDst {
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u16 unk2;
    /* 0x4 */ u8 pad4[4];
    /* 0x8 */ s32 unk8;
} Unk3107CDst;

extern u32 lbl_804EE6D8;
extern char lbl_802642E0[];

void* fn_800AAA88(const char* input);
void fn_80150D20(void);
void* fn_80150E34(void* a, s32 b);
void fn_800D5CD0(Unk3107CItem* item, s16 width, s16 height);
void fn_800D5D08(s32 a, s32 b, s32 c, u16 d, u16 e, s32 f, s32 g);
void fn_800D5B90(Unk3107CItem* item, u8 value);

void fn_8003107C(Unk3107C* obj, s32 arg) {
    Unk3107CItem* item = obj->unk280;
    void* p;
    Unk3107CDst* d;

    p = fn_800AAA88(lbl_802642E0);
    if (!(lbl_804EE6D8 & 1)) {
        fn_80150D20();
        lbl_804EE6D8 |= 1;
    }
    p = fn_80150E34(p, 0);
    if (arg != 0) {
        fn_800D5CD0(item, 0, 0);
    } else {
        fn_800D5CD0(item, 0, 0);
        obj->unk280->unk24 = 0x258;
        obj->unk280->unk26 = 0x141;
    }
    d = *(Unk3107CDst**)p;
    fn_800D5D08((s32)item, d->unk8, 1, d->unk2, d->unk0, 1, 1);
    item->unk20 = 0;
    item->unk22 = -0x20;
    obj->unk28C = 0;
    fn_800D5B90(obj->unk280, 0);
}
