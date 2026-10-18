#include "types.h"

typedef struct Unk800BEEFCParent {
    /* 0x000 */ u8 pad0[0xA];
    /* 0x00A */ u8 unkA;
    /* 0x00B */ u8 padB[0x11 - 0xB];
    /* 0x011 */ u8 unk11;
    /* 0x012 */ u8 pad12[0x50 - 0x12];
    /* 0x050 */ u32 unk50;
    /* 0x054 */ u8 pad54[0x60 - 0x54];
    /* 0x060 */ s32 x;
    /* 0x064 */ s32 y;
    /* 0x068 */ u8 pad68[0xA0 - 0x68];
    /* 0x0A0 */ u32 hit;
    /* 0x0A4 */ u8 padA4[0xB6 - 0xA4];
    /* 0x0B6 */ s16 unkB6;
    /* 0x0B8 */ u8 padB8[0x18C - 0xB8];
    /* 0x18C */ u16 unk18C;
} Unk800BEEFCParent;

typedef struct Unk800BEEFC {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 type;
    /* 0x15 */ u8 pad15[0x18 - 0x15];
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ Unk800BEEFCParent* parent;
    /* 0x38 */ u8 pad38[0x54 - 0x38];
    /* 0x54 */ struct {
        u32 hi : 21;
        u32 b10 : 1;
        u32 lo : 10;
    } unk54;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ s32 vx;
    /* 0x6C */ s32 vy;
    /* 0x70 */ u8 pad70[0x88 - 0x70];
    /* 0x88 */ u8 anim[0xA0 - 0x88];
    /* 0xA0 */ u32 hit;
    /* 0xA4 */ u8 padA4[0xCC - 0xA4];
    /* 0xCC */ u8 unkCC;
    /* 0xCD */ u8 timer;
    /* 0xCE */ u8 padCE;
    /* 0xCF */ u8 unkCF;
    /* 0xD0 */ u8 unkD0;
} Unk800BEEFC;

extern u32* lbl_8027F228[];
extern u8 lbl_804ECF4C[4];
extern void (*lbl_804ECF40[2])(Unk800BEEFC* obj);
extern u8 lbl_8027EFE0[];

void fn_800E9244(Unk800BEEFC* obj);
void fn_8009996C(void* anim, void* data);
void fn_800D5234(s32 se);

static inline void SetState(Unk800BEEFC* obj, u8 n) {
    obj->unk18 = lbl_8027F228[obj->kind][n];
    obj->unk10 = n;
    obj->unk11 = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

static inline void Kill(Unk800BEEFC* obj) {
    SetState(obj, 2);
    SetState(obj, 4);
    fn_800E9244(obj);
    obj->unkA &= ~1;
    lbl_804ECF40[lbl_804ECF4C[obj->type]](obj);
}

void fn_800BEEFC(Unk800BEEFC* obj) {
    Unk800BEEFCParent* p = obj->parent;
    u32 f;
    s32 sp;

    switch (obj->step) {
    case 0:
        obj->timer = 1;
        obj->step++;
    case 1:
        if ((p->hit & 0x200) || p->unkB6 == 0) {
            Kill(obj);
            return;
        }
        if (obj->hit & 0x1000) {
            Kill(obj);
            return;
        }
        obj->x = p->x;
        obj->y = p->y - 0xA00;
        obj->unkD0 = p->unk50 & 3;
        if (p->unkA & 1) {
            obj->unkCF = 1;
            fn_8009996C(obj->anim, lbl_8027EFE0);
        } else {
            obj->unkCF = 0;
            fn_8009996C(obj->anim, NULL);
        }
        if (obj->timer == 0) {
            if (((1 << p->unk11) & 0xF) && (p->unk18C & 0x40)) {
                obj->step++;
            }
        } else {
            obj->timer--;
        }
        break;
    case 2:
        obj->unkCF = 1;
        fn_8009996C(obj->anim, lbl_8027EFE0);
        obj->unkD0 = 2;
        obj->step++;
        obj->vx = ((((p->unkA >> 4) & 1) << 1) - 1) * 0x300;
        obj->vy = 0;
    case 3:
        if (obj->hit & 0x1000) {
            fn_800D5234(0x3E);
            sp = 0x300;
            obj->vy = -0x240;
            sp *= (obj->vx >> 31) * 2 + 1;
            obj->vx = -sp;
            f = ((obj->unkA >> 4) & 1) ^ 1;
            if (f) {
                obj->unkA |= 0x10;
            } else {
                obj->unkA &= 0xEF;
            }
            obj->unk54.b10 = f;
            fn_800E9244(obj);
        }
        obj->x += obj->vx;
        obj->y += obj->vy;
        break;
    }
    obj->unkCC += 4;
}
