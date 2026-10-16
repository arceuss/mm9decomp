#include "types.h"

extern char lbl_804EC698[2];

void fn_8000E91C(void);
s32 fn_8011CEE8(void*, s32, s32);
char* strcpy(char*, const char*);
void fn_80175294(void*, void*);
u32 fn_8011B5D4(void*, void*, s32);
u32 fn_8011B044(void*, u32*);
u32 fn_8011B854(void*);

s32 fn_8000E79C(s32 a1, s32 a2, s32 a3) {
    char buf[0x40] = {0};
    u8 file[0x90];
    u32 x = 0;
    s32 r;

    r = fn_8011CEE8(buf, a2, a3);
    if (r != 0) {
        fn_8000E91C();
        return -1;
    }
    strcpy((char*)a1 + 0xF0C0, buf);
    fn_80175294(buf, lbl_804EC698);
    fn_80175294(buf, (void*)a2);
    r = fn_8011B5D4(buf, file, 1);
    if (r != 0) {
        fn_8000E91C();
    } else {
        r = fn_8011B044(file, &x);
        if (r != 0) {
            fn_8000E91C();
            fn_8011B854(file);
        } else {
            r = fn_8011B854(file);
            if (r != 0) {
                fn_8000E91C();
            }
        }
    }
    if (r == 0) {
        if (x == (u32)a3) {
            r = 0;
        } else {
            r = 2;
        }
    } else if (r == -0xc) {
        r = 1;
    } else {
        r = -1;
    }
    return r;
}
