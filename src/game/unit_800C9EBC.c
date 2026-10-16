#include "game/anim.h"

void fn_800C9EBC(AnimPlayer* anim, u8* data) {
    anim->data = data;
    anim->seq = 0;
    anim->frame = 0;
    anim->count = data[*(u16*)data + 1] + 1;
    anim->state = 0;
    anim->unk9 = 0;
}
