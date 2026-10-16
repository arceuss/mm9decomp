#include "game/anim.h"

#define SEQ(a) (*(u16*)((a)->data + (a)->seq * 2))

void fn_800C9F8C(AnimPlayer* a) {
    s8 c;
    u32 f;
    u32 off;
    s8 next;
    u8 cnt;

    a->count--;
    c = a->count;
    if (c == 0) {
        f = a->frame + 1;
        a->frame = f;
        off = (u8)f * 2 + SEQ(a);
        next = (a->data + off)[1];
        if (next == -1) {
            a->frame = (u8)f - 1;
            a->count = 1;
            a->state = 3;
            return;
        }
        if (next == -2) {
            a->frame = a->data[off];
            a->state = 0;
        }
        cnt = a->data[a->frame * 2 + SEQ(a) + 1];
        a->count = cnt;
        a->frame++;
        next = a->data[a->frame * 2 + SEQ(a) + 1];
        if (next < 0) {
            if ((s8)cnt == 2) {
                a->state = 2;
            } else if ((s8)cnt == 1) {
                if (next == -1) {
                    a->state = 3;
                } else {
                    a->state = 4;
                }
            } else {
                a->state = 1;
            }
        }
        a->frame--;
        return;
    }
    if (a->state >= 1) {
        if (c == 2) {
            a->state = 2;
        } else if (c == 1) {
            if ((s8)a->data[(a->frame + 1) * 2 + SEQ(a) + 1] == -1) {
                a->state = 3;
            } else {
                a->state = 4;
            }
        }
    }
}
