
#ifndef PRODUCTION
# error PRODUCTION(kind, message, sev) NOT DEFINED
#endif

#define ERROR(kind, message)   PRODUCTION(kind, message, error)
#define WARNING(kind, message) PRODUCTION(kind, message, warning)
#define NOTE(kind, message)    PRODUCTION(kind, message, note)

WARNING(multi_char_in_lit, "Multiple characters in character literal.")

#undef PRODUCTION
#undef ERROR
#undef WARNING
#undef NOTE
