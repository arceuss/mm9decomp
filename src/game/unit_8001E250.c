#include "types.h"
#include "game/sound.h"

typedef struct Unk8001E250 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 padA[0x10 - 0xA];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14[0x18 - 0x14];
    /* 0x18 */ void* unk18;
    /* 0x1C */ u8 pad1C[0x84 - 0x1C];
    /* 0x84 */ s32 timer;
    /* 0x88 */ u8 pad88[0xA0 - 0x88];
    /* 0xA0 */ u32 hitFlags;
    /* 0xA4 */ u8 padA4[0xB6 - 0xA4];
    /* 0xB6 */ s16 hp;
    /* 0xB8 */ u8 padB8[0xD8 - 0xB8];
    /* 0xD8 */ struct Unk8001E250* sats[4];
    /* 0xE8 */ u8 padE8[0xED - 0xE8];
    /* 0xED */ u8 unkED;
    /* 0xEE */ s16 unkEE;
} Unk8001E250;

extern void** lbl_802638A0[];
extern void (*lbl_804EC7C8[2])(Unk8001E250* obj);
extern void (*lbl_80263070[])(Unk8001E250* obj);
extern void (*lbl_80263080[])(Unk8001E250* obj);

void fn_800C75D0(void);
Unk8001E250* fn_80067B90(Unk8001E250* parent, s32 arg1, s32 idx, s32 arg3, u16 angle, s32 arg5);
void fn_800D5234(s32 id);

static inline BOOL Hit(Unk8001E250* obj) {
    if ((obj->hitFlags & 0x200) || obj->hp == 0) {
        obj->unk18 = lbl_802638A0[obj->kind][2];
        obj->unk10 = 2;
        obj->unk13 = 0;
        obj->state = 0;
        obj->step = 0;
        return TRUE;
    }
    return FALSE;
}

void fn_8001E250(Unk8001E250* obj) {
    Unk8001E250* a;
    Unk8001E250* b;
    Unk8001E250* c;
    Unk8001E250* d;

    if (obj->state != 0) {
        fn_800C75D0();
        if (Hit(obj)) {
            lbl_804EC7C8[obj->state](obj);
            return;
        }
        a = obj->sats[0];
        b = obj->sats[1];
        c = obj->sats[2];
        d = obj->sats[3];
        if (a->unk10 >= 2 && b->unk10 >= 2 && c->unk10 >= 2 && d->unk10 >= 2) {
            if (obj->timer == 0) {
                obj->sats[0] = fn_80067B90(obj, 0, 0, 0x30, 0xA000, 0);
                obj->sats[1] = fn_80067B90(obj, 0, 1, 0x20, 0xE000, 0x20);
                obj->sats[2] = fn_80067B90(obj, 0, 2, 0x10, 0x2000, 0x40);
                obj->sats[3] = fn_80067B90(obj, 0, 3, 0, 0x6000, 0x60);
                fn_800D5234(SE_EM_J_SATELLITE);
                obj->timer = 300;
                obj->unkED = 10;
            } else if (obj->state != 3) {
                obj->timer--;
            }
        }
    }
    if (obj->unkED != 0) {
        obj->unkED--;
    }
    lbl_80263070[obj->state](obj);
    lbl_80263080[obj->state](obj);
    obj->unkEE = 0;
}
