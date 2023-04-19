#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
class spell {
public:
    int power;
    int mana_cost;
    spell()
    {
        int power = 0;
        int mana_cost = 0;
    }
    spell(int power_, int mana_cost_) {
        this->power = power_;
        this->mana_cost = mana_cost_;
    }
    void get_info()
    {
        cout << power << " " << mana_cost << endl;
    }
};
int main()
{
    int value = int(std::time(nullptr));
    for (int i = 0; i < 20; ++i)
    {
         value = (value * 73669 + 95121) % 100000;
    }
    int value1 = int(std::time(nullptr));
    for (int i = 0; i < 20; ++i)
    {
        value1 = (value1 * 73229 + 95121) % 100000;
    }
    int value2 = int(std::time(nullptr));
    for (int i = 0; i < 20; ++i)
    {
        value2 = (value2 * 73449 + 95121) % 100000;
    }
    int value3 = int(std::time(nullptr));
    for (int i = 0; i < 20; ++i)
    {
        value3 = (value3 * 78829 + 95121) % 100000;
    }
    vector<spell> v;
    spell s1(value,value2);
    spell s2(value1,value3);
    vector<int> v1;
    v1.push_back(value);
    v1.push_back(value1);
    v1.push_back(value2);
    v1.push_back(value3);
    v.push_back(s1);
    v.push_back(s2);
    cout << s1.power << " " << s1.mana_cost << endl;
    cout << s2.power << " " << s2.mana_cost << endl;

    int size = v1.size();
    int temp = 0;
    int min = 0;
    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
            min = (v1[j] < v1[min]) ? j : min;
        if (i != min)
        {
            temp = v1[i];
            v1[i] = v1[min];
            v1[min] = temp;
        }
    }
    for (int i = 0; i < size; i++)
        cout << v1[i] << '\t';
    cout << endl;
}
