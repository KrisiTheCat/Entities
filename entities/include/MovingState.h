#pragma once

#include "defines.h"
#include "Entity.h"

class MovingContext;

class MovingState {

protected:
    MovingContext* context_;

public:
    virtual ~MovingState() {}

    void setContext(MovingContext* context);

    virtual void update() = 0;
};

class MovingContext {

private:
    MovingState* state_;

public:
    MovingContext(MovingState* state);
    ~MovingContext();

    void TransitionTo(MovingState* state);

    void update();
    void init(Entity* entity);
    Entity* m_entity;
};

class Chase : public MovingState {
public:
    void update() override;
private:
};

class Roam : public MovingState {
public:
    void update() override;
};