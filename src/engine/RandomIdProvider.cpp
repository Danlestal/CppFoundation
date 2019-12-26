#include <cstdlib>
#include "IdentifierProvider.hpp"
#include "RandomIdProvider.hpp"



long RandomIdProvider::getUID() {
    if (sizeof(int) < sizeof(long))
        return (static_cast<long>(rand()) << (sizeof(int) * 8)) | rand();

    return rand();
}