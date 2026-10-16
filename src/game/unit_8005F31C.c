#include "types.h"
typedef struct Unk8005F31C {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ s8 unk08;
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 pad0A[7];
    /* 0x11 */ u8 unk11;
} Unk8005F31C;
typedef void (*Unk8005F31CFunc)(Unk8005F31C*);
typedef struct Unk8005F31CData {
    /* 0x00 */ u8 pad00[0x14];
    /* 0x14 */ Unk8005F31CFunc unk14[3];
    /* 0x20 */ Unk8005F31CFunc unk20[3];
    /* 0x2C */ Unk8005F31CFunc unk2C[5];
} Unk8005F31CData;
extern u8 lbl_803051D8[];
extern Unk8005F31CData lbl_80267338;
extern void fn_80042D30(Unk8005F31C*);
extern u8 fn_8005FA68(Unk8005F31C*);
extern void fn_800C7C24(s32, s32, s32);
void fn_8005F31C(Unk8005F31C* p) {
    Unk8005F31CData* data = &lbl_80267338;
    if (lbl_803051D8[2] & 0x20) { fn_80042D30(p); return; }
    if (fn_8005FA68(p)) {
        fn_800C7C24(p->unk08, p->unk09, 0);
        data->unk2C[p->unk11](p);
    } else {
        data->unk14[p->unk11](p);
        data->unk20[p->unk11](p);
    }
}
