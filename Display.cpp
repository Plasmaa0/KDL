#include "Display.h"

Display *Display::m_instance = nullptr;
bool Display::m_destroyed = false;

Display *Display::instance() {
    if (not m_instance) {
        if (m_destroyed) {
            OnDeadReference();
        } else {
            Create();
        }
    }
    return m_instance;
}

Display::Display() {
    std::cout << "INIT DISPLAY WITH ERROR" << std::endl;
    Log::instance()->reportError("display");
}

Display::~Display() {
    std::cout << "~DISPLAY" << std::endl;
    m_instance = nullptr;
    m_destroyed = true;
}

void Display::Create() {
    static Display inst;
    m_instance = &inst;
}

void Display::OnDeadReference() {
    Create();
    new(m_instance) Display;
    std::atexit(KillSingleton);
    m_destroyed = false;
}

void Display::KillSingleton() { m_instance->~Display(); }
