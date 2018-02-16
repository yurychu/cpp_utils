#ifndef CIRCULAR_BALANCING_BUFFER_CIRCULARBALANCINGBUFFER_HPP
#define CIRCULAR_BALANCING_BUFFER_CIRCULARBALANCINGBUFFER_HPP


#include <memory>
#include <array>


namespace util_lib {

    template<typename T, size_t SIZE>
    class BalancingBuffer
    {
    private:
        std::unique_ptr<std::array<T, SIZE>> itsBuffer;

    public:
        explicit BalancingBuffer();
        ~BalancingBuffer() = default;

        T get(size_t elem_id);
        void set(T & elem);

    };

    template<typename T, size_t SIZE>
    BalancingBuffer<T, SIZE>::BalancingBuffer()
            : itsBuffer(std::make_unique<std::array<T, SIZE>>())
    {

    }

    template<typename T, size_t SIZE>
    T BalancingBuffer<T, SIZE>::get(size_t elem_id)
    {
        return itsBuffer->at(elem_id);
    }

    template<typename T, size_t SIZE>
    void BalancingBuffer<T, SIZE>::set(T & elem)
    {
        itsBuffer->at(3) = std::move(elem);
    }

}

#endif  // CIRCULAR_BALANCING_BUFFER_CIRCULARBALANCINGBUFFER_HPP
