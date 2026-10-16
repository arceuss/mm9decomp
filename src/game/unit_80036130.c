#include "types.h"

typedef struct Unk80036130 {
    /* 0x000 */ u8 pad0[0x28A];
    /* 0x28A */ u8 unk28A;
    /* 0x28B */ u8 unk28B;
    /* 0x28C */ u8 unk28C;
    /* 0x28D */ u8 unk28D;
    /* 0x28E */ u8 unk28E;
    /* 0x28F */ u8 unk28F;
} Unk80036130;

typedef struct Unk8037C3D8 {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 pad1[0x5 - 0x1];
    /* 0x5 */ u8 unk5;
    /* 0x6 */ u8 pad6[0x50 - 0x6];
} Unk8037C3D8;

extern Unk8037C3D8 lbl_8037C3D8;
extern u8 lbl_804EC954[6];

void fn_800A7084(s32 arg0, u8 id, s32 arg2, s32 arg3, s32 arg4);
void fn_800A6D90(void);



void fn_80036130(Unk80036130* menu, u8 idx) {
    switch (menu->unk28B) {
    case 0:
        if ((u32)(menu->unk28A - 1) > 4) {
            if (menu->unk28A == 0) {
                fn_800A7084(2, lbl_804EC954[idx], 0x18, 0, 0);
                menu->unk28B = 1;
            }
        } else if (menu->unk28F == 0) {
            fn_800A7084(2, lbl_804EC954[idx], 0x18, 0, 0);
            menu->unk28B = 1;
        } else {
            fn_800A7084(2, lbl_804EC954[idx], 0x18, 1, 0);
            menu->unk28B = 2;
        }
        break;
    case 1:
        fn_800A6D90();
        if (lbl_8037C3D8.unk0 == 0 && lbl_8037C3D8.unk5 == 0) {
            menu->unk28B = 4;
        }
        break;
    case 2:
        fn_800A6D90();
        if (lbl_8037C3D8.unk0 == 0 && lbl_8037C3D8.unk5 == 0) {
            fn_800A7084(2, lbl_804EC954[idx + 1], 0x18, 0, 0);
            menu->unk28B = 3;
        }
        break;
    case 3:
        fn_800A6D90();
        if (lbl_8037C3D8.unk0 == 0 && lbl_8037C3D8.unk5 == 0) {
            menu->unk28B = 4;
        }
        break;
    case 4:
        menu->unk28B = 0;
        menu->unk28C = 0;
        menu->unk28E = 1;
        menu->unk28F = 0;
        break;
    }
}
