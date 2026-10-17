#include "types.h"

typedef struct Unk8006AB84 {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 pad18[0x34 - 0x18];
    /* 0x34 */ struct Unk8006AB84* unk34;
    /* 0x38 */ struct Unk8006AB84* unk38;
    /* 0x3C */ u8 pad3C[0x60 - 0x3C];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x7C - 0x68];
    /* 0x7C */ u8 unk7C;
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 unk7E;
    /* 0x7F */ u8 pad7F;
    /* 0x80 */ u8 pad80[0x88 - 0x80];
    /* 0x88 */ u8 unk88[1];
    /* 0x89 */ u8 pad89[0xA0 - 0x89];
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u8 padA4[0xC8 - 0xA4];
    /* 0xC8 */ u8 unkC8;
    /* 0xC9 */ u8 padC9[0xCC - 0xC9];
    /* 0xCC */ u32 unkCC;
    /* 0xD0 */ u32 unkD0;
} Unk8006AB84;

extern u8 lbl_80268128[];
extern Unk8006AB84* lbl_804EE738;

void fn_800E946C(Unk8006AB84* obj, u8 arg1);
void fn_800E9750(Unk8006AB84* obj, u16 arg1);
void fn_800E9244(Unk8006AB84* obj);
void fn_800E947C(Unk8006AB84* obj, u8 arg1, s8 arg2, s8 arg3);
void fn_8009996C(void* handle, void* table);
void fn_800D5234(u32 id);
void fn_80042DA0(Unk8006AB84* obj, s32 arg1);
Unk8006AB84* fn_800E8C44(Unk8006AB84* list);

void fn_8006AB84(Unk8006AB84* obj) {
    u8* const table = lbl_80268128;
    Unk8006AB84* parent = obj->unk34;
    Unk8006AB84* p = obj->unk38;

    if (p != NULL && p->unk10 >= 2) {
        obj->unk38 = NULL;
    }
    if (obj->unkA0 & 0x200) {
        fn_800E946C(obj, 0);
        fn_800E9244(obj);
    }
    if (parent->unk11 == 2) {
        fn_800E946C(obj, 3);
        fn_800E9750(obj, 0xFFFF);
        obj->unk11 = 4;
        obj->unk12 = 0;
        return;
    }
    switch (obj->unk12) {
    case 0:
        obj->unk12 = obj->unk12 + 1;
    case 1:
        if (parent->unk7C == 0) {
            if (obj->unk7C != 0) {
                fn_800E946C(obj, 0);
                fn_8009996C(obj->unk88, table + 0x68);
            }
        } else if (obj->unk7C != 2) {
            fn_800E947C(obj, 2, parent->unk7D, parent->unk7E);
            fn_8009996C(obj->unk88, table + 0x68);
        }
        obj->unk60 = parent->unk60;
        obj->unk64 = parent->unk64 + 0xA00;
        if (parent->unk11 == 1 && parent->unk12 >= 2 && p == NULL) {
            obj->unk17 = 2;
            obj->unk12 = obj->unk12 + 1;
        }
        break;
    case 2:
        fn_800E946C(obj, 1);
        fn_8009996C(obj->unk88, table + 0x98);
        obj->unk16 = 0x10;
        obj->unk13 = 0;
        obj->unk12 = obj->unk12 + 1;
    case 3:
        obj->unk60 = parent->unk60;
        obj->unk64 = parent->unk64 + 0xA00;
        if (obj->unk7D == 1) {
            if (obj->unk13 == 0) {
                s32 x;
                s32 y;

                fn_8009996C(obj->unk88, table + 0xC8);
                x = obj->unk60 - 0x3600;
                y = obj->unk64 - 0x4000;
                fn_800D5234(0x3F);
                p = fn_800E8C44(lbl_804EE738);
                if (p != NULL) {
                    fn_80042DA0(p, 0x28);
                    p->unk34 = obj;
                    p->unk60 = x;
                    p->unk64 = y;
                    p->unk14 = 2;
                    p->unkC8 = 0;
                    p->unkCC = 0;
                    p->unkD0 = 0;
                }
                obj->unk38 = p;
                obj->unk13 = obj->unk13 + 1;
            }
            if (obj->unk16 == 0) {
                if (obj->unk7C != 2) {
                    obj->unk12 = 0;
                }
            } else {
                obj->unk16 = obj->unk16 - 1;
            }
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
