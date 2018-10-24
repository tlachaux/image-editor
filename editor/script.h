#ifndef SCRIPT_H
#define SCRIPT_H

#include <QVector>
#include <QImage>

typedef double (*Function)(double, double);

struct Instruction
{
    int        first;
    int        second;
    int        result;
    Function    function;
};

class Script
{
public:
    Script(const QString& sources);
    QRgb execute(const QImage& image, int x, int y);

private:
    void parse(const QString& sources, int index);

    QVector<double>         variables;
    QVector<Instruction>    instructions;
};

#endif // SCRIPT_H
