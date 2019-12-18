#include "bridge.h"

int main() {
    Scheduler *sch = new DisplayScheduler();
    // System *system = new LinuxSystem(sch);
    System *system = new WindowsSystem(sch);
    system->Execute();
}