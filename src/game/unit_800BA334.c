#include "types.h"

typedef struct Unk800BA334 {
    /* 0x00 */ u8 pad0[0x09];
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 padA[0x1A];
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u8 pad26[0x57];
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 unk7E;
    /* 0x7F */ u8 unk7F;
    /* 0x80 */ u8 pad80[0x78];
    /* 0xF8 */ u32 unkF8;
    /* 0xFC */ u8 unkFC;
} Unk800BA334;

extern u8* lbl_8027EB54[];
extern u8* lbl_8027EB60[];

void fn_800E9424(Unk800BA334* obj, u16 v);
void fn_800E946C(Unk800BA334* obj, u8 v);
void fn_800E947C(Unk800BA334* obj, u8 a1, s8 a2, s8 a3);
void fn_800B68FC(Unk800BA334* obj, u32 v, s32 a2);

u32 fn_800BA334(Unk800BA334* obj, u32 a1) {
    u32 t = obj->unkFC;
    u32 v;
    u16 w;
    s8 b;
    u8 a;

    if (a1 & 1) {
        t = 8;
    }
    if (t != obj->unkFC) {
        obj->unkFC = t;
        v = ((u32*)lbl_8027EB60[obj->unk9])[t];
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
    return t;
}
