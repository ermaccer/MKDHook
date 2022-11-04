#pragma once

void makeJal(unsigned int addr, void* func);
void patchInt(unsigned int addr, int data);
void makeJmp(unsigned int addr, void* func);
void NOP(unsigned int addr);
void patchShort(unsigned int addr, short data);