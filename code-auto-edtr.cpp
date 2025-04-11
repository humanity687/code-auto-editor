#include<iostream>
#include<fstream>
#include<string>
#include<chrono>
#include<random>
#include<limits>
using namespace std;
mt19937 mt;
template<typename T>
T ilrand(T l=numeric_limits<T>::min(), T r=numeric_limits<T>::max())
{
    return uniform_int_distribution<T>(l, r)(mt);
}
int main()
{
    mt.seed(chrono::system_clock::now().time_since_epoch().count());
    string fn,tp,nm;
    cout<<"file path(name): "; cin>>fn;
    fstream fin(fn,ios::in);
    if(!fin)
    {
        cout<<"file not found\n";
        return 0;
    }
    for(int i=fn.size()-1;i>=0;--i)
    {
        if(fn[i]=='.')
        {
            tp=fn.substr(i+1,100);
            nm=fn.substr(0,i);
        }
    }
    fstream fout(nm+".md",ios::out);
    fout<<"```"<<tp<<"\n";
    int cdtp,rspc,lth;
    cout<<"Edit method? 1:anti-cheat code; 2:anti-cheat string; 3:both  ";
    cin>>cdtp;
    cout<<"Code/String length?  ";
    cin>>lth;
    cout<<"Number of spacing rows?  ";
    cin>>rspc;
    int pow10=1;
    for(int i=1;i<=lth;++i)
    {
        pow10*=10;
    }
    string nrow="",cod,str;
    int cnt=0;
    cout<<"Processing..."<<endl;
    while(getline(fin,nrow))
    {
        cnt++;
        if(cnt%rspc==0)
        {
            switch (cdtp)
            {
            case 1:
                cod=to_string(ilrand<long long>(-pow10,pow10));
                fout<<nrow<<"\ncode:"<<cod<<"\n";
                break;
            case 2:
                str="";
                for(int i=1;i<=lth;++i)
                {
                    str+=ilrand<unsigned char>();
                }
                fout<<nrow<<"\nstr:"<<str<<"\n";
                break;
            default:
                cod=to_string(ilrand<long long>(-pow10,pow10));
                fout<<nrow<<"\ncode:"<<cod;
                str="";
                for(int i=1;i<=lth;++i)
                {
                    str+=ilrand<unsigned char>();
                }
                fout<<" | str:"<<str<<"\n";
                break;
            }
        }
        else
        {
            fout<<nrow<<"\n";
        }
    }
    fout<<"```";
    cout<<"Done.\n";
    getchar();
    return 0;
}