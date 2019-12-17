#ifndef GATE_H
#define GATE_H

#include <vector>
#include <map>
#include <set>


class Gate
{
public:
    Gate();
    virtual ~Gate();

    virtual void calculate() = 0;
    bool getValue() const;
    unsigned getId() const;
protected:
    unsigned _id;
    bool _value;
};

class InputGate : public Gate
{
public:
    InputGate() ;

    void calculate();

    void addOutGate(unsigned id);
    void deleteOutGate(unsigned id);

private:
    std::set<unsigned> _outGates;
};

class OutputGate : public Gate
{
public:
    OutputGate();

    void calculate();
    void setInGate(unsigned id);
    void deleteInGate();

private:
    unsigned _in;
};

class InnerGate : public Gate
{
public:
    InnerGate(unsigned numInputs = 4);
    ~InnerGate();

    void addInGate(unsigned id);
    void addOutGate(unsigned id);
    void deleteInGate(unsigned id);
    void deleteOutGate(unsigned id);

protected:
    unsigned _numInputs;
    std::set<unsigned> _inGates;
    std::set<unsigned> _outGates;
};

class And : public InnerGate
{
public:
    And() : InnerGate()
    {}

    void calculate();
};

class Or : public InnerGate
{
public:
    Or() : InnerGate()
    {}

    void calculate();
};

class Xor : public InnerGate
{
public:
    Xor() : InnerGate()
    {}

    void calculate();
};

class NAnd : public InnerGate
{
public:
    NAnd() : InnerGate()
    {}

    void calculate();
};

class NOr : public InnerGate
{
public:
    NOr() : InnerGate()
    {}

    void calculate();
};

class Not : public InnerGate
{
public:
    Not() : InnerGate(1u)
    {}

    void calculate();
};

#endif // GATE_H
