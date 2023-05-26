#ifndef EXPRESSION_H
#define EXPRESSION_H 1

#define _USE_MATH_DEFINES
#include <vector>
#include <iostream>
#include <map>
#include <cmath>

// #include <gsl/gsl_math.h>

#define MARGE   0.05

#define error(s) return(cout<<s<<endl)?EXIT_FAILURE:1

const static double undefined = *(double*) 0xFFFFFFFF;

enum TypeExp { CONSTANT , VARIABLE , FUNCTION , OPERATOR , N_FUNCTION };
typedef enum TypeExp TypeExp;

class Expression
{
    public:
        Expression(double (*op)(std::vector<Expression>, std::map<std::string,double>), std::vector<Expression>);
        Expression(double);
        Expression(std::string);
        Expression();
        ~Expression();

        virtual double eval(std::map<std::string,double> vars = std::map<std::string,double>());

        virtual TypeExp getop() const;
        virtual std::string getVarName() const;

    protected:
        std::vector<Expression> _operandes;
        double (*_op)(std::vector<Expression>, std::map<std::string,double>);
        TypeExp _type;
        double _last;
        std::string var_name;
};

typedef double (*operateur)(std::vector<Expression>, std::map<std::string,double>);

double constant         (std::vector<Expression> exps, std::map<std::string,double> vars = std::map<std::string,double>());
double identity         (std::vector<Expression> exps, std::map<std::string,double> vars = std::map<std::string,double>());
double variable         (std::vector<Expression> exps, std::map<std::string,double> vars = std::map<std::string,double>());
double addition         (std::vector<Expression> exps, std::map<std::string,double> vars = std::map<std::string,double>());
double subtraction      (std::vector<Expression> exps, std::map<std::string,double> vars = std::map<std::string,double>());
double multiplication   (std::vector<Expression> exps, std::map<std::string,double> vars = std::map<std::string,double>());
double divide           (std::vector<Expression> exps, std::map<std::string,double> vars = std::map<std::string,double>());
double sum              (std::vector<Expression> exps, std::map<std::string,double> vars = std::map<std::string,double>());
double logarithm        (std::vector<Expression> exps, std::map<std::string,double> vars = std::map<std::string,double>());
double exponent         (std::vector<Expression> exps, std::map<std::string,double> vars = std::map<std::string,double>());
double derivate         (std::vector<Expression> exps, std::map<std::string,double> vars = std::map<std::string,double>());
double integrate        (std::vector<Expression> exps, std::map<std::string,double> vars = std::map<std::string,double>());

#endif // EXPRESSION_H