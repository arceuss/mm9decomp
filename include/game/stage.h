#ifndef GAME_STAGE_H
#define GAME_STAGE_H

// Stage ids. The stage descriptors at 0x80275CF4 and on carry st00.bin..st0e.bin
// in id order, and lbl_80272E44[N] is the music fn_80082950 starts for stage N.
// The names come from that music: stage 0 has none (0xFFFF), 0x0D plays
// BGM_GENERATE and 0x0E BGM_SPECIAL, so those keep the sequence label rather
// than a guessed mode name.
enum Stage {
    STAGE_00          = 0x00,
    STAGE_MAGMAMAN    = 0x01,
    STAGE_HORNETMAN   = 0x02,
    STAGE_GALAXYMAN   = 0x03,
    STAGE_TORNADOMAN  = 0x04,
    STAGE_JEWELMAN    = 0x05,
    STAGE_SPLASHWOMAN = 0x06,
    STAGE_PLUGMAN     = 0x07,
    STAGE_CONCRETEMAN = 0x08,
    STAGE_WILY1       = 0x09,
    STAGE_WILY2       = 0x0A,
    STAGE_WILY3       = 0x0B,
    STAGE_WILY4       = 0x0C,
    STAGE_GENERATE    = 0x0D,
    STAGE_SPECIAL     = 0x0E,
    STAGE_COUNT       = 0x0F
};

#endif
