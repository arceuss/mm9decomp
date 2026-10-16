#include "types.h"

typedef struct Unk8008C6CC {
    /* 0x0000 */ u8 pad0[0x2];
    /* 0x0002 */ u8 stage;
    /* 0x0003 */ u8 pad3[0xDD0 - 0x3];
    /* 0x0DD0 */ u8 unkDD0[0xFFA - 0xDD0];
    /* 0x0FFA */ u8 unkFFA;
    /* 0x0FFB */ u8 padFFB[0x100C - 0xFFB];
    /* 0x100C */ u32 voice;
    /* 0x1010 */ void* unk1010;
    /* 0x1014 */ u8 unk1014[0x10];
} Unk8008C6CC;

typedef struct Unk8037C3D8 {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 pad1[0x5 - 0x1];
    /* 0x5 */ u8 unk5;
    /* 0x6 */ u8 pad6[0x50 - 0x6];
} Unk8037C3D8;

extern u8 lbl_8043CD08[];
extern Unk8037C3D8 lbl_8037C3D8;
extern void (*lbl_80273660[])(Unk8008C6CC* obj);
extern void* lbl_804EE948;

void fn_800E6A78(void* arg0);
void fn_8009C04C(s32 arg0, void* arg1, s32 arg2);
void fn_800A78AC(void);
void fn_800A7084(s32 arg0, s32 id, s32 arg2, s32 arg3, s32 arg4);
void fn_800E8D30(void* arg0, s32 arg1);
s32 fn_8000EECC(s32 id);
void fn_800E85D0(void* arg0, s32 arg1, s32 arg2);
void fn_800E8FC4(void* arg0, void* arg1);
void fn_800E69E8(void* arg0);
void fn_800A6D90(void);
void fn_8008F9C0(void* arg0);

void fn_8008C6CC(Unk8008C6CC* obj) {
    fn_800E6A78(obj->unkDD0);
    fn_8009C04C(0, lbl_8043CD08, 0x20);
    fn_800A78AC();
    if (lbl_8037C3D8.unk0 == 0 && lbl_8037C3D8.unk5 == 0) {
        if (obj->voice != 0) {
            switch (obj->voice) {
            case 1:
                fn_800A7084(0, 0x98, 0x18, 0, 0);
                obj->voice = 0;
                break;
            case 2:
                fn_800A7084(0, 0x9B, 0x18, 0, 0);
                obj->voice = 0;
                break;
            case 3:
                fn_800A7084(0, 0x9E, 0x18, 0, 0);
                obj->voice = 0;
                break;
            }
        } else {
            lbl_80273660[obj->stage](obj);
            fn_800E8D30(lbl_804EE948, 0x100);
        }
    }
    if (obj->unkFFA != 0) {
        fn_800E85D0(obj->unk1010, fn_8000EECC(0x38), 0x1000);
        obj->unkFFA = 0;
    }
    fn_800E8FC4(lbl_804EE948, obj->unkDD0);
    fn_800E69E8(obj->unkDD0);
    fn_800A6D90();
    fn_8008F9C0(obj->unk1014);
}
