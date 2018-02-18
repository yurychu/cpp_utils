#ifndef CIRCULAR_BALANCING_BUFFER_CIRCULARBALANCINGBUFFER_HPP
#define CIRCULAR_BALANCING_BUFFER_CIRCULARBALANCINGBUFFER_HPP

#include <memory>
#include <algorithm>
#include <array>


namespace util_lib {

    template<typename T, size_t SIZE>
    class BalancingBuffer
    {
    private:
        size_t itsArrow;
        std::unique_ptr<std::array<T, SIZE>> itsBuffer;
        std::array<size_t, SIZE> itsMapper;

    public:
        explicit BalancingBuffer();
        ~BalancingBuffer();

        T get_if_exist(size_t elem_id);
        void set_force(T &elem, size_t elem_id);

    };

    template<typename T, size_t SIZE>
    BalancingBuffer<T, SIZE>::BalancingBuffer()
            : itsArrow(0),
              itsBuffer(std::make_unique<std::array<T, SIZE>>())
    {
        itsMapper.fill(0);
        std::cout << std::endl << "Created buffer size: " << SIZE << std::endl;
    }

    template<typename T, size_t SIZE>
    T BalancingBuffer<T, SIZE>::get_if_exist(size_t elem_id)
    {
        auto it = std::find(itsMapper.begin(), itsMapper.end(), elem_id);
        if (it != itsMapper.end()){
            auto index = std::distance(itsMapper.begin(), it);
            return itsBuffer->at(index);
        }
        return T();
    }

    template<typename T, size_t SIZE>
    void BalancingBuffer<T, SIZE>::set_force(T &elem, size_t elem_id)
    {
        itsMapper.at(itsArrow) = elem_id;
        itsBuffer->at(itsArrow) = elem;

        itsArrow++;
        if (itsArrow == SIZE){
            itsArrow = 0;
        }
    }

    template<typename T, size_t SIZE>
    BalancingBuffer<T, SIZE>::~BalancingBuffer()
    {
        std::cout << std::endl << "Destructing buffer size: " << SIZE << std::endl;
    }

}

#endif  // CIRCULAR_BALANCING_BUFFER_CIRCULARBALANCINGBUFFER_HPP
