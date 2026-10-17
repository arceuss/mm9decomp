#include "types.h"

typedef struct Unk80036810 {
    /* 0x000 */ u8 pad0[0x26C];
    /* 0x26C */ u8 unk26C;
    /* 0x26D */ u8 pad26D[0x26F - 0x26D];
    /* 0x26F */ u8 unk26F;
    /* 0x270 */ u8 unk270;
    /* 0x271 */ u8 unk271;
    /* 0x272 */ u8 pad272[0x288 - 0x272];
    /* 0x288 */ u8 unk288;
    /* 0x289 */ u8 unk289;
} Unk80036810;

typedef struct Unk80301420 {
    /* 0x00 */ u8 pad0[0x48];
    /* 0x48 */ u8 unk48[0x10];
} Unk80301420;

typedef void (*Unk80036810Func)(Unk80036810* obj);

extern Unk80301420 lbl_80301420;
extern u8 lbl_8043CD08[];
extern Unk80036810Func lbl_804EC968[2];
extern Unk80036810Func lbl_804EC970[2];
extern u8 lbl_804EC97C;
extern u8 lbl_8037C3D8[0x50];
extern void* lbl_804EE948;

void fn_800E6A78(void* a);
void fn_8009C04C(s32 a, void* b, s32 c);
void fn_800A78AC(void);
void fn_80036D0C(Unk80036810* obj);
void fn_80036FBC(Unk80036810* obj);
u32 fn_800BB6C8(u32 id);
void fn_800375BC(Unk80036810* obj);
void fn_800A7084(s32 a, s32 b, s32 c, s32 d, s32 e);
void fn_800A6D90(void);
void fn_800E8D30(void* a, s32 b);
void fn_800E8FC4(void* a, void* b);
void fn_800E69E8(void* a);

void fn_80036810(Unk80036810* obj) {
    fn_800E6A78(lbl_80301420.unk48);
    fn_8009C04C(0, lbl_8043CD08, 0x20);
    fn_800A78AC();
    if (obj->unk289 == 0) {
        if (obj->unk271 == 1 && obj->unk26C == 3) {
            fn_80036D0C(obj);
            fn_80036FBC(obj);
        }
        if (obj->unk26C != 3) {
            lbl_804EC968[obj->unk26C](obj);
        }
        if (obj->unk26F != 2) {
            lbl_804EC970[obj->unk26F](obj);
        } else if (obj->unk270 == 1) {
            if ((u8)fn_800BB6C8(1) == 3) {
                obj->unk26F = 0;
                obj->unk271 = 0;
            }
        } else if (obj->unk270 == 0) {
            obj->unk26F = 2;
            obj->unk271 = 1;
        }
        fn_800375BC(obj);
    }
    if (obj->unk289 == 1) {
        switch (obj->unk288) {
        case 0:
            fn_800A7084(2, lbl_804EC97C, 0x18, 0, 0);
            obj->unk288++;
            break;
        case 1:
            fn_800A6D90();
            if (lbl_8037C3D8[0] == 0 && lbl_8037C3D8[5] == 0) {
                obj->unk288++;
            }
            break;
        case 2:
            obj->unk288 = 0;
            obj->unk289 = 2;
            break;
        }
    } else if (obj->unk289 == 2) {
        obj->unk289 = 0;
    }
    fn_800BB6C8(0);
    fn_800E8D30(lbl_804EE948, 0x100);
    fn_800E8FC4(lbl_804EE948, lbl_80301420.unk48);
    fn_800E69E8(lbl_80301420.unk48);
}
