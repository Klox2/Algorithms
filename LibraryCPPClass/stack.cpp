#include "stack.h"

void Stack::push(Data data) {
    v_.resize(v_.size() + 1);
    v_.set(v_.size() - 1, data);
}

Data Stack::get() const { return v_.get(v_.size() - 1); }

void Stack::pop() { v_.resize(v_.size() - 1); }

bool Stack::empty() const { return v_.size() == 0; }
