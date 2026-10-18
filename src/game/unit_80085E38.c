#include "types.h"

typedef struct Unk80085E38 {
    u8 pad0[2];
    u8 unk2;
    u8 step;
    s16 unk4;
    s16 unk6;
    u8 pad8[0xFF4-8];
    u8 unkFF4;
    u8 unkFF5;
    u8 unkFF6;
    u8 padFF7[0x1001-0xFF7];
    u8 unk1001;
    u8 pad1002;
    u8 unk1003;
} Unk80085E38;
typedef struct Unk80316D78 { u8 pad0[0x3004]; u8* unk3004; } Unk80316D78;
extern Unk80316D78 lbl_80316D78;
extern u8 lbl_8038E738[];
void fn_800DBCE0(Unk80085E38*, s32, s32);
u32 fn_800BB6C8(u32);
void fn_800E5910(s32);
void* fn_8000EF20(s32);
void fn_800E83A4(void*, void*);
void fn_800BAF48(void*, s32);
void fn_8000ECB8(s32, void*, s32, s32, s32);
void fn_800D5234(s32);

static inline void Load(s32 index) {
    u32 R = (u32)lbl_80316D78.unk3004 + 0xCD5000;
    void* p = fn_8000EF20(0x38);
    fn_800E83A4((u8*)((*(u32*)(R+8) >> 1) + R) + index*20, p);
    R = (u32)lbl_80316D78.unk3004 + 0xCD5000;
    fn_800BAF48((u8*)((*(u32*)(R+8) >> 1) + R) + index*20 + 12, 0);
    R = (u32)lbl_80316D78.unk3004 + 0xCD5000;
    fn_8000ECB8(0x38, (void*)((*(u32*)(R+4) >> 1) + R), index, 0, 0);
}

void fn_80085E38(Unk80085E38* obj) {
    switch (obj->step) {
    case 0:
        fn_800DBCE0(obj, 0, 1);
        fn_800DBCE0(obj, 0, 2);
        obj->unk1001 = 2;
        obj->unk1003 = 1;
        obj->unkFF4++;
        obj->step++;
    case 1:
        if (obj->unk1001 == 0) obj->step++;
        fn_800BB6C8(0);
        break;
    case 2:
        obj->unk4 = 0x78;
        obj->unkFF4++;
        obj->step++;
    case 3:
        if (--obj->unk4 == 0) obj->step++;
        fn_800BB6C8(0);
        break;
    case 4:
        fn_800DBCE0(obj, 0, 0);
        obj->unkFF5 = 0;
        obj->unk4 = 0;
        obj->unkFF4++;
        obj->step++;
    case 5:
        if (obj->unkFF5 == 1) {
            if (++obj->unk4 == 0x1E) obj->step++;
        }
        fn_800BB6C8(0);
        break;
    case 6:
        fn_800E5910(0xC00);
        obj->unkFF4++;
        obj->step++;
    case 7:
        if (*(u16*)(lbl_8038E738+0xA) == 0) obj->step++;
        fn_800BB6C8(0);
        break;
    case 8:
        fn_800E5910(0xC01);
        obj->unkFF4++;
        obj->step++;
    case 9:
        if (*(u16*)(lbl_8038E738+0xA) == 0) {
            obj->unk1001 = 4;
            obj->unk1003 = 1;
            obj->step++;
        }
        fn_800BB6C8(0);
        break;
    case 10:
        if (obj->unk1001 != 0) { fn_800BB6C8(0); break; }
        Load(1);
        obj->unk1001 = 2;
        obj->unk1003 = 1;
        obj->unk4 = 0;
        obj->unk6 = 0xB4;
        obj->unkFF4++;
        obj->step++;
    case 11:
        if (obj->unk4 == 0) {
            if (obj->unk1001 == 0) {
                fn_800D5234(0x1A);
                obj->unk4++;
            }
        } else if (obj->unk4 == 1) {
            if (--obj->unk6 == 0) {
                obj->unk1001 = 4;
                obj->unk1003 = 1;
                obj->unk4++;
            }
        } else if (obj->unk1001 == 0) obj->step++;
        break;
    case 12:
        obj->unk1001 = 2;
        obj->unk1003 = 1;
        Load(0);
        obj->unkFF5 = 0;
        obj->unk4 = 0;
        obj->unkFF4++;
        obj->step++;
    case 13:
        if (obj->unk4 == 0) {
            if (obj->unk1001 == 0) obj->unk4++;
        } else if (obj->unk4 == 1) {
            fn_800E5910(0xC02);
            obj->unk4++;
        } else if (*(u16*)(lbl_8038E738+0xA) == 0) {
            obj->unk4 = 0;
            obj->step++;
        }
        fn_800BB6C8(0);
        break;
    case 14:
        if (++obj->unk4 != 0x1E) break;
        obj->unkFF5 = 0;
        obj->unk4 = 0;
        obj->unkFF4++;
        obj->step++;
    case 15:
        if (obj->unkFF5 == 1) {
            if (++obj->unk4 == 0x3C) obj->step++;
        }
        fn_800BB6C8(0);
        break;
    case 16:
        obj->unk1001 = 4;
        obj->unk1003 = 1;
        obj->unkFF4++;
        obj->step++;
    case 17:
        if (obj->unk1001 == 0) {
            obj->unkFF4 = 0xFF;
            obj->unkFF6 = 0;
            obj->unk2 = 2;
            obj->step = 0;
        }
        fn_800BB6C8(0);
        break;
    }
}
