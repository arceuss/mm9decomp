#include "types.h"

typedef struct Unk80083714 {
    /* 0x0 */ struct Unk80083714* next;
    /* 0x4 */ struct Unk80083714* prev;
} Unk80083714;

void fn_80083714(Unk80083714* node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
}
