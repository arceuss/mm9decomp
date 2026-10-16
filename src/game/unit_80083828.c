#include "types.h"

typedef struct Unk80083828 {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ s32 unkC;
    /* 0x10 */ char name[1];
} Unk80083828;

char* strcpy(char* dst, const char* src);
void fn_80179BA0(char* dst, const char* src);

void fn_80083828(Unk80083828* self, const char* src) {
    if (self->unkC != 1) {
        strcpy(self->name, src);
    } else {
        fn_80179BA0(self->name, src);
    }
}
