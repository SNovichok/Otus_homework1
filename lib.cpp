#include "lib.h"
#include "version.h"

int version()
{
    return (PROJECT_VERSION_PATCH > 0 ? PROJECT_VERSION_PATCH : 666);
}
