#include "types.h"
typedef struct Unk80083024 {
    /* 0x00 */ u8 pad00[0x28];
    /* 0x28 */ u8* unk28;
} Unk80083024;
extern u8 lbl_8043CD28[];
extern void fn_800EB060(s32, s32);
extern void fn_800EA870(void);
extern void fn_800EB074(void);
s32 fn_80083024(Unk80083024* p) {
    u8* cmd = p->unk28;
    switch (cmd[1]) {
    case 0: lbl_8043CD28[0x2E4] = 0; break;
    case 1: lbl_8043CD28[0x2E4] = 1; break;
    case 2: fn_800EB060(*(s32*)(cmd + 4), *(s32*)(lbl_8043CD28 + 0x2D8)); break;
    case 3: fn_800EB060(*(s32*)(lbl_8043CD28 + 0x2D4), *(s32*)(cmd + 4)); break;
    case 4: fn_800EA870(); break;
    case 5: fn_800EB074(); break;
    }
    return 0;
}
