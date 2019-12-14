#ifndef GATE_H
#define GATE_H

#include <vector>

class Gate
{
public:
    Gate() = default;

    virtual void calculate() = 0;

    bool getValue() const;

protected:
    bool _value;
};

class InputGate : public Gate
{
public:
    InputGate() : Gate()
    {}

    void calculate();

    void addOutGate(Gate* gate);
    void deleteOutGate(Gate* gate);

private:
    std::vector<Gate*> _outGates;
};

class OutputGate : public Gate
{
public:
    OutputGate() : Gate()
    {}

    void calculate();
    void setInGate(Gate* gate);
    void deleteInGate();

private:
    Gate* _in;
};

class InerGate : public Gate
{
public:
    InerGate(unsigned numInputs = 4)
        : Gate (), _numInputs(numInputs)
    {}

    void addInGate(Gate* gate);
    void addOutGate(Gate* gate);
    void deleteInGate(Gate* gate);
    void deleteOutGate(Gate* gate);

protected:
    unsigned _numInputs;
    std::vector<Gate*> _inGates;
    std::vector<Gate*> _outGates;
};

class And : public InerGate
{
public:
    And() : InerGate()
    {}

    void calculate();
};

class Or : public InerGate
{
public:
    Or() : InerGate()
    {}

    void calculate();
};

class Xor : public InerGate
{
public:
    Xor() : InerGate()
    {}

    void calculate();
};

class NAnd : public InerGate
{
public:
    NAnd() : InerGate()
    {}

    void calculate();
};

class NOr : public InerGate
{
public:
    NOr() : InerGate()
    {}

    void calculate();
};

class Not : public InerGate
{
public:
    Not() : InerGate(1u)
    {}

    void calculate();
};

#endif // GATE_H
