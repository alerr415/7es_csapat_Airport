#ifndef MANIPULATOR_H
#define MANIPULATOR_H

// INTERFACE
class Manipulator
{
public:
    Manipulator();
    virtual ~Manipulator() = default;
    virtual void keres() const = 0;
};

#endif // MANIPULATOR_H
