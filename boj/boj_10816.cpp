#include <iostream>
#include <map>
using namespace std;
map<int, int> cards;
int main()
{    
    cin.sync_with_stdio(false);    
    cin.tie(NULL);    
    int n, m;    
    cin >> n;    
    while (n--) 
    {        
        int num;        
        cin >> num;        
        cards[num]++;    
    }    
    cin >> m;    
    while (m--) 
    {        
        int num;        
        cin >> num;        
        cout << cards[num] << ' ';    
    }     
    return 0;
}
