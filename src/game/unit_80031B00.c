#include "types.h"

typedef struct Unk80031B00 {
    /* 0x000 */ u8 pad0[0x26C];
    /* 0x26C */ u8 unk26C;
    /* 0x26D */ u8 pad26D;
    /* 0x26E */ u8 unk26E;
    /* 0x26F */ u8 pad26F[0x28D - 0x26F];
    /* 0x28D */ u8 unk28D;
} Unk80031B00;

typedef struct Unk80301420 {
    /* 0x000 */ u8 pad0[0x48];
    /* 0x048 */ u8 unk48[0x380 - 0x48];
} Unk80301420;

extern Unk80301420 lbl_80301420;
extern u8 lbl_8043CD08[0x20];
extern void (*lbl_804EC960[2])(Unk80031B00* work);
extern void (*lbl_80264338[30])(Unk80031B00* work);
extern void* lbl_804EE948[2];

void fn_800E6A78(void* list);
void fn_8009C04C(s32 arg0, void* buf, s32 size);
void fn_800A78AC(void);
void fn_800E8D30(void* pool, s32 arg1);
void fn_800E8FC4(void* pool, void* list);
void fn_800E69E8(void* list);

void fn_80031B00(Unk80031B00* work) {
    fn_800E6A78(lbl_80301420.unk48);
    fn_8009C04C(0, lbl_8043CD08, 0x20);
    fn_800A78AC();
    if (work->unk26E != 3 && work->unk26E != 2) {
        lbl_804EC960[work->unk26E](work);
    }
    lbl_80264338[work->unk26C](work);
    if (work->unk28D != 0) {
        fn_800E8D30(lbl_804EE948[0], 0x100);
        fn_800E8FC4(lbl_804EE948[0], lbl_80301420.unk48);
    }
    fn_800E69E8(lbl_80301420.unk48);
}
