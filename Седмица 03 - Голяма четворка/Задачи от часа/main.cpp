#include <iostream>
#include "student.hpp"
#include "test.hpp"

enum class Status {
    Finished,
    InProgress,
    NotStarted
};

int main()
{
    Student anon("Yavor");
    Student student("Stukata", "8MI0800229", 1, 2, 4.25);
    Student copy(student);
    copy.setName("Georgi");
    student.print();
    anon.print();

    Status status = Status::Finished;
    if(status == Status::InProgress) {

    }
    else if (status == Status::Finished) {

    }
    return 0;
}