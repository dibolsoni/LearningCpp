#include <bitset>
#include <iostream>


void bit_manipulation()
{
    std::bitset<8> bits{ 0b0000'0101 }; // we need 8 bits, start with bit pattern 0000 0101
    bits.set(3); // set bit position 3 to 1 (now we have 0000 1101)
    bits.flip(4); // flip bit 4 (now we have 0001 1101)
    bits.reset(4); // set bit 4 back to 0 (now we have 0000 1101)
 
    std::cout << "All the bits: " << bits << '\n';
    std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
    std::cout << "Bit 4 has value: " << bits.test(4) << '\n';
}

void binaries_count(int total)
{

    for (int i = 0; i <= total; i++)
    {
        std::cout << i << "- \t" << std::bitset<8>(i) << '\n';
    }

}

void bitwise_operators()
{
    std::bitset<4> x { 0b1100 };
 
    // the >>= works as ++= on integers
    std::cout << x << '\n';
    std::cout << (x >> 1) << '\n'; // shift right by 1, 1100 yielding 0110
    std::cout << (x << 1) << '\n'; // shift left by 1, 1100 yielding 1000

    //bitwise NOT = flips
    std::cout << std::bitset<4>{ ~0b0100u } << ' ' << std::bitset<8>{ ~0b0100u };

    //bitwise OR = evaluates the numbers as OR in true table
    std::cout << (std::bitset<4>{ 0b0101 } | std::bitset<4>{ 0b0110 });

    //bitwise AND = evaluates the numbers as AND in true table
    std::cout << (std::bitset<4>{ 0b0101 } & std::bitset<4>{ 0b0110 });

    //bitwise XOR (exclusive or) = 
        //one and only one of its operands is true (1). 
        //If neither or both are true, it evaluates to 0
    std::cout << (std::bitset<4>{ 0b0101 } ^ std::bitset<4>{ 0b0110 });
}

void bit_masks()
{
    constexpr std::uint_fast8_t mask0{ 0b0000'0001 }; // represents bit 0
	constexpr std::uint_fast8_t mask1{ 0b0000'0010 }; // represents bit 1
	constexpr std::uint_fast8_t mask2{ 0b0000'0100 }; // represents bit 2 
	constexpr std::uint_fast8_t mask3{ 0b0000'1000 }; // represents bit 3
	constexpr std::uint_fast8_t mask4{ 0b0001'0000 }; // represents bit 4
	constexpr std::uint_fast8_t mask5{ 1 << 5 }; // 0010 0000
    constexpr std::uint_fast8_t mask6{ 1 << 6 }; // 0100 0000
    constexpr std::uint_fast8_t mask7{ 1 << 7 }; // 1000 0000
 
	std::uint_fast8_t flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags
 
	std::cout << "bit 0 is " << ((flags & mask0) ? "on\n" : "off\n");
	std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

    //setting a bit ON using OR operand
    flags |= mask1; // turn on bit 1
    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");
    flags |= (mask4 | mask5); // turn bits 4 and 5 on at the same time
    std::cout << "bit 4 is " << ((flags & mask4) ? "on\n" : "off\n");
    std::cout << "bit 5 is " << ((flags & mask5) ? "on\n" : "off\n");

    //setting a bit OFF using AND and NOT operand
    flags &= ~mask2; // turn off bit 2
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");

    //flipping bit using XOR operand
    flags ^= mask2; // flip bit 2
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");

    //a example of using <bitset> to manipulate
    std::bitset<8> isHungry{	0b0000'0001 };
	std::bitset<8> isSad{		0b0000'0010 };
	std::bitset<8> isMad{		0b0000'0100 };
	std::bitset<8> isHappy{		0b0000'1000 };
	std::bitset<8> isLaughing{	0b0001'0000 };
	std::bitset<8> isAsleep{	0b0010'0000 };
	std::bitset<8> isDead{		0b0100'0000 };
	std::bitset<8> isCrying{	0b1000'0000 };
 
 
	std::bitset<8> me{}; // all flags/options turned off to start
	me |= isHappy | isLaughing; // I am happy and laughing
	me &= ~isLaughing; // I am no longer laughing
 
	// Query a few states (we use the any() function to see if any bits remain set)
	std::cout << "I am happy? " << (me & isHappy).any() << '\n';
	std::cout << "I am laughing? " << (me & isLaughing).any() << '\n';
}

void bit_mask_multiple_bits()
{
    constexpr std::uint_fast32_t redBits{ 0xFF000000 };
	constexpr std::uint_fast32_t greenBits{ 0x00FF0000 };
	constexpr std::uint_fast32_t blueBits{ 0x0000FF00 };
	constexpr std::uint_fast32_t alphaBits{ 0x000000FF };
 
	std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
	std::uint_fast32_t pixel{};
	std::cin >> std::hex >> pixel; // std::hex allows us to read in a hex value
 
	// use Bitwise AND to isolate red pixels,
	// then right shift the value into the lower 8 bits
	// (we're not using brace initialization to avoid a static_cast)
	std::uint_fast8_t red = (pixel & redBits) >> 24;
	std::uint_fast8_t green = (pixel & greenBits) >> 16;
	std::uint_fast8_t blue = (pixel & blueBits) >> 8;
	std::uint_fast8_t alpha = pixel & alphaBits;
 
	std::cout << "Your color contains:\n";
	std::cout << std::hex; // print the following values in hex
	std::cout << static_cast<int>(red) << " red\n";
	std::cout << static_cast<int>(green) << " green\n";
	std::cout << static_cast<int>(blue) << " blue\n";
	std::cout << static_cast<int>(alpha) << " alpha\n";
}

void bit_mask_exercise() 
{
    constexpr std::uint_fast8_t option_viewed{ 0x01 };
    constexpr std::uint_fast8_t option_edited{ 0x02 };
    constexpr std::uint_fast8_t option_favorited{ 0x04 };
    constexpr std::uint_fast8_t option_shared{ 0x08 };
    constexpr std::uint_fast8_t option_deleted{ 0x10 };
 
    std::uint_fast8_t myArticleFlags{};
    
    //Write a line of code to set the article as viewed.
    myArticleFlags |= option_viewed;
    std::cout << "My article is viewed? " << ((myArticleFlags & option_viewed)? "yes" : "no") << '\n';
    
    //b) Write a line of code to check if the article was deleted.
    std::cout << "My article was deleted? " << (myArticleFlags & option_deleted ? "yes" : "no") << '\n';

    //c) Write a line of code to clear the article as a favorite.
    myArticleFlags &= ~option_favorited;
    std::cout << "My article is favorited? " << (myArticleFlags & option_favorited ? "yes" : "no") << '\n';
}
