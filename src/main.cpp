#include "mainwindow.h"
#include <QApplication>

#include "gate.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    InputGate* input_g1 = new InputGate();
    InputGate* input_g2 = new InputGate();
    InputGate* input_g3 = new InputGate();
    InputGate* input_g4 = new InputGate();

    Or* or1 = new Or();
    And* and1 = new And();
    Xor* xor1 = new Xor();
    NOr* nor = new NOr();
    NAnd* nand = new NAnd();
    Or* or2 = new Or();
    Not* not1 = new Not();

    OutputGate* output_g1 = new OutputGate();

    input_g1->calculate();
    input_g3->calculate();

    input_g1->addOutGate(and1->getId());
    input_g1->addOutGate(xor1->getId());
    input_g2->addOutGate(or1->getId());
    input_g3->addOutGate(and1->getId());
    input_g4->addOutGate(or1->getId());
    input_g4->addOutGate(xor1->getId());

    and1->addInGate(input_g1->getId());
    and1->addInGate(input_g3->getId());

    or1->addInGate(input_g2->getId());
    or1->addInGate(input_g4->getId());

    xor1->addInGate(input_g1->getId());
    xor1->addInGate(input_g4->getId());

    and1->addOutGate(nand->getId());
    and1->addOutGate(nor->getId());

    or1->addOutGate(nand->getId());

    xor1->addOutGate(nor->getId());

    nand->addInGate(and1->getId());
    nand->addInGate(or1->getId());

    nor->addInGate(and1->getId());
    nor->addInGate(xor1->getId());

    nand->addOutGate(or2->getId());

    nor->addOutGate(or2->getId());

    or2->addInGate(nand->getId());
    or2->addInGate(nor->getId());

    or2->addOutGate(not1->getId());

    not1->addInGate(or2->getId());

    not1->addOutGate(output_g1->getId());

    output_g1->setInGate(not1->getId());

    std::cout << output_g1->getValue() << std::endl;

    input_g2->calculate();

    InputGate* input1 = new InputGate();
    InputGate* input2 = new InputGate();
    OutputGate* output = new OutputGate();
    Or* orr = new Or();
    And* andd = new And();

   // input1->calculate();
    orr->addInGate(input1->getId());
    orr->addInGate(input2->getId());
    orr->addOutGate(output->getId());
    output->setInGate(orr->getId());

    std::cout <<input1->getValue()  <<std::endl;
    std::cout <<input2->getValue() << std::endl;
    std::cout << output->getValue() << std::endl;

    return a.exec();
}
