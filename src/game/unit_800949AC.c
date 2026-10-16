#include "types.h"
#include "game/sound.h"

typedef struct Unk949AC {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ u8 unk03;
    /* 0x04 */ s16 unk04;
} Unk949AC;

extern u8 lbl_803051D8[];
extern u8 lbl_80316D78[];
extern void* lbl_804EE984;

void fn_800D5234(s32);
void fn_800B5F90(void*, u16);
void fn_8008C07C(void*, u32);

void fn_800949AC(Unk949AC* p) {
    switch (p->unk03) {
    case 0:
        fn_800D5234(SE_WEAPON_MENU);
        {
            u8* q = *(u8**)(lbl_80316D78 + 0x3004);
            q[0xD4102B] = 4;
            q = *(u8**)(lbl_80316D78 + 0x3004);
            q[0xD4102D] = 2;
        }
        p->unk03++;
        /* fallthrough */
    case 1:
        if (*(u8*)(*(u8**)(lbl_80316D78 + 0x3004) + 0xD4102B) == 0) {
            p->unk03++;
        }
        break;
    case 2: {
        u8* q = lbl_803051D8;
        q[2] |= 0x20;
        p->unk04 = 0;
        p->unk03++;
        /* fallthrough */
    }
    case 3:
        if (p->unk04 == 4) {
            u8* q;
            lbl_803051D8[2] &= ~0x20;
            q = *(u8**)(lbl_80316D78 + 0x3004) + 0xD40000;
            lbl_803051D8[9] = q[0x101E];
            lbl_803051D8[0xB] = q[0x101F];
            lbl_803051D8[0xC] = q[0x1020];
            lbl_803051D8[0xA] = q[0x1021];
            lbl_803051D8[0xD] = q[0x1022];
            lbl_803051D8[0xE] = q[0x1023];
            fn_800B5F90(lbl_804EE984, *(u16*)(q + 0x1028));
            fn_8008C07C(p, 0xC00);
        } else {
            p->unk04++;
        }
        break;
    }
}
