#include "types.h"

typedef struct Unk80084478 {
    /* 0x000 */ u8 pad0;
    /* 0x001 */ u8 state;
    /* 0x002 */ u8 step;
    /* 0x003 */ u8 unk3;
    /* 0x004 */ s16 fade;
    /* 0x006 */ u8 pad6[0x8 - 0x6];
    /* 0x008 */ s16 pos;
    /* 0x00A */ s16 speed;
    /* 0x00C */ u8 padC[0xDD0 - 0xC];
    /* 0xDD0 */ u8 unkDD0[0xFF4 - 0xDD0];
    /* 0xFF4 */ u8 unkFF4;
} Unk80084478;

typedef struct Unk80301280Sub {
    /* 0x00 */ u8 pad0[0x1E];
    /* 0x1E */ s16 unk1E;
} Unk80301280Sub;

typedef struct Unk80301280 {
    /* 0x00 */ u8 pad0[0x40];
    /* 0x40 */ Unk80301280Sub* unk40;
} Unk80301280;

typedef struct Unk8038B2F8 {
    /* 0x000 */ u8 pad0[0x184];
    /* 0x184 */ u8* unk184;
} Unk8038B2F8;

extern Unk80301280 lbl_80301280;
extern Unk8038B2F8 lbl_8038B2F8;
extern u8 lbl_8043CD08[];
extern void* lbl_804EE948;

void fn_800D5234(s32 id);
void fn_800DB280(Unk80084478* obj, s32 arg1, s32 arg2);
void fn_800D5544(s32 id, s32 arg1);
BOOL fn_800D5520(s32 id);
BOOL fn_800D57BC(s32 id);
void fn_800D5564(s32 id);
void fn_800E6A78(void* arg0);
void fn_8009C04C(s32 arg0, void* arg1, s32 arg2);
void fn_800A78AC(void);
void fn_800E8D30(void* arg0, s32 arg1);
void fn_800E8FC4(void* arg0, void* arg1);
void fn_800E69E8(void* arg0);

void fn_80084478(Unk80084478* obj) {
    switch (obj->step) {
    case 0:
        if ((obj->fade += 2) < 0x20) {
            break;
        }
        fn_800D5234(7);
        fn_800DB280(obj, 0, 0);
        obj->step++;
    case 1:
        if (obj->unkFF4 != 1) {
            break;
        }
        fn_800D5544(7, 0x100);
        obj->pos = 0;
        obj->speed = 9;
        obj->step++;
    case 2:
        if ((obj->pos += obj->speed) < 0x1000) {
            if (!fn_800D5520(7) && !fn_800D57BC(6)) {
                fn_800D5564(6);
            }
            lbl_80301280.unk40->unk1E = (obj->pos * 0xE000 / 0x1000) >> 8;
            break;
        }
        lbl_80301280.unk40->unk1E = 0xE0;
        obj->step++;
    case 3:
        if (obj->unkFF4 == 2) {
            obj->state = 2;
            obj->unk3 = 0;
            obj->step = 2;
        }
        break;
    }
    fn_800E6A78(obj->unkDD0);
    fn_8009C04C(0, lbl_8043CD08, 0x20);
    fn_800A78AC();
    fn_800E8D30(lbl_804EE948, 0x100);
    fn_800E8FC4(lbl_804EE948, obj->unkDD0);
    fn_800E69E8(obj->unkDD0);
    lbl_8038B2F8.unk184[0x2500] = obj->fade;
}
