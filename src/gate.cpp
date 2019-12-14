#include "gate.h"

bool Gate::getValue() const
{
    return _value;
}

void InputGate::calculate()
{
    _value = !_value;

    for (auto it = _outGates.cbegin(); it != _outGates.cend(); it++)
        (*it)->calculate();
}

void InputGate::addOutGate(Gate* gate)
{
    _outGates.push_back(gate);
    for (auto it = _outGates.cbegin(); it != _outGates.cend(); it++)
        (*it)->calculate();
}

void InputGate::deleteOutGate(Gate* gate)
{

}

void OutputGate::calculate()
{
    _value = _in->getValue();
}

void OutputGate::setInGate(Gate *gate)
{
    _in = gate;
    calculate();
}

void OutputGate::deleteInGate()
{
    _in = nullptr;
}

void InerGate::addInGate(Gate* gate)
{
    _inGates.push_back(gate);
}

void InerGate::addOutGate(Gate* gate)
{
    _outGates.push_back(gate);
}

void InerGate::deleteInGate(Gate* gate)
{

}

void InerGate::deleteOutGate(Gate* gate)
{

}

void And::calculate()
{
    bool new_value = true;
    for (auto it = _inGates.cbegin(); it != _inGates.cend(); it++)
    {
        new_value = new_value && (*it)->getValue();
    }
    _value = new_value;

    for (auto it = _outGates.cbegin(); it != _outGates.cend(); it++)
        (*it)->calculate();
}

void Or::calculate()
{
    bool new_value = false;
    for (auto it = _inGates.cbegin(); it != _inGates.cend(); it++)
    {
        new_value = new_value || (*it)->getValue();
    }
    _value = new_value;

    for (auto it = _outGates.cbegin(); it != _outGates.cend(); it++)
        (*it)->calculate();
}

void Xor::calculate()
{
    unsigned num_true = 0;
    for (auto it = _inGates.cbegin(); it != _inGates.cend(); it++)
    {
        if ((*it)->getValue() == true)
            num_true++;
    }
    _value = num_true == 1 ? true : false;

    for (auto it = _outGates.cbegin(); it != _outGates.cend(); it++)
        (*it)->calculate();
}

void NAnd::calculate()
{
    bool new_value = true;
    for (auto it = _inGates.cbegin(); it != _inGates.cend(); it++)
    {
        new_value = new_value && (*it)->getValue();
    }
    _value = !new_value;

    for (auto it = _outGates.cbegin(); it != _outGates.cend(); it++)
        (*it)->calculate();
}

void NOr::calculate()
{
    bool new_value = false;
    for (auto it = _inGates.cbegin(); it != _inGates.cend(); it++)
    {
        new_value = new_value || (*it)->getValue();
    }
    _value = !new_value;

    for (auto it = _outGates.cbegin(); it != _outGates.cend(); it++)
        (*it)->calculate();
}

void Not::calculate()
{
    _value = !_inGates[0]->getValue();

    for (auto it = _outGates.cbegin(); it != _outGates.cend(); it++)
        (*it)->calculate();
}
