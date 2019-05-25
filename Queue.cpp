#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

char pil;
int jml;
void delay();


void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    cout.flush();
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}
struct node
{
   char kar;
   node *next;
};
   node *tail;
   node *now;
   node *head;
   
void buatnodebaru()
{
  tail=NULL;
  head=NULL;
}
void push(char ch)
{
 now=new node;
 if(head==NULL)
 {
   now->kar=ch;
   now->next=NULL;
   tail=now;
  head=now;
 }
 else
 {
   now->kar=ch;
   now->next=NULL;
  tail->next = now;
   tail=now;
 }
}
void tambah()
{
 int i;
 char temp;
 gotoxy(1,10);
 cout<<"          ";
 gotoxy(1,10);
 cout<<"masukkan 1 karakter : ";
 cin>>temp;
 push(temp);
   for(i=1;i<=75-jml*6;i++)
   {
     gotoxy(i,21); cout<<"("<<now->kar<<")";
    delay();
    if(i!=75-jml*6)
    {
         gotoxy(i,21);cout<<"      ";
    }
   }
}

void kurang()
{
 if(head==NULL)
 {
  gotoxy(1,8); cout<<"antrean kosong !";
   delay();
 }
 else
 {
   jml=jml-1;
   char delete_element=now->kar;
   node *temp;
   temp=head;
   head=head->next;
   delete temp;
 for(int i=69;i<=76;i++)
 {
  gotoxy(i,21); cout<<"("<<delete_element<<")";
  delay();
  gotoxy(i,21); cout<<"      ";
 }
 int byk=0;
 while(byk!=jml)
 {
   byk=byk+1;
  for(int i=69-byk*6;i<=75-byk*6;i++)
  {
    gotoxy(i,21); cout<<"("<<now->kar<<")";
    delay();
      if(i!=75-byk*6)
      {
     gotoxy(i,21); cout<<"      ";
      }
  }
 }
 }
}
void input()
{
 gotoxy(1,1);cout<<"===============================================\n";
 gotoxy(1,2);cout<<"               P I L I H A N\n";
 gotoxy(1,3);cout<<"===============================================\n";
 gotoxy(1,4);cout<<"\t\t1.Tambah";
 gotoxy(1,5);cout<<"\t\t2.Kurangi";
 gotoxy(1,6);cout<<"\t\t3.Keluar";
 gotoxy(1,7);cout<<"-----------------------------------------------\n";
 do
 {
 gotoxy(1,1);cout<<"===============================================\n";
 gotoxy(1,2);cout<<"               P I L I H A N\n";
 gotoxy(1,3);cout<<"===============================================\n";
 gotoxy(1,4);cout<<"\t\t1.Tambah";
 gotoxy(1,5);cout<<"\t\t2.Kurangi";
 gotoxy(1,6);cout<<"\t\t3.Keluar";
 gotoxy(1,7);cout<<"-----------------------------------------------\n";
   gotoxy(1,8);cout<<"Masukkan pilihan anda : ";
   gotoxy(25,8);cin>>pil;
   gotoxy(25,8);cout<<"  ";
   switch(pil)
   {
   case '1':
   {
     if(jml<10)
     {
       jml=jml+1;
       tambah();
     }
     else
     {
      gotoxy(1,16); cout<<"antrean penuh !";
      delay();
      gotoxy(1,16); cout<<"     ";
     }
     break;
    }
   case '2':
   {
     kurang();
    break;
   }

   case '3':
   {
      exit(1);
    break;
   }
  }
 }while(1);
}
int main()
{
  buatnodebaru();
  jml=0;
  system("cls");
  input();
  getch();
}
void delay()
{
 for(int y=1;y<100;y++)
 for(int x=1;x<100;x++)
 for(int p=1;p<100;p++)
 cout<<"";
}
