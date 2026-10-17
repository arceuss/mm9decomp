#include "types.h"

typedef struct Unk8009F1A8Pos {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Unk8009F1A8Pos;

typedef struct Unk8009F1A8 {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ u16 unkC;
    /* 0x0E */ u8 padE[0x14 - 0xE];
    /* 0x14 */ u8 unk14[0x2C - 0x14];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s32 unk40;
    /* 0x44 */ s32 unk44;
    /* 0x48 */ s32 unk48;
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 unk54;
    /* 0x58 */ s32 unk58;
    /* 0x5C */ s32 unk5C;
} Unk8009F1A8;

typedef struct Unk8043CA80 {
    /* 0x000 */ u8 pad0[0x258];
    /* 0x258 */ u8* unk258;
} Unk8043CA80;

typedef struct Unk80301280 {
    /* 0x00 */ u8 pad0[0x40];
    /* 0x40 */ u8* unk40;
} Unk80301280;

extern u8 lbl_8031BF70[];
extern Unk8043CA80 lbl_8043CA80;
extern Unk80301280 lbl_80301280;

u32 fn_8000EECC(s32 arg0);
void fn_800C944C(void* layer, Unk8009F1A8Pos* pos, u8* dst);
void fn_800C8B7C(void* layer, Unk8009F1A8Pos* pos, u8* dst);
void fn_800C9704(void* layer, Unk8009F1A8Pos* pos, u8* dst, u8* map);
void fn_800C99EC(void* layer, Unk8009F1A8Pos* pos, u8* dst, u8* map);
void fn_800C9EA8(void* layer, u8* arg1);

void fn_8009F1A8(Unk8009F1A8* l) {
    Unk8009F1A8Pos p;
    u32 dx;
    u32 dy;
    void* sub = l->unk14;

    p.x = (l->unk4C << 8) + l->unk34 * l->unk44;
    p.y = (l->unk50 << 8) + l->unk38 * l->unk48;
    dx = p.x - ((l->unk54 << 8) + l->unk3C * l->unk44) + 0xF00;
    dy = p.y - ((l->unk58 << 8) + l->unk40 * l->unk48) + 0xF00;
    if (l->unk44 != 0) {
        p.x += l->unk2C;
    }
    if (l->unk48 != 0) {
        p.y += l->unk30;
    }
    if (*(u16*)(lbl_8031BF70 + 0x4AEAE) != 0) {
        dx = 0x2000;
    }
    dx >>= 8;
    dy >>= 8;
    p.x >>= 8;
    p.y >>= 8;
    if (l->unkC != 0) {
        if (dx > 0x1E || dy > 0x1E) {
            fn_800C944C(sub, &p, lbl_8043CA80.unk258 + fn_8000EECC(l->unk5C));
        } else {
            fn_800C8B7C(sub, &p, lbl_8043CA80.unk258 + fn_8000EECC(l->unk5C));
        }
    } else {
        if (dx > 0x1E || dy > 0x1E || *(u16*)(lbl_8031BF70 + 0x4AEAC) != 0) {
            fn_800C9704(sub, &p, lbl_8031BF70 + 0x4AED0, lbl_8031BF70 + 0x8A4);
        } else {
            fn_800C99EC(sub, &p, lbl_8031BF70 + 0x4AED0, lbl_8031BF70 + 0x8A4);
        }
        *(u16*)(lbl_8031BF70 + 0x4AEAC) = 0;
    }
    fn_800C9EA8(sub, &lbl_80301280.unk40[(l->unk5C >> 4) * 4 + 0x10]);
}
