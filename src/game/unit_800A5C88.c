#include "types.h"

typedef struct Unk8036CF50 {
    /* 0x0000 */ u8 pad0[0x97A8];
    /* 0x97A8 */ u8 unk97A8[0xEFA8 - 0x97A8];
    /* 0xEFA8 */ u32 unkEFA8;
    /* 0xEFAC */ u16* unkEFAC[2];
    /* 0xEFB4 */ u8* unkEFB4[2];
    /* 0xEFBC */ u8 padEFBC[0xEFE0 - 0xEFBC];
} Unk8036CF50;

extern Unk8036CF50 lbl_8036CF50;

typedef struct Unk800A5C88Header {
    /* 0x0 */ u16 size;
    /* 0x2 */ u16 offset;
} Unk800A5C88Header;

void fn_800AA9AC(u32 id, void* dst, u32 size, u32 offset);

void fn_800A5C88(u32 id) {
    Unk800A5C88Header header;
    BOOL load = FALSE;

    if (lbl_8036CF50.unkEFA8 != id) {
        load = TRUE;
    }
    if (load) {
        fn_800AA9AC(id, &header, sizeof(header), 0);
        fn_800AA9AC(id, lbl_8036CF50.unk97A8, header.size, 4);
        lbl_8036CF50.unkEFAC[1] = (u16*)lbl_8036CF50.unk97A8;
        lbl_8036CF50.unkEFB4[1] = lbl_8036CF50.unk97A8 + header.offset;
        lbl_8036CF50.unkEFA8 = id;
    }
}
