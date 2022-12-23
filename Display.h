#pragma once

#include "Log.h"
#include <iostream>

class Display {
public:
    static Display *instance();

private:
    static Display *m_instance;
    static bool m_destroyed;

    Display();

    Display(const Display &) = default;

    ~Display();

    static void Create();

    static void OnDeadReference();

    static void KillSingleton();
};
