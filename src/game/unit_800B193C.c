#include "types.h"
typedef struct UnkB193C {
    u8 pad0[0x1F8];
    u8 unk1F8;
    u8 pad1F9;
    u8 unk1FA;
    u8 pad1FB;
    u8 unk1FC;
    u8 unk1FD;
    u8 unk1FE;
    u8 unk1FF;
    u8 unk200;
    u8 unk201;
    u8 unk202;
} UnkB193C;
void fn_800B193C(UnkB193C* rec) {
    rec->unk1F8 = 0;
    rec->unk1FC = 0xFF;
    rec->unk200 = 0xFF;
    rec->unk1FD = 0xFF;
    rec->unk201 = 0xFF;
    rec->unk1FA = rec->unk1FA & 0xF8;
    rec->unk1FE = 0xFF;
    rec->unk202 = 0xFF;
}
