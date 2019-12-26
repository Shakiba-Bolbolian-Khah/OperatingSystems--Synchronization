#include "types.h"
#include "stat.h"
#include "user.h"
 
int
test(void)
{
    testLock();
    return 1;
}

int
main(int argc, char *argv[])
{
    test();
    exit();
}