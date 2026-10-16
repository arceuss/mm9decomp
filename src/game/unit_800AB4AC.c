#include "types.h"

typedef struct Unk804EE898 {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
    /* 0x6 */ u8 pad6;
    /* 0x7 */ u8 unk7;
} Unk804EE898;

extern Unk804EE898 lbl_804EE898;

u32 SCCheckStatus(void);
u8 SCGetLanguage(void);
u8 fn_8011FBB4(void);
u8 fn_8011FC7C(void);
u8 fn_8011FD54(void);
u8 fn_8011FDFC(void);
u8 fn_801201A4(void);
u8 fn_801201E4(void);

void fn_800AB4AC(void) {
    while (SCCheckStatus() == 1) {
    }
    lbl_804EE898.unk0 = fn_8011FBB4();
    lbl_804EE898.unk1 = fn_8011FC7C();
    lbl_804EE898.unk3 = SCGetLanguage();
    lbl_804EE898.unk2 = fn_8011FD54();
    lbl_804EE898.unk4 = fn_8011FDFC();
    lbl_804EE898.unk5 = fn_801201A4();
    lbl_804EE898.unk7 = fn_801201E4();
}
