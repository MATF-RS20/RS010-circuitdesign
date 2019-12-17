#include "gate.h"

static unsigned idCounter;
static std::map<unsigned, Gate*> globalMap;

Gate::Gate()
{
    _id = idCounter;
    globalMap[idCounter++] = this;
}

Gate::~Gate(){

}

unsigned Gate::getId() const
{
    return _id;
}

bool Gate::getValue() const
{
    return _value;
}

InputGate::InputGate()
  : Gate()
{
  _value = false;
}

void InputGate::calculate()
{
     //changing state od
    _value = !_value;

    for(auto gate : _outGates)
        globalMap[gate]->calculate();
}

void InputGate::addOutGate(unsigned id)
{
    _outGates.insert(id);
}

void InputGate::deleteOutGate(unsigned id)
{
    _outGates.erase(id);
}

OutputGate::OutputGate()
  : Gate()
{}

void OutputGate::calculate()
{
    _value = globalMap[_in]->getValue();
}

void OutputGate::setInGate(unsigned id)
{
    _in = id;
    calculate();
}

void OutputGate::deleteInGate()
{
    //obrisan gejt koji je ulaz u Output
    _value = false;
}

InnerGate::InnerGate(unsigned numInputs)
    : Gate (), _numInputs(numInputs)
  {}

InnerGate::~InnerGate(){

}

void InnerGate::addInGate(unsigned id)
{
    _inGates.insert(id);
    calculate();
}

void InnerGate::addOutGate(unsigned id)
{
    _outGates.insert(id);
    //globalMap[id]->calculate();
}

void InnerGate::deleteInGate(unsigned id)
{
    _inGates.erase(id);
    calculate();
}

void InnerGate::deleteOutGate(unsigned id)
{
    _outGates.erase(id);
}

void And::calculate()
{
    bool new_value = true;
    for (unsigned gateId : _inGates)
        new_value = new_value && globalMap[gateId]->getValue();

    _value = new_value;
    for(unsigned gateId : _outGates)
       globalMap[gateId]->calculate();
}

void Or::calculate()
{
    bool new_value = false;
    for (unsigned gateId : _inGates)
        new_value = new_value || globalMap[gateId]->getValue();

    _value = new_value;
    for(unsigned gateId : _outGates)
       globalMap[gateId]->calculate();
}

// proveri kako radi XOR
void Xor::calculate()
{
    unsigned num_true = 0;
    for (unsigned gateId : _inGates)
    {
        if (globalMap[gateId]->getValue() == true)
            num_true++;
    }

    _value = num_true % 2 == 0 ? false : true;

    for(unsigned gateId : _outGates)
       globalMap[gateId]->calculate();
}

void NAnd::calculate()
{
    bool new_value = true;
    for (unsigned gateId : _inGates)
        new_value = new_value && globalMap[gateId]->getValue();

    _value = !new_value;
    for(unsigned gateId : _outGates)
       globalMap[gateId]->calculate();
}

void NOr::calculate()
{
    bool new_value = true;
    for (unsigned gateId : _inGates)
        new_value = new_value || globalMap[gateId]->getValue();

    _value = !new_value;
    for(unsigned gateId : _outGates)
       globalMap[gateId]->calculate();
}

void Not::calculate()
{
    _value = !globalMap[(*_inGates.begin())]->getValue();

    for(unsigned gateId : _outGates)
       globalMap[gateId]->calculate();
}
