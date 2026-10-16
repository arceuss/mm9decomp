#include "types.h"

typedef struct Unk80089D2C {
    /* 0x0000 */ u8 pad0[0x2148];
    /* 0x2148 */ s32 unk2148;
    /* 0x214C */ u8 pad214C[0x2154 - 0x214C];
    /* 0x2154 */ u32 stage;
    /* 0x2158 */ u8 pad2158[0x227C - 0x2158];
    /* 0x227C */ u8 unk227C;
} Unk80089D2C;

typedef struct Unk803140C0 {
    /* 0x0000 */ u8 pad0[0x2290];
    /* 0x2290 */ u8* player;
} Unk803140C0;

typedef struct Unk80301280Sub {
    /* 0x0 */ u32 flags;
} Unk80301280Sub;

typedef struct Unk80301280 {
    /* 0x00 */ u8 pad0[0x40];
    /* 0x40 */ Unk80301280Sub* unk40;
} Unk80301280;

extern Unk80301280 lbl_80301280;
extern Unk803140C0 lbl_803140C0;
extern u32 lbl_804EE988;
extern void* lbl_804EE6C0;
extern void* lbl_804EE664;
extern void* lbl_804EE738;
extern void* lbl_804EE810;
extern void* lbl_804EE730;
extern void* lbl_804EE908;
extern void* lbl_804EE878;
extern u32 lbl_80272F50[];
extern void* lbl_8027E0D8[];

void fn_800D4230(void);
void fn_800D5088(void);
void fn_800A7C30(void);
void fn_800E8D0C(void);
void fn_800E8BB8(void* pool);
void fn_80099784(void);
void fn_800BB244(void);
void fn_800833EC(s32 arg0, s32 arg1);
void fn_8007D9F4(u32 arg0);
void fn_800722D4(void);
void fn_8007DC1C(void);
void fn_800E66E0(u8 arg0);
void fn_8007DA00(u32 stage);
void fn_8009DE58(void* arg0, void* pos);
void fn_800EA1E0(void);
void fn_8008C07C(Unk80089D2C* obj, s32 arg1);

void fn_80089D2C(Unk80089D2C* obj) {
    u32 seed = obj->stage;
    u32 stage;
    u32 idx;
    u8* player;

    fn_800D4230();
    fn_800D5088();
    lbl_80301280.unk40->flags &= ~7;
    lbl_80301280.unk40->flags &= ~0xF00;
    fn_800A7C30();
    fn_800E8D0C();
    lbl_804EE988 = seed;
    fn_800E8BB8(lbl_804EE6C0);
    fn_800E8BB8(lbl_804EE664);
    fn_800E8BB8(lbl_804EE738);
    fn_800E8BB8(lbl_804EE810);
    fn_800E8BB8(lbl_804EE730);
    fn_800E8BB8(lbl_804EE908);
    fn_800E8BB8(lbl_804EE878);
    fn_80099784();
    fn_800BB244();
    fn_800833EC(2, 6);
    stage = obj->stage;
    player = lbl_803140C0.player;
    idx = stage & 0xFFF;
    fn_8007D9F4(lbl_80272F50[idx]);
    if (obj->unk227C == 4) {
        fn_800722D4();
    } else {
        fn_8007DC1C();
    }
    if (obj->unk227C == 3) {
        fn_800E66E0(idx);
    }
    fn_8007DA00(stage);
    fn_8009DE58(lbl_8027E0D8[idx], player + 0x60);
    fn_800EA1E0();
    obj->unk2148 = 0;
    fn_8008C07C(obj, 0xA00);
}
