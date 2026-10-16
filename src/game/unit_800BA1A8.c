#include "types.h"

typedef struct Unk800BA1A8Tbl {
    /* 0x00 */ u8 pad0[0x60];
    /* 0x60 */ u32 unk60;
} Unk800BA1A8Tbl;

typedef struct Unk800BA1A8 {
    /* 0x00 */ u8 pad0[0x09];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 padA[0x1A];
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u8 pad26[0x3E];
    /* 0x64 */ u32 unk64;
    /* 0x68 */ u8 pad68[0x15];
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 unk7E;
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[0x78];
    /* 0xF8 */ u32 unkF8;
    /* 0xFC */ u8 unkFC;
    /* 0xFD */ u8 padFD[0x07];
    /* 0x104 */ u32 unk104;
    /* 0x108 */ u8 unk108;
    /* 0x109 */ u8 pad109[0x0E];
    /* 0x117 */ u8 unk117;
} Unk800BA1A8;

extern u8* lbl_8027EB54[];
extern Unk800BA1A8Tbl* lbl_8027EB60[];

void fn_800E9424(Unk800BA1A8* obj, u16 v);
void fn_800E946C(Unk800BA1A8* obj, u8 v);
void fn_800E947C(Unk800BA1A8* obj, u8 a1, s8 a2, s8 a3);
void fn_800B68FC(Unk800BA1A8* obj, u32 v, s32 a2);

u8 fn_800BA1A8(Unk800BA1A8* obj, u32 a1, u32 a2) {
    s32 t = obj->unk108;
    u8 ret = obj->unkFC;
    u32 v;
    u16 w;
    s8 b;
    u8 a;

    if (t != 0xFF && (obj->unk117 & 2) == 0) {
        if (t > 0) {
            t--;
        }
        if (t == 0) {
            if (a1 != a2) {
                obj->unk104 |= 2;
                obj->unk64 -= 0x100;
                t = 4;
            }
        }
        obj->unk108 = t;
    }
    if (obj->unkFC == 8 && (u8)(obj->unk7F + 0xFE) <= 2) {
        obj->unkFC = 0x18;
        v = lbl_8027EB60[obj->unk9]->unk60;
        if ((v >> 24 & 0xF) != 0 && (v >> 24 & 0xF) == (obj->unkF8 >> 24 & 0xF)) {
            obj->unkF8 = v;
            b = (s8)obj->unk7E;
            w = ((u16*)lbl_8027EB54[obj->unk9])[(v >> 8) & 0xF];
            a = obj->unk7D;
            if (w != obj->unk24) {
                fn_800E9424(obj, w);
            }
            fn_800E947C(obj, v, a, b);
            fn_800B68FC(obj, v, a);
        } else {
            obj->unkF8 = v;
            w = ((u16*)lbl_8027EB54[obj->unk9])[(v >> 8) & 0xF];
            if (w != obj->unk24) {
                fn_800E9424(obj, w);
            }
            fn_800E946C(obj, v);
            fn_800B68FC(obj, v, 0);
        }
    }
    return ret;
}
