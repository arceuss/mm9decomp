#include "types.h"

typedef struct Unk80019074Node {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ struct Unk80019074Node* next;
    /* 0x08 */ u8 pad8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 padA[0x14 - 0xA];
    /* 0x14 */ u8 unk14;
} Unk80019074Node;

typedef struct Unk80019074List {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ Unk80019074Node* iter;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ Unk80019074Node head;
} Unk80019074List;

typedef struct Unk80019074 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x12 - 0xB];
    /* 0x12 */ u8 step;
    /* 0x13 */ u8 shot;
    /* 0x14 */ u8 pad14[0x16 - 0x14];
    /* 0x16 */ u8 timer;
    /* 0x17 */ u8 left;
    /* 0x18 */ u8 pad18[0x54 - 0x18];
    /* 0x54 */ u32 unk54_hi : 21;
    /* 0x54 */ u32 flipX : 1;
    /* 0x54 */ u32 unk54_lo : 10;
    /* 0x58 */ u8 pad58[0x60 - 0x58];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
    /* 0x68 */ u8 pad68[0x7C - 0x68];
    /* 0x7C */ u8 unk7C;
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 pad7E[0x88 - 0x7E];
    /* 0x88 */ u8 unk88[0x10];
} Unk80019074;

extern Unk80019074List* lbl_804EE810;
extern Unk80019074* lbl_804EE984;
extern void* lbl_80262960[4];

void fn_800E946C(Unk80019074* obj, u8 anim);
void fn_800E8BD0(Unk80019074List* list);
void fn_800195F0(Unk80019074* obj);
void fn_8009996C(void* arg0, void* arg1);
void fn_800D5234(s32 se);
void fn_80079B44(Unk80019074* obj, s32 x, s32 y);
void fn_800E9750(Unk80019074* obj, u16 arg1);

void fn_80019074(Unk80019074* obj) {
    u8 count;
    Unk80019074Node* saved;
    Unk80019074Node* node;
    s32 d;

    switch (obj->step) {
    case 0:
        fn_800E946C(obj, 1);
        obj->timer = 0x28;
        count = 0;
        saved = lbl_804EE810->iter;
        fn_800E8BD0(lbl_804EE810);
        while ((node = lbl_804EE810->iter = lbl_804EE810->iter->next) != &lbl_804EE810->head) {
            if (node->unk9 == 0xC && node->unk14 == 0) {
                count++;
            }
        }
        lbl_804EE810->iter = saved;
        obj->left = 2 - count;
        if (obj->left == 0) {
            fn_800195F0(obj);
            break;
        }
        d = lbl_804EE984->x - obj->x;
        obj->flipX = (u32)(-d & ~d) >> 31;
        if (obj->flipX) {
            obj->flagsA |= 0x10;
        } else {
            obj->flagsA &= 0xEF;
        }
        obj->shot = 0;
        obj->step++;
    case 1:
        if (obj->unk7D >= 1 && obj->shot == 0) {
            fn_8009996C(obj->unk88, lbl_80262960[obj->unk7C]);
            obj->shot++;
        }
        if (obj->timer == 0) {
            if (obj->left == 0) {
                obj->step++;
                break;
            }
            if (--obj->left != 0) {
                fn_800E946C(obj, 1);
            } else {
                fn_800E946C(obj, 0);
                fn_8009996C(obj->unk88, lbl_80262960[obj->unk7C]);
            }
            fn_800D5234(0x55);
            obj->timer = 0x28;
            fn_80079B44(obj, obj->x + (((obj->flagsA >> 3) & 2) - 1) * 0x1E00, obj->y - 0x1100);
        } else {
            obj->timer--;
        }
        break;
    case 2:
        fn_800E946C(obj, 0);
        fn_8009996C(obj->unk88, lbl_80262960[obj->unk7C]);
        obj->timer = 0x18;
        obj->step++;
    case 3:
        if (obj->timer == 0) {
            fn_800195F0(obj);
        } else {
            obj->timer--;
        }
        break;
    }
    fn_800E9750(obj, 0xFFFF);
}
