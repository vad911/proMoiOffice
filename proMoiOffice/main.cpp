
#include <iostream>
#include <vector>
#include <cassert>

// Возвращает максимальное целое n такое, что сумма элементов numbers от 0 до n
// меньше либо равна max
// numbers[0]+...+numbers[n] <= max
int get_pos(const std::vector<unsigned>& numbers, int max)
{

    int pos = 0;
    unsigned int sum = numbers[pos];
    unsigned int Size = numbers.size()-1;
 
    // here im on this branch master
    // var_master = "branch_master"


    int next= pos +1;

    // выкинем -1, если самый первый элемент уже больше max
    if (numbers[0] > max) 
    {
        return -1;
    }

    

    while (next <= Size)
    {
       
       

        if ((sum + numbers[next]) <= max)
        {
               sum = sum + numbers[next];
               ++next;  // index of next elem
               ++pos;
        }
        else 
        {
            return pos;
        }
     
       
    }
  
    return pos;
}

int main()
{
    const std::vector<unsigned int> vec{ 3,3,2 };
    int max =10;
    int result = 0;
    result = get_pos(vec, max);

    std::cout << "\nresult =" << result;
    
    assert(get_pos({ 3,3,2 }, 1) == -1);
    assert(get_pos({3,3,2}, 6) == 1);
    assert(get_pos({ 3,3,2 }, 1) == -1);
    assert(get_pos({ 3,3,2 }, 3) == 0);
    assert(get_pos({ 3,3,2 }, 4) == 0);
    assert(get_pos({ 3,3,2 }, 8) == 2);
    assert(get_pos({ 3,3,2 }, 10) == 2);
    
}