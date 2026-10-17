#include "types.h"

typedef struct Unk800AAFB0Ent {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ s32 type;
    /* 0x0C */ char* name;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
} Unk800AAFB0Ent;

typedef struct Unk800AAFB0Name {
    /* 0x00 */ char str[0x50];
} Unk800AAFB0Name;

typedef struct Unk80383E70 {
    /* 0x0000 */ u8 pad0[0x2028];
    /* 0x2028 */ u32 count;
    /* 0x202C */ u32 offs[0x101];
    /* 0x2430 */ Unk800AAFB0Name names[0x100];
} Unk80383E70;

extern Unk80383E70 lbl_80383E70;
extern char lbl_804ECE18[2];
extern u8 lbl_804ECE1C;
extern u8 lbl_804ECE1D;
extern u8 lbl_804ECE1E;
extern u8 lbl_804ECE1F;
extern u32 lbl_8036CF50[];
extern u8 lbl_8026F9B8[];

void OSFatal(void*, void*, void*);
s32 fn_801E2958(const char* path, const char* mode, void* dir);
s32 fn_801E29EC(void* dir, Unk800AAFB0Ent* ent);
s32 fn_801E26B4(const char* path, const char* name, void* info);
u32 fn_801E28C4(void* info);
s32 fn_801E27AC(void* info, u32 dst, u32 size);
void fn_801E28F8(void* info);
s32 fn_801E2A38(void* dir);
s32 fn_800AB27C(s32 err);
char* strcpy(char* dst, const char* src);

static inline void Fatal(void) {
    u32 bg = 0;
    u8 fg[4];

    fg[0] = lbl_804ECE1C;
    fg[1] = lbl_804ECE1D;
    fg[2] = lbl_804ECE1E;
    fg[3] = lbl_804ECE1F;
    OSFatal(fg, &bg, *(void**)(lbl_8026F9B8 + lbl_8036CF50[0] * 0x24 + 0x10));
}

static inline s32 Check(s32 r) {
    switch (r) {
    case -0x1395:
        {
            u32 bg = 0;
            u8 fg[4];

            fg[0] = lbl_804ECE1C;
            fg[1] = lbl_804ECE1D;
            fg[2] = lbl_804ECE1E;
            fg[3] = lbl_804ECE1F;
            OSFatal(fg, &bg, *(void**)(lbl_8026F9B8 + lbl_8036CF50[0] * 0x24 + 0x10));
        }
        break;
    case -0x1394:
        {
            u32 bg = 0;
            u8 fg[4];

            fg[0] = lbl_804ECE1C;
            fg[1] = lbl_804ECE1D;
            fg[2] = lbl_804ECE1E;
            fg[3] = lbl_804ECE1F;
            OSFatal(fg, &bg, *(void**)(lbl_8026F9B8 + lbl_8036CF50[0] * 0x24 + 0x10));
        }
        break;
    default:
        return fn_800AB27C(r);
    }
    return -1;
}

void fn_800AAFB0(const char* path, s32 check) {
    u8 info[0x48];
    u8 dir[0x14];
    Unk800AAFB0Ent ent;
    u32 n;
    u32 off;
    s32 r;
    s32 size;

    if (fn_801E2958(path, lbl_804ECE18, dir) == 0) {
        return;
    }
    n = lbl_80383E70.count;
    off = lbl_80383E70.offs[n];
    for (;;) {
        if (fn_801E29EC(dir, &ent) == 0) {
            break;
        }
        if (ent.type != 0) {
            continue;
        }
        if (n + 1 >= 0x100) {
            return;
        }
        r = fn_801E26B4(path, ent.name, info);
        if (check) {
            if (Check(r) != -1) {
            } else {
                break;
            }
        } else if (fn_800AB27C(r) == -1) {
            break;
        }
        if ((r = (fn_801E28C4(info) + 0x1F) & ~0x1F) != 0) {
            size = fn_801E27AC(info, off, r);
        } else {
            size = 0;
        }
        fn_801E28F8(info);
        if (check) {
            if (Check(size) != -1) {
            } else {
                break;
            }
        } else if (fn_800AB27C(size) == -1) {
            break;
        }
        strcpy(lbl_80383E70.names[n].str, ent.name);
        lbl_80383E70.offs[n] = off;
        off += (size + 0x1F) & ~0x1F;
        n++;
    }
    lbl_80383E70.count = n;
    lbl_80383E70.offs[n] = off;
    if (fn_801E2A38(dir)) {
        return;
    }
}
