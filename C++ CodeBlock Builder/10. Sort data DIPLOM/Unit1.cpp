//---------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <iomanip.h>
#include <cmath>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
ifstream in ("IRKL1119.txt");
ofstream out ("output.txt");

    string a;
    //���������� �� �� END OF HEADER
    while(true) {
        getline (in,a);
        if(a == "                                                            END OF HEADER") {
            break;
        }
    }

    string name;
    // ������� ������� � ���������
    int temp;
    double temp2;
    int countSputnik;
    vector <vector <double> > info;
    vector <double> tempVector;
    tempVector.resize(53);
    vector <string> Sputnik;
    vector <string> allSputnik;//  ������ ������ � ������� ����������
    int index=-1; //��������� ��������
    string tempName = "";

       for(int i=0; i<2880; i++) {
        in >> temp;
        in >> temp;
        in >> temp;
        in >> temp;
        in >> temp;
        in >> temp2;
        in >> temp;
        in >> countSputnik;
        /*out << countSputnik << endl; */

        getline(in,name);

        allSputnik.resize(0);
        index=-1; //��������� ��������
        tempName = "";  //
        for(int i=0; i< name.size(); i++) {
        if(name[i] == '-')
            break;
        if(name[i] >= 'A' && name[i] <= 'Z') {
            index++;
            if(tempName != "") {
               allSputnik.push_back(tempName);
               tempName="";
            }
        }
        if (name[i] != ' '){
            tempName = tempName + name[i];
        }
    }
    if(tempName != "") {
        allSputnik.push_back(tempName);
        tempName="";
    }
    tempName="";
    if(index <= countSputnik-1) {  //��������� ��������� �� ����� ���� ��������
        //2 stroka
        getline(in,name);

        for(int i=0; i<name.size(); i++){
            if(name[i] >= 'A' && name[i] <= 'Z') {
                index++;
                if(tempName != "") {
                   allSputnik.push_back(tempName);
                   tempName="";
                }
            }
            if (name[i] != ' '){
                tempName = tempName + name[i];
            }
        }
    }
    if(tempName != "") {
        allSputnik.push_back(tempName);
        tempName="";
    }
      /*
    for(int i=0; i<allSputnik.size(); i++){
        out << allSputnik[i] << endl;
    }
      */
    info.push_back(tempVector);
    for(int i = 0; i<allSputnik.size(); i++) {
         double dalnost=0;
         /*
         in >>  dalnost;
         in >>  dalnost;
           */
         string b = "";
         getline (in, b);

         a ="";
         if(b.size()>=14){
             a=b.substr(1,13);
         }
         int tochka=-1;
         int chislo=0;
         for (int i=0; i<a.size(); i++){
                if (a[i]>='0' && a[i]<='9'){
                        dalnost = dalnost *10 + (a[i]-'0');
                }
                else {
                        if(a[i]== '.') {
                                tochka=i;
                        }
                }
        }
        if(tochka != -1){
                chislo = a.size()-1 - tochka;
                chislo = (int) pow(10, (double)chislo);
                dalnost=dalnost/chislo;
        }

         getline (in,name);

         index=-1;
         for(int j=0; j<Sputnik.size(); j++) {
                if(allSputnik[i] == Sputnik[j]) {
                        index = j;
                        break;
                }
         }
         if(index == -1) {
                Sputnik.push_back(allSputnik[i]);
                info[info.size()-1][Sputnik.size()-1] = dalnost;
         }
         else {
                info[info.size()-1][index] = dalnost;
         }
    }
    }

   // out << endl;
    for(int j=0; j<Sputnik.size(); j++) {
        out << setw(13) << Sputnik[j] << " ";
    }
    out << endl;

    for(int i=0; i<info.size(); i++) {
        for(int j=0; j<info[i].size(); j++) {
                out << setw(13)  << setprecision(13) << info[i][j] << " ";
        }
       out << endl;
    }
    out << endl;

    for(int i=0; i<info.size(); i++){

         Form1->Memo1->Lines->Add(info[i][0]);
         Form1->Memo2->Lines->Add(info[i][1]);
         //Form1->Memo3->Lines->Add(info[i][0]-info[i][1]);

         Series1->Add(info[i][0],clBlue);
         Series2->Add(info[i][1],clBlue);

         //out << setw(13) << setprecision(13) << info[i][0] << setw(14) << info[i][1] << endl;
    }
}
//---------------------------------------------------------------------------


