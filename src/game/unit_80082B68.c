#include "types.h"

typedef struct Unk80082B68Data {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    s32 unk4;
} Unk80082B68Data;

typedef struct Unk80082B68Obj {
    u8 pad0[0x60];
    s32 x;
    s32 y;
    s32 vx;
    s32 vy;
} Unk80082B68Obj;

typedef struct Unk80082B68 {
    u8 pad0[0x28];
    Unk80082B68Data* unk28;
    Unk80082B68Obj* unk2C;
    u8 pad30[0xF6-0x30];
    u16 unkF6;
    u8 padF8[0x1A0-0xF8];
    s32 unk1A0;
    s32 unk1A4;
    u8 pad1A8[8];
    s32 unk1B0;
} Unk80082B68;

typedef struct Unk80304B90 {
    u8 pad0[0x25C];
    s32 unk25C;
    s32 unk260;
} Unk80304B90;
extern Unk80304B90 lbl_80304B90;
s32 fn_800B661C(Unk80082B68Obj*, s32);
s32 fn_800B66B0(Unk80082B68Obj*);
s32 fn_800B672C(Unk80082B68Obj*);
s32 fn_800B66BC(Unk80082B68Obj*, s32);
s32 fn_800B6750(Unk80082B68Obj*);
s32 fn_800B6440(Unk80082B68Obj*, s32);
s32 fn_800B6104(Unk80082B68Obj*);
s32 fn_800B608C(Unk80082B68Obj*);
s32 fn_800A3AE0(s32, s32);
s32 fn_800A3DBC(s32, s32);

s32 fn_80082B68(Unk80082B68* obj) {
    Unk80082B68Obj* target = obj->unk2C;
    s32 d;
    if (target) {
        switch (obj->unk28->unk1) {
        case 0:
            obj->unk1A0 = target->x;
            obj->unk1A4 = target->y;
            break;
        case 1:
            obj->unk1A0 = obj->unk1A4 = -1;
            break;
        case 2:
            if (!fn_800B661C(target, 0)) {
                obj->unk28--;
                return 1;
            }
            break;
        case 3:
            if (!fn_800B66B0(target)) {
                obj->unk28--;
                return 1;
            }
            break;
        case 4:
            d = target->x - obj->unk28->unk4;
            if (d < -0x200) {
                obj->unkF6 = 0x8008;
                obj->unk28--;
                return 1;
            } else if (d > 0x200) {
                obj->unkF6 = 0x8004;
                obj->unk28--;
                return 1;
            }
            target->x = obj->unk28->unk4;
            obj->unkF6 = 0x8000;
            break;
        case 5:
            if (!fn_800B672C(target)) {
                obj->unk28--;
                return 1;
            }
            break;
        case 6:
            if (obj->unk28->unk2) {
                if (!fn_800B66BC(target, 1)) {
                    obj->unk28--;
                    return 1;
                }
            } else {
                if (!fn_800B66BC(target, 0)) {
                    obj->unk28--;
                    return 1;
                }
            }
            break;
        case 7:
            if (!fn_800B6750(target)) {
                obj->unk28--;
                return 1;
            }
            break;
        case 8:
            fn_800B6440(target, obj->unk28->unk4);
            break;
        case 9:
            if (target->y >= lbl_80304B90.unk260 && target->vy > 0) {
                obj->unk1A0 = target->x;
                obj->unk1A4 = lbl_80304B90.unk260;
            } else {
                obj->unk28--;
                return 1;
            }
            break;
        case 10:
            d = target->x - obj->unk28->unk4;
            if (d < -0x200) {
                if (obj->unk1B0 == 0) {
                    if (fn_800A3AE0(fn_800B6104(target) + 0x100, target->y)) {
                        obj->unkF6 = 0x8000;
                        obj->unk1B0 = 0x28;
                    } else obj->unkF6 = 0x8008;
                } else {
                    obj->unkF6 = 0xA008;
                    obj->unk1B0--;
                }
                obj->unk28--;
                return 1;
            } else if (d > 0x200) {
                if (obj->unk1B0 == 0) {
                    if (fn_800A3DBC(fn_800B6104(target) - 0x100, target->y)) {
                        obj->unkF6 = 0x8000;
                        obj->unk1B0 = 0x28;
                    } else obj->unkF6 = 0x8004;
                } else {
                    obj->unkF6 = 0xA004;
                    obj->unk1B0--;
                }
                obj->unk28--;
                return 1;
            }
            target->x = obj->unk28->unk4;
            obj->unk1B0 = 0;
            obj->unkF6 = 0x8000;
            break;
        case 11:
            d = target->x - obj->unk28->unk4;
            if (d < -0x200) {
                if (obj->unk1B0 == 0) {
                    if (target->x < lbl_80304B90.unk25C - 0x3000) {
                        obj->unkF6 = 0x8000;
                        obj->unk1B0 = 0x14;
                    } else obj->unkF6 = 0x8008;
                } else {
                    obj->unkF6 = 0xA008;
                    obj->unk1B0--;
                }
                obj->unk28--;
                return 1;
            } else if (d > 0x200) {
                if (obj->unk1B0 == 0) {
                    if (target->x > lbl_80304B90.unk25C + 0x2FFF) {
                        obj->unkF6 = 0x8000;
                        obj->unk1B0 = 0x14;
                    } else obj->unkF6 = 0x8004;
                } else {
                    obj->unkF6 = 0xA004;
                    obj->unk1B0--;
                }
                obj->unk28--;
                return 1;
            }
            target->x = obj->unk28->unk4;
            obj->unk1B0 = 0;
            obj->unkF6 = 0x8000;
            break;
        case 12:
            if (!fn_800B6750(target) || fn_800B608C(target)) {
                obj->unk28--;
                return 1;
            }
            break;
        }
    }
    return 0;
}
