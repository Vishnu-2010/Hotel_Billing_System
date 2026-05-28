#include<iostream>
#include<fstream>
using namespace std;
class hotel
{
protected:
    int am = 0;
    int sno = 0;
    int tax;
    int product;
    int a;
public:
    void menu()
    {
        cout << "\t1_dosa" << endl;
        cout << "\t2_idly" << endl;
        cout << "\t3_vada" << endl;
        cout << "\t4_upma" << endl;
        cout << "\t5_uttapam" << endl;
        cout << "\t6_pongal" << endl;
        cout << "\t7_pesarattu" << endl;
        cout << "\t8_bonda" << endl;
        cout << "\t9_biryani" << endl;
        cout << "\t10_filter_coffee" << endl;
    }
    void getproductno()
    {
        cout << "\tEnter product number: ";
        cin >> product;
    }
    void getprice()
    {
        switch (product)
        {
        case 1:
            cout << "Enter number of plates of dosa bought: ";
            cin >> a;
            am += 50 * a;
            sno += a;
            break;

        case 2:
            cout << "Enter number of plates of idly bought: ";
            cin >> a;
            am += 50 * a;
            sno += a;
            break;

        case 3:
            cout << "Enter number of plates of vada bought: ";
            cin >> a;
            am += 15 * a;
            sno += a;
            break;

        case 4:
            cout << "Enter number of plates of upma bought: ";
            cin >> a;
            am += 60 * a;
            sno += a;
            break;

        case 5:
            cout << "Enter number of plates of uttapam bought: ";
            cin >> a;
            am += 70 * a;
            sno += a;
            break;

        case 6:
            cout << "Enter number of plates of pongal bought: ";
            cin >> a;
            am += 60 * a;
            sno += a;
            break;

        case 7:
            cout << "Enter number of plates of pesarattu bought: ";
            cin >> a;
            am += 70 * a;
            sno += a;
            break;

        case 8:
            cout << "Enter number of bonda bought: ";
            cin >> a;
            am += 15 * a;
            sno += a;
            break;

        case 9:
            cout << "Enter number of plates of biryani bought: ";
            cin >> a;
            am += 150 * a;
            sno += a;
            break;

        case 10:
            cout << "Enter number of filter coffee bought: ";
            cin >> a;
            am += 25 * a;
            sno += a;
            break;

        default:
            cout << "Invalid product!\n";
        }
    }
};
class bill:public hotel
{
public:
    void getbill()
    {
        ofstream file("swipe.txt",ios::app);
        cout << "\tthe number of items that you entered is : " << sno << endl;
        cout << "\tyour total is\t\t\t\t: " << am << endl;
        tax = (am * 5) / 100;
        cout << "\tgst\t\t\t\t\t: " << tax << endl;
        cout << "\tyour grand total is\t\t\t:" << tax + am;
        cout << endl << "\t\t\tTHANK YOU FOR VISITING US!" << endl;
        file << "number of items : " << sno << endl;
        file << "total amount    : " << am << endl;
        file << "tax             : " << tax << endl;
        file << "grand total     : " << tax + am << endl<<endl;
        file.close();
    }
};
int main()
{
    char ans = 'y';
    hotel h;
    bill b;

    while (ans == 'y' || ans == 'Y')
    {
        cout << "\t\t\tBilling Software" << endl << endl;
        cout << endl << "\t\tMENU:" << endl;

        b.menu();
        b.getproductno();
        b.getprice();

        cout << "\nDo you want to add more items? (y/n): ";
        cin >> ans;

        system("cls");
    }
    cout << "\t\t\tBilling Software" << endl << endl;
    cout << endl << "\t\tbill:" << endl;
    b.getbill();

    return 0;
}