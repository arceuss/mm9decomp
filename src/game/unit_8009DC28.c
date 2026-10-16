#include "types.h"

typedef struct Unk80319DA0 {
    /* 0x0000 */ u8 pad0[0x866];
    /* 0x0866 */ u8 unk866;
    /* 0x0867 */ u8 unk867;
    /* 0x0868 */ u8 pad868[0x21C0 - 0x868];
} Unk80319DA0;

typedef struct Unk8038B2F8 {
    /* 0x0000 */ u8 pad0[0x26BC];
    /* 0x26BC */ s16 unk26BC;
} Unk8038B2F8;

typedef struct Unk8009DC28 {
    /* 0x0000 */ u8 pad0[0x431C];
    /* 0x431C */ void* unk431C;
} Unk8009DC28;

extern Unk80319DA0 lbl_80319DA0;
extern Unk8038B2F8 lbl_8038B2F8;

void fn_800E65B0(void);
void fn_8009D670(void);
void fn_800E6878(void);
void fn_800E72B4(void);
void fn_800D432C(void);
void fn_800D4230(void);
void fn_800D5088(void);
void fn_80083608(void);
void fn_800E6610(s32 arg0);
void fn_800AA38C(void);
void fn_80031650(void);
void fn_800E6578(void* arg0, void (*func)(void));

s32 fn_8009DC28(Unk8009DC28* work) {
    fn_800E65B0();
    fn_8009D670();
    lbl_80319DA0.unk866 = 0x18;
    lbl_80319DA0.unk867 = 4;
    fn_800E6878();
    lbl_8038B2F8.unk26BC = 0;
    fn_800E72B4();
    fn_800D432C();
    fn_800D4230();
    fn_800D5088();
    fn_80083608();
    fn_800E6610(1);
    fn_800AA38C();
    fn_800E6578(work->unk431C, fn_80031650);
    return 0;
}
