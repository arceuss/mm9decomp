#include "types.h"

typedef struct Unk80085920 {
    /* 0x000 */ u8 pad0;
    /* 0x001 */ u8 stage;
    /* 0x002 */ u8 pad2[0x170 - 0x2];
    /* 0x170 */ u8 unk170[0x1F4 - 0x170];
    /* 0x1F4 */ u8 unk1F4[0xDD0 - 0x1F4];
    /* 0xDD0 */ u8 unkDD0[0xFDC - 0xDD0];
    /* 0xFDC */ u8 unkFDC[0xFEC - 0xFDC];
    /* 0xFEC */ s32 unkFEC;
    /* 0xFF0 */ s32 unkFF0;
    /* 0xFF4 */ u8 unkFF4[0x10];
} Unk80085920;

extern u8 lbl_8030C2B8[];
extern u8 lbl_803066B8[];
extern void (*lbl_80273134[])(Unk80085920* obj);
extern s32 lbl_802731F8[];

void fn_80023EF0(void* arg0, void* arg1, s32 arg2, s32 arg3, s32 arg4);
void fn_800E695C(void* arg0);
void fn_800E69A4(void* arg0, void* arg1);
void fn_800408F8(void* arg0, void* arg1, s32 arg2);
void fn_800D606C(void* arg0, void* arg1, s32 arg2);
void fn_8009C04C(s32 arg0, void* arg1, s32 arg2);
void fn_800A576C(void);
void fn_800E5654(void);
void fn_800D5564(s32 arg0);
void fn_80085A08(Unk80085920* obj);

void fn_80085920(Unk80085920* obj) {
    fn_80023EF0(obj->unkFDC, &obj->unkFEC, 0, 0, 0x100);
    obj->unkFEC = 0x8000;
    obj->unkFF0 = 0x7000;
    fn_800E695C(obj->unkDD0);
    fn_800E69A4(obj->unkDD0, obj->unkFDC);
    fn_800408F8(obj->unk170, lbl_8030C2B8, 0x40);
    fn_800D606C(obj->unk1F4, lbl_803066B8, 0x40);
    fn_8009C04C(0, obj->unkFF4, 0x10);
    fn_800A576C();
    fn_800E5654();
    lbl_80273134[obj->stage](obj);
    fn_800D5564(lbl_802731F8[obj->stage]);
    fn_80085A08(obj);
}
