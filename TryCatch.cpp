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
        unsigned int id;
    public:
        ErrorsId(std::string error)
            : ArrayException(error)
        {id = 1;}

        inline const unsigned int getId() const {return id;}

    };
    
    void caller()
    {
        IntArray array;
    
        try
        {
            int value{ array[5] };
        }
        catch (const ArrayException &exception)
        {
            std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
            // std::cerr << "Error num:" << exception.getId() << "\n";
        }
    }
}