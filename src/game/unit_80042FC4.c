#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk80042FC4Obj {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ char unk8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 padA[0x60 - 0xA];
    /* 0x60 */ Vec2i pos;
    /* 0x68 */ u8 pad68[0xA0 - 0x68];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u8 padA4[0xC8 - 0xA4];
    /* 0xC8 */ Vec2i unkC8;
} Unk80042FC4Obj;

typedef struct Unk80042FC4 {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ struct Unk80042FC4* other;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ u32 flags;
    /* 0x18 */ u8 pad18[0x23 - 0x18];
    /* 0x23 */ u8 unk23_hi : 4;
    /* 0x23 */ u8 type : 4;
    /* 0x24 */ u8 pad24[0x28 - 0x24];
    /* 0x28 */ Unk80042FC4Obj* obj;
} Unk80042FC4;

void fn_800B5ECC(Unk80042FC4Obj* obj, Vec2i* pos);
void fn_800B5F38(Unk80042FC4Obj* obj, s32 arg1);
void fn_800B5F10(Unk80042FC4Obj* obj, Vec2i* pos);
void fn_800B5F68(Unk80042FC4Obj* obj, s32 arg1);

void fn_80042FC4(Unk80042FC4* hit) {
    Unk80042FC4Obj* self = hit->obj;
    Unk80042FC4Obj* other = hit->other->obj;
    Vec2i pos;

    if (hit->flags & 1) {
        if (hit->type == 3) {
            self->unkC8 = other->pos;
        }
        if (hit->type == 8) {
            pos.x = self->pos.x;
            pos.y = self->pos.y - 0x800;
            if (!(hit->flags & 8)) {
                fn_800B5ECC(other, &pos);
            }
        }
        if (hit->type == 2 && (self->unkA0 & 0x200)) {
            fn_800B5F38(other, 0);
        }
    }
    if (hit->flags & 8) {
        if (other->unk8 == 3 && other->unk9 == 0) {
            pos.x = self->pos.x;
            pos.y = self->pos.y - 0x800;
            fn_800B5F10(other, &pos);
        }
        fn_800B5F68(other, 0);
    }
}
