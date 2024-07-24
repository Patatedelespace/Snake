#pragma once

#include <assert.h>

// int crop(int min, int max, int value) {
//     return (value <= min) ? min : ((value >= max) ? max : value);
// }
//
// long long crop(long long min, long long max, long long value) {
//     return (value <= min) ? min : ((value >= max) ? max : value);
// }

double crop(double min, double max, double value) {
    return (value <= min) ? min : ((value >= max) ? max : value);
}
