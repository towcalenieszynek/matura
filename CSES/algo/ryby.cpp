#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, bool>> ryby;
    ryby.push_back({4, false});
    ryby.push_back({3, true});
    ryby.push_back({2, false});
    ryby.push_back({1, false});
    ryby.push_back({5, false});

    vector<int> stos;
    int res = 0;

    for (auto ryba : ryby)
    {
        bool pod_prad = ryba.second;
        if (!pod_prad)
        {
            while (true) {
                if (stos.empty()) 
                    {
                        res++;
                        break;
                    }
                    else {
                        if (ryba.first < stos.back())
                        {
                            break;
                        }
                        else
                        {
                            stos.pop_back();
                        }
                    }
            }
        }
        else
        {
            stos.push_back(ryba.first);
        }
    }

    cout << "wynik " << res + stos.size();

}