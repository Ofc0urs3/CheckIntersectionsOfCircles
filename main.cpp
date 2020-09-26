#include "my.h"

int main(void)
{
    Field f;
    int res = f.read("input.txt");
    if (res < 0)
        return -1;
    f.print();

    Field f1;
    res = f1.read("input1.txt");
    if (res < 0)
        return -1;
    f1.print();

    f.check();
    f1.check();

    return 0;
}
