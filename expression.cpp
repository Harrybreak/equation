#include "expression.h"

using namespace std;

Expression::Expression(operateur op, vector<Expression> operandes) : _last(0.0), _op(op), var_name("") { copy(operandes.begin(), operandes.end(), _operandes); }
Expression::Expression() : Expression(constant, vector<Expression>()) {}
Expression::Expression(double a) : Expression() { _last = a; }
Expression::Expression(string s) : Expression() { var_name = s; }

Expression::~Expression() {}


double Expression::eval(map<string,double> vars)
{
    // VARIABLE CASE
    if (_op == variable)
        for (pair<string,double> p : vars)
            if (var_name == p.first)
                return _last = p.second;
    // OPERATOR CASE
    else if (_op != constant)
        return _op(_operandes, vars);
    // CONSTANT OR VARNAME NOT FOUND CASE
    return _last;
}

operateur Expression::getop() const { return _op; }

double constant(vector<Expression> exps, map<string,double> vars) { return 0.0; }

double identity(vector<Expression> exps, map<string,double> vars)
{
    if (exps.size() != 1)
        throw invalid_argument("error size exps in identity operator");
    return exps[0].eval(vars);
}

double variable(vector<Expression> exps, map<string,double> vars) { return 0.0; }

double addition(vector<Expression> exps, map<string,double> vars)
{
    if (exps.size() != 2)
        throw invalid_argument("error size exps in addition operator");
    return exps[0].eval(vars) + exps[1].eval(vars);
}

double subtraction(vector<Expression> exps, map<string,double> vars)
{
    if (exps.size() != 2)
        throw invalid_argument("error size exps in subtraction operator");
    return exps[0].eval(vars) - exps[1].eval(vars);
}

double multiplication(vector<Expression> exps, map<string,double> vars)
{
    if (exps.size() != 2)
        throw invalid_argument("error size exps in multiplication operator");
    return exps[0].eval(vars) * exps[1].eval(vars);
}

double divide(vector<Expression> exps, map<string,double> vars)
{
    if (exps.size() != 2)
        throw invalid_argument("error size exps in divide operator");
    return exps[0].eval(vars) / exps[1].eval(vars);
}

double sum(vector<Expression> exps, map<string,double> vars)
{
    double r = 0.0;
    for (Expression e : exps) r += e.eval(vars);
    return r;
}

double logarithm(vector<Expression> exps, map<string,double> vars)
{
    if (exps.size() != 1)
        throw invalid_argument("error size exps in log operator");
    return log(exps[0].eval(vars));
}

double exponent(vector<Expression> exps, map<string,double> vars)
{
    if (exps.size() != 1)
        throw invalid_argument("error size exps in exp operator");
    return exp(exps[0].eval(vars));
}

double derivate(vector<Expression> exps, map<string,double> vars)
{
    if (exps.size() != 3)
        throw invalid_argument("error size exps in derivate operator");
    if (exps[2].getop() != variable)
        throw invalid_argument("error type argument");
}

double integrate(vector<Expression> exps, map<string,double> vars)
{
    if (exps.size() != 4)
        throw invalid_argument("error size exps in integrate operator");
    return 0.0;
}