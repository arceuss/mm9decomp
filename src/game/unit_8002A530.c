#include "types.h"

typedef struct Unk80301320Sub {
    /* 0x00 */ u8 state;
    /* 0x01 */ u8 prevState;
    /* 0x02 */ u8 pad2[0x4 - 0x2];
    /* 0x04 */ void* unk4;
    /* 0x08 */ void* unk8;
    /* 0x0C */ u8 padC[0x18 - 0xC];
    /* 0x18 */ void (*unk18)(void);
    /* 0x1C */ u8 pad1C[0x22 - 0x1C];
    /* 0x22 */ u16 unk22;
    /* 0x24 */ u8 unk24[0x28 - 0x24];
    /* 0x28 */ s32 unk28;
} Unk80301320Sub;

typedef struct Unk80301320 {
    /* 0x00 */ u8 state;
    /* 0x01 */ u8 prevState;
    /* 0x02 */ u8 pad2[0x4 - 0x2];
    /* 0x04 */ u32 flags;
    /* 0x08 */ u8 pad8[0x29 - 0x8];
    /* 0x29 */ u8 errorKind;
    /* 0x2A */ u8 pad2A[0x2C - 0x2A];
    /* 0x2C */ s32 errorCode;
    /* 0x30 */ u8 pad30[0x5C - 0x30];
    /* 0x5C */ Unk80301320Sub* sub;
    /* 0x60 */ void (*callback)(s32 event, s32 arg, void* user);
    /* 0x64 */ void* user;
} Unk80301320;

extern Unk80301320 lbl_80301320;

void fn_80025860(void);

typedef struct Unk8002A530A {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ s32 unk1C;
} Unk8002A530A;

typedef struct Unk8002A530B {
    /* 0x0 */ u8 pad0[0x4];
    /* 0x4 */ Unk8002A530A* unk4;
} Unk8002A530B;

BOOL fn_801F6C00(void* arg0, u16 arg1);

s32 fn_8002A530(u16 id) {
    if (lbl_80301320.sub->state == 7 && (lbl_80301320.flags & 0x20)) {
        if (id != lbl_80301320.sub->unk22) {
            if (fn_801F6C00(lbl_80301320.sub->unk24, id)) {
                lbl_80301320.errorKind = 4;
                lbl_80301320.errorCode = 0;
                fn_80025860();
                lbl_80301320.callback(3, 0, lbl_80301320.user);
                return -1;
            }
            lbl_80301320.sub->unk22 = id;
        }
        return lbl_80301320.sub->unk28 == ((Unk8002A530B*)lbl_80301320.sub->unk8)->unk4->unk1C;
    }
    return 0;
}
