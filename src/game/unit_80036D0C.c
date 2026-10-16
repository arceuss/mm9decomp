#include "types.h"
#include "game/sound.h"

typedef struct Unk80036D0C {
    /* 0x000 */ u8 pad0[0x272];
    /* 0x272 */ s8 col;
    /* 0x273 */ s8 row;
    /* 0x274 */ u8 area;
} Unk80036D0C;

typedef struct Unk80319DA0 {
    /* 0x000 */ u8 pad0[0x864];
    /* 0x864 */ u16 unk864;
} Unk80319DA0;

extern Unk80319DA0 lbl_80319DA0;

void fn_800D5234(s32 id);
void fn_8003714C(Unk80036D0C* menu);

void fn_80036D0C(Unk80036D0C* menu) {
    if (lbl_80319DA0.unk864 & 1) {
        if ((s8)menu->area == 0 || (u8)(menu->area - 5) <= 1) {
            menu->row--;
            if ((s8)menu->row < 0) {
                menu->row = 7;
                fn_800D5234(SE_CURSOR);
            } else {
                fn_800D5234(SE_CURSOR);
            }
        } else {
            fn_800D5234(SE_CURSOR);
            if ((s8)menu->area == 1) {
                menu->row = 7;
            } else if ((s8)menu->area == 2) {
                menu->row = 0;
            } else if ((s8)menu->area == 3) {
                menu->row = 3;
            }
        }
    } else if (lbl_80319DA0.unk864 & 2) {
        if ((s8)menu->area == 0 || (u8)(menu->area - 5) <= 1) {
            menu->row++;
            if ((s8)menu->row > 7) {
                menu->row = 0;
                fn_800D5234(SE_CURSOR);
            } else {
                fn_800D5234(SE_CURSOR);
            }
        } else {
            fn_800D5234(SE_CURSOR);
            if ((s8)menu->area == 1) {
                menu->row = 3;
            } else if ((s8)menu->area == 2) {
                menu->row = 7;
            } else if ((s8)menu->area == 3) {
                menu->row = 0;
            }
        }
    }
    if (lbl_80319DA0.unk864 & 4) {
        switch (menu->area) {
        case 0:
        case 1:
        case 2:
        case 3:
            menu->col--;
            if ((s8)menu->col < 0) {
                menu->col = 0xB;
                fn_800D5234(SE_CURSOR);
            } else {
                fn_800D5234(SE_CURSOR);
            }
            break;
        case 5:
            fn_800D5234(SE_CURSOR);
            menu->col = 6;
            break;
        case 6:
            fn_800D5234(SE_CURSOR);
            menu->col = 7;
            break;
        }
    } else if (lbl_80319DA0.unk864 & 8) {
        switch (menu->area) {
        case 0:
        case 1:
        case 2:
        case 3:
            menu->col++;
            if ((s8)menu->col > 0xB) {
                menu->col = 0;
                fn_800D5234(SE_CURSOR);
            } else {
                fn_800D5234(SE_CURSOR);
            }
            break;
        case 5:
            fn_800D5234(SE_CURSOR);
            menu->col = 0xA;
            break;
        case 6:
            fn_800D5234(SE_CURSOR);
            menu->col = 0xB;
            break;
        }
    }
    fn_8003714C(menu);
}
