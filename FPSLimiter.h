#pragma once
#include <chrono>
#include <thread>

template <typename C = std::chrono::high_resolution_clock>
class FPSLimiter {
public:
    FPSLimiter(int64_t frameTime = 16666666) :
        m_frameTime    { frameTime },
        m_startTime    { C::now().time_since_epoch().count() },
        m_sleepTime    { 0 },
        m_frameTimeDebt{ 0 } {
    }

    void run() {
        m_sleepTime = (m_frameTime - m_frameTimeDebt) - (C::now().time_since_epoch().count() - m_startTime);
        if (m_sleepTime > 0) {
            std::this_thread::sleep_for(std::chrono::nanoseconds(m_sleepTime));
        }
        m_frameTimeDebt = (C::now().time_since_epoch().count() - m_startTime) - (m_frameTime - m_frameTimeDebt);
        m_startTime = C::now().time_since_epoch().count();
    }
    
private:
    int64_t m_frameTime;
    int64_t m_startTime;
    int64_t m_sleepTime;
    int64_t m_frameTimeDebt;
};