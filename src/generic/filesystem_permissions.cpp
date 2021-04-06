//By Tsuki Superior
#include <generic/filesystem_permissions.hpp>

Permissions::Permissions() : read(false), write(false), execute(false)
{
}

Permissions::Permissions(bool r, bool w, bool e) : read(r), write(w), execute(e)
{
}
