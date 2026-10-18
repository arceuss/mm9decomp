#include "types.h"

typedef struct Unk800A82DCEntryA {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u8 live:1;
    u8 rest8:7;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u32 unkC;
} Unk800A82DCEntryA;

typedef struct Unk800A82DCEntryB {
    u16 unk0;
    u16 unk2;
    u8 type:1;
    u8 live:1;
    u8 rest4:6;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 pad9[3];
    u32 unkC;
} Unk800A82DCEntryB;

typedef struct Unk800A82DC {
    s8 unk0;
    s8 unk1;
    u16 unk2;
    u8 unk4;
    u8 unk5;
    u8 pad6[4];
    u8 unkA;
    u8 unkB;
    u16 unkC;
    u8 padE[2];
    Unk800A82DCEntryA a[96];
    Unk800A82DCEntryB b[96];
    u8 mapA[640];
    u8 mapB[640];
} Unk800A82DC;

void fn_800A82DC(Unk800A82DC* obj) {
    s32 i;
    s32 n;
    s32 j;
    n = 0;
    for (i = 0; i < obj->unk0; i++) {
        if (obj->a[i].live) {
            obj->a[n] = obj->a[i];
            obj->mapA[obj->a[n].unk0] = n;
            n++;
        } else {
            obj->mapA[obj->a[i].unk0] = 0xFF;
        }
    }
    obj->unk0 = n;
    obj->unk2 = 0;
    for (i = 0; i < obj->unk0; i++) {
        obj->a[i].unk2 = obj->unk2;
        obj->unk2 += obj->a[i].unk4;
    }
    obj->unkC = obj->unk2;
    n = 0;
    for (i = 0; i < obj->unk1; i++) {
        if (obj->b[i].live) {
            obj->b[n] = obj->b[i];
            obj->mapB[obj->b[n].unk0] = n;
            n++;
        } else {
            for (j = 0; j < 640; j++) {
                if (obj->mapB[j] == i) obj->mapB[j] = 0xFF;
            }
        }
    }
    obj->unk1 = n;
    obj->unk4 = 0;
    obj->unk5 = 0;
    for (i = 0; i < obj->unk1; i++) {
        if (!obj->b[i].type) {
            obj->b[i].unk8 = obj->unk4;
            obj->unk4 += obj->b[i].unk7;
        } else {
            obj->b[i].unk8 = obj->unk5;
            obj->unk5 += obj->b[i].unk7;
        }
    }
    obj->unkA = obj->unk4;
    obj->unkB = obj->unk5;
    for (i = 64; i < 96; i++) {
        obj->a[i].unkC = 0;
        obj->a[i].unkA = 0xFF;
        obj->a[i].unk9 = 0xFF;
    }
    for (i = 64; i < 96; i++) {
        obj->b[i].unkC = 0;
        obj->b[i].unk6 = 0xFF;
        obj->b[i].unk5 = 0xFF;
    }
}
