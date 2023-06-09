#include "filehandeling.h"
FileHandeling::FileHandeling()
{

}
int FileHandeling::key(int index){
    //key:x^2+2x+2
    return (index*index+2*index+2)%26;
}
bool FileHandeling::IsAPlayer(QString path){
    std::ifstream file(path.toStdString(),std::ios::in);
    bool is_there= file.is_open();
    if(is_there)
        file.close();
    return is_there;

}

QString FileHandeling::Encrypt(QString str){
    std::string str_temp=str.toStdString();
    std::string encrypted_string="";
    for(int i=0;i<str.length();i++){
        if(str_temp[i]!='/'){
            if(str_temp[i]>='a')
                encrypted_string+=(str_temp[i]-'a'+FileHandeling::key(i))%26+'a';
            else
                encrypted_string+=(str_temp[i]-'A'+FileHandeling::key(i))%26+'A';
        }else{
            encrypted_string+='/';
        }
    }
    return QString(encrypted_string.c_str());
}
QString FileHandeling::Decrypt(QString str){
    std::string str_temp=str.toStdString();
    std::string decrypted_string="";
    char temp;
    for(int i=0;i<str.length();i++){
        if(str_temp[i]!='/'){
            if(str_temp[i]>='a'){
                temp=(str_temp[i]-'a'-FileHandeling::key(i));
                if(temp<0)
                    temp+=26;

                decrypted_string+=temp+'a';
            }
            else{
                temp=(str_temp[i]-'A'-FileHandeling::key(i));
                if(temp<0)
                    temp+=26;

                decrypted_string+=temp+'A';
            }
        }else{
            decrypted_string+='/';
        }
    }
    return QString(decrypted_string.c_str());

}
void FileHandeling::write(QString path,QString content){
    std::ofstream file(path.toStdString());
    if(!file.is_open())throw Errors(Errors::file_openning_error);
    file<<content.toStdString();
    file.close();

}
std::vector<QString> FileHandeling::read(QString path){

     std::ifstream file(path.toStdString());
     if(!file.is_open())throw Errors(Errors::file_openning_error);
     char c=' ';
     QString string="";
     std::vector<QString> result;
     while(true){
         while(true){
             file>>c;
             if(c=='/')
                 break;
            if(file.eof()){
                file.close();
                return result;
            }
             string+=c;

         }

         result.push_back(Decrypt(string));
         string="";
         c=' ';


     }
     file.close();
     return result;




}
