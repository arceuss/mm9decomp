#include "types.h"

typedef struct Unk80036FBC {
    /* 0x000 */ u8 pad0[0x26D];
    /* 0x26D */ u8 page;
    /* 0x26E */ u8 unk26E;
    /* 0x26F */ u8 unk26F;
    /* 0x270 */ u8 pad270;
    /* 0x271 */ u8 unk271;
    /* 0x272 */ u8 unk272;
    /* 0x273 */ u8 unk273;
    /* 0x274 */ s8 cursor;
    /* 0x275 */ u8 shownPage;
    /* 0x276 */ u8 pad276;
    /* 0x277 */ u8 result;
    /* 0x278 */ u8 pad278[0x282 - 0x278];
    /* 0x282 */ u8 unk282;
} Unk80036FBC;

typedef struct Unk80319DA0 {
    /* 0x000 */ u8 pad0[0x860];
    /* 0x860 */ u32 trig;
} Unk80319DA0;

extern Unk80319DA0 lbl_80319DA0;

void fn_800D5234(s32 se);

void fn_80036FBC(Unk80036FBC* obj) {
    if (lbl_80319DA0.trig & 0x10) {
        switch (obj->cursor) {
        case 1:
            fn_800D5234(10);
            if (++obj->page > 1) {
                obj->page = 0;
            }
            goto show;
        case 2:
            fn_800D5234(10);
            obj->page = 2;
        show:
            if (obj->shownPage != obj->page) {
                obj->shownPage = obj->page;
                obj->unk26E = 0;
                obj->unk26F = 1;
                obj->unk271 = 0;
            }
            break;
        case 5:
            fn_800D5234(10);
            obj->result = 3;
            break;
        case 0:
            fn_800D5234(10);
            obj->result = 1;
            break;
        case 6:
            fn_800D5234(10);
            obj->result = 4;
            break;
        case 3:
            if (obj->unk282 == 1) {
                obj->unk271 = 0;
                obj->result = 5;
            }
            break;
        }
    } else if (lbl_80319DA0.trig & 0x20) {
        obj->result = 2;
    } else if (lbl_80319DA0.trig & 0x40) {
        if (obj->cursor != 3) {
            obj->cursor = 3;
            obj->unk272 = 0xB;
            obj->unk273 = 5;
            fn_800D5234(0);
        }
    } else {
        obj->result = 0;
    }
}
