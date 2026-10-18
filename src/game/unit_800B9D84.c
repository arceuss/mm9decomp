#include "types.h"

typedef struct Unk800B9D84 {
    /* 0x000 */ u8 pad000[0x9];
    /* 0x009 */ u8 unk009;
    /* 0x00A */ u8 unk00A;
    /* 0x00B */ u8 pad00B[0x24 - 0xB];
    /* 0x024 */ u16 unk024;
    /* 0x026 */ u8 pad026[0x2C - 0x26];
    /* 0x02C */ u8 unk02C;
    /* 0x02D */ u8 unk02D;
    /* 0x02E */ u8 unk02E;
    /* 0x02F */ u8 pad02F[0x50 - 0x2F];
    /* 0x050 */ u32 unk050h : 30;
    /* 0x050 */ u32 unk050t : 2;
    /* 0x054 */ u32 unk054p : 20;
    /* 0x054 */ u32 unk054b : 1;
    /* 0x054 */ u32 unk054a : 1;
    /* 0x054 */ u32 unk054q : 10;
    /* 0x058 */ u8 pad058[0x7D - 0x58];
    /* 0x07D */ u8 unk07D;
    /* 0x07E */ s8 unk07E;
    /* 0x07F */ u8 pad07F[0xF8 - 0x7F];
    /* 0x0F8 */ u32 unk0F8;
    /* 0x0FC */ u8 unk0FC;
    /* 0x0FD */ u8 pad0FD[0x100 - 0xFD];
    /* 0x100 */ u8 unk100;
    /* 0x101 */ u8 unk101;
} Unk800B9D84;

extern u16* lbl_8027EB54[];
extern u32* lbl_8027EB60[];

void fn_800E9810(Unk800B9D84* obj, s16 value);
void fn_800E9424(Unk800B9D84* obj, u16 anim);
void fn_800E946C(Unk800B9D84* obj, u8 id);
void fn_800E947C(Unk800B9D84* obj, u8 id, s8 arg2, s8 arg3);
void fn_800B68FC(Unk800B9D84* obj, u32 id, u8 arg2);

void fn_800B9D84(void* arg) {
    Unk800B9D84* obj = arg;
    s32 b;
    u8 a;
    u16 anim;
    u32 f;
    u32 id;

    fn_800E9810(obj, 0x140);
    f = (obj->unk00A >> 4) & 1;
    fn_800E9424(obj, lbl_8027EB54[obj->unk009][0]);
    obj->unk054a = f;
    if (obj->unk054a) {
        obj->unk00A |= 0x10;
    } else {
        obj->unk00A &= 0xEF;
    }
    obj->unk054b = 0;
    if (obj->unk054b) {
        obj->unk00A |= 0x20;
    } else {
        obj->unk00A &= 0xDF;
    }
    obj->unk02C = 0;
    obj->unk050t = 2;
    obj->unk02E = 0x10;
    obj->unk00A |= 1;
    obj->unk0FC = 0;
    id = *lbl_8027EB60[obj->unk009];
    if (((id >> 24) & 0xF) != 0 && ((id >> 24) & 0xF) == ((obj->unk0F8 >> 24) & 0xF)) {
        obj->unk0F8 = id;
        b = (s8)obj->unk07E;
        anim = lbl_8027EB54[obj->unk009][(id >> 8) & 0xF];
        a = obj->unk07D;
        if (anim != obj->unk024) {
            fn_800E9424(obj, anim);
        }
        fn_800E947C(obj, id, a, b);
        fn_800B68FC(obj, id, a);
    } else {
        obj->unk0F8 = id;
        anim = lbl_8027EB54[obj->unk009][(id >> 8) & 0xF];
        if (anim != obj->unk024) {
            fn_800E9424(obj, anim);
        }
        fn_800E946C(obj, id);
        fn_800B68FC(obj, id, 0);
    }
    obj->unk100 = 0;
    obj->unk101 = 0xFF;
    return;
}
