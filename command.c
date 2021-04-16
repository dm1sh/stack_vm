#include "./command.h"

cmd_desc_t cmd_desc[] = {
    {PUSH, 1, "PUSH"},
    {POP, 0, "POP"},
    {ADD, 0, "ADD"},
    {SUB, 0, "SUB"},
    {MUL, 0, "MUL"},
    {DIV, 0, "DIV"},
    {MOD, 0, "MOD"},
#ifdef IO_OPERATIONS
    {IN, 0, "IN"},
    {OUT, 0, "OUT"},
#endif
    {NONE, 0, "NONE"}}
