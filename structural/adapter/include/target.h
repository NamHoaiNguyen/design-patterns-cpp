#ifndef INCLUDE_TARGET_H
#define INCLUDE_TARGET_H

#pragma once

template<typename T>
class Target {
public:
    virtual void send(T words) = 0;
};

#endif