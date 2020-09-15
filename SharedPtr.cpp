#include <iostream>
#include <memory> // for std::shared_ptr
#include <string>
 

namespace SharedPrt
{
		
	class Resource
	{
	public:
		Resource() { std::cout << "Resource acquired\n"; }
		~Resource() { std::cout << "Resource destroyed\n"; }
	};
	
	int main()
	{
		// allocate a Resource object and have it owned by std::shared_ptr
		auto ptr1 = std::make_shared<Resource>();
		{
			auto ptr2 = ptr1; // create ptr2 using copy initialization of ptr1
	
			std::cout << "Killing one shared pointer\n";
		} // ptr2 goes out of scope here, but nothing happens
	
		std::cout << "Killing another shared pointer\n";
	
		return 0;
	} // ptr1 goes out of scope here, and the allocated Resource is destroyed

	namespace CircularDependency
	{
		class Person
		{
			std::string m_name;
			// with shared_ptr, no object will be destroyed because of circular dependency. the last
			//keeps the first alive
			//std::shared_ptr<Person> m_partner; // initially created empty
			//to fix this problem, c++ has weak_ptr
			//only use weak_ptr when has circular dependency
			std::weak_ptr<Person> m_partner;

		public:
			Person(const std::string& name): m_name(name)
			{
				std::cout << m_name << " created\n";
			}
			~Person()
			{
				std::cout << m_name << " destroyed\n";
			}

			friend bool partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
			{
				if (!p1 || !p2)
					return false;

				p1->m_partner = p2;
				p2->m_partner = p1;

				std::cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';

				return true;
			}
			// to access weak_ptr u must use lock(). that converts weak_ptr into shared_ptr
			const std::shared_ptr<Person> getPartner()const {return m_partner.lock();}
			const std::string getName() const {return m_name;}
		};

		void caller()
		{
			auto lucy = std::make_shared<Person>("Lucy"); //create a person named lucy
			auto ricky = std::make_shared<Person>("Ricky"); //create a person named Ricky

			partnerUp(lucy, ricky); // Make "Lucy" point to "Ricky" and vice

			auto partner = ricky->getPartner(); // get shared_ptr to Ricky's partner
			std::cout << ricky->getName() << "'s partner is: " << partner->getName() << '\n';

		}
	}
}
