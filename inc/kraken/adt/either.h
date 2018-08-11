#ifndef KRAKEN_ADT_EITHER_H
#define KRAKEN_ADT_EITHER_H

#include <iostream>
#include <functional>
#include <stdexcept>
#include <type_traits>

template<class type>
struct aligned_array {
    alignas(alignof(type)) char buffer[sizeof(type)];
};

// \brief Either monad implementation.
template<class left_type, class right_type>
class either {
    static const bool is_left_ref   = std::is_reference<left_type>::value;
    static const bool is_right_ref  = std::is_reference<right_type>::value;

    using left_wrap = std::reference_wrapper<typename std::remove_reference<left_type>::type>;
    using right_wrap = std::reference_wrapper<typename std::remove_reference<right_type>::type>;

public:
    using left_storage_type     = typename std::conditional<is_left_ref, left_wrap, left_type>::type;
    using right_storage_type    = typename std::conditional<is_right_ref, right_wrap, right_type>::type;

private:
    enum class type_bits : bool {
        left    = 0,
        right   = 1,
    };

    union {
        aligned_array<left_storage_type>    left_storage;
        aligned_array<right_storage_type>   right_storage;
    };

    type_bits type_bit : 1;

    void copy_construct(const either<left_type, right_type> &other) {
        if (other.type_bit == type_bits::left) {
            type_bit = type_bits::left;
            new (left()) left_storage_type(*other.left());
        } else {
            type_bit = type_bits::right;
            new (right()) right_storage_type(other.right());
        }
    }

    void move_construct(either<left_type, right_type> &&other) {
        if (other.type_bit == type_bits::left) {
            type_bit = type_bits::left;
            new (left()) left_storage_type(std::move(*other.left()));
        } else {
            type_bit = type_bits::right;
            new (right()) right_storage_type(std::move(*other.right()));
        }
    }

    void copy_assign(const either<left_type, right_type> &other) {
        this->~either<left_type, right_type>();
        new (this) either(other);
    }

    void move_assign(either<left_type, right_type> &&other) {
        this->~either<left_type, right_type>();
        new (this) either<left_type, right_type>(std::move(other));
    }

public:
    either(left_type value) : type_bit(type_bits::left) {
        new (left()) left_storage_type(std::move(value));
    }

    either(right_type value) : type_bit(type_bits::right) {
        new (right()) right_storage_type(std::move(value));
    }

    explicit either(const either<left_type, right_type> &other) {
        copy_construct(other);
    }

    either(either<left_type, right_type> &&other) {
        move_construct(std::move(other));
    }

    either<left_type, right_type> &operator=(const either<left_type, right_type> &other) {
        copy_assign(other);
        return *this;
    }

    either<left_type, right_type> &operator=(either<left_type, right_type> &&other) {
        move_assign(std::move(other));
        return *this;
    }

    ~either() {
        if (type_bit == type_bits::left)    left()->~left_type();
        if (type_bit == type_bits::right)   right()->~right_type();
    }

    inline bool is_left() const {
        return type_bit == type_bits::left;
    }

    inline bool is_right() const {
        return type_bit == type_bits::right;
    }

    left_storage_type *left() {
        assert(this->is_left() && "Cannot get value when an error exists!");
        return reinterpret_cast<left_storage_type *>(left_storage.buffer);
    }
    const left_storage_type *left() const {
        assert(this->is_left()&& "Cannot get value when an error exists!");
        return reinterpret_cast<const left_storage_type *>(left_storage.buffer);
    }

    right_storage_type *right() {
        assert(this->is_right() && "Cannot get value when an error exists!");
        return reinterpret_cast<right_storage_type *>(left_storage.buffer);
    }
    const right_storage_type *right() const {
        assert(this->is_right() && "Cannot get value when an error exists!");
        return reinterpret_cast<const right_storage_type *>(right_storage.buffer);
    }
};

template<class error_type, class func_type, class... types>
auto attempt(const func_type &fn, types&&... params)
     -> either<error_type, decltype(fn(std::forward<types>(params)...))> {
    try {
        return std::move(fn(std::forward<types>(params)...));
    } catch (const error_type &except) {
        return std::move(except);
    }
}

#endif // KRAKEN_ADT_EITHER_H
