#include "types.h"

typedef struct Unk80301320Text {
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u16 unk2;
} Unk80301320Text;

typedef struct Unk80301320 {
    /* 0x00 */ u8 pad0[0x2C];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ void* unk30;
    /* 0x34 */ Unk80301320Text* unk34;
    /* 0x38 */ u8 pad38[0x58 - 0x38];
    /* 0x58 */ u8* msg;
} Unk80301320;

extern Unk80301320 lbl_80301320;
extern u32 lbl_8036CF50[];
extern char lbl_804EC840[8];
extern char lbl_804EC848[8];
extern char lbl_804EC858[8];
extern u8 lbl_80263A58[];
extern u8 lbl_80263A68[];
extern u8 lbl_80263A1C[];
extern u8 lbl_80263A30[];
extern u8 lbl_80263A44[];

void fn_80179BA0(void* a, void* msg);
void fn_80179A8C(char* buf, u32 n, const char* fmt, s32 v);
void fn_80025C58(void* dst, void* msg, void* fmt, char* buf);

static inline u8* Msg(u32 i) {
    u8* t = lbl_80301320.msg;
    u8* s;

    if (t != NULL) {
        s = t + (((u32*)t)[lbl_8036CF50[0] + 1] >> 1);
        if (i < *(u32*)s) {
            return s + *(u32*)(s + (i + 1) * 4);
        }
    }
    return NULL;
}

void fn_80025728(u32 id, char* str, s32 show) {
    char buf[0x22];

    fn_80025C58(lbl_80301320.unk30, Msg(id), lbl_80263A58, str);
    if (show) {
        fn_80179A8C(buf, 0x22, lbl_804EC858, lbl_80301320.unk2C);
        fn_80025C58(lbl_80301320.unk34, Msg(0), lbl_80263A68, buf);
    } else {
        lbl_80301320.unk34->unk0 = 0x20;
        lbl_80301320.unk34->unk2 = 0;
    }
}
