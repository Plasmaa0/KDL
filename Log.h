#pragma once

#include <cstdlib>
#include <iostream>

class Log {
public:
    static Log *instance();

    void reportError(const std::string &from_who);

private:
    static Log *m_instance;
    static bool m_destroyed;

    Log();

    Log(const Log &) = default;

    ~Log();

    static void Create();

    static void OnDeadReference();

    static void KillSingleton();
};