#include "types.h"

typedef struct Unk800E5AEC {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5_hi : 4;
    /* 0x05 */ u8 unk5_lo : 4;
    /* 0x06 */ u8 pad6[0x17 - 6];
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8* unk18;
    /* 0x1C */ u8* unk1C;
    /* 0x20 */ u8* unk20;
    /* 0x24 */ u8* unk24;
} Unk800E5AEC;

extern u8 lbl_8038E3A8[];
void fn_800A5FA8(void*, void*, u32);

void fn_800E5AEC(Unk800E5AEC* obj) {
    u32 b = 0xFF;
    u8* p = obj->unk1C;
    u32 a = 0xFF;
    u8* q;

    fn_800A5FA8(p, lbl_8038E3A8 + 0x2C, 0x100);
    obj->unk24 = NULL;
    while (*p < 0xFD) {
        if (*p == 0xF0) {
            do { p++; } while (*p == 0xFF);
        } else if (*p == 0xF2) {
            switch ((s32)*++p) {
            case 0: obj->unk4 = 0; break;
            case 1: obj->unk4 = 1; break;
            }
        } else if (*p == 0xF5) {
            a = *++p;
        } else if (*p == 0xF6) {
            b = *++p;
        }
        p++;
    }
    if (a != 0xFF) {
        obj->unk17 = a;
        for (p = obj->unk18; *p < 0xFF; p++) {
            if (*p == 0xF4 && p[1] == a) {
                obj->unk20 = p + 2;
                break;
            }
        }
        if (*p == 0xFF) obj->unk20 = NULL;
    } else {
        if (*p < 0xFE) obj->unk20 = p + 1;
        else obj->unk20 = NULL;
    }
    if (b != 0xFF) {
        obj->unk20 = p + 1;
        obj->unk5_hi = obj->unk5_lo;
        obj->unk5_lo = 1;
        q = obj->unk18;
        for (; *q < 0xFF; q++) {
            if (*q == 0xF4 && q[1] == b) {
                obj->unk24 = q + 2;
                break;
            }
        }
        if (*q == 0xFF) obj->unk24 = obj->unk20;
        if (obj->unk24 == NULL) obj->unk24 = (u8*)-1;
    }
}
