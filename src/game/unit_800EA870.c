#include "types.h"

typedef struct Unk8043CD28Entry {
    /* 0x0 */ u16 id;
    /* 0x2 */ u8 pad2[0x4 - 0x2];
    /* 0x4 */ u8 group;
    /* 0x5 */ u8 pad5[0x8 - 0x5];
} Unk8043CD28Entry;

typedef struct Unk8043CD28 {
    /* 0x000 */ u8 pad0[0x8];
    /* 0x008 */ Unk8043CD28Entry* unk8;
    /* 0x00C */ u8 padC[0x2E2 - 0xC];
    /* 0x2E2 */ u8 unk2E2;
    /* 0x2E3 */ u8 pad2E3[0x2E8 - 0x2E3];
} Unk8043CD28;

typedef struct Unk80383E70 {
    /* 0x000 */ u32 unk0;
    /* 0x004 */ u32 unk4[0x200];
    /* 0x804 */ u32 unk804[0x200];
} Unk80383E70;

extern Unk8043CD28 lbl_8043CD28;
extern Unk80383E70 lbl_80383E70;

void fn_800EAE24(void);

void fn_800EA870(void) {
    Unk8043CD28Entry* entry;

    for (entry = lbl_8043CD28.unk8; entry->group != 0xFF; entry++) {
        if (entry->group == lbl_8043CD28.unk2E2) {
            lbl_80383E70.unk4[entry->id] = 0;
            lbl_80383E70.unk804[entry->id] = 0;
        }
    }
    lbl_8043CD28.unk2E2 = 0xFF;
    fn_800EAE24();
}
