#include "Span.h"
#include <ctime>

#define MAGENTA "\033[1;35m"
#define END     "\033[0m"
#define RED     "\033[1;31m"


static void fill(std::vector<int>& _vector);

int main()
{
    
    std::cout << MAGENTA << "Hello, I will create a Class Span, filling it using addNumber : " << END << std::endl;
    Span myspan(10);   
    
    for (int i = 0; i < 13; i++)
    {
        try 
        {
            std::cout << "trying to add " << i + i << std::endl;
            myspan.addNumber(i + i);
        }
        catch (const std::exception& e)
        {
            std::cerr << RED << e.what() << END << std::endl;
        }
    }
    std::cout << "my span is : "; 
    myspan.printSpan();

    try {
       std::cout << "shortest Span is : " << myspan.shortestSpan() << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << RED << e.what() << END << std::endl;
    }
    try {
       std::cout << "longest Span is : "<< myspan.longestSpan() << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << RED << e.what() << END << std::endl;
    }
    
    std::cout << MAGENTA << std::endl << "Time to test my methods on invalid Spans" << END << std::endl;
    
    Span emptyspan(0);
    Span solospan(1);
    Span nonfilledspan(100);

    try {
        std::cout << "longest Span is : " << emptyspan.longestSpan() << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << RED << e.what() << END << std::endl;
    }
    try {
        std::cout << "longest Span is : " << solospan.longestSpan() << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << RED << e.what() << END << std::endl;
    }
    try {
        std::cout << "longest Span is : " << nonfilledspan.longestSpan() << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << RED << e.what() << END << std::endl;
    }
    try {
        std::cout << "shortest Span is : " << emptyspan.shortestSpan() << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << RED << e.what() << END << std::endl;
    }
    try {
        std::cout << "shortest Span is : " << solospan.shortestSpan() << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << RED << e.what() << END << std::endl;
    }
    try {
        std::cout << "shortest Span is : " << nonfilledspan.shortestSpan() << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << RED << e.what() << END << std::endl;
    }
    

    std::cout << MAGENTA << "Time to add a bunch of numbers at once !" << END << std::endl;
    
    Span myspan2(30);
    
    // //Creating my new Vector of int that we will add to our span;
    std::vector<int> toadd;
    toadd.reserve(15);
    fill(toadd);

    std::cout << MAGENTA;
    try 
    { 
        myspan2.addManyNumbers(toadd);
    }
    catch (const std::exception& e)
    {
        std::cerr << END << RED << e.what() << END << std::endl;
    }
    std::cout << END;

    // //Creating my new Vector of int thats way too big for our current span;
    std::vector<int> toaddBIG;
    toaddBIG.reserve(10000);
    fill(toaddBIG);

    std::cout << MAGENTA;
    try 
    { 
        myspan2.addManyNumbers(toaddBIG);
    }
    catch (const std::exception& e)
    {
        std::cerr << END << RED << e.what() << END << std::endl;
    }
    std::cout << END;
    myspan2.printSpan();

    
    //UNCOMMENT BELOW TO SEE ME ADD 10000 numbers
    
    // std::cout << MAGENTA << "Let's make a Span class big enough for all these numbers !" << END << std::endl;
    // Span big_span(10000);
    // std::cout << MAGENTA;
    // try 
    // { 
    //     big_span.addManyNumbers(toaddBIG);
    // }
    // catch (const std::exception& e)
    // {
    //     std::cerr << END << RED << e.what() << END << std::endl;
    // }
    // std::cout << END;
    // big_span.printSpan();
    // try {
    //     std::cout << "shortest Span is : " << big_span.shortestSpan() << std::endl;
    // }
    // catch(const std::exception& e) {
    //     std::cerr << RED << e.what() << END << std::endl;
    // }
    // try {
    //     std::cout << "longest Span is : "<< big_span.longestSpan() << std::endl;
    // }
    // catch(const std::exception& e) {
    //     std::cerr << RED << e.what() << END << std::endl;
    // }
    return 0;
}

static void fill(std::vector<int>& _vector)
{
	unsigned int    start;
    unsigned int    end;

	start = _vector.size();
    end = _vector.capacity();
    srand((unsigned)time(0));
	while (start < end)
	{
		_vector.push_back(rand() % end); //% end just to get smaller values
		start++;
	}
}


