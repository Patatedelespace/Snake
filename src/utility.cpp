#include "utility.h"


double crop(double min, double max, double value) {
    return (value <= min) ? min : ((value >= max) ? max : value);
}
