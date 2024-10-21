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

    uint8_t operator +(const uint8_t& a, const Type& b) {
        return a | b;
    }

    uint8_t operator -(const uint8_t& a, const Type& b) {
        return a ^ b;
    }

    void operator +=(uint8_t& a, const Type& b) {
        a = a | b;
    }

    void operator -=(uint8_t& a, const Type& b) {
        a = a ^ b;
    }
}

