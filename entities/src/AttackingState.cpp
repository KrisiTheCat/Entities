#include "AttackingState.h"


void AttackingState::setContext(AttackingContext* context) {
    this->context_ = context;
}

AttackingContext::AttackingContext(AttackingState* state) : state_(nullptr) {
    this->TransitionTo(state);
}

AttackingContext::~AttackingContext() {
    delete state_;
}
/**
 * The Context allows changing the State object at runtime.
 */
void AttackingContext::TransitionTo(AttackingState* state) {
    std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
    if (this->state_ != nullptr)
        delete this->state_;
    this->state_ = state;
    this->state_->setContext(this);
}
/**
 * The Context delegates part of its behavior to the current State object.
 */

void AttackingContext::update()
{
    this->state_->update();
}

void AttackingContext::init(Entity* entity)
{
    m_entity = entity;
}

void Attack::update()
{
    if (this->context_->m_entity->m_attackTargets.size() > 0)
    {
        if (m_frameId == 0)
        {
            this->context_->m_entity->attack(this->context_->m_entity->m_attackTargets.at(0));
        }
        m_frameId++;
        m_frameId %= m_framesToShoot;
    }
}

void NoAttack::update()
{
    std::cout << "Update B\n";
}
