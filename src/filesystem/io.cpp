
#include <fstream>

#include "kraken/filesystem/io.h"

namespace fs {

either<std::error_code, std::unique_ptr<mem::buffer>>
read_utf8(const fs::path &p) noexcept {
    // \brief Check if path exists.
    if (__builtin_expect(!p.exists(), 0))
        return std::make_error_code(std::errc::no_such_file_or_directory);

    // \brief Check if path is not a directory.
    if (__builtin_expect(p.is_dir(), 0))
        return std::make_error_code(std::errc::is_a_directory);

    std::wifstream stream(p, std::ios::ate | std::ios::in | std::ios::binary);
    std::size_t file_size;

    // \brief Check the stream to see if it caught an error.
    if (__builtin_expect(!stream.is_open(), 0))
        return std::error_code(errno, std::generic_category());

    file_size = stream.tellg();
    stream.seekg(0, stream.beg);

    mem::buffer *buffer = new mem::buffer(file_size);
    // \brief Check if the buffer allocated the memory block successfully.
    if (buffer->failed())
        return std::make_error_code(std::errc::not_enough_memory);

    stream.read(buffer->data(), file_size);

    if (__builtin_expect(!stream, 0)) {
        stream.close();
        return std::error_code(errno, std::generic_category());
    }

    stream.close();
    return std::unique_ptr<mem::buffer>(buffer);
}

} // namespace io
