#include <iostream>
#include <string>

namespace TryCatch
{
    class ArrayException
    {
    private:
        std::string m_error;
    
    public:
        ArrayException(std::string error)
            : m_error(error)
        {
        }
    
        const char* getError() const { return m_error.c_str(); }
    };
    
    class IntArray
    {
    private:
    
        int m_data[3]; // assume array is length 3 for simplicity
    public:
        IntArray() {}
        
        int getLength() const { return 3; }
    
        int& operator[](const int index)
        {
            if (index < 0 || index >= getLength())
                throw ArrayException("Invalid index");
    
            return m_data[index];
        }
    
    };

    class ErrorsId: public ArrayException
    {
    public:
        ErrorsId(std::string error)
            : ArrayException(error)
        {}


    };
    
    void caller()
    {
        IntArray array;
    
        try
        {
            try
            {
                int value{ array[5] };
            }
            catch (const ArrayException &exception)
            {
                std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
                // std::cerr << "Error num:" << exception.getId() << "\n";
                throw ; // rethrow the same error
            }
            catch (...)
            {
                std::cerr << "An undefined error occurs\n";
            }
        }catch (...)
        {
            std::cout << "Second catcher \n";
        }

    }
}