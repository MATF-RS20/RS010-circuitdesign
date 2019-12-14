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

    input_g1->addOutGate(and1);
    input_g1->addOutGate(xor1);

    input_g2->addOutGate(or1);

    input_g3->addOutGate(and1);

    input_g4->addOutGate(or1);
    input_g4->addOutGate(xor1);

    and1->addInGate(input_g1);
    and1->addInGate(input_g3);

    or1->addInGate(input_g2);
    or1->addInGate(input_g4);

    xor1->addInGate(input_g1);
    xor1->addInGate(input_g4);

    and1->addOutGate(nand);
    and1->addOutGate(nor);

    or1->addOutGate(nand);

    xor1->addOutGate(nor);

    nand->addInGate(and1);
    nand->addInGate(or1);

    nor->addInGate(and1);
    nor->addInGate(xor1);

    nand->addOutGate(or2);

    nor->addOutGate(or2);

    or2->addInGate(nand);
    or2->addInGate(nor);

    or2->addOutGate(not1);

    not1->addInGate(or2);

    not1->addOutGate(output_g1);

    output_g1->setInGate(not1);

    std::cout << output_g1->getValue() << std::endl;

    input_g2->calculate();

    std::cout << output_g1->getValue() << std::endl;

    return a.exec();
}
