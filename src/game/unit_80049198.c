#include "types.h"

typedef struct Unk80049198 {
    u8 pad0[0xA];
    u8 unkA;
    u8 padB[5];
    u8 unk10;
    u8 unk11;
    u8 step;
    u8 unk13;
    u8 unk14;
    u8 pad15;
    u8 unk16;
    u8 unk17;
    u8 pad18[0x34-0x18];
    struct Unk80049198* unk34;
    struct Unk80049198* unk38;
    u8 pad3C[0x54-0x3C];
    u32 hi54:21;
    u32 face:1;
    u32 lo54:10;
    u8 pad58[8];
    s32 x;
    s32 y;
    s32 vx;
    s32 vy;
    s32 unk70;
    s32 unk74;
    u8 pad78[5];
    u8 unk7D;
    u8 pad7E[0x88-0x7E];
    u8 unk88[0xB6-0x88];
    u16 unkB6;
    u16 unkB8;
    u8 padBA[0xD0-0xBA];
    u8 unkD0;
} Unk80049198;

typedef struct Unk80304B90 {
    u8 pad0[0x21C];
    u8 cam[0x25C-0x21C];
    s32 unk25C;
} Unk80304B90;
extern Unk80304B90 lbl_80304B90;
extern u8 lbl_804ECA68[4];
extern u8 lbl_804ECA6C[4];
extern u8 lbl_804ECA70[8];
extern void* lbl_804ECA78[2];
extern void* lbl_804ECA80[2];
extern void* lbl_80265A68[];
void fn_800E946C(Unk80049198*, u8);
void fn_8009996C(void*, void*);
void fn_800E9750(Unk80049198*, u16);
void fn_800D5234(s32);
u32 fn_80080484(void*, s32*, s32);
void fn_80042D30(Unk80049198*);

static inline void Box(Unk80049198* obj) {
    fn_8009996C(obj->unk88, lbl_80265A68[obj->unk7D]);
}

void fn_80049198(Unk80049198* obj) {
    s32 bit;
    if (obj->unk14 == 1 && obj->unk34 && obj->unk34->unk10 >= 2) obj->unk34 = 0;
    switch (obj->step) {
    case 0:
        fn_800E946C(obj, lbl_804ECA68[obj->unk14]);
        fn_8009996C(obj->unk88, lbl_804ECA78[obj->unk14]);
        obj->vx = 0x300;
        obj->vx *= ((obj->unkA >> 3) & 2) - 1;
        obj->step++;
    case 1:
        obj->x += obj->vx;
        if (__abs(obj->x - obj->unk70) > 0x4000) obj->step++;
        fn_800E9750(obj, 0xFFFF);
        break;
    case 2:
        fn_800E946C(obj, lbl_804ECA70[obj->unk14]);
        fn_8009996C(obj->unk88, lbl_804ECA80[obj->unk14]);
        obj->unk16 = 8;
        obj->unk17 = 1;
        obj->step++;
    case 3:
        fn_800E9750(obj, 0xFFFF);
        if (obj->unk16 == 0) {
            if (obj->unk17 == 0) obj->step++;
            else {
                fn_800E946C(obj, lbl_804ECA6C[obj->unk14]);
                obj->unk16 = 8;
                obj->unk17--;
            }
        } else obj->unk16--;
        break;
    case 4:
        obj->vx = (((obj->unkA >> 3) & 2) - 1) * 0x380;
        obj->vy = (((!obj->unk14) == 1) * 2 - 1) * 0x380;
        obj->step++;
    case 5:
        obj->x += obj->vx;
        obj->y += obj->vy;
        if (obj->unk14 == 0) {
            if (obj->y > obj->unk74) {
                if (obj->unk38->unkD0 == 0) {
                    fn_800E946C(obj, 4);
                    Box(obj);
                    obj->unkB8 = 3;
                    obj->unkB6 = 3;
                    obj->y = obj->unk74;
                    fn_800D5234(0x40);
                    obj->step++;
                } else if (fn_80080484(lbl_80304B90.cam, &obj->x, 1) > 0x1400) {
                    fn_80042D30(obj);
                    return;
                }
            }
        } else if (obj->y < obj->unk74) {
            if (obj->unk34) {
                obj->y = obj->unk74;
                fn_80042D30(obj);
                return;
            } else if (fn_80080484(lbl_80304B90.cam, &obj->x, 1) > 0x1400) {
                fn_80042D30(obj);
                return;
            }
        }
        fn_800E9750(obj, 0xFFFF);
        break;
    case 6:
        obj->unk16 = 0x10;
        obj->step++;
    case 7:
        fn_800E9750(obj, 0xFFFF);
        Box(obj);
        if (--obj->unk16 == 0) obj->step++;
        break;
    case 8:
        obj->vx = (((obj->unkA >> 3) & 2) - 1) * 0x500;
        obj->step++;
    case 9:
        fn_800E9750(obj, 0xFFFF);
        Box(obj);
        obj->x += obj->vx;
        if (fn_80080484(lbl_80304B90.cam, &obj->x, 1) > 0x1400) obj->step++;
        break;
    case 10:
        fn_800E946C(obj, 0xC);
        obj->vx = -obj->vx;
        bit = obj->vx > 0;
        if (bit) obj->unkA |= 0x10;
        else obj->unkA &= 0xEF;
        obj->face = bit;
        obj->step++;
    case 11:
        fn_800E9750(obj, 0xFFFF);
        Box(obj);
        obj->x += obj->vx;
        if (obj->vx < 0) {
            if (obj->x < lbl_80304B90.unk25C - 0x9400) fn_80042D30(obj);
        } else {
            if (obj->x > lbl_80304B90.unk25C + 0x93FF) fn_80042D30(obj);
        }
        break;
    }
}
