#include "types.h"

typedef struct Unk800301C4Box {
    /* 0x000 */ u8 pad0[0x419];
    /* 0x419 */ u8 visible;
    /* 0x41A */ u8 pad41A[0x41C - 0x41A];
} Unk800301C4Box;

typedef struct Unk800301C4 {
    /* 0x000 */ u8 pad0[0x5];
    /* 0x005 */ u8 state;
    /* 0x006 */ u8 step;
    /* 0x007 */ u8 unk7;
    /* 0x008 */ u8 pad8[0x274 - 0x8];
    /* 0x274 */ Unk800301C4Box* boxes;
    /* 0x278 */ u8 pad278[0x2AE - 0x278];
    /* 0x2AE */ u8 unk2AE;
} Unk800301C4;

typedef struct Unk80301320 {
    /* 0x00 */ u8 pad0[0x30];
    /* 0x30 */ s16* msg;
    /* 0x34 */ s16* title;
} Unk80301320;

typedef struct Unk80319DA0 {
    /* 0x000 */ u8 pad0[0x860];
    /* 0x860 */ u32 trig;
} Unk80319DA0;

extern Unk80301320 lbl_80301320;
extern Unk80319DA0 lbl_80319DA0;

void fn_8003107C(Unk800301C4* obj, s32 arg1);
u8 fn_80031188(Unk800301C4* obj);
u8 fn_800312D8(Unk800301C4* obj);
void fn_80083620(Unk800301C4Box* box, s32 a, s32 b, s16* text, s32 x, s16 y, s32 w, s32 h);
void fn_800836B0(Unk800301C4Box* box);
void fn_80083714(Unk800301C4Box* box);

void fn_800301C4(Unk800301C4* obj) {
    s16* text;
    s16* p;
    u8 lines;

    switch (obj->step) {
    case 0:
        fn_8003107C(obj, 0);
        lines = 1;
        text = lbl_80301320.msg;
        for (p = text; *p != 0; p++) {
            if (*p == '\n') {
                lines++;
            }
        }
        fn_80083620(&obj->boxes[0], 1, 1, text, 0, -(lines * 16) - 0x14, 0x18, 0x20);
        fn_800836B0(&obj->boxes[0]);
        obj->boxes[0].visible = 1;
        fn_80083620(&obj->boxes[1], 1, 1, lbl_80301320.title, 0, 0x5C, 0x18, 0x20);
        fn_800836B0(&obj->boxes[1]);
        obj->boxes[1].visible = 1;
        obj->step++;
        break;
    case 1:
        if (fn_80031188(obj)) {
            obj->step++;
        }
        break;
    case 2:
        if (lbl_80319DA0.trig & 0x10) {
            fn_8003107C(obj, 1);
            obj->step++;
        }
        break;
    case 3:
        if (fn_800312D8(obj)) {
            fn_80083714(&obj->boxes[0]);
            fn_80083714(&obj->boxes[1]);
            obj->unk2AE &= ~4;
            obj->state = 2;
            obj->step = 0;
            obj->unk7 = 1;
        }
        break;
    }
}
