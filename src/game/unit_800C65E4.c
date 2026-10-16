#include "types.h"

typedef struct Unk8038DC58 {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4[0x90 - 0x4];
    /* 0x90 */ u8 unk90[0x128 - 0x90];
} Unk8038DC58;

extern Unk8038DC58 lbl_8038DC58;

void fn_8009C100(void* src, void* dst, s32 size);

void fn_800C65E4(void* src) {
    fn_8009C100(src, lbl_8038DC58.unk90, 0x64);
    fn_8009C100(lbl_8038DC58.unk90, lbl_8038DC58.unk4, 8);
    lbl_8038DC58.unk0 = 0xFF;
    lbl_8038DC58.unk1 = 0xFF;
    lbl_8038DC58.unk2 = 0;
    lbl_8038DC58.unk3 = 0;
}
