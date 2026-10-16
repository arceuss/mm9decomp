#include "types.h"

void fn_800BA51C();
void fn_800BA464(u8* obj);
void fn_80024058(s32 v);
void fn_800B5894(u8* obj, u32 idx);

int fn_800B5F90(u8* obj, u32 a) {
    fn_800BA51C();
    fn_800B5894(obj, a);
    if (obj[0x101] == 0xE) {
        obj[0x101] = 0xFF;
    }
    fn_800BA464(obj);
    fn_80024058(0);
    return a != obj[0x10C];
}
