#include "types.h"

typedef struct Unk800810FCObj {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u8 flagsA;
    /* 0x0B */ u8 padB[0x1C - 0xB];
    /* 0x1C */ void* unk1C;
} Unk800810FCObj;

typedef struct Unk800810FCEntry {
    /* 0x0 */ Unk800810FCObj* obj;
    /* 0x4 */ u8 pad4[0x8 - 0x4];
    /* 0x8 */ u8 id;
    /* 0x9 */ u8 unk9;
    /* 0xA */ s16 unkA;
    /* 0xC */ s16 unkC;
    /* 0xE */ s16 unkE;
} Unk800810FCEntry;

typedef struct Unk800810FC {
    /* 0x000 */ u8 pad0[0x2C];
    /* 0x02C */ Unk800810FCEntry entries[12];
    /* 0x0EC */ u8 padEC[0xF5 - 0xEC];
    /* 0x0F5 */ u8 unkF5;
    /* 0x0F6 */ u8 padF6[0x194 - 0xF6];
    /* 0x194 */ s32 unk194;
    /* 0x198 */ u8 pad198[0x19C - 0x198];
    /* 0x19C */ s32 unk19C;
} Unk800810FC;

typedef struct Unk80301308 {
    /* 0x00 */ Unk800810FCObj* unk0;
    /* 0x04 */ u8 pad4[0x18 - 0x4];
} Unk80301308;

extern Unk80301308 lbl_80301308;

void fn_80023F08(void);
void fn_80023FCC(void);
void fn_80024034(void);
void fn_80080BA4(Unk800810FCEntry* entry);

void fn_800810FC(Unk800810FC* p, Unk800810FCObj* obj, s32 arg2) {
    u8 i;

    fn_80023F08();
    lbl_80301308.unk0 = obj;
    fn_80023FCC();
    fn_80024034();
    p->unkF5 = 0;
    p->unk194 = 0;
    p->unk19C = arg2;
    for (i = 0; i < 12; i++) {
        p->entries[i].obj = NULL;
        p->entries[i].unk9 = 0;
        p->entries[i].unkE = 0;
        p->entries[i].unkC = 0;
        p->entries[i].unkA = 0;
        p->entries[i].id = i;
    }
    p->entries[0].obj = obj;
    obj->unk1C = &p->entries[0];
    obj->flagsA |= 0x80;
    fn_80080BA4(&p->entries[0]);
}
