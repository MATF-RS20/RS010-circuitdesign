#include "mainwindow.h"
#include <QApplication>

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*
    InputGate* input1 = new InputGate();
    InputGate* input2 = new InputGate();
    InputGate* input3 = new InputGate();

    Or* or_ = new Or();
    And* and_ = new And();
    Xor* xor_ = new Xor();
    NOr* nor_ = new NOr();
    NAnd* nand_ = new NAnd();
    Not* not_ = new Not();

    OutputGate* outputOr = new OutputGate();
    OutputGate* outputAnd = new OutputGate();
    OutputGate* outputXor = new OutputGate();
    OutputGate* outputNor = new OutputGate();
    OutputGate* outputNand = new OutputGate();
    OutputGate* outputNot = new OutputGate();

    input1->addOutGate(or_->getId());
    input2->addOutGate(or_->getId());
    input3->addOutGate(or_->getId());

    input1->addOutGate(and_->getId());
    input2->addOutGate(and_->getId());
    input3->addOutGate(and_->getId());

    input1->addOutGate(xor_->getId());
    input2->addOutGate(xor_->getId());
    input3->addOutGate(xor_->getId());

    input1->addOutGate(nor_->getId());
    input2->addOutGate(nor_->getId());
    input3->addOutGate(nor_->getId());

    input1->addOutGate(nand_->getId());
    input2->addOutGate(nand_->getId());
    input3->addOutGate(nand_->getId());

    input1->addOutGate(not_->getId());
    input2->addOutGate(not_->getId());
    input3->addOutGate(not_->getId());

    or_->addInGate(input1->getId());
    or_->addInGate(input2->getId());
    or_->addInGate(input3->getId());
    or_->addOutGate(outputOr->getId());
    outputOr->setInGate(or_->getId());

    and_->addInGate(input1->getId());
    and_->addInGate(input2->getId());
    and_->addInGate(input3->getId());
    and_->addOutGate(outputAnd->getId());
    outputAnd->setInGate(and_->getId());

    xor_->addInGate(input1->getId());
    xor_->addInGate(input2->getId());
    xor_->addInGate(input3->getId());
    xor_->addOutGate(outputXor->getId());
    outputXor->setInGate(xor_->getId());

    nor_->addInGate(input1->getId());
    nor_->addInGate(input2->getId());
    nor_->addInGate(input3->getId());
    nor_->addOutGate(outputNor->getId());
    outputNor->setInGate(nor_->getId());

    nand_->addInGate(input1->getId());
    nand_->addInGate(input2->getId());
    nand_->addInGate(input3->getId());
    nand_->addOutGate(outputNand->getId());
    outputNand->setInGate(nand_->getId());

    not_->addInGate(input1->getId());
    not_->addOutGate(outputNot->getId());
    outputNot->setInGate(not_->getId());

    input1->calculate();
    input2->calculate();
    //input3->calculate();

    std::cout << "input1: " << input1->getValue() << std::endl;
    std::cout << "input2: " << input2->getValue() << std::endl;
    std::cout << "input3: " << input3->getValue() << std::endl;
    std::cout << "Or: " << outputOr->getValue() << std::endl;
    std::cout << "And: " << outputAnd->getValue() << std::endl;
    std::cout << "Xor: " << outputXor->getValue() << std::endl;
    std::cout << "Nor: " << outputNor->getValue() << std::endl;
    std::cout << "Nand: " << outputNand->getValue() << std::endl;
    std::cout << "Not: " << outputNot->getValue() << std::endl;
    */

    return a.exec();
}
