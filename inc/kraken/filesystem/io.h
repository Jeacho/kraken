#ifndef KRAKEN_FILESYSTEM_IO_H
#define KRAKEN_FILESYSTEM_IO_H

#include "kraken/filesystem/path.h"
#include "kraken/memory/buffer.h"
#include "kraken/adt/either.h"

#include <memory>

namespace fs {

either<std::error_code, std::unique_ptr<mem::buffer>>
    read_utf8(const path &) noexcept;

} // namespace fs

#endif // KRAKEN_FILESYSTEM_IO_H
