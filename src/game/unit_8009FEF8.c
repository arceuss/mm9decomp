#include "types.h"
#include "game/work_8031BF70.h"

typedef struct Unk8009FEF8Player {
    /* 0x00 */ u8 pad0[0x60];
    /* 0x60 */ s32 x;
    /* 0x64 */ s32 y;
} Unk8009FEF8Player;

typedef struct Unk8038B2F8 {
    /* 0x0000 */ u8 pad0[0x26BC];
    /* 0x26BC */ s16 unk26BC;
    /* 0x26BE */ u8 pad26BE[0x26C0 - 0x26BE];
} Unk8038B2F8;

extern Unk8038B2F8 lbl_8038B2F8;
extern Unk8009FEF8Player* lbl_804EE984;

u16 fn_8009E850(s32 x, s32 y);

void fn_8009FEF8(void) {
    s32 width = lbl_8031BF70.unk288->unk10[2] << 16;
    s32 height = lbl_8031BF70.unk288->unk10[3] * 0xE000;
    s32 x;
    s32 y;

    lbl_8038B2F8.unk26BC = 0;
    for (y = 0; y < height; y += 0x1000) {
        for (x = 0; x < width; x += 0x1000) {
            if (fn_8009E850(x, y) == 7) {
                lbl_804EE984->x = x + 0x800;
                lbl_804EE984->y = y;
                return;
            }
        }
    }
}
