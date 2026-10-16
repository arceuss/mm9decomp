#include "types.h"

typedef struct Unk8007DAD4Entry {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ u8 pad8[0x14 - 0x8];
} Unk8007DAD4Entry;

typedef struct Unk8007DAD4Table {
    /* 0x0 */ u32 count;
    /* 0x4 */ Unk8007DAD4Entry* entries;
} Unk8007DAD4Table;

typedef struct Unk8007DAD4Obj {
    /* 0x00 */ u8 pad0[0x60];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
} Unk8007DAD4Obj;

typedef struct Unk8007DAD4Vt {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ void (*func)(void* arg);
} Unk8007DAD4Vt;

typedef struct Unk80304B90 {
    /* 0x000 */ void* unk0;
    /* 0x004 */ u8 pad4[0x8 - 0x4];
    /* 0x008 */ Unk8007DAD4Obj* unk8;
    /* 0x00C */ u8 unkC;
    /* 0x00D */ u8 padD[0x10 - 0xD];
    /* 0x010 */ u8 unk10[0x124 - 0x10];
    /* 0x124 */ u8 unk124;
    /* 0x125 */ u8 unk125;
    /* 0x126 */ u8 pad126[0x2D8 - 0x126];
    /* 0x2D8 */ u32 unk2D8;
    /* 0x2DC */ u8 pad2DC[0x300 - 0x2DC];
} Unk80304B90;

extern Unk80304B90 lbl_80304B90;

s32 fn_8007DCF4(void);
s32 fn_80081260(void* arg0);
void fn_80081470(void* arg0);

u32 fn_8007DAD4(void) {
    u32 result = 0;
    Unk80304B90* s = &lbl_80304B90;
    Unk8007DAD4Vt* vt = s->unk0;
    BOOL again = FALSE;
    s32 r;
    Unk8007DAD4Table* table;
    Unk8007DAD4Obj* obj;
    Unk8007DAD4Entry* entry;
    u32 next;

    do {
        if (fn_8007DCF4() == 0) {
            if (!(s->unk125 & 1)) {
                vt->func(s->unk10);
            } else {
                again = TRUE;
            }
        }
        if (!(s->unk125 & 1)) {
            result = s->unk2D8 & 1;
        }
        r = fn_80081260(&s->unk124);
        if (r != 0) {
            result = s->unk2D8 & 1;
        }
        if (r == 0) {
            again = FALSE;
        }
    } while (again);
    table = lbl_80304B90.unk0;
    obj = lbl_80304B90.unk8;
    next = lbl_80304B90.unkC;
    if (next < table->count) {
        next++;
        entry = &table->entries[next];
        if ((u32)(obj->x - entry->x) < 0x10000 && (u32)(obj->y - entry->y) < 0xE000) {
            lbl_80304B90.unkC = next;
        }
    }
    fn_80081470(&lbl_80304B90.unk124);
    return result;
}
