#include "Log.h"

#define PHOENIX_LOG
#define ATEXIT_FIXED

Log *Log::m_instance = nullptr;
bool Log::m_destroyed = false;

Log *Log::instance() {
    if (not m_instance) {
        if (m_destroyed) {
            OnDeadReference();
        } else {
            Create();
        }
    }
    return m_instance;
}

void Log::reportError(const std::string &from_who) {
    std::cout << "error from " << from_who << std::endl;
}

Log::Log() {
    std::cout << "INIT LOG" << std::endl;
}

Log::~Log() {
    std::cout << "~LOG" << std::endl;
    m_instance = nullptr;
    m_destroyed = true;
}

void Log::OnDeadReference() {
    std::cout << "LOG DEAD REFERENCE" << std::endl;
#ifdef PHOENIX_LOG
    Create();
    new(m_instance) Log;
    m_destroyed = false;
#ifdef  ATEXIT_FIXED
    std::atexit(KillSingleton);
#else
    std::cout << "ERR -- ATEXIT_FIXED NOT DEFINED" << std::endl;
#endif
#else
    throw std::runtime_error("log dead ref");
#endif
}

void Log::Create() {
    static Log inst;
    m_instance = &inst;
}

void Log::KillSingleton() { m_instance->~Log(); }
