
#include<iostream>
using namespace std;

class Rectangle
{
    private:
        double length;
        double width;
    public:
    Rectangle() //default constructor
    {
        length=0;
        width=0;
    }
        Rectangle (double l,double w)
        {   //parametarize constructor
            length=l;
            width=w;
        }
        double getrectangledetail(double l,double w)
        {
            length=l;
            width=w;
        }
        double Length()
        {
            return length;
        }
        double Width()
        {
            return width;
        }
        double calculateperimeter()
        {
            return 2*(length+width);
        }
        double calculatearea()
        {
            return length*width;
        }
};

int main()
{
    Rectangle r;
    double l,w;
    int choice;
    do
    {
          cout<<endl<<"1.Add Rectangle dimmensions"<<endl;
          cout<<"2.Update Rectangle dimmension"<<endl;
          cout<<"3.Calculate perimeter"<<endl;
          cout<<"4.Calculate area"<<endl;
          cout<<"5.Rectangle Details"<<endl;
          cout<<"6.Exit"<<endl;

          cout<<"Enter your choice:";
          cin>>choice;

          switch (choice)
          {
            case 1:
                 cout<<"Enter the lenght:";
                 cin>>l;
                 cout<<"Enter the width:";
                 cin>>w;

            r.getrectangledetail(l,w);
            break;

            case 2:
                 cout<<"Enter the  new length:";
                 cin>>l;
                 cout<<"Enter the new width:";
                 cin>>w;

                r.getrectangledetail(l,w);
                break;
            case 3:
                 cout<<"Perimeter is:"<<r.calculateperimeter()<<endl;
                break;

            case 4:
                 cout<<"Area is:"<<r.calculatearea()<<endl;
                break;
            case 5:
                 cout<<"\nRectangle Details:\n";
                 cout<<"Length:"<<l<<endl;
                 cout<<"Width:"<<w<<endl;
                 cout<<"Perimeter:"<<r.calculateperimeter()<<endl;
                 cout<<"Area:"<<r.calculatearea()<<endl;
                break;

            case 6:
                 cout<<"Exisiting....";
                break;
            default:
                 cout<<"Invalid Choice,please enter number between 1 to 4";
          }
    }while(choice!=6);
    return 0;

}
