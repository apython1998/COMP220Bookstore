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
    printf("\n*************************\nTESTING UI (Manual):\n*************************\n");
    InventoryManager* testManager = new InventoryManager("saveFile");
    UI* testUI = new UI(testManager);
    UIRunTester(*testUI);
}

