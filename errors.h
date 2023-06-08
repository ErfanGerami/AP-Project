#ifndef ERRORS_H
#define ERRORS_H


class Errors
{
public:
    Errors();
    Errors(int stat);
    int GetError();
    static int file_openning_error;

private:
    int stat;

};
#endif // ERRORS_H
