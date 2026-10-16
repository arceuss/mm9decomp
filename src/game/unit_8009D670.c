#include "types.h"

typedef struct Unk80319DA0Entry {
    /* 0x000 */ u8 pad0[0x840];
    /* 0x840 */ s32 unk840;
    /* 0x844 */ s32 unk844;
    /* 0x848 */ s32 unk848;
    /* 0x84C */ u8 pad84C[0x850 - 0x84C];
    /* 0x850 */ s32 unk850;
    /* 0x854 */ s32 unk854;
    /* 0x858 */ s32 unk858;
    /* 0x85C */ s16 unk85C;
    /* 0x85E */ u8 unk85E;
    /* 0x85F */ u8 unk85F;
    /* 0x860 */ s32 unk860;
    /* 0x864 */ s32 unk864;
    /* 0x868 */ s16 unk868;
    /* 0x86A */ u8 pad86A[0x86C - 0x86A];
} Unk80319DA0Entry;

typedef struct Unk80319DA0 {
    /* 0x0000 */ u8 pad0[0x8];
    /* 0x0008 */ Unk80319DA0Entry entries[4];
    /* 0x21B8 */ u16 unk21B8;
    /* 0x21BA */ u8 pad21BA[0x21C0 - 0x21BA];
} Unk80319DA0;

extern Unk80319DA0 lbl_80319DA0;

void fn_8009D780(void);

void fn_8009D670(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        lbl_80319DA0.entries[i].unk848 = 0xFD;
        lbl_80319DA0.entries[i].unk85C = 0;
        lbl_80319DA0.entries[i].unk858 = 0;
        lbl_80319DA0.entries[i].unk854 = 0;
        lbl_80319DA0.entries[i].unk850 = 0;
        lbl_80319DA0.entries[i].unk864 = 0;
        lbl_80319DA0.entries[i].unk860 = 0;
        lbl_80319DA0.entries[i].unk868 = 0;
        lbl_80319DA0.entries[i].unk840 = 0;
        lbl_80319DA0.entries[i].unk844 = 0;
        lbl_80319DA0.entries[i].unk85E = 0x18;
        lbl_80319DA0.entries[i].unk85F = 4;
    }
    fn_8009D780();
    lbl_80319DA0.unk21B8 = 0;
}
