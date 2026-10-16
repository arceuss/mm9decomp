#include "types.h"

typedef struct Vec2i {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
} Vec2i;

typedef struct Unk800999FCFrame {
    /* 0x00 */ u8 layer;
    /* 0x01 */ u8 prio;
    /* 0x02 */ u8 pad2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[0x8 - 0x4];
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 pad9[0xB - 0x9];
    /* 0x0B */ u8 more;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ s16 x;
    /* 0x12 */ s16 y;
    /* 0x14 */ u16 w;
    /* 0x16 */ u16 h;
} Unk800999FCFrame;

typedef struct Unk800999FC {
    /* 0x00 */ Unk800999FCFrame* frame;
    /* 0x04 */ u8 pad4[0x8 - 0x4];
    /* 0x08 */ Vec2i* pos;
    /* 0x0C */ u8 padC[0x18 - 0xC];
    /* 0x18 */ void* unk18;
    /* 0x1C */ void* unk1C;
    /* 0x20 */ u8 unk20;
} Unk800999FC;

typedef struct Unk80316398Entry {
    /* 0x00 */ struct Unk80316398Entry* next;
    /* 0x04 */ Unk800999FCFrame* frame;
    /* 0x08 */ Unk800999FC* sprite;
    /* 0x0C */ s32 x;
    /* 0x10 */ s32 y;
    /* 0x14 */ u16 w;
    /* 0x16 */ u16 h;
} Unk80316398Entry;

typedef struct Unk80316398 {
    /* 0x000 */ u8 pad0[0x3];
    /* 0x003 */ u8 count;
    /* 0x004 */ Unk80316398Entry entries[0x60];
    /* 0x904 */ Unk80316398Entry* lists[1][3];
} Unk80316398;

extern Unk80316398 lbl_80316398;

void fn_800999FC(Unk800999FC* sprite) {
    Unk800999FCFrame* frame = sprite->frame;
    Vec2i* pos = sprite->pos;
    Unk80316398Entry* entry;

    if (sprite->unk20 & 0x7F) {
        sprite->unk20 = (sprite->unk20 & 0x80) | ((sprite->unk20 & 0x7F) - 1);
    }
    if (frame == NULL) {
        return;
    }
    if (frame->unk3 == 0 && frame->unk8 == 0) {
        sprite->unk1C = sprite->unk18;
        sprite->unk18 = NULL;
        return;
    }
    {
        for (;;) {
            if (lbl_80316398.count >= 0x60) {
                break;
            }
            entry = &lbl_80316398.entries[lbl_80316398.count];
            lbl_80316398.count++;
            entry->sprite = sprite;
            entry->frame = frame;
            entry->x = pos->x + frame->x;
            entry->y = pos->y + frame->y;
            entry->w = frame->w;
            entry->h = frame->h;
            entry->next = lbl_80316398.lists[frame->layer][frame->prio];
            lbl_80316398.lists[frame->layer][frame->prio] = entry;
            if (frame->more == 0) {
                break;
            }
            frame++;
        }
    }
    sprite->unk1C = sprite->unk18;
    sprite->unk18 = NULL;
}
