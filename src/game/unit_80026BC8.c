#include "types.h"

typedef struct Unk80301320State {
    /* 0x00 */ u8 cur;
    /* 0x01 */ u8 prev;
    /* 0x02 */ u8 pad2[0x16 - 0x2];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
} Unk80301320State;

typedef struct Unk80301320 {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u8 pad8[0x5C - 0x8];
    /* 0x5C */ Unk80301320State* state;
    /* 0x60 */ u8 pad60[0x68 - 0x60];
} Unk80301320;

extern Unk80301320 lbl_80301320;

s32 fn_800265F4(s32 arg0);
char* fn_80027394(s32 key);
s32 fn_80177360(const char* str, char** end, s32 base);
void fn_8024D950(s32 arg0, s32* arg1, s32* arg2);
BOOL fn_800275B4(s32 arg0, s32 arg1);
void fn_80029460(void);
void fn_80025C34(void (*cb)(void), s32 arg1, s32 arg2);

BOOL fn_80026BC8(void) {
    s32 b;
    s32 a;
    s32 id;
    s32 value;
    char* str;

    if (lbl_80301320.state->cur == 0x10) {
        if (lbl_80301320.state->unk17 != 1) {
            return FALSE;
        }
        id = fn_800265F4(1);
        str = fn_80027394(0xD);
        value = str != NULL ? fn_80177360(str, NULL, 10) : 0;
        str = fn_80027394(0xB);
        value -= str != NULL ? fn_80177360(str, NULL, 10) : 0;
        fn_8024D950(1, &a, &b);
        value += b;
        if (lbl_80301320.unk4 & 0x80) {
            fn_8024D950(0, &a, &b);
            value += b + 1;
        }
        if (!fn_800275B4(id, value)) {
            return FALSE;
        }
        lbl_80301320.state->unk16 = 0;
        lbl_80301320.state->prev = lbl_80301320.state->cur;
        lbl_80301320.state->cur = 0x11;
        fn_80025C34(fn_80029460, 0, 0);
        return TRUE;
    }
    return FALSE;
}
