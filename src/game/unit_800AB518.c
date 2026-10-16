#include "types.h"

typedef struct Unk800AB518Date {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ s32 mday;
    /* 0x10 */ s32 mon;
    /* 0x14 */ s32 year;
    /* 0x18 */ u8 pad18[0x28 - 0x18];
} Unk800AB518Date;

void fn_800F9130(s64 ticks, Unk800AB518Date* out);

BOOL fn_800AB518(s64 ta, s64 tb) {
    Unk800AB518Date a;
    Unk800AB518Date b;

    fn_800F9130(ta, &a);
    fn_800F9130(tb, &b);
    if (a.year == b.year && a.mon == b.mon && a.mday == b.mday) {
        return TRUE;
    }
    return FALSE;
}
