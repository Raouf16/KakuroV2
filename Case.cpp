#include "Case.h"

Case::Case(bool usedValue, int value) {
    this->usedValue = usedValue;
    this->value = value;
}

Case::Case() {
    this->usedValue = false;
    this->value = 0;
}
