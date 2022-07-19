#include "MovingState.h"


void MovingState::setContext(MovingContext* context) {
    this->context_ = context;
}

MovingContext::MovingContext(MovingState* state) : state_(nullptr) {
    this->TransitionTo(state);
}

MovingContext::~MovingContext() {
    delete state_;
}
/**
 * The Context allows changing the State object at runtime.
 */
void MovingContext::TransitionTo(MovingState* state) {
    std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
    if (this->state_ != nullptr)
        delete this->state_;
    this->state_ = state;
    this->state_->setContext(this);
}
/**
 * The Context delegates part of its behavior to the current State object.
 */
void MovingContext::Request1() {
    this->state_->Handle1();
}
void MovingContext::Request2() {
    this->state_->Handle2();
}