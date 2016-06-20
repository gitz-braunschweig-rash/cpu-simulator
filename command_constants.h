#ifndef COMMAND_CONSTANTS_H
#define COMMAND_CONSTANTS_H

#include <QVector>

const u_int16_t COMMAND_ADD = 0x0;
const u_int16_t COMMAND_SUBTRACT = 0x1;
const u_int16_t COMMAND_MULTIPLY = 0x2;
const u_int16_t COMMAND_DIVISION = 0x3;
const u_int16_t COMMAND_LOAD = 0x4; //Storage
const u_int16_t COMMAND_STORE = 0x5; //Storage
const u_int16_t COMMAND_ADD_VALUE_TO_REGISTER_FIRST_OCTED = 0x6;
const u_int16_t COMMAND_ADD_VALUE_TO_REGISTER_SECOND_OCTED = 0x7;
const u_int16_t COMMAND_PUSH = 0x8; //Storage
const u_int16_t COMMAND_POP = 0x9; //Storage
const u_int16_t COMMAND_JUMP_STATIC = 0xA; //Flow
const u_int16_t COMMAND_JUMP_REGISTER = 0xB; //Flow
const u_int16_t COMMAND_BRANCH_ON_EQUAL = 0xC; //Flow
const u_int16_t COMMAND_SET_STACK_POINTER = 0xD; //Storage
const u_int16_t COMMAND_LOAD_REGISTER = 0xE; //Load via Register
const u_int16_t COMMAND_STORE_REGISTER = 0xF; //Storage via Register
#endif // COMMAND_CONSTANTS_H
