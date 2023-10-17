#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class student{

typedef struct stud{
int roll;
char name[10];
char div;
char add[10];
}stud;
stud rec;
public:

void create();
int search ();
void Delete();
void display();

};

void student::create(){
char ch;
ofstream fout;
fout.open("sample.dat" ,ios::out | ios::binary);
do{
    cout<<"enter roll no of student";
    cin>>rec.roll;
    cout<<"enter name";
    cin>>rec.name;
    cout<<"enter div";
    cin>>rec.div;
    cout<<"add";
    cin>>rec.add;
    fout.write((char *)&rec , sizeof(stud)) <<flush;
    cout<<"do you want to continue";
    cin>>ch;
}
while(ch=='y' || ch=='Y');
fout.close();
}

int student::search(){
   int  r;
   int found=0 ,  i=0;
ifstream fin;
fin.open("sample.dat" ,ios::in |ios::binary);
fin.seekg(0,ios::beg);
cout<<"enter roll no r";
cin>>r;
while(fin.read((char *)&rec , sizeof(stud)));
{
if(rec.roll==r){
    cout<<"record found";
    cout<<"\n\troll \tname \tdiv \tadd";
    cout<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;
    found=1;
    //break;
}
i++;
}
fin.close();
}

void student::display(){
int i;
ifstream fin;
fin.open("sample.dat", ios::in | ios::binary);
fin.seekg(0,ios::beg);
cout<<"content of the file is";
cout<<"\n\troll \tname \tdiv \tadd";
while(fin.read((char *)&rec , sizeof(stud)));
{
    if(rec.roll!=-1){
       // cout<<"content of the file is":
        //cout<<"\n\troll \tname \tdiv \tadd";
        cout<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;

    }
}
fin.close();

}

void student::Delete(){
int pos;
pos=search();
fstream f;
f.open("sample.dat" ,ios::in | ios::out |ios::binary);
f.seekg(0 ,ios::beg);
if(pos==0){
    cout<<"record not found";
    return;

}
int offset=pos*sizeof(stud);
f.seekp(offset);
rec.roll=-1;
strcpy(rec.name ,"deleted");
rec.div = 'n';
strcpy(rec.add ,"NULL");
f.write((char*)&rec ,sizeof(stud));
f.seekg(0);
f.close();
cout<<"record deleted";
}


int main(){

student object;
int key, ch;
char Ans;
do{
    cout<<"menu";
    cout<<"1.creat \n2display \n3.search\4delete";
    cout<<"enter your choice";
    cin>>ch;
    switch(ch){
case 1:
    object.create();
    break;
case 2:
    object.display();
    break;
case 3:
        key=object.search();
        if(key==0){
                cout<<"rec not found";}
        else
        {
cout<<"yes";
        }

        break;
case 4:
    object.Delete();
    break;
case 5:
    break;

    }
    cout<<"do you to continue";
    cin>>Ans  ;

    }
    while(Ans=='y' || Ans=='Y');
   return 1;
}

