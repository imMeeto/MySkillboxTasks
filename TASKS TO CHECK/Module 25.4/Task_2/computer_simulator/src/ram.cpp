#include "ram.h"

static int buffer[8];

void write(const int* data)
{
    for (int i = 0; i < 8; ++i)
    {
        buffer[i] = data[i];
    }
}

void read(int* dest)
{
    for (int i = 0; i < 8; ++i)
    {
        dest[i] = buffer[i];
    }
}