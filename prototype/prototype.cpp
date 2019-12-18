#include "prototype.h"
#include <memcpy>

using namespace std;

int main() {
    Resume* resume = new ResumeA("google", "2015-2017");
    resume->ShowResume();

    cout << "copy :" << endl;
    Resume* resume_copy = resume->Clone("baidu", "2017-2019");
    resume->ShowResume();
    resume_copy->ShowResume();
    delete resume_copy;
    delete resume;
    resume = nullptr;
    resume_copy = nullptr;
}