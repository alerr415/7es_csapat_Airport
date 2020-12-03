#ifndef MANIPULATOR_H
#define MANIPULATOR_H

// INTERFACE
class Manipulator
{
public:
    Manipulator();
    virtual ~Manipulator() = default;
    virtual void keres() const = 0;
    virtual void modosit() = 0;
    virtual void teljesBevitel() = 0;
};

#endif // MANIPULATOR_H
