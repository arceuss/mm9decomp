#include "types.h"

extern u8 lbl_802638A0[];
extern u8 lbl_804EE698[8];
extern u8 lbl_80263050[0x20];
void fn_800E9424(u8* obj, s32 a);
void fn_800E91F0(u8* obj, s32 a, s32 b);
void fn_8000F134(u32 a);
void fn_800C7594(s32 a);
void fn_8001E250(u8* obj);
void fn_8001E174(u8* obj);

void fn_8001E188(u8* obj) {
    u8* tbl;
    u32 idx;
    u8 v;
    u8 a;
    void* fn;

    tbl = lbl_802638A0;
    idx = obj[9] * 4;
    a = obj[0x0A];
    v = obj[0x14];
    *(u32*)(obj + 0x11) = *(u32*)(*(u32*)(tbl + idx) + 4);
    fn_800E9424(obj, 0x44);
    fn_800E91F0(obj, 0, 0);
    fn = fn_8001E174;
    *(u32*)(obj + 0xAC) = (u32)fn;
    fn_8000F134((u32)lbl_80263050);
    obj[0xEA] = 0xFF;
    fn_800C7594(0xB);
    obj[0xEB] = 0;
    fn_8001E250(obj);
}
