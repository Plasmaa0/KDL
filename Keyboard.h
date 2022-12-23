#pragma once

#include "Log.h"
#include <iostream>


class Keyboard {
public:
    static Keyboard *instance();

private:
    static Keyboard *m_instance;
    static bool m_destroyed;

    Keyboard();

    Keyboard(const Keyboard &) = default;

    ~Keyboard();

    static void Create();

    static void OnDeadReference();

    static void KillSingleton();
};
