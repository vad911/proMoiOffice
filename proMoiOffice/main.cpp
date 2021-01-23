
#include <iostream>
#include <vector>
#include <cassert>

// ¬озвращает максимальное целое n такое, что сумма элементов numbers от 0 до n
// меньше либо равна max
// numbers[0]+...+numbers[n] <= max
int get_pos(const std::vector<unsigned>& numbers, int max)
{


    unsigned int sum = 0;
    unsigned int Size = numbers.size() - 1 ;
    int pos = 0;


    int next=0;

    // выкинем -1, если самый перв
    if (numbers[0] > max) 
    {
        return -1;
    }


    while ((pos <= Size) && ((sum + numbers[pos]) <= max) )
    {
       sum = sum + numbers[pos];
       ++next;  // index of next elem
       if (( (next <= Size) && (sum + numbers[next]) <= max))  { ++pos; }
      
         
          
    }


  
    return pos ;
}

int main()
{
    const std::vector<unsigned int> vec{ 3,3,2 };
    int max =10;
    int result = 0;
    result = get_pos(vec, max);

    std::cout << "result =" << result;

    assert(get_pos({3,3,2}, 6) == 1);
    assert(get_pos({ 3,3,2 }, 1) == 0);
    assert(get_pos({ 3,3,2 }, 3) == 0);
    assert(get_pos({ 3,3,2 }, 4) == 0);
    assert(get_pos({ 3,3,2 }, 8) == 2);
    assert(get_pos({ 3,3,2 }, 10) == 2);
}