#ifndef FILE_WAS_DAMAGER_EXCEPTION
#define FILE_WAS_DAMAGER_EXCEPTION
#include <string>
class FileWasDamagedException : public std::exception{
private:
    std::string message;

public:
    FileWasDamagedException();
    virtual const char* what() const noexcept override;
};
#endif 


