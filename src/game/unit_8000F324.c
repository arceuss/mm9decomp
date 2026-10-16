#include "types.h"

typedef struct Unk8000F324 {
    /* 0x00 */ u8 pad00[0x11];
    /* 0x11 */ u8 unk11;
} Unk8000F324;

typedef void (*Unk8000F324Func)(Unk8000F324*);

extern Unk8000F324Func lbl_80261E68[];
extern Unk8000F324Func lbl_80261E84[];

void fn_800C75D0(Unk8000F324*);

void fn_8000F324(Unk8000F324* o) {
    if (o->unk11 != 0 && o->unk11 != 2 && o->unk11 != 4) {
        fn_800C75D0(o);
    }
    lbl_80261E68[o->unk11](o);
    lbl_80261E84[o->unk11](o);
}
