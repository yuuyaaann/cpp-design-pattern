#include <iostream>
#include "state.h"


EngineBox::EngineBox() {
    state =  new EngineIdle();
}

void EngineBox::up () {
    state->up(this);
}

void EngineBox::down () {
    state->down(this);
}

void EngineBox::nowState () {
    state->showCurrentState();
}
void EngineBox::changeState (EngineState *newState) {
    delete state;
    state = newState; 
}

void EngineIdle::up(EngineBox* pEBoX) {
    std::cout << "idle->Low" << std::endl;
    pEBoX->changeState(new EngineRunningLow());
}

void EngineIdle::down(EngineBox* pEBoX) {
    std::cout << "No Change" << std::endl;
    pEBoX->changeState(new EngineIdle());
}

void EngineIdle::showCurrentState() {
    std::cout << "State:idle" << std::endl;
}


void EngineRunningLow::up(EngineBox* pEBoX) {
    std::cout << "Low->High" << std::endl;
    pEBoX->changeState(new EngineRunningHigh());
}

void EngineRunningLow::down(EngineBox* pEBoX) {
    std::cout << "Low->idle" << std::endl;
    pEBoX->changeState(new EngineIdle());
}

void EngineRunningLow::showCurrentState() {
    std::cout << "State:Low" << std::endl;
}

void EngineRunningHigh::up(EngineBox* pEBoX) {
    std::cout << "No Change" << std::endl;
    pEBoX->changeState(new EngineRunningHigh());
}

void EngineRunningHigh::down(EngineBox* pEBoX) {
    std::cout << "High->Low" << std::endl;
    pEBoX->changeState(new EngineRunningLow());
}

void EngineRunningHigh::showCurrentState() {
    std::cout << "State:High" << std::endl;
}


int main () {
    EngineBox *enginbox = new EngineBox();

    enginbox->nowState();
    enginbox->up();
    enginbox->nowState();
    enginbox->down();

    delete enginbox;

    return 0;

}