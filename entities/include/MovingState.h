#pragma once
class MovingContext;

class MovingState {

protected:
    MovingContext* context_;

public:
    virtual ~MovingState() {}

    void setContext(MovingContext* context);

    virtual void Handle1() = 0;
    virtual void Handle2() = 0;
};

/**
 * The Context defines the interface of interest to clients. It also maintains a
 * reference to an instance of a State subclass, which represents the current
 * state of the Context.
 */
class MovingContext {
    /**
     * @var State A reference to the current state of the Context.
     */
private:
    MovingState* state_;

public:
    MovingContext(MovingState* state);
    ~MovingContext();
    /**
     * The Context allows changing the State object at runtime.
     */
    void TransitionTo(MovingState* state);
    /**
     * The Context delegates part of its behavior to the current State object.
     */
    void Request1();
    void Request2();
};