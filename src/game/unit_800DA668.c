#include "types.h"

typedef struct Unk802819B0Entry {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
} Unk802819B0Entry;

typedef struct Unk800DA668ParentA {
    /* 0x000 */ u8 pad0[0x278];
    /* 0x278 */ u8 unk278[9];
    /* 0x281 */ u8 pad281[0x288 - 0x281];
    /* 0x288 */ u8 unk288;
} Unk800DA668ParentA;

typedef struct Unk800DA668ParentB {
    /* 0x0000 */ u8 pad0[0xFFB];
    /* 0x0FFB */ u8 unkFFB[9];
    /* 0x1004 */ u8 pad1004[0x100A - 0x1004];
    /* 0x100A */ u8 unk100A;
} Unk800DA668ParentB;

typedef struct Unk800DA668 {
    /* 0x00 */ u8 pad0[0x9];
    /* 0x09 */ u8 kind;
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x10 - 0xB];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14;
    /* 0x15 */ u8 slot;
    /* 0x16 */ u8 pad16[0x18 - 0x16];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x34 - 0x1C];
    /* 0x34 */ void* parent;
    /* 0x38 */ u8 pad38[0x8F - 0x38];
    /* 0x8F */ u8 unk8F;
} Unk800DA668;

extern Unk802819B0Entry* lbl_802819B0[];

void fn_800E9750(Unk800DA668* obj, u16 arg1);

static inline void Show(Unk800DA668* obj, u8 v) {
    if (v == 1) {
        obj->flagsA |= 1;
    } else {
        obj->flagsA &= ~1;
    }
}

static inline void Die(Unk800DA668* obj) {
    obj->unk18 = lbl_802819B0[obj->kind]->unk8;
    obj->unk10 = 2;
    obj->state = 0;
    obj->step = 0;
    obj->unk13 = 0;
}

void fn_800DA668(Unk800DA668* obj) {
    Unk800DA668ParentA* pa;
    Unk800DA668ParentB* pb;

    if (obj->unk8F == 0) {
        pa = obj->parent;
        if (pa->unk288 == 1) {
            Die(obj);
            return;
        }
        switch (obj->slot) {
        case 0:
            if (obj->unk8F == 0) {
                Show(obj, pa->unk278[0]);
            }
            break;
        case 1:
            if (obj->unk8F == 0) {
                Show(obj, pa->unk278[1]);
            }
            break;
        case 2:
            if (obj->unk8F == 0) {
                Show(obj, pa->unk278[2]);
            }
            break;
        case 3:
            if (obj->unk8F == 0) {
                Show(obj, pa->unk278[3]);
            }
            break;
        case 4:
            if (obj->unk8F == 0) {
                Show(obj, pa->unk278[4]);
            }
            break;
        case 5:
            if (obj->unk8F == 0) {
                Show(obj, pa->unk278[5]);
            }
            break;
        case 6:
            if (obj->unk8F == 0) {
                Show(obj, pa->unk278[6]);
            }
            break;
        case 7:
            if (obj->unk8F == 0) {
                Show(obj, pa->unk278[7]);
            }
            break;
        case 8:
            if (obj->unk8F == 0) {
                Show(obj, pa->unk278[8]);
            }
            break;
        default:
            if (obj->unk8F == 0) {
                Show(obj, pa->unk278[0]);
            }
            break;
        }
        fn_800E9750(obj, 0xFFFF);
    } else {
        pb = obj->parent;
        if (pb->unk100A == 1) {
            Die(obj);
            return;
        }
        switch (obj->slot) {
        case 0:
            if (obj->unk8F != 0) {
                Show(obj, pb->unkFFB[0]);
            }
            break;
        case 1:
            if (obj->unk8F != 0) {
                Show(obj, pb->unkFFB[1]);
            }
            break;
        case 2:
            if (obj->unk8F != 0) {
                Show(obj, pb->unkFFB[2]);
            }
            break;
        case 3:
            if (obj->unk8F != 0) {
                Show(obj, pb->unkFFB[3]);
            }
            break;
        case 4:
            if (obj->unk8F != 0) {
                Show(obj, pb->unkFFB[4]);
            }
            break;
        case 5:
            if (obj->unk8F != 0) {
                Show(obj, pb->unkFFB[5]);
            }
            break;
        case 6:
            if (obj->unk8F != 0) {
                Show(obj, pb->unkFFB[6]);
            }
            break;
        case 7:
            if (obj->unk8F != 0) {
                Show(obj, pb->unkFFB[7]);
            }
            break;
        case 8:
            if (obj->unk8F != 0) {
                Show(obj, pb->unkFFB[8]);
            }
            break;
        default:
            if (obj->unk8F != 0) {
                Show(obj, pb->unkFFB[0]);
            }
            break;
        }
        fn_800E9750(obj, 0xFFFF);
    }
}
