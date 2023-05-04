#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <Windows.h>
using namespace std;

int main() {
    bool running_game = false;
    bool running_app = true;
    unsigned long long balance = 0;
    unsigned long long deposit;
    unsigned long long withdraw;
    int init_choice;
    int your_choice;
    int com_choice;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 3);

    while(running_app) {
        cout<<"Nhap lua chon cua ban: 1.Nap tien    2.Rut tien    3.Kiem tra so du    4.Choi game     5.QUIT\n";
        cin>>init_choice;

        switch (init_choice)
        {
            case 1:
                cout<<"Vui long nhap so tien ban muon nap:";
                cin >> deposit;
                balance += deposit;
                cout<<"Ban da nap: "<<deposit<<" VND vao tai khoan\n";
                break;
            case 2:
                cout<<"Vui long nhap so tien ban muon rut (So tien rut khong duoc lon hon so du):";
                cin >> withdraw;
                while (withdraw > balance) {
                        cout<<"Ban nhap so tien rut lon hon so du, xin vui long nhap lai:";
                        cin>>withdraw;
                    }
                balance -= withdraw;
                cout<< "So du -"<< withdraw<<endl;
                cout<<"Ban da rut: "<< withdraw <<" VND\n";
                break;
            case 3:
                cout<<"So du hien tai la: " << balance<<" VND\n";
                break;
            case 4:
                running_game = true;
                running_app = false;
                system("cls");
                break;
            case 5:
                running_app = false;
                break;
        }    
        while(running_game) {
            if(balance == 0) {
                cout<<"So du cua ban khong du de choi tiep! Xin ban hay nap tien roi tiep tuc.\n";
                running_game = false;
                running_app = true;
                break;
            }
            cout<<"So du hien tai: " << balance << endl;

            cout<< "Nhap lua chon cua ban:\n1.Keo 2.Bua 3.Bao 4.QUIT\n";
            cin >> your_choice;
            unsigned long long bet;

            system("cls");
            cout<<"So du hien tai: " << balance << endl;
            switch (your_choice)
            {
                case 1:
                    cout<<"Ban chon: Keo \n";
                    cout<<"Nhap so tien ma ban muon dat cuoc (Ti le 1 an 2):";
                    cin>> bet;

                    while (bet > balance) {
                        cout<<"Ban nhap so tien dat cuoc lon hon so du, xin vui long nhap lai:";
                        cin>>bet;
                    }
                    break;
                case 2:
                    cout<<"Ban chon: Bua \n";
                    cout<<"Nhap so tien ma ban muon dat cuoc (Ti le 1 an 2):";
                    cin>> bet;

                    while (bet > balance) {
                        cout<<"Ban nhap so tien dat cuoc lon hon so du, xin vui long nhap lai:";
                        cin>>bet;
                    }
                    break;
                case 3:
                    cout<<"Ban chon: Bao \n";
                    cout<<"Nhap so tien ma ban muon dat cuoc (Ti le 1 an 2):";
                    cin>> bet;

                    while (bet > balance) {
                        cout<<"Ban nhap so tien dat cuoc lon hon so du, xin vui long nhap lai:";
                        cin>>bet;
                    }
                    break;
                case 4:
                    running_game = false;
                    running_app =true;
                    system("cls");
                    break;
            }
            
            com_choice = dist(gen);
            if (running_game) {
                if (com_choice == 1){
                cout<< "Computer: Keo \n";
                    if(your_choice == 2) {
                        balance += bet;
                        cout<<"You win\nSo du +"<<bet;
                    }else if(your_choice == com_choice) {
                        cout<<"Draw";
                    } else {
                        balance -= bet;
                        cout<< "You lose\nSo du -"<<bet;
                    }
                }
                if (com_choice == 2){
                    cout<< "Computer: Bua \n";
                    if(your_choice == 3) {
                        balance += bet;
                        cout<<"You win\nSo du +"<<bet;
                    }else if(your_choice == com_choice) {
                        cout<<"Draw";
                    } else {
                        balance -= bet;
                        cout<< "You lose\nSo du -"<<bet;
                    }
                }
                if (com_choice == 3){
                cout<< "Computer: Bao \n";
                    if(your_choice == 1) {
                        balance += bet;
                        cout<<"You win\nSo du +"<<bet;
                    }else if(your_choice == com_choice) {
                        cout<<"Draw";
                    } else {
                        balance -= bet;
                        cout<< "You lose\nSo du -"<<bet;
                    }
                }
                cout<<endl;
            }
        }
    } 
}
