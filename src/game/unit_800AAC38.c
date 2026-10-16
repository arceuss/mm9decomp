#include "types.h"

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3008];
    /* 0x3008 */ u8* unk3008;
} Unk80316D78;

typedef struct Unk800AAC38File {
    /* 0x00 */ u8 data[0x50];
} Unk800AAC38File;

extern Unk80316D78 lbl_80316D78;

s32 fn_801E26B4(void* cnt, const char* path, Unk800AAC38File* file);
u32 fn_801E28C4(Unk800AAC38File* file);
s32 fn_801E27AC(Unk800AAC38File* file, void* dst, u32 size);
s32 fn_801E28F8(Unk800AAC38File* file);
s32 fn_800AB27C(s32 result);
void DCFlushRange(void* addr, u32 size);
s32 fn_801209D8(void* src);
void fn_80120A18(void* src, void* dst);
void fn_80120B58(void* src, void* dst);

s32 fn_800AAC38(void* cnt, const char* path, void* dst, u32 mode) {
    Unk800AAC38File file;
    s32 size;
    u8* buf;
    s32 ret;

    if (mode != 0) {
        buf = lbl_80316D78.unk3008 + 0x2819000;
    } else {
        buf = dst;
    }
    ret = fn_801E26B4(cnt, path, &file);
    if (fn_800AB27C(ret) == -1) {
        return ret;
    }
    size = fn_801E27AC(&file, buf, (fn_801E28C4(&file) + 31) & ~31);
    if (fn_800AB27C(size) == -1) {
        return size;
    }
    ret = fn_801E28F8(&file);
    if (fn_800AB27C(ret) == -1) {
        return ret;
    }
    DCFlushRange(buf, size);
    if (mode == 1) {
        size = fn_801209D8(buf);
        fn_80120A18(buf, dst);
        DCFlushRange(dst, size);
    } else if (mode == 2) {
        size = fn_801209D8(buf);
        fn_80120B58(buf, dst);
        DCFlushRange(dst, size);
    }
    return size;
}
