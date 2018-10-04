#ifndef CIRCULAR_BALANCING_BUFFER_PIPEBOX_HPP
#define CIRCULAR_BALANCING_BUFFER_PIPEBOX_HPP

namespace util_lib {

    template <typename OutputT, typename InputT, typename FunctorT>
    class PipeBox
    {
    private:
        FunctorT itsFunctor;

    public:
        PipeBox();
        ~PipeBox();

    };


}
#endif  // CIRCULAR_BALANCING_BUFFER_PIPEBOX_HPP
