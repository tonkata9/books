#include<iostream>
#include<cmath>
#include<cstring>
#include<iomanip>
using namespace std;

struct Book{

char name[16];
char author [16];
char genre [16];
char isdn [16];
double price;
int year;
int pages;

};

void input(Book *books, int n){

    cout<<"!!IMPORTANT!! Every ISDN must be unique for the book! "<<endl;

    for(int i=0;i<n;i++){

        cin.ignore();
        cout<<"Name: "; cin.getline(books[i].name, 16);
        cout<<"Author: "; cin.getline(books[i].author, 16);
        cout<<"Genre: "; cin.getline(books[i].genre, 16);
        cout<<"ISDN: "; cin.getline(books[i].isdn, 16);
        cout<<"Price of the book: "; cin>>books[i].price;
        cout<<"Year of publication: "; cin>>books[i].year;
        cout<<"Number of pages: "; cin>>books[i].pages;
        cout<<endl;

    }

}

void outputArray(Book *books, int n){

    cout<<setw(5)<<"Number";
    cout<<setw(16)<<"Name";
    cout<<setw(16)<<"Author";
    cout<<setw(16)<<"Genre";
    cout<<setw(16)<<"ISDN";
    cout<<setw(16)<<"Price";
    cout<<setw(16)<<"Year";
    cout<<setw(16)<<"Pages"<<endl;

    int a=1;

    for(int i=0;i<n;i++){

        cout<<setw(5)<<a;
        cout<<setw(16)<<books[i].name;
        cout<<setw(16)<<books[i].author;
        cout<<setw(16)<<books[i].genre;
        cout<<setw(16)<<books[i].isdn;
        cout<<fixed;
        cout<<setprecision(0);
        cout<<setw(16)<<books[i].price;
        cout<<setw(16)<<books[i].year;
        cout<<setw(16)<<books[i].pages<<endl;
        a++;

    }
    cout<<endl;

}
void printoutput(Book book){

        cout<<"Name: "<<book.name<<endl;
        cout<<"Author: "<<book.author<<endl;
        cout<<"Genre: "<<book.genre<<endl;
        cout<<"ISDN: "<<book.isdn<<endl;
        cout<<"Price of the book: "<<book.price<<endl;
        cout<<"Year of publication: "<<book.year<<endl;
        cout<<"Number of pages: "<<book.pages<<endl;
        cout<<endl;

}

void minmaxPrice(Book *books, int n){

    if(n==1) cout<<"There is only one book in the library. "<<endl;

    else {
        int x=0, a=0;

        for(int i=0;i<n;i++){

            if(books[i].price>x){

                x=books[i].price;

            }
        }

        for(int i=0;i<n;i++){

            if(books[i].price==x){

            cout<<"One of the most expensive books is "<<books[i].name<<" with a price of "<<x<<". "<<endl;

            }
        }

        for(int i=0;i<n;i++){

            if(i==0){

                a=books[i].price;

            }

            else{

                if(books[i].price<a){

                    a=books[i].price;

                }

            }

        }
        for(int i=0;i<n;i++){

            if(books[i].price==a){

                cout<<"One of the cheapest books is "<<books[i].name<<" with a price of "<<a<<". "<<endl;

            }

        }

    }

}

void findbyYear(Book *books, int n){

    int a;
    cout<<"In what year was the book published? "; cin>>a;
    cout<<endl;
    bool notfound=true;
    for (int i=0;i<n;i++){

        if(books[i].year==a){
            printoutput(books[i]);
            notfound=false;
        }

    }

    if(notfound) cout<<"We couldn`t find any books published in "<<a<<". "<<endl;

}

void findbyEquality(Book *books, int n){

    char a[16];
    cin.ignore();
    cout<<"Enter ISDN: "; cin.getline(a, 16);
    cout<<endl;
    bool foundISDN, found=false;

    for(int i=0;i<n;i++){

        foundISDN=true;

        for(int j=0;j<16 &&  books[i].isdn[j]!='\0';j++){

            if (books[i].isdn[j]!=a[j]){

                foundISDN=false;

            }

        }

        if(foundISDN){

            printoutput(books[i]);
            found=true;


        }

    }
    if(!found){

        cout<<"We couldn`t find any coincidence. Try again. "<<endl;

    }

}

/*findbyEquality(Book *books, int n){

    Функция която се оказа излишна-намира и извежда всички елементи на масива, при които определена стойност се повтаря
    (В случая това са страници)
    Домъчня ми да я изтрия

 if (n==1){
        cout<<"To compare 2 values we need more than 1 book in the library. "<<endl;
        return;
    }

    bool a, x=true;
    for(int i=0;i<n;i++){

        for(int j=i+1;j<n;j++){

                a=true;
                if (books[i].pages!=books[j].pages){

                a=false;

                }

                if(a){

                cout<<books[i].name<<" and "<<books[j].name<<" have the same number of pages, which is "<<books[i].pages<<endl;
                x=false;

            }

        }

    }

    if(x) cout<<"There aren`t any books that have the same number of pages. "<<endl;
}*/

void findbyGenre (Book *books, int n){

    char a[16];
    cin.ignore();
    cout<<"What is the genre you are searching for? "; cin.getline(a, 16);
    cout<<endl;
    bool foundGenre, found=false;

    for(int i=0;i<n;i++){

        foundGenre=true;

        for(int j=0;j<16 &&  books[i].genre[j]!='\0';j++){

            if (books[i].genre[j]!=a[j]){

                foundGenre=false;

            }

        }

        if(foundGenre){

            printoutput(books[i]);
            found=true;


        }

    }
    if(!found){

        cout<<"We couldn`t find any coincidence. Try again. "<<endl;

    }

}

void morethanPrice (Book *books, int n){

    int a, x=0;
    cout<<"What price do you want the lower limit to be? "; cin>>a;
    cout<<endl;
    for(int i=0;i<n;i++){

        if(books[i].price>=a){
            x++;
        }

    }

    switch(x){

        case 0: cout<<"There aren`t any books costing more than "<<a<<endl;
                break;
        case 1: cout<<"There is only one book costing more than "<<a<<endl;
                break;
        default: cout<<"There are "<<x<<" books costing more than "<<a<<endl;
                break;

    }

}

void sumofPrices (Book *books, int n){

    int a=0;
    for(int i=0;i<n;i++){

        a=a+books[i].price;

    }

    cout<<"Sum of prices: "<<a<<endl;

}

void sortbyName (Book *books, int n){

    for(int i=0;i<n;i++){

        for(int j=i;j<n;j++){

            int y=0;

                while(books[i].name[y]==books[j].name[y] && books[i].name[y]!='\0') y++;

                if(books[i].name[y]>books[j].name[y]){

                    int a=0;
                    Book x;

                while(books[i].name[a]!='\0'){

                    x.name[a]=books[i].name[a];
                    a++;

                }

                while(a<16){

                    x.name[a]='\0';
                    a++;

                }

                a=0;

                while(books[i].author[a]!='\0'){

                    x.author[a]=books[i].author[a];
                    a++;

                }

                while(a<16){

                    x.author[a]='\0';
                    a++;

                }

                a=0;

                while(books[i].genre[a]!='\0'){

                    x.genre[a]=books[i].genre[a];
                    a++;

                }

                while(a<16){

                    x.genre[a]='\0';
                    a++;

                }

                a=0;

                while(books[i].isdn[a]!='\0'){

                    x.isdn[a]=books[i].isdn[a];
                    a++;

                }

                while(a<16){

                    x.isdn[a]='\0';
                    a++;

                }

                a=0;

                x.price=books[i].price;
                x.year=books[i].year;
                x.pages=books[i].pages;

                while(books[j].name[a]!='\0'){

                    books[i].name[a]=books[j].name[a];
                    a++;

                }

                while(a<16){

                    books[i].name[a]='\0';
                    a++;

                }

                a=0;

                while(books[j].author[a]!='\0'){

                    books[i].author[a]=books[j].author[a];
                    a++;

                }

                while(a<16){

                    books[i].author[a]='\0';
                    a++;

                }

                a=0;

                while(books[j].genre[a]!='\0'){

                    books[i].genre[a]=books[j].genre[a];
                    a++;

                }

                while(a<16){

                    books[i].genre[a]='\0';
                    a++;

                }

                a=0;

                while(books[j].isdn[a]!='\0'){

                    books[i].isdn[a]=books[j].isdn[a];
                    a++;

                }

                while(a<16){

                    books[i].isdn[a]='\0';
                    a++;

                }

                a=0;

                books[i].price=books[j].price;
                books[i].year=books[j].year;
                books[i].pages=books[j].pages;

                while(x.name[a]!='\0'){

                    books[j].name[a]=x.name[a];
                    a++;

                }

                while(a<16){

                    books[j].name[a]='\0';
                    a++;

                }

                a=0;

                while(x.author[a]!='\0'){

                    books[j].author[a]=x.author[a];
                    a++;

                }

                while(a<16){

                    books[j].author[a]='\0';
                    a++;

                }

                a=0;

                while(x.genre[a]!='\0'){

                    books[j].genre[a]=x.genre[a];
                    a++;

                }

                while(a<16){

                    books[j].genre[a]='\0';
                    a++;

                }

                a=0;

                while(x.isdn[a]!='\0'){

                    books[j].isdn[a]=x.isdn[a];
                    a++;

                }

                while(a<16){

                    books[j].isdn[a]='\0';
                    a++;

                }

                books[j].price=x.price;
                books[j].year=x.year;
                books[j].pages=x.pages;

            }

        }

    }

}

void sortbyYear (Book *books, int n){

    for(int i=0;i<n;i++){

        for(int j=i;j<n;j++){

            if(books[i].year>books[j].year){

                int a=0;
                Book x;

                while(books[i].name[a]!='\0'){

                    x.name[a]=books[i].name[a];
                    a++;

                }

                while(a<16){

                    x.name[a]='\0';
                    a++;

                }

                a=0;

                while(books[i].author[a]!='\0'){

                    x.author[a]=books[i].author[a];
                    a++;

                }

                while(a<16){

                    x.author[a]='\0';
                    a++;

                }

                a=0;

                while(books[i].genre[a]!='\0'){

                    x.genre[a]=books[i].genre[a];
                    a++;

                }

                while(a<16){

                    x.genre[a]='\0';
                    a++;

                }

                a=0;

                while(books[i].isdn[a]!='\0'){

                    x.isdn[a]=books[i].isdn[a];
                    a++;

                }

                while(a<16){

                    x.isdn[a]='\0';
                    a++;

                }

                a=0;

                x.price=books[i].price;
                x.year=books[i].year;
                x.pages=books[i].pages;

                while(books[j].name[a]!='\0'){

                    books[i].name[a]=books[j].name[a];
                    a++;

                }

                while(a<16){

                    books[i].name[a]='\0';
                    a++;

                }

                a=0;

                while(books[j].author[a]!='\0'){

                    books[i].author[a]=books[j].author[a];
                    a++;

                }

                while(a<16){

                    books[i].author[a]='\0';
                    a++;

                }

                a=0;

                while(books[j].genre[a]!='\0'){

                    books[i].genre[a]=books[j].genre[a];
                    a++;

                }

                while(a<16){

                    books[i].genre[a]='\0';
                    a++;

                }

                a=0;

                while(books[j].isdn[a]!='\0'){

                    books[i].isdn[a]=books[j].isdn[a];
                    a++;

                }

                while(a<16){

                    books[i].isdn[a]='\0';
                    a++;

                }

                a=0;

                books[i].price=books[j].price;
                books[i].year=books[j].year;
                books[i].pages=books[j].pages;

                while(x.name[a]!='\0'){

                    books[j].name[a]=x.name[a];
                    a++;

                }

                while(a<16){

                    books[j].name[a]='\0';
                    a++;

                }

                a=0;

                while(x.author[a]!='\0'){

                    books[j].author[a]=x.author[a];
                    a++;

                }

                while(a<16){

                    books[j].author[a]='\0';
                    a++;

                }

                a=0;

                while(x.genre[a]!='\0'){

                    books[j].genre[a]=x.genre[a];
                    a++;

                }

                while(a<16){

                    books[j].genre[a]='\0';
                    a++;

                }

                a=0;

                while(x.isdn[a]!='\0'){

                    books[j].isdn[a]=x.isdn[a];
                    a++;

                }

                while(a<16){

                    books[j].isdn[a]='\0';
                    a++;

                }

                a=0;

                books[j].price=x.price;
                books[j].year=x.year;
                books[j].pages=x.pages;
            }

        }

    }

}

Book* addElement (Book *books, int n){

    Book *temporary=new Book[n+1];

    for(int i=0;i<n;i++){

        temporary[i]=books[i];

    }

        cin.ignore();
        cout<<"Name: "; cin.getline(temporary[n].name, 16);
        cout<<"Author: "; cin.getline(temporary[n].author, 16);
        cout<<"Genre: "; cin.getline(temporary[n].genre, 16);
        cout<<"ISDN: "; cin.getline(temporary[n].isdn, 16);
        cout<<"Price of the book: "; cin>>temporary[n].price;
        cout<<"Year of publication: "; cin>>temporary[n].year;
        cout<<"Number of pages: "; cin>>temporary[n].pages;
        cout<<endl;

        return temporary;

}

Book* deleteElement (Book *books, int n){

    int x;
    cout<<"Which book do you want to delete? "; cin>>x;
    cout<<endl;

    Book *temporary=new Book[n-1];
    bool a=false;

    for(int i=0;i<n-1;i++){

        for(int j=0;j<n;j++){

            if(j==x) a=true;

            if(!a){

                if(i==j){

                    temporary[i]=books[j];

                }

            }
            else{

                if(i+1==j){

                    temporary[i]=books[j];

                }

            }

        }

    }
    return temporary;

}

void changeElement (Book *books, int n){

    int a;
    char field;
    cout<<"Which book do you want to change? "; cin>>a;
    cout<<endl;
    cout<<"Which value do you want to change (t-Title, g-Genre, p-Price): "; cin>>field;
    cout<<endl;

    if(field=='t'){

        cin.ignore();
        cout<<"New title: "; cin.getline(books[a-1].name, 16);
        cout<<endl;

    }

    if(field=='g'){

        cin.ignore();
        cout<<"New genre: "; cin.getline(books[a-1].genre, 16);
        cout<<endl;

    }

    if(field=='p'){

        cout<<"New price: "; cin>>books[a-1].price;
        cout<<endl;

    }

}

int main(){

    int operation, n;
    cout<<"Operation: ";cin>>operation;
    cout<<endl;

    while(operation!=0 && operation!=1){

        cout<<"First operation must be either 1 or 0. "<<endl;
        cout<<"Operation: ";cin>>operation;
        cout<<endl;

    }

    if(operation==0) return 0;

    cout<<"How many books? ";cin>>n;
    cout<<endl;

    Book *books=new Book[n];
    input(books, n);

    while(true){

        cout<<"Operation: ";cin>>operation;
        cout<<endl;

        switch(operation){

            case 0: return 0;
            case 1: input(books, n);
                    break;
            case 2: outputArray(books, n);
                    break;
            case 3: minmaxPrice(books, n);
                    break;
            case 4: findbyYear(books, n);
                    break;
            case 5: findbyEquality(books, n);
                    break;
            case 6: findbyGenre(books, n);
                    break;
            case 7: morethanPrice(books, n);
                    break;
            case 8: sumofPrices(books, n);
                    break;
            case 9: sortbyName(books, n);
                    break;
            case 10:sortbyYear(books, n);
                    break;
            case 11:books=addElement(books, n);
                    n++;
                    break;
            case 12:books=deleteElement(books, n);
                    n--;
                    break;
            case 13:changeElement(books, n);
                    break;

            default: cout<<"Invalid operation! "<<endl;

        }

    }

    return 0;
}
