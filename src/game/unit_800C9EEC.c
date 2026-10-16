#include "game/anim.h"

/* Best attempt: 97.35%.
 * Residual diff (target | ours):
 *   lhzx r4, r8, r6      | lhzx r0, r8, r6
 *   addi r0, r4, 0x2     | (missing)
 *                        | ... (add folded)
 *   add r4, r0, r8       | add r4, r0, r8
 *   lbz r0, 0x1(r4)      | lbz r0, 0x3(r4)
 * The target materializes (offset + 2) as an intermediate pointer and then loads
 * .unk1 at displacement 1; mwcc folds 2+1 into a single displacement 3 load.
 * Tested ~14 source shapes for the second read; all fold. Believed non-steerable.
 */
void fn_800C9EEC(AnimPlayer* anim, u8 a) {
    u8* data = anim->data;
    s8 c;

    anim->seq = a;
    anim->frame = 0;
    anim->count = data[*(u16*)(data + a * 2) + 1] + 1;
    c = data[*(u16*)(data + a * 2) + 3];
    if (c < 0) {
        if ((s8)anim->count == 2) {
            anim->state = 2;
        } else if ((s8)anim->count == 1) {
            if (c == -1) {
                anim->state = 3;
            } else {
                anim->state = 4;
            }
        } else {
            anim->state = 1;
        }
    } else {
        anim->state = 0;
    }
    anim->unk9 = 0;
}
