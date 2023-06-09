#ifndef FILEHANDELING_H
#define FILEHANDELING_H

#include <fstream>
#include <QString>
#include "errors.h"
#include <vector>
class FileHandeling
{
public:
    FileHandeling();
    static std::vector<QString> read(QString path);
    static void write(QString path,QString content);
    static QString Encrypt(QString string);
    static QString Decrypt(QString string);
    static bool IsAPlayer(QString path);
private:
    static int key(int index);

};

#endif // FILEHANDELING_H
