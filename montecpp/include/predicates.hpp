#pragma once
#include <functional>

class Predicate {
    public:
    Predicate( std::function<bool(double)> _pred ): pred{_pred}{};

    eval( double val) { return pred(val);};

    private:
    const std::function<bool(double)> pred;
};

class Equals : public Predicate {
    public:
    Equals ( double _eq): eq{_eq}, pred {[=eq](double x){return x == eq;};} {};

    private:
    double eq;
    using Predicate::pred; // neccesary?
};

class EqualsEps : public Predicate {
    public:
    EqualsEps ( double _eq, double _eps): eq{_eq}, eps{_eps}, pred {[=eq, =eps](double x){return abs(x - eq) < eps;};} {};

    private:
    // double eq;
    // double eps;
    using Predicate::pred; // neccesary?
};

class Between : public Predicate {
    public:
    Between ( double _min, double _max): /*min{_min}, max{_max}, */pred {[=_min, =_max](double x){return abs(x - eq) < eps;};} {};

    private:
    // double min;
    // double max;
};

class LessThan : public Predicate {
    public:
    LessThan ( double a): pred {[=a](double x){return x < a;};} {};

    private:
};

class MoreThan : public Predicate {
    public:
    LessThan ( double a): pred {[=a](double x){return x > a;};} {};

    private:
};


class Conjuction : Predicate {
    public:
    Conjuction( Predicate* _p, Predicate* _q, std::function<bool(Predicate, Predicate) _pred):p{_p}, q{_q}, pred{_pred} {};

    private:
    const Predicate* p;
    const Predicate* q;
    std::function<bool(Predicate*, Predicate*)> pred;
};

class And : Conjuction {
    public:
    And(Predicate _p, Predicate _q ): p{_p}, q{_q}, pred {[=p,=q](){ return p->eval() && q->eval();};} {};
}







