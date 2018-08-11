#ifndef KRAKEN_SUPPORT_COMPILER_H
#define KRAKEN_SUPPORT_COMPILER_H

#if defined(_WIN32) || defined(_WIN64)
# define WINDOWS
# ifndef S_ISREG
#  define S_ISREG(mode) (((mode) & S_IFMT) == S_IFREG)
# endif
# ifndef S_ISDIR
#  define S_ISDIR(mode) (((mode) & S_IFMT) == S_IFDIR)
# endif
#elif defined(__APPLE__)
# define MACOS
#elif defined(__unix__) || defined(__unix)
# define LINUX
#endif
# define platform_error #error("error: kraken only unix and windows platforms.")
#endif // KRAKEN_SUPPORT_COMPILER_H
