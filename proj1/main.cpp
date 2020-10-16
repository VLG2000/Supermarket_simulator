#include <iostream>
#include<fstream>
using namespace std;
class item
{
public:
    string name;
    float cost,qnt;
    item(){};
    item(string n,float c,float q);
    friend ofstream & operator<<(ofstream &of, item &i);
    friend ifstream & operator>>(ifstream &inf,item &i);
};
item:: item(string n,float c,float q)
{
    name=n;
    cost=c;
    qnt=q;
}
ofstream & operator<<(ofstream &of, item &i)
{
    of<<i.name<<endl<<i.cost<<endl<<i.qnt<<endl;
}
ifstream & operator>>(ifstream &inf,item &i)
{
    inf>>i.name>>i.cost>>i.qnt;
    return inf;
}

int main()
{
    int ch;
    cout<<"1.Write into file"<<endl;
    cout<<"2.Read from file"<<endl;
    cout<<"Enter your choice :";
    cin>>ch;
    switch(ch)
    {
    case 1:
        {
           ofstream o("item.txt");
           cout<<"Enter number of items you want input: ";
           int n;
           cin>>n;
           for (int i=0;i<n;i++)
           {
               string n;
               float c,q;
               cout<<"For item no"<<i+1<<endl;
               cout<<"Enter name: ";
               cin>>n;
               cout<<"Enter price: ";
               cin>>c;
               cout<<"Enter quantity: ";
               cin>>q;
               item it(n,c,q);
               o<<it;
           }
           cout<<"Input has been taken please check file \"item \. txt\"";
           break;
        }
        case 2:
            {
                ifstream in;
                in.open("item.txt");
                if(!in.is_open())
                {
                    cout<<"File does not exist";
                    break;
                }
                else
                {
                    int n;
                    cout<<"Enter number of items you want to see: ";
                    cin>>n;
                    for (int i=0;i<n;i++)
                    {
                        if(in.eof())
                        {
                            cout<<"file has ended ";
                            break;
                        }
                        else
                        {
                            item it;
                            in>>it;
                            cout<<"Item number "<<i+1<<it.name<<endl<<it.cost<<endl<<it.qnt<<endl;
                        }
                    }
                }
                break;
            }
        default:
            cout<<"wrong input please try again";
    }
}
