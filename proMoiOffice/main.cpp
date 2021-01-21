
#include <iostream>
#include <vector>
#include <cassert>

// ���������� ������������ ����� n �����, ��� ����� ��������� numbers �� 0 �� n
// ������ ���� ����� max
// numbers[0]+...+numbers[n] <= max
int get_pos(const std::vector<unsigned>& numbers, int max)
{
   
 
    unsigned int sum = 0;
    unsigned int maxSize = numbers.size();
    int pos = 0;

    while ( (pos < maxSize) && ((sum + numbers[pos]) < max))
    {
       sum = sum + numbers[pos];
        ++pos;
    }


  
    return pos;
}

int main()
{
    const std::vector<unsigned int> vec{ 3,3,2 };
    int max = 1;
    int result = 0;
    result = get_pos(vec, max);

    std::cout << "result =" << result;

    assert(get_pos({3,3,2}, 6) == 1);
    assert(get_pos({ 3,3,2 }, 1) == 0);
    assert(get_pos({ 3,3,2 }, 10) == 3);
}