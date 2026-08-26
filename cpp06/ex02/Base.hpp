#pragma once

class Base {
    public:
       virtual ~Base(); //For dynamic_cast to identify derived types, Base must be polymorphic
};

class A : public Base {};
class B : public Base {};
class C : public Base {};