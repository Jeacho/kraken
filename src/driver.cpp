
#include <iostream>
#include <vector>

#include "kraken/support/console.h"
#include "kraken/filesystem/io.h"

std::ostream &__KKC(std::ostream &stream) {
    return stream << bold << fg::blue << "[ KKC ] ";
}

int main(int argc, char *argv[]) {
    std::vector<std::unique_ptr<mem::buffer>> paths;
    std::vector<segment> args;

    for (std::size_t index = 1; index < argc; index++) {
        segment seg(argv[index]);

        if (seg.starts_with("--"))
            args.push_back(seg);
        else {
            either<std::error_code, std::unique_ptr<mem::buffer>>
                maybe_buffer = fs::read_utf8(static_cast<fs::path>(seg));

            if (maybe_buffer.is_left()) {
                // error occured when the file was being read.
                std::cerr << reset << '\"' << fg::blue << seg
                          << reset << "\": " << fg::red << "error: " << reset
                          << maybe_buffer.left()->message() << std::endl;
            } else {
                paths.push_back(std::move(*maybe_buffer.right()));
            }
        }
    }

    if (paths.empty()) {
        std::cerr << __KKC << reset << "No input files..." << std::endl;
        return 0;
    }

    return 0;
}
