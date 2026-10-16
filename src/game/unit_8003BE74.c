#include "types.h"
#include "game/sound.h"

typedef struct Unk8003BE74 {
    /* 0x000 */ u8 pad0[0x26C];
    /* 0x26C */ u8 unk26C;
    /* 0x26D */ u8 unk26D;
    /* 0x26E */ u8 unk26E;
    /* 0x26F */ s8 unk26F;
    /* 0x270 */ u8 unk270;
    /* 0x271 */ u8 pad271[0x274 - 0x271];
    /* 0x274 */ u8 unk274;
    /* 0x275 */ u8 unk275;
} Unk8003BE74;

typedef struct Unk80319DA0 {
    /* 0x000 */ u8 pad0[0x860];
    /* 0x860 */ u32 unk860;
    /* 0x864 */ u16 unk864;
} Unk80319DA0;

extern Unk80319DA0 lbl_80319DA0;

void fn_800D5234(s32 id);

void fn_8003BE74(Unk8003BE74* obj) {
    if (obj->unk270 == 1 && obj->unk26F == 3) {
        return;
    }
    if (obj->unk270 == 0) {
        if (lbl_80319DA0.unk864 & 1) {
            fn_800D5234(SE_CURSOR);
            obj->unk26F--;
        } else if (lbl_80319DA0.unk864 & 2) {
            fn_800D5234(SE_CURSOR);
            obj->unk26F++;
        }
        if (obj->unk26F < 0) {
            obj->unk26F = 3;
        } else if (obj->unk26F > 3) {
            obj->unk26F = 0;
        }
    }
    if (obj->unk26C == 1) {
        return;
    }
    if (lbl_80319DA0.unk860 & 0x50) {
        fn_800D5234(SE_SELECT);
        if (obj->unk270 == 0) {
            obj->unk270 = 1;
        } else if (obj->unk270 == 1) {
            obj->unk270 = 0;
        }
    } else if (lbl_80319DA0.unk860 & 0x20) {
        if (obj->unk270 != 0) {
            obj->unk26D = obj->unk274;
            obj->unk26E = obj->unk275;
            obj->unk270 = 0;
        } else {
            if (obj->unk26F != 3) {
                fn_800D5234(SE_CURSOR);
            }
            obj->unk26F = 3;
        }
    }
}
