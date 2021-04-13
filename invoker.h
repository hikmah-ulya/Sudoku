
#ifndef invoker_h
#define invoker_h

#pragma once
#include <vector>
#include "command.h"

class Invoker {
private:
    stack <Command*> Commands;
public:
    void pushCommand(Command& command);
    void popCommand();
};

void Invoker::pushCommand(Command& command) {
    Commands.push(&command);
    cout << "Command is added" << endl;
}

void Invoker::popCommand() {
    if (Commands.empty() == true) {
        cout << "The stack is empty" << endl;
    }
    else {
        cout << "command popped" << endl;
        Commands.top()->undo();
        Commands.pop();
    }
}

#endif /* invoker_h */
