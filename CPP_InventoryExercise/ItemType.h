#pragma once
#include <cstdint>

namespace ItemType {
    enum Type {
        Consumable = 1 << 0, //1
        Weapon = 1 << 1, //2
        Junk = 1 << 2, //4
        Poison = 1 << 3, //8
        Breakable = 1 << 4, //16
        Shiny = 1 << 5, //32
        Armor = 1 << 6, //64
    };

    static uint8_t operator +(const uint8_t& a, const Type& b)
    {
        return a | b;
    }

    static uint8_t operator -(const uint8_t& a, const Type& b)
    {
        return a ^ b;
    }

    static uint8_t operator +=(uint8_t& a, const Type& b)
    {
        return a = a + b;
    }

    static uint8_t operator -=(uint8_t& a, const Type& b) 
    {
        return a = a - b;
    }
}

template <typename ValueType, typename FlagType>

static bool HasFlag(ValueType type, FlagType flag)
{
    return type & flag;
}

