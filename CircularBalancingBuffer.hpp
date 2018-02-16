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
        std::array<size_t, SIZE> itsMapper;

    public:
        explicit BalancingBuffer();
        ~BalancingBuffer();

        T get(size_t elem_id);
        void set(T & elem, size_t elem_id);

    };

    template<typename T, size_t SIZE>
    BalancingBuffer<T, SIZE>::BalancingBuffer()
            : itsBuffer(std::make_unique<std::array<T, SIZE>>())
    {
        itsMapper.fill(0);
    }

    template<typename T, size_t SIZE>
    T BalancingBuffer<T, SIZE>::get(size_t elem_id)
    {
        return itsBuffer->at(elem_id);
    }

    template<typename T, size_t SIZE>
    void BalancingBuffer<T, SIZE>::set(T & elem, size_t elem_id)
    {
        itsBuffer->at(elem_id) = elem;
        std::cout << itsMapper.at(3) << std::endl;
    }

    template<typename T, size_t SIZE>
    BalancingBuffer<T, SIZE>::~BalancingBuffer()
    {
        std::cout << std::endl << "Destructing buffer size: " << SIZE << std::endl;
    }

}

#endif  // CIRCULAR_BALANCING_BUFFER_CIRCULARBALANCINGBUFFER_HPP
