#include "types.h"

typedef struct Unk80083CF8 {
    /* 0x000 */ u8 pad0[0x414];
    /* 0x414 */ u16 size;
} Unk80083CF8;

typedef struct Unk80083CF8Info {
    /* 0x00 */ u8 height;
    /* 0x01 */ u8 pad1[0x10 - 0x1];
} Unk80083CF8Info;

typedef struct Unk80083CF8Glyph {
    /* 0x00 */ u8 pad0[0x6];
    /* 0x06 */ s8 advance;
    /* 0x07 */ u8 pad7[0x10 - 0x7];
} Unk80083CF8Glyph;

void fn_801E1E2C(void* font, Unk80083CF8Info* info);
s32 fn_801E1E98(void* font);
void* fn_801E1D24(void* font, void* text, Unk80083CF8Glyph* glyph);

s32 fn_80083CF8(Unk80083CF8* obj, void* font, void* text) {
    Unk80083CF8Glyph glyph;
    Unk80083CF8Info info;
    BOOL wide = FALSE;
    s32 width;

    fn_801E1E2C(font, &info);
    if (fn_801E1E98(font) == 1) {
        wide = TRUE;
    }
    width = 0;
    if (!wide) {
        while (*(s8*)text != 0 && *(s8*)text != '\n') {
            text = fn_801E1D24(font, text, &glyph);
            width += glyph.advance * obj->size / info.height;
        }
    } else {
        while (*(u16*)text != 0 && *(u16*)text != '\n') {
            text = fn_801E1D24(font, text, &glyph);
            width += glyph.advance * obj->size / info.height;
        }
    }
    return width;
}
