//
// Created by Alex Python on 11/29/17.
//
#include "UI.h"
#include "UITester.h"
#include <iostream>

void UIRunTester(UI& testUI) {
    testUI.run();
}

void testUI() {
    InventoryManager* testManager = new InventoryManager("saveFile");
    UI* testUI = new UI(testManager);
    UIRunTester(*testUI);
}

