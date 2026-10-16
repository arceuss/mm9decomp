#include "types.h"

typedef struct Unk401ACEntry {
    /* 0x00 */ u8 unk00[0x3C];
} Unk401ACEntry;
typedef struct Unk401AC {
    /* 0x000 */ u8 pad000[0xC54];
    /* 0xC54 */ Unk401ACEntry unkC54[2];
    /* 0xCCC */ u16 unkCCC;
    /* 0xCCE */ u8 padCCE[0xD];
    /* 0xCDB */ u8 unkCDB;
} Unk401AC;
extern Unk401AC lbl_80303E58;
void fn_800D5B90(Unk401ACEntry*, u8);

void fn_800401AC(void) {
    s32 i;
    if (lbl_80303E58.unkCCC != 0) {
        for (i = 0; i < 2; i++) {
            if (lbl_80303E58.unkCCC & (1 << i)) {
                fn_800D5B90(&lbl_80303E58.unkC54[i], lbl_80303E58.unkCDB);
            }
        }
    }
}
