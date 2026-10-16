#include "types.h"

typedef struct Unk8038E738Player {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5_hi : 4;
    /* 0x05 */ u8 unk5_lo : 4;
    /* 0x06 */ u8 pad6[0x8 - 0x6];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u8 state;
    /* 0x0D */ u8 step;
    /* 0x0E */ u8 unkE;
    /* 0x0F */ u8 unkF;
    /* 0x10 */ u8 pad10[0x17 - 0x10];
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8* data;
    /* 0x1C */ u8* cur;
    /* 0x20 */ u8* unk20;
    /* 0x24 */ u8* unk24;
} Unk8038E738Player;

typedef struct Unk8038E738 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ Unk8038E738Player player;
    /* 0x30 */ u8 pad30[0x88 - 0x30];
} Unk8038E738;

typedef struct Unk8038E3A8 {
    /* 0x000 */ u8 pad0[0x36C];
    /* 0x36C */ s32 unk36C[1][2];
} Unk8038E3A8;

extern Unk8038E738 lbl_8038E738;
extern Unk8038E3A8 lbl_8038E3A8;

u8* fn_800A5DE0(s32 kind, s32 id);
void fn_800A5D34(s32 arg0);
void fn_800E5AEC(Unk8038E738Player* player);

static inline void LoadBank(s32 bank) {
    fn_800A5D34(lbl_8038E3A8.unk36C[bank][lbl_8038E738.unk4]);
}

void fn_800E5910(u16 id) {
    Unk8038E738Player* player = &lbl_8038E738.player;
    u32 bank = (id >> 10) & 0x3F;

    if (bank == 0) {
        player->data = fn_800A5DE0(0, id & 0x3FF);
    } else {
        LoadBank(bank - 1);
        player->data = fn_800A5DE0(1, id & 0x3FF);
    }
    player->unk8 = 0;
    player->unk0 = 0;
    player->unk2 = 1;
    player->unk5_hi = 0;
    player->unk5_lo = 0;
    player->unk17 = 0;
    player->unk4 = 0;
    player->cur = player->data;
    player->unk20 = 0;
    player->unk24 = 0;
    fn_800E5AEC(player);
    player->state = 1;
    player->step = 0;
    player->unkE = 0;
    player->unkF = 0;
}
