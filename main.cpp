#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <cstring>

using namespace std;

inline void type_of_word(char f);


int main()
{   char c,h,ch,ch1,ch2;
    char word[25];
    char word2[25];

    int l,i,ng,n,k,x;

do{
    do{
        c='\0';
        cout<<"\n\t\t    ******************** Himanshu Pawar *******************\n\n";
        cout<<"\n\t\t    ******************** PROJECT: HANGMAN GAME *******************\n\n";

        cout<<"(E)Please Enter a word\n\n(C) Computer chooses word\n\n(A)";
        cout<<"Add new word to list\n\n(Q) Quit\n\n\nEnter your choice (E - C - Q): ";
        cin>>ch2;
       }while (ch2!='C' && ch2!='c' && ch2!='E' && ch2!= 'e' &&
                ch2!='Q' && ch2!= 'q'&& ch2!='A' && ch2!= 'a');
    if (ch2 == 'Q' || ch2=='q')  exit (0);

    if (ch2 == 'C' || ch2=='c')

    {
        ifstream fin("hangword.txt");
        if(!fin) {
        cout<<"File missing! , aborting.\n\nText file with words is missing...";
        system("pause"); return 0;}
        for (i=0;!fin.eof();i++)   fin.getline(word,25);
        fin.close();

        do {
        x=rand();
        }while(x>i || x<0);

        ifstream finn("hangword.txt");
        for (i=0;!finn.eof();i++)
        {finn>>c; finn.getline(word,25); if (x==i) break;}
        finn.close();
    }

  if (ch2 == 'A' || ch2=='a')

    {
        ofstream fout("hangword.txt",ios::app);
        if(!fout) {
        cout<<"File missing, aborting.\n\nText file with words is missing...\n\n"; system("pause"); return 0;}
        cin.get();
        cout<<"Choose the topic of your word\n\n(M) Place\n\n(A) Animal\n\n(S)"
        " Sport\n\n(M) Music\n\nEnter your choice (A-M-S-P) : ";
        cin>>h;
        cin.get();
        //clrscr();
        cout<<"\n\nThe word should not exceed 25 letters\n\nEnter the word : ";
        cin.getline(word,25);
        fout<<h<<word<<endl;
        fout.close();

    }


   if (ch2 == 'E' || ch2=='e')
     {// clrscr();
       cin.get();
       cout<<"\t\t\t Type the word :  ";
       cin.getline (word, 25);
     }
 if (ch2 == 'E' || ch2=='e' || ch2 == 'C' || ch2=='c')
{
l=strlen(word);
char choosen[25]="\0";
n=0;k=0;

 for(i=0;i<=24;i++)
   {
    if (word[i]=='\0') {word2[i]='\0';break;}
    if (word[i]==' ')  {word2[i]=' ';  n++;}
    if (word[i]!=' ')  word2[i]='-';
   }
ng=l+2-n;     //only 2 guesses extra
   do{
   there:  type_of_word(c);
     if (k!=0)  
        cout<<"\n\n\t\t\tChoosen letters : "<<choosen<<"\n";
     cout<<"\n\n\n\t\t\t      "<<word2<<"\n\n\nYou have "<<ng
     << " guesses left, choose a letter : ";
     cin>>ch; cin.get();
     for (i=0;i<25;i++) if (choosen[i]==ch) {//clrscr();
     cout<<"\a\t\t     !!You have choosen "<<ch<<" already!!\n";goto there;}
     ng--; choosen [k]=ch; choosen [k+1]=',';k+=2;

     for (i=0;i<=24;i++)
     if (word[i]==ch || word[i]==ch+32 || word[i]==ch-32) word2[i]=ch;
     if (!strcmpi (word2,word)) {cout<<"\n\t\t\t      "<<strupr(word)
     <<"\n\n\t\t\t---->>  CONGRATULATIONS! You Guessed the correct word  <<----\n"; break;}

    }while(ng>0 || !strcmpi (word2,word));


if (strcmpi (word2,word))  cout<<"\nSorry, all guesses finished. Better luck next time!.\n\nThe word was : "
<<strupr(word)<<endl;
}

cout<<"\nWould you like to play again??? (Y - N) : ";
cin>>ch1;  cin.get();

}while (ch1=='y' || ch1=='Y');
      system("PAUSE");
      return 0;
}

inline void type_of_word(char f)

{    if (f=='M') cout<<"\t\t\t\tMUSIC";
     if (f=='A') cout<<"\t\t\t\tANIMAL";
     if (f=='P') cout<<"\t\t\t\tPLACE";
     if (f=='S') cout<<"\t\t\t\tSPORTS";
}

// End of Code
