#include <chrono>

namespace Utils {
    template <
        typename Time = std::chrono::nanoseconds,
        typename Clock = std::chrono::high_resolution_clock
    >
    struct FunctionTimer {
        template <typename F, typename ...Args>
        static auto run(F&& f, Args&&... args) {
            auto start = Clock::now();
            std::invoke(std::forward<F>(f), std::forward<Args>(args)...);
            return std::chrono::duration_cast<Time>(Clock::now() - start).count();
        }
    };
} // namespace Utils