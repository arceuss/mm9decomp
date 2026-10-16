#include "types.h"

typedef struct Unk800332F4 {
    /* 0x000 */ u8 pad0[0x6];
    /* 0x006 */ u8 state;
    /* 0x007 */ u8 pad7;
    /* 0x008 */ s16 unk8;
    /* 0x00A */ u8 padA[0x1C - 0xA];
    /* 0x01C */ u8 unk1C[0x26C - 0x1C];
    /* 0x26C */ u8 unk26C;
    /* 0x26D */ u8 pad26D;
    /* 0x26E */ u8 unk26E;
    /* 0x26F */ u8 pad26F[0x27B - 0x26F];
    /* 0x27B */ u8 unk27B;
    /* 0x27C */ u8 pad27C[0x281 - 0x27C];
    /* 0x281 */ u8 unk281;
    /* 0x282 */ u8 pad282[0x288 - 0x282];
    /* 0x288 */ u8 unk288;
    /* 0x289 */ u8 unk289;
    /* 0x28A */ u8 pad28A[0x28D - 0x28A];
    /* 0x28D */ u8 unk28D;
} Unk800332F4;

typedef struct Unk8038B2F8Sub {
    /* 0x0000 */ u8 pad0[0x2500];
    /* 0x2500 */ u8 unk2500;
} Unk8038B2F8Sub;

typedef struct Unk8038B2F8 {
    /* 0x000 */ u8 pad0[0x184];
    /* 0x184 */ Unk8038B2F8Sub* unk184;
} Unk8038B2F8;

extern Unk8038B2F8 lbl_8038B2F8;
extern u8 lbl_803140C0[];
extern u8 lbl_803017A0[];

void fn_8008C07C(void* buf, u32 size);
void fn_8008C004(void);
void fn_800E6534(s32 arg0, void (*cb)(void));
BOOL fn_800E6654(s32 arg0);
void fn_8003170C(Unk800332F4* obj);
void fn_80035F8C(Unk800332F4* obj);
void fn_800D606C(void* dst, void* src, s32 arg2);

void fn_800332F4(Unk800332F4* obj) {
    switch (obj->state) {
    case 0:
        fn_8008C07C(lbl_803140C0, 0x600);
        fn_800E6534(1, fn_8008C004);
        obj->state++;
        obj->unk28D = 0;
        obj->unk8 = 0;
    case 1:
        if (fn_800E6654(1)) {
            obj->state++;
            fn_8003170C(obj);
            obj->unk26C = 10;
            obj->unk27B = 0;
            obj->unk281 = 0;
            obj->unk288 = 12;
            obj->unk289 = 2;
            fn_80035F8C(obj);
            obj->unk27B = 0;
        }
        break;
    case 2:
        lbl_8038B2F8.unk184->unk2500 = obj->unk8;
        if (obj->unk8 < 0x20) {
            obj->unk8 += 2;
        } else {
            obj->unk28D = 1;
            lbl_8038B2F8.unk184->unk2500 = 0x20;
            obj->unk26E = 3;
        }
        if (obj->unk28D == 1) {
            obj->state++;
        }
        break;
    case 3:
        fn_800D606C(obj->unk1C, lbl_803017A0, 0x40);
        obj->unk26C = 10;
        break;
    }
}
