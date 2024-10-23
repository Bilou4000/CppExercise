#pragma once

namespace ConsumableType {
    enum Type {
        Food = 1 << 0, //1
        Potion = 1 << 1, //2
        Bakable = 1 << 2, //4
    };
}
