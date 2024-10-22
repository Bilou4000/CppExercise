#pragma once

namespace ItemEffect {
    enum Effect {
        Strenght = 1 << 0, //1
        Speed = 1 << 1, //2
        Regen = 1 << 2, //4
        HeatResistance = 1 << 3, //8
        ColdResistance = 1 << 4, //16
        Immunity = 1 << 5, //32
        None = 1 << 6, //64
    };
}