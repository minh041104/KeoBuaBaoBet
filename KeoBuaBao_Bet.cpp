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
    int init_choice;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 3);

    while(running_app) {
        cout<<"Nhap lua chon cua ban: 1.Nap tien    2.Kiem tra so du    3.Choi game     4.QUIT\n";
        cin>>init_choice;

        switch (init_choice)
        {
            case 1:
                cout<<"Vui long nhap so tien ban muon nap:";
                unsigned long long deposit;
                cin >> deposit;
                balance += deposit;
                cout<<"Ban da nap: "<<deposit<<" VND vao tai khoan\n";
                break;
            case 2:
                cout<<"So du hien tai la: " << balance<<" VND\n";
                break;
            case 3:
                running_game = true;
                running_app = false;
                system("cls");
                break;
            case 4:
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
            cout<<"Nhap so tien ma ban muon dat cuoc (Ti le 1 an 2):";
            unsigned long long bet;
            cin>> bet;

            while (bet > balance) {
                cout<<"Ban nhap so tien dat cuoc lon hon so du, xin vui long nhap lai:";
                cin>>bet;
            }

            cout<< "Nhap lua chon cua ban:\n1.Keo 2.Bua 3.Bao 4.QUIT\n";
            int your_choice;
            cin >> your_choice;
            system("cls");
            switch (your_choice)
            {
                case 1:
                    cout<<"Ban chon: Keo \n";
                    break;
                case 2:
                    cout<<"Ban chon: Bua \n";
                    break;
                case 3:
                    cout<<"Ban chon: Bao \n";
                    break;
                case 4:
                    running_game = false;
                    running_app =true;
                    system("cls");
                    break;
            }
            
            int com_choice = dist(gen);
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
