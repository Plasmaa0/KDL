#include "Keyboard.h"

Keyboard *Keyboard::m_instance = nullptr;
bool Keyboard::m_destroyed = false;

Keyboard *Keyboard::instance() {
    if (not m_instance) {
        if (m_destroyed) {
            OnDeadReference();
        } else {
            Create();
        }
    }
    return m_instance;
}

Keyboard::Keyboard() {
    std::cout << "INIT KEYBOARD" << std::endl;
}

Keyboard::~Keyboard() {
    std::cout << "~KEYBOARD WITH ERROR" << std::endl;
    m_instance = nullptr;
    m_destroyed = true;
    Log::instance()->reportError("keyboard");
}

void Keyboard::Create() {
    static Keyboard inst;
    m_instance = &inst;
}

void Keyboard::OnDeadReference() {
    Create();
    new(m_instance) Keyboard;
    std::atexit(KillSingleton);
    m_destroyed = false;
}

void Keyboard::KillSingleton() { m_instance->~Keyboard(); }
