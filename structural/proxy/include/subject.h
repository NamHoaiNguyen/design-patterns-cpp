#ifndef INCLUDE_SUBJECT_H
#define INCLUDE_SUBJECT_H

template<typename T>
class Subject {
public:
    ~Subject() = default;

    virtual void load() = 0;

    virtual void insert() = 0;
};

#endif