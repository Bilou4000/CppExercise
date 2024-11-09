#pragma once

namespace ConsumableType {
    enum Type {
        Food = 1 << 0, //1
        Potion = 1 << 1, //2
        Vegetable = 1 << 2, //4
        Herb = 1 << 3, //8
        Meat = 1 << 4, //16
        Mushroom = 1<< 5, //32
        Cookable =  1 << 6, // 64
    };
}
