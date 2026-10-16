#include "types.h"

typedef struct Unk80085594 {
    /* 0x0000 */ u8 pad0[0xFFB];
    /* 0x0FFB */ u8 unkFFB;
    /* 0x0FFC */ u8 unkFFC;
    /* 0x0FFD */ u8 unkFFD;
    /* 0x0FFE */ u8 unkFFE;
    /* 0x0FFF */ u8 unkFFF;
    /* 0x1000 */ u8 unk1000;
    /* 0x1001 */ u8 unk1001;
    /* 0x1002 */ u8 unk1002;
    /* 0x1003 */ u8 unk1003;
    /* 0x1004 */ u8 pad1004[0x100F - 0x1004];
    /* 0x100F */ s8 unk100F;
} Unk80085594;

extern u8 lbl_80305648[0x34];

void fn_80085594(Unk80085594* obj) {
    u8 i;

    for (i = 0; i < 9; i++) {
        switch (i) {
        case 0:
            obj->unkFFB = lbl_80305648[i + obj->unk100F];
            break;
        case 1:
            obj->unkFFC = lbl_80305648[i + obj->unk100F];
            break;
        case 2:
            obj->unkFFD = lbl_80305648[i + obj->unk100F];
            break;
        case 3:
            obj->unkFFE = lbl_80305648[i + obj->unk100F];
            break;
        case 4:
            obj->unkFFF = lbl_80305648[i + obj->unk100F];
            break;
        case 5:
            obj->unk1000 = lbl_80305648[i + obj->unk100F];
            break;
        case 6:
            obj->unk1001 = lbl_80305648[i + obj->unk100F];
            break;
        case 7:
            obj->unk1002 = lbl_80305648[i + obj->unk100F];
            break;
        case 8:
            obj->unk1003 = lbl_80305648[i + obj->unk100F];
            break;
        default:
            obj->unkFFB = lbl_80305648[i + obj->unk100F];
            break;
        }
    }
}
