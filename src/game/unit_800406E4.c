#include "game/work_8031BF70.h"

typedef struct Unk80264FC0 {
    /* 0x0 */ u16 weight[8];
} Unk80264FC0;

extern Unk80264FC0 lbl_80264FC0[8];
extern u32 lbl_804EE988;
extern u8 lbl_804ECA10[8];

void fn_8009C308(u8 item, s32 arg1, s32 arg2);

u8 fn_800406E4(s32 kind, s32 arg1) {
    s32 r;
    s32 sum;
    s32 i;
    u8 item;
    u16* w;

    if (kind == 0xFF) {
        return 0xFF;
    }
    if ((lbl_8031BF70.unk28C & 0x7F) == 13) {
        kind = 7;
    }
    lbl_804EE988 = (lbl_804EE988 * 0x343FD + 0x269EC3) & 0x7FFFFFFF;
    r = (lbl_804EE988 >> 16) & 0xFF;
    w = lbl_80264FC0[kind].weight;
    sum = w[0];
    i = 0;
    while (i < 7) {
        if (r < sum) {
            break;
        }
        i++;
        sum += w[i];
    }
    item = lbl_804ECA10[i];
    fn_8009C308(item, arg1, 0);
    return item;
}
