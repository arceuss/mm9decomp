#include "types.h"

extern u8 lbl_80305210[];
extern u8 lbl_803BB320[];

typedef struct Node {
    /* 0x0 */ u8 pad0[4];
    /* 0x4 */ struct Node* next;
    /* 0x8 */ u32 unk8;
} Node;

void fn_801108E4(void);
void fn_801104A4(s32, s32);
void fn_80110918(s32, s32, s32, s32, s32);
void fn_80114580(s32, s32, s32, s32);
void fn_80114628(s32, s32, s32);
void fn_80083930(Node*, u32);
void fn_80083E08(Node*, u32);

void fn_80083730(void) {
    Node* n;
    u32 arg;

    fn_801108E4();
    fn_801104A4(9, 1);
    fn_80110918(0, 9, 1, 3, 0);
    fn_801104A4(0xD, 1);
    fn_80110918(0, 0xD, 1, 3, 0xC);
    fn_80114580(1, 4, 5, 0);
    fn_80114628(1, 3, 1);
    arg = *(u32*)(lbl_803BB320 + 0xC);
    n = *(Node**)(lbl_80305210 + 0x20);
    while (n != (Node*)(lbl_80305210 + 0x1C)) {
        if (n->unk8 == 0) {
            fn_80083930(n, arg);
        } else {
            fn_80083E08(n, arg);
        }
        n = n->next;
    }
}
