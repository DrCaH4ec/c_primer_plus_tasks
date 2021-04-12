#include "prot.h"

int my_atoi(const char *str)
{
    bool sign = (str[0] == '-');
    int res = 0;
    size_t i = sign ? 1 : 0;
    for (; str[i] != '\0'; i++) {
        if (!isdigit(str[i]))
            return 0;

        res = res * 10 + (str[i] - '0');
    }

    return sign ? -res : res;
}
