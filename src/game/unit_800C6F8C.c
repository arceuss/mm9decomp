#include "types.h"

typedef struct Unk8038DC58 {
    /* 0x00 */ u8 pad0[0x90];
    /* 0x90 */ u8 unk90[0x9D - 0x90];
    /* 0x9D */ u8 unk9D;
    /* 0x9E */ u8 unk9E;
    /* 0x9F */ u8 unk9F;
    /* 0xA0 */ u8 padA0[0xC8 - 0xA0];
    /* 0xC8 */ s64 last;
} Unk8038DC58;

typedef struct Unk803140C0 {
    /* 0x0000 */ u8 pad0[0x227C];
    /* 0x227C */ u8 unk227C;
} Unk803140C0;

extern Unk803140C0 lbl_803140C0;
extern Unk8038DC58 lbl_8038DC58;

s64 OSGetTime(void);
s32 fn_800AB518(s64 a, s64 b);
u8 fn_800C675C(s32 a);
void fn_800E5598(void* a);

#define OS_BUS_CLOCK (*(u32*)0x800000F8)
#define OS_TIMER_CLOCK (OS_BUS_CLOCK / 4)

void fn_800C6F8C(void) {
    s64 now;
    s64 t;
    u8 d;
    u8 e;
    s32 i;

    if (lbl_803140C0.unk227C != 0) {
        return;
    }
    now = OSGetTime();
    t = 0;
    t += lbl_8038DC58.last;
    d = lbl_8038DC58.unk9D;
    if (fn_800AB518(t, now)) {
        if (d <= 4) {
            d++;
        }
    } else {
        d = 0;
    }
    lbl_8038DC58.unk9D = d;
    if (!fn_800AB518(t, now)) {
        e = lbl_8038DC58.unk9E;
        for (i = 0; i < 86400; i++) {
            t += OS_TIMER_CLOCK;
        }
        if (fn_800AB518(t, now)) {
            if (e <= 2) {
                e++;
            }
        } else {
            e = 0;
        }
        lbl_8038DC58.unk9E = e;
    }
    lbl_8038DC58.last = now;
    d = lbl_8038DC58.unk9F;
    if (d <= 0x1D) {
        d++;
    }
    lbl_8038DC58.unk9F = d;
    if (!fn_800C675C(1)) {
        fn_800E5598(lbl_8038DC58.unk90);
    }
}
