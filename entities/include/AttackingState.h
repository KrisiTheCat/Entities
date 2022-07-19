#pragma once

#include "defines.h"
#include "Entity.h"

class AttackingContext;

class AttackingState {

protected:
    AttackingContext* context_;

public:
    virtual ~AttackingState() {}

    void setContext(AttackingContext* context);

    virtual void update() = 0;
};

class AttackingContext {

private:
    AttackingState* state_;

public:
    AttackingContext(AttackingState* state);
    ~AttackingContext();

    void TransitionTo(AttackingState* state);

    void update();
    void init(Entity* entity);
    Entity* m_entity;
};

class Attack : public AttackingState {
public:
    void update() override;
    int m_frameId = 0;
    int m_framesToShoot = 100;
};

class NoAttack : public AttackingState {
public:
    void update() override;
};