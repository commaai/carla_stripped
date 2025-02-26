#include <cstdlib>

extern "C" long __isoc23_strtol(const char* nptr, char** endptr, int base) {
    return strtol(nptr, endptr, base);
}
